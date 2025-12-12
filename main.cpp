#include <iostream>
#include "main.h"
using namespace std;

// deklarasi supaya dikenali compiler
void loadDummyDataKurir(ListParent &L);
void menuAdmin(ListParent &L);
void menuStudiKasus(ListParent &L);

int main() {
    ListParent listAdmin;
    ListParent listUser;

    createListParent(listAdmin);
    createListParent(listUser);

    /*DUMMY ONLYY!!!!!*/
    loadDummyDataKurir(listUser);

    int option = 0;
    while (option != 3) {
        cout << "\n================ MENU UTAMA ================\n";
        cout << "1. Menu Admin\n";
        cout << "2. Menu User (Studi Kasus)\n";
        cout << "3. Exit\n";
        cout << "============================================\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            menuAdmin(listAdmin);

        } else if (option == 2) {
            menuStudiKasus(listUser);
        } else if (option == 3) {
            cout << "Program selesai.\n";
        } else {
            cout << "[!] Option invalid.\n";
        }
    }

    return 0;
}
