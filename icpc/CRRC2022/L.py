week = dict()
week["monday"] = 0
week["tuesday"] = 1
week["wednesday"] = 2
week["thursday"] = 3
week["friday"] = 4
week["saturday"] = 5
week["sunday"] = 6

WEEK_MINUTES = 7 * 24 * 60

ans_in = 1e9
ans_out = 1e9

def minus(d1, d2):
    a1 = d1[0] * 60 * 24 + d1[1] * 60 + d1[2]
    a2 = d2[0] * 60 * 24 + d2[1] * 60 + d2[2]
    if (a1 < a2):
        return a1 - a2 + WEEK_MINUTES
    return a1 - a2


def readTwoDates(in_put):
    d1 = [
        week[in_put[0]],
        int(in_put[1].split(':')[0]),
        int(in_put[1].split(':')[1])
    ]
    d2 = [
        week[in_put[2]],
        int(in_put[3].split(':')[0]),
        int(in_put[3].split(':')[1])
    ]
    return d1,d2


d_start, d_finish = readTwoDates(input().split())

rzd_in, rzd_out = map(int, input().split())

for i in range(rzd_in):
    d1, d2 = readTwoDates(input().split())
    res = minus(d2, d1)
    res += minus(d_start, d2)
    ans_in = min(ans_in, res)

for i in range(rzd_out):
    d3, d4 = readTwoDates(input().split())
    res = minus(d3, d_finish)
    res += minus(d4, d3)
    ans_out = min(ans_out, res)

print(ans_in + ans_out + minus(d_finish, d_start))