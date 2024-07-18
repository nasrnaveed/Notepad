#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
using namespace std;

struct Node
{
	char data;
	Node* right;
	Node* left;
	Node* top;
	Node* bottom;
};
Node* head, * tail, * topHead, * leftHead;
Node** arr = new Node * [1000];
int row = 0;
Node* newNode(char d)
{
	Node* temp = new Node;
	temp->data = d;
	if (head == NULL)
		head = tail = temp;
	return temp;
}
void upDown()
{
	topHead = arr[row - 1];
	leftHead = head;
}
void line(char d)
{
	Node* t = newNode(d);
	tail->right = t;
	t->left = tail;
	tail = t;
	if (row != 0 && topHead != NULL)
	{
		t->top = topHead;
		topHead->bottom = t;
		topHead = topHead->right;
	}
}
void rowsArray()
{
	arr[row] = head;
	head = tail = NULL;
	row++;
}
void save(char d)
{
	if (d != '0')
	{
		ofstream writing("notepad.txt", ios::app);
		writing << d;
	}
}
void read()
{
	string text;
	ifstream reading("notepad.txt");
	while (getline(reading, text))
		cout << text << endl;
}
char text{};
void input()
{
	system("CLS");
	cout << "\n----------------------------------------------\n";
	cout << "\t\tPRESS X TO STOP.";
	cout << "\n----------------------------------------------\n";
	cout << "Enter text : " << endl;
	while (true)
	{
		text = _getch();
		if (text == 'X')
			break;
		else if (text == '\r')
		{
			cout << endl;
			save('\n');
			text = _getch();
			cout << text;
			rowsArray();
			upDown();
			line(text);
			save(text);
		}
		else
		{
			cout << text;
			line(text);
			save(text);
		}
	}
}
int main()
{
	char c = 'y', i;
	do
	{
		system("CLS");
		cout << "To Enter New Text Press N." << endl;
		cout << "To Read Old Text Press O." << endl;
		cout << "Enter Choice : "; cin >> i;
		switch (i)
		{
		case'N':
		case'n':
			input();
			break;
		case'O':
		case'o':
			read();
			break;
		}
		cout << "To Continue Press Y else Press X : "; cin >> c;
	} while (c=='y'||c=='Y');
	cout << "\n----------------------------------------------\n";
	cout << "\t\t THANK YOU ";
	cout << "\n----------------------------------------------\n";
	system("pause");
	return 0;
}
