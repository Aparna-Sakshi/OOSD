#include <bits/stdc++.h>
using namespace std;

//generates a boolean list of size n-1. 
void partitionListGenerator(int n, int c)
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
    int prev=0;
    cout<<"{";
    for(i=0;i<n;i++)
    {
        if(bool_list[i])
        {
            cout<<((i+1)-prev)<<",";
            prev=i+1;
        }
    }
    
    if(n-prev)
    {
        cout<<(n-prev)<<"}"<<endl;
    }
    
    free( bool_list);
}
int main()
{
    int n = 4;
    for(int i=0;i<pow(2,n-1);i++)
    {
        partitionListGenerator(n, i);
    }
    return 0;
}