with open("./Dane_2212/mecz.txt", "r") as file:
    line = file.readlines()[0]
    cPass = 0
    pMax = 0
    pD = "Nie ma"
    passa = 0
    current = line[0]
    for i in range(0, len(line)):
        x = line[i]
        if(x == current):
            passa+=1
        if(x != current):
            if(passa >= 10):
                cPass+=1
                if(passa > pMax):
                    pMax = passa
                    pD = current
            current = x
            passa = 1

    print(f"{cPass} {pD} {pMax}")
            
        
        
