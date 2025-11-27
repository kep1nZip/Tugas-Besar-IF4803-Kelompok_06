#include "main.h"

void menuUser(){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1. studi case 1          ||" << endl;
        cout << "|| 2. studi case 2           ||" << endl;
        cout << "|| .....dst                 ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              // write your code here

              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
            // continue for another case here
        }
    }
}
