#pragma once
#pragma warning(disable : 4996)
#include <string>
#include <ctime>

class Date {
private:
	time_t t=time(NULL);
public:
	friend std::ostream &operator<<(std::ostream &flux, Date d);
};