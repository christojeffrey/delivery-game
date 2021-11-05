#include "nodePaket.h"
#include <stdlib.h>

Address newNodePaket(paket val) {
    Address ipl = (Address) malloc(sizeof(nodePaket));
    if (ipl != NULL) {
        (ipl)->info = val;
        (ipl)->next = NULL;
    }
    return ipl;
}