n = int(input())

bad_drives = []
good_drives = []
for _ in range(n):
    args = [int(x) for x in input().split()]
    a, b = args
    if a > b:
        bad_drives.append((b,a))
    else:
        good_drives.append((a,b))

bad_drives.sort(reverse=True)
good_drives.sort()

# print(bad_drives)
# print(good_drives)

out = 0
available = 0

for a,b in good_drives:
    if a > available:
        out += a-available
        available = a
    available += b-a

    # print(out, available, a, b)

for b,a in bad_drives:
    if a > available:
        out += a-available
        available = a
    available += b-a

    # print(out, available, a, b)

print(out)
