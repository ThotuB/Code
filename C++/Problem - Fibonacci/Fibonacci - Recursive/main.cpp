#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/// EFICIENCY & COMPLEXITY
clock_t tic, toc;
long long unsigned steps = 0;


long long unsigned fibonacci(unsigned n){
  steps++;

  if ( n > 1){
      return fibonacci(n-2) + fibonacci(n-1);
  }
  return n;
}

int main(){
  unsigned iter;

  cout<<"iter: ";
  cin>>iter;

  tic = clock();
  cout<<"Fibonacci ["<<iter<<"] = "<<fibonacci(iter)<<"\n";
  toc = clock();

  cout<<" -Time: "<<toc-tic<<"ms\n";
  cout<<" -Steps: "<<steps;
}
