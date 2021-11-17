#include <stdio.h>
#include "../buildingList/buildingList.h"
#include "../building/building.h"
#include "../location/location.h"
#include<stdlib.h>

int main(){
    buildingList bL;
    createBuildingList(&bL, 5);
    printf("%d,%d\n", bLNEFF(bL), bLCAPACITY(bL)); //0, 5
    insertLastBuildingList(&bL, makeBuilding('C',makeLocation(1,2)));
    printf("%d,%d\n", bLNEFF(bL), bLCAPACITY(bL)); //1, 5
    building D = makeBuilding('D',makeLocation(3,4));
    insertLastBuildingList(&bL, D);
    printf("%d,%d\n", bLNEFF(bL), bLCAPACITY(bL)); //2, 5
    printf("bangunan bernama C berada di index ke = %d\n", buildingListIndexOfName(bL, 'C'));
    printf("D berada di index ke = %d\n", buildingListIndexOf(bL, D));
    buildingList copyOfbL;
    copyBuildingList(bL, &copyOfbL);
    printf("Semua yang ada di building list bL akan di copy ke building list copyOfbL\n");
    printf("%d,%d\n", bLNEFF(copyOfbL), bLCAPACITY(copyOfbL)); //2, 5
    printf("bangunan bernama C berada di index ke = %d, di building list copyOfbL\n", buildingListIndexOfName(copyOfbL, 'C'));
    printf("D berada di index ke = %d, di building list copyOfbL\n", buildingListIndexOf(copyOfbL, D));
    
    building temp;
    deleteLastBuildingList(&bL, &temp);
    printf("%c dibuang dengan absis dan ordinat berturut-turut : %d, %d\n", Nama(temp), Absis(temp), Ordinat(temp));
    printf("%d,%d\n", bLNEFF(bL), bLCAPACITY(bL)); //2, 5
    compactBuildingList(&bL);
    printf("bL di compact sehingga : %d,%d\n", bLNEFF(bL), bLCAPACITY(bL)); //2, 5
    dealocateBuildingList(&copyOfbL);
    printf("copyOfbL di dealocate sehingga : %d,%d\n", bLNEFF(copyOfbL), bLCAPACITY(copyOfbL));
}