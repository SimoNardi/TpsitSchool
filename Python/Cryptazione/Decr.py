import math

enc = [459541, 134033, 243696, 243696, 497836, 121848, 497836, 252297, 243696, 357421]
pub = (536131, 5939)

def decifratore(msg,chiave):
    for i in range(65, 91):
        char2number[chr(i)] = i - 65
        number2char[i - 65] = chr(i)

dec = ''.join(map(lambda a: chr(decifratore(a, pub) + 65), enc))
print(dec)
#x**c % n