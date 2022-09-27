
class Station {
private:
	std::string name;
	int countWorkshop;
	int countActiveWorkshop;
	int efficiency;

public:
	Station();
	void setName(std::string name);
	void setCountWorkshop(int countWorkshop);
	void setCountActiveWorkshop(int countActiveWorkshop);
	void setEfficiency(int efficiency);
	std::string getName() const;
	int getCountWorkshop() const;
	int getCountActiveWorkshop() const;
	int getEfficiency() const;
};
