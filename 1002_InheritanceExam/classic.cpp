#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "classic.h"

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strcpy(performers, s1);
	
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);

	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[1];
	performers[0] = '\0';

	label = new char[1];
	label[0] = '\0';

	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	std::cout << "\nperformers: " << performers << std::endl;
	std::cout << "label: " << label << std::endl;
	std::cout << "selections: " << selections << std::endl;
	std::cout << "playtime: " << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);

	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
	: Cd(s2, s3, n, x)
{
	repSong = new char[strlen(s1) + 1];
	strcpy(repSong, s1);
}

Classic::Classic(const Classic& d)
	: Cd(d)
{
	repSong = new char[strlen(d.repSong) + 1];
	strcpy(repSong, d.repSong);
}

Classic::Classic()
	:Cd("none", "none", 0, 0.0)
{
	repSong = new char[1];
	repSong[0] = '\0';
}

Classic::~Classic()
{
	delete[] repSong;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "reprataive Song: " << repSong << "\n\n";
}

Classic& Classic::operator=(const Classic& d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[] repSong;
	repSong = new char[strlen(d.repSong) + 1];
	strcpy(repSong, d.repSong);
	return *this;
}