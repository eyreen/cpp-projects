#include <iostream>
using namespace std;
class worker
{
public:

	worker();
	worker(string, string, double);

	string getid();
	string getName();
	double getSalary();

	void setID(string);
	void setName(string);
	void setSalary(double);

	virtual void print();

private:

	string id;
	string name;
protected:
	double salary;
	virtual double process() = 0;
};

class partTime : public worker
{
public:
	partTime();
	partTime(string, string, double, int);
	int getDays();
	void setDays(int);
	void print();
private:
	int days;
protected:
	virtual double process();
};

class fullTime : public worker
{
public:
	fullTime();
	fullTime(string, string, double, double);
	double getBonus();
	double getDeduct();
	void setBonus(double);
	void print();

private:
	double bonus;
	double deduct;

protected:
	virtual double process();
};