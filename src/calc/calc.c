#include <limits.h>
#include "calc.h"

int sum(int a, int b){
    return a+b;
}

int prod(int a, int b){
    if(b>0) return a+prod(a,b-1);
    if(b == 0) return 0;
    return a*b;
}