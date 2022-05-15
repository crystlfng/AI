#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>  
#include <list>
using namespace std;

class Node{
    public:
        vector<vector<int> > curr;
        int hn;
        int gn;
        int cost;
        Node(vector<vector<int> > curr, int hn, int gn);
        Node(){};
        int getGn(){return gn;}
        int getHn(){return hn;}
};

Node::Node(vector<vector<int> > c, int h, int g){
    curr = c;
    hn = h;
    gn = g;
}

pair<int,int> findBlank(vector<vector<int> > puzzle);
void printp(vector<vector<int> > puzzle);
bool isValid(int i, int j);
int calcH( vector<vector<int> > puzzle, int searchType);


vector<Node> getChildren(Node puz, int searchType){

    vector<Node> moves;
    Node p = puz;
    vector<vector<int> > temp = puz.curr;

    pair<int,int> position = findBlank(puz.curr);

    int i = position.first;
    int j = position.second;

    //cout << "the blank tile is at (" << position.first << ", " << position.second << ")" << endl;

    //up
    if(i >0){
        vector<vector<int> > temp = puz.curr;
        swap(temp[i][j], temp[i-1][j]);
        Node child = Node(temp, calcH(temp, searchType)+ p.getGn() +1, p.getGn()+1);
        moves.push_back(child);
    }
    //down
    if(i < 3){
        vector<vector<int> > temp = puz.curr;
        swap(temp[i][j], temp[i+1][j]);
        Node child = Node(temp, calcH(temp, searchType)+ p.getGn() +1, p.getGn()+1);
        moves.push_back(child);
    }

    //left
    if(j > 0){
        vector<vector<int> > temp = puz.curr;
        swap(temp[i][j], temp[i][j-1]);
        Node child = Node(temp, calcH(temp, searchType)+ p.getGn() +1, p.getGn()+1);
        moves.push_back(child);
    }
    //right
    if(j < 3){
        vector<vector<int> > temp = puz.curr;
        swap(temp[i][j], temp[i][j-1]);
        Node child = Node(temp, calcH(temp, searchType)+ p.getGn() +1, p.getGn()+1);
        moves.push_back(child);
    }
    return moves;
}

void search(vector<vector<int>> grid, int searchType, vector<vector<int> > goal){

    Node initial = Node();
    initial.curr = grid;
    initial.hn = calcH(grid, searchType);
    initial.gn = 0; //this is the first one depth is 0
    initial.cost = initial.gn + initial.hn;

    printp(initial.curr);

    int movesCount = 0;

    vector<Node> path; 
    path.push_back(initial);

    vector<Node> heap = path; // kind of like the queue
    make_heap(heap.begin(), heap.end());

    vector<Node> seen;  //keeps track of duplicates or visited nodes
    seen.push_back(initial);
    Node current;

    cout << "test" << endl;
    while(path.empty()){
        current = heap.front(); 

        cout << "The best state to expand with g(n) = "<< current.gn << " and h(n) = " << current.hn <<endl;

        printp(current.curr);

        if(current.curr == goal){ // get out of this loop if the puzzle is solved
            break;
        }

        heap.erase (heap.begin(), heap.begin()+1);

        // generate the children of the current node
        vector<Node> children = getChildren(current,searchType);

        // check to see if the children have been visited before
        for(int i =0;i <children.size(); i++){
            //if the current child has been seen before do nothing
            if(std::find(seen.begin(), seen.end(), children[i]) != seen.end()){}
            else{ // else put it in seen
                seen.push_back(children[i]);
                heap.push_back(children[i]); // in heap to be expanded on 
                make_heap(heap.begin(), heap.end());
            }
        }

    }

}


pair<int,int> findBlank(vector<vector<int> > puzzle){
    for(int i = 0; i< 3; i ++){
        for(int j = 0; j < 3; j++){
            if(puzzle[i][j] == 0){
                return pair<int,int>(i,j);
            }
        }
    }
}

int misplaced(vector<vector<int> > puzzle){
    vector<int> temp = {1,2,3};
    vector<int> temp1 = {4,5,6};
    vector<int> temp2 = {7,8, 0};
    vector<vector<int> > goal;
    goal.push_back(temp);
    goal.push_back(temp1);
    goal.push_back(temp2);

    int count =0;
    for (int i =0; i < puzzle.size();i++){
        for(int j = 0; j < puzzle[j].size(); j++){
           if(puzzle[j][i] != goal[i][j] && puzzle[j][i] != 0)
           count++;
        }
    }
    return count;
}

int euclidean(vector<vector<int> > puzzle){
    vector<int> temp = {1,2,3};
    vector<int> temp1 = {4,5,6};
    vector<int> temp2 = {7,8, 0};
    vector<vector<int> > goal;
    goal.push_back(temp);
    goal.push_back(temp1);
    goal.push_back(temp2);
    
    int total = 0;
    for (int i =0; i < puzzle.size();i++){
        for(int j = 0; j < puzzle[j].size(); j++){
            int dist= 0;
            if(puzzle[j][i] != goal[i][j] && puzzle[j][i] != 0){
                //find the euclidean distance from puzzle[i][j] to goal(puzzle[i][j])
                 
            }
            total += dist;
        }
    }
    return total;
}

int calcH( vector<vector<int> > puzzle, int searchType){
    if(searchType == 2){
        return misplaced(puzzle);
    }
    else{
        return euclidean(puzzle);
    }
}

void printp(vector<vector<int> > puzzle){
    for (int j =0; j < puzzle.size();j++){
        for(int i = 0; i < puzzle[j].size(); i++){
            cout << puzzle[j][i] << " ";
        }
        cout << endl;;
    }
}