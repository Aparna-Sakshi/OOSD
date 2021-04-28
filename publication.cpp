#include <iostream>
#include <string>

using namespace std;
class publication
{
    private:
        string title;
        float price;
    public:
    void getdata(void)
    {
        string t;
        float p;
        cout << "Input Publication Title: ";
        cin >> t;
        cout << "Input Publication Price: ";
        cin >> p;
        title = t;
        price = p;
    }
    void putdata(void)
    {
        cout << "The title of the publication is : " << title << endl;
        cout << "The price of the publication is : " << price<<endl;
    }
};
class book :public publication
{
    private:
    int pagecount;
    public:
    void getdata(void)
    {
        publication::getdata(); 
        cout << "Input Book Page Count: "; 
        cin >> pagecount;
    }
    void putdata(void)
    {
        publication::putdata();  
        cout << "The count of the Book page is: " << pagecount << endl; 
    }
};
class tape :public publication
{
    private:
    float ptime;
    public:
    void getdata(void)
    {
        publication::getdata();
        cout << "Input playing time of tap: ";
        cin >> ptime;
    }
    void putdata(void)
    {
        publication::putdata();
        cout << "The playing time of tap is: " << ptime << endl;
    }
};
int main(void)
{
    book b;
    tape t;
    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();
    return 0;

}