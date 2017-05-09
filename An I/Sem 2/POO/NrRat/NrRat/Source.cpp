#include "NrRat.h"
#include <map>

void citire(NrRat &a, NrRat &b) {
	cout << "x= ";
	cin >> a;
	cout << "y= ";
	cin >> b;
}

int run(int option)
{
	if (option < 0 || option>7) {
		cout << "optiune invalida, alegeti alta optiune:";
		return -1;
	}
	else {
		NrRat r, x, y;
		if (option == 1) {
			citire(x, y);
			r = x + y;
			cout << r;
		}
		if (option == 2) {
			citire(x, y);
			r = x - y;
			cout << r;
		}
		if (option == 3) {
			citire(x, y);
			r = x * y;
			cout << r;
		}
		if (option == 4) {
			citire(x, y);
			r = x / y;
			cout << r;
		}
		if (option >= 5) {
			map<NrRat, int> numbers;
			pair< map<NrRat, int>::iterator, bool> ret;
			map< NrRat, int>::iterator it;
			NrRat n;
			int k;
			cout << "nr elemente: ";
			cin >> k;
			for (int i = 0; i < k; i++) {
				cin >> n;
				ret = numbers.insert(pair<NrRat, int>(n, 1));
				if (!ret.second)
					ret.first->second++;
			}


			if (option == 5)
				for (it = numbers.begin(); it != numbers.end(); ++it)
					cout << (*it).first;
			if (option == 6) {
				it = numbers.begin();
				cout << it->first;
				it++;
				cout << it->first;
			}
			if (option == 7)
				for (it = numbers.begin(); it != numbers.end(); ++it)
					cout << (*it).first << " " << (*it).second << "\n";
		}
	}
	return 1;
}
int main() {

	int option = 0;
	do {
		cout << "0-exit \n1-add \n2-substract \n3-multiply \n4-devide \n5-sortByValue \n6-primele 2 numere cele mai mici: \n7-numar de aparitii \n";
		start:
		cin >> option;
		if (run(option) == -1)
			goto start;
	} while (option);

}
