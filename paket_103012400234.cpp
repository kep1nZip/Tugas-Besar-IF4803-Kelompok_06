#include "paket.h"


adrChild createElemenChild(infotypeChild x){
    adrChild c = new elmChild;
    c->info = x;
    c->next = NULL;
    return c;
}
void insertFirstChild(adrParent &p, adrChild c){
   c->next = p->firstChild;
   p->firstChild = c;


}
void insertLastChild(adrParent &p, adrChild c){
    if (p->firstChild == NULL){
        p->firstChild = c;
        
    }else{
        adrChild q = p->firstChild;
        while(q->next != NULL){
            q = q->next;
        }

        q->next = c;
    }
}
void insertAfterChild(adrParent &p, adrChild prec, adrChild c);

// DELETE
void deleteFirstChild(adrParent &p, adrChild &c){
    if(p->firstChild == NULL){
        c = NULL;
    }else{
        c = p->firstChild;
        p->firstChild = c->next;
        c->next = NULL;

    }

}