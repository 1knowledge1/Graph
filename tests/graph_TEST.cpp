#include <catch.hpp>
#include <sstream>
#include "Graph.hpp"
using namespace std;

TEST_CASE(" read and DFS "){
    Graph g;
    string input {
	"4\n"
        "0 1 1 0\n"
        "0 0 1 0\n"
        "1 0 0 1\n"
        "0 0 0 1\n"
    };
    istringstream stream (input);
    g.read(stream);
    string result = "2 0 1 3 ";
    ostringstream output;
    g.DFS(2, output);
    REQUIRE(result == output.str());
}

TEST_CASE(" invalid input "){
    Graph g;
    string input {
	"4\n"
        "0 1 a 1\n"
        "1 0 1 0\n"
        "0 1 0 0\n"
        "1 0 0 0\n"
    };
    istringstream stream (input);
    REQUIRE(g.read(stream) == 0);
}
