/*複素数ライブラリ*/
#include<stdio.h>
#include<complex.h>

int main(){
    
    double _Complex z1 = 3.0 + 4.0 * _Complex_I;
    double _Complex z2 = 2.0 + 3.0 * _Complex_I;
    double _Complex z3 = z1 + z2;

    printf("%f %f\n", creal(z3), cimag(z3));
    
    return 0;
}
