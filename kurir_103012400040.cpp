#include "kurir.h"
#include <cstring>
#include <iostream>
using namespace std;

bool isEmptyParent(ListParent L) {
    return (L.first == nullptr);
}

/* CREATE LIST PARENT*/
void createListParent(ListParent &L) {
    L.first = nullptr;
    L.last = nullptr;
}

/* ALOKASI PARENT*/
adrParent allocateParent(infotypeParent data) {
    adrParent P = new elmParent;
    P->info = data;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstChild = nullptr;
    return P;
}

/* INSERT LAST PARENT */
void insertLastParent(ListParent &L, adrParent P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ======================================================
   INSERT PARENT BERDASARKAN KONDISI (URUT ID KURIR)
   ======================================================*/
void insertParentByCondition(ListParent &L, adrParent P) {
    if (isEmptyParent(L)) {
        insertLastParent(L, P);
        return;
    }

    adrParent Q = L.first;

    if (P->info.idKurir < Q->info.idKurir) {
        P->next = Q;
        Q->prev = P;
        L.first = P;
        return;
    }

    while (Q != nullptr && Q->info.idKurir < P->info.idKurir) {
        Q = Q->next;
    }

    if (Q == nullptr) {
        insertLastParent(L, P);
    } else {
        adrParent prevNode = Q->prev;
        prevNode->next = P;
        P->prev = prevNode;
        P->next = Q;
        Q->prev = P;
    }
}

/* ======================================================
   DELETE PARENT BERDASARKAN KONDISI (ID KURIR)
   ======================================================*/
void deleteParentByCondition(ListParent &L, int idKurir) {
    adrParent P = L.first;

    while (P != nullptr && P->info.idKurir != idKurir) {
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Kurir dengan ID " << idKurir << " tidak ditemukan.\n";
        return;
    }

    adrChild C = P->firstChild;
    while (C != nullptr) {
        adrChild temp = C;
        C = C->next;
        delete temp;
    }

    if (P == L.first && P == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    }
    else if (P == L.first) {
        L.first = P->next;
        L.first->prev = nullptr;
    }
    else if (P == L.last) {
        L.last = P->prev;
        L.last->next = nullptr;
    }
    else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
}

/* ======================================================
   RATA-RATA JUMLAH PAKET PER KURIR
   ======================================================*/
void rataRataPaketPerKurir(ListParent L) {
    if (isEmptyParent(L)) {
        cout << "List kurir kosong.\n";
        return;
    }

    int totalKurir = 0;
    int totalPaket = 0;

    adrParent P = L.first;
    while (P != nullptr) {
        totalKurir++;

        adrChild C = P->firstChild;
        while (C != nullptr) {
            totalPaket++;
            C = C->next;
        }

        P = P->next;
    }

    float rata = 0;
    if (totalKurir > 0) {
        rata = (float) totalPaket / totalKurir;
    }

    cout << "Rata-rata paket per kurir: " << rata << endl;
}
