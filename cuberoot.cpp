#include <iostream> 

using namespace std;   


double abs(double n,double mid) 
{ 

    if (n > (mid*mid*mid)) 
    {
        return (n-(mid*mid*mid)); 
    }      

    else
    {
        return ((mid*mid*mid) - n); 
    }

        
} 

  


double cubic_root(double n) 
{   

    double start = 0, end = n; 
    double e = 0.0000001;

    while (true) 

    { 

        double mid = (start + end)/2; 
        double error = abs(n, mid); 

  

        if (error <= e) 
        {
            return mid;  
        }

        if ((mid*mid*mid) > n) 
        {
            end = mid;  
        }
        else
        {
            start = mid; 
        }

    } 
} 

  


int main() 
{ 

    double n; 
    cin<<n;
    cout<<"Cube root of n is "<<cubic_root(n);     

    return 0; 
} 