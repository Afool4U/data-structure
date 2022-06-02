#include<string>
using std::string;
#include"queue.h"

int main() {

	Queue<std::string> queue;

	queue.enqueue("Feynman");
	queue.enqueue("Turing");
	queue.enqueue("Einstein");
	queue.enqueue("Bohr");
	queue.enqueue("Sanchez");

	queue.print();

	queue.dequeue();
	queue.dequeue();

	queue.print();

	queue.dequeue();
	queue.dequeue();

	queue.print();

	return 0;
}

