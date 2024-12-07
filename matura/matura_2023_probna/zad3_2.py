import math

N = 1000000
pierwsza = []
for i in range(0, N+1):
    pierwsza.append(True)

for i in range(2, int(math.sqrt(N))):
    if(pierwsza[i]):
        j = i*i
        while j <= N:
            pierwsza[j] = False
            j += i 

with open("./Dane_2212/liczby.txt", "r") as file:
    count = 0
    for line in file:
        x = int(line[:-1])
        if(pierwsza[x-1]):
            count+=1

    print(count)
    
