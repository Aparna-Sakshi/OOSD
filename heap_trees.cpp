
#include <iostream>
using namespace std;
 
struct HeapElement 
{
    double value;
    HeapElement* parent;
    HeapElement* child1;
    HeapElement* child2;
};
class Heap 
{
    HeapElement* head;
public:
    Heap();
    ~Heap();
    void insert(double d); // inserts value d into the heap
    double top(); // returns the smallest element
    void pop_top(); // removes the smallest element
 
}; 

Heap::Heap()
{
     head = NULL;
}
 
Heap::~Heap()
{
    while (head != NULL)
    {
        pop_top();
    }
}
double Heap::top()
{ // returns the smallest element
    if (head != NULL)
    {
        return head->value;
    }
    else
    {
        cout << "empty heap" << endl;
        return -1;
    }
 
}

void Heap::insert(double d)
{// inserts value d into the heap
    if (head == NULL)
    {
        head = new HeapElement;
        head->value = d;
        head->parent = NULL;
        head->child1 = NULL;
        head->child2 = NULL;
    }
    else
    {
        HeapElement* new_elem_parent = head;
        HeapElement* new_elem = new HeapElement;
        double temp;
         
        //find the parent of a free position and then insert value d to this positon(a node that that has less than 2 childrend.)
        while (new_elem_parent->child1 != NULL && new_elem_parent->child2 != NULL)
        {
            if (rand() % 2 == 0)
            {
                new_elem_parent = new_elem_parent->child1;
            }
            else
            {
                new_elem_parent = new_elem_parent->child2;
            }
        }
         
        //if left child is NULL then insert to left child, else insert to right child.
        if (new_elem_parent->child1 == NULL)
        {
            new_elem_parent->child1 = new_elem;
        } 
        else
        {
            new_elem_parent->child2 = new_elem;
        }
        //insert the new value to the position new_elem.
        new_elem->parent = new_elem_parent;
        new_elem->value = d;
        new_elem->child1 = NULL;
        new_elem->child2 = NULL;
 
        while (new_elem_parent!=NULL && new_elem_parent->value > new_elem->value)
        {
            //swap the value
            temp = new_elem_parent->value;
            new_elem_parent->value = new_elem->value;
            new_elem->value = temp;
            //set to one level higher
            new_elem = new_elem_parent;
            new_elem_parent = new_elem->parent;
        }
    }
}

void Heap::pop_top()
{ 
    // removes the smallest element
    if (head == NULL)
    {
        cout << "The heap is already empty." << endl;
    }
    else if (head->child1 == NULL && head->child2 ==NULL)
    {
        cout<<head->value<<",";
        delete head;
        head = NULL;
    }
    else
    {
        HeapElement* leaf =  head;
        cout<<head->value<<",";
        //find a leaf node
        while (leaf->child1 != NULL || leaf->child2 != NULL)
        { //if it has child
            if (leaf->child1 != NULL && leaf->child2 != NULL)
            { //if has two children
                if (rand() % 2 == 0)
                {
                    leaf = leaf->child1;
                }
                else
                {
                    leaf = leaf->child2;
                }
            }
            else if (leaf->child1 != NULL)
            {
                leaf = leaf->child1;
            }
            else
            { 
                leaf = leaf->child2; 
            }
        }
         
        //cut the leaf
        if (leaf == leaf->parent->child1)
        {
            leaf->parent->child1 = NULL;
        }
        else
        { 
            leaf->parent->child2 = NULL;
        }
 
        //change head to the leaf
        leaf->parent = NULL;
        leaf->child1 = head->child1;
        leaf->child2 = head->child2;
 
        // change the parents of childs of previous head
        if (head->child1 != NULL)
        {
            head->child1->parent = leaf;
        }
        if (head->child2 != NULL)
        {
            head->child2->parent = leaf;
        }
 
        delete head;   
        head = leaf;
        //swap
        HeapElement* small_child = new HeapElement;
        double temp;
        while (leaf->child1 != NULL || leaf->child2 != NULL)
        {
            if (leaf->child1 != NULL)
            {
                small_child = leaf->child1;
                if (leaf->child2 != NULL && leaf->child2->value < leaf->child1->value)
                {
                    small_child = leaf->child2;
                }
            }
            else
            { 
                small_child = leaf->child2; 
            }
            if (leaf->value > small_child->value)
            {
                temp = small_child->value;
                small_child->value = leaf->value;
                leaf->value = temp;
            }
            leaf = small_child;
        }
 
    }
 
}    

int main()
{
    Heap heap;
        // example input
    double input[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, 28 };
    for (int i = 0; i < 20; i++)
    {
        heap.insert(input[i]);//data is inserted into an heap
    }

    return 0;
}