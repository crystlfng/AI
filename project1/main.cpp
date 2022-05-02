#include <iostream>
#include <string>
#include <vector>
#include "search.cpp"
using namespace std;

vector<vector<int> > puzzle();

int main(){
    vector<vector<int> > initial;
    int choice;
    cout << "\nChoose the puzzle type:\n";
    cout << "1: default puzzles\n";
    cout << "2: input an arbitrary puzzle\n";
    cin >> choice;

    while(choice!=1&&choice!=2){
        cout << "\nPlease choose a valid puzzle type:\n";
        cout << "1: default puzzle\n";
        cout << "2: input an arbitrary puzzle\n";
        cin >> choice;
    }
    
    if(choice == 1){
        initial = puzzle();
    }
    else{
        for (int j =0; j < 3;j++){
            vector<int> temp;
            cout << "Enter the numbers for row " << j << "press enter after each\n";

            for(int i = 0; i < 3; i++){
                int num;
                cin >> num;
                temp.push_back(num);
            }

            initial.push_back(temp);
        }

    }

    cout << "\nSo the puzzle you would like to solve is this one: \n";
    for (int j =0; j < initial.size();j++){
        for(int i = 0; i < initial[j].size(); i++){
            cout << initial[j][i] << " ";
        }
        cout << endl;;
    }
    
    cout << "\nWhat type of search would you like to preform?\n";
    cout << "1: Uniform Cost Search\n";
    cout << "2: Misplaced Tile Heuristic\n";    
    cout << "3: Euclidian Distance Heuristic\n";
    cin >> choice;

    while(choice!=1&&choice!=2&&choice!=3){
        cout << "Please choose a valid puzzle type:\n";
        cout << "1: Uniform Cost Search\n";
        cout << "2: Misplaced Tile Heuristic\n";    
        cout << "3: Euclidian Distance Heuristic\n";
        cin >> choice;
    }

    vector<int> temp = {1,2,3};
    vector<int> temp1 = {4,5,6};
    vector<int> temp2 = {7,8, 0};
    vector<vector<int> > goal;
    goal.push_back(temp);
    goal.push_back(temp1);
    goal.push_back(temp2);

   
    search(initial, choice, goal);

    return 0;
}


vector<vector<int> > puzzle(){
    int choice;
    vector<vector<int> > initial;
    cout << "\nPlease choose the difficulty: \n1. Trivial\n2. Very Easy\n3. Easy\n4. Doable\n5. Oh Boy\n"<<endl;

    cin >> choice;

    if(choice ==1){
        vector<int> temp = {1,2,3};

        vector<int> temp1 = {4,5,6};

        vector<int> temp2 = {7,8, 0};

        initial.push_back(temp);
        initial.push_back(temp1);
        initial.push_back(temp2);
    }
    else if(choice ==2){
        vector<int> temp;
        temp.push_back(1);
        temp.push_back(2);
        temp.push_back(3);

        vector<int> temp1;
        temp1.push_back(4);
        temp1.push_back(5);
        temp1.push_back(6);

        vector<int> temp2;
        temp2.push_back(7);
        temp2.push_back(0);
        temp2.push_back(8);

        initial.push_back(temp);
        initial.push_back(temp1);
        initial.push_back(temp2);
    }
    else if(choice ==3){
        vector<int> temp;
        temp.push_back(1);
        temp.push_back(2);
        temp.push_back(0);

        vector<int> temp1;
        temp1.push_back(4);
        temp1.push_back(5);
        temp1.push_back(3);

        vector<int> temp2;
        temp2.push_back(7);
        temp2.push_back(8);
        temp2.push_back(6);

        initial.push_back(temp);
        initial.push_back(temp1);
        initial.push_back(temp2);
    }
    else if(choice ==4){
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(1);
        temp.push_back(2);

        vector<int> temp1;
        temp1.push_back(4);
        temp1.push_back(5);
        temp1.push_back(3);

        vector<int> temp2;
        temp2.push_back(7);
        temp2.push_back(8);
        temp2.push_back(6);

        initial.push_back(temp);
        initial.push_back(temp1);
        initial.push_back(temp2);
    }
    else if(choice ==5){
        vector<int> temp;
        temp.push_back(8);
        temp.push_back(7);
        temp.push_back(1);

        vector<int> temp1;
        temp1.push_back(6);
        temp1.push_back(0);
        temp1.push_back(2);

        vector<int> temp2;
        temp2.push_back(5);
        temp2.push_back(4);
        temp2.push_back(3);

        initial.push_back(temp);
        initial.push_back(temp1);
        initial.push_back(temp2);
    }
    return initial;
}
