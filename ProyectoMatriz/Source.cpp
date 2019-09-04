#include<iostream>
#include<vector>
#include<string>
#include "SparseMatrix.h"

using namespace std;


int main() {
	SparseMatrix m1;
	m1.sizeX = 10;
	m1.sizeY = 10;
	m1.SetMatrix(3);
	m1.getValues();
	m1.MultiEscalar();
	m1.getValues();

};
