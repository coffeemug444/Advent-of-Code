import networkx as nx
import matplotlib.pyplot as plt


def shortest_path(G, source, target):
    def path_cost(G, path):
        return sum([G[path[i]][path[i+1]]['weight'] for i in range(len(path)-1)])
    return sorted([(path_cost(G,p), p) for p in nx.shortest_simple_paths(G, source,target,weight='weight')])[0]

f = open("input.txt")
lines = f.readlines()
f.close()

bags = set()
DG = nx.DiGraph()

#DG.add_node("GODBAG")

for line in lines:
    tmp = line.split(" ")
    parentbagcolour = tmp[0] + tmp[1]
    bags.add(parentbagcolour)
    DG.add_node(parentbagcolour)
    #DG.add_edge(parentbagcolour, "GODBAG", weight=1)

    if "contain no other bags" not in line:
        line = line.split("contain")
        line = line[1].strip(" \n.")
        line = line.split(", ")

        for bag in line:
            col = bag.split(" ")
            bagcolour = col[1] + col[2]
            bags.add(bagcolour)
            DG.add_node(bagcolour)
            DG.add_edge(bagcolour, parentbagcolour, weight=int(col[0]))


paths = 0
for bag in bags:
    if nx.has_path(DG,"shinygold", bag) and bag != "shinygold":
        paths += 1

print(paths)