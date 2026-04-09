import torch
from torch_geometric.loader import DataLoader


def screen(model, dataset):

    loader = DataLoader(dataset, batch_size=32, shuffle=False)

    preds = []

    with torch.no_grad():
        for batch in loader:
            pred = model(batch)
            preds.extend(pred.squeeze().tolist())

    return preds
