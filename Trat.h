#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
enum typTrate {zastavka, stanica};
class Trat
{
public:
	Trat();
	void nacitaj(std::istream& is);
	void vypis(std::ostream& os);
	friend std::istream& operator >>(std::istream& is, Trat* b)
	{
		b->nacitaj(is); return is;
	}
	friend std::ostream& operator <<(std::ostream& os, Trat* b) //takyto zapis aby sa to dalo retazit
	{
		b->vypis(os); return os;
	}
	std::string usporiadanyToStr(std::string parameter);
	double getKilometre() { return m_kilometirckaPoloha; }
	typTrate getTyp() { return m_typ; }
	std::string getNazov() { return m_nazov; }
	~Trat();
private:
	std::string m_nazov;
	typTrate m_typ;
	double m_kilometirckaPoloha;
};

