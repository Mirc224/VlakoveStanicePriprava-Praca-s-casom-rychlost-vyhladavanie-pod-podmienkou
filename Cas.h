#pragma once
#include <iostream>
#include <string>
class Cas
{
public:
	Cas(int hodiny, int minuty): m_hodiny(hodiny), m_minuty(minuty) {}
	void pridajMinuty(int minuty);
	int getHodiny() { return m_hodiny; }
	int getMinuty() { return m_minuty; }
	int getCasVSekundach() { return m_hodiny * 3600 + m_minuty * 60; }
	std::string toString();
	virtual ~Cas();
private:
	int m_hodiny;
	int m_minuty;
};

