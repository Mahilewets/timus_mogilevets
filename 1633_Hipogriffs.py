a1, b1= map (int, input (). split ()) 
a2, b2= map (int, input (). split ())
from math import sqrt 

def calc_danger(A, B) :
    new_A=a1*A+b1*B
    new_B=a2*A+b2*B
    return sqrt((new_A**2+new_B**2)/(A**2+B**2))



iters=100

def search_b(a) :
    l=0
    r=10**18
    for i in range (iters) :
        d=(r-l)/3
        m1=l+d
        m2=r-d
        f1=calc_danger (a, m1) 
        f2=calc_danger (a, m2) 
        if f1>f2:
            r=m2
        else:
            l=m1
    return (l+r) /2
    
def search_ans() :
    l=0
    r=10**18
    for i in range (iters) :
        d=(r-l)/3
        m1=l+d
        m2=r-d
        f1=calc_danger (m1, search_b(m1)) 
        f2=calc_danger (m2, search_b(m2)) 
        if f1>f2:
            r=m2
        else:
            l=m1
    return calc_danger ((l+r) /2, search_b((l+r) /2) ) 
    
print (search_ans()) 
