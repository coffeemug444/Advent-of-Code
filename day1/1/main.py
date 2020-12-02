f = open("input.txt")
s = set()
lines = f.readlines()
for line in lines:
    i = int(line)
    if 2020 - i in s:
        print(str(i), "*", str(2020 - i), "=", i * (2020 - i))
        break
    s.add(i)