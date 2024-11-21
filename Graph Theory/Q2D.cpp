#include <iostream>

using namespace std;

int indexCheck(int vertice,int uniqueVertices[],int numOfVert);

main()
{
    int numOfVert;
    cout << "Enter the number of unique vertices: ";
    cin >> numOfVert;
    int uniqueVertices[numOfVert];
    int o = 0;
    int uVert;

    while (o < numOfVert)
    {
        bool check = true;
        cout << "Vertice: ";
        cin >> uVert;

        for (int i = 0; i < o; i++)
        {
            if (uniqueVertices[i] == uVert)
            {
                cout << "Enter again! ";
                check = false;
                break;
            }
        }
        if (check == true)
        {
            uniqueVertices[o] = uVert;
            o++;
        }
    }

    int numOfEdges;
    cout << "Enter the number of edges: ";
    cin >> numOfEdges;

    string option;
    while (option != "Y" && option != "N")
    {
        cout << "Is graph directed? (Y/N): ";
        cin >> option;
    }
    int vertices[numOfEdges][2];
    int matrix[numOfVert + 1][numOfVert + 1];
    for (int i = 0; i < numOfVert + 1; i++)
    {
        for (int j = 0; j < numOfVert + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < numOfVert ; i++)
    {
        matrix[0][i + 1] = uniqueVertices[i];
        matrix[i + 1][0] = uniqueVertices[i];
    }
    cout << endl;
    if (option == "Y")
    {
        cout << "\e[0;31mEnter the tail first and tail of edges later!" << endl;
        cout << "Entering wrong input may result in unexcpected results! Enter valid vertex only!" << endl << endl;
        cout << "\e[0;37mEnter vertices of the edges: " << endl;
        for (int i = 0; i < numOfEdges; i++)
        {
            cout << "Edge " << i + 1 << " tail vertex: ";
            cin >> vertices[i][0];

            cout << "Edge " << i + 1 << " head vertex: ";
            cin >> vertices[i][1];
            matrix[indexCheck(vertices[i][0],uniqueVertices,numOfVert)+1][indexCheck(vertices[i][1],uniqueVertices,numOfVert)+1]=1;
        }

        for (int i = 0; i < numOfVert + 1; i++)
        {
            for (int j = 0; j < numOfVert + 1; j++)
            {
                if(i==0 || j==0)
                {
                    cout << "\e[0;31m";
                }
                else
                {
                    cout << "\e[0;37m";
                }
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\e[0;31mEntering wrong input may result in unexcpected results! Enter valid vertices only!" << endl << endl;
        cout << "\e[0;37mEnter vertices of the edges: " << endl << endl;
        for (int i = 0; i < numOfEdges; i++)
        {
            cout << "Edge " << i + 1 << " vertex 1: ";
            cin >> vertices[i][0];

            cout << "Edge " << i + 1 << " vertex 2: ";
            cin >> vertices[i][1];
            matrix[indexCheck(vertices[i][0],uniqueVertices,numOfVert)+1][indexCheck(vertices[i][1],uniqueVertices,numOfVert)+1]=1;
            matrix[indexCheck(vertices[i][1],uniqueVertices,numOfVert)+1][indexCheck(vertices[i][0],uniqueVertices,numOfVert)+1]=1;
        }
        for (int i = 0; i < numOfVert + 1; i++)
        {
            for (int j = 0; j < numOfVert + 1; j++)
            {
                if(i==0 || j==0)
                {
                    cout << "\e[0;31m";
                }
                else
                {
                    cout << "\e[0;37m";
                }
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int indexCheck(int vertice,int uniqueVertices[],int numOfVert)
{
    for(int j=0;j<numOfVert;j++)
    {
        if(vertice==uniqueVertices[j])
        {
            return j;
        }
    }
}