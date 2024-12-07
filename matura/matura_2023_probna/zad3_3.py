import math

N = 1000000
pierwsza = []
for i in range(0, N+1):
    pierwsza.append(True)
pierwsza[0] = False
pierwsza[1] = False

for i in range(2, int(math.sqrt(N))):
    if(pierwsza[i]):
        j = i*i
        while j <= N:
            pierwsza[j] = False
            j += i 

def ilosc_rozkladow(x):    
    count = 0
    a = b = x//2
    for i in range(0, x//2):        
        if(pierwsza[a] and pierwsza[b]):
            count+=1
        a -= 1
        b += 1
    return count

with open("./Dane_2212/liczby.txt", "r") as file:
    minLiczba = 0
    minRoz = N
    maxLiczba = 0
    maxRoz = 0    
    for line in file:
        x = int(line[:-1])
        if(x%2==0):
            r = ilosc_rozkladow(x)
            if(r > maxRoz):
                maxRoz = r
                maxLiczba = x
            if(r < minRoz):
                minRoz = r
                minLiczba = x

    print(f"{maxLiczba} {maxRoz} {minLiczba} {minRoz}")

