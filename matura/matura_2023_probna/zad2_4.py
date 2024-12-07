N = 1000000
to_save = []

l = []
def rysuj(x, y):
    l.append(x)
    
    if(2*x <= y):
        rysuj(2*x, y)
    if(2*x+1 <= y):
        rysuj(2*x+1, y)


with open("./Dane_2212/pary.txt", "r") as file:    
    for line in file:
        line = line[:-1]
        x, y = line.split(" ")
        x = int(x)
        y = int(y)
        if(x >= y or x >= N or y > N):
            continue
        l = []
        rysuj(x, y)
        isIn = y in l
        #print(f"{y}: {l}")
        if(isIn):
            print(x, y)

        
