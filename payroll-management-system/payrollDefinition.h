#include "payroll.h"
#include <iostream>
using namespace std;
worker::worker()
{
	id = name = "";
	salary = 0.0;
}
worker::worker(string a, string b, double c)
{
	this->id = a;
	name = b;
	salary = c;
}
string worker::getid()
{
	return id;
}
string worker::getName()
{
	return name;
}
double worker::getSalary()
{
	return salary;
}
void worker::setID(string a)
{
	this->id = a;
}
void worker::setName(string b)
{
	name = b;
}
void worker::setSalary(double c)
{
	salary = c;
}
void worker::print()
{
	cout << "\n ID: " << id << "\n Name: " << name << "\n Total salary:: " << salary;
}
partTime::partTime() : worker()
{
	days = 0;
}
partTime::partTime(string a, string b, double c, int d) : worker(a, b, c)
{
	days = d;
}
int partTime::getDays()
{
	return days;
}
void partTime::setDays(int d)
{
	days = d;
}
double partTime::process()
{
	return salary * days;
}
void partTime::print()
{
	worker::print();
	cout << "\n Number of days worked: " << days << "\n Total salary:: " << process() << endl;
}
fullTime::fullTime() : worker()
{
	bonus = 0.0;
}
fullTime::fullTime(string a, string b, double c, double e) : worker(a, b, c)
{
	bonus = e;
}
double fullTime::getBonus()
{
	return bonus;
}
void fullTime::setBonus(double e)
{
	bonus = e;
}
double fullTime::process()
{
	deduct = (salary + bonus) * 0.09;
	return (salary + bonus) - deduct;
}
void fullTime::print()
{
	worker::print();
	cout << "\n EPF & SOCSO deduction: " << deduct << "\n Total salary: " << process() << endl;
}