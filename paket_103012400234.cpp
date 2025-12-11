#include "paket.h"
#include <iostream>
using namespace std;

adrChild createElemenChild(infotypeChild x){
    adrChild c = new elmChild;
    c->info = x;
    c->next = nullptr;
    return c;
}

//INSERT FIRST
void insertFirstChild(adrParent &p, adrChild c){
   c->next = p->firstChild;
   p->firstChild = c;
}

//INSERT LAST
void insertLastChild(adrParent &p, adrChild c){
    if (p->firstChild == nullptr){
        p->firstChild = c;
    }else{
        adrChild q = p->firstChild;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = c;
    }
}
void insertAfterChild(adrParent &p, adrChild prec, adrChild c){
    if (prec == nullptr) {
        insertFirstChild(p, c);
    } else {
        c->next = prec->next;
        prec->next = c;
    }
}

//DELETE FIRST
void deleteFirstChild(adrParent &p, adrChild &c){
    if(p->firstChild == nullptr){
        c = nullptr;
    }else{
        c = p->firstChild;
        p->firstChild = c->next;
        c->next = nullptr;

    }

}
void countTotalBeratPaket(ListParent L){
    int totalBerat = 0;
    adrParent p = L.first;
    while (p != NULL) {
        adrChild c = p->firstChild;
        while (c != NULL) {
            totalBerat += c->info.idPaket;  
        }
        p = p->next;
    }
    cout << "Total berat semua paket : " << totalBerat << endl;
}



void rataRataBeratPaket(ListParent L){
    int totalBerat = 0;
    int jumlahPaket = 0;
    float rata = 0; 

    adrParent p = L.first;
    while (p != NULL) {
        adrChild c = p->firstChild;
        while (c != NULL) {
            totalBerat += c->info.idPaket;
            jumlahPaket++;
            c = c->next;
        }
        p = p->next;
    }

    if (jumlahPaket == 0) {
        cout << "Tidak ada paket." << endl;
        return;
    }

    rata = (float) totalBerat / jumlahPaket;   
    cout << "Rata-rata : " << rata << endl;

    
}