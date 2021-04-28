def str_replace(s, i, c):
    tmp = list(s)
    tmp[i] = c
    return "".join(tmp)

n, m = map(int, input().split())

if n == 1:
    res = 0
    for j in range(m):
        i, c = map(int, input().split())
        if j != 0 and res != c:
            print(-1)
            exit()
        if j == 0:
            res = c
    print(res)
    exit()


res = int(10**n / 10)

res = str(res)
NG = False

dic = {}

for i in range(m):
    dic[i] = False

for i in range(m):
    s, c = map(int, input().split())
    s -= 1
    if not dic[s]:
        dic[s] = True
        tmp = list(res)
        tmp[s] = str(c)
        res = "".join(tmp)
        # print(res)
    elif str(c) != res[s]:
        NG = True
        # print(c, res[i])
        break
    if s == 0 and c == 0:
        NG = True
        # print(c, res[i])
        break


if NG:
    print(-1)
else:
    print(res)
