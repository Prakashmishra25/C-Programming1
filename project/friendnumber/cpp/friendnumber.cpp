#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
int factoradd(int a)
{
  int x = 0;
  int k = sqrt(a);
  for(int i=2;i<=k;i++){
    if(0==a%i){
      x=x+i+a/i;
    }
  }
  if(a%k == 0){
      x=x-k;
  }
  return x+1;
}
int main()
{
  clock_t start,finish;
  double totaltime;
  //cout << sqrt(5) << endl;
  start=clock();
  //factoradd(220);
  //cout << "8" << factoradd(8);
  for(int j=220;j<=1000000;j++){
    int m=factoradd(j);
    if(j < m && j == factoradd(m)){
	cout << j << ',' << factoradd(j) << '\n';
    }
  }
  finish=clock();
  totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
  cout << "Program run time is " << totaltime << "s." << '\n';
  return 0;
}
