#include <iostream>
#define MAX 20
#define INFINITY 999
using namespace std;
class graph
{
public:
    int vertices, edges, weight, u, v;
    int visited[MAX];
    int cost = 0;
    void read()
    {
        int GMAT[20][20];
        cout << "enter the number of vertices\n";
        cin >> vertices;
        cout << "enter the number of edges\n";
        cin >> edges;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                GMAT[i][j] = 0;
            }
        }
        cout << "enter the starting ending and weight\n";
        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v >> weight;
            GMAT[u - 1][v - 1] = weight;
            GMAT[v - 1][u - 1] = weight;
        }
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << GMAT[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < vertices - 1; i++)
        {
            int min = 99999;
            for (int j = 0; j < vertices; j++)
            {
                if (GMAT[i][j] != 0 && GMAT[i][j] < min && visited[i] == 0)
                {
                    min = GMAT[i][j];
                    u = i;
                    v = j;
                }
            }
            visited[u] = 1;
            cout << u + 1 << " " << v + 1 << " " << min << "\n";
            cost = cost + min;
        }
        cout << endl;
        cout << "minimum cost is " << cost;
    }
};
int main()
{
    graph g;
    g.read();
    return 0;
}