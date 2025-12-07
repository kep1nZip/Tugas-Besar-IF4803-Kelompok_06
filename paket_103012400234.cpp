#include "paket.h"
#include <iostream>
using namespace std;

#include <iostream>

using namespace std;


adrChild createElemenChild(infotypeChild x){
    adrChild c = new elmChild;
    c->info = x;
    c->next = nullptr;
    return c;
}

/*INSERT FIRST*/
void insertFirstChild(adrParent &p, adrChild c){
   c->next = p->firstChild;
   p->firstChild = c;
}

/*INSERT LAST*/
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
        c->next = p->firstChild;
        p->firstChild = c;
    } else {
        c->next = prec->next;
        prec->next = c;
    }
}
// DELETE
void deleteFirstChild(adrParent &p, adrChild &c){
    if (p->firstChild == nullptr){
        c = nullptr;
    }
    else if (p->firstChild->next == nullptr){
        c = p->firstChild;
        p->firstChild = nullptr;
    }else{
        c = p->firstChild;
        p->firstChild = c->next;
        c->next = nullptr;
    }
}
    
