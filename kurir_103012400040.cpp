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
adrParent createElemenParent(infotypeParent data) {
    adrParent P = new elmParent;
    P->info = data;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstChild = nullptr;
    return P;
}

/* INSERT FIRST PARENT */
void insertFirstParent(ListParent &L, adrParent P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        P->prev = nullptr;
        L.first = P;
    }
}


/* INSERT LAST PARENT */
void insertLastParent(ListParent &L, adrParent P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        P->next = nullptr;
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
        temp->next = nullptr;
    }
    P->firstChild = nullptr;

    if (P == L.first && P == L.last) {
        L.first = nullptr;
        L.last  = nullptr;
    }
    else if (P == L.first) {
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
    else if (P == L.last) {
        L.last = P->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
    else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = nullptr;
        P->prev = nullptr;
    }

    cout << "Kurir dengan ID " << idKurir << " berhasil dihapus dari list.\n";
}


/* ======================================================
   DELETE CHILD BERDASARKAN KONDISI (ID PAKET)
   ======================================================*/
void deleteChildByCondition(adrParent P, int idPaket) {
    if (P == nullptr) return;

    adrChild C = P->firstChild;

    if (C == nullptr) {
        cout << "Tidak ada paket pada kurir ini.\n";
        return;
    }

    /*pertama*/
    if (C->info.idPaket == idPaket) {
        P->firstChild = C->next;
        C->next = nullptr;
        cout << "Paket " << idPaket << " berhasil dihapus.\n";
        return;
    }

    adrChild prev = C;
    C = C->next;

    /*selanjut2nya*/
    while (C != nullptr && C->info.idPaket != idPaket) {
        prev = C;
        C = C->next;
    }

    if (C == nullptr) {
        cout << "Paket dengan ID " << idPaket << " tidak ditemukan.\n";
        return;
    }

    prev->next = C->next;
    C->next = nullptr;

    cout << "Paket " << idPaket << " berhasil dihapus.\n";
}


/* ======================================================
   TOTAL PAKET (SEMUA KURIR)
   ======================================================*/
int countTotalPaket(ListParent L) {
    int total = 0;

    adrParent P = L.first;
    while (P != nullptr) {
        adrChild C = P->firstChild;

        while (C != nullptr) {
            total++;
            C = C->next;
        }

        P = P->next;
    }

    cout << "Total Paket: " << total << endl;
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

/* ======================================================
   LIHAT KURIR DENGAN PAKET TERBANYAK
   ======================================================*/

void viewKurirWithMostPaket(ListParent L) {
    if (isEmptyParent(L)) {
        cout << "List kurir kosong.\n";
        return;
    }

    adrParent P = L.first;
    adrParent maxKurir = nullptr;
    int maxPaket = 0;

    while (P != nullptr) {
        int count = 0;
        adrChild C = P->firstChild;

        while (C != nullptr) {
            count++;
            C = C->next;
        }

        if (count > maxPaket) {
            maxPaket = count;
            maxKurir = P;
        }

        P = P->next;
    }

    cout << "\n=== KURIR DENGAN PAKET TERBANYAK ===\n";
    if (maxKurir != nullptr) {
        cout << "Nama: " << maxKurir->info.namaKurir << endl;
        cout << "ID   : " << maxKurir->info.idKurir << endl;
        cout << "Total Paket: " << maxPaket << endl;
    }
    cout << "====================================\n";
}
