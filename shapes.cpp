#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
    public:
    virtual float perimeter()
    {
        return 0;
    }
    virtual float area()
    {
        return 0;
    }
    float distance(int x1, int y1, int x2, int y2) 
    { 
        // Calculating distance 
        return sqrt(pow(x2 - x1, 2) +  
                    pow(y2 - y1, 2) * 1.0); 
    } 
};

class Circle : public Shape
{
    public:
    float radius;
    float x,y;//coordinates of center of circle
    Circle(float x1, float y1, float r)
    {
        radius = r;
        x = x1;
        y = y1;
    }
    float perimeter()
    {
        return 3.14*2*radius;//2*pi*r
    }
    float area()
    {
        return 3.24*radius*radius;//pi*r*r
    }
};

class Triangle : public Shape
{
    public:
    float x1,y1,x2,y2,x3,y3;//coordinates of 3 vertices of triangle
    Triangle(float a1, float b1, float a2, float b2, float a3, float b3 )
    {
        
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;
        x3 = a3;
        y3 = b3;
    }
    float perimeter()
    {
        return distance(x1,y1,x2,y2)+distance(x2,y2,x3,y3)+distance(x1,y1,x3,y3);
    }
    float area()
    {
        return abs(x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2)*0.5;
        //area of triangle given 3 vertices
    }
};
class Square : public Shape
{
    public:
    float x1,y1,x2,y2;//coordinates of 3 vertices of triangle
    Square(float a1, float b1, float a2, float b2 )
    {
        
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;
        
    }
    float perimeter()
    {
        return distance(x1,y1,x2,y2)*2*1.414;//2*sqrt(2)*d
    }
    float area()
    {
        return distance(x1,y1,x2,y2)*distance(x1,y1,x2,y2)*0.5;//d*d*0.5
    }

};
int main()
{
    Shape *shapes[3];
    shapes[0] = new Circle(0, 0, 1);//(0,0), r=1
    shapes[1] = new Triangle(1,0,0,0,0,1);//(1,0),(0,0),(0,1)
    shapes[2] = new Square(0,0, 1,1);//(0,0),(1,1)

    cout<<"Circle: area ="<<shapes[0]->area()<<" perimeter="<<shapes[0]->perimeter()<<endl;
    cout<<"Triangle: area ="<<shapes[1]->area()<<" perimeter="<<shapes[1]->perimeter()<<endl;
    cout<<"Square: area ="<<shapes[2]->area()<<" perimeter="<<shapes[2]->perimeter()<<endl;

    return 0;
}
