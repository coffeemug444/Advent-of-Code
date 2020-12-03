f = open("input.txt")
lines = f.readlines()
f.close()

trees = 0
pos = 0
for line in lines:
    if line[pos] == "#":
        trees += 1
    pos = (pos + 3) % (len(line) - 1)


print(trees)