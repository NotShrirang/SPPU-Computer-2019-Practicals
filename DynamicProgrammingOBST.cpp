#include <iostream>
using namespace std;
#define MAX 10
int *pArr, *qArr;
struct fields
{
    int weight;
    int cost;
    int root;
};
class DPArray
{
    fields dpArray[MAX][MAX];
    int sizeOfArray;
    void createArray(int size);

public:
    DPArray(int num)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                dpArray[i][j].weight = NULL;
                dpArray[i][j].cost = NULL;
                dpArray[i][j].root = NULL;
            }
        }
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
    int calcWeight(int i, int j);
    int calcCost(int i, int j);
};
void DPArray::createArray(int size)
{
    int count = 0;
    for (int r = 0; r < size; r++)
    {
        int j = r;
        for (int i = 0; i < size; i++)
        {
            dpArray[i][j].weight = calcWeight(i, j);
        }
        // for (int k = 0; k < 3; k++)
        // {
        //     *(dPArray + i * size * 3 + j * 3 + k) = ++count;
        // }
    }
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
int DPArray::calcWeight(int i, int j)
{
    if (i == j)
    {
        return qArr[i];
    }
    else
    {
        int w;
        w = pArr[i] + qArr[i] + dpArray[i][j - 1].weight;
        return w;
    }
}
int DPArray::calcCost(int i, int j)
{
    if (i == j)
    {
        return 0, 0;
    }
    else
    {
        int w, min_value = 10000, k;
        for (k = i; k <= j; k++)
        {
            int m = calcCost(i, k - 1) + calcCost(k, j);
            if (m < min_value)
            {
                min_value = m;
            }
        }
        w = dpArray[i][j - 1].weight + min_value;
        return w, k;
    }
}
int main()
{
    int num;
    cout << "Enter number of nodes : ";
    cin >> num;
    pArr = new int[num - 1];
    qArr = new int[num - 1];
    DPArray *arr = new DPArray(num);
    arr->displayArr();
    arr->~DPArray();
    cout << "Enter p array: ";
    for (int i = 0; i < num; i++)
    {
        cin >> pArr[i];
    }
    cout << "Enter q array: ";
    for (int i = 0; i <= num; i++)
    {
        cin >> qArr[i];
    }
    // for (int i = 0; i < num; i++)
    // {
    //     cout << pArr[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i <= num; i++)
    // {
    //     cout << qArr[i] << " ";
    // }
    return 0;
}