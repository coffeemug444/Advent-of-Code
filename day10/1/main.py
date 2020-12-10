f = open("input.txt")
lines = f.readlines()
f.close()

maximum = 0
joltages = set()
for line in lines:
    curr = int(line)
    if curr > maximum:
        maximum = curr
    joltages.add(curr)

curr = 0
diffs = [0, 0, 1]

while curr != maximum:
    for i in range(1, 4):
        if (curr + i) in joltages:
            diffs[i - 1] += 1
            curr = curr + i
            break

print(diffs)