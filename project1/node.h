#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    public:
        Node* parent;
        vector<vector<int> > curr;
        int x, y; //the coordinates to the blanck tile
        int gn;
        int hn;
        int fn;

        int misplaced();
        int euclidean();

        Node* up();
        Node* down();
        Node* right();
        Node* left();

        Node();
        Node(vector<vector<int> >);
        pair<int,int> getblank();
};