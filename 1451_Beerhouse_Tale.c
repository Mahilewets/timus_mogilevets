#include <stdio.h>
#include <math.h>
typedef long double ld;
const ld INF=1e4;
const int steps=1100;
const ld eps=1e-7;
ld  x_0, x_1,x_2,x_3,y_0,y_1,y_2,y_3;
ld dist_y(ld dx1,ld dx2,ld dx3){
    ld up=INF;
    ld low=-INF;  
    ld delta,n1,n2,dy1, dy2, dy3,s1,s2;
    int j;  
    for (j=0; j<steps; ++j){
         delta=(up-low)/3;
         n1=low+delta;
         n2=up-delta;
         dy1=(n1-y_1);
         dy1=dy1*dy1;
         dy2=(n1-y_2);
         dy2=dy2*dy2;
         dy3=(n1-y_3);
         dy3=dy3*dy3;
         s1=sqrt(dx1+dy1)+sqrt(dx2+dy2)+sqrt(dx3+dy3); 
         dy1=(n2-y_1);
         dy1=dy1*dy1;
         dy2=(n2-y_2);
         dy2=dy2*dy2;
         dy3=(n2-y_3);
         dy3=dy3*dy3;
         s2=sqrt(dx1+dy1)+sqrt(dx2+dy2)+sqrt(dx3+dy3); 
         if (s1<s2)
             up=n2;
         else
             low=n1;
     }
     y_0=(up+low)/2;
     return s1;
}
int main(){  
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&x_1,&y_1,&x_2,&y_2,&x_3,&y_3);
    ld min_s=1e100;
    ld left_x=-INF;
    ld right_x=INF;
    ld up_y=INF;
    ld low_y=-INF;
    int i;
    for (i=0; i<steps; ++i){
        ld delta_x=(right_x-left_x)/3;
        ld m1=left_x+delta_x;
        ld m2=right_x-delta_x;
        ld dx1=m1-x_1;
        dx1=dx1*dx1;
        ld dx2=m1-x_2;
        dx2=dx2*dx2;
        ld dx3=m1-x_3;
        dx3=dx3*dx3;
        ld s1=dist_y(dx1,dx2,dx3);
        dx1=m2-x_1;
        dx1=dx1*dx1;
        dx2=m2-x_2;
        dx2=dx2*dx2;
        dx3=m2-x_3;
        dx3=dx3*dx3;
        ld s2=dist_y(dx1,dx2,dx3);
        if (s1<s2)
            right_x=m2;
        else
            left_x=m1; 
        x_0=(left_x+right_x)/2;
   
    }
    printf("%.10Lf %.10Lf",x_0,y_0);
    return 0;
}
