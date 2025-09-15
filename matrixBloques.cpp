#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

#define MAX 800
#define BLOCK_SIZE MAX/10

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
  
  for(int ii = 0; ii < MAX; ii += BLOCK_SIZE)
  {
    for(int jj = 0; jj < MAX; jj += BLOCK_SIZE)
    {
      for(int kk = 0; kk < MAX; kk += BLOCK_SIZE)  
      {
        for(int i = ii; i < ii + BLOCK_SIZE; i++) 
        {
          for(int j = jj; j < jj + BLOCK_SIZE; j++)
          {
            for(int k = kk; k < kk + BLOCK_SIZE; k++)
            {
              Y[i][j] += A[i][k] * B[k][j];
            }
          }
        }
      }
    }
  }
  
  auto end = high_resolution_clock::now();
  auto time = duration_cast<milliseconds>(end - start).count();
  cout << time << " " << MAX << " (Block size: " << BLOCK_SIZE << ")";
  
  return 0;
}
