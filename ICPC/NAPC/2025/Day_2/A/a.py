n = int(input())

out = 1
for i in range(1, n+1):
    out *= i * i / n

print(str(out))