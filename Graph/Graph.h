#pragma once
#include <fstream>
#include <iostream>
class Graph
{
public:
	int** matrix = new int*;
	int numGraphNode;
	void outMatrix();
	void components();
	void topologicalSort();
	Graph(std::string str);
};

