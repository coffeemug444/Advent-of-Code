f = open("input.txt")
lines = f.readlines()
f.close()

grads = [(1,1), (3,1), (5,1), (7,1), (1,2)]
trees = []
for grad in grads:
    trees.append(0)

row = 0
for line in lines:
    for i in range(len(grads)):
        if (row % grads[i][1]) == 0:
            pos = ((row // grads[i][1]) * grads[i][0]) % (len(line)-1)
            if line[pos] == '#':
                trees[i] += 1
    row += 1

prod = 1
for treecount in trees:
    prod *= treecount

print(trees)
print(prod)