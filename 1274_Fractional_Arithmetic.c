#include <stdio.h>
typedef long long int ll;
ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);  
}
int main(){
    int sign1=1, sign2=1;
    ll whole1=0, whole2=0, num1=0, num2=0, den1=1, den2=1;
    char str[100], op[2];
    gets(str);
    if(str[0]=='-')
        sign1=-1;
    int space_cnt=0, slash_cnt=0;
    for(int i=0; str[i]!='\0'; ++i){
        if(str[i]==' ')
            ++space_cnt; 
        if(str[i]=='/')
            ++slash_cnt; 
    }
    if (space_cnt==0)
        if(slash_cnt==0)
           sscanf(str,"%lld",&whole1);
        else
           sscanf(str,"%lld/%lld",&num1,&den1);
    else
        sscanf(str,"%lld %lld/%lld",&whole1, &num1, &den1);
    gets(op);
    gets(str);
    if(str[0]=='-')
        sign2=-1;
    space_cnt=0, slash_cnt=0;
    for(int i=0; str[i]!='\0'; ++i){
        if(str[i]==' ')
            ++space_cnt; 
        if(str[i]=='/')
            ++slash_cnt; 
    }
    if (space_cnt==0)
        if(slash_cnt==0)
           sscanf(str,"%lld",&whole2);
        else
           sscanf(str,"%lld/%lld",&num2,&den2);
    else
        sscanf(str,"%lld %lld/%lld",&whole2, &num2, &den2);
    
    
    if(whole1!=0)
        num1=num1*sign1+whole1*den1;
    if(whole2!=0)
        num2=num2*sign2+whole2*den2;
    
    
    ll GCD=gcd(sign1*num1,den1);
    num1/=GCD, den1/=GCD;
    GCD=gcd(sign2*num2,den2);
    num2/=GCD, den2/=GCD;
    
    if(op[0]=='*'){
        GCD=gcd(num1*sign1, den2);
        num1/=GCD,den2/=GCD;
        GCD=gcd(num2*sign2, den1);
        num2/=GCD,den1/=GCD;
        num1*=num2, den1*=den2;
        sign1*=sign2;
    }
    else if(op[0]=='/'){
        GCD=gcd(num1*sign1, num2*sign2);
        num1/=GCD,num2/=GCD;
        GCD=gcd(den1, den2);
        den1/=GCD,den2/=GCD;
        num1*=den2, den1*=num2;
        sign1*=sign2;
    }
    else if(op[0]=='+'){
        GCD=gcd(den1, den2);
        ll mul1=den2/GCD,mul2=den1/GCD;
        num1*=mul1,den1*=mul1;
        num2*=mul2,den2*=mul2;
        num1+=num2;
        if(num1<0)
            sign1=-1;
        else
           sign1=1;
    }
    else if(op[0]=='-'){
           GCD=gcd(den1, den2);
        ll mul1=den2/GCD,mul2=den1/GCD;
        num1*=mul1,den1*=mul1;
        num2*=mul2,den2*=mul2;
        num1-=num2;
        if(num1<0)
           sign1=-1;
        else
           sign1=1;
    }
    whole1=num1/den1;
    num1-=whole1*den1;    
    
    
    GCD=gcd(sign1*num1,den1);
    num1/=GCD, den1/=GCD;
    if (whole1!=0){
        printf("%lld",whole1);
        if(num1!=0)
           printf(" %lld/%lld",sign1*num1,den1);
    }
    else
        if(num1!=0)
           printf("%lld/%lld",num1,den1);
        else
           printf("0");
    return 0;
}
