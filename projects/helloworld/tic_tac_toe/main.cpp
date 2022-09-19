#include <iostream>
#include "tic_tac_toe.h"

int main() {
    Game Game1;
    std::string prvi, drugi;
    std::cout << "Upisite ime prvog igraca: ";
    std::cin >> prvi;
    std::cout << "Upisite ime drugog igraca: ";
    std::cin >> drugi;

    Game1.unesiImeIgraca1(prvi);
    Game1.unesiImeIgraca2(drugi);

    while (Game1.provjeraStanjaIgre() == 0) {
        Game1.ispisPloce();
        Game1.kontrolaIgre();
    }

    if (Game1.provjeraStanjaIgre() == 1 || Game1.provjeraStanjaIgre() == 2) {
        if (Game1.pobjednik() == 1) {
            std::cout << Game1.p1 << " je pobjednik!" <<std::endl;
        }
        else {
            std::cout << Game1.p2 << " je pobjednik!" << std::endl;
        }
    }

    if (Game1.provjeraStanjaIgre() == 3) {
        std::cout << "Izjednaceno je!" << std::endl;
    }
    
    return 0;
}