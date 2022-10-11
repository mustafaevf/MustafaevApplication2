#include <string>
#include <iostream>

class Station {
private:
	std::string name;
	int countWorkshop;
	int countActiveWorkshop;
	double efficiency;

public:
	unsigned int id;
	Station();
	void setName(std::string name);
	void setCountWorkshop(int countWorkshop);
	void setCountActiveWorkshop(int countActiveWorkshop);
	void setEfficiency(double efficiency);
	std::string getName() const;
	int getCountWorkshop() const;
	int getCountActiveWorkshop() const;
	void saveFile(std::ofstream& fout);
	double getEfficiency() const;
	void updateWorkshop(int newCount);
};
