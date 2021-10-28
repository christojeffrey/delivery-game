
#ifndef NODE_PAKET_H
#define NODE_PAKET_H

#include "paket.h"
#include <stdlib.h>

typedef struct NodePaket* Address;
typedef struct NodePaket {
    paket info;
    Address next;
} nodePaket;


Address newNodePaket(paket val);

#endif