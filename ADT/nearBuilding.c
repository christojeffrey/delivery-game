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

buildingList getMove(nearBuilding m, buildingList l, location p, location hq)
/* mencari move legal dari suatu posisi */
{
   buildingList legalmove;
   createBuildingList(&legalmove, 27);
   //cari building b di buildingList l

   int idx;
   if(p.X == hq.X && p.Y == hq.Y){
      idx = 0;
   }
   else{
      building bding;
      for(int b = 0; b< l.nEff;b++){
         if(l.buffer[b].loc.X == p.X && l.buffer[b].loc.Y == p.Y){
            bding = l.buffer[b];
         }
      }  
      idx = buildingListIndexOf(l, bding) + 1;
   }
   

   for (int i = 0; i < nBSIZE(m); i++){
      if (nBELMT(m , idx, i) == 1){
         if(i == 0){
            building temp;
            temp.name = '!';
            temp.loc.X = hq.X;
            temp.loc.Y = hq.Y;
            insertLastBuildingList(&legalmove,temp);
         }
         else{
            insertLastBuildingList(&legalmove, bLELMT(l, i-1));
         }
      }
   }
   compactBuildingList(&legalmove);
   return legalmove;
}