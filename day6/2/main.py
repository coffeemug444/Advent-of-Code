f = open("input.txt")
lines = f.readlines()
f.close()

answers = set()
group = set()
sum = 0
for line in lines:
    if line != "\n":
        line = line.strip("\n")
        group.add(line)
        for char in line:
            answers.add(char)
    else:
        for char in answers:
            isin = True
            for person in group:
                isin &= char in person
            if isin:
                sum += 1
        answers = set()
        group = set()

print(sum)