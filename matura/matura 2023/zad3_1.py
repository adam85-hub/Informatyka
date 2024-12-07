with open("./Dane_2305/pi.txt") as file:
    lines = file.readlines()
    count = 0
    for i in range(len(lines)-1):
        a = int(lines[i][0:-1])
        b = int(lines[i+1][0:-1])
        if(a==9 and b > 0):
            count+=1

print(count)
