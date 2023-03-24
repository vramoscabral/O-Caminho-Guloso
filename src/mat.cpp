#include "mat.hpp"
int Matriz::matrixs=0;

Matriz::Matriz()
{}

int Matriz::Tam()
{
  ifstream tam;

  tam.open("dataset/input.data");
  int size;

  tam >> size >> size;

  tam.close();

  return size;
}

void Matriz::ReadMatrix()
{
  ifstream Mtxfile;

  Mtxfile.open("dataset/input.data");
  int a, size=Tam(), i, j, nn=1; 

  Mtxfile >> a >> a;

  while (!Mtxfile.eof()) {
    int **mtrx=new int*[size];
    for (i=0; i<size; i++)
      mtrx[i]=new int[size];
    
    for (i=0; i<a; i++)
    {
      for (j=0; j<a; j++)
      {
        if (!Mtxfile.eof())
          Mtxfile >> mtrx[i][j];
      }
    }

    if (!Mtxfile.eof())
    {
      cout << "Matriz " << nn << endl << endl;
      for (i=0; i<a; i++)
      {
        for (j=0; j<a; j++)
        {
          cout << mtrx[i][j] << " ";
        }
        cout << endl;
      }
      
      WalkMatrix(mtrx,size);
      matrixs++;
      cout << endl;
      int numbs=numbers.size();
      for (i=0; i<numbs; i++)
        cout << numbers[i] << " ";
      cout << endl << "A soma do caminho percorrido eh: ";
      cout << accumulate(numbers.begin(),numbers.end(),0);
      soma.push_back(accumulate(numbers.begin(),numbers.end(),0));
      cout << endl << endl;
      numbers.clear();
      nn++;
    }
  }
    

  Mtxfile.close();
}

void Matriz::WalkMatrix(int **m, int size)
{
  int z=1, i=0, j=0;

  while(z!=0)
  {
    if (i==size-1 && j==size-1)
    {
      z=0;
      numbers.push_back(m[i][j]);
    }
    else if (j==size-1 && i<size-1)
    {
      if (m[i][j-1] > m[i+1][j] && m[i][j-1] > m[i+1][j-1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        j--;
      }
      else if (m[i+1][j-1] > m[i+1][j] && m[i+1][j-1] >= m[i][j-1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
        j--;
      }
      else
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
      }
    }
    else if (i==size-1 && j<size-1)
    {
      numbers.push_back(m[i][j]);
      j++;
    }
    else if (i==0 && j==0)
    {
      if (m[i+1][j] >= m[i][j+1] && m[i+1][j] > m[i+1][j+1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
      }
      else if (m[i][j+1] > m[i+1][j] && m[i][j+1] > m[i+1][j+1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        j++;
      }
      else
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
        j++;
      }
    }
    else
    {
      if (m[i+1][j] >= m[i][j+1] && m[i+1][j] > m[i+1][j+1] && m[i+1][j] >= m[i][j-1] && m[i+1][j] >= m[j+1][j-1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
      }
      else if (m[i][j-1] > m[i][j+1] && m[i][j-1] > m[i+1][j+1] && m[i][j-1] > m[i+1][j] && m[i][j-1] > m[i+1][j-1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        j--;
      }
      else if (m[i][j+1] >= m[i][j-1] && m[i][j+1] > m[i+1][j+1] && m[i][j+1] > m[i+1][j] && m[i][j+1] > m[i+1][j-1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        j++;
      }
      else if (m[i+1][j-1] >= m[i][j-1] && m[i+1][j-1] > m[i+1][j+1] && m[i+1][j-1] > m[i+1][j] && m[i+1][j-1] >= m[i][j+1])
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
        j--;
      }
      else
      {
        numbers.push_back(m[i][j]);
        m[i][j] = -1;
        i++;
        j++;
      }
    }
  }
}

void Matriz::SumUpTimes()
{
  int ss=0, sm=soma.size();

  cout << endl << "CONSIDERACOES FINAIS" << endl << endl;
  for (int i=0; i<sm; i++)
  {
    cout << "A soma do caminho percorrido da matriz " << i+1 << " foi " << soma[i] << endl;
    ss+=soma[i];
  }
  cout << endl << "A soma total do percurso por todas as " << matrixs << " matrizes foi " << ss;
}