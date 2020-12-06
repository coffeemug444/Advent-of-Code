f = open("input.txt")
lines = f.readlines()
f.close()

answers = set()
sum = 0
for line in lines:
    if line != "\n":
        line = line.strip("\n")
        for char in line:
            answers.add(char)
    else:
        sum += len(answers)
        answers = set()

print(sum)