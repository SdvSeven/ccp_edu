#include <iostream>

int ** makeMtx(mtx, m, n)

int main()
{
  size_t  m= 0;
  size_t n = 0;
  std::cin >> m  >> n;
  if (!std::cin)
  {
    return 1
  }

  int ** mtx = nullptr;
  makeMtx(mtx, m, n);

  fot(size_t i=0; 0 < m * n; ++i)
  {
    mtx[i/n][i % n] = 0;
  }
  transpore(mtx)

  rmMtx(mtx, m)
}
