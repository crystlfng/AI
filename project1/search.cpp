#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include "node.h"
#include "node.cpp"
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
    if(j > 0){
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

    queue<Node> path;

    path.push(initial);

    vector<Node> seen;

    while(!path.empty()){
        vector<Node> children = getChildren(initial,searchType);
        for(int i =0;i <children.size(); i++){
            if(find(seen.begin(), seen.end(), children[i]) != seen.end()){}
            else{
                seen.push_back(children[i]);
            }

            if(children[i].cost < temp)
            
            

        }

    }

    // someDatastruck = append(initial);
    // while someDataStruc is not empty
    //   currNodeChildren = getChildren(grid);
    //   for child in currNodeChildren:
    //     if child has been seen: continue
    //     seen.append(child)
    //     if this child.cost < temp:
    //       temp = child
    //     temp add to someDataStruc
}



bool isValid(int i, int j){
    if( i < 0 || j < 0)
        return false;
    else
        return false;
    return true;
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