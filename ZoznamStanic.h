#pragma once
#include "Trat.h"
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include "Cas.h"

class ZoznamStanic
{
public:
	ZoznamStanic();
	void nacitajStanice(std::istream& is);
	void usporiadanyVypis();
	void cestaOsobakom();
	void cestaRychlikom();
	void prestup();
	~ZoznamStanic();
private:
	std::vector<Trat*> m_zoznamTrati;
};

