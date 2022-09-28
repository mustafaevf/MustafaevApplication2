
class Pipe {
private:
	double length;
	double diametr;
	bool inRepair;

public:
	Pipe();
	double getLength() const;
	double getDiametr() const;
	bool getInRepair() const;
	void setLength(double length);
	void setDiametr(double diametr);
	void setInRepair(bool inRepair);
};

