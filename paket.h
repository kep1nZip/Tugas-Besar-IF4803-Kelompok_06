#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
#include <iostream>
using namespace std;

/* =======================
     ADT PARENT : KURIR
   ======================= */
typedef struct elmChild *adrChild;

struct infotypeChild{
  int idpaket;
  char namaPenerima[50];
  char alamt[100];

};

struct elmChild{
    infotypeChild info;
    adrChild next;
};

adrChild allocateChild(infotypeChild data);



#endif /* PAKET_H_INCLUDED */
