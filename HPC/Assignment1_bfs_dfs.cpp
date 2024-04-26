#include <iostream>
#include <omp.h>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjancentNodes;

public:
    Graph(int V)
    {
        this->V = V;
        adjancentNodes.resize(V);
    }

    void addEdge(int source, int destination)
    {
        this->adjancentNodes[source].push_back(destination);
        this->adjancentNodes[destination].push_back(source);
    }

    void bfs(int node)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while (!q.empty())
        {
            int new_node = q.front();
            q.pop();
            cout << new_node << " ";

            #pragma omp parallel for
            for (int i = 0; i < adjancentNodes[node].size(); i++)
            {
                int v = adjancentNodes[new_node][i];
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfs(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        #pragma omp parallel for
        for (int i = 0; i < adjancentNodes[node].size(); i++)
        {
            int next_node = adjancentNodes[node][i];
            if (!visited[next_node])
            {
                dfs(next_node, visited);
            }
        }
    }
};

int main()
{
    int numNodes = 6; // Number of nodes in the graph
    Graph graph(numNodes);
    vector<bool> visited(numNodes, false);

    // Adding edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    cout << "BFS starting from node 0: ";
    graph.bfs(0);
    cout << endl;

    cout << "DFS starting from node 0: ";
    graph.dfs(0, visited);
    cout << endl;

    return 0;
}