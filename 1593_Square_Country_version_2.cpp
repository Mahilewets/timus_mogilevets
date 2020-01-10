#include <cstdio>
#include <cmath>
typedef long long ll;
typedef long double ld;
int main()
{
    ll n;
    scanf("%lld", &n);
    ll sqrt_of_n=sqrt((ld)n);
    if(sqrt_of_n*sqrt_of_n==n){
        printf("1");
        return 0;
    }

    ll a=1, squared_a=1;

    while((squared_a<<1) <= n){
        ll squared_b=n-squared_a, b=sqrt((ld) squared_b);
        if(b*b==squared_b){
            printf("2");
            return 0;
        }
        squared_a+=(a<<1)+1;
        ++a;
    }

    ll x=n, y=x>>2;
    while(x==y<<2){
        x=y;
        y=x>>2;
    }
    x-=7;
    if(x>=0){
        ll b=x/8;
        if (x==8*b){
            printf("4");
            return 0;
        }
    }

    printf("3");

    return 0;
}
