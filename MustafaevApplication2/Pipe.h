#include <string>
#include <iostream>

class Pipe {
private:
	
	double length;
	double diametr;
	bool inRepair;
	std::string name;

public:
	unsigned int id;
	Pipe();
	double getLength() const;
	double getDiametr() const;
	bool getInRepair() const;
	void setName(std::string name);
	std::string getName();
	void setLength(double length);
	void setDiametr(double diametr);
	void setInRepair(bool inRepair);
	void saveFile(std::ofstream& fout);
	bool check();
	void updateInRepair();
};

