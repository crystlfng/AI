#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Node {
public:
	int depth;
	int cost;
	vector<vector<int>> grid;

	void print();

	Node();
	Node(vector<vector<int>>, int, int);
};
