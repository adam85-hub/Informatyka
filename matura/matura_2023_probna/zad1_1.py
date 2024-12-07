with open("./Dane_2212/mecz.txt", "r") as file:
    line = file.readlines()[0]
    count = 0
    current = line[0]
    for i in range(1, len(line)):
        x = line[i]
        if(x != current):
            count+=1
            current = x

    print(count)
