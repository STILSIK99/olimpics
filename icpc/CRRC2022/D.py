n, k, m = map(int, input().split())

if (m > (n - k)):
    print(1)
else:
    if (n - k == 0):
        print(0)
    else:
        ans = 1
        for i in range(m):
            ans *= (n - k - i) / (n - i)
        print(1 - ans)
