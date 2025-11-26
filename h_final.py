from decimal import Decimal
from decimal import localcontext
import math
def solution(s):
    n=int(s)
    with localcontext() as xx:
        xx.prec = 1000
        def get(n):
            n1=(Decimal(2).sqrt()-1)
            n1=n1*Decimal(n)
            n1=int(n1)
            if n==0:
                return str(0)
            else:
                tot = n*n1 + (n*(n+1))/2 - (n1*(n1+1))/2
                return str(int(tot) - int(get(int(n1))))
        return str(int(get(n)))
        