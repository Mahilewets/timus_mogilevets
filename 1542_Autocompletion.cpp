#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cctype>

using std::string;
using std::pair;
using std::sort;
using std::vector;
using std::max;
using std::min;
using std::lower_bound;
using std::upper_bound;

char buff[1<<22], *pbuff=buff;

void read_string(string &s){
   s.reserve(1<<4);
   while(!isalpha(*pbuff))
       ++pbuff;
   while(isalpha(*pbuff))
       s.push_back(*pbuff), ++pbuff;
}

void print_string(const string &s){
   for(char ch: s){
       _putchar_nolock(ch);
   }
}

void read_int(int &x){
   x=0;
   while(!isdigit(*pbuff))
       ++pbuff;
   while(isdigit(*pbuff))
      x=(x<<1) + (x<<3) + *pbuff - '0', ++pbuff;
}

pair<string, int> words[1<<17];
int tree[1<<19], n;

void build(int l, int r, int i=1){

    if(l>r){
        return;
    }

    if(l==r){
        tree[i]=l;
        return;
    }

    int m=(l+r)>>1,
        j=i<<1,
        k=j|1;

    build(l, m, j);
    build(m+1, r, k);

    int j_res=tree[j],
        k_res=tree[k];

    if(words[j_res].second < words[k_res].second)
        tree[i]=k_res;

    else
        tree[i]=j_res;

}

void upd(int val, int pos, int tl, int tr, int i=1){

    if(tl==tr){
        tree[i]=val;
        return;
    }

    int tm=(tl+tr)>>1, j=i<<1, k=j|1;

    if(pos<=tm)
        upd(val, pos, tl, tm, j);
    else
        upd(val, pos, tm+1, tr, k);

    int j_res=tree[j], k_res=tree[k];

    if(words[j_res].second < words[k_res].second)
        tree[i]=k_res;
    else
        tree[i]=j_res;
}

int query(int l, int r, int tl, int tr, int i=1){

   if(l>r){
       return 0;
   }

   if(l==tl && r==tr){
      return tree[i];
   }

   int tm=(tl+tr)>>1,
       j=i<<1,
       k=j|1,
       j_res=query(l, min(tm, r), tl, tm, j),
       k_res=query(max(l, tm+1), r, tm+1, tr, k);


   if(words[j_res].second < words[k_res].second){
      return k_res;
   }

   return j_res;
}


int main(){

    fread(buff, 1, sizeof(buff), stdin);

    read_int(n);

    words[0]=pair<string,int>("",-1);

    for(int i=1; i<=n; ++i){
        read_string(words[i].first);
        read_int(words[i].second);
    }

    sort(words, words+n+1);

    build(0, n);

    int m;
    read_int(m);

    for(int i=0; i<m; ++i){

        string curr;
        read_string(curr);

        int l=lower_bound(words, words+n+1, pair<string,int>(curr,-1))-words,
            r=upper_bound(words, words+n+1, pair<string,int>(curr+"zzzzzzzzzzzzzz",-1))-words-1;

        if(l>r){

            if(i<m-1){
                _putchar_nolock('\n');
            }

            continue;
        }

        vector<int> ans;
        ans.reserve(1<<4);

        for(int j=0; j<min(r-l+1, 10); ++j){
            int res=query(l, r, 0, n);
            ans.push_back(res);
            upd(0, res, 0, n);
        }

        for(int res: ans){
            print_string(words[res].first);
            _putchar_nolock('\n');
            upd(res, res, 0, n);
        }

        if(i<m-1){
            _putchar_nolock('\n');
        }
    }

    return 0;
}
