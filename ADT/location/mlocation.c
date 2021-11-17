#include "location.h"
#include <stdio.h>
int main(){
    location l = makeLocation(1,2);
    printf("%d,%d", l.X, l.Y);
}