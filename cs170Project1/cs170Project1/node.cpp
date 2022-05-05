#include <iostream>
#include <vector>
#include <string>
#include "node.h"

using namespace std;

Node::Node(vector<vector<int>> puzzle, int gn, int hn) {
	this->cost = hn;
	this->depth = gn;
	this->grid = puzzle;
}

Node::Node() {}

void Node::print() {
	for (int i = 0; i < this->grid.size(); i++) {
		for (int j = 0; j < this->grid[i].size(); j++) {
			cout << this->grid[i][j] << " ";
		}
		cout << endl;
	}
}