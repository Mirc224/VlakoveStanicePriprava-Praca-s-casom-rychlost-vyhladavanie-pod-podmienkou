#include "Trat.h"



Trat::Trat()
{
}

void Trat::nacitaj(std::istream & is)
{
	int typ;
	is >> typ >> m_nazov >> m_kilometirckaPoloha;
	m_typ = (typTrate)typ;
}

void Trat::vypis(std::ostream & os)
{
	os << m_typ << " " << m_nazov << " " << m_kilometirckaPoloha << std::endl;
}


std::string Trat::usporiadanyToStr(std::string parameter)
{
	std::stringstream stream;
	stream << parameter;
	stream << ":";
	switch (m_typ)
	{
		case zastavka:
			stream << "\t  ";
			break;
		case stanica:
			stream << " ";
			break;
	}
	stream << m_nazov + "\n";
	return stream.str();
}

Trat::~Trat()
{
}
