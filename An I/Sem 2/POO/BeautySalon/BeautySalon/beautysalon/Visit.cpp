#include "Visit.h"

Visit::Visit(string name) {
	this->customer = Customer(name);
}

string Visit::getName() {
	return this->customer.getName();
}

double Visit::getServiceExpense() {
	return this->serviceExpense - this->serviceExpense * this->customer.getServiceDiscountRate(this->customer.getMemberType());;
}

void Visit::setServiceExpense(double servExpense) {
	this->serviceExpense = servExpense;
}

double Visit::getProductExpense() {
	return this->productExpense;
}

void Visit::setProductExpense(double prodExpense) {
	this->productExpense = prodExpense - prodExpense * this->customer.getProductDiscountRate(this->customer.getMemberType());
};


double Visit::getTotalExpense() {
	return this->serviceExpense + this->productExpense;
}

string Visit::toString() {
	return string();
}
