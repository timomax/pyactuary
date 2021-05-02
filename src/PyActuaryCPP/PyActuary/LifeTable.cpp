#include "LifeTable.h"



LifeTable::LifeTable(std::map<int, double> ageToQx)
{
	_ageToQx = ageToQx;
	_minage = _ageToQx.begin()->first;
	_maxage = _ageToQx.rbegin()->first;

	// other values will be back or forward casted.
	_Ix[_minage] = 1000;
	for (int age = _minage; age <= _maxage; age++)
	{
		_Ix[age + 1] = _Ix[age] * (1.0 - qx(age));
	}

}

double LifeTable::qx(int age)
{
	auto entry = _ageToQx.find(age);
	if (entry != _ageToQx.end())
		return entry->second;
	if (age < _ageToQx.begin()->first)
		return  _ageToQx.begin()->second;
	if (age > _ageToQx.rbegin()->first)
		return  _ageToQx.rbegin()->second;

	return  (--_ageToQx.upper_bound(age))->second;

}

double LifeTable::ix(int age)

{
	auto entry = _Ix.find(age);
	if (entry != _Ix.end())
		return entry->second;

	int minage = _Ix.begin()->first;
	int maxage = _Ix.rbegin()->first;
	if (age < minage)
	{
		for (int i = minage-1; i>= age; i--)
			_Ix[i] = _Ix[i+1]/(1-qx(i));
	}
	else 
	{
		for (int i = maxage + 1; i <= age; i++)
			_Ix[i] = _Ix[i - 1] * (1 - qx(i-1));
	}
	return _Ix[age];

}

double LifeTable::tpx(int x, int t)
{
	return ix(x + t) / ix(x);
}

double LifeTable::eol(int age)
{
	double eol {0.0};
	for (int i = age+1; i <= _maxage; i++)
	{
		eol = +tpx(age, i);
	}
	return eol;
}