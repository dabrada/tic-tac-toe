#include <iostream>
#include <array>
#include "tic_tac_toe.h"

Game::Game() {
    token = 'x';
    broj_zauzetih_mjesta = 0;
    ploca = {{{'1', '2', '3'},
              {'4', '5', '6'},
              {'7', '8', '9'}}};
}

void Game::unesiImeIgraca1(std::string ime) {
    p1 = ime;
}

void Game::unesiImeIgraca2(std::string ime) {
    p2 = ime;
}

void Game::ispisPloce() {
    std::cout << "  |     |     |     |" << std::endl;
    std::cout << "  |  " << ploca[0][0] << "  |  " << ploca[0][1] << "  |  " << ploca[0][2] << "  |" << std::endl;
    std::cout << "__|_____|_____|_____|__"  << std::endl;
    std::cout << "  |     |     |     |" << std::endl;
    std::cout << "  |  " << ploca[1][0] << "  |  " << ploca[1][1] << "  |  " << ploca[1][2] << "  |" << std::endl;
    std::cout << "__|_____|_____|_____|__"  << std::endl;
    std::cout << "  |     |     |     |" << std::endl;
    std::cout << "  |  " << ploca[2][0] << "  |  " << ploca[2][1] << "  |  " << ploca[2][2] << "  |" << std::endl;
    std::cout << "  |     |     |     |" << std::endl;
    std::cout << std::endl;
}

void Game::kontrolaIgre() {
    char odabranoMjesto;
    int redak;
    int stupac;

    if (token == 'x') {
        std::cout << "Na redu je " << p1 << ". Unesi zeljeno polje: ";
    }
    if (token == 'o') {
        std::cout << "Na redu je " << p2 << ". Unesi zeljeno polje: " ;
    }
    std::cin >> odabranoMjesto;

    switch (odabranoMjesto) {
        case '1':
            redak = 0;
            stupac = 0;
            break;
        case '2':
            redak = 0;
            stupac = 1;
            break;
        case '3':
            redak = 0;
            stupac = 2;
            break;
        case '4':
            redak = 1;
            stupac = 0;
            break;
        case '5':
            redak = 1;
            stupac = 1;
            break;
        case '6':
            redak = 1;
            stupac = 2;
            break;
        case '7':
            redak = 2;
            stupac = 0;
            break;
        case '8':
            redak = 2;
            stupac = 1;
            break;
        case '9':
            redak = 2;
            stupac = 2;
            break;
        default:
            std::cout << "Neispravna pozicija!" << std::endl;
            break;
    }

    if (ploca[redak][stupac] != 'x' && ploca[redak][stupac] != 'o') {
        if (token == 'x') {
            ploca[redak][stupac] = 'x';
            token = 'o';
        }
        else {
            ploca[redak][stupac] = 'o';
            token = 'x';
        }
        broj_zauzetih_mjesta += 1;
    }
    else {
        std::cout << "Odabrano je vec zauzeto mjesto!" << std::endl;
        kontrolaIgre();
    }
    ispisPloce();
}

int Game::pobjednik(){
    // pobjednik je prvi igrac
    // nakon sto je prvi igrac oznacio pobjednicko polje,
    // token se promijenio u 'x'
    if (token == 'o') {
        return 1;
    }
    // pobjednik je drugi igrac
    else {
        return 2;
    }
}

// 0 za nastavak igre
// 1 ili 2 kada postoji pobjednik
// 3 kada je ploca puna, ali nema pobjednika
int Game::provjeraStanjaIgre() {
    // provjera redaka i stupaca
    for (int i = 0; i < 3; ++i) {
        if (ploca[i][0] == ploca[i][1] && ploca[i][1] == ploca[i][2]) {
            return pobjednik();
        }
        if (ploca[0][i] == ploca[1][i] && ploca[1][i] == ploca[2][i]) {
            return pobjednik();
        }
    }

    // provjera glavne dijagonale
    if (ploca[0][0] == ploca[1][1] && ploca[1][1] == ploca[2][2]) {
        return pobjednik();
    }

    // provjera sporedne dijagonale
    if (ploca[0][2] == ploca[1][1] && ploca[1][1] == ploca[2][0]) {
        return pobjednik();
    }

    // jos nitko nije pobijedio

    if (broj_zauzetih_mjesta < 9) {
        return 0;
    }

    // igra je izjednacena
    return 3;
}