f = open("input.txt")
lines = f.readlines()
f.close()

fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}

def isDigit(data):
    for letter in data:
        if letter not in "0123456789":
            return False
    return True

def verify(field, data):
    if field == "byr":
        if len(data) != 4:
            return False
        if not isDigit(data):
            return False
        yr = int(data)
        if yr < 1920 or yr > 2002:
            return False
        return True
    
    if field == "iyr":
        if len(data) != 4:
            return False
        if not isDigit(data):
            return False
        yr = int(data)
        if yr < 2010 or yr > 2020:
            return False
        return True
    
    if field == "eyr":
        if len(data) != 4:
            return False
        if not isDigit(data):
            return False
        yr = int(data)
        if yr < 2020 or yr > 2030:
            return False
        return True
    
    if field == "hgt":
        if len(data) < 3:
            return False
        end = data[-2:]
        if end != "cm" and end != "in":
            return False
        start = data[:-2]
        if not isDigit(start):
            return False
        start = int(start)
        if end == "cm":
            if start < 150 or start > 193:
                return False
        elif end == "in":
            if start < 59 or start > 76:
                return False
        return True   
         
    if field == "hcl":
        if len(data) != 7:
            return False
        if data[0] != "#":
            return False
        col = data[1:]
        for val in col:
            if val not in "0123456789abcdef":
                return False
        return True

    if field == "ecl":
        if data not in ["amb","blu","brn","gry","grn","hzl","oth"]:
            return False
        return True
    if field == "pid":
        if len(data) != 9:
            return False
        if not isDigit(data):
            return False
        return True
    
    if field == "cid":
        return True

    return False

valids = 0
infields = []
passport_data = []
for line in lines:
    if line != "\n":
        data = line.split(" ")
        for item in data:
            infields.append(item.split(":")[0])
            passport_data.append(item.split(":"))
            passport_data[-1][1] = passport_data[-1][1].strip("\n")
    else:
        valid = True
        for field in fields:
            if field not in infields:
                valid = False
                break
        for data in passport_data:
            if not verify(data[0], data[1]):
                valid = False
                break
        if valid:
            valids += 1
        infields = []
        passport_data = []

print(valids)