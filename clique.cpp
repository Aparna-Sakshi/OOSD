 
#include <bits/stdc++.h> 
using namespace std; 

class Graph
{
    
    public:
    // dynamic array to store the vertices if they can form clique
    int *dp, *dp_, n; 
    
    // AdjacencyMatrix
    int **AdjacencyMatrix; 
    
    // Degree of the vertices 
    int* d; 
    bool flag;
    
    
    Graph(int* edges[], int no_of_edges, int no_of_vertices)
    {
        n=no_of_vertices;
        d=(int*)malloc(sizeof(int)*(n+1));
        AdjacencyMatrix = (int**)malloc(sizeof(int*)*(n+1));
        for(int i=0;i<=n; i++)
        {
            AdjacencyMatrix[i] = (int*)malloc(sizeof(int)*(n+1));
        }
        for (int i = 0; i < no_of_edges; i++) 
        { 
            
            AdjacencyMatrix[edges[i][0]][edges[i][1]] = 1; 
            AdjacencyMatrix[edges[i][1]][edges[i][0]] = 1; 
            d[edges[i][0]]++; 
            d[edges[i][1]]++; 
            
        } 
        
        dp=(int*)malloc(sizeof(int)*(n+1));
        dp_=(int*)malloc(sizeof(int)*(n+1));
        flag = true;
        

    }
    
    
    //check if the vertices form clique or not
    bool checkClique(int b) 
    { 
    
        // Run a loop for all set of edges 
        for (int i = 1; i < b; i++) 
        { 
            for (int j = i + 1; j < b; j++) 
            {
    
                // If any edge is missing 
                if (AdjacencyMatrix[dp[i]][dp[j]] == 0) 
                {
                    return false; 
                }
            }
        } 
        return true;
        
    }
    bool checkClique_(int b) 
    { 
    
        // Run a loop for all set of edges 
        for (int i = 1; i < b; i++) 
        { 
            for (int j = i + 1; j < b; j++) 
            {
    
                // If any edge is missing 
                if (AdjacencyMatrix[dp_[i]][dp_[j]] == 0) 
                {
                    return false; 
                }
            }
        } 
        return true;
        
    }
    
    // Find maximalClique
    int maximalClique(int i, int l) 
    { 
        // Maximal clique size 
        int currmax = 0; 
    
        // Check if any vertices from i+1 can be inserted or not  
        for (int j = i + 1; j <= n; j++) 
        { 
    
            // Add the vertex to dp 
            dp[l] = j; 
    
            // check if it is a clique of size l
            if (checkClique(l + 1))
            { 
                
                // if it is clique and its' size is greater than currmax then update
                if(l > currmax)
                {
                    currmax = l;
                }
                
                // Check for maximalClique of size l+1
                int nextmax = maximalClique(j, l + 1);
                if(nextmax > currmax)
                {
                    currmax = nextmax;
                }                
                
            } 
        } 
        
        return currmax; 
        
        
    } 
    
    // Find maximalClique
    int printMaximalCliques(int i, int l, int maxlen) 
    { 
        // Maximal clique size 
        int currmax = 0; 
    
        // Check if any vertices from i+1 can be inserted or not  
        for (int j = i + 1; j <= n; j++) 
        { 
    
            // Add the vertex to dp 
            dp_[l] = j; 
    
            // check if it is a clique of size l
            if (checkClique_(l + 1))
            { 
                  
                // if it is clique and its' size is greater than currmax then update
                if(l > currmax)
                {
                    currmax = l;
                }
                //if it the maximal clique then print it
                if(currmax==maxlen && flag)
                {
                    for(int jj=1; jj<=currmax; jj++)
                    {
                        cout<<dp_[jj]<<",";
                    }
                    flag = false;
                }  
                // Check for maximalClique of size l+1
                int nextmax = printMaximalCliques(j, l + 1, maxlen);
                if(nextmax > currmax)
                {
                    currmax = nextmax;
                }   
                         
                
            } 
        } 
        
        
        return currmax; 
        
        
    } 
    
    
    void printMaximalClique()
    {
        int currmax = maximalClique(0, 1);
        cout <<"Size of maximalClique is: " <<currmax<<endl;
        cout<<"Vertices of the graph which forms maximalClique is "<<endl;
        flag=true;
        printMaximalCliques(0, 1, currmax);   
        
        
    }
    
    
     
};

int main() 
{ 
    int **edges;
    int size = 6; 
    int n = 8;//vertices are 1 to 7
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
    graph.printMaximalClique();
 

    return 0; 
} 
