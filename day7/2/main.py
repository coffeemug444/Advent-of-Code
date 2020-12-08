import networkx as nx
import matplotlib.pyplot as plt



def shortest_path(G, source, target):
    def path_cost(G, path):
        return sum([G[path[i]][path[i+1]]['weight'] for i in range(len(path)-1)])
    return sorted([(path_cost(G,p), p) for p in nx.shortest_simple_paths(G, source,target,weight='weight')])[0]

def get_num_children(G, source):
    neighs = nx.neighbors(G, source)
    neighs = list(neighs)
    if len(neighs) == 0:
        return 0
    total = 0
    for n in neighs:
        total += shortest_path(G, source, n)[0] * (get_num_children(G, n) + 1)
    return total

f = open("input.txt")
lines = f.readlines()
f.close()

bags = set()
DG = nx.DiGraph()

for line in lines:
    tmp = line.split(" ")
    parentbagcolour = tmp[0] + tmp[1]
    bags.add(parentbagcolour)
    DG.add_node(parentbagcolour)

    if "contain no other bags" not in line:
        line = line.split("contain")
        line = line[1].strip(" \n.")
        line = line.split(", ")

        for bag in line:
            col = bag.split(" ")
            bagcolour = col[1] + col[2]
            bags.add(bagcolour)
            DG.add_node(bagcolour)
            DG.add_edge(parentbagcolour, bagcolour, weight=int(col[0]))

#print(get_num_children(DG, "shinygold"))

maximum = 0
name = ""
for bag in bags:
    num = get_num_children(DG, bag)
    print(num)
    if num > maximum:
        name = bag
        maximum = num
        
print(name, "contains", maximum, "other bags")
