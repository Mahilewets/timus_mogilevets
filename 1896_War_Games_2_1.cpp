#include <cstdio>

int tree[1<<25], n;

inline void upd(int pos, int delta){
    while(1){
        if(pos>n){
            return;
        }
        tree[pos]+=delta;
        pos+=(pos&-pos);
    }
}

inline int find_kth(int k){
   int res=0, mask=1<<20;

   while(mask){
       int tmp_res=res+mask;
       if(tmp_res>n){
           mask>>=1;
           continue;
       }
       int tmp_k=k-tree[tmp_res];
       if(tmp_k>=0){
            res=tmp_res;
            k=tmp_k;
       }
       mask>>=1;
   }
   return res;
}


int main(){

    int k=0, ans=0, cur=0;

    scanf("%d %d", &n, &k);

    for(int i=2; i<=n; ++i){
        upd(i, 1);
    }


    for(int i=1; i<n+1; ++i){

        cur=(cur+k-1)%(n-i+1);

        int x=find_kth(cur);

        int y=x-i, mask=y>>31;
        ans^=(y+mask)^mask;
        upd(x+1, -1);
    }

    printf("%d", ans);

    return 0;
}
