
#ifndef SPARSEMATRIX_
#define SPARSEMATRIX_
#include <iostream>
#include<vector>
#include<string>
using namespace std;

class SparseMatrix {

public:
	int sizeX;
	int sizeY;
	vector<int> values;
	vector<int> RowX;
	vector<int> ColumnY;


	// constructor


	// methods
	
	void SetMatrix(int nelements); //Función para inputear los datos a la matriz 

	int Suma(); //Suma dos matrices y genera una nueva con los datos sumados

	int Resta(); //Resta dos matrices y genera una nueva con los datos restados

	int Multiplicacion(); //Multiplica dos matrices y genera una nueva con el resultado (identificar los casos con valores indefinidos)

	int MultiEscalar(); //Multiplica los valores de la matriz por un valor inputeado 

	int Transposicion(); //Swappear las coordenadas x, y

	int getSparsity(); // Devuelve la dispersión de la matrix
	
	int getValues(); //Devuelve los valores de la matriz como una lista

};
#endif