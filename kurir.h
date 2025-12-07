#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

/* ADT CHILD : PAKET (ONE TO MANY)*/

typedef struct elmChild *adrChild;

struct infotypeChild {
    int idPaket;
    string namaPenerima;
    string alamat;
};

struct elmChild {
    infotypeChild info;
    adrChild next;
};


/*ADT PARENT (KURIR)*/

typedef struct elmParent *adrParent;

struct infotypeParent {
    int idKurir;
    string namaKurir;
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

/* BASIC FUNCTION */
bool isEmptyParent(ListParent L);
void createListParent(ListParent &L);
adrParent createElemenParent(infotypeParent data);
adrChild createElemenChild(infotypeChild data);
void insertFirstParent(ListParent &L, adrParent P);
void insertLastParent(ListParent &L, adrParent P);
void insertAfterParent(ListParent &L, adrParent prec, adrParent P);
void insertChild(adrParent P, adrChild C);
void deleteFirstParent(ListParent &L, adrParent &P);
void deleteLastParent(ListParent &L, adrParent &P);
void deleteAfterParent(ListParent &L, adrParent prec, adrParent &P);

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
adrParent findKurirByName(ListParent L, const string &nama);

/* LIHAT/VIEW KURIR BESERTA DETAIL */
void viewAllKurir(ListParent L);
void viewKurirDetail(ListParent L);

/* LIHAT/VIEW KURIR DENGAN PAKET TERBANYAK */
void viewKurirWithMostPaket(ListParent L);

#endif /* KURIR_H_INCLUDED */
