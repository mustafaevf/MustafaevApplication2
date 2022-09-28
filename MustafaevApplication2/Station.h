
class Station {
private:
	std::string name;
	int countWorkshop;
	int countActiveWorkshop;
	double efficiency;

public:
	Station();
	void setName(std::string name);
	void setCountWorkshop(int countWorkshop);
	void setCountActiveWorkshop(int countActiveWorkshop);
	void setEfficiency(double efficiency);
	std::string getName() const;
	int getCountWorkshop() const;
	int getCountActiveWorkshop() const;
	double getEfficiency() const;
};
