#include<iostream>
#include<vector>
#include<string>
#include "SparseMatrix.h"

using namespace std;


int main() {
	SparseMatrix m1;
	m1.setSize();
	SparseMatrix m2;
	m2.setSize();
	m1.setMatrix();
	m2.setMatrix();
	m1.Transposicion();
	m1.Suma(m2);
	m1.MultiEscalar();
	m1.getSparsity();
	m2.setMatrix();
	m2.Resta(m1);

};
