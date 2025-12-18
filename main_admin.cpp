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

        if (option == 1){
            menuParent(L);
        } else if (option == 2){
            menuChild(L);
        } else if (option == 0){
            system("cls");
        } else {
            system("cls");
            cout << "Opsi invalid euy~ \n";
        }
    }
}


void menuParent(ListParent &L) {
    int option = -99;
    while (option != 0) {
        cout << "============ Menu Parent =============\n";
        cout << "|| 1. Insert First Parent           ||\n";
        cout << "|| 2. Insert Last Parent            ||\n";
        cout << "|| 3. Insert Parent by ID (sorted)  ||\n";
        cout << "|| 4. Delete Parent by ID           ||\n";
        cout << "|| 5. View Parents                  ||\n";
        cout << "|| 6. View Parents + Child          ||\n";
        cout << "|| 7. Kurir dengan Paket Terbanyak  ||\n";
        cout << "|| 0. Back                          ||\n";
        cout << "======================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            infotypeParent x = inputDataKurir();

            adrParent Q = L.first;
            bool duplikat = false;

            while (Q != nullptr) {
                if (Q->info.idKurir == x.idKurir) {
                    duplikat = true;
                }
                Q = Q->next;
            }
            if (duplikat) {
                cout << "[!] Gagal insert. ID kurir sudah terdaftar.\n";
            } else {
                adrParent P = createElemenParent(x);
                insertFirstParent(L, P);
                cout << "[+] Kurir berhasil ditambahkan.\n";
            }

        } else if (option == 2) {
            infotypeParent x = inputDataKurir();

            adrParent Q = L.first;
            bool duplikat = false;

            while (Q != nullptr) {
                if (Q->info.idKurir == x.idKurir) {
                    duplikat = true;
                }
                Q = Q->next;
            }
            if (duplikat) {
                cout << "[!] Gagal insert. ID kurir sudah terdaftar.\n";
            } else {
                adrParent P = createElemenParent(x);
                insertLastParent(L, P);
                cout << "[+] Kurir berhasil ditambahkan.\n";
            }
        } else if (option == 3) {
            infotypeParent x = inputDataKurir();

            adrParent Q = L.first;
            bool duplikat = false;

            while (Q != nullptr) {
                if (Q->info.idKurir == x.idKurir) {
                    duplikat = true;
                }
                Q = Q->next;
            }
            if (duplikat) {
                cout << "[!] Gagal insert. ID kurir sudah terdaftar.\n";
            } else {
                adrParent P = createElemenParent(x);
                insertParentByCondition(L, P);
                cout << "[+] Kurir berhasil ditambahkan.\n";
            }

        } else if (option == 4) {
            int id;
            cout << "Masukkan ID kurir: ";
            cin >> id;
            deleteParentByCondition(L, id);

        } else if (option == 5) {
            viewAllKurir(L);

        } else if (option == 6) {
             viewKurirDetail(L);

        } else if (option == 7) {
             viewKurirWithMostPaket(L);
        } else if (option == 0){
            system("cls");
        }else {
            system("cls");
            cout << "Opsi invalid euy~ \n";
        }
    }
}

void menuChild(ListParent &L) {
    int option = -99;

    while (option != 0) {
        cout << "=========== Menu Child ===========\n";
        cout << "|| 1. Insert Paket ke Kurir     ||\n";
        cout << "|| 2. Delete Paket dari Kurir   ||\n";
        cout << "|| 3. View Paket Kurir          ||\n";
        cout << "|| 0. Back                      ||\n";
        cout << "==================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            string nama;
            cout << "Masukkan nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "Kurir tidak ditemukan.\n";
                continue;
            }

            infotypeChild Cinfo = inputDataPaket();

            adrChild Q = P->firstChild;
            bool duplikat = false;

            while (Q != nullptr) {
                if (Q->info.idPaket == Cinfo.idPaket) {
                    duplikat = true;
                }
                Q = Q->next;
            }

            if (duplikat) {
                cout << "[!] Gagal insert. ID paket sudah ada.\n";
            } else {
                adrChild C = createElemenChild(Cinfo);
                insertChild(P, C);
                cout << "[+] Paket berhasil ditambahkan.\n";
            }

        } else if (option == 2) {
            string nama;
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
            string nama;
            cout << "Nama kurir: ";
            cin >> nama;

            adrParent P = findKurirByName(L, nama);
            if (P == nullptr) {
                cout << "Kurir tidak ditemukan.\n";
                continue;
            }

            viewChild(P);
        }else if (option == 0){
            system("cls");
        } else {
            system("cls");
            cout << "Opsi invalid euy~ \n";
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
    cout << "Berat (kg)       : ";
    cin >> x.berat;

    return x;
}

