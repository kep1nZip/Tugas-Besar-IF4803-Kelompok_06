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

/* BASIC FUNCTION */.
void createListParent(ListParent &L);
adrParent allocateParent(infotypeParent data);
adrChild allocateChild(infotypeChild data);
void insertLastParent(ListParent &L, adrParent P);
void insertChild(adrParent P, adrChild C);

/* MENYISIPKAN DATA PARENT BERDASARKAN SUATU KONDISI */
void insertParentByCondition(ListParent &L, adrParent P);

/* MENGHAPUS DATA PARENT BERDASARKAN SUATU KONDISI */
void deleteParentByCondition(ListParent &L, int idKurir);

/* MENYISIPKAN CHILD BERDASARKAN SUATU KONDISI */
void insertChildByCondition(adrParent P, adrChild C);

/* MENGHAPUS CHILD BERDASARKAN SUATU KONDISI */
void deleteChildByCondition(adrParent P, int idPaket);

/* KOMPUTASI */
int countTotalPaket(ListParent L); /* TOTAL PAKET */
void rataRataPaketPerKurir(ListParent L); /* RATA-RATA PAKET PERKURIR */

/* PROSES PENCARIAN BERDASARKAN SUATU KONDISI (KONDISI = NAMA KURIR) */
adrParent findKurirByName(ListParent L, const char nama[]);

#endif /* KURIR_H_INCLUDED */
