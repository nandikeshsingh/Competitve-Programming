l=[1,2,3,4,5,6]
cnt=0
for i in range(1,len(l)-1):
    left=0
    right=0
    for j in range(0,i):
        if(l[i]%l[j] == 0):
            left+=1
    for j in range(i+1,len(l)):
        if(l[j]%l[i] == 0):
            right+=1
    cnt+=(left*right)
print(cnt)

        