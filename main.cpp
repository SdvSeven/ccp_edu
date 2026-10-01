#include <iostream>
#include <stdexcept>

void rmMtx(int ** mtx, size_t m);

int ** makeMtx(size_t m, size_t n)
{
  int ** mtxR = new int * [m];

  try
  {
    for (size_t i = 0; i < m; ++i)
    {
      mtxR[i] = new int [n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    rmMtx(mtxR, m);
    throw;
  }

  return mtxR;
}

void rmMtx(int ** mtx, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete [] mtx[i];
  }

  delete [] mtx;
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  size_t total = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    total += lns[i];
  }

  if (total != n)
  {
    throw std::invalid_argument("sum of row lengths does not equal n");
  }

  int ** result = new int * [rows];
  size_t allocated = 0;

  try
  {
    size_t pos = 0;
    for (size_t i = 0; i < rows; ++i)
    {
      result[i] = new int[lns[i]];
      ++allocated;

      for (size_t j = 0; j < lns[i]; ++j)
      {
        result[i][j] = t[pos];
        ++pos;
      }
    }
  }
  catch (const std::bad_alloc & e)
  {
    rmMtx(result, allocated);
    throw;
  }

  return result;
}

void printMtx(int ** mtx, const size_t * lns, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    if (lns[i] == 0)
    {
      std::cout << '\n';
      continue;
    }

    std::cout << mtx[i][0];
    for (size_t j = 1; j < lns[i]; ++j)
    {
      std::cout << ' ' << mtx[i][j];
    }

    std::cout << '\n';
  }
}

int main()
{
  size_t n = 0;
  size_t rows = 0;
  std::cin >> n >> rows;
  if (!std::cin || rows == 0)
  {
    return 1;
  }

  int * t = new int[n];
  for (size_t i = 0; i < n; ++i)
  {
    std::cin >> t[i];
  }

  size_t * lns = new size_t[rows];
  for (size_t i = 0; i < rows; ++i)
  {
    std::cin >> lns[i];
  }

  if (std::cin.fail())
  {
    delete [] t;
    delete [] lns;
    return 1;
  }

  int ** mtx = nullptr;

  try
  {
    mtx = convert(t, n, lns, rows);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << '\n';
    delete [] t;
    delete [] lns;
    return 2;
  }

  printMtx(mtx, lns, rows);

  rmMtx(mtx, rows);
  delete [] t;
  delete [] lns;

  return 0;
}
