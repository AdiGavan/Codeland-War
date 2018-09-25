//Nume: Gavan Adrian George
//Grupa: 314CA

#include <stdio.h>

//functii folosite
int transformare_binar(int d, int b, int *p, int pos);    //transformare numar intreg in binar
int transformare_intreg(int *p, int x, int y);		  //transformare binar in intreg
int putere(int x, int y);				  //functie de ridicare la putere
void initializare_matrice(int m,int n,int matrice[][400]);//functie de initializare a matricelor
void baza(int mat[][400],int m, int n, int i, int j);     //numar baze dintr-o reuniune (dimensiune reuniune)
int viz[400][400];					  //matrice baze vizitate
int baza_curenta = 0;					  

int main()
{
	int b, m, n;		 	//datele de intrare
	int mat[400][400];        	//matricea bazelor	
	int numar, pos = 0, a = 0;	//numar citit, pozitia curenta, nr. biti adaugati			
	int x, y;			//x si y pentru intervale
	int nr_format;			//numar intreg format din bitii x->y						
	int i, j;			//iteratii linii, coloane
	int baza_max = 0; 		//maximul de baze intr-o reuniune  			
	int lista_baze[3][80000];	//salvare linii, coloane si dimensiune reuniuni baze
	int lista;			//iterator pt. matricea lista
	int nr_grp = 0;		        //nr. de reuniuni(grupuri)
	int key[200000];		//vector pentru sirul de biti
	int* p;				//pointer la vectorul de biti
	p = key;			

	//task 1
	scanf("%d", &b);
	scanf("%d", &m);
	scanf("%d", &n);
	initializare_matrice(m, n, mat);
	//se formeaza sirul de biti	
	do{
		scanf("%d", &numar);
		if(numar == -1){
			break;
		}
		//reintializare a cu 0 cand s-a atins nr. b de biti
		if(pos % b == 0){
			a = 0;
		}
		//se pune ((pos/b) + 1)*b-pos pentru det. nr. de biti ramasi liberi din b 
		a = transformare_binar(numar, ((pos / b) + 1) * b - pos, p, pos);
		pos = pos + a;
	}while(numar != -1);
	//afisare rezultat task 1
	for(i = 0; i < pos; i++){
		printf("%d ", p[i]);
	}
	printf("\n");

	//task2;
	do{
		scanf("%d", &x);
		scanf("%d", &y);
		if(x == -1 && y == -1){		 //verificare conditie iesire
			break;
		}
		//verificare conditii x si y din tema
		if( y < x || x >= pos || y < 0){ //conditie 1
			continue;
		}else{
			if(x < 0){		//conditia 2
				x = 0;
			}
			if(y >= pos){		//conditia 3	
				y = pos - 1;		
			}
			if(y - x > 30){		//conditia 4
				y = x + 30;
				if(y >= pos){
					y = pos - 1;
				}
			}
			//se formeaza intregul din binar
			nr_format = transformare_intreg(p, x, y);
			if (nr_format > (m * n)){                 //conditia 5
				nr_format = nr_format % (m * n);
			}
			//se marcheaza baza in matrice
			mat[nr_format/n][nr_format%n] = 1;	
			printf("%d ", nr_format);
		}
	}while(1);	//conditie de loop(intotdeauna adevarat)
	printf("\n");

	//task 3
	initializare_matrice(m, n, viz);  //initializare matrice vizite
	//initializare_matrice lista
	for(i = 0; i < 3; i++){
		for(j = 0; j < 80000; j++){
			lista_baze[i][j] = 0;
		}
	}
	nr_grp = 0;
	baza_max = 0;
	//pt. fiecare baza nevizitata din matrice se calculeaza numarul de baze din reuniune
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			baza_curenta = 0;
			baza(mat, m, n, i, j); //calculeaza nr. baze din reuniunea ce incepe la i,j
			//pentru fiecare prima baza gasita se memoreaza numarul de baze din reuniune, linia, coloana
			if(baza_curenta != 0){
				lista_baze[0][nr_grp] = baza_curenta;
				lista_baze[1][nr_grp] = i;
				lista_baze[2][nr_grp] = j;
				//se retine numarul maxim de baze din reuniuni
				if(baza_max < lista_baze[0][nr_grp]){
					baza_max = lista_baze[0][nr_grp];
				}
				nr_grp++;
			}
		}
	}
	//se afiseaza cele mai sigure reuniuni de baze
	for(lista = 0; lista < nr_grp; lista++){
		if(lista_baze[0][lista] == baza_max){
			printf("%d %d %d\n", lista_baze[1][lista], lista_baze[2][lista], lista_baze[0][lista]);
		}
	}    
	return 0;
}

//transformare numar intreg in binar
int transformare_binar(int numar, int b, int *p, int pos){
	int c, aux;
	int i; 
	int k = 0;
	int v[32] = {0}; //v primeste 32 pentru ca nu pot fi mai multi de 32 de biti
	int rezultat = 0;
	c = 0;
	aux = numar;
	i = 31;
	if(aux == 0){
		v[i] = 0;
		k++;
	}else{	
		//transformare in binar
		//stocam numarul la finalul vectorului, v[31] fiind cel mai nesemnificativ bit
		while (aux != 0){
			c = aux % 2;
			v[i] = c;
			aux = aux / 2;
			i--;
			k++;
		}
	}
	//se compara cu b si adaugam noii biti la sir
	if(k <= b){	
		for(i = 0; i < k; i++){
			p[i+pos] = v[32 - k + i];
			rezultat = k;
		}
	}else{
		for(i = 0; i < b; i++){
			p[i+pos] = v[32 - k + i];
			rezultat = b; 
		}
	}
	return rezultat;
}

//functie ce ridica la putere
int putere(int x, int y){
	int p, i;
	p = x;
	if (x == 0){
		p = 0;
		return p;
	}
	if (y == 0){
		p = 1;
		return p;
	}
	if (y == 1){
		p = x;
		return p;
	}
	for (i = 2; i <= y; i++){
		p = p * x;
	}
	return p;
}

//transformare binar (interval x->y)in intreg
int transformare_intreg(int *p, int x, int y){ 
	int i, nr_intreg, k;
	i = 0;
	nr_intreg = 0;
	k = 0;
	for(i = y; i >=x ; i--){
		nr_intreg = nr_intreg + p[i] * putere(2, k);
		k++;
	}
	return nr_intreg;
}

//functie de initializare a matricilor cu 0
void initializare_matrice(int m,int n,int matrice[][400]){
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			matrice[i][j] = 0;
		}
	}
}

//functie determinare numar baze dintr-o reuniune (dimensiune reuniune)
void baza(int mat[][400], int m, int n, int i, int j){  
	if(viz[i][j]){	//verifica daca baza a fost vizitata
		return;
	}
	if(i < 0 || j < 0 || i >= m || j >= n){ //verifica daca i, j sunt in afara dimensiunilor matricei
		return;
	}
	if(!mat[i][j]){		//verifica daca celula e 0
		viz[i][j] = 1;  //o marcheaza ca vizitat
        	return;
	}
	baza_curenta++;
	viz[i][j] = 1;
	//apeleaza functia recursiv pentru celulele vecine pe orizontala si verticala
	baza(mat, m, n, i,j-1); //stanga
	baza(mat, m, n, i+1,j); //jos
	baza(mat, m, n, i,j+1); //dreapta
	baza(mat, m, n, i-1,j); //sus
}













	
	
