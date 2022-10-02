t = int(input())
for tt in range(t):
    n,k = map(int,input().split())
    k += 1
    steps = list(map(lambda x: 10**int(x),input().split()))
    ans = 0
    if n == 1:
        print(k+1)
        continue
    for i in range(0,n-1):
        count = steps[i+1]//steps[i] - 1
        ans += min(count, k) * steps[i]
        k -= min(count, k)

    ans += k * steps[n-1]
    print(ans)