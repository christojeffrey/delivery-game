#include "getType.h"

char* getType(paket input) {
// mengembalikan tipe item dalam bentuk string dari char
    if (input.item == 'N') {
        return "Normal";
    } else if (input.item == 'H') {
        return "Heavy";
    } else if (input.item == 'P') {
        return "Perishable";
    } else if (input.item == 'V') {
        return "VIP";
    } else {
        return "???";
    }
}