#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED
#include <iostream>
using namespace std;

/*  =======================
    ADT CHILD : PAKET
    ======================= */

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

adrChild alokasiChild(infotypeChild x);
void dealokasiChild(adrChild C);

void insertChild(adrChild &firstChild, adrChild C);
void deleteChild(adrChild &firstChild, int idPaket);

adrChild findChild(adrChild firstChild, int idPaket);

void printChildList(adrChild firstChild);

#endif /* KURIR_H_INCLUDED */
