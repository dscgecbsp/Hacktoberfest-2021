//enter the number 'n', till which Fibonacci series will be printed out in the terminal...
//this code returns/prints Fibonacci series upto the n'th(inputted by user) term in the series...
//written by pradipto karmakar, Kolkata.
#include <iostream>
using namespace std;

int checkprime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 1;
    return 0;
}
//the main calling function...
int main()
{
    int i, num;
    int first = 0, second = 1;
    int newterm = first + second;
    cin >> num;
    cout << second << " ";
    for (i = 3; i <= num + 1; ++i)
    {
        if (newterm % 5 == 0)
        {
            cout << 0 << " ";
        }
        else if (checkprime(newterm) == 0)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << newterm << " ";
        }
        first = second;
        second = newterm;
        newterm = second + first;
    }
}
