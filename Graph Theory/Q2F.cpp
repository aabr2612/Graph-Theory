#include <iostream>

using namespace std;

main()
{
    int numOfVert;
    cout << "Enter the number of vertices: ";
    cin >> numOfVert;

    int numOfEdges;
    cout << "Enter the number of edges: ";
    cin >> numOfEdges;

    int incidenceMatrix[numOfEdges][numOfEdges];
    int vertices[numOfEdges][2];
    int frequencyEdges[numOfEdges];

    for(int i=0;i<numOfEdges;i++)
    {
        for(int j=0;j<numOfEdges;j++)
        {
            incidenceMatrix[i][j]=0;
        }
    }
    for (int i = 0; i < numOfVert; i++)
    {
        for (int j = 0; j < numOfVert; j++)
        {
            incidenceMatrix[i][j] = 0;
        }
    }
    

    for(int k=0;k<numOfEdges;k++)
    {
        cout << "Enter edge " << k+1 << " vertex 1: ";
        cin >> vertices[k][0];
        cout << "Enter edge " << k+1 << " vertex 2: ";
        cin >> vertices[k][1];
        cout << "Enter the frequency of edge: ";
        cin >> frequencyEdges[k];
    }

    for(int a=0;a<numOfEdges;a++)
    {
        incidenceMatrix[vertices[a][0]][a]=frequencyEdges[a];
        incidenceMatrix[vertices[a][1]][a]=frequencyEdges[a];
    }

    for(int b=0;b<numOfVert;b++)
    {
        for(int c=0;c<numOfVert;c++)
        {
            cout << incidenceMatrix[b][c] << " ";
        }
        cout << endl;
    }
}