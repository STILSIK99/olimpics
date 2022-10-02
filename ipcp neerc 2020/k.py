m = [[] for i in range(10)]
for x in range(0,10):
    for y in range(0,10):
        if sorted([x, y]) not in m[(x * y) % 10]:
            m[(x * y) % 10].append(sorted([x, y]))
for i in range(10):
    print(i, m[i])
