#include <iostream>
using namespace std;
class DPArray
{
    int *dpArray;
    int sizeOfArray;
    void createArray(int size);

public:
    DPArray(int num)
    {
        dpArray = NULL;
        createArray(num);
        sizeOfArray = num;
    }
    ~DPArray()
    {
        if (dpArray != NULL)
            delete[] dpArray;
    }
    void displayArr();
    void algo();
};
void DPArray::createArray(int size)
{
    int count = 0;
    int *Array = new int[size * size * 3];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(Array + i * size * 3 + j * 3 + 0) = -1;
            *(Array + i * size * 3 + j * 3 + 1) = -2;
            *(Array + i * size * 3 + j * 3 + 2) = -3;
            // for (int k = 0; k < 3; k++)
            // {
            //     *(dPArray + i * size * 3 + j * 3 + k) = ++count;
            // }
        }
    }
    dpArray = Array;
}
void DPArray::displayArr()
{
    int size = sizeOfArray;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << *(dpArray + i * size * 3 + j * 3 + k) << " ";
            }
            cout << "\t";
        }
        cout << endl
             << endl;
    }
}
void DPArray::algo()
{
}
int main()
{
    int num;
    cout << "Enter number of nodes : ";
    cin >> num;
    DPArray *arr = new DPArray(num);
    arr->~DPArray();
    arr->displayArr();
    return 0;
}