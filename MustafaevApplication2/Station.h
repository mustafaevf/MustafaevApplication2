#ifndef STATION_H
#define STATION_H
#include <string>


class Station {
private:
	int id;
	std::string name;
	int countWorkshop;
	int countActiveWorkshop;
	double efficiency;
	

public:
	Station();
	static int IDcs;

	double weight = 0;
	int last = 0;
	int getId() const;
	std::string getName() const;
	int getCountWorkshop() const;
	int getCountActiveWorkshop() const;
	double getEfficiency() const;

	void setName(std::string name);
	void setCountWorkshop(int countWorkshop);
	void setCountActiveWorkshop(int countActiveWorkshop);
	void setEfficiency(double efficiency);
	
	void Save(std::ofstream& fout);
	void Load(std::ifstream& fin);

	friend std::ostream& operator << (std::ostream& out, Station& station);

	friend std::istream& operator >> (std::istream& in, Station& station);
};

#endif