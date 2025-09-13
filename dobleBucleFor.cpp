#include <iostream>
#include <ctime>
using namespace std;
#define MAX 100
int main()
{
  double A[MAX][MAX], y[MAX], x[MAX];
  for (int i = 0; i < MAX; i++)
  {
    x[i] = rand() % 3;
    y[i] = 0.0;
    for (int j = 0; j < MAX; j++)
    {
      A[i][j] = rand() % 3; 
    }
  }

  for (int i = 0; i < MAX; i++)
  {
    for(int j = 0; i < MAX; j++)
    {
      y[i] += A[i][j] * x[j];
    }
  }




  return 0;
}
