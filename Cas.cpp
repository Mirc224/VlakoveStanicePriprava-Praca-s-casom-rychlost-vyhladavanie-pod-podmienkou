#include "Cas.h"


void Cas::pridajMinuty(int minuty)
{
	int temp = 0;
	m_minuty += minuty;
	temp = m_minuty / 60;
	m_minuty = m_minuty % 60;
	m_hodiny += temp;
}

std::string Cas::toString()
{
	std::string casVoFormate;
	if (m_hodiny < 10)
		std::string casVoFormate = "0";
	casVoFormate += std::to_string(m_hodiny) + ":";
	if (m_minuty < 10)
		casVoFormate += "0";
	casVoFormate += std::to_string(m_minuty) + "";
	return casVoFormate;
}

Cas::~Cas()
{
}
