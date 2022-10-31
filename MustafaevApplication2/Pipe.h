#include <iostream>
#include <string>

class Pipe {

private:
	int id;
	std::string name;
	double length;
	double diametr;
	bool repair;
public:
	static int IDp;

	// get
	int getId() const;
	double getLength() const;
	bool getRepair() const;
	double getDiametr() const;
	std::string getName() const;

	//set
	void setLength(double length);
	void setDiametr(double diametr);
	void setRepair(bool repair);
	void setName(std::string name);
	void setId(int id);

	//
	void updateRepair();
	//
	void Save(std::ofstream& fout);
	void Load(std::ifstream& fin);

	/*friend std::ostream& operator << (std::ostream& out, Pipe& pipe);*/

	/*friend std::ifstream& operator >> (std::ifstream& fin, Pipe& pipe);*/
		
};