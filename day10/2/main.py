f = open("input.txt")
#f = open("given.txt")
lines = f.readlines()
f.close()

maximum = 0
joltages = []
joltages_dict = {0:1}
for line in lines:
    curr = int(line)
    if curr > maximum:
        maximum = curr
    joltages.append(curr)
    joltages_dict[curr] = 0
joltages.sort()
joltages.append(joltages[-1] + 3)
joltages_dict[joltages[-1]] = 0

for jolt in joltages:
    for i in range(1,4):
        if (jolt - i) in joltages_dict:
            joltages_dict[jolt] += joltages_dict[jolt - i]
print(joltages_dict[joltages[-1]])