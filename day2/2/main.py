f = open("input.txt")
lines = f.readlines()
f.close()

valid = 0

for line in lines:
    splitline = line.split(":")

    password = splitline[1][1:]

    rule = splitline[0].split(" ")  #["min-max", "key"]
    key = rule[1]
    first = int(rule[0].split("-")[0]) - 1
    second = int(rule[0].split("-")[1]) - 1

    if (password[first] == key) ^ (password[second] == key):
        valid += 1
    

print(valid)