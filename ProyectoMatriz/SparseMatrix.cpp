
#include "SparseMatrix.h"
#include <iostream>
#include<vector>
#include<string>

using namespace std;

void SparseMatrix::setSize() {
	cout << "Input the x, y dimensions of the Sparse Matrix: "<<endl;
	cin >> sizeX >> sizeY;

};

void SparseMatrix::setMatrix()	
{
	int nelements;
	cout << "Number of values to set: ";
	cin >> nelements;

	for (int i = 0; i < nelements;) {
		int v, x, y;
		int cont;
		cout << "input value followed by x, y coordinates: " << endl;
		cin >> v;

		do {
			cont = 0; cin >> x >> y;
			x -= 1; y -= 1;
			if (0 > x || x > sizeX || 0 > y || y > sizeY) {
				cont++;
				cout << "coordinates out of bounds, reinput another coordinate" << endl;


			}
			else {
				for (int u = 0; u < SparseMatrix::values.size(); u++) {
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

};


int SparseMatrix::Suma(SparseMatrix OtherMatrix) {
	if (sizeX <= OtherMatrix.sizeX) {
		sizeX = OtherMatrix.sizeX;
	}
	if (sizeY <= OtherMatrix.sizeY) {
		sizeY = OtherMatrix.sizeY;
	}

	for (int i = 0; i < values.size(); i++) {
		for (int u = 0; u < OtherMatrix.values.size(); u++) {
			if (RowX[i] == OtherMatrix.RowX[u]) {
				if (ColumnY[i] == OtherMatrix.ColumnY[u]) {
					cout << "Match Found" << endl;
					values[i] += OtherMatrix.values[u];
					cout << values[i];
				}
			}
			else {
				values.push_back(OtherMatrix.values[u]);
				RowX.push_back(OtherMatrix.RowX[u]);
				ColumnY.push_back(OtherMatrix.ColumnY[u]);

			}
		
		}
	}
	return 0;
};

int SparseMatrix::Resta() {
	return 0;
};

int SparseMatrix::Multiplicacion() {
	return 0;
};

int SparseMatrix::MultiEscalar() {

	int Scalar;
	cout << "Input scalar to multiply vector: ";
	cin >> Scalar;

	if (Scalar == 0) {
		cout << "Multiplying by 0 erases the Sparse Matrix, the operation will not proceed"<<endl;
		return 0;
	}

	else {
		for (int i = 0; i < values.size(); i++) {
			values[i] = values[i] * Scalar;
		}
		cout << "Scalar multiplication sucessful" << endl;
	}
};

int SparseMatrix::Transposicion() {
	return 0;
};

int SparseMatrix::getSparsity() {
	return 0;
};

int SparseMatrix::getValues() {
	cout << "values in vector values= ";
	for (int i = 0; i < values.size(); i++) {
		cout << values[i] << ", ";	
	}
	cout << endl;
	return 0;
};