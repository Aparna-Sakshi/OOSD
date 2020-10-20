#include<iostream>
#include<iomanip>
#include <math.h> 
using namespace std;



class AVLtree
{
	class Node
	{
		public:	
			Node *left;
			Node *right;
			int key;
			int height;
	};
	private:
		Node* root;
	
	public:
		AVLtree()
		{	
			root=NULL;
				
		}
	
	private:
		// height of node
		int height(Node *N) 
		{ 
			if (N == NULL) 
				return 0; 
			return N->height; 
		} 
		//return max of 2 numbers
		int max(int a, int b) 
		{ 
			return (a > b)? a : b; 
		} 
		Node* newNode(int key) 
		{ 
			Node* node = new Node(); 
			node->key = key; 
			node->left = NULL; 
			node->right = NULL; 
			node->height = 1; // new node is initially 
							// added at leaf 
			return(node); 
		} 
		Node *rightRotate(Node *y) 
		{ 
			Node *x = y->left; 
			Node *T2 = x->right; 

			// Perform rotation 
			x->right = y; 
			y->left = T2; 

			// Update heights 
			y->height = max(height(y->left), 
							height(y->right)) + 1; 
			x->height = max(height(x->left), 
							height(x->right)) + 1; 

			// Return new root 
			return x; 
		} 
		Node *leftRotate(Node *x) 
		{ 
			Node *y = x->right; 
			Node *T2 = y->left; 

			// Perform rotation 
			y->left = x; 
			x->right = T2; 

			// Update heights 
			x->height = max(height(x->left),	 
							height(x->right)) + 1; 
			y->height = max(height(y->left), 
							height(y->right)) + 1; 

			// Return new root 
			return y; 
		} 
		int getBalance(Node *N) 
		{ 
			if (N == NULL) 
				return 0; 
			return height(N->left) - height(N->right); 
		} 

		//return min value in the node
		Node * minVal(Node* node) 
		{ 
			Node* current = node; 
			
			while (current->left != NULL) 
				current = current->left; 

			return current; 
		} 
		//insert element	
		Node* insert(Node* node, int key) 
		{ 
			
			if (node == NULL) 
				return(newNode(key)); 

			if (key < node->key) 
				node->left = insert(node->left, key); 
			else if (key > node->key) 
				node->right = insert(node->right, key); 
			else 
				return node; 

			
			node->height = 1 + max(height(node->left), 
								height(node->right)); 

			
			int balance = getBalance(node); 	

			// Left Left Case 
			if (balance > 1 && key < node->left->key) 
				return rightRotate(node); 

			// Right Right Case 
			if (balance < -1 && key > node->right->key) 
				return leftRotate(node); 

			// Left Right Case 
			if (balance > 1 && key > node->left->key) 
			{ 
				node->left = leftRotate(node->left); 
				return rightRotate(node); 
			} 

			// Right Left Case 
			if (balance < -1 && key < node->right->key) 
			{ 
				node->right = rightRotate(node->right); 
				return leftRotate(node); 
			} 

			
			return node; 
		} 
		//delete element
		Node* deleteNode(Node* root, int key) 
		{ 
			
			
			if (root == NULL) 
				return root; 

			
			if ( key < root->key ) 
				root->left = deleteNode(root->left, key); 

			
			else if( key > root->key ) 
				root->right = deleteNode(root->right, key); 

			
			else
			{ 
				
				if( (root->left == NULL) || 
					(root->right == NULL) ) 
				{ 
					Node *temp = root->left ? 
								root->left : 
								root->right; 

					
					if (temp == NULL) 
					{ 
						temp = root; 
						root = NULL; 
					} 
					else 
					*root = *temp; 
					free(temp); 
				} 
				else
				{ 
					
					Node* temp = minVal(root->right); 					
					root->key = temp->key; 					
					root->right = deleteNode(root->right, 
											temp->key); 
				} 
			} 

			
			if (root == NULL) 
			return root; 

			
			root->height = 1 + max(height(root->left), 
								height(root->right)); 

			
			int balance = getBalance(root); 

			
			// Left Left Case 
			if (balance > 1 && 
				getBalance(root->left) >= 0) 
				return rightRotate(root); 

			// Left Right Case 
			if (balance > 1 && 
				getBalance(root->left) < 0) 
			{ 
				root->left = leftRotate(root->left); 
				return rightRotate(root); 
			} 

			// Right Right Case 
			if (balance < -1 && 
				getBalance(root->right) <= 0) 
				return leftRotate(root); 

			// Right Left Case 
			if (balance < -1 && 
				getBalance(root->right) > 0) 
			{ 
				root->right = rightRotate(root->right); 
				return leftRotate(root); 
			} 

			return root; 
		} 
		void inorder(Node *root) 
		{ 
			if(root != NULL) 
			{ 
				inorder(root->left); 
				cout << root->key << " "; 				
				inorder(root->right); 
			} 
		} 
		void printlv(int n)
		{
			Node* temp = root;
		    int val = pow(2, height(root) -n+2);
		    cout << setw(val) << "";
		    dispLV(temp, n, val);
		}
		void dispLV(Node*p, int lv, int d)
		{
			int disp = 2 * d;
		    if (lv == 0)
		    {
		        if (p == NULL)
		        {

		            cout << " x ";
		            cout << setw(disp -3) << "";
		            return;
		        }
		        else
		        {
		            int result = ((p->key <= 1) ? 1 : log10(p->key) + 1);
		            cout << " " << p->key << " ";
		            cout << setw(disp - result-2) << "";
		        }
		    }
		    else
		    {
		        if (p == NULL&& lv >= 1)
		        {
		            dispLV(NULL, lv - 1, d);
		            dispLV(NULL, lv - 1, d);
		        }
		        else
		        {
		            dispLV(p->left, lv - 1, d);
		            dispLV(p->right, lv - 1, d);
		        }
		    }
		}

	public:
		void avl_insert(int key)
		{
			root = insert(root, key);
			cout<<"Successfully inserted "<< key<<endl;
		}

		void avl_insert(int *keyarr, int length)
		{
			for(int i=0;i<length;i++)
			{
				root = insert(root, keyarr[i]);
			}
			cout<<"Successfully inserted the given array of numbers"<<endl;
		}

		void avl_delete(int key)
		{
			root = deleteNode(root, key);
			cout<<"Successfully deleted "<<key<<endl;
		}
		//print the tree, x for gaps/ missing element
		void avl_print()
		{
			int i = 0;
		    while (i <= height(root))
		    {
		        printlv(i);
		        i++;
		        cout << endl;
		    }
		
		}
		//print elements in sorted order
		void avl_sort()
		{
			cout<<"Sorted values are:"<<endl;
			inorder(root);
			cout<<endl;
		}

};



int main()
{
	//declare an AVLtree
	AVLtree tree;
	
	while(1)
	{
		cout<<"__________MENU_________________"<<endl;
		cout<<"1. insert an element"<<endl;
		cout<<"2. insert many elements"<<endl;
		cout<<"3. delete an element"<<endl;
		cout<<"4. print AVLtree"<<endl;
		cout<<"5. see elements of the tree in sorted order"<<endl;
		cout<<"6. exit"<<endl;
		cout<<"enter your choice [1 to 6]"<<endl;
		int choice, num;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the number to be inserted"<<endl;
					cin>>num;
					tree.avl_insert(num); break;

			case 2: cout<<"Enter the number of elements to be inserted"<<endl;
					cin>>num;
					int val,i;					
					for(i=0;i<num;i++)
					{
						cin>>val;
						tree.avl_insert(val);
					}
					break;

					
			case 3: cout<<"Enter the number to be deleted"<<endl;
					cin>>num;
					tree.avl_delete(num); break;

			case 4: cout<<"Printing the tree...."<<endl;
					tree.avl_print();break;

			case 5: cout<<"Sorting the tree...."<<endl;
					tree.avl_sort();break;

			case 6: exit(0);
		}

	}
	

}
