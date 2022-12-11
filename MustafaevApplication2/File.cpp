#pragma once
#include "File.h"


ofstream OpenFout(const string name) {
	ofstream fout(name + ".txt");
	return fout;
}

ifstream OpenFin(const string name) {
	ifstream fin;
	fin.open(name + ".txt");
	if (fin.is_open()) {
		return fin;
	}
}

void FoutClose(ofstream& fout) {
	fout.close();
}

void FinClose(ifstream& fin) {
	fin.close();
}