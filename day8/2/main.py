f = open("input.txt")
lines = f.readlines()
f.close()

def execute():
    pos = 0
    acc = 0
    executed = set()

    while pos not in executed:
        executed.add(pos)
        ins = lines[pos].strip("\n").split(" ")
        if ins[0] == "acc":
            acc += int(ins[1])
            pos += 1
        if ins[0] == "jmp":
            pos += int(ins[1])
        if ins[0] == "nop":
            pos += 1
        if pos >= len(lines):
            print("halted with acc:", acc)        
            break

for i in range(len(lines)):
    if "jmp" in lines[i]:
        lines[i] = lines[i].replace("jmp", "nop")
        execute()
        lines[i] = lines[i].replace("nop", "jmp")
    if "nop" in lines[i]:
        lines[i] = lines[i].replace("nop", "jmp")
        execute()
        lines[i] = lines[i].replace("jmp", "nop")