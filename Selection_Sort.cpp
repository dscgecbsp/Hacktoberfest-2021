#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

//Creating A function prototype
void selectionSort(vector<int>& elements);

int main()
{
    //Prompt the user for the number of elements
    int nElements;
    cin >> nElements;
    //Then create a vector with size n and prompt user for element
    vector<int> elements(nElements);
    for(int i = 0; i < nElements; i++)
    {   
        cin >> elements[i];
    }
    //Calling Function SelectionSort
    selectionSort(elements);

    //Here, we are printing the elements of the vector after sorting it
    for(int i = 0; i < nElements; i++)
    {
        cout << elements[i] << " ";
    }
    cout << '\n';
    return 0;
}

//Create a Function that takes a unsorted vector of elements and sort it
//There is no need for returning as we pass vector by reference
void selectionSort(vector<int>& elements)
{
    // Creating a pointer with points to the elements from which we start out search
    //First, We search for the minimal value in our vector then we increase the value of our Pointer by 1
    //Then we Search for the second minimal Value and so on...
    int pointer = 0;
    int size = elements.size();
    while(pointer < size - 1)
    {
        int minIdx = pointer;
        for(int i = pointer + 1; i < size; i++)
        {
            //Searching for an element less than the element we are pointing at
            if(elements[i] < elements[minIdx]) minIdx = i;
        }
        //If we found an element less than the the element we are pointing at, then swap values
        swap(elements[pointer++], elements[minIdx]);
    }
}