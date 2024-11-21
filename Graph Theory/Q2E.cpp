#include <iostream>

using namespace std;

main()
{
    int numOfNodes;
    cout << "Enter the number of nodes: ";
    cin >> numOfNodes;

    int adjMatrix[100][100];
    int vertices[100][2];
    int maxCountEdges[100]={0};
    int edgesCount=0;

    cout << "Enter the adjacency matrix of edges: " << endl;

    for (int i=0;i<numOfNodes;i++)
    {
        for(int j=0;j<numOfNodes;j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    for(int j=0;j<numOfNodes;j++)
    {
        for(int k=j+1;k<numOfNodes;k++)
        {
            if(adjMatrix[j][k]>0)
            {
                edgesCount++;
            }
        }
    }

    int index=0;
    for(int l=0;l<numOfNodes;l++)
    {
        for(int m=l+1;m<numOfNodes;m++)
        {
            if(adjMatrix[l][m]!=0)
            {
                vertices[index][0]=l;
                vertices[index][1]=m;
                maxCountEdges[index]=adjMatrix[l][m];
                index++;
            }
        }
    }

    cout << "Lists of edges: " << endl;
    for(int p=0;p<edgesCount;p++)
    {
        cout << "Edge " << p+1 << ": " << "[" << vertices[p][0] << "," << vertices[p][1] << "]" << endl;
        cout << "Edges count: " << maxCountEdges[p] << endl;
    }
}