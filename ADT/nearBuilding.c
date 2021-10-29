#include "nearBuilding.h"
#include "buildingList.h"
void CreatenearBuilding(int rowcol, nearBuilding *nb)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
   nBSIZE(*nb) = rowcol;
}

buildingList getMove(nearBuilding m, buildingList l, location p)
/* mencari move legal dari suatu posisi */
{
   buildingList legalmove;
   createBuildingList(&legalmove, 27);
   int idx = buildingListIndexOf(l, p);
   for (int i = 0; i < nBSIZE(m); i++){
      if (nBELMT(m , idx, i) == 1) insertLastBuildingList(&legalmove, bLELMT(l, i));
   }
   compactBuildingList(&legalmove);
   return legalmove;
}