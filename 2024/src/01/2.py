def getNumAmnts(ls: list[int]) -> dict:
    # dictionary:
    #   key = number,
    #   value = amount number occurs in list
    numAmnts = {}

    # sets only contain each element once
    # removes useless duplicate numbers
    for i in set(ls):
        counter = 0
        for j in ls:
            if i == j:
                counter += 1
        numAmnts[i] = counter
    return numAmnts


# open input file, read lines and extract numbers
with open("./input.txt", "r") as file:
    lines = [line.strip() for line in file]

locList1, locList2 = ([], [])
for line in lines:
    splitLine = line.split(" ")
    locList1.append(int(splitLine[0]))
    locList2.append(int(splitLine[-1]))

numAmnts = getNumAmnts(locList2)
sim_score = 0
for element in locList1:
    try:
        sim_score += element * numAmnts[element]
    except KeyError:
        pass

print(sim_score)
