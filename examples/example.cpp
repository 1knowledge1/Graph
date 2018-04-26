#include <iostream>
#include "tree_t.hpp"

int main() {
	tree_t<int> tree;
	char op;
	while (std::cin >> op && op != 'q') {
		int num;
		switch (op) {
		case '=':
			tree.print(std::cout);
			break;
		case '+':
			if (std::cin >> num) {
				tree.insert(num);
				tree.print(std::cout);
			}
			else {
				std::cout << "An error has occured while reading input data\n";
				exit(0);
			}
			break;
		case '?':
			if (std::cin >> num) {
				if (tree.find(num)) {
					std::cout << "true\n";
				}
				else {
					std::cout << "false\n";
				}
			}
			else {
				std::cout << "An error has occured while reading input data\n";
				exit(0);
			}
			break;
		}
	}
	return 0;
}
