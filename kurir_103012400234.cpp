#include "kurir.h"
#include <cstring>
#include <iostream>
using namespace std;

void insertAfterParent(ListParent &L, adrParent prec, adrParent P){
     //I.S: List terdefinisi dan tidak pada First atau Last
    P->next = prec->next;
    P->prev = prec;
    prec->next->prev = P;       
    prec->next = P;
}

void deleteFirstParent(ListParent &L, adrParent &P){
        if (isEmptyParent(L)) {
        cout << "List Kosong";
        P = nullptr;
    } 
    else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}
void deleteLastParent(ListParent &L, adrParent &P){
   if (isEmptyParent(L)) {
        cout << "List Kosong";
        P = nullptr;
    }
    else if (L.first == L.last) { 
        P = L.last;
void insertChild(adrParent P, adrChild C) {
    if (P == nullptr || C == nullptr) return;

    if (P->firstChild == nullptr) {
        P->firstChild = C;
    } else {
        adrChild Q = P->firstChild;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = C;
    }
}


void insertAfterParent(ListParent &L, adrParent prec, adrParent P){
//I.S: List terdefinisi dan tidak pada First atau Last
    if (prec == nullptr) return;

    if (prec == L.last) {
        insertLastParent(L, P);
        return;
    }

    P->next = prec->next;
    P->prev = prec;

    prec->next->prev = P;
    prec->next = P;
}


void deleteFirstParent(ListParent &L, adrParent &P){
    if (isEmptyParent(L)) {
        cout << "List Kosong";
        P = nullptr;
        return;
    }

    P = L.first;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    }
    else {
        L.first = L.first->next;
        L.first->prev = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteLastParent(ListParent &L, adrParent &P) {
    if (isEmptyParent(L)) {
        cout << "List kosong\n";
        P = nullptr;
        return;
    }

    P = L.last;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    }
    else {
       
        P = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;
        P->prev = nullptr;    
    }
}
void deleteAfterParent(ListParent &L, adrParent prec, adrParent &P){
    //I.S: List terdefinisi dan tidak pada First atau Last
    P = prec->next;
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;

}
adrParent findKurirByName(ListParent L, const char nama[]) {
adrParent P = L.first;

    while (P != nullptr) {
        if (strcmp(p->info.namaKurir, nama) == 0) {
            return p;   
        L.last = L.last->prev;
        L.last->next = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}


void deleteAfterParent(ListParent &L, adrParent prec, adrParent &P) {
    if (prec == nullptr || prec->next == nullptr) {
        P = nullptr;
        return;
    }

    P = prec->next;

    if (P == L.last) {
        L.last = prec;
        prec->next = nullptr;
        P->prev = nullptr;
        P->next = nullptr;
        return;
    }

    prec->next = P->next;
    P->next->prev = prec;

    P->next = nullptr;
    P->prev = nullptr;
}

adrParent findKurirByName(ListParent L, const string &nama){
    adrParent P = L.first;

    while (P != nullptr) {
        if (P->info.namaKurir == nama) {
            return P;   // ketemu
        }
        P = P->next;
    }

    return nullptr; // tidak ditemukan
}
