def calc(n, k):
    Up=k
    Dn=0 
    while(Up-Dn>1): 
        Md=(Up+Dn)//2
        cnt, aux=0,  1
        for i in range (1,min(n, Md) +1):
                aux=aux*(Md-i+1)//i
                if(aux>=k) :
                    cnt=k
                    break 
                cnt+=aux;
                if(cnt>=k) :
                     break
        
        if(cnt<k):
            Dn=Md
        else :
            Up=Md
  
    return Dn+1

i, j=map (int, input (). split ())
ans=[]
while i>0:
    ans. append (str(calc (min(60,i),j))) 
    i, j=map (int, input (). split ())
print ("\n". join (ans) ) 
    
