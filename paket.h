#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
#include <iostream>
using namespace std;
#include "kurir.h"

//create Child
adrChild createElemenChild(infotypeChild x);

// INSERT
void insertFirstChild(adrParent &p, adrChild c);
void insertLastChild(adrParent &p, adrChild c);
void insertAfterChild(adrParent &p, adrChild prec, adrChild c);

// DELETE
void deleteFirstChild(adrParent &p, adrChild &c);
void deleteLastChild(adrParent &p, adrChild &c);
void deleteAfterChild(adrParent &p, adrChild prec, adrChild &c);

// SEARCH
adrChild findElemenChild(adrParent p, int idPaket);

// VIEW
void viewChild(adrParent p);




#endif /* PAKET_H_INCLUDED */
