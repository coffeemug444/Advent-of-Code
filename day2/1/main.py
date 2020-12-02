f = open("input.txt")
lines = f.readlines()
f.close()

valid = 0

for line in lines:
    splitline = line.split(":")

    password = splitline[1]

    rule = splitline[0].split(" ")  #["min-max", "key"]
    key = rule[1]
    minimum = int(rule[0].split("-")[0])
    maximum = int(rule[0].split("-")[1])

    count = 0
    for letter in password:
        if letter == key:
            count += 1
    
    if (count >= minimum) and (count <= maximum):
        valid += 1

print(valid)