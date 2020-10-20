#include <iostream>
#include <string> 
using namespace std;

class Number
{
    public:
    string number="0";

    

    public:
    void get_num(string num)
    {
        number = num;
    }
    void show_num()
    {
        cout<<number<<endl;
    }
    //add two NUM
    void add_num(Number Num1, Number Num2)
    {
        string num1 = Num1.number;
        string num2 = Num2.number;
        int n1 = num1.length(); 
        int n2 = num2.length();
               
        string num3;
        int carry=0;
        int i,j;
        for (i = n1-1, j = n2-1; i>=0||j>=0; i--,j--) 
        {
            char ch0='0';
            char ch1, ch2;
            int digit1 = 0;
            int digit2 = 0;
            if(i<0)
            {
                digit1=0;
            }
            else
            {
                ch1 = num1[i];
                digit1 = ch1 - '0';
            }
            
            if(j<0)
            {
                digit2 =0;
            }
            else
            {
                ch2 = num2[j];
                digit2 = ch2 - '0';
                
            }
            
            int digit3=0;
            if(carry+digit1+digit2>9)
            {
                digit3 = carry + digit1 + digit2-10;
                carry = 1;
            }
            else
            {
                digit3 = carry + digit1 + digit2;
                carry = 0;
            }            
            char ch3 = (char)(digit3+(int)ch0);
            num3.push_back(ch3);

            
        }
        if(carry==1)
        {
            num3.push_back('1');
        }
        int n3 = num3.length();
        for (int k = 0; k < n3 / 2; k++) 
            swap(num3[k], num3[n3 - k - 1]); 
        number = num3;
        
        

    }
    
    Number operator + (Number Num2)
    {
        Number Num3, Num4;
        Num3.get_num(number);
        Num4.add_num(Num3, Num2);
        return Num4;
    }
   
    void mul_num(Number Num1, Number Num2)
    {
        string num1 = Num1.number;
        string num2 = Num2.number;
        int n1 = num1.length(); 
        int n2 = num2.length();
        int i,k,j;
        
        Number Num3;
        Number NumSum;
        for(i=n1-1;i>=0;i--)
        {
            char ch1 = num1[i];
            int digit1 = ch1 - '0';
            for(j=n2-1;j>=0;j--)
            {
                char ch2 = num2[j];
                int digit2 = ch2 - '0';
                int zeroes=n2+n1-i-j-2;
                
                int mult_digit = digit1*digit2;
                
                string temp = to_string(mult_digit);
                for(k=0;k<zeroes;k++)
                {
                    temp.push_back('0');
                }
                Number Temp;
                Temp.number = temp;    
                
                NumSum.add_num(Num3, Temp);
                Num3.number=NumSum.number;
                //NumSum.show_num();
               

            }
            
        }
        number = NumSum.number;

    }
    
    Number operator * (Number Num2)
    {
        Number Num3, Num4;
        Num3.get_num(number);
        Num4.mul_num(Num3, Num2);
        return Num4;
    }
    
};

int main() {
    int num1, num2;
    int sum;
    cin>>num1>>num2;
    Number Num1;
    Number Num2;
    Number Num3;
    Number Num4;
    Number Num5;
    Number Num6;
    Num1.get_num("121");
    Num2.get_num("19");
    Num1.show_num();
    Num2.show_num();
    Num4.mul_num(Num1,Num2);
    Num3.add_num(Num1,Num2);
    
    Num3.show_num();
    Num4.show_num();
    
    Num5=Num1+Num2;
    Num6=Num1*Num2;

    Num5.show_num();
    Num6.show_num();
    
    return 0;
}
