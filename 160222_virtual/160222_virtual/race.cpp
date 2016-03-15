#include "race.h"


race::race(char* raceInfo, int hp) : _Hp(hp)
{
	_raceInfo = new char[strlen(raceInfo) + 1];
	strcpy_s(_raceInfo, strlen(raceInfo) + 1, raceInfo);
}


race::~race()
{
	delete[]_raceInfo;
}
