
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
			if (0 > x || x >= sizeX || 0 > y || y >= sizeY) {
				cont++;
				cout << "coordinates out of bounds, reinput another coordinate" << endl;

			}
			else {
				for (int u = 0; u < SparseMatrix::values.size(); u++) {
					if (SparseMatrix::RowX[u] == x) {
						if (SparseMatrix::ColumnY[u] == y) {
							cont++;
							cout << "coordinates already filled, reinput another coordinate" << endl;
							
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

void SparseMatrix::Suma(SparseMatrix OtherMatrix) {
	SparseMatrix suma;
	if (sizeX <= OtherMatrix.sizeX) {
		suma.sizeX = OtherMatrix.sizeX;
	}
	else { suma.sizeX = sizeX; };

	if (suma.sizeY <= OtherMatrix.sizeY) {
		suma.sizeY = OtherMatrix.sizeY;
	}
	else { suma.sizeY = sizeY; };


	cout << "starting first pass" << endl;
	for (int i = 0; i < values.size(); i++) {
		bool checker = true;
		for (int u = 0; u < OtherMatrix.values.size(); u++) {
			if (RowX[i] == OtherMatrix.RowX[u]) {
				//cout << "found in rowx" << endl;
				if (ColumnY[i] == OtherMatrix.ColumnY[u]) {
					//cout << "found in columny" << endl;
					//cout << "Match Found" << endl;
					suma.values.push_back(values[i] + OtherMatrix.values[u]);
					suma.RowX.push_back(RowX[i]);
					suma.ColumnY.push_back(ColumnY[i]);
					checker = false;
				}
				//cout << "exited columny, in if rowx" << endl;

			}
			//cout << checker << endl;

			if ((u + 1) == OtherMatrix.values.size()) {
				if (checker == true) {
					//cout << "gotta pushback";
					suma.values.push_back(values[i]);
					suma.RowX.push_back(RowX[i]);
					suma.ColumnY.push_back(ColumnY[i]);
					//cout << "pushed values";
				}
			}

			//cout << "exited rowx, in for U" << endl;


		}
		//cout << "exited for U, in for I" << endl;

	} 

	cout << "starting inverse pass"<<endl;
	for (int i = 0; i < OtherMatrix.values.size();i++) {
		bool checker = true;
		for (int u = 0; u < values.size(); u++) {
			if (OtherMatrix.RowX[i] == RowX[u]) {
				//cout << "found in rowx" << endl;
				if (OtherMatrix.ColumnY[i] == ColumnY[u]) {
					//cout << "found in columny" << endl;
					//cout << "Match Found, already summed in first pass" << endl;
					checker = false;
				}

				//cout << "exited columny, in if rowx" << endl;
			}
			//cout << checker << endl;

			if ((u + 1) == values.size()) {
				if (checker == true) {
					//cout << "gotta pushback";
					suma.values.push_back(OtherMatrix.values[i]);
					suma.RowX.push_back(OtherMatrix.RowX[i]);
					suma.ColumnY.push_back(OtherMatrix.ColumnY[i]);
					//cout << "pushed values";
				}
			}

			//cout << "exited rowx, in for U" << endl;


		}
		//cout << "exited for U, in for I" << endl;

	}

	cout << "Sum Sucessful. Created SparseMatrix suma"<<endl;
	suma.getValues();
	suma.getCoordinates();
	
};

void SparseMatrix::Resta(SparseMatrix OtherMatrix) {

	SparseMatrix resta;
	if (sizeX <= OtherMatrix.sizeX) {
		resta.sizeX = OtherMatrix.sizeX;
	}
	else { resta.sizeX = sizeX; };

	if (resta.sizeY <= OtherMatrix.sizeY) {
		resta.sizeY = OtherMatrix.sizeY;
	}
	else { resta.sizeY = sizeY; };


	cout << "starting first pass" << endl;
	for (int i = 0; i < values.size(); i++) {
		bool checker = true;
		for (int u = 0; u < OtherMatrix.values.size(); u++) {
			if (RowX[i] == OtherMatrix.RowX[u]) {
				//cout << "found in rowx" << endl;
				if (ColumnY[i] == OtherMatrix.ColumnY[u]) {
					//cout << "found in columny" << endl;
					//cout << "Match Found" << endl;
					resta.values.push_back(values[i] - OtherMatrix.values[u]);
					resta.RowX.push_back(RowX[i]);
					resta.ColumnY.push_back(ColumnY[i]);
					checker = false;
				}
				//cout << "exited columny, in if rowx" << endl;

			}

			if ((u + 1) == OtherMatrix.values.size()) {
				if (checker == true) {
					//cout << "gotta pushback";
					resta.values.push_back(values[i]);
					resta.RowX.push_back(RowX[i]);
					resta.ColumnY.push_back(ColumnY[i]);
					//cout << "pushed values";
				}
			}

			//cout << "exited rowx, in for U" << endl;


		}
		//cout << "exited for U, in for I" << endl;

	}

	cout << "starting inverse pass" << endl;
	for (int i = 0; i < OtherMatrix.values.size();i++) {
		bool checker = true;
		for (int u = 0; u < values.size(); u++) {
			if (OtherMatrix.RowX[i] == RowX[u]) {
				//cout << "found in rowx" << endl;
				if (OtherMatrix.ColumnY[i] == ColumnY[u]) {
					//cout << "found in columny" << endl;
					//cout << "Match Found, already substracted in first pass" << endl;
					checker = false;
				}

				//cout << "exited columny, in if rowx" << endl;
			}

			if ((u + 1) == values.size()) {
				if (checker == true) {
					//cout << "gotta pushback";
					resta.values.push_back(-(OtherMatrix.values[i]));
					resta.RowX.push_back(OtherMatrix.RowX[i]);
					resta.ColumnY.push_back(OtherMatrix.ColumnY[i]);
					//cout << "pushed values";
				}
			}

			//cout << "exited rowx, in for U" << endl;


		}
		//cout << "exited for U, in for I" << endl;

	}

	cout << "Substraction Sucessful. Created SparseMatrix resta"<<endl;
	resta.getValues();
	resta.getCoordinates();
};

void  SparseMatrix::Multiplicacion(SparseMatrix OtherMatrix) {
	SparseMatrix multiplicacion;
	if (sizeY = OtherMatrix.sizeX) {

		for (int i = 0; i < values.size(); i++) {
			
			bool checker = true;

			for (int u = 0; u < OtherMatrix.values.size(); u++) {
				if (ColumnY[i] == OtherMatrix.RowX[u]) {
					//cout << "found inverse" << endl;
					if (RowX[i] == OtherMatrix.ColumnY[u]) {
						//cout << "found in columny" << endl;
						//cout << "Match Found" << endl;

						checker = false;
					}
					//cout << "exited columny, in if rowx" << endl;
				}
				//cout << checker << endl;

				if ((u + 1) == OtherMatrix.values.size()) {
					if (checker == true) {
						//cout << "gotta pushback";
						multiplicacion.values.push_back(values[i]);
						multiplicacion.RowX.push_back(RowX[i]);
						multiplicacion.ColumnY.push_back(ColumnY[i]);
						//cout << "pushed values";
					}
				}

				//cout << "exited rowx, in for U" << endl;


			}
			//cout << "exited for U, in for I" << endl;

		}
		
	}
	else {
		cout << "Matrix size incompatible";
	}

};

void SparseMatrix::MultiEscalar() {

	int Scalar;
	cout << "Input scalar to multiply matrix: ";
	cin >> Scalar;

	if (Scalar == 0) {
		cout << "Multiplying by 0 erases the Sparse Matrix, the operation will not proceed"<<endl;
	}

	else {
		for (int i = 0; i < values.size(); i++) {
			values[i] = values[i] * Scalar;
		}
		cout << "Scalar multiplication sucessful" << endl;
	}
};

void SparseMatrix::Transposicion() {
	
	RowX.swap(ColumnY);
	cout << "values sucessfully inverted" << endl;
	getValues();
	getCoordinates();
};

float SparseMatrix::getSparsity() {
	float sparsity=0;
	sparsity = float ((sizeX * sizeY) - values.size()) / (sizeX * sizeY);
	cout << "Matrix has a sparsity of: "<<sparsity<<endl;
	return sparsity;
};

int SparseMatrix::getValues() {
	cout << "values in vector values= ";
	for (int i = 0; i < values.size(); i++) {
		cout << values[i] << ", ";	
	}
	cout << endl;
	return 0;
};

int SparseMatrix::getCoordinates() {
	cout << "       coordinates in x= ";
	for (int i = 0; i < RowX.size(); i++) {
		cout << RowX[i]+1 << ", ";
	}
	cout << endl;
	cout << "       coordinates in y= ";
	for (int i = 0; i < ColumnY.size(); i++) {
		cout << ColumnY[i]+1<< ", ";
	}
	cout << endl;
	return 0;
}