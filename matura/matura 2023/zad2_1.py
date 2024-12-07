n=int(input())

def toBin(n):
    b = []
    while True:
        b.insert(0, n%2)
        n = int(n/2)
        if(n==0):
            return b

def liczba_b(b):
    count = 1
    current_block = b[0]
    for x in b:
        if(x != current_block):
            count+=1
            current_block = x
    return count

#b=liczba_b(to_bin(n))
#print(b)
print(toBin(n))
