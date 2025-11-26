import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n,x=get_ints()
# n=int(input())
# x=int(input())
aa=input().split()
a=[]
for i in aa:
    a.append(int(i))
fx=1
for i in range(1,x+1):
    # print(i)
    fx=fx*i
    # print(fx)
tot=[]
tot.append(1)
cur=1
for i in range(1,500001):
    cur=(cur*i)%fx
    tot.append(cur)
ans=0
for i in a:
    ans=(ans+tot[i])%fx
if(ans==0):
    print("Yes")
else:
    print("No")


