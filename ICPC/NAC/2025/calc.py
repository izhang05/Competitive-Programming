# 511374200 637192506 100000000
from math import sqrt

# c = 511374200
# a = 637192506
# b = 100000000

c, a, b = 500000003, 600000010, 1

# optx = int(sqrt(2) * c / a)
# opty = int(sqrt(2) * c / b)
optx = sqrt(2) * c / a
opty = sqrt(2) * c / b

print(optx, opty)

print(optx*optx*a*a+ opty*opty*b*b, 4*c*c)

# print(a * a + b * b * 64)
# print(4 * c * c)
