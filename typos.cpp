// iline.cpp
// file input with strings
#include <fstream>        //for file functions
#include <iostream>
#include<ctype.h>
#include<string>
using namespace std;


int main()
{
	const int MAX = 80; //size of buffer
	string buffer; //character buffer
	
	ifstream infile("input.txt"); //create file for input
	ofstream outfile("output.txt");//create file for output
	while( !infile.eof() ) //until end-of-file
	{
		//read a line of text
		getline(infile, buffer);
		 
		cout << buffer << endl; //display it
		int j=0;
		for (int i = 0; i < buffer.size(); i++) 
		{ 
          
	        // Finding the character whose  
	        // ASCII value fall under this 
	        // range 
	        if ((buffer[i] < '0' || buffer[i] > '9')&&buffer[i]!='.'&&buffer[i]!=',' )  
	        {    
	            // erase function to erase  
	            // the character 
	            buffer.erase(i, 1);  
	            i--; 
	        } 

    	} 
    	cout<<buffer<<endl;
		outfile<<buffer<<endl;
	}
infile.close();
outfile.close();
return 0;
}
