with open("./Dane_2212/mecz.txt", "r") as file:
    line = file.readlines()[0]
    countA = 0
    countB = 0
    for i in range(0, len(line)):
        x = line[i]
        if(x == "A"):
            countA+=1
        else:
            countB+=1
        if(countA >= 1000 and countA - countB >= 3):
            print(f"A {countA}:{countB}")
            break
        elif (countB >= 1000 and countB - countA >= 3):
            print(f"B {countA}:{countB}")
            break
