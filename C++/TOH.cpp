/*Tower of Hanoi */

/*
This is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying 2 rules: 
(i) Only one disk can be moved at a time. (ii) No bigger disk may be placed on top of a smaller disk.
*/

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char A, char B,char C)
{
    if (n>1){
    towerOfHanoi(n - 1, A,C,B);
    cout << "Move disk " << n << " from rod " << A <<
                                " to rod " << C << endl;
    towerOfHanoi(n - 1,B,A,C);
    }
}

int main()
{
    int n;
    cout<<"Enter the value of disks\n";
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
