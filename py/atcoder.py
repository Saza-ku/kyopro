def pow(x, n):
    """
    O(log n)
    """
    if n == 0:  # exit case
        return 1
    if n % 2 == 0:  # standard case ① n is even
        return pow(x ** 2, n // 2)
    else:  # standard case ② n is odd
        return x * pow(x ** 2, (n - 1) // 2)

def f(n, s):
    ret = 0
    for i in range(len(s)):
        try:
            ret += pow(n, i) * int(s[i])
        except:
            return int(2e18)
    return ret


s = input()
M = int(input())

if(len(s) == 1):
    x = int(s)
    if x <= M:
        print(1)
    else:
        print(0)
    exit()

d = 0
for i in range(len(s)):
    d = max(d, int(s[i]))

ok = 0
ng = int(1e18)
s = s[::-1]
while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    if f(mid, s) <= M:
        ok = mid
        #print(f(mid, s))
    else:
        ng = mid

print(max(0, ok - d))