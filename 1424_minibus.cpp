#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
using std::pair;

inline void read_int(int &x){
    x=0;
    int ch=_getchar_nolock();
    while(ch<'0'){
        ch=_getchar_nolock();
    }
    while(ch>='0'){
        x=(x<<1) + (x<<3) + ch - '0';
        ch=_getchar_nolock();
    }
}

struct seg_tree{
    vector<int> tree_max, tree_add;
    seg_tree(int n){
        tree_max.resize(n<<2, 0);
        tree_add.resize(n<<2, 0);
    }
    void increment_range(int l, int r, int tl, int tr, int i=1){
        if(l>r)
            return;
        if(l==tl && r==tr){
            ++tree_add[i];
            return;
        }
        int tm=(tl+tr)>>1, j=i<<1, k=j|1;
        increment_range(l, std::min(tm, r), tl, tm, j);
        increment_range(std::max(l, tm+1), r, tm+1, tr, k);
        tree_max[i]=std::max(tree_add[j]+tree_max[j], tree_add[k]+tree_max[k]);
    }

    int range_max(int l, int r, int tl, int tr, int i=1){
        if(l>r)
            return 0;
        if(l==tl && r==tr)
            return tree_add[i]+tree_max[i];
        int tm=(tl+tr)>>1, j=i<<1, k=j|1,
            left_max=range_max(l, std::min(tm, r), tl, tm, j),
            right_max=range_max(std::max(l, tm+1), r, tm+1, tr, k);
        return std::max(left_max, right_max) + tree_add[i];
    }

};


void find_answer_minibus(const int n, const int m, const vector<pair<int,int>> &passengers, const vector<int> &passengers_order, vector<int> &selected_passengers){
     seg_tree tree(n+1);
     for(int it: passengers_order){
        int left=passengers[it].first, right=passengers[it].second-1,
            degree=tree.range_max(left, right, 0, n);
        if(degree<m){
            selected_passengers.push_back(it+1);
            tree.increment_range(left, right, 0, n);
        }
     }
}

int main(){

    int n, m, k, p;
    read_int(n); read_int(m); read_int(k); read_int(p);

    vector<pair<int,int>> passengers(k);
    vector<int> passengers_order(k), selected_passengers;
    selected_passengers.reserve(k);

    for(int i=0; i<k; ++i){
        passengers_order[i]=i;
        read_int(passengers[i].first);
        read_int(passengers[i].second);
    }

    std::sort(passengers_order.begin(), passengers_order.end(), [&passengers](const int x, const int y){
         return passengers[x].second < passengers[y].second;});

    find_answer_minibus(n, m, passengers, passengers_order, selected_passengers);

    int money_earned=p*selected_passengers.size();
    printf("%d\n", money_earned);
    for(int it: selected_passengers){
        printf("%d ", it);
    }

    return 0;
}
