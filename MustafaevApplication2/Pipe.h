#ifndef PIPE_H
#define PIPE_H
#include <iostream>
#include <string>

class Pipe {

private:
	int id;
	std::string name;
	double length;
	double diametr;
	bool repair;
	double efficiency;
	int outputStation = 0;
	int inputStation = 0;
public:
	Pipe();
	static int IDp;

	// get
	int getId() const;
	double getLength() const;
	bool getRepair() const;
	double getDiametr() const;
	std::string getName() const;
	double getEfficiency() const;
	int getInputStation() const;
	int getOutputStation() const;

	//set
	void setLength(double length);
	void setDiametr(double diametr);
	void setRepair(bool repair);
	void setName(std::string name);
	void Edit();
	void setInputStation(int id);
	void setEfficiency(double efficiency);
	void setOutputStation(int id);

	//
	void updateRepair();
	//
	void Save(std::ofstream& fout);
	void Load(std::ifstream& fin);

	friend std::ostream& operator << (std::ostream& out, Pipe& pipe);
		
	friend std::istream& operator >> (std::istream& in, Pipe& pipe);
};

#endif