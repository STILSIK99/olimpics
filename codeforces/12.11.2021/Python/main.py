import math

h, d = map(int, input().split())
r = d/2
tg_a = 0.6745085168
tg_b = h/r
R = (h)/ (tg_a + tg_b)

v = math.pi * R * R * h / 3
print(v)

