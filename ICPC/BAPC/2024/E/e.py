n = int(input())

print('?', 1)
x = int(input())
print('?', n)
z = int(input())

avg = (x+z) / 2

a = 2
b = n-1

low = a
lowi = 1
high = b
highi = n
while a <= b:
    m = (a+b) // 2
    print('?', m)
    y = int(input())

    if y <= avg:
        low = y
        lowi = m
        a = m+1
    else:
        high = y
        highi = m
        b = m-1

best = -100000
besti = -1
def calc(x,y,z):
    return (abs(x-y)**0.5 + abs(y-z)**0.5 + abs(z-x)**0.5)

if lowi > 1:
    best = max(best, calc(x,low,z))
    besti = lowi
if highi < n:
    if calc(x,high,z) > best:
        besti = highi
        best = calc(x,high,z)

print('!', 1, besti, n)

