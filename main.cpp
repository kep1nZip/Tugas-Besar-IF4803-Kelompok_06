#include <iostream>
#include "main.h"
using namespace std;

int main() {
    ListParent L;
    createListParent(L);

    int option = -99;
    while (option != 0) {
        cout << "============ Menu ============ \n";
        cout << "|| 1. Admin                 ||\n";
        cout << "|| 2. User                  ||\n";
        cout << "|| 0. Exit                  ||\n";
        cout << "============================== \n";
        cout << "Choose your option: ";
        cin >> option;

        switch (option) {
            case 1:
                menuAdmin(L);
                break;
            case 2:
                menuStudiKasus(L);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Option invalid.\n";
        }
    }

    return 0;
}
