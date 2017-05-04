#include "Customer.h"

Customer::Customer(string name) {
	this->name = name;
}

string Customer::getName() {
	return this->name;
}

bool Customer::isMember() {
	return this->member;
}

void Customer::setMember(bool member) {
	this->member = member;
}

string Customer::getMemberType() {
	return this->memberType;
}

void Customer::setMemberType(string memberType) {
	this->memberType = memberType;
}

string Customer::toString() {
	return string();
}
