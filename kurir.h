#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED
#include <iostream>
using namespace std;

/* ADT CHILD : PAKET (ONE TO MANY)*/

typedef struct elmChild *adrChild;

struct infotypeChild {
    int idPaket;
    char namaPenerima[50];
    char alamat[100];
};

struct elmChild {
    infotypeChild info;
    adrChild next;
};


/*ADT PARENT (KURIR)*/

typedef struct elmParent *adrParent;

struct infotypeParent {
    int idKurir;
    char namaKurir[50];
};

struct elmParent {
    infotypeParent info;
    adrParent next;
    adrParent prev;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
    adrParent last;
};


/* Parent (Kurir) */
void createListParent(ListParent &L);
adrParent allocateParent(infotypeParent data);
void insertLastParent(ListParent &L, adrParent P);
adrParent findParent(ListParent L, int idKurir);
void deleteParent(ListParent &L, adrParent &P);

/* Child (Paket) */
adrChild allocateChild(infotypeChild data);
void insertChild(adrParent P, adrChild C);
adrChild findChild(adrParent P, int idPaket);
void deleteChild(adrParent P, adrChild &C);

void printAll(ListParent L);
#endif /* KURIR_H_INCLUDED */
