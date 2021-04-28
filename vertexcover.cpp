

#include <bits/stdc++.h>
using namespace std;
//Vertex class
class Vertex
{
    public:
    int x;
    int y;
};
//Graph class
class Graph
{
    public:
    int n;//no_of_vertices 1-based
    int size;//no_of_egdes
    Vertex *edges;

    Graph(Vertex *arr, int no_of_vertices, int no_of_egdes)
    {
        n = no_of_vertices;
        size = no_of_egdes;
        edges = (Vertex*)malloc(sizeof(Vertex)*size);
        for(int i=0;i<size;i++)
        {
            edges[i].x=arr[i].x;
            edges[i].y=arr[i].y;
        }
    }

    //Generate subset of vertices
    bool* subsetListGenerator(int n, int c)
    {
        bool *bool_list = (bool*)malloc(sizeof(bool)*n);
        int i,k;
        for(k=c,i=0;i<n;k/=2,i++)
        {
            if(k%2==1)
            {
                bool_list[i] = true;
            }
            else
            {
                bool_list[i] = false;
            }
        }
        return bool_list;
    }

    int minimalVertexCover()
    {
        int edges_covered = 0;
        int minlen = n;
        //iterate through each subset of vertices
        for(int i=0;i<pow(2,n);i++)
        {
            bool *vertices;
            vertices = subsetListGenerator(n,i);
            edges_covered = 0;//find the number of edge it covers
            for(int ii=0;ii<n;ii++)
            {
                if(!vertices[ii])
                {
                    continue;
                }
                for(int j=0;j<size;j++)
                {
                    if(edges[j].x==(ii+1)||edges[j].y==(ii+1))
                    {
                        edges_covered++;
                    }
                }
            }
            //check if all edges are covered or not
            if(edges_covered == size)
            {
                int len =0;
                
                for(int iii=0; iii<n; iii++)
                {
                    if(vertices[iii])
                    {
                        
                        len++;
                    }
                }
                if(len<minlen)
                {
                    minlen = len;
                }
            }
            free(vertices);
        }
        //return minimum number of edges it covers
        return minlen;
        
    }

    //this function is same as above function
    //given the minimum number of edges backtrack to find a solution and then print
    void printMinimalVertexCover(int minlen)
    {
        int edges_covered = 0;
        for(int i=0;i<pow(2,n);i++)
        {
            bool *vertices;
            vertices = subsetListGenerator(n,i);
            edges_covered = 0;
             //iterate through each subset of vertices
            for(int ii=0;ii<n;ii++)
            {
                if(!vertices[ii])
                {
                    continue;
                }
                for(int j=0;j<size;j++)
                {
                    if(edges[j].x==(ii+1)||edges[j].y==(ii+1))
                    {
                        edges_covered++;
                    }
                }
            }
            //check if all edges are covered or not
            if(edges_covered == size)
            {
                int len =0;
                for(int iii=0; iii<n; iii++)
                {
                    if(vertices[iii])
                    {                        
                        len++;
                    }
                }
                //check if the edge covering subset is of minimum length
                if(len == minlen)
                {
                	//if it is of minimum length then print it
                    cout<<"minimalVertexCover is:"<<endl;
                    for(int iii=0; iii<n; iii++)
                    {
                        if(vertices[iii])
                        {
                            cout<<(iii+1)<<",";
                            len++;
                        }
                    }
                    cout<<endl<<"minimal size of vertex cover is "<<minlen<<endl;

                    break;
                }
                
            }
            free(vertices);
        }
        
    }

    void output()
    {
        int minlen = minimalVertexCover();
        printMinimalVertexCover(minlen);
    }

};

int main()
{
	//array of edges
    Vertex arr[] = {{ 1, 4 }, { 4, 3 }, { 3, 1 },{ 5, 3 }, { 4, 5 }, { 4, 2 }};
    int no_of_vertices = 5;
    int no_of_egdes = 6;
    Graph graph(arr, no_of_vertices, no_of_egdes);
    graph.output();
    return 0;
}
