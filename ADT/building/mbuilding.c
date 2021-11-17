#include "../boolean.h"
#include "../location/location.h"
#include "building.h"
#include <stdio.h>
int main(){
    building B = makeBuilding('B', makeLocation(1,2));
    building C = makeBuilding('C', makeLocation(1,2));
    printf("%d", inTheSameTiles(B,C)); // 1 (true)
    printf("%d", booleanIsIn(B,makeLocation(3,2))); //0 (false)
    printf("%d", booleanIsIn(B,makeLocation(1,2))); //1 (true)
}