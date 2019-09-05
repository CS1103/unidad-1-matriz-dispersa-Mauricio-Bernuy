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
	m1.Suma(m2);
	m1.getValues();
	

};
