#include <cstdio>
#include <cstring>

const int MAX_N=80000;
int N, M, P, tree[MAX_N*4][5], arr[MAX_N];


void build(int l, int r, int i=1){
    if(l>r) return;
    if(l==r){
        tree[i][0]=1;
        tree[i][1]=(arr[l]+10000000LL*P)%P;
        return;
    }
    int m=(l+r)>>1, j=i<<1, k=j|1;
    build(l, m, j);
    build(m+1, r, k);
    tree[i][0]=1;
    for(int it=1; it<=4; ++it){
        for(int it2=0; it2<=it; ++it2){
            tree[i][it]=(1LL*tree[j][it2]*tree[k][it-it2]+tree[i][it])%P;
        }
    }
}

void update(int pos, int val, int tl, int tr, int i=1){
   if(tl==tr){
         tree[i][1]=(tree[i][1]+val+100000LL*P)%P;
         return;
   }
   int tm=(tl+tr)>>1, j=i<<1, k=j|1;
   if(pos<=tm){
       update(pos, val, tl, tm, j);
   }
   else{
       update(pos, val, tm+1, tr, k);
   }
   for(int it=1; it<=4; ++it){
        tree[i][it]=0;
        for(int it2=0; it2<=it; ++it2){
            tree[i][it]=(1LL*tree[j][it2]*tree[k][it-it2]+tree[i][it])%P;
        }
    }
}

void query(int *res, int l, int r, int tl, int tr, int i=1){

    if(l==tl && r==tr){
        memcpy (res, tree[i],sizeof(tree[i]));
        return ;
    }

    int tm=(tl+tr)>>1, j=i<<1, k=j|1;

    if(r<=tm){
       query(res, l, r, tl, tm, j);
       return;} 

    if(l>=tm+1){
        query(res, l, r, tm+1, tr, k);
        return ;} 

    int left[5], right[5];
    query(left, l, tm, tl, tm, j);
    query(right, tm+1, r, tm+1, tr, k);
    res[0]=1;
    for(int it=1; it<=4; ++it){
        res[it]=0;
        for(int it2=0; it2<=it; ++it2){
            res[it]=(1LL*left[it2]*right[it-it2]+res[it])%P;
        }
    }
}

int main(){


    scanf("%d %d %d", &N, &M, &P);

    for(int *it=arr; it!=arr+N; ++it){
        scanf("%d", it);
    }

    build(0, N-1);

    for(int i=M; i; --i){
        char type=getchar();
        while(type<'C'){
            type=getchar();
        }
        if(type=='C'){
            int left, right, K;
            scanf("%d %d %d", &left, &right, &K);
            int aux[5];
            query(aux,left-1, right-1, 0, N-1);
            for(int j=0; j<=K; ++j){
                printf("%d ", aux[j]);
            }
            putchar('\n');
        }
        else{
           int index, val;
           scanf("%d %d", &index, &val);
           update(index-1, val, 0, N-1);
        }
    }
    return 0;
}
