# from decimal import Decimal, localcontext

# def ssolution(s):
#     n = Decimal(s)
#     with localcontext() as ctx:
#         ctx.prec = 102
#         r = Decimal(2).sqrt()
#         s = Decimal(2) + Decimal(2).sqrt()
#         print("r,s ",r," ",s)

#         def solve(n):
#             if n == 0:
#                 return 0
#             Brn = int(r * n)
#             Brns = int(Decimal(Brn) / s)

#             return (Brn * (Brn + 1)) / 2 - solve(Brns) - Brns * (Brns + 1)

#         return str(int(solve(n)))

# print(solution('5'))





# from decimal import Decimal
# from decimal import localcontext
# import math
# def solution(s):
#     n=int(s)
#     with localcontext() as xx:
#         xx.prec = 1000
#         def get(n):
#             n1=(Decimal(2).sqrt()-1)
#             n1=n1*Decimal(n)
#             n1=int(n1)
#             if n==0:
#                 return str(0)
#             else:
#                 tot = n*n1 + (n*(n+1))/2 - (n1*(n1+1))/2
#                 return str(int(tot) - int(get(int(n1))))
#         return str(int(get(n)))
# print(solution("77"))
# # # def brute(s):
# #     n=int(s)
# #     ans=0
# #     sqrt=math.sqrt(2)
# #     for i in range(1,n+1):
# #         ans+=(math.floor(i*sqrt))
# #     return str(ans)
# s=""
# for i in range (102):
#     s+='1'
# print(solution("987657")," ",ssolution("987657"))


# from decimal import Decimal, localcontext
# def solution(s):
#     x = Decimal(s)
#     with localcontext() as ctx:
#         ctx.prec = 10
#         def get(x):
#             if x == 0:
#                 return 0
#             x = int((Decimal(2).sqrt())*x)
#             y = int(Decimal(x) / (Decimal(2) + Decimal(2).sqrt()))
#             return (x*(x+1))/2-y*(y+1)-get(y)
#         return str(int(get(x)))
# print(solution("77"))









# from decimal import Decimal
# from decimal import localcontext
# import math
# def solution(s):
#     x = int(s)
#     with localcontext() as xx:
#         xx.prec = 1000
#         def get(x):
#             if x == 0:
#                 return 0
#             x = int((Decimal(2).sqrt())*x)
#             y = int(x / (2 + Decimal(2).sqrt()))
#             return (x*(x+1))/2-y*(y+1)-get(y)
#         return str(int(get(x)))






# final uploaded solution

# from decimal import Decimal
# from decimal import localcontext
# import math
# def solution(s):
#     n=int(s)
#     with localcontext() as xx:
#         xx.prec = 1000
#         def get(n):
#             n1=(Decimal(2).sqrt()-1)
#             n1=n1*Decimal(n)
#             n1=int(n1)
#             if n==0:
#                 return str(0)
#             else:
#                 tot = n*n1 + (n*(n+1))/2 - (n1*(n1+1))/2
#                 return str(int(tot) - int(get(int(n1))))
#         return get(n)
        
# print(solution("77"))