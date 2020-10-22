#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id;
	char name[50];
	char qual[30];
	char addres[50];
	char city[30];
	char jobtitle[30];
	char date[30];
	int salary;
	node *prev,*next;
};
class employee
{
	private:
		node *head;
		char ch;
	public:
		employee(){
			head = NULL;
		}
		void menu(){
			cout<<"\n\t\t\t WELCOME TO THE EMPLOYEE MANAGEMENT SYSTEM"<<endl;
			cout<<"\n\t\t\t\t 1.Add a Record"<<endl;
			cout<<"\n\t\t\t\t 2.Search a Record"<<endl;
			cout<<"\n\t\t\t\t 3.Update a Record"<<endl;
			cout<<"\n\t\t\t\t 4.Delete a Record"<<endl;
			cout<<"\n\t\t\t\t 5.Display a Record"<<endl;
			cout<<"\n\t\t\t\t 6.Exit"<<endl;
			return;
		}
		void add_primary(){										//---------------function to add node in the beginning
			node *newer = new node;
			cout<<"\n\t\tEnter the Employee Id:";
			cin>>newer->id;
			fflush(stdin);                                      //-----------------helps to clear the buffer
			cout<<"\n\t\tEnter the name of Employee:";
			cin.getline(newer->name,50);
			fflush(stdin);
			cout<<"\n\t\tEnter the Employee's Qualification:";
			cin.getline(newer->qual,30);
			fflush(stdin);
			cout<<"\n\t\tEnter the Employee's Address:";
			cin.getline(newer->addres,50);
			fflush(stdin);
			cout<<"\n\t\tEnter the City:";
			cin.getline(newer->city,30);
			fflush(stdin);
			cout<<"\n\t\tEnter the Employee's Job Title:";
			cin.getline(newer->jobtitle,30);
			fflush(stdin);
			cout<<"\n\t\tEnter the Salary:";
			cin>>newer->salary;
			fflush(stdin);
			cout<<"\n\t\tEnter the Start Date:";
			cin.getline(newer->date,30);
			fflush(stdin);
			newer->next=head;
			newer->prev=NULL;
			if(head!=NULL){
				head->prev=newer;
			}
			head = newer;
			cout<<"\n\t\tRecord is Inserted Successfully!!!";	
		}
		
		void add_sec()												//--------------function to add node at last
		{
			if(head==NULL){
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);                      //-------------------abnormal termination either some error or interrupt occur
				}	
			}
			else
			{
				node *temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				node *newer= new node;
				fflush(stdin);
				cout<<"\n\t\tEnter the Employee Id:";
				cin>>newer->id;
				fflush(stdin);
				cout<<"\n\t\tEnter the name of Employee:";
				cin.getline(newer->name,50);
				fflush(stdin);
				cout<<"\n\t\tEnter the Employee's Qualification:";
				cin.getline(newer->qual,30);
				fflush(stdin);
				cout<<"\n\t\tEnter the Employee's Address:";
				cin.getline(newer->addres,50);
				fflush(stdin);
				cout<<"\n\t\tEnter the City:";
				cin.getline(newer->city,30);
				fflush(stdin);
				cout<<"\n\t\tEnter the Employee's Job Title:";
				cin.getline(newer->jobtitle,30);
				fflush(stdin);
				cout<<"\n\t\tEnter the Salary:";
				cin>>newer->salary;
				fflush(stdin);
				cout<<"\n\t\tEnter the Start Date:";
				cin.getline(newer->date,30);
				fflush(stdin);
				newer->next=NULL;
				temp->next=newer;
				newer->prev=temp;
			}
		}
		void add_after()
		{
			if(head==NULL)
			{
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);
				}		
			}
			else
			{
				int val;                                     //----------store the value for which node after u want insert
				cout<<"\n\t\tEnter the id after which you want to add a new record:";
				cin>>val;
				bool flag=false;
				node *temp=head;
				node *p;
				while(temp!=NULL){
					if(temp->id==val){
						node *newer = new node;
						fflush(stdin);
						cout<<"\n\t\tEnter the Employee Id:";
						cin>>newer->id;
						fflush(stdin);
						cout<<"\n\t\tEnter the name of Employee:";
						cin.getline(newer->name,50);
						fflush(stdin);
						cout<<"\n\t\tEnter the Employee's Qualification:";
						cin.getline(newer->qual,30);
						fflush(stdin);
						cout<<"\n\t\tEnter the Employee's Address:";
						cin.getline(newer->addres,50);
						fflush(stdin);
						cout<<"\n\t\tEnter the City:";
						cin.getline(newer->city,30);
						fflush(stdin);
						cout<<"\n\t\tEnter the Employee's Job Title:";
						cin.getline(newer->jobtitle,30);
						fflush(stdin);
						cout<<"\n\t\tEnter the Salary:";
						cin>>newer->salary;
						fflush(stdin);
						cout<<"\n\t\tEnter the Start Date:";
						cin.getline(newer->date,30);
						fflush(stdin);
						if(temp->next!=NULL)
						{
							newer->next=temp->next;
							newer->prev=temp;
							p=temp->next;
							p->prev=newer;
							temp->next=newer;
						}
						else
						{
							newer->next=temp->next;
							newer->prev=temp;
							temp->next=newer;
						}
						flag=true;
					}
					temp=temp->next;
				}
				if(flag==false)
				{
					cout<<"\n\t\tId is not found"<<endl;
				}
			}
		}
		void add_before()
		{
			if(head==NULL){
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);
				}			
			}
			else
			{
				int val;
				cout<<"\n\t\tEnter the id before which you want to add a new record:";
				cin>>val;
				bool flag=false;
				node *temp=head;
				if(temp->id==val)
				{
					add_primary();
					return;
				}
				else
				{
					while(temp!=NULL){
						
						if(temp->id==val){
							node *newer = new node;
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee Id:";
							cin>>newer->id;
							fflush(stdin);
							cout<<"\n\t\tEnter the name of Employee:";
							cin.getline(newer->name,50);
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee's Qualification:";
							cin.getline(newer->qual,30);
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee's Address:";
							cin.getline(newer->addres,50);
							fflush(stdin);
							cout<<"\n\t\tEnter the City:";
							cin.getline(newer->city,30);
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee's Job Title:";
							cin.getline(newer->jobtitle,30);
							fflush(stdin);
							cout<<"\n\t\tEnter the Salary:";
							cin>>newer->salary;
							fflush(stdin);
							cout<<"\n\t\tEnter the Start Date:";
							cin.getline(newer->date,30);
							fflush(stdin);
							newer->next=temp;
							newer->prev=temp->prev;
							node *p;
							p=temp->prev;
							p->next=newer;
							temp->prev=newer;
							flag=true;	
						}
						temp=temp->next;
					}
					if(flag==false){
						cout<<"\n\t\\tRecord is not founded"<<endl;
					}
				}			
			}
		}
		void del()
		{
			if(head==NULL){
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);
				}			
			}
			else
			{
				int val;
				cout<<"\n\t\tEnter the employee id which u want to delete:";
				cin>>val;
				node *temp=head;
				bool flag= false;
				if(temp->id == val)
				{
					head= temp->next;
					head->prev=NULL;
					flag=true;
					delete temp;
					if(flag==true){
						cout<<"\n\t\tRecord has deleted successfully"<<endl;
					}
				}
				else
				{
					while(temp!=NULL)
					{
						if(temp->id==val){
							node *p, *q;
							if(temp->next==NULL){
								p=temp->prev;
								p->next=NULL;
								flag=true;
								delete temp;
							}
							else{
								p=temp->prev;
								q=temp->next;
								p->next=q;
								q->prev=p;
								flag=true;
								delete temp;
							}
						}
						temp=temp->next;
					}
					if(flag==false){
						cout<<"\n\t\tValue is not found"<<endl;
					}
					else{
						cout<<"\n\t\tRecord deleted.."<<endl;
					}
				}	
			}		
		}
		void show()
		{
			if(head==NULL)
			{
				
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);
				}			
			}
			else
			{
				node *temp=head;
				while(temp!=NULL)
				{
					cout<<"\n\t\tInformation of employee"<<endl;
					cout<<"\n\t\t ID:"<<temp->id<<endl;
					cout<<"\n\t\t NAME:"<<temp->name<<endl;
					cout<<"\n\t\t QUALIFICATION:"<<temp->qual<<endl;
					cout<<"\n\t\t ADDRESS:"<<temp->addres<<endl;
					cout<<"\n\t\t CITY:"<<temp->city<<endl;
					cout<<"\n\t\t JOB TITLE:"<<temp->jobtitle<<endl;
					cout<<"\n\t\t SALARY:"<<temp->salary<<endl;
					cout<<"\n\t\t STARTING DATE:"<<temp->date<<endl;
					
					temp=temp->next;
				}	
			}	
		}
		void search()
		{
			if(head==NULL)
			{
				
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);
				}			
			}
			else
			{
				int val;
				cout<<"\n\t\tEnter employee id which u want to search:";
				cin>>val;
				node *temp=head;
				bool flag = false;
				while(temp!=NULL)
				{
					if(temp->id==val)
					{
					cout<<"\n\t\tInformation of employee"<<endl;
					cout<<"\n\t\t ID:"<<temp->id<<endl;
					cout<<"\n\t\t NAME:"<<temp->name<<endl;
					cout<<"\n\t\t QUALIFICATION:"<<temp->qual<<endl;
					cout<<"\n\t\t ADDRESS:"<<temp->addres<<endl;
					cout<<"\n\t\t CITY:"<<temp->city<<endl;
					cout<<"\n\t\t JOB TITLE:"<<temp->jobtitle<<endl;
					cout<<"\n\t\t SALARY:"<<temp->salary<<endl;
					cout<<"\n\t\t STARTING DATE:"<<temp->date<<endl;
					flag=true;
					return;
					}
					temp=temp->next;
				}
				if(flag==false){
					cout<<"\n\t\tID ENTERED IS NOT IN DATABASE,PLEASE ENTER CORRECT ID..."<<endl;
				}
			}
		}
		void update()
		{
			if(head==NULL)
			{
				
				cout<<"\n\t\tLinked List is Empty... ";
				cout<<"\n\t\tAdd a New Record\n\tPress Y or N:";
				cin>>ch;
				if(ch=='Y' || ch=='y')
				{
					add_primary();
					return;
				}
				else{
					exit(1);
				}			
			}
			else
			{
				int val;
				cout<<"\n\t\tEnter employee id whose record u want to update:";
				cin>>val;
				node *temp = head;
				bool flag = false;
				while(temp!=NULL){
					if(temp->id==val){
						fflush(stdin);
							cout<<"\n\t\tEnter the Employee Id:";
							cin>>temp->id;
							fflush(stdin);
							cout<<"\n\t\tEnter the name of Employee:";
							cin.getline(temp->name,50);
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee's Qualification:";
							cin.getline(temp->qual,30);
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee's Address:";
							cin.getline(temp->addres,50);
							fflush(stdin);
							cout<<"\n\t\tEnter the City:";
							cin.getline(temp->city,30);
							fflush(stdin);
							cout<<"\n\t\tEnter the Employee's Job Title:";
							cin.getline(temp->jobtitle,30);
							fflush(stdin);
							cout<<"\n\t\tEnter the Salary:";
							cin>>temp->salary;
							fflush(stdin);
							cout<<"\n\t\tEnter the Start Date:";
							cin.getline(temp->date,30);
							fflush(stdin);
							flag=true;
					}
					temp=temp->next;
				}
				if(flag==true)
				cout<<"\n\t\tRecord has been successfully updated"<<endl;
				else{
					cout<<"\n\t\tId enterd is wrong. Not found in list.."<<endl;
				}
			}
		}
};


int main()
{
	int n;
	char ch;
	employee ew;
	x2:
	ew.menu();
	cout<<"\n\t\tEnter your choice:";
	cin>>n;
	if(n==1)
	{
		x1:
			cout<<"\n\t\tWhere You want to add record:"<<endl;
			cout<<"\n\t\t 1. Very first record"<<endl;
			cout<<"\n\t\t 2. Very last record"<<endl;
			cout<<"\n\t\t 3. Location to add record to after record"<<endl;
			cout<<"\n\t\t 4. Add before record"<<endl;
			cout<<"\n\t\t Enter your choice:";
			cin>>n;
			if(n==1){
				ew.add_primary();
				cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
				cin>>ch;
				fflush(stdin);
				if(ch=='Y' || ch=='y')
				{
					goto x2;
				}
				else{
					exit(1);
				}
			}
			else if(n==2)
			{
				ew.add_sec();
				cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
				cin>>ch;
				fflush(stdin);
				if(ch=='Y' || ch=='y')
				{
					goto x2;
				}
				else{
					exit(1);
				}
			}
			else if(n==3)
			{
				ew.add_after();
				cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
				cin>>ch;
				fflush(stdin);
				if(ch=='Y' || ch=='y')
				{
					goto x2;
				}
				else{
					exit(1);
				}
			}
			else if(n==4)
			{
				ew.add_before();
				cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
				cin>>ch;
				fflush(stdin);
				if(ch=='Y' || ch=='y')
				{
					goto x2;
				}
				else{
					exit(1);
				}
			}
			else{
				cout<<"\n\t\t Enter correct answer"<<endl;
				goto x1;
			}
	}
	else if(n==2)
	{
		ew.search();
			cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
			{
				goto x2;
			}
			else{
				exit(1);
			}
	}
	else if(n==3)
	{
		ew.update();
			cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
			{
				goto x2;
			}
			else{
				exit(1);
			}
	}
	else if(n==4)
	{
		ew.del();
			cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
			{
				goto x2;
			}
			else{
				exit(1);
			}
	}
	else if(n==5)
	{
		ew.show();
			cout<<"\n\t\t\t Do you want to go main menu(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
			{
				goto x2;
			}
			else{
				exit(1);
			}
	}
	else if(n==6)
	{
		exit(1);
	}
	else
	{
		cout<<"\n\t\tChoose correct option"<<endl;
		goto x2;
	}
	return 0;	
}
