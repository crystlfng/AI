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
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);

    vector<int> temp1;
    temp1.push_back(4);
    temp1.push_back(0);
    temp1.push_back(5);

    vector<int> temp2;
    temp2.push_back(6);
    temp2.push_back(7);
    temp2.push_back(8);

    goal.push_back(temp);
    goal.push_back(temp1);
    goal.push_back(temp2);
}

Node* Node::up(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    
    if (coor.second == 0){
        return NULL;
    }
    else{
        swap(temp->curr[coor.first][coor.second],temp->curr[coor.first][coor.second-1]);
        this->parent = this;
        this->curr = temp->curr;
        this->gn = this->gn + 1;
    
        return temp;
    }
}

Node* Node::down(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();

    if (coor.second == 2){
        return NULL;
    }
    else{
        swap(temp->curr[coor.first][coor.second],temp->curr[coor.first][coor.second+1]);
        this->parent = this;
        this->curr = temp->curr;
        this->gn = this->gn + 1;
    
        return temp;
    }
}
Node* Node::right(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    if (coor.first == 2){
        return NULL;
    }
    else{
        swap(temp->curr[coor.first][coor.second],temp->curr[coor.first+1][coor.second]);
        this->parent = this;
        this->curr = temp->curr;
        this->gn = this->gn + 1;
    
        return temp;
    }
}
Node* Node::left(){
    Node* temp = new Node(this->curr);
    pair<int,int> coor= getblank();
    if (coor.second == 0){
        return NULL;
    }
    else{
        swap(temp->curr[coor.first][coor.second],temp->curr[coor.first-1][coor.second]);
        this->parent = this;
        this->curr = temp->curr;
        this->gn = this->gn + 1;
    
        return temp;
    }
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

int Node::misplaced(){
    int count = 0;
    for(int i = 0; i< 3; i ++){
        for(int j = 0; j < 3; j++){
            if(this->curr[i][j] != 0 && this->curr[i][j] != this->goal[i][j]){
                count++;
            }
        }
    }
    return count;
}

int Node::euclidean(){
    int totaldist = 0;
    int dist;
    for(int i = 0; i< 3; i ++){
        for(int j = 0; j < 3; j++){
            
        }
    }
    return totaldist;
}