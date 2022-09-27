
class Pipe {
private:
	int length;
	int diametr;
	bool inRepair;

public:
	Pipe();
	int getLength() const;
	int getDiametr() const;
	bool getInRepair() const;
	void setLength(int length);
	void setDiametr(int diametr);
	void setInRepair(bool inRepair);
};

