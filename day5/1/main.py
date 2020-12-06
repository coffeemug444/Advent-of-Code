f = open("input.txt")
lines = f.readlines()
f.close()


def seatID(ticket):
    id = 0
    for i in range(7):
        if ticket[i] == "B":
            id += 2**(6-i)
    id *= 8
    for i in range(3):
        if ticket[7 + i] == "R":
            id += 2**(2-i)
    return id

max = 0
for line in lines:
    ticket = line.strip("\n")
    id = seatID(ticket)
    if id > max:
        max = id

print(max)