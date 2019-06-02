#include "fun.h"
#include "string.h"
void calcTot(User &X) {
	X.avg = 0;
	for (int j = 0; j < X.n; j++) {
		X.avg += X.nd[j];
	}
	X.avg /= X.n;
	X.ig = 0.4 * X.avg + 0.6 * X.egz;
}

void calcMed(User &X) {
	for(int i = 0; i < X.n - 1; i++) {
		for(int j = i + 1; j < X.n; j++) {
			if (X.nd[i] > X.nd[j]) {
				int t = X.nd[i];
				X.nd[i] = X.nd[j];
				X.nd[j] = t;
			}
		}
	}
	int k = X.n / 2;
	if (X.n % 2 != 0)
		X.med = X.nd[k];
	else
		X.med = (X.nd[k] + X.nd[k - 1]);
}

void sortVec(User *X, int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if (strcmp(X[i].name, X[j].name) > 0) {
				User t = X[i];
				X[i] = X[j];
				X[j] = t;
			}
		}
	}
}
