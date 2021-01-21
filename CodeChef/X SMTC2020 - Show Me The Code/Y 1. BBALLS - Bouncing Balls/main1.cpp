// solved with python
//
//
//import sys
//
//readLine = lambda: sys.stdin.readline()
//readInt = lambda: int(sys.stdin.readline())
//readInts = lambda: [int(x) for x in sys.stdin.readline().split(" ")]
//
//for _ in range(readInt()):
//    d = readInt()
//    solution = 0
//    for i in bin(d)[2:]:
//        if i == "1":
//            solution += 1
//    print(solution - 1)