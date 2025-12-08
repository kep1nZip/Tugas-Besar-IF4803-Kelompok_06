#include <iostream>
#include <string>
#include "main.h"

void menuStudiKasus(ListParent &L) {
    int option = -99;

    while (option != 0) {
        cout << "========= Menu Studi Kasus =========\n";
        cout << "1. Studi Kasus 1 (Tampilkan paket pada kurir tertentu)\n";
        cout << "2. Studi Kasus 2 (Rata-rata paket perkurir)\n";
        cout << "3. Studi Kasus 3 (Total Paket)\n";
        cout << "4. Studi Kasus 4 (Rata-rata berat paket)\n";
        cout << "5. Studi Kasus 5 (Total berat paket perkurir)\n";
        cout << "0. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            string nama;
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
        } else if (option == 3) {
            countTotalPaket(L);
        } else if (option == 4){
            rataRataBeratPaket(L);
        } else if (option == 5){
            countTotalBeratPaket(L);
        }
    }
}

void loadDummyDataKurir(ListParent &L) {
    /* ====== DUMMY KURIR ====== */
    infotypeParent k1 = {101, "Budi"};
    infotypeParent k2 = {102, "Andi"};
    infotypeParent k3 = {103, "Siti"};
    infotypeParent k4 = {104, "Rini"};
    infotypeParent k5 = {105, "Dedi"};

    adrParent A = createElemenParent(k1);
    adrParent B = createElemenParent(k2);
    adrParent C = createElemenParent(k3);
    adrParent D = createElemenParent(k4);
    adrParent E = createElemenParent(k5);

    insertLastParent(L, A);
    insertLastParent(L, B);
    insertLastParent(L, C);
    insertLastParent(L, D);
    insertLastParent(L, E);

    /* ====== DUMMY PAKET UNTUK KURIR A ====== */
    insertChild(A, createElemenChild({201, "Asep", "Bandung"}));
    insertChild(A, createElemenChild({202, "Lia", "Jakarta"}));
    insertChild(A, createElemenChild({203, "Romi", "Surabaya"}));

    /* ====== DUMMY PAKET UNTUK KURIR B ====== */
    insertChild(B, createElemenChild({204, "Tono", "Depok"}));
    insertChild(B, createElemenChild({205, "Bunga", "Cimahi"}));
    insertChild(B, createElemenChild({206, "Kevin", "Bekasi"}));

    /* ====== DUMMY PAKET UNTUK KURIR C ====== */
    insertChild(C, createElemenChild({207, "Dika", "Malang"}));
    insertChild(C, createElemenChild({208, "Sari", "Solo"}));

    /* ====== DUMMY PAKET UNTUK KURIR D ====== */
    insertChild(D, createElemenChild({209, "Rina", "Jogja"}));
    insertChild(D, createElemenChild({210, "Putra", "Semarang"}));

    /* ====== DUMMY PAKET UNTUK KURIR E ====== */
    insertChild(E, createElemenChild({211, "Nana", "Bogor"}));
}
