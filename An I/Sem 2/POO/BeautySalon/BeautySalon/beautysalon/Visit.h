#pragma once
#include "Customer.h"
#include "Date.h"

class Visit {
private:
	Customer customer=Customer(string());
	Date date;
	double serviceExpense=0.0;
	double productExpense=0.0;
public:
	Visit(string name);
	string getName();
	double getServiceExpense();
	void setServiceExpense(double servExpense);
	double getProductExpense();
	void setProductExpense(double prodExpense);
	double getTotalExpense();
	string toString();
};