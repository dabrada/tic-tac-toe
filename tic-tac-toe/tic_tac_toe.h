#include <iostream>

class game{
    public:
        game();
        ~game();
        std::string p1;
        std::string p2;
        int redak;
        int stupac;
        char token = 'x';
        int broj_zauzetih_mjesta = 0;
        char **ploca;
        char odabranoMjesto;

        void unesiImeIgraca1(std::string ime);
        void unesiImeIgraca2(std::string ime);

        void ispisPloce();
        void kontrolaIgre();
        int pobjednik();
        int provjeraStanjaIgre();
};