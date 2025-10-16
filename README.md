# Tema 2 — Password Policies

Acest repository conține implementarea ta pentru biblioteca/aplicația de verificare a parolelor pe baza unui set de **politici** configurabile.

## Ce face codul

- Definește politici de parolă (lungime, clase de caractere, include / nu include, repetiții, secvențe consecutive).
- Citește de la intrare un set de reguli, apoi verifică fiecare parolă pâna la EOF și afișează `OK` sau `NOK` în funcție de respectarea **tuturor** regulilor.
- Implementarea păstrează **codul original**; am adăugat doar comentarii explicative și acest fișier `README.md`.

## Politici suportate (conform cerinței)

- `length <min_length>` — lungime minimă.  `length <min_length> <max_length>` — lungime între min și max (inclusiv).
- `class <min_class_count>` — minim *k* tipuri de caractere din: literă mică, literă mare, cifră, alte caractere.
- `include <class>` — parola trebuie să conțină cel puțin un caracter din clasa dată (`a`, `A`, `0`, `$`).
- `ninclude <class>` — parola **nu** trebuie să conțină caractere din clasa dată.
- `repetition <max_count>` — același caracter nu poate apărea consecutiv de mai mult de *k* ori.
- `consecutive <max_count>` — maxim *k* caractere consecutive în secvență (ex. `abc`, `123`).

## Cum se rulează

### Compilare (g++)
```bash
g++ -std=c++17 -O2 -pipe -s -o password_policies main.cpp
# dacă proiectul are mai multe fișiere:
# g++ -std=c++17 -O2 -pipe -s -o password_policies *.cpp
```

### Rulare
Programul citește din stdin regulile și parolele, apoi printează pentru fiecare parolă `OK`/`NOK`.

```bash
./password_policies < input.txt
```

### Format intrare (exemplu)
```
4
length 6
include 0
include A
repetition 2
PimpMyPassword
HoldMyB33r
OnceUponAtimeinKansas
1234
```

### Ieșire pentru exemplul de mai sus
```
NOK
OK
NOK
NOK
```

## Note

- Am inserat comentarii **neintruzive** la începutul fișierelor și/sau înaintea unor secțiuni importante, fără a modifica logica originală.
- Data actualizării: 2025-10-16.
