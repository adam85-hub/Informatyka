file = open("./Dane_2305/bin.txt", "r")

def binToDec(b):
    d = 0
    for i in range(0, len(b)):
        d += int(b[len(b)-i-1]) * 2**i
    return d

m_d = 0
m_b = ""
for line in file:
    line = line[0:-1]
    number = binToDec(line)
    if(number > m_d):
        m_d = number
        m_b = line

print(m_b)
    
