import torch
import pandas as pd
import math
from torch_geometric.data import Data
from rdkit import Chem


# ======================
# 1️⃣ SMILES → 图
# ======================
def mol_to_graph(smiles):
    mol = Chem.MolFromSmiles(str(smiles))
    if mol is None:
        return None

    x = [[atom.GetAtomicNum()] for atom in mol.GetAtoms()]
    x = torch.tensor(x, dtype=torch.float)

    edge_index = []
    for bond in mol.GetBonds():
        i = bond.GetBeginAtomIdx()
        j = bond.GetEndAtomIdx()
        edge_index.append([i, j])
        edge_index.append([j, i])

    if len(edge_index) == 0:
        return None

    edge_index = torch.tensor(edge_index, dtype=torch.long).t().contiguous()
    return x, edge_index


# ======================
# 2️⃣ 安全转换
# ======================
def safe_float(x, default=0.0):
    try:
        val = float(x)
        if math.isnan(val):
            return default
        return val
    except:
        return default


# ======================
# 3️⃣ 解析 lipid ratio（新增🔥）
# ======================
def parse_ratio(ratio_str):
    try:
        parts = str(ratio_str).split(":")
        nums = [float(p) for p in parts]
        if len(nums) == 4:
            return nums  # ionizable, PEG, cholesterol, helper
    except:
        pass
    return [0, 0, 0, 0]


# ======================
# 4️⃣ 🔥 新标签（增强版）
# ======================
def compute_bio_score(row):
    size = safe_float(row["particle_size_nm_std"])
    pdi = safe_float(row["pdi_std"])
    zeta = safe_float(row["zeta_potential_mv_std"])
    encaps = safe_float(row["encapsulation_efficiency_percent_std"])

    # 限制范围
    size = min(max(size, 0), 300)
    pdi = min(max(pdi, 0), 1)
    zeta = min(max(zeta, -50), 50)

    # 物理特征
    size_score = -((size - 100) ** 2) / 10000
    pdi_score = -pdi * 2
    zeta_score = -((zeta - 5) ** 2) / 2500

    # 🔥 生物性能（关键）
    encaps_score = encaps / 100

    # 综合评分
    score = (
        0.3 * size_score +
        0.2 * pdi_score +
        0.2 * zeta_score +
        0.3 * encaps_score
    )

    return score


# ======================
# 5️⃣ 主函数
# ======================
def load_dataset(df):

    # ======================
    # 🔥 计算所有score（过滤NaN）
    # ======================
    scores = []
    for _, row in df.iterrows():
        s = compute_bio_score(row)
        if not math.isnan(s):
            scores.append(s)

    scores = sorted(scores)
    idx = int(len(scores) * 0.8)
    idx = min(idx, len(scores) - 1)
    threshold = scores[idx]

    print(f"Threshold (Top 20%): {threshold:.4f}")

    data_list = []
    label_sum = 0

    for _, row in df.iterrows():

        # ======================
        # SMILES组合
        # ======================
        smiles_list = [
            row.get("ionizable_lipid_smiles"),
            row.get("helper_lipid_smiles"),
            row.get("peg_lipid_smiles"),
            row.get("sterol_lipid_smiles"),
        ]

        merged_x = []
        merged_edge = []
        offset = 0

        for smi in smiles_list:
            if pd.isna(smi):
                continue

            result = mol_to_graph(smi)
            if result is None:
                continue

            x, edge_index = result
            merged_x.append(x)
            merged_edge.append(edge_index + offset)
            offset += x.shape[0]

        if len(merged_x) == 0:
            continue

        x = torch.cat(merged_x, dim=0)
        edge_index = torch.cat(merged_edge, dim=1)

        # ======================
        # 🔥 数值特征（含ratio）
        # ======================
        size = safe_float(row["particle_size_nm_std"]) / 200
        pdi = safe_float(row["pdi_std"])
        zeta = safe_float(row["zeta_potential_mv_std"]) / 50
        encaps = safe_float(row["encapsulation_efficiency_percent_std"]) / 100

        # 🔥 ratio加入
        r1, r2, r3, r4 = parse_ratio(row.get("lipid_molar_ratio"))

        extra = torch.tensor([
            size, pdi, zeta, encaps,
            r1/100, r2/100, r3/100, r4/100
        ], dtype=torch.float)

        # ======================
        # 🔥 标签（Top-K）
        # ======================
        y_val = compute_bio_score(row)

        if math.isnan(y_val):
            continue

        label = 1 if y_val > threshold else 0
        label_sum += label

        y = torch.tensor([label], dtype=torch.float)

        data = Data(x=x, edge_index=edge_index, y=y)
        data.extra = extra

        data_list.append(data)

    print(f"Final usable samples: {len(data_list)}")
    print(f"Positive samples: {label_sum}")
    print(f"Negative samples: {len(data_list) - label_sum}")

    return data_list
