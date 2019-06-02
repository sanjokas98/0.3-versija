#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "fun.cpp"
using namespace std;
const int N = 50;	//Maksimalus studentu kiekis
int main() {
	system("chcp 1251"); // suinstaliojame kodiruote
	User std[N];
	int n;
	char ch;
	do {
		system("cls"); //nuvalome ekrana
		cout << "Skaitome is failo arba ivedame is klaviaturos?" << endl;
		cout << "[1] - Ivedame\n[2] - Skaitome\n" << endl;
		ch = getch();
	} while (ch < '1' || ch > '2');

	if (ch == '1') {
		try {
			cout << "Pateikite informacija apie kiek studentu mes vesime: ";
			(cin >> n).get();
			for (int i = 0; i < n; i++) {
				cout << "Informacijos ivedimas " << i + 1 << "pirma studenta:" << endl;
				cout << "Vardas: ";
				cin.getline(std[i].name, 20);
				cout << "Pavarde: ";
				cin.getline(std[i].sname, 20);
				cout << "Kiekis atliekamu namu darbu: ";
				cin >> std[i].n;
				cout << "Rezultatai is " << std[i].n << " namu darbu (per tarpa):" << endl;
				for (int j = 0; j < std[i].n; j++) {
					cin >> std[i].nd[j];
				}
				cout << "Egzameno rezultatas: ";
				(cin >> std[i].egz).get();
				calcTot(std[i]);
				calcMed(std[i]);
			}
		} catch (std::exception &e) {
			cout << "Nekorektiški pradiniai duomenys." << endl;
			n = -1;
		}
	}
	else {
		try {
			FILE *in = fopen("kursiokai.txt", "r");// atidarome faila nuo kurio nuskaiciuosime duomenys
			if (in != NULL) {
				n = 0;
				while (fscanf(in, "%s%s%d%d%d%d%d%d", &std[n].name, &std[n].sname, &std[n].nd[0], &std[n].nd[1], &std[n].nd[2], &std[n].nd[3], &std[n].nd[4], &std[n].egz) != EOF) {
					std[n].n = 5;
					calcTot(std[n]);
					calcMed(std[n]);
					n++;
				}
				fclose(in);
			}
			else
				cout << "Neisejo atidaryti faila." << endl;
		} catch (std::exception &e) {
			cout << "Klaida del darbo su failo." << endl;
			n = -1;
		}
	}
	if (n > 0) {
		sortVec(std, n);
		printf("%10s%10s%20s%20s\n", "Vardas", "Pavarde", "Galutinis (vidutinis)", "Gakutinis (Mediana)");
		printf("------------------------------------------------------------\n");
		for (int i = 0; i < n; i++) {
			printf("%10s%10s%20.2lf%20.2lf\n", std[i].name, std[i].sname, std[i].ig, std[i].med);
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
