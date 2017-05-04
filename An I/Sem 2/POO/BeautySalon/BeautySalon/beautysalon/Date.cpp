#include "Date.h"

std::ostream & operator<<(std::ostream & flux, Date d) {
	char* ct=ctime(&d.t);
	flux<<ct<<"\n";
	return flux;
}
