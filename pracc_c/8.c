/*±の表示(極座標変換)*/
#include<stdio.h>
#include<math.h>

int main(){

    double r,deg;
    double a = 0.0, b = 0.0;

    printf("r:"); scanf("%lf",&r);
    printf("deg:"); scanf("%lf",&deg);

    a = r * cos(deg * M_PI / 180.0);
    b = r * sin(deg * M_PI / 180.0);

    printf("%lf%+lf\n",a,b);

    return 0;
}
