#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

float** read_matrix(const unsigned r, const unsigned c){
  float **mat = (float**)calloc(r, sizeof(float*));

  for (unsigned i = 0 ; i < r ; i++){
    mat[i] = (float*)calloc(c, sizeof(float));
    for (unsigned j = 0 ; j < c ; j++){
      fin>>mat[i][j];
    }
  }

  return mat;
}

void print_matrix(float **mat, unsigned r, unsigned c){
  for (unsigned i = 0 ; i < r ; i++){
    for (unsigned j = 0 ; j < c ; j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
}

float det(){

}

int main(){
  unsigned r, c;
  fin >> r >> c;

  float **sysA = read_matrix(r, c);
  print_matrix(sysA, r, c);
}
