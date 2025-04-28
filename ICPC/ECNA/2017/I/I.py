a,b,c,d = [int(x) for x in input().split()]

large = 100000000000000000000000000000000000000000000000

def evaluate(nums, ops, parens, verbose=False):
    if len(parens) == 1 and (parens[0] == (0,2)):
        val = evaluate(nums[:3],ops[:2],[])
        if val == large:
            return large
        nums = [val, nums[-1]]
        ops = [ops[-1]]
    elif len(parens) == 1 and (parens[0] == (1,3)):
        val = evaluate(nums[1:],ops[1:],[], verbose=verbose)
        if val == large:
            return large
        if verbose:
            print(val)
            print(nums[1:], ops[1:])
        nums = [nums[0], val]
        ops = [ops[0]]
    else:
        for i,j in parens:
            op = ops[i]
            a,b = nums[i], nums[j]

            if op == '+':
                val = a+b
            elif op == '-':
                val = a-b
            elif op == '*':
                val = a*b
            elif op == '/':
                if b == 0 or not a % b == 0:
                    return large
                val = a // b
            else:
                assert False, 'error'
            
            ops.pop(i)
            nums.pop(j)
            nums.pop(i)
            nums.insert(i,val)
    
    while len(nums) > 1:
        if verbose:
            print(nums)
        index = -1
        use_op = ''
        for i,op in enumerate(ops):
            if op == '*':
                index = i
                use_op = op
                break
            elif op == '/':
                index = i
                use_op = op
                break
        
        if index == -1:
            index = 0
            use_op = ops[0]

        a = nums[index]
        b = nums[index+1]
        if use_op == '+':
            val = a+b
        elif use_op == '-':
            val = a-b
        elif use_op == '*':
            val = a*b
        elif use_op == '/':
            if b == 0 or not a % b == 0:
                return large
            val = a // b
        else:
            assert False, 'error2'

        ops.pop(index)
        nums.pop(index+1)
        nums.pop(index)
        nums.insert(index,val)
    
    num = nums[0]
    return num


parens = [
    [],
    [(0,1)],
    [(1,2)],
    [(2,3)],
    [(0,1),(0,1)],
    [(0,1),(1,2)],
    [(2,3),(1,2)],
    [(2,3),(0,1)],
    [(1,2),(0,1)],
    [(1,2),(1,2)],
    [(0,2)],
    [(1,3)]
]
ops = ['+','-','*','/']
permutes = [
    (a,b,c,d,0),
    (a,b,d,c,1),
    (a,c,b,d,1),
    (a,c,d,b,2),
    (a,d,b,c,2),
    (a,d,c,b,3),
    (b,a,c,d,1),
    (b,a,d,c,2),
    (b,c,a,d,2),
    (b,c,d,a,3),
    (b,d,a,c,3),
    (b,d,c,a,4),
    (c,a,b,d,2),
    (c,a,d,b,3),
    (c,b,a,d,3),
    (c,b,d,a,4),
    (c,d,a,b,4),
    (c,d,b,a,5),
    (d,a,b,c,3),
    (d,a,c,b,4),
    (d,b,a,c,4),
    (d,b,c,a,5),
    (d,c,a,b,5),
    (d,c,b,a,6),
]


p = 47
count = 0

minimum = large
for op1 in ops:
    for op2 in ops:
        for op3 in ops:
            for paren in parens:
                for a,b,c,d,grade in permutes:
                    # count += 1
                    # if count % p == 0:
                    #     print(a,b,c,d)
                    #     print(op1,op2,op3)
                    #     print(paren)
                    #     print(val)
                    #     print()

                    val = evaluate([a,b,c,d], [op1,op2,op3],paren)
                    # if len(paren) > 0 and paren[0] == (1,3) and (op1,op2,op3) == ('*','+','-') and (a,b,c,d) == (3,5,5,2):
                        # print(a,b,c,d)
                        # print(op1,op2,op3)
                        # print(paren)
                        # print(val)
                        # evaluate([a,b,c,d], [op1,op2,op3],paren, verbose=True)
                    if val == large or val != 24:
                        continue
                    else:
                        # print(val)
                        minimum = min(minimum, len(paren)+2*grade)
                    
                        # print(a,b,c,d)
                        # print(op1,op2,op3)
                        # print(paren)

if minimum == large:
    print('impossible')
else:
    print(minimum)