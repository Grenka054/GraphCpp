#include <iostream>
#include "Graph.h"

int main()
{
	using namespace std;
	Graph graph("input2.txt");
	graph.topologicalSort();
	graph.outMatrix();
	graph.components();
}