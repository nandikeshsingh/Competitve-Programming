def solution(x, y):
    m=int(x)
    f=int(y)
    print("m=",m," f=",f)
    ans=0
    while(m!=f):
        print("printing ",m,f)
        if(m==1 and f>1):
            ans+=f-m
            break
        elif(m>1 and f==1):
            ans+=m-f
            break
        ans+=1
        if(m>f):
            m=m%f
        elif(f>m):
            f=f%m
    if(m!=1 and f!=1):
        return "impossible"
    else:
        return str(ans)
    # Your code here

print(solution('2','1'))