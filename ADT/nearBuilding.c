#include "nearBuilding.h"
#include "buildingList.h"
#include "building.h"

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
   //cari building b di buildingList l
   building bding;
   for(int b = 0; b< l.nEff;b++){
      if(l.buffer[b].loc.X == p.X && l.buffer[b].loc.Y == p.Y){
         bding = l.buffer[b];
      }
   }
   int idx = buildingListIndexOf(l, bding);
   for (int i = 0; i < nBSIZE(m); i++){
      if (nBELMT(m , idx, i) == 1) insertLastBuildingList(&legalmove, bLELMT(l, i));
   }
   compactBuildingList(&legalmove);
   return legalmove;
}