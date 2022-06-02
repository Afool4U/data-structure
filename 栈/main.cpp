#include<string>
using std::string;
#include"stack.h"

int main() {

	Stack<std::string> stack;

	stack.push("Feynman");
	stack.push("Turing");
	stack.push("Einstein");
	stack.push("Bohr");
	stack.push("Sanchez");

	stack.print();

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.print();
	
	return 0;
}

