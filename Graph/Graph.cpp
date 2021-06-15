#include <iostream>
#include "Graph.h"
#include <vector>
Graph::Graph(std::string str) {
	using namespace std;
	fstream file(str);
	file >> numGraphNode;
	//Создание и зануление матрицы смежности
	int** matrix = new int* [numGraphNode];
	for (int i{ 0 }; i < numGraphNode; ++i) {
		matrix[i] = new int[numGraphNode];
	}
	for (int i{ 0 }; i < numGraphNode; ++i) {
		for (int j{ 0 }; j < numGraphNode; ++j) {
			matrix[i][j] = 0;
		}
	}
	//заполнение матрицы смежности
	int in, out;
	while (file >> in >> out) {
		matrix[in - 1][out - 1] = 1;
	}
	this->matrix = matrix;
}
void Graph::outMatrix() {
	using namespace std;
	for (int i{ 0 }; i < numGraphNode; ++i) {
		for (int j{ 0 }; j < numGraphNode; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Graph::topologicalSort() {
	int** matrix = new int* [numGraphNode];
	for (int i{ 0 }; i < numGraphNode; ++i) {
		matrix[i] = new int[numGraphNode];
	}
	for (int i{ 0 }; i < numGraphNode; ++i) {
		for (int j{ 0 }; j < numGraphNode; ++j) {
			matrix[i][j] = this->matrix[i][j];
		}
	}
	using namespace std;
	bool cycle = false;
	int check = numGraphNode * numGraphNode;
	int count{ 0 }, index{ 0 };
	vector<int> indexes;
	while (check > 0) {
		for (int j{ 0 }; j < numGraphNode; ++j) {
			count = 0;
			for (int i{ 0 }; i < numGraphNode; ++i) {
				if (matrix[i][j] == 0) count++;
				else break;
			}
			if (count == numGraphNode) {
				index = j;
				if (find(indexes.begin(), indexes.end(), j) == indexes.end())
					indexes.push_back(j);
			}
		}
		for (int i = 0; i < indexes.size(); ++i) {
			for (int j = 0; j < numGraphNode; ++j) {
				int k = indexes[i];
				matrix[k][j] = 0;
			}
		}
		int check2 = 0;
		for (int i{ 0 }; i < numGraphNode; ++i) {
			for (int j{ 0 }; j < numGraphNode; ++j) {
				if (matrix[i][j] == 1)
					++check2;
			}
		}
		if (check2 == check) {
			cout << endl << "Cyclic graph!" << endl;
			cycle = true;
			break;
		}
		if (check2 < check)
			check = check2;
	}

	if (!cycle) {
		for (int i{ 0 }; i < numGraphNode; ++i)
			if (find(indexes.begin(), indexes.end(), i) == indexes.end())
				indexes.push_back(i);
		cout << endl;
		for (auto i : indexes)
			cout << i + 1 << " ";
		cout << endl;
	}
}
void Graph::components() {
	int* array = new int[numGraphNode];
	for (int i{ 0 }; i < numGraphNode; ++i) {
		array[i] = i + 1;
	}
	for (int i{ 0 }; i < numGraphNode; ++i) {
		for (int j{ 0 }; j < numGraphNode; ++j) {
			if (matrix[i][j] != 0)
				array[j] = array[i];
		}
	}
	for (int i{ 0 }; i < numGraphNode; ++i) {
		std::cout << array[i] << " ";
	}
}