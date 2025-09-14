#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

#define MAX 1600

int A[MAX][MAX], B[MAX][MAX], Y[MAX][MAX];

void print(int Y[MAX][MAX])
{
  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < MAX; j++)
    {
      cout << Y[i][j] << " ";
    }
    cout << endl;
  }
}
int main()
{
  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < MAX; j++)
    {
      A[i][j] = rand() % 5;
      B[i][j] = rand() % 5;
      Y[i][j] = 0;
    }
  }
  auto start = high_resolution_clock::now();

  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < MAX; j++)
    {
      for(int k = 0; k < MAX; k++)
      {
        Y[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  auto end = high_resolution_clock::now();
  auto time = duration_cast<milliseconds>(end - start).count();
  cout << time << " " << MAX;

  return 0;
}
