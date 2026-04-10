import pandas as pd

from src.dataset import load_dataset
from src.model_gnn import LNP_GNN
from src.train_gnn import train
from src.screen_gnn import screen

# 1️⃣ 读数据
df = pd.read_csv("data/clean_lnp.csv", encoding="latin1")

# 2️⃣ 构建dataset
dataset = load_dataset(df)

print(f"Dataset size: {len(dataset)}")

# 3️⃣ 建模型
model = LNP_GNN(extra_dim=8)

# 4️⃣ 训练
model = train(dataset, model)

# 5️⃣ 预测
preds = screen(model, dataset)

df = df.iloc[:len(preds)].copy()
df["pred"] = preds

# 6️⃣ 输出Top结果
df = df.sort_values("pred", ascending=False)

df.head(20).to_csv("top_intestinal_lnp.csv", index=False, encoding="utf-8-sig")

print("Top candidates saved to top_intestinal_lnp.csv")
