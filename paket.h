#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
#include <iostream>
using namespace std;

/* =======================
     ADT PARENT : KURIR
   ======================= */

#define NIL NULL

typedef struct elmChild *adrChild;
typedef struct elmParent *adrParent;

struct infotypeParent {
    int idKurir;
    char namaKurir[50];
    int kapasitasMax;
};

struct elmParent {
    infotypeParent info;
    adrParent next;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
};

void createListParent(ListParent &L);
adrParent alokasiParent(infotypeParent x);
void dealokasiParent(adrParent P);
void insertParent(ListParent &L, adrParent P);
void deleteParent(ListParent &L, int idKurir);
adrParent findParent(ListParent L, int idKurir);
void printParent(ListParent L);

#endif /* PAKET_H_INCLUDED */
