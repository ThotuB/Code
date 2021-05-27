#include <iostream>
#include <string>

using namespace std;

unsigned **alloc_mat(unsigned rows, unsigned cols){
    unsigned **Mat = new unsigned*[rows];

    for (unsigned i = 0 ; i < rows ; i++){
        Mat[i] = new unsigned[cols];
    }

    return Mat;
}

void print_mat(unsigned **Mat, unsigned rows, unsigned cols){
    for (unsigned i = 0 ; i < rows ; i++){
        for (unsigned j = 0; j < cols; j++){
            cout << Mat[i][j] << " ";
        }
        cout << "\n";
    }
}

unsigned LCS_length(string str1, string str2){
    unsigned rows = str1.length() + 1;
    unsigned cols = str2.length() + 1;

    unsigned **Mat = alloc_mat(rows, cols);

    for (unsigned i = 0 ; i < rows ; i++){
        Mat[i][0] = 0;
    }

    for (unsigned j = 1 ; j < cols ; j++){
        Mat[0][j] = 0;
    }

    for (unsigned i = 1 ; i < rows ; i++){
        for (unsigned j = 1 ; j < cols ; j++){
            if ( str1[i-1] == str2[j-1] ){
                Mat[i][j] = Mat[i-1][j-1] + 1;
            }
            else if ( Mat[i-1][j] >= Mat[i][j-1] ){
                Mat[i][j] = Mat[i-1][j];
            }
            else {
                Mat[i][j] = Mat[i][j-1];
            }
        }
    }
    
    cout << str1 << "\n" << str2 << "\n";
    print_mat(Mat, rows, cols);

    return Mat[rows-1][cols-1];
}

int main(){
    string str1 = "BDCABA";
    string str2 = "ABCBDAB";

    LCS_length(str2, str1);
}