n=int (input ()) 
from decimal import Decimal as dec
s=dec(0)
for i in range (n) :
    s+=dec(input ()) 
t=s.as_tuple ()[1] 
e=s.adjusted()
ans=str(t[0])+'.'
for i in range (1,len(t)):
    ans+=str(t[i])
ans+='e'+str(e) 
print (ans ) 
