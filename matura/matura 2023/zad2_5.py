file = open("./Dane_2305/bin.txt", "r")
file_save = open("./wyniki2_5.txt", "w") #overwrites a file

def toBin(n):
    b = []
    while True:
        b.insert(0, n%2)
        n = int(n/2)
        if(n==0):
            return b

def binToDec(b):
    d = 0
    for i in range(0, len(b)):
        d += int(b[len(b)-i-1]) * 2**i
    return d

for line in file:
    line = line[0:-1]
    p1 = line
    p2 = toBin(int(binToDec(p1)/2))
    wynik = []
    for i in range(0, max(len(p1), len(p2))):
        a = 0
        if(i < len(p1)):
            a = int(p1[len(p1)-i-1])
        b = 0
        if(i < len(p2)):
            b = int(p2[len(p2)-i-1])
        if(a==b):
            wynik.insert(0, "0")
        else:
            wynik.insert(0, "1")
    wynik = "".join(wynik)
    file_save.write(wynik + "\n")
        
file_save.close()
file.close()
