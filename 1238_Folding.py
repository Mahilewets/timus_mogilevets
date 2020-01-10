s=raw_input () 
n=len(s) 
dp=[{} for i in range (n)]
ans = [{} for i in range (n)] 
for l in range (1,n+1):
    for p in range (n-l+1):
        pe=p+l-1
        dp[p] [pe] =l
        ans[p] [pe] =s[p:p+l] 
        for m in range (p, pe) :
            if dp[p] [pe]>dp[p][m]+dp[m+1][pe]:
                dp[p][pe] = dp[p][m]+dp[m+1][pe]
                ans[p][pe]=ans[p][m]+ans[m+1][pe]
        pi=[0 for i in range (l)] 
        for i in range (1,l):
            k=pi[i-1]
            while k and s[p+k]!=s[p+i] :
                k=pi[k-1]
            if s[p+k]==s[p+i]:
                k+=1
            pi[i] = k
        lastp=pi[l-1];
        per=l-lastp
        cnt=l//per
        if per*cnt==l:
            numbr=str(cnt) 
            curlen=len(numbr)+2+dp[p][p+per-1] 
            if dp[p][pe]>curlen:
                dp[p][pe] = curlen
                ans[p][pe] = numbr+"("+ans[p][p+per-1]+")"
                


            
print (ans[0][n-1])           
