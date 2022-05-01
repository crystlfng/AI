#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(){
    vector<vector<int> > initial;
    int choice;
    cout << "Choose the puzzle type:\n";
    cout << "1: default puzzle\n";
    cout << "2: input an arbitrary puzzle\n";
    cin >> choice;

    while(choice!=1&&choice!=2){
        cout << "Please choose a valid puzzle type:\n";
        cout << "1: default puzzle\n";
        cout << "2: input an arbitrary puzzle\n";
        cin >> choice;
    }
    
    if(choice == 1){
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

        initial.push_back(temp);
        initial.push_back(temp1);
        initial.push_back(temp2);
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

    for (int j =0; j < initial.size();j++){
        vector<int> temp;
        for(int i = 0; i < initial[j].size(); i++){
            cout << initial[j][i] << " ";
        }

        cout << endl << endl;;
    }
    
    cout << "What type of search would you like to preform?\n";
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

    if(choice == 1){
        //ucs();
    }
    else if(choice ==2){
        //mth();
    }
    else{
        //edh();
    }

    return 0;
}


