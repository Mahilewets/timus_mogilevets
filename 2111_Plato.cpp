#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d;
int res;
int n;
unsigned long long w;

int main()
{
    cin>>n;
    d.resize(n);
    for(auto &x:d)
    {
        cin>>x;
        w += x;
    }
    //w = accumulate(d.begin(),d.end(),0);
    sort(d.begin(),d.end());
    for(auto x: d)
    {
        res += w * x;
        w -=x;
        res += w * x;
    }

    cout << res << endl;

    return 0;
}

