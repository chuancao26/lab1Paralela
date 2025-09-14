#include <iostream>
using namespace std;
#define MAX 100
void print(double a[])
{
  for(int i = 0; i < MAX; i++)
  {
    cout << a[i] << endl;
  }
}
int main()
{
  double A[MAX][MAX], y[MAX], x[MAX];
  for (int i = 0; i < MAX; i++)
  {
    x[i] = (double)rand() / RAND_MAX;
    y[i] = 0.0;
    for (int j = 0; j < MAX; j++)
    {
      A[i][j] = (double)rand() / RAND_MAX;
    }
  }

  for (int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < MAX; j++)
    {
      y[i] += A[i][j] * x[j];
    }
  }

  for (int j = 0; j < MAX; j++)
  {
    for(int i = 0; i < MAX; i++)
    {
      y[i] += A[i][j] * x[j];
    }
  }
  return 0;
}
