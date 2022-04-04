// Floyd - Warshall's alogrithm for creation of minimum spanning tree.

#include<iostream>

using namespace std;
int FloydWarshall()
{
    return 0;
}
int main(int argc)
{
    int num = argc;
    int array[num][num];
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(i==j)
            {
                array[i][j] = 0;
            }
        }
    }
    return 0;
}