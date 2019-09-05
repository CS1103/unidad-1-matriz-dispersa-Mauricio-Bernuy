
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


	// methods
	
	void setSize(); //funcion para inputear el tamaño de la matriz (DONE)

	void setMatrix(); //Función para inputear los datos a la matriz (DONE)

	void Suma(SparseMatrix OtherMatrix); //Suma dos matrices y devuelve una nueva con los datos sumados (DONE)

	void Resta(SparseMatrix OtherMatrix); //Resta dos matrices y genera una nueva con los datos restados (DONE)

	void Multiplicacion(SparseMatrix OtherMatrix); //Multiplica dos matrices y genera una nueva con el resultado (identificar los casos con valores indefinidos) [NOT DONE]

	void MultiEscalar(); //Multiplica los valores de la matriz por un valor inputeado (DONE)

	void Transposicion(); //Swappear las coordenadas x, y (DONE)

	float getSparsity(); // Devuelve la dispersión de la matrix  (DONE)
	
	int getValues(); //Devuelve los valores de la matriz como una lista (DONE)

	int getCoordinates(); //Devuelve las coordenadas x,y como dos listas (DONE)
};
#endif