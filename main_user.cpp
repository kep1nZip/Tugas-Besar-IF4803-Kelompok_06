#include <iostream>
#include <string>
#include "main.h"

void menuStudiKasus(ListParent &L) {
    int option = -99;

    while (option != 0) {
        cout << "====================== Menu Studi Kasus ======================\n";
        cout << "|| 1. Studi Kasus 1 (Menyisipkan paket)                     ||\n";
        cout << "|| 2. Studi Kasus 2 (Menghapus paket)                       ||\n";
        cout << "|| 3. Studi Kasus 3 (Tampilkan paket pada kurir tertentu)   ||\n";
        cout << "|| 4. Studi Kasus 4 (Rata-rata paket perkurir)              ||\n";
        cout << "|| 5. Studi Kasus 5 (Total Paket)                           ||\n";
        cout << "|| 6. Studi Kasus 6 (Rata-rata berat paket)                 ||\n";
        cout << "|| 7. Studi Kasus 7 (Total berat paket perkurir)            ||\n";
        cout << "|| 8. Studi Kasus 8 (View kurir + paket)                    ||\n";
        cout << "|| 0. Back                                                  ||\n";
        cout << "==============================================================\n";
        cout << "Choose option: ";
        cin >> option;

        if  (option == 1) {
            string nama;
            cout << "\nMasukkan nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "[!] Kurir tidak ditemukan.\n";
                continue;
            }

            infotypeChild X;
            cout << "ID Paket       : ";
            cin >> X.idPaket;
            cout << "Nama Penerima  : ";
            cin >> X.namaPenerima;
            cout << "Alamat         : ";
            cin >> X.alamat;
            cout << "Berat(kg)      : ";
            cin >> X.berat;

            adrChild C = createElemenChild(X);
            insertChild(P, C);

            cout << "[+] Paket berhasil disisipkan!\n";
        } else if (option == 2) {
            string nama;
            cout << "\nMasukkan nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "[!] Kurir tidak ditemukan.\n";
                continue;
            }

            int idPaket;
            cout << "ID paket yang ingin dihapus: ";
            cin >> idPaket;

            deleteChildByCondition(P, idPaket);
        } else if (option == 3) {
            string nama;
            cout << "Nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "[!] Kurir tidak ditemukan.\n";
                continue;
            }

            viewChild(P);

        } else if (option == 4) {
            rataRataPaketPerKurir(L);
        } else if (option == 5) {
            countTotalPaket(L);
        } else if (option == 6){
            rataRataBeratPaket(L);
        } else if (option == 7){
            countTotalBeratPaket(L);
        } else if (option == 8){
            viewKurirDetail(L);
        }else if (option == 0){
            system("cls");
        } else {
            system("cls");
            cout << "Opsi invalid euy~ \n";
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
    insertChild(A, createElemenChild({201, "Asep", "Bandung", 2.5}));
    insertChild(A, createElemenChild({202, "Lia", "Jakarta", 1.2}));
    insertChild(A, createElemenChild({203, "Romi", "Surabaya", 3.0}));

    /* ====== DUMMY PAKET UNTUK KURIR B ====== */
    insertChild(B, createElemenChild({204, "Tono", "Depok", 1.8}));
    insertChild(B, createElemenChild({205, "Bunga", "Cimahi", 2.0}));
    insertChild(B, createElemenChild({206, "Kevin", "Bekasi", 4.1}));

    /* ====== DUMMY PAKET UNTUK KURIR C ====== */
    insertChild(C, createElemenChild({207, "Dika", "Malang", 0.9}));
    insertChild(C, createElemenChild({208, "Sari", "Solo", 1.7}));

    /* ====== DUMMY PAKET UNTUK KURIR D ====== */
    insertChild(D, createElemenChild({209, "Rina", "Jogja", 3.4}));
    insertChild(D, createElemenChild({210, "Putra", "Semarang", 2.2}));

    /* ====== DUMMY PAKET UNTUK KURIR E ====== */
    insertChild(E, createElemenChild({211, "Nana", "Bogor", 1.1}));
}
