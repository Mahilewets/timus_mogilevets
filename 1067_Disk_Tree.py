n=int (input ()) 
trie=[{} for i in range (50000)]
used={} 
first_free=1
for i in range (n) :
    path =raw_input () 
    ptr=0
    for folder in path.replace("\\", " "). split () :
        cur=trie[ptr] 
        if folder in cur:
            ptr=cur[folder] 
        else:
            trie[ptr][folder]=first_free
            used[(ptr, first_free)]=False
            ptr=first_free
            first_free+=1

def dfs (depth, ver) :
    cur=trie[ver] 
    adj=tuple(sorted(list(cur))) 
    for to in adj:
        next=cur[to] 
        if not used[(ver, next) ] : 
            used[(ver, next)] =True
            print (depth*" "+to) 
            dfs(depth+1,next)

dfs(0,0)
