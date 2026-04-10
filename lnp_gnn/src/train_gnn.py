from torch_geometric.loader import DataLoader
import torch


def train(dataset, model):

    loader = DataLoader(dataset, batch_size=32, shuffle=True)

    optimizer = torch.optim.Adam(model.parameters(), lr=1e-3)

    # ======================
    # 🔥 自动计算类别权重（关键）
    # ======================
    labels = [d.y.item() for d in dataset]
    pos = sum(labels)
    neg = len(labels) - pos

    pos_weight = torch.tensor([neg / (pos + 1e-6)])  # 防止除0

    print(f"Positive samples: {pos}")
    print(f"Negative samples: {neg}")
    print(f"pos_weight: {pos_weight.item():.2f}")

    loss_fn = torch.nn.BCEWithLogitsLoss(pos_weight=pos_weight)

    # ======================
    # 🔥 训练
    # ======================
    for epoch in range(20):
        total_loss = 0

        for batch in loader:

            pred = model(batch)

            target = batch.y.view(-1, 1)

            loss = loss_fn(pred, target)

            # 防NaN
            if torch.isnan(loss):
                continue

            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            total_loss += loss.item()

        # ======================
        # 🔥 监控训练状态（关键）
        # ======================
        with torch.no_grad():
            pred_all = []
            for batch in loader:
                pred = model(batch)
                prob = torch.sigmoid(pred)
                pred_all.append(prob.mean().item())

        avg_loss = total_loss / len(loader)
        print(f"Epoch {epoch}: Loss = {avg_loss:.4f}")

    return model
