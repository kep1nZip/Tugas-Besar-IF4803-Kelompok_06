#include <iostream>
#include <string>

#include "kurir.h"
#include "paket.h"
#include "main.h"

using namespace std;

// deklarasi menu
void menuAdmin(ListParent &L);
void menuParent(ListParent &L);
void menuChild(ListParent &L);
void menuStudiKasus(ListParent &L);

// deklarasi input
infotypeParent inputDataKurir();
infotypeChild inputDataPaket();

void menuAdmin(ListParent &L) {
    int option = -99;
    while (option != 0) {
        cout << "============ Menu Admin ============ \n";
        cout << "|| 1. Parent (Kurir)              ||\n";
        cout << "|| 2. Child  (Paket)              ||\n";
        cout << "|| 0. Back                        ||\n";
        cout << "====================================\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
            case 1:
                menuParent(L);
                break;
            case 2:
                menuChild(L);
                break;
        }
    }
}



void menuParent(ListParent &L) {
    int option = -99;
    while (option != 0) {
        cout << "=========== Menu Parent ===========\n";
        cout << "1. Insert First Parent\n";
        cout << "2. Insert Last Parent\n";
        cout << "3. Insert Parent by ID (sorted)\n";
        cout << "4. Delete Parent by ID\n";
        cout << "5. View Parents\n";
        cout << "0. Back\n";
        cout << "===================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            infotypeParent x = inputDataKurir();
            adrParent P = createElemenParent(x);
            insertFirstParent(L, P);

        } else if (option == 2) {
            infotypeParent x = inputDataKurir();
            adrParent P = createElemenParent(x);
            insertLastParent(L, P);

        } else if (option == 3) {
            infotypeParent x = inputDataKurir();
            adrParent P = createElemenParent(x);
            insertParentByCondition(L, P);

        } else if (option == 4) {
            int id;
            cout << "Masukkan ID kurir: ";
            cin >> id;
            deleteParentByCondition(L, id);

        } else if (option == 5) {
            adrParent P = L.first;
            cout << "=== DATA KURIR ===\n";
            while (P != nullptr) {
                cout << "ID: " << P->info.idKurir
                     << " | Nama: " << P->info.namaKurir << endl;
                P = P->next;
            }
        }
    }
}

void menuChild(ListParent &L) {
    int option = -99;

    while (option != 0) {
        cout << "=========== Menu Child ===========\n";
        cout << "1. Insert Paket ke Kurir\n";
        cout << "2. Delete Paket dari Kurir\n";
        cout << "3. View Paket Kurir\n";
        cout << "0. Back\n";
        cout << "==================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            char nama[50];
            cout << "Masukkan nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "Kurir tidak ditemukan.\n";
                continue;
            }

            infotypeChild Cinfo = inputDataPaket();
            adrChild C = createElemenChild(Cinfo);
            insertChild(P, C);

        } else if (option == 2) {
            char nama[50];
            int idPaket;
            cout << "Nama kurir: ";
            cin >> nama;
            cout << "ID paket: ";
            cin >> idPaket;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "Kurir tidak ditemukan.\n";
                continue;
            }

            deleteChildByCondition(P, idPaket);

        } else if (option == 3) {
            char nama[50];
            cout << "Nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "Kurir tidak ditemukan.\n";
                continue;
            }

            viewChild(P);
        }
    }
}

infotypeParent inputDataKurir() {
    infotypeParent x;

    cout << "ID Kurir        : ";
    cin >> x.idKurir;
    cout << "Nama Kurir      : ";
    cin >> x.namaKurir;

    return x;
}

infotypeChild inputDataPaket() {
    infotypeChild x;

    cout << "ID Paket        : ";
    cin >> x.idPaket;

    cout << "Nama Penerima   : ";
    cin >> x.namaPenerima;

    cout << "Alamat          : ";
    cin >> x.alamat;

    return x;
}

