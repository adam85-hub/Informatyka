with open("./Dane_2305/pi.txt") as file:
    lines = file.readlines()
    count = 0
    for i in range(len(lines)-6):
        cR = 0
        cM = 0
        j = 0
        prev = int(lines[i+j][0:-1])
        current = int(lines[i+j+1][0:-1])
        while(prev < current):
            cR+=1
            j+=1
            prev = int(lines[i+j][0:-1])
            current = int(lines[i+j+1][0:-1])
        j+=1
        prev = int(lines[i+j][0:-1])
        current = int(lines[i+j+1][0:-1])
        while(prev > current and j <= 4 and cR > 0):
            cM+=1
            j+=1
            prev = int(lines[i+j][0:-1])
            current = int(lines[i+j+1][0:-1])
        if(cR > 0 and cM > 0 and j == 5):
            count+=1
            
                                                    
print(count)
