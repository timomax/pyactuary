#pragma once
#include <map>
class LifeTable
{
private:
	std::map<int, double> _ageToQx;
	std::map<int, double> _Ix = std::map<int, double>();
	int _minage;
	int _maxage;


public:

	LifeTable(std::map<int, double> ageToQx);
	double qx(int x);
	double ix(int x);
	double tpx(int x, int t);
	double eol(int age);


	


};

