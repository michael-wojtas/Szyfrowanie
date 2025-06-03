def szyfruj(tekst, klucz, ile_razy):
    alfabet = [
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    ]
    wynik = tekst

    for _ in range(ile_razy):
        nowy = ""
        for znak in wynik:
            if znak in alfabet:
                poz = alfabet.index(znak)
                nowy_poz = (poz + klucz) % len(alfabet)
                nowy += alfabet[nowy_poz]
            else:
                nowy += znak
        wynik = nowy
    return wynik

def deszyfruj(tekst, klucz, ile_razy):
    return szyfruj(tekst, -klucz, ile_razy)

while True:

    print("1 - Szyfrowanie")
    print("2 - Deszyfrowanie")
    print("3 - Wyjście z Programu")
    wybor = input("Wybierz opcję (1 lub 2): ")

    if wybor == "1":
        tekst = input("Podaj tekst (małe litery!): ")
        klucz = int(input("Podaj przesunięcie: "))
        ile = int(input("Ile razy szyfrować?: "))
        print("Zaszyfrowany tekst:", szyfruj(tekst, klucz, ile))

    elif wybor == "2":
        tekst = input("Podaj tekst (małe litery!): ")
        klucz = int(input("Podaj przesunięcie: "))
        ile = int(input("Ile razy było szyfrowane?: "))
        print("Odszyfrowany tekst:", deszyfruj(tekst, klucz, ile))

    elif wybor == "3":
        print("Wyjście z programu.")
        break

    else:
        print("Nieprawidłowy wybór.")



