#pragma once
#include "DiscountRate.h"
#include <iostream>
#include <string>


using namespace std;

class Customer: public DiscountRate {
private:
	string name;
	bool member=false;
	string memberType;
public:
	Customer(string name);
	string getName();
	bool isMember();
	void setMember(bool member);
	string getMemberType();
	void setMemberType(string memberType);
	string toString();
};