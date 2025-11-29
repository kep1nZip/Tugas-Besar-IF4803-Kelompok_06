#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include "kurir.h"
#include "paket.h"
using namespace std;

/* MENU ADMIN */
void menuAdmin(ListParent &L);

/* MENU USER/STUDI KASUS */
void menuStudiKasus(ListParent &L);

/* INPUT */
infotypeParent inputDataKurir();
infotypeChild inputDataPaket();

#endif // MAIN_H_INCLUDED
