#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void szyfruj(const string &tekst, int klucz, int ile_razy, string &wynik) {

    const vector<char> alfabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                  'u', 'v', 'w', 'x', 'y', 'z'};
    wynik = tekst;


    for (int i = 0; i < ile_razy; ++i) {
        string nowy = "";


        for (char znak : wynik) {

            auto it = find(alfabet.begin(), alfabet.end(), znak);
            if (it != alfabet.end()) {
                int poz = distance(alfabet.begin(), it);
                int nowy_poz = (poz + klucz + alfabet.size()) % alfabet.size();
                nowy += alfabet[nowy_poz];
            } else {
                nowy += znak;
            }
        }
        wynik = nowy;
    }
}

// Funkcja do deszyfrowania tekstu
void deszyfruj(const string &tekst, int klucz, int ile_razy, string &wynik) {
    szyfruj(tekst, -klucz, ile_razy, wynik);
}

int main() {
    while (true) {
        cout << "1 - Szyfrowanie" << endl;
        cout << "2 - Deszyfrowanie" << endl;
        cout << "3 - Wyjście z programu" << endl;
        cout << "Wybierz opcję (1, 2 lub 3): ";

        int wybor;
        cin >> wybor;

        if (wybor == 1) {
            cin.ignore(); // Ignorujemy znak nowej linii po wczytaniu wyboru
            cout << "Podaj tekst: ";
            string tekst;
            getline(cin, tekst);

            cout << "Podaj przesunięcie: ";
            int klucz;
            cin >> klucz;

            cout << "Ile razy szyfrować?: ";
            int ile_razy;
            cin >> ile_razy;

            string zaszyfrowany;
            szyfruj(tekst, klucz, ile_razy, zaszyfrowany); // Wywołanie funkcji szyfrującej
            cout << "Zaszyfrowany tekst: " << zaszyfrowany << endl;
        }
        else if (wybor == 2) {
            cin.ignore(); // Ignorujemy znak nowej linii po wczytaniu wyboru
            cout << "Podaj tekst: ";
            string tekst;
            getline(cin, tekst);

            cout << "Podaj przesunięcie: ";
            int klucz;
            cin >> klucz;

            cout << "Ile razy było szyfrowane?: ";
            int ile_razy;
            cin >> ile_razy;

            string odszyfrowany;
            deszyfruj(tekst, klucz, ile_razy, odszyfrowany); // Wywołanie funkcji deszyfrującej
            cout << "Odszyfrowany tekst: " << odszyfrowany << endl;
        }
        else if (wybor == 3) {
            cout << "Wyjście z programu." << endl;
            break;
        }
        else {
            cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }

        cout << endl; // Dodanie pustej linii dla większej czytelności
    }

    return 0;
}