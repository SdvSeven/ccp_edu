#include <iostream>
int  makeMtx(int  mtx,size_t m,size_t n);
int  transpose(int  mtx);
void rmMtx(int  mtx, size_t m);
int main()
{
        size_t m = 0;
        size_t n = 0;
        std::cin >> m >> n;
        if (!std::cin)
	if (!std::cin || m == 0 || n == 0)
        {
                return 1;
        }
        int  mtx = nullptr;
        mtx = makeMtx(mtx,m,n);
        for (size_t i=0;i<m*n;++i)
        {
                std::cin >> mtx[i/n][i%n];
        }
        if (std::cin.fail())
        {
                rmMtx(mtx,m);
                return 1;
        }
        transpose(mtx);
	std::cout <<mtx[0][0];
        for (size_t i=0;i<m*n;++i) 
        { 
                std::cout << '_' <<  mtx[i/m][i%m];
        }
	for (size_t i =0; i <n; i++)
	{
		std::cout << '\n' << mtx[i][0];
		for (size_t j =0; j < m; ++j)
		{
	std::cout << '_' << mtx[i][j];
	}
	}
        rmMtx(mtx,m);

}
