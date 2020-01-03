pow=[1] 
n, m=map (int, input (). split ()) 
for i in range (n):
    pow. append (pow[i] *26)
pow_sum=[0] 
for i in range (n) :
    pow_sum. append (pow_sum[i] +pow[i+1])
def kth_word(x) :
    k=x-1
    word_len=1
    while pow_sum[word_len]<k :
        word_len+=1
    k=k-pow_sum[word_len-1]
    ans=["a" for i in range (word_len) ] 
    for i in range (word_len) :
        cur_char=k//(pow[word_len-i-1])+ord("a") 
        k=k%(pow[word_len-i-1])
        ans[i]=chr(cur_char)
    return "". join (ans)
total=pow_sum[n] 
part=total//m
remain=total%m
cur=1
for i in range (m) :
    extra=0
    if remain :
        extra =1
        remain-=1
    print (kth_word(cur) +"-"+kth_word(extra+cur+part-1))
    cur+=part+extra
    
