def ths(x):
    return str(hex(x)).replace("0x", "").upper()

occ = {}
for i in range(0, 16):
    occ[ths(i)] = 0

with open("./Dane_2212/liczby.txt", "r") as file:
    for line in file:
        x = int(line[:-1])
        for c in ths(x):
            occ[c]+=1


for key in occ:
    print(f"{key}:{occ[key]}")
            

