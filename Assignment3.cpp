#include<iostream>
using namespace std;

struct n
{
	string name;
	n *ptrChld[10];
	int count;
}*root;
n* create(n *head)
{
	char name[30];
	int c, s, ss;
	cout<<"Enter book name : ";
	cin>>name;
	struct n *ptr = new n();
	ptr->name = name;
	root = ptr;
	cout<<"How many chapters? : ";
	cin>>c;
	root->count = c;
	for(int i=0; i<c; i++) //For chapters
	{
		cout<<"Enter chapter name : ";
		cin>>name;
		struct n *ptr = new n();
		ptr->name = name;
		root->ptrChld[i] = ptr;
		cout<<"How many sections? : ";
		cin>>s;
		root->ptrChld[i]->count = s;
		for(int j=0; j<s; j++)
		{
			cout<<"Enter section name : ";
			cin>>name;
			struct n *ptr = new n();
			ptr->name = name;
			root->ptrChld[i]->ptrChld[j] = ptr;
			cout<<"How many sub-sections? : ";
			cin>>ss;
			root->ptrChld[i]->ptrChld[j]->count = ss;
			for(int k=0; k<s; k++)
			{
				cout<<"Enter sub - section name : ";
				cin>>name;
				struct n *ptr = new n();
				ptr->name = name;
				root->ptrChld[i]->ptrChld[j]->ptrChld[k] = ptr;
			}
		}
	}
	return root;
}
void display(n *head)
{
	cout<<"########################### Book ############################\n";
	cout<<"Name of the book : ";
	cout<<head->name<<endl;
	for(int i=0; i<4; i++)
	{
		cout<<"|\n";
	}
	cout<<"---> Chapters : \n";
	for(int i=0; i<4; i++)
	{
		cout<<"\t|\n";
	}
	for(int i=0;i<head->count;i++)
	{
		cout<<"\t---> Chapter "<<(i+1)<<" : "<<head->ptrChld[i]->name<<endl;
		for(int j=0; j<head->ptrChld[i]->count;j++)
		{
			cout<<"\t---> Section "<<(i+1)<<" : "<<head->ptrChld[i]->ptrChld[j]->name<<endl;
			for(int k=0; k<head->ptrChld[i]->ptrChld[j]->count;k++)
			{
				cout<<"\t---> Section "<<(i+1)<<" : "<<head->ptrChld[i]->ptrChld[j]->ptrChld[k]->name<<endl;
			}
		}
	}
}
int main()
{
	root = NULL;
	root = create(root);
	display(root);
}
