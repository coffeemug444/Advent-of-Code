f = open("input.txt")
lines = f.readlines()
f.close()

fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}

valids = 0
infields = []
for line in lines:
    if line != "\n":
        data = line.split(" ")
        for item in data:
            infields.append(item.split(":")[0])
    else:
        valid = True
        for field in fields:
            if field not in infields:
                valid = False
                break
        if valid:
            valids += 1
        infields = []

print(valids)

