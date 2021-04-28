X, Y, a, b = map(int, input().split())

res = 0

str = X

while a * str < str + b:
    if a * str >= Y:
        break
    str *= a
    res += 1
    
r = Y - str




res += r // b

if r % b == 0:
    res -= 1

print(res)