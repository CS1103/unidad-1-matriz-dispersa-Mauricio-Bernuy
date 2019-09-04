
#ifndef SPARSEMATRIX_
#define SPARSEMATRIX_
#include "SparseMatrix.h"
#include<iostream>



using namespace std;



void SparseMatrix::SetMatrix(int nelements)
{

	for (int i = 0; i < nelements;) {
		int v, x, y;
		int cont;
		cout << "input value followed by x, y coordinates: " << endl;
		cin >> v;

		do {
			cont = 0; cin >> x >> y;

			if (0 > sizeX || x > 10 || 0 > y || y > SparseMatrix::sizeY) {
				cont++;
				cout << "coordinates out of bounds, reinput another coordinate" << endl;


			}
			else {
				for (int u = 0; u < SparseMatrix::values.size(); u++) {
					cout << "lol2";
					if (SparseMatrix::RowX[u] == x) {
						if (SparseMatrix::ColumnY[u] == y) {
							cont++;
							cout << "coordinates already filled, reinput another coordinate" << endl;
							u--;
							break;
						}
					}

				}
			}
		} while (cont == !0);


		SparseMatrix::values.push_back(v); SparseMatrix::RowX.push_back(x); SparseMatrix::ColumnY.push_back(y);
		cout << "values validated" << endl << "\n" << endl;
		i++;
	}
	cout << "SetMatrix Finished. Values in vector values= ";
	for (int i = 0; i < nelements; i++) {
		cout << SparseMatrix::values[i] << ", ";
	}
};


int SparseMatrix::Suma() {
	return 0;
};

int SparseMatrix::Resta() {
	return 0;
};

int SparseMatrix::Multiplicacion() {
	return 0;
};

int SparseMatrix::MultiEscalar() {
	return 0;
};

int SparseMatrix::Transposicion() {
	return 0;
};

int SparseMatrix::getSparsity() {
	return 0;
};



#endif