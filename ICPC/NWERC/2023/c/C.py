import math

n, q = [int(x) for x in input().split()]

operations = []
mults = []

modulo = n
coeff = 1
offset = 0

def reverse_basic(query, modulo, coeff, offset):
    inv = math.pow(coeff, -1, modulo)
    out = query - offset
    if out < 0:
        out += modulo

    out = (inv * out) % modulo
    return out

def reverse_advanced(query, modulo, mult):
    inv = math.pow(mult, -1, modulo)


for _ in range(q):
    t, x = input().split()
    x = int(x)

    if t == '+':
        offset = (offset + x) % modulo
    elif t == '*':
        gcd = math.gcd(x, modulo)
        if gcd == 1:
            coeff = (coeff * x) % modulo
            offset = (offset * x) % modulo
            continue

        operations.append((modulo, coeff, offset))
        mults.append((modulo, x))

        modulo = modulo // gcd
        coeff = (coeff * x // gcd) % modulo
        offset = (offset * x // gcd) % modulo
    elif t == '?':
        x -= 1
        
        if math.gcd(x-offset, modulo) > 1:
            print(-1)
            continue


