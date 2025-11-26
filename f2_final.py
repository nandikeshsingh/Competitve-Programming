import math

def gcd(x,y):
    while y:
        x, y = y, x % y
    return x
    
def bitsoncount(x):
    return bin(x).count('1')
    
def ok(x,y):
    num = int((x+y)/gcd(x,y))
    ret=bitsoncount(num)
    if ret==1:
        return 0
    else:
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

    while has >= 1 and len(gp) > 1:
        cur = min(gp, key=lambda key: len(gp[key]))

        if (len(gp[cur])) < 1 :
            del gp[cur]
            
        else:
            was = [len(gp[gp[cur][0]])+1,1]

            for u in gp[cur]:
                if len(gp[u]) < was[0]:
                    was = [len(gp[u]), u]
                for v in range(len(gp[u])):
                    if gp[u][v] == cur:
                        del gp[u][v]
                        break

            for u in gp[was[1]]:
                for v in range(len(gp[u])):
                    if gp[u][v] == was[1]:
                        del gp[u][v]
                        break
            del gp[was[1]]        
            del gp[cur]
            
            total_busy += 2

        if len(gp) > 1:
            has = len(gp[max(gp, key=lambda key: len(gp[key]))])

    return total_busy

def solution(banana_list):
    return len(banana_list) - find(make(banana_list))

