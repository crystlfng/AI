#include <iostream>
#include <vector>
#include <string>
#include "search.cpp"


using namespace std;

int main() {
	vector<vector<int>> puzzle;
	vector<vector<int>> goal;
	int type = 1;

	vector<int> temp1 = { 1,2,3 };
	vector<int> temp2 = { 4,5,0 };
	vector<int> temp3 = { 7,8,6 };

	puzzle.push_back(temp1);
	puzzle.push_back(temp2);
	puzzle.push_back(temp3);

	temp1 = { 1,2,3 };
	temp2 = { 4,5,6 };
	temp3 = { 7,8,0 };

	goal.push_back(temp1);
	goal.push_back(temp2);
	goal.push_back(temp3);

	for (int i = 0; i < puzzle.size(); i++) {
		for (int j = 0; j < puzzle[i].size(); j++) {
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}

	cin >> type;

	search(puzzle, type,goal);

	return 0;
}