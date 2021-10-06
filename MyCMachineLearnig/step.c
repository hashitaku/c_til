#include"./step.h"

int step(double a, double b, double c, double x, double y){
    if(a * x + b * y + c > 0){
        return 1;
    }else{
        return -1;
    }
}
