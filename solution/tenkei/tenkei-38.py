def gcd(x, y):
    a = max(x, y)
    b = min(x, y)
    r = a % b
    if r == 0:
        return b
    return gcd(b, r)

a, b = map(int, input().split())

d = gcd(a, b)
p = a // d
q = b

if p * q > 1000000000000000000:
    print("Large")
    exit()

print(int(p * q))
