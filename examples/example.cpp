#include <iostream>
#include "Graph.hpp"

int main() {
	Graph g;
	if(g.read(std::cin))
	{
		g.DFS(2, std::cout);
	}
	else
	{
		std::cout << "error\n";
	}
	return 0;
}
