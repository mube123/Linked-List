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
	void insertAtStart(int val)
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
		cout << "Value Inserted At Start...!\n";
	}
	void insertAtEnd(int val)
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = NULL;
		Node* curr = head, *prev = 0;
		while (curr != NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0) //when we are inserting very first element in a list
		{
			head = temp;
			cout << "Value Inserted At End...!\n";
		}
		else
		{
			prev->next = temp;
			cout << "Value Inserted At End...!\n";
		}
	}
	bool deleteFromStart()
	{
		if (head == NULL)
		{
			cout << "List is Empty...!\n";
			return false;
		}
		Node* curr = head;
		head = curr->next;
		delete curr;
		curr = 0;
		cout << "First Element Deleted...!\n";
		return true;
	}
	bool deleteFromEnd()
	{
		if (head == NULL)
		{
			cout << "List is Empty...!\n";
			return false;
		}
		Node* curr = head, *last = 0, *secondLast=0;
		while (curr != NULL)
		{
			secondLast = last;
			last = curr;
			curr = curr->next;
		}
		if (secondLast == 0)//When a list having only 1 element
		{
			head = NULL;
			delete last;
			last = 0;
			cout << "Last Element Deleted...!\n";
			return true;
		}
		else
		{
			secondLast->next = NULL;
			delete last;
			last = 0;
			cout << "Last Element Deleted...!\n";
			return true;
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
	bool removeSpecificValue(int val)
	{
		if (head == NULL)
		{
			cout << "List is Empty...!\n";
			return 0;
		}
		else
		{
			Node* curr = head, *prev = 0;
			while (curr != NULL && curr->data != val)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != 0)
			{
				if (prev == 0)
				{
					head = head->next;
				}
				else
				{
					prev->next = curr->next;
				}
				delete curr;
				curr = 0;
				cout <<endl<<val << " has deleted...!\n";
				return 1;
			}
			else
			{
				cout <<endl<< val << " not found...!\n";
				return 0;
			}
			
		}
	}

};
int main()
{
	LinkedList list;
	//list.insertAtStart(5);//this will be third element
	//list.insertAtStart(6);//this will be 2nd element
	//list.insertAtStart(7);//this will come first
	//list.insertAtEnd(8);//this will be fourth element
	//list.insertAtEnd(9);//this will be fifth element
	//cout << "\nElements in list are...!\n";
	//list.display(); //expected 7 6 5 8 9
	//cout << endl;
	//list.deleteFromStart();
	//cout << "\nAfter deletion the Elements in List are...!\n";
	//list.display(); //expected 6 5 8 9
	//cout << endl;
	//list.deleteFromEnd();
	//cout << "\nAfter deletion the Elements in List are...!\n";
	//list.display(); //expected 6 5 8
	//cout << endl;
	list.sortedInsert(3);
	list.sortedInsert(2);
	list.sortedInsert(4);
	cout << "\nElements in list are...!\n";
	list.display();
	list.removeSpecificValue(3);
	cout<<"\nAfter deletion the Elements in List are...!\n";
	list.display();
	list.removeSpecificValue(5);
	list.display();

	system("pause");
	return 0;
}