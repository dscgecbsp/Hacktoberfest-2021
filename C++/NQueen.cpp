#include <bits/stdc++.h>
using namespace std;
int n;

// its time complexity is O(3n)
// lets optimise this.

bool isSafe(int row, int col, vector<vector<int>> &arr)
{
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (arr[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i, j--)
        if (arr[i][j] == 1)
            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (arr[i][j] == 1)
            return false;

    return true;
}
// optimization
bool isSafe2(int row, int col, vector<int> &rowHash, vector<int> &thirdHash, vector<int> &firstHash)
{
    if (rowHash[row] == 1 || thirdHash[row + col] == 1 || firstHash[n - 1 + row - col] == 1)
        return false;

    return true;
}

void NQueen(int col, int n, vector<vector<int>> &arr, vector<int> &rowHash, vector<int> &thirdHash, vector<int> &firstHash)
{
    if (col == n)
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe2(row, col, rowHash, thirdHash, firstHash))
        {
            rowHash[row] = 1;
            thirdHash[row + col] = 1;
            firstHash[n - 1 + row - col] = 1;

            arr[row][col] = 1;

            NQueen(col + 1, n, arr, rowHash, thirdHash, firstHash);

            arr[row][col] = 0;

            rowHash[row] = 0;
            thirdHash[row + col] = 0;
            firstHash[n - 1 + row - col] = 0;
        }
    }
    // return;
}

void printfunc(int n)
{
    vector<vector<int>> arr(n, vector<int>(n, 0));

    vector<int> rowHash(n, 0);
    vector<int> thirdHash(2 * n - 1, 0);
    vector<int> firstHash(2 * n - 1, 0);

    NQueen(0, n, arr, rowHash, thirdHash, firstHash);
}

int main()
{
    cin >> n;
    printfunc(n);
    return 0;
}