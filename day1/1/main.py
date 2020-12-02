# find 2 numbers in a list that add to 2020

f = open("input.txt")
s = set()
lines = f.readlines()
f.close()
for line in lines:
    i = int(line)
    if 2020 - i in s:
        print(str(i), "*", str(2020 - i), "=", i * (2020 - i))
        break
    s.add(i)
