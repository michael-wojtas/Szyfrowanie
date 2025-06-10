#include <iostream>
#include <string>
#include <vector>

using namespace std;


string szyfr(const string &tekst) {
    int n = tekst.length();
    string wynik = "";

    for (int i = 0; i < n; i += 4) {
        wynik += tekst[i];
    }

    for (int i = 1; i < n; i += 2) {
        wynik += tekst[i];
    }

    for (int i = 2; i < n; i += 4) {
        wynik += tekst[i];
    }

    return wynik;
}


string deszyfr(const string &ods) {
    int n = ods.length();
    vector<char> oryginal(n, '\0');
    int j = 0;

    for (int i = 0; i < n; i += 4) {
        oryginal[i] = ods[j++];
    }

    for (int i = 1; i < n; i += 2) {
        oryginal[i] = ods[j++];
    }

    for (int i = 2; i < n; i += 4) {
        oryginal[i] = ods[j++];
    }

    return string(oryginal.begin(), oryginal.end());
}


int main() {
    while (true) {
        cout << "Co chcesz zrobić?" << endl;
        cout << "1. Szyfruj" << endl;
        cout << "2. Deszyfruj" << endl;
        cout << "3. Wyjdź" << endl;
        cout << "Wybierz 1, 2 lub 3: ";

        int wybor;
        cin >> wybor;


        if (wybor == 1) {
            cin.ignore();
            cout << "Podaj tekst do zaszyfrowania: ";
            string tekst_jawny;
            getline(cin, tekst_jawny);
            cout << "Zaszyfrowany tekst: " << szyfr(tekst_jawny) << endl;
        }
        else if (wybor == 2) {
            cin.ignore();
            cout << "Podaj zaszyfrowany tekst: ";
            string ods;
            getline(cin, ods);
            cout << "Odszyfrowany tekst: " << deszyfr(ods) << endl;
        }
        else if (wybor == 3) {
            cout << "Wyjście z programu." << endl;
            break;
        }
        else {
            cout << "Nieprawidłowy wybór. Wybierz 1, 2 lub 3." << endl;
        }

        cout << endl;
    }

    return 0;
}