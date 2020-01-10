n, m=map (int, input (). split ()) 
house=[]
place={}
rev_place={} 
sz=0
for i in range (n) :
    house.append(input ()) 
    for j in range (m) :
        if(house[i][j] ==".") :
            place[sz]=i*m+j
            rev_place[place[sz]]=sz
            sz+=1
from fractions import gcd
matrix=[[0 for i in range (sz)] for i in range (sz)] 
for x in range (sz):
    order=place[x] 
    i=order//m
    j=order%m
    if(j>0 and house[i][j-1]=='.'):
        matrix[x][x]-=1
        matrix[x][rev_place[i*m+j-1]]=1
    if(i>0 and house[i-1][j]=='.'):
        matrix[x][x]-=1
        matrix[x][rev_place[(i-1)*m+j]]=1
    if(j<m-1 and house[i][j+1]=='.'):
        matrix[x][x]-=1
        matrix[x][rev_place[i*m+j+1]]=1
    if(i<n-1 and house[i+1][j]=='.'):
        matrix[x][x]-=1
        matrix[x][rev_place[(i+1)*m+j]]=1
 
det=1
det_denom=1
row=0
col=0
sz-=1
while (row<sz and col<sz-1) :
    max_abs=abs(matrix[row][col]) 
    next_row=row
    for i in range (row+1,sz):
        cur_abs=abs(matrix [i][col]) 
        if(cur_abs>max_abs):
            max_abs=cur_abs
            next_row=i
    if(max_abs==0):
        det=0
        break
    for i in range (sz) :
        matrix[row][i], matrix[next_row][i]=matrix[next_row][i], matrix[row][i] 
    for i in range (row+1,sz):
        if(matrix[i] [col]!=0):
            GCD=gcd(matrix [row] [col], matrix[i] [col] )
            LCM=matrix [row] [col] *matrix[i] [col] //GCD
            m1=LCM//matrix[row] [col] 
            m2=LCM//matrix[i] [col] 
            det_denom*=m1*m2
            for j in range (col, sz) :
                matrix[row][j]*=m1
                matrix[i][j]*=m2
                matrix[i][j]-=matrix[row][j] 
    row+=1
    col+=1
    
for i in range (sz):
    det*=matrix[i][i] 
M=10**9    
det=(abs(det//det_denom))%M
if(sz==0):
    det=1
print(str(det) ) 
