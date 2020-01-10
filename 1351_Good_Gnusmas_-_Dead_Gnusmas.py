D, X1, Y1, X2, Y2=map(int, input (). split ())
det=X1*Y2-X2*Y1 
D2=D*D
if det<0:
    X1, Y1=X2, Y2
N=int (input ()) 
ans=[] 
for i in range (N) :
    X, Y=map(int, input (). split ()) 
    if  X*X+Y*Y<=D2 and ( (det!=0 and X*Y1-Y*X1<=0 and X*Y2-Y*X2>=0) or (det==0 and X*X1+Y*Y1>0 and X*Y1-Y*X1==0)) :
        ans. append ("YES") 
    else :
        ans. append ("NO") 
print ("\n". join (ans))
