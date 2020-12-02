# find 3 numbers in a list that add to 2020

f = open("input.txt")
numbers = set()
offs = set()

lines = f.readlines()
for line in lines:
    i = int(line)
    numbers.add(i)
    offs.add(2020-i)

found = False

for off in offs:
    for num in numbers:
        if (off - num) in numbers:
            print((2020-off) , "*", num, "*", off - num, "=", (2020-off)*num*(off-num))
            found = True
            break
    if found:
        break