f = open("input.txt")
lines = f.readlines()
f.close()

nums = []
for line in lines:
    nums.append(int(line))

rot = nums[:25]

for i in range(25, len(nums)):
    valid = False
    for num in rot:
        tocheck = nums[i] - num
        if tocheck in rot:
            valid = True
    if not valid:
        print(nums[i])
        break
    rot = rot[1:]
    rot.append(nums[i])

target = nums[i]

for i in range(len(nums)):
    found = False
    arr = []
    for j in range(i, len(nums)):
        arr.append(nums[j])
        total = sum(arr)
        if total > target:
            break
        if total == target:
            found = True
            break
    if found:
        print(min(arr), "+", max(arr), "=", min(arr) + max(arr))
        break