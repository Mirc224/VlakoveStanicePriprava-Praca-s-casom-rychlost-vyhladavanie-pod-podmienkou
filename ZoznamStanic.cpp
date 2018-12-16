#include "ZoznamStanic.h"



ZoznamStanic::ZoznamStanic()
{
}

void ZoznamStanic::nacitajStanice(std::istream& is)
{
	while (!is.eof())
	{
		Trat* temp = new Trat();
		is >> temp;
		m_zoznamTrati.push_back(temp);
	}
	std::vector<Trat*> usporiadanyTemp;
	std::set<double> tempZoradeny;
	for (auto &trat : m_zoznamTrati)
	{
		tempZoradeny.insert(trat->getKilometre());
	}
	for (auto &kilometre : tempZoradeny)
	{
		for (auto &trat : m_zoznamTrati)
		{
			if (trat->getKilometre() == kilometre)
			{
				usporiadanyTemp.push_back(trat);
			}
		}
	}
	m_zoznamTrati.clear();
	for (auto &p : usporiadanyTemp)
	{
		m_zoznamTrati.push_back(p);
	}
}

void ZoznamStanic::usporiadanyVypis()
{
	for (auto &trat : m_zoznamTrati)
	{
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << trat->getKilometre();
		std::cout << trat->usporiadanyToStr(stream.str());
	}
}

void ZoznamStanic::cestaOsobakom()
{
	Cas tempCas = Cas(11, 18);
	double rychlost = 80.0/60.0; // km/min
	for (auto it = m_zoznamTrati.begin(); it != m_zoznamTrati.end(); ++it)
	{
		int minuty = 0;
		Trat* temp = *it;
		if (temp->getTyp() == stanica)
			minuty += 3;
		else
			minuty += 2;
		if (it != m_zoznamTrati.end()-1)
		{
			tempCas.pridajMinuty(minuty);
			std::cout << temp->usporiadanyToStr(tempCas.toString());
			auto dalsiaTrat = *(it + 1);
			minuty = (dalsiaTrat->getKilometre() - temp->getKilometre()) / rychlost;
			tempCas.pridajMinuty(minuty);
		}
		else
		{
			std::cout << temp->usporiadanyToStr(tempCas.toString());
		}
	}
}

void ZoznamStanic::cestaRychlikom()
{
	Cas tempCas = Cas(11, 33);
	double rychlost = 100.0 / 60.0;
	auto it = m_zoznamTrati.begin();
	while(it != m_zoznamTrati.end())
	{
		Trat* stanica1 = *it;
		if(it != m_zoznamTrati.end() - 1)
		tempCas.pridajMinuty(3);
		Trat* stanica2 = nullptr;
		std::cout << stanica1->usporiadanyToStr(tempCas.toString());
		bool test = false;
		while (!test)
		{
			++it;
			if (it != m_zoznamTrati.end())
			{
				if ((*it)->getTyp() == stanica)
				{
					stanica2 = *it;
					test = true;
				}
			}
			else
				test = true;
		}
		if (stanica2 != nullptr)
		{
			 tempCas.pridajMinuty((stanica2->getKilometre() - stanica1->getKilometre()) / rychlost);
		}
	}
}
void ZoznamStanic::prestup()
{
	std::map<int, Trat*> staniceOsobak;
	std::map<int, Trat*> staniceRychlik;
	std::set<int> najmensiCas;
	{
		Cas tempCas = Cas(11, 18);
		double rychlost = 80.0 / 60.0; // km/min
		for (auto it = m_zoznamTrati.begin(); it != m_zoznamTrati.end(); ++it)
		{
			int minuty = 0;
			Trat* temp = *it;
			if (temp->getTyp() == stanica)
			{
				staniceOsobak.insert(std::make_pair(tempCas.getCasVSekundach(), temp));
				najmensiCas.insert(tempCas.getCasVSekundach());
				minuty += 3;
			}
			else
				minuty += 2;
			if (it != m_zoznamTrati.end() - 1)
			{
				tempCas.pridajMinuty(minuty);
				auto dalsiaTrat = *(it + 1);
				minuty = (dalsiaTrat->getKilometre() - temp->getKilometre()) / rychlost;
				tempCas.pridajMinuty(minuty);
			}
		}
	}
	Cas tempCas = Cas(11, 33);
	double rychlost = 100.0 / 60.0;
	auto it = m_zoznamTrati.begin();
	while (it != m_zoznamTrati.end())
	{
		Trat* stanica1 = *it;
		staniceRychlik.insert(std::make_pair(tempCas.getCasVSekundach(), stanica1));
		if (it != m_zoznamTrati.end() - 1)
			tempCas.pridajMinuty(3);
		Trat* stanica2 = nullptr;
		bool test = false;
		while (!test)
		{
			++it;
			if (it != m_zoznamTrati.end())
			{
				if ((*it)->getTyp() == stanica)
				{
					stanica2 = *it;
					test = true;
				}
			}
			else
				test = true;
		}
		if (stanica2 != nullptr)
		{
			tempCas.pridajMinuty((stanica2->getKilometre() - stanica1->getKilometre()) / rychlost);
		}
	}
	for (auto &stanicaPrichodu : staniceOsobak)
	{
		if (stanicaPrichodu.second->getNazov().compare("Zilina") == 0)
		{
			std::cout << "Prestup nie je mozny!\n";
			return;
		}
		for (auto &stanica2 : staniceRychlik)
		{
			if (stanicaPrichodu.second == stanica2.second)
			{
				if ((stanicaPrichodu.first - stanica2.first ) > 180)
				{
					std::cout << "Najskorsi prestup je mozny na stanici " << stanicaPrichodu.second->getNazov() << "\n";
					return;
				}
			}
		}
	}
}


ZoznamStanic::~ZoznamStanic()
{
	for (auto &trat : m_zoznamTrati)
	{
		delete trat;
	}
}
