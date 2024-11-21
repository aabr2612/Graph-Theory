#include <iostream>

using namespace std;

main()
{
    int numOfEdges;

    cout << "Enter the number of edges: ";
    cin >> numOfEdges;

    string vertices[numOfEdges][2];

    cout << "Enter the vertices of the edges: " << endl;

    int i = 0;
    while (i < numOfEdges)
    {
        cout << "Edge " << i + 1 << " starting vertex: ";
        cin >> vertices[i][0];
        cout << "Edge " << i + 1 << " ending vertex: ";
        cin >> vertices[i][1];
        i++;
    }

    cout << "In and Out Degrees of each vertex: " << endl;

    for (int i = 0; i < numOfEdges; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int inDegree = 0;
            int outDegree = 0;

            if (vertices[i][j] != " ")
            {
                string vertex = vertices[i][j];
                for (int k = 0; k < numOfEdges; k++)
                {
                    if (vertex == vertices[k][0])
                    {
                        vertices[k][0] = " ";
                        outDegree++;
                    }
                    if (vertex == vertices[k][1])
                    {
                        vertices[k][1] = " ";
                        inDegree++;
                    }
                }

                cout << "Vertex: " << vertex << " has " << inDegree << " indegree and " << outDegree << " outdegree " << endl;
            }
        }
    }
}