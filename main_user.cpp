#include <iostream>
#include <string>
#include "main.h"

void menuStudiKasus(ListParent &L) {
    int option = -99;

    while (option != 0) {
        cout << "========= Menu Studi Kasus =========\n";
        cout << "1. Studi Kasus 1 (Tampilkan paket pada bulan tertentu)\n";
        cout << "2. Studi Kasus 2 (Sales dengan paket terbanyak)\n";
        cout << "0. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            char nama[50];
            cout << "Nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "Kurir tidak ditemukan.\n";
                continue;
            }

            viewChild(P);

        } else if (option == 2) {
            rataRataPaketPerKurir(L);
        }
    }
}