#pragma once
#include<iostream>
#include<vector>
#include<string>


using namespace std;

void SparseMatrix::SetMatrix(int nelements)
{
	int nelements;
	cout << "input size: ";
	cin >> nelements;

	for (int i = 0; i < nelements;) {
		int v, x, y;
		int cont;
		cout << "input value followed by x, y coordinates: " << endl;
		cin >> v;

		do {
			cont = 0; cin >> x >> y;

			if (0 > sizeX || x > 10 || 0 > y || y > sizeY) {
				cont++;
				cout << "coordinates out of bounds, reinput another coordinate" << endl;


			}
			else {
				for (int u = 0; u < values.size(); u++) {
					cout << "lol2";
					if (RowX[u] == x) {
						if (ColumnY[u] == y) {
							cont++;
							cout << "coordinates already filled, reinput another coordinate" << endl;
							u--;
							break;
						}
					}

				}
			}
		} while (cont == !0);


		values.push_back(v); RowX.push_back(x); ColumnY.push_back(y);
		cout << "values validated" << endl << "\n" << endl;
		i++;
	}
	cout << "SetMatrix Finished. Values in vector values= ";
	for (int i = 0; i < nelements; i++) {
		cout << values[i] << ", ";
	}
}

}

int SparseMatrix::Suma()
{
	return 0;
}

