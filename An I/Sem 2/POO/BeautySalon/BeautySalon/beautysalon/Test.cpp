#include "Visit.h"



int main() {
	int option=1;
	while (option) {
		string name = "Mada";
		Customer c = Customer(name);
		c.setMember(true);
		c.setMemberType("Premium");
		Visit v = Visit(name);
		v.setProductExpense(10);
		v.setServiceExpense(20);
		cout << "Product price: " << v.getProductExpense() << "\nService price: " << v.getServiceExpense() << "\nTotal expense: " << v.getTotalExpense() << "\n";
	}
}
