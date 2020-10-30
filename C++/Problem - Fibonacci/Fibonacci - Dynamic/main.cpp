#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/// EFICIENCY & COMPLEXITY
clock_t tic, toc;
long long unsigned steps = 0;

long long unsigned *fibArr;

long long unsigned fibonacci(unsigned n){
  steps++;

  if ( n > 1){
    if (  fibArr[n] == 0 ){
      long long unsigned sum = fibonacci(n-2) + fibonacci(n-1);
      fibArr[n] = sum;
      //cout<<sum<<" ";
      return sum;
    }
    return fibArr[n];
  }
  return n;
}

int main(){
  unsigned iter;

  cout<<"iter: ";
  cin>>iter;

  fibArr = (long long unsigned*)calloc(iter+1, sizeof(long long unsigned));

  tic = clock();
  cout<<"Fibonacci ["<<iter<<"] = "<<fibonacci(iter)<<"\n";
  toc = clock();

  cout<<" -Time: "<<toc-tic<<"ms\n";
  cout<<" -Steps: "<<steps;
}
