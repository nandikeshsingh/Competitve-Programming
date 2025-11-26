def all_pairs(lst):
    if len(lst) < 2:
        yield []
        return
    if len(lst) % 2 == 1:
        # Handle odd length list
        for i in range(len(lst)):
            for result in all_pairs(lst[:i] + lst[i+1:]):
                # print("inside")
                # print(result)

                yield result
    else:
        a = lst[0]
        for i in range(1,len(lst)):
            pair = (a,lst[i])
            for rest in all_pairs(lst[1:i]+lst[i+1:]):
                # print([pair]+rest)
                yield [pair] + rest

lst=[]
for i in range(4):
    lst.append(i+1)
ans=all_pairs(lst)
print(ans)
cnt=0
for i in ans:
    cnt+=1
    print(i)
print("total count =",cnt)

val=1
for i in range(1,100):
    if(i%2):
        val=val*i
print("val=",val)