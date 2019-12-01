#include <limits.h>
#include "calc.h"

int sum(int a, int b){
    if(a > 0 && b > INT_MAX - a)
        return INT_MAX;
    if(a < 0 && b < INT_MIN - a)
        return INT_MIN;
    
    return a+b;
}