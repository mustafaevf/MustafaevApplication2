#pragma once
#include <fstream>
#include <map>
#include <iostream>

using namespace std;


ofstream OpenFout(const string name);

ifstream OpenFin(const string name);

void FoutClose(ofstream& fout);

void FinClose(ifstream& fin);

template <typename Arg>
void SaveToFile(ofstream& fout, map<int, Arg>& objects) {
	fout << objects.size() << endl;
	for (auto& obj : objects) {
		obj.second.Save(fout);
	}
}

//void LoadFromFile(ifstream& fin);