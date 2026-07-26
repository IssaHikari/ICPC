import math
x, y, n = [int(x) for x in input().split()]
def f(z,w):
    return abs(w*x-z*y)
if y <= n:
    g = math.gcd(x, y)
    print(f"{x//g}/{y//g}")
else:
    b = n
    a = min(((b*x)//y),((b*x)//y)+1, key = lambda t: f(t,b))
    if f((b*x)//y, b) == f(((b*x)//y)+1, b):
        a = (b*x)//y
    for i in range(n-1,0,-1):
        b1 = i
        a1 = min(((b1*x)//y),((b1*x)//y)+1, key = lambda t: f(t,b1))
        if f((b1*x)//y, b1) == f(((b1*x)//y)+1, b1):
            a1 = max(((b1*x)//y)-1,0)
        if abs(b*(b1*x-a1*y))<abs(b1*(b*x-a*y)):
            a,b= a1,b1
        elif abs(b*(b1*x-a1*y))==abs(b1*(b*x-a*y)):
            a,b= a1,b1
    print(f"{a}/{b}")