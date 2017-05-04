#include "Visit.h"

Visit::Visit(string name) {
	this->customer = Customer(name);
}

string Visit::getName() {
	return this->customer.getName();
}

double Visit::getServiceExpense() {
	return this->serviceExpense;
}

void Visit::setServiceExpense(double servExpense) {
	this->serviceExpense = servExpense - servExpense * this->customer.getServiceDiscountRate(this->customer.getMemberType());
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
