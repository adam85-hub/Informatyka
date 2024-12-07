with open("./Dane_2305/pi.txt") as file:
    lines = file.readlines()
    cTable = {}
    for i in range(10):
        for j in range(10):
            cTable[i*10+j] = 0
    for i in range(len(lines)-1):
        a = int(lines[i][0:-1])
        b = int(lines[i+1][0:-1])
        cTable[a*10+b] += 1
    cMax = 0
    eMax = 0
    cMin = 10000
    eMin = 0
    for i in range(10):
        for j in range(10):
            element = i*10+j
            if(cTable[element] > cMax):
                eMax = element
                cMax = cTable[element]
            elif(cTable[element] == cMax and element < eMax):
                eMax = element
                cMax = cTable[element]

            if(cTable[element] < cMin):
                cMin = cTable[element]
                eMin = element
            elif(cTable[element] == cMin and element < eMin):
                eMin = element
                cMin = cTable[element]

if(eMax < 10):
    eMax = "0" + str(eMax)
if(eMin < 10):
    eMin = "0" + str(eMin)
print(f"{eMin} {cMin}")
print(f"{eMax} {cMax}")
                
        
