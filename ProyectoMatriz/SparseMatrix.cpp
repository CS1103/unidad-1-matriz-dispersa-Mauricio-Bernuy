#include "SparseMatrix.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class SparseMatrix{
public:
	int sizeX;
	int sizeY;
	vector<int> values;
	vector<int> RowX;
	vector<int> ColumnY;
	

// constructor
	SparseMatrix(int sizeX, int sizeY);

// methods
	int SetMatrix(); //Función para inputear los datos a la matriz (implementar una opción para terminar)

	int Suma(); //Suma dos matrices y genera una nueva con los datos sumados

	int Resta(); //Resta dos matrices y genera una nueva con los datos restados

	int Multiplicacion(); //Multiplica dos matrices y genera una nueva con el resultado (identificar los casos con valores indefinidos)

	int MultiEscalar(); //Multiplica los valores de la matriz por un valor inputeado 

	int Transposicion(); //Swappear las coordenadas x, y

};