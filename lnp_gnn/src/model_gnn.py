import torch
import torch.nn as nn
from torch_geometric.nn import GCNConv, global_mean_pool


class LNP_GNN(nn.Module):
    def __init__(self, extra_dim):
        super().__init__()

        # ======================
        # 🔥 GNN部分
        # ======================
        self.conv1 = GCNConv(1, 64)
        self.conv2 = GCNConv(64, 64)

        # 👉 防过拟合（重要）
        self.dropout = nn.Dropout(p=0.2)

        # ======================
        # 🔥 全连接（已适配 extra_dim=8）
        # ======================
        self.fc = nn.Sequential(
            nn.Linear(64 + extra_dim, 128),
            nn.ReLU(),
            nn.Linear(128, 64),
            nn.ReLU(),
            nn.Linear(64, 1)
        )

    def forward(self, data):
        x, edge_index, batch = data.x, data.edge_index, data.batch

        # ======================
        # 🔥 GNN传播
        # ======================
        x = self.conv1(x, edge_index)
        x = torch.relu(x)

        x = self.conv2(x, edge_index)
        x = torch.relu(x)

        # ======================
        # 🔥 图级 pooling
        # ======================
        x = global_mean_pool(x, batch)

        # ======================
        # 🔥 拼接 extra 特征（关键）
        # ======================
        extra = data.extra.view(data.num_graphs, -1)

        x = torch.cat([x, extra], dim=1)

        # ======================
        # 🔥 dropout（增强泛化）
        # ======================
        x = self.dropout(x)

        # ======================
        # 🔥 输出
        # ======================
        return self.fc(x)
