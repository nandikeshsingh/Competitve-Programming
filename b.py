x=100000
y=100000
ty=1+((y*(y-1)/2))
cur=0
cd=y+1
for i in range(x-1):
    cur=cur+cd
    cd+=1
cur=cur+ty
print(str(cur))

    