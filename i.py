from collections import Counter
def factorial(n):
    if n==0:
        return 1
    else:
        return n*factorial(n-1)

def gcd(x,y):
    while y:
        x,y=y,x%y
    return x

def cc(c,n):
    ccc=factorial(n)
    for a,b in Counter(c).items():
        ccc//=(a**b)*factorial(b)
    return ccc
def cp(n,i=1):
    yield [n]
    for i in range (i,n//2+1):
        for p in cp(n-i,i):
            yield [i] + p
def solution(w, h, s):
    g=0
    for cw in cp(w):
        for ch in cp(h):
            m=cc(cw,w)*cc(ch,h)
            g+=m*(s**sum([sum([gcd(i, j) for i in cw]) for j in ch]))
    ans = str(g//(factorial(w)*factorial(h)))
    return ans


print(solution(2,3,4))


