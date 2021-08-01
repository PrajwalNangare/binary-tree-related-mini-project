#include<iostream>
using namespace std;
struct treeNode
{
	public:
	int data;
	struct treeNode* lchild;
	struct treeNode* rchild;
};
struct treeNode* root=NULL;
class Queue
{
	public:
	struct treeNode* data;
	Queue* next;
};
Queue* first=NULL;
Queue* rear=NULL;
void Enqueue(struct treeNode* data)
{
	Queue* temp=new Queue;
	if(temp==NULL)
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		temp->data=data;
		temp->next=NULL;
		if(first==NULL)
		{
			first=rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;
		}
	}
}
struct treeNode* dequeue()
{
	struct treeNode* retadd=NULL;
	if(first==NULL)
	{
		cout<<"Underflow"<<endl;
		return retadd;
	}
	else
	{
		Queue* temp=first;
		first=first->next;
		retadd=temp->data;
		delete(temp);
	}
	return retadd;
}
bool isEmptyQueue()
{
	return first==NULL;
}
void preorder(struct treeNode* ptr)
{
	if(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void inorder(struct treeNode* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		cout<<ptr->data<<" ";
		inorder(ptr->rchild);
	}
}
void postorder(struct treeNode* ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		cout<<ptr->data<<" ";
	}
}
void Levelorder(struct treeNode* ptr)
{
	if(ptr==NULL)
	{
		cout<<"Empty";
	}
	else
	{
		cout<<ptr->data<<" ";
		Enqueue(ptr);
	    while(ptr!=NULL && isEmptyQueue()!=true)
		{
			ptr=dequeue();
			if(ptr!=NULL)
			{
			   if(ptr->lchild!=NULL)
			   {
				  cout<<ptr->lchild->data<<" ";
				  Enqueue(ptr->lchild);
			   }
			   if(ptr->rchild!=NULL)
			   {
				  cout<<ptr->rchild->data<<" ";
				  Enqueue(ptr->rchild);
			   }
		    }
		}
	}
}
void DisplayTree()
{
	Queue *ptr=first;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}
int CountNodeWhoseDegreeIsZero(struct treeNode* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountNodeWhoseDegreeIsZero(ptr->lchild);
		y=CountNodeWhoseDegreeIsZero(ptr->rchild);
		if(ptr->lchild==NULL && ptr->rchild==NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
}
int CountNodeWhoseDegreeIsOne(struct treeNode* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountNodeWhoseDegreeIsOne(ptr->lchild);
		y=CountNodeWhoseDegreeIsOne(ptr->rchild);
		if((ptr->lchild!=NULL && ptr->rchild==NULL)||(ptr->lchild==NULL && ptr->rchild!=NULL))
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
}
int CountNodeWhoseDegreeIsOneandTwo(struct treeNode* ptr)
{
    int x,y;

    if(ptr==NULL)
    {
        return 0;
    }
    
    else
    {
      x=CountNodeWhoseDegreeIsOneandTwo(ptr->lchild);
      y=CountNodeWhoseDegreeIsOneandTwo(ptr->rchild);

      if(ptr->lchild!=NULL || ptr->rchild!=NULL)
      {
          return x+y+1;
      }
      else
      {
          return x+y;
      }
    }
}
int CountNodeWhoseDegreeIsTwo(struct treeNode* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountNodeWhoseDegreeIsTwo(ptr->lchild);
		y=CountNodeWhoseDegreeIsTwo(ptr->rchild);
		if(ptr->lchild!=NULL && ptr->rchild!=NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
}
int Counttotalnodeintree(struct treeNode* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=Counttotalnodeintree(ptr->lchild);
		y=Counttotalnodeintree(ptr->rchild);
		return x+y+1;
	}
	
}
int main()
{
	
	int data;
	char side;
	while(true)
	{
		cout<<"*******Welcome to the tree  based project*******"<<endl;
		cout<<"Create tree"<<endl;
		cout<<"the inorder of the tree is"<<endl;
		cout<<"the preorder of the tree is"<<endl;
		cout<<"the postorder of the tree is"<<endl;
		cout<<"the Levelorder of the tree is"<<endl;
		cout<<"count total node in tree is"<<endl;
		cout<<"count two child node in tree is"<<endl;
		cout<<"count one child node in tree is"<<endl;
		cout<<"count zero child node in tree is"<<endl;
		cout<<"count both one and two node in tree is"<<endl;
		cout<<"Exit"<<endl;
		cout<<"----------------------------"<<endl;
		int choice;
		cout<<"enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				int data;
				char side;
			    cout<<"Do You Wants Enter More Data(Y/N):";
		        char ch;
		        cin>>ch;
		        if(ch=='Y')
		        {
			      if(root==NULL)
			      {
				      struct treeNode *temp=new treeNode;
				      if(temp==NULL)
				      {
					     cout<<"Overflow";
					     return 0;
				      }
				      else
				      {
					     cout<<"Enter The Data For the Root Node:";
					     cin>>temp->data;
					     temp->lchild=temp->rchild=NULL;
					     root=temp;
					     Enqueue(temp);
					    
				      }
			      }
			      else
			      {
				     struct treeNode *t=dequeue();
				     char ch;
				     cout<<"Do you want to enter the Data at the Lside<<of:"<<t->data<<"(Y/N)";
				     cin>>ch;
				     //Left Child Insertion
				     if(ch=='Y')
				     {
					    struct treeNode *temp=new treeNode;
					    if(temp==NULL)
					    {
						   cout<<"Overflow"<<endl;
						   return 0;
					    }
					    else
					    {
						   cout<<"Enter the Left Child Data:";
						   cin>>temp->data;
						   temp->lchild=temp->rchild=NULL;
						   t->lchild=temp;
						   Enqueue(temp);
						  
					    }
				     }
				     //Right Child Insertion
				     cout<<"Do you wants to enter the Data at the Rside<<of:"<<t->data<<"(Y/N)";
				     cin>>ch;
				     if(ch=='Y')
				     {
					    struct treeNode *temp=new treeNode;
					    if(temp==NULL)
					    {
						   cout<<"Overflow"<<endl;
						   return 0;
					    }
					    else
					    {
						  cout<<"Enter the Right Child Data:";
						  cin>>temp->data;
						  temp->lchild=temp->rchild=NULL;
						  t->rchild=temp;
						  Enqueue(temp);
						  
					    }
				     }
			      }
		        }
		        else if(ch=='N')
		        {
		        	break;
		        }
	        }
	        break;
	        case 2:
			{
				cout<<"the inorder is:";
				inorder(root);
				cout<<endl;
			}
			break;
			case 3:
			{
				cout<<"the preorder is:";
				preorder(root);
				cout<<endl;
			}
			break;
			case 4:
			{
				cout<<"the postorder is:";
				postorder(root);
				cout<<endl;
			}
			break;
			case 5:
			{
				cout<<"the Levelorder is:";
				Levelorder(root);
				cout<<endl;
			}
			break;
			case 6:
			{
				cout<<"the count total node in tree is:";
				cout<<Counttotalnodeintree(root);
				cout<<endl;
			}
			break;
			case 7:
			{
				cout<<"the count two child node in tree is:";
				cout<<CountNodeWhoseDegreeIsTwo(root);
				cout<<endl;
			}
			break;
			case 8:
			{
				cout<<"the count zero child node in tree is:";
				cout<<CountNodeWhoseDegreeIsZero(root);
				cout<<endl;
			}
			break;
			case 9:
			{
				cout<<"the count one child node in tree is:";
				cout<<CountNodeWhoseDegreeIsOne(root);
				cout<<endl;
			}
			break;
			case 10:
			{
				cout<<"the count both one and two node in tree is:";
				cout<<CountNodeWhoseDegreeIsOneandTwo(root);
				cout<<endl;
			}
			break;
			default:
			{
				cout<<"wrong input";
				break;
			}
			
	    }
	}
}
