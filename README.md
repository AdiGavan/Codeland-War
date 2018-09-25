Nume: Gavan Adrian George

Grupa: 314CA

Tema 2: Codeland War

Informatii generale:
====================

- Acest program rezolva problema decriptarii datelor transmise de catre vrajitor 
locuitorilor din Codeland si problema gasirii celei mai sigure baze. Aceste date
contin locatiile tuturor bazelor unde se afla luptatorii din Codeland. Toate 
cele 3 taskuri care duceau la indeplinirea misiunii au fost realizate.

Prezentarea implementarii:
==========================

Functii folosite pentru implementarea temei:
1. Transformarea unui numar intreg in binar:
int transformare_binar(int d, int b, int *p, int pos);
2. Transformarea unui numar binar in intreg:
int transformare_intreg(int *p, int x, int y);
3. Functie pentru ridicare la putere:
int putere(int x, int y);
4. Functie de initializare cu 0 a matricelor:
void initializare_matrice(int m,int n,int matrice[][400]);
5. Functie de numarare a bazelor dintr-o reuniune (dimensiune reuniune):
void baza(int mat[][400],int m, int n, int i, int j);

Algoritm:
1) Task1
- Se initializeaza variabilele, vectorii, matricele si pointerii necesari rezolvarii 
temei.
- Se citeste "ingredientul principal" (b), reprezentand numarul maxim de biti care se
pot retine deodata.
- Se citesc de la tastatura dimensiunile matricei (m linii si n coloane).
- Se initializeaza cu 0 matricea "mat".
- Se creeaza un loop, se citesc numerele si se pune conditia ca citirea numerelor sa se opreasca la 
intalnirea valorii "-1".
- Se transforma numerele in binar si luam bitii necesari pentru completarea sirului
(in functie de b si de cati biti mai sunt necesari).
- Se adauga acesti biti la vectorul in care se retine sirul de biti.
- Variabila "pos" retine pozitia in care a fost memorat ultimul bit in vector,
pentru a se stii unde sa se puna urmatorii biti.
- Se afiseaza fiecare element al vectorului de biti, formandu-se astfel sirul de biti.
2) Task2
- Se creeaza un loop infinit (conditia de oprire va fi in loop).
- Se citesc capetele intervalului (x si y) si se pune conditia ca citirea sa se 
opreasca la intalnirea perechii {-1, -1}.
- Se verifica conditiile referitoare la x si y impuse de catre tema si se realizeaza
modificarile necesare.
- Se formeaza numarul intreg reprezentat de codul binar din intervalul x -> y.
- Se verifica conditia referitoare la numarul format (nr_format sa nu iasa din 
dimensiunea matricei). Daca nr_format este mai mare, atunci 
nr_format = nr_format % (m * n).
- In matricea initializata cu 0 vom pune elementul 1 pe pozitia corespunsatoare 
numarului format, aceasta pozitie reprezentand o baza.
- Se afiseaza toate numerele formate.
3) Task3
- Se initializeaza matricea viz (matrice cu baze vizitate).
- Se initializeaza matricea lista_baze. In aceasta matrice se vor stoca reuniunile de
baze astfel: pe prima linie numarul de baze continut de reuniune, pe a doua linie 
indicele liniei primei baze din reuniune, iar pe a 2a se va salva indicele coloanei 
primei baze din reuniune.
- Pentru fiecare baza nevizitata din matrice se calculeaza numarul de baze din reuniune.
- In cele 2 foruri (pentru parcurgerea matricei) apelam functia ce calculeaza numarul de 
baze din reuniunea ce incepe la i,j.
- Functia de calculare a numarului de baze din reuniune verifica daca i si j sunt in 
afara dimensiunii matricei, verifica daca celula este 0 si marcheaza ca vizitat. Daca nu
se indeplineste niciuna din conditiile de return, functia se apeleaza recursiv de 4 ori,
pentru fiecare din celulele vecine (de pe orizontala si de pe verticala).
- Se retine numarul maxim de baze din reuniuni.
- Se afiseaza cele mai sigure reuniuni de baze. Se compara numarul de baze al reuniunii 
respective cu numarul maxim de baze continut de o reuniune. Daca este egal, se vor 
afisa linia, coloana si numarul de baze.
 

Conditii impuse de tema:
========================

- 1<m<400 si 1<n<400;
- 0<b<32;
- Trebuie verificat daca:
  - x<y, y<0, x>=dimensiune_sir_biti (se va ignora perechea x si y);
  - x<0 (x va deveni 0);
  - y>=dimensiune_sir_biti (y va deveni pozitia ultimului bit);
  - y-x>30 (se va reduce y);
  - nr_format>m*n (nr_format = nr_format%(m*n));


