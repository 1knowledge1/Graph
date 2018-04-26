#include <iostream>

#include "tree_t.hpp"

int main() {
	tree_t<int> tree1, tree2;
	tree1.insert(3);
	tree1.insert(2);
	tree1.insert(1);
	tree1.insert(0);

	tree2.insert(3);
	tree2.insert(2);
	tree2.insert(1);
	tree2.insert(0);
	tree2.insert(10);
	tree1.print(std::cout);
	std::cout << "\n";
	tree2.print(std::cout);
	std::cout << "\n";
	if (tree1 == tree2) std::cout << "trees =\n";
	else std::cout << "trees !=\n";
	return 0;
}
