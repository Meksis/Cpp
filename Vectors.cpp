#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    vector<int> vec_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    vector<int> vec_2;
    
    string input;
    int delete_begin;
    int delete_end;
    
    cout << "First deleting item index "; cin >> input; delete_begin = stoi(input);
    cout << "Last deleting item index "; cin >> input; delete_end = stoi(input);
    
    if (delete_begin <= delete_end) {
        for (int counter = 0; counter < delete_begin; counter ++) {
            vec_2.push_back(vec_1[counter]);
        }
        //for (int counter = 0; counter < static_cast<int>(vec_2.size()); counter ++) cout << vec_2[counter] << " ";
        
        cout << endl;


        for (int counter = delete_end + 1; counter < static_cast<int>(vec_1.size()); counter ++) {
            vec_2.push_back(vec_1[counter]);
        }
        
        for (int counter = 0; counter < static_cast<int>(vec_2.size()); counter ++) cout << vec_2[counter] << " ";
    }
    
    else {
        for (int counter = 0; counter < static_cast<int>(vec_1.size()); counter ++) cout << vec_1[counter] << " ";
    }
    
    return 0;
}