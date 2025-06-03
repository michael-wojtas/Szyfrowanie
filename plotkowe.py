def szyfr(tekst):
  n = len(tekst)
  wynik = ""

  for i in range(0, n, 4):
    wynik += tekst[i]

  for i in range(1, n, 2):
    wynik += tekst[i]

  for i in range(2, n, 4):
    wynik += tekst[i]

  return wynik


def deszyfr(ods):
    n = len(ods)
    oryginal = [""] * n

    j = 0

    for i in range(0, n, 4):
        oryginal[i] = ods[j]
        j += 1

    for i in range(1, n, 2):
        oryginal[i] = ods[j]
        j += 1

    for i in range(2, n, 4):
        oryginal[i] = ods[j]
        j += 1

    return "".join(oryginal)

while True:
    print("Co chcesz zrobić?")
    print("1. Szyfruj")
    print("2. Deszyfruj")
    print("3. Wyjdź")
    wybor = input("Wybierz 1, 2 lub 3: ")

    if wybor == "1":
        tekst_jawny = input("Podaj tekst do zaszyfrowania: ")
        print("Zaszyfrowany tekst:", szyfr(tekst_jawny))
    elif wybor == "2":
        ods = input("Podaj zaszyfrowany tekst: ")
        print("Odszyfrowany tekst:", deszyfr(ods))
    elif wybor == "3":
        print("Wyjście z programu.")
        break
    else:
        print("Nieprawidłowy wybór.")