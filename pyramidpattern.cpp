using namespace std;
 

void pyramid(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
 
        // Ending line after each row
        cout << endl;
    }
}
int main()
{
    int n = 5;
    pyramid(n);
    return 0;
}
