#include <iostream>
#include <array>

class Game{
    public:
        Game();
        std::string p1;
        std::string p2;
        char token;
        int broj_zauzetih_mjesta;
        std::array<std::array<char, 3>, 3> ploca;

        void unesiImeIgraca1(std::string ime);
        void unesiImeIgraca2(std::string ime);
        void ispisPloce();
        void kontrolaIgre();
        int pobjednik();
        int provjeraStanjaIgre();
};