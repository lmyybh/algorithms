#include <iostream>
#include "nqueens2.h"

void Test(int func(int), int n, int result)
{
    int res = func(n);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(int) = totalNQueens_v2;

    Test(func, 1, 1);
    Test(func, 4, 2);

    return 0;
}
