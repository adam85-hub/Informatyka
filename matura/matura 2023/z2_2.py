file = open("./Dane_2305/bin.txt", "r")

def liczba_b(b):
    count = 1
    current_block = b[0]
    for x in b:
        if(x != current_block):
            count+=1
            current_block = x
    return count

count = 0
for line in file:
    line = line[0:-1]
    if(liczba_b(line) <= 2):
        count+=1

print(count)
    
