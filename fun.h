#ifndef FUN_H
#define FUN_H

typedef struct TUser {
	char name[20];	//Vardas
	char sname[20];	//Pavarde
	int n;			//Kiekis padarytu namu darbu
	int nd[50];		//Namu darbu rezultatai
	int egz;		//Egzamenas
	double ig;		//Galutinis rezultatas
	double avg;		//Vidurkis
	double med;		//Mediana
} User;

void calcTot(User &X);
void calcMed(User &X);
void sortVec(User *X, int n);

#endif
