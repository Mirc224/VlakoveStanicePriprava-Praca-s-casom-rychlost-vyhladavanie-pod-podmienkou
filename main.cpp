#include <iostream>
#include <fstream>
#include "Trat.h"
#include "ZoznamStanic.h"

int main(int argc, char *argv[])
{
	ZoznamStanic stanice = ZoznamStanic();
	std::ifstream inputFile("trat.txt");
	stanice.nacitajStanice(inputFile);
	stanice.usporiadanyVypis();
	stanice.cestaOsobakom();
	stanice.cestaRychlikom();
	stanice.prestup();
	return 0;
}