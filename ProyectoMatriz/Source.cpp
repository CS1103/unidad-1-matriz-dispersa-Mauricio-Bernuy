#include<iostream>
#include<vector>
#include<string>
#include "SparseMatrix.h"

using namespace std;


int main() {
	SparseMatrix m1;
	m1.setSize();
	m1.setMatrix();
	m1.getValues();
	m1.MultiEscalar();
	m1.getValues();

};
