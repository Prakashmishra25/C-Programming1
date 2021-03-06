#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#define MAXCOUNT 1000000

using namespace std;

int pivoloc;

int partition(int A[],int low,int high)
{
  int temp;
  int x=A[high];
  int i = low - 1;
  for(int j=low;j <= high-1;j++){
    if(A[j] <= x){
      i = i+1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[high];
  A[high] = temp;
  return i+1;
}

void QuickSort(int A[],int low,int high)
{
  if(low < high){
      pivoloc = partition(A,low,high);
      QuickSort(A,low,pivoloc-1);
      QuickSort(A,pivoloc+1,high);
  }
}
int main(int argc, char **argv)
{
  //not Main code
  char filename[100];
  int a[MAXCOUNT], count;

  if (argc == 1) {
    cout << "Enter data file name:";
    cin >> filename;
  } else {
     strcpy(filename, argv[1]);
    if (argc == 2) {
      cout << "How many numbers you want to read:";
      cin >> count;
    } else if (argc == 3) {
      count = atoi(argv[2]);
    }
  }
  
  if (count > MAXCOUNT) {
    cout << "max count " << MAXCOUNT << ", exit!";
    exit(1);
  }
  
  ifstream infile;
  infile.open(filename);
  int i;
  for(i = 0; i < count; i++) {
    infile >> a[i];
  }

  const clock_t beginTime = clock();
  //Main code
  QuickSort(a,0,count);
  
  double seconds = (double)(clock() - beginTime)/CLOCKS_PER_SEC;

  for(i = 0; i < count; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "Total time is " << seconds << " sec." << endl;
  return 0;
}
  
