#include <iostream>
#include <vector>
#include <string>
#include "node.cpp"
#include <queue>

using namespace std;
bool checkVisited(vector<Node> visited, Node child);
queue<Node> moves(Node current, int type);
pair<int, int> getblank(vector<vector<int>> grid);
int calc(vector<vector<int>> puzzle, int type, vector<vector<int>> goal);
int euclidean(vector<vector<int>> grid, vector<vector<int>> goal);
int misplaced(vector<vector<int>> grid, vector<vector<int>> goal);

void search(vector<vector<int>> puzzle, int type, vector<vector<int>> goal) {
	priority_queue<Node> frontier;
	Node initial = Node(puzzle, 0, 0);
	vector<Node> visited;
	

	if(type >1)
		initial.cost = calc(puzzle, type,goal);

	frontier.push(initial);

	while (true) {
		if (frontier.empty()) {
			cout << "There is no solution" << endl;
			break;
		}
		Node current = frontier.top();
		frontier.pop();
		visited.push_back(current);
		cout << "The best state to expand with g(n) = " << current.depth << " and h(n) = " << current.cost << " is...\n";
		current.print();

		if (puzzle == goal) {
			cout << "Goal state reached! :)" << endl;
		}

		queue<Node> children = moves(current, type);

		while (!children.empty()) {
			Node child = children.front();
			children.pop();
			if (!checkVisited(visited, child)) {
				frontier.push(child);
			}
		}
	}

}

bool checkVisited(vector<Node> visited, Node child) {
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i].grid == child.grid) {
			return true; // have been visited
		}
	}
	return false; //not visited yet
}

queue<Node> moves(Node current, int type, vector<vector<int>> goal) {
	queue<Node> children;

	pair<int, int> blank = getblank(current.grid);
	int i = blank.first;
	int j = blank.second;
	//up
	if (blank.first > 0) {
		Node child = Node(current.grid, current.depth, current.cost);
		swap(child.grid[i][j], child.grid[i - 1][j]);
		child.depth += 1;
		child.cost = calc(child.grid, type, goal);
		children.push(child);
	}
	// down
	if (blank.first < current.grid.size() ) {
		Node child = Node(current.grid, current.depth, current.cost);
		swap(child.grid[i][j], child.grid[i + 1][j]);
		child.depth += 1;
		child.cost = calc(child.grid, type, goal);
		children.push(child);
	}
	
	//left
	if (blank.second >  0 ) {
		Node child = Node(current.grid, current.depth, current.cost);
		swap(child.grid[i][j], child.grid[i][j-1]);
		child.depth += 1;
		child.cost = calc(child.grid, type, goal);
		children.push(child);
	}
	//right
	if (blank.second < current.grid.size()) {
		Node child = Node(current.grid, current.depth, current.cost);
		swap(child.grid[i][j], child.grid[i][j + 1]);
		child.depth += 1;
		child.cost = calc(child.grid, type, goal);
		children.push(child);
	}

	return children;
}

pair<int, int> getblank(vector<vector<int>> grid) {
	pair<int, int> c;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j]) {
				c = { i,j };
				return c;
			}
		}
	}
}

int calc(vector<vector<int>> puzzle, int type, vector<vector<int>> goal) {
	if (type == 2) {
		return misplaced(puzzle, goal);
	}
	else {
		return euclidean(puzzle, goal);
	}
}

int euclidean(vector<vector<int>> grid, vector<vector<int>> goal) {
	int cost;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] != goal[i][j]) {
				int n = 0;
				int m = 0;

				for (int y = 0; y < grid.size(); y++) {
					for (int z = 0; z < grid[y].size(); z++) {
						if (goal[y][z] == grid[i][j]) {
							n = y;
							m = z;
						}
					}
				}
				n = pow(n - i, 2);
				m = pow(m - j, 2);
				cost += sqrt(n + m);
			}
		}
	}
	return cost;
}
int misplaced(vector<vector<int>> grid, vector<vector<int>> goal) {
	int cost;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] != goal[i][j])
				cost++;
		}
	}
	return cost;
}