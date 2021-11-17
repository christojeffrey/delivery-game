#include "nearBuilding.h"
#include "../buildingList/buildingList.h"
#include "../building/building.h"
#include "../location/location.h"
#include <stdio.h>
int main(){
    nearBuilding nB;
    CreatenearBuilding(5, &nB);
    printf("%d",nBSIZE(nB));
    //getMove hanya berguna pada game, bukan pada ADT jadi tidak di buat drivernya disini
}