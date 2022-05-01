#include "node.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

Node::Node(){
    parent = NULL;
}

Node::Node(vector<vector<int> > v){
    curr = v;
}

Node* Node::up(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    this->gn = this->gn + 1;

    swap(temp->curr[coor.first][coor.second],temp->curr[coor.first][coor.second-1]);
    this->parent = this;
    this->curr = temp->curr;
    
    return temp;
}

Node* Node::down(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    this->gn = this->gn + 1;

    swap(temp->curr[coor.first][coor.second],temp->curr[coor.first][coor.second+1]);
    this->parent = this;
    this->curr = temp->curr;
    
    return temp;
}
Node* Node::right(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    this->gn = this->gn + 1;

    swap(temp->curr[coor.first][coor.second],temp->curr[coor.first+1][coor.second]);
    this->parent = this;
    this->curr = temp->curr;
    
    return temp;
}
Node* Node::left(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    this->gn = this->gn + 1;

    swap(temp->curr[coor.first][coor.second],temp->curr[coor.first-1][coor.second]);
    this->parent = this;
    this->curr = temp->curr;
    
    return temp;
}

pair<int,int> Node::getblank(){
    for(int i = 0; i< 3; i ++){
        for(int j = 0; j < 3; j++){
            if(this->curr[i][j] == 0){
                return pair<int,int>(i,j);
            }
        }
    }
}