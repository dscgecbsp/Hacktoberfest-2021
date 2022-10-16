#include <iostream>
#include <cstring>
using namespace std;
// Deep And Shallow Copy in Cpp
class ShallowCopy
{
public:
    int a, b;
    char *name;
    ShallowCopy()
    {
        name = new char[7];
    }
    void Sum(string obj)
    {
        cout << obj << " Sum: " << a + b << endl;
        cout << name << endl;
    }
    void SetName(char name[])
    {
        this->name = name;
    }
    // When U Call Deep Copy No Changes Effect
    //  In Obj2...
    ShallowCopy(ShallowCopy &dc)
    {
        // Create New Dynamically char
        char *c = new char[strlen(dc.name) + 1];
        strcpy(c, dc.name);
        this->name = c;
        this->a = dc.a;
        this->b = dc.b;
    }
    // Deallocating Memory...
    ~ShallowCopy()
    {
        delete name;
    }
};

int main()
{
    ShallowCopy sc;
    sc.a = 10;
    sc.b = 20;
    char name[7] = "Justin";
    sc.SetName(name);
    sc.Sum("Obj1->");
    // Shallow Copy
    ShallowCopy sc2(sc);
    sc2.Sum("Obj2->");
    // Now Change the value of first obj
    sc.a = 20;
    sc.name[0] = 'B';
    // Now Calling obj2 and obj1..
    sc2.Sum("Obj2->");
    sc.Sum("Obj1->");
    return 0;
}