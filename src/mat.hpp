#ifndef MAT_HPP
#define MAT_HPP
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

class Matriz
{
  private:
    vector<int> numbers;
    vector<int> soma;
    static int matrixs;
    
  public:
    Matriz();

    int Tam();
    void ReadMatrix();
    void WalkMatrix(int **m, int size);
    void SumUpTimes();
};
#endif