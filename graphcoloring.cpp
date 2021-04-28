#include <bits/stdc++.h>
using namespace std;


class Graph
{
    
    public:
    int n;
    int** adjacencyMatrix;

    Graph(int* edges[], int no_of_edges, int no_of_vertices)
    {
        n=no_of_vertices;
        adjacencyMatrix = (int**)malloc(sizeof(int*)*(n+1));
        for(int i=0;i<=n; i++)
        {
            adjacencyMatrix[i] = (int*)malloc(sizeof(int)*(n+1));
        }
        
        for (int i = 0; i < no_of_edges; i++) 
        { 
            
            adjacencyMatrix[edges[i][0]][edges[i][1]] = 1; 
            adjacencyMatrix[edges[i][1]][edges[i][0]] = 1;             
            
        } 
        
       

    }

    // no color should be adjacent
    bool notAdjacent(int colour[])
    {
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (adjacencyMatrix[i][j] && colour[j] == colour[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    //checks if atmost m colours can be assigned or nots
    bool colourGraph(int m, int i, int colour[])
    {
        
        if (i == n) 
        {
            
            if (notAdjacent(colour)) 
            {                
                printMinimalColouring(colour);
                return true;
            }
            return false;
        }
    
        for (int j = 1; j <= m; j++) 
        {
            colour[i] = j;            
            if (colourGraph(m, i + 1, colour))
            {
                return true;
            }

            colour[i] = 0;
        }

        return false;
    }


    void printMinimalColouring(int colour[])
    {
        cout<<"Colouring for "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<"vertex "<<i<<" is "<<colour[i]<<endl;
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(maxi<colour[i])
            {
                maxi=colour[i];
            }
        }
        cout<<"chromatic number is "<<(maxi)<<endl;
        
    }
    
    void output()
    {
        int color[n];
        for (int i = 0; i < n; i++)
        {
            color[i] = 0;
        }
        for (int i = 1; i <=n; i++)
        {
            if (colourGraph(i, 0, color))
            {
                break;
            }        
            
        }
        
    }
};



int main() 
{ 
    int **edges;
    int size = 6; 
    int n = 6;
    edges = (int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++)
    {
        edges[i] = (int*)malloc(sizeof(int)*2); 
    }
    edges[0][0]=1;
    edges[0][1]=4;
    edges[1][0]=4;
    edges[1][1]=3;
    edges[2][0]=3;
    edges[2][1]=1;
    edges[3][0]=5;
    edges[3][1]=3;
    edges[4][0]=4;
    edges[4][1]=5;
    edges[5][0]=4;
    edges[5][1]=2;
    //edges are { 1, 4 }, { 4, 3 }, { 3, 1 },{ 5, 3 }, { 4, 5 }, { 4, 2 } 
    
     
    
    Graph graph(edges, size, n);
    graph.output();
 

    return 0; 
} 

