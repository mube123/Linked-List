#include<iostream>
using namespace std;
class LinkedList;
class Node
{
	friend class LinkedList;
private:
	int data;
	Node* next;
};
class LinkedList
{
private:
	Node* head;
public:
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{
		if (head == NULL)
		{
			//do nothing because list is empty.....!
		}
		else
		{
			Node* curr;
			while (head != NULL)
			{ 
				curr = head;
				head = curr->next;
				delete curr;
			}
		}
	}
	void display()
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}	
	bool sortedInsert(int val)
	{
		Node* temp = new Node;
		temp->data = val;
		Node* curr = head, *prev = 0;
		while (curr != NULL && curr->data<val)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0)
		{
			head = temp;
		}
		else
		{
			prev->next = temp;
		}
		temp->next = curr;
		cout << "Element is inserted in Sorted Linked List...!\n";
		return 1;
	}
	
	//splitlist function
	int splitlist()
	{
		int key,val;
		cout<<"Enter the value from where the list have to be splited: ";
		cin>>val;
		if (head == NULL)
		{
			cout << "List is Empty...!\n";
			return 0;
		}
		else
		{
			Node* curr = head, *next = 0;
				
			
			cout<<"List 1: ";
			while(curr->data <= val )
			{
				cout<<curr->data;
				curr = curr->next;
				cout<<" ";
			}
		
			cout<<endl<<"List 2: ";
			while(curr!=NULL)
			{
				next = curr;
				cout<<next->data;
				curr = curr->next;
				cout<<" ";
			}		
		}
	}

};
int main()
{
	LinkedList list;
	list.sortedInsert(3);
	list.sortedInsert(2);
	list.sortedInsert(4);
	list.sortedInsert(8);
	list.sortedInsert(5);
	list.sortedInsert(7);
	list.sortedInsert(10);
	list.sortedInsert(43);
	list.sortedInsert(1);
	list.sortedInsert(9);
	cout << "\nElements in list are...!\n";
	list.display();
	cout<<endl;
	list.splitlist();
	
	//system("pause");
	return 0;
}
