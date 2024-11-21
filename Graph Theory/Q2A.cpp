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
        cout << "Edge " << i + 1 << " Vertex 1: ";
        cin >> vertices[i][0];
        cout << "Edge " << i + 1 << " Vertex 2: ";
        cin >> vertices[i][1];
        i++;
    }

    cout << "Degrees of each vertex: " << endl;

    for (int i = 0; i < numOfEdges; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int degree = 0;
            if (vertices[i][j] != " ")
            {
                string vertex = vertices[i][j];

                for (int k = 0; k < numOfEdges; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        if (vertex == vertices[k][l])
                        {
                            vertices[k][l] = " ";
                            degree++;
                        }
                    }
                }
                
                cout << "Vertex: " << vertex << " has " << degree << " degree" << endl;
            }
        }
    }
}