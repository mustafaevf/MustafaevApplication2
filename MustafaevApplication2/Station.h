#include <string>

class Station {
private:
	int id;
	std::string name;
	int countWorkshop;
	int countActiveWorkshop;
	double efficiency;

public:
	static int IDcs;
	
	int getId() const;
	std::string getName() const;
	int getCountWorkshop() const;
	int getCountActiveWorkshop() const;
	double getEfficiency() const;
	
	void setName(std::string name);
	void setCountWorkshop(int countWorkshop);
	void setCountActiveWorkshop(int countActiveWorkshop);
	void setEfficiency(double efficiency);
	void setId(int id);

	void Save(std::ofstream& fout);
	void Load(std::ifstream& fin);
};