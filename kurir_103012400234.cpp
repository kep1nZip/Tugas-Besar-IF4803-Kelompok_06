#include "kurir.h"
#include "kurir.h"
#include <cstring>
#include <iostream>
using namespace std;

void insertAfterParent(ListParent &L, adrParent prec, adrParent P){
//I.S: List terdefinisi dan tidak pada First atau Last
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;       
    Prec->next = P;
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
    } 
    else {
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
    P = Prec->next;
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = NULL;
    P->prev = NULL;



}
adrParent findKurirByName(ListParent L, const char nama[]){

    adrParent P = L.first;

    while (P != nullptr) {
        if (strcmp(P->info.namaKurir, nama) == 0) {
            return P;   // ketemu
        }
        P = P->next;
    }

    return nullptr; // tidak ditemukan
}