#pragma once
class Pipe {
private:
	unsigned int id;
	double length;
	double diametr;
	bool repair;
public:
	static unsigned int IDp;
	int getId() const;
	double getLength() const;
	bool getRepair() const;
	double getDiametr() const;
	void setLength(double length);
	void setDiametr(double diametr);
	void setRepair(bool repair);
	void setId(int id);
	void updateRepair();
};