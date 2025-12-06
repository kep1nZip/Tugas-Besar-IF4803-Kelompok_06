#include "paket.h"
#include <iostream>

using namespace std;

/* ======================================================
   DELETE LAST CHILD
   ======================================================*/

void deleteLastChild(adrParent &p, adrChild &c) {
    c = nullptr;

    if (p == nullptr || p->firstChild == nullptr) {
        cout << "List child kosong.\n";
        return;
    }

    adrChild q = p->firstChild;

    if (q->next == nullptr) {
        c = q;
        p->firstChild = nullptr;
        return;
    }

    adrChild prev = nullptr;
    while (q->next != nullptr) {
        prev = q;
        q = q->next;
    }

    prev->next = nullptr;
    c = q;
}

/* ======================================================
   DELETE AFTER CHILD
   ======================================================*/

void deleteAfterChild(adrParent &p, adrChild prec, adrChild &c) {
    c = nullptr;

    if (p == nullptr || prec == nullptr || prec->next == nullptr) {
        cout << "Tidak bisa menghapus. Elemen setelah prec tidak ada.\n";
        return;
    }

    c = prec->next;
    prec->next = c->next;
}

/* ======================================================
   FIND ELEMENT CHILD
   ======================================================*/

adrChild findElemenChild(adrParent p, string idpaket) {
    if (p == nullptr) return nullptr;

    adrChild q = p->firstChild;

    while (q != nullptr) {
        if (q->info.idpaket == idpaket) {
            return q;
        }
        q = q->next;
    }

    return nullptr;
}

/* ======================================================
   VIEW CHILD
   ======================================================*/

void viewChild(adrParent p) {
    if (p == nullptr) {
        cout << "Parent tidak valid.\n";
        return;
    }

    adrChild c = p->firstChild;

    if (c == nullptr) {
        cout << "Tidak ada paket untuk kurir ini.\n";
        return;
    }

    cout << "Daftar Paket:\n";
    while (c != nullptr) {
        cout << "- ID Paket   : " << c->info.idpaket << endl;
        cout << "  Penerima   : " << c->info.namaPenerima << endl;
        cout << "  Alamat     : " << c->info.alamat << endl;
        cout << "-------------------------------------\n";
        c = c->next;
    }
}
