
def gcd(x,y):
    while y:
        x, y = y, x % y
    return x

# def ok(x,y):
#     num = int((x+y)/gcd(x,y))
#     return bool(num & (num - 1))
def ok(x,y):
    num = int((x+y)/gcd(x,y))
    ret=num.bit_count()
    if ret==1:
        return 0
    else :
        return 1

def make(banana_list):
    gp = {i: [] for i in range(len(banana_list))}
    for i in range(len(banana_list)):
        for j in range(i, len(banana_list)):
            if i != j and ok(banana_list[i], banana_list[j]):
                gp[i].append(j)
                gp[j].append(i)
    return gp

def find(gp):
    total_busy = 0
    has = len(gp[max(gp, key=lambda key: len(gp[key]))])

    while len(gp) > 1 and has >= 1:
        cur = min(gp, key=lambda key: len(gp[key]))

        if (len(gp[cur])) < 1 :
            del gp[cur]
        else:
            was = [len(gp[gp[cur][0]])+1,1]

            for now in gp[cur]:
                if len(gp[now]) < was[0]:
                    was = [len(gp[now]), now]
                for v in range(len(gp[now])):
                    if gp[now][v] == cur:
                        del gp[now][v]
                        break

            for now in gp[was[1]]:
                for v in range(len(gp[now])):
                    if gp[now][v] == was[1]:
                        del gp[now][v]
                        break
            del gp[was[1]]        
            del gp[cur]
            
            total_busy += 2

        if len(gp) > 1:
            has = len(gp[max(gp, key=lambda key: len(gp[key]))])

    return total_busy

def solution(banana_list):
    gp = make(banana_list)
    total_busy = find(gp)
    return len(banana_list) - total_busy


print(solution([1, 7, 3, 21, 13, 19]))
# print(solution([1]))
# print(solution([1, 7, 1, 1]))
# print(solution([1,1]))
