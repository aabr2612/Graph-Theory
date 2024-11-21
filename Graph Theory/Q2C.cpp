#include <iostream>

using namespace std;

void colorGraph(string[][2], char[][2], int, int);
void colorNodes(string[][2], char[][2], int, int);

main()
{
    bool bipartiteCheck = true;
    int numOfEdges;

    cout << "Enter the number of edges: ";
    cin >> numOfEdges;

    cout << "Enter the vertices of the edges: " << endl;

    string vertices[numOfEdges][2];
    char color[numOfEdges][2];

    for (int i = 0; i < numOfEdges; i++)
    {
        color[i][0] = color[i][1] = 'o';

        cout << "Edge " << i + 1 << " starting vertex: ";
        cin >> vertices[i][0];

        cout << "Edge " << i + 1 << " ending vertex: ";
        cin >> vertices[i][1];

        if (vertices[i][0] == vertices[i][1])
        {
            bipartiteCheck = false;
        }
        else if (i == 0 && vertices[i][0] != vertices[i][1] && bipartiteCheck == true)
        {
            color[i][0] = 'R';
            color[i][1] = 'B';
        }
        else if (bipartiteCheck == true)
        {
            colorGraph(vertices, color, i, i);
            if (color[i][0] == color[i][1] && color[i][0] != 'o')
            {
                bipartiteCheck = false;
            }
        }
    }

    if (bipartiteCheck)
    {
        for (int m = 0; m < numOfEdges; m++)
        {
            if (color[m][0] == 'o' && color[m][1] == 'o')
            {
                color[m][0] = 'R';
                color[m][1] = 'B';
                colorNodes(vertices, color, m, numOfEdges);
            }
            else if (color[m][1] == 'o')
            {
                if (color[m][0] == 'R' && color[m][1] == 'o')
                {
                    color[m][1] = 'B';
                }
                if (color[m][0] == 'B' && color[m][1] == 'o')
                {
                    color[m][1] = 'R';
                }
                colorNodes(vertices, color, m, numOfEdges);
            }
            else if (color[m][0] == 'o')
            {
                if (color[m][1] == 'R' && color[m][0] == 'o')
                {
                    color[m][0] = 'B';
                }
                if (color[m][1] == 'B' && color[m][0] == 'o')
                {
                    color[m][0] = 'R';
                }
                colorNodes(vertices, color, m, numOfEdges);
            }
        }
        for (int l = 0; l < numOfEdges; l++)
        {
            if (color[l][0] == color[l][1])
            {
                bipartiteCheck = false;
                break;
            }
        }
    }
    if (bipartiteCheck == true)
    {
        cout << "The Graph is Bipartite.";
    }
    else
    {
        cout << "The Graph is not Bipartite.";
    }

    return 0;
}
void colorGraph(string vertices[][2], char color[][2], int i, int numOfEdges)
{
    bool colorC = false;
    for (int j = 0; j < numOfEdges; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            if (vertices[j][k] == vertices[i][0] && color[j][k] != 'o')
            {
                color[i][0] = color[j][k];
            }
            else if (vertices[j][k] == vertices[i][1] && color[j][k] != 'o')
            {
                color[i][1] = color[j][k];
            }
        }
        if (color[i][0] == 'R' && color[i][1] == 'o')
        {
            color[i][1] = 'B';
        }
        if (color[i][0] == 'B' && color[i][1] == 'o')
        {
            color[i][1] = 'R';
        }
        if (color[i][1] == 'R' && color[i][0] == 'o')
        {
            color[i][0] = 'B';
        }
        if (color[i][1] == 'B' && color[i][0] == 'o')
        {
            color[i][0] = 'R';
        }
        if (colorC)
        {
            break;
        }
    }
}
void colorNodes(string vertices[][2], char color[][2], int m, int numOfEdges)
{
    for (int n = 0; n < numOfEdges; n++)
    {
        if (vertices[n][0] == vertices[m][0] && color[n][0] == 'o')
        {
            color[n][0] = color[m][0];
        }
        if (vertices[n][1] == vertices[m][0] && color[n][1] == 'o')
        {
            color[n][1] = color[m][0];
        }
        if (vertices[n][0] == vertices[m][1] && color[n][0] == 'o')
        {
            color[n][0] = color[m][1];
        }
        if (vertices[n][1] == vertices[m][1] && color[n][1] == 'o')
        {
            color[n][1] = color[m][1];
        }
    }
}