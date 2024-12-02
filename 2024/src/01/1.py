# simple (bad) quicksort implementation
def quickSort(ls: list[int]) -> list[int]:
    if len(ls) > 1:
        pivot = ls.pop(0)
        higher, lower = ([], [])
        for element in ls:
            if element < pivot:
                lower.append(element)
            else:
                higher.append(element)
        lower = quickSort(lower)
        higher = quickSort(higher)
        ls = lower + [pivot] + higher
    return ls


# read input values and extract ints to two lists
with open("./input.txt", "r") as file:
    lines = [line.strip() for line in file]

locList1, locList2 = ([], [])

for line in lines:
    splitLine = line.split(" ")
    locList1.append(int(splitLine[0]))
    locList2.append(int(splitLine[-1]))

# sort the lists by size
locList1, locList2 = (quickSort(locList1), quickSort(locList2))

delta = 0
for i in range(len(locList1)):
    delta += abs(locList1[i] - locList2[i])

print(f"The total distance between the location lists is {delta}.")
