#include<string>
using std::string;
#include"dllist.h"

int main() {

	DLList<std::string> dllist;

	dllist.insert_front("Feynman");
	dllist.insert_rear("Turing");
	dllist.print();
	dllist.insert_rear("Einstein");
	dllist.insert_rear("Bohr");
	dllist.print();
	dllist.insert_front("Sanchez");
	dllist.print();
	dllist.remove_value("Einstein");
	dllist.print();
	dllist.remove(2);
	dllist.print();


	return 0;
}

