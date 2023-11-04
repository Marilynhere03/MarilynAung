#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
using namespace std;
void Main_menu();	//Main menu for user to view
void adminmenu();	//menu for admin to view
void menu_customer();//menu for customer to view
float cost[3];	 //training plan price 
int current_weight;	   //crrent weight to customer input 
string plan[3];	    //training plan for admin to insert

/*********Class for Admin.****************
Admin program is here which are Inserting 
the Training Plan,Viewing the Training****
Plan and Updating it*********************/
class Admin
{
	public:
// for admin user to input the plan
		void insert()
		{
			for(int i=0;i<3;i++)
			{
				cin.ignore();
				cout<<"Enter training plan ";
				getline(cin,plan[i]);
		
				cout<<"Enter price ";
				cin>>cost[i];
			}
			cout<<"Sucessfuly insert\n";
        }
//for admin input and display 
//
		void display_admin()
		{	cout<<"No.\t\t Planning \t\t Price"<<endl;
			for(int i=0;i<3;i++)
			{
					cout<<i+1<<"\t\t"<<plan[i]<<"\t\t"<<cost[i]<<endl;
			}	}
//for updating the plan
		void update_admin()
		{
			display_admin();
			string upplan;	//Update plan
					cin.ignore();
			cout<<"Enter a plan you want to update :";
			getline(cin,upplan);
	
			for(int i=0;i<3;i++)
			{
				if(upplan==plan[i])
				{
					cout<<"Enter a training plan : ";
					getline(cin,plan[i]);
					cout<<"Enter cost : ";
					cin>>cost[i];
					break;		// Exit the loop once the update is done
				}
			}
			adminmenu();
		}
};

//*** object of admin****
		Admin judo_admin;
/*********Class for Guest****************
Guest program is here which are Showing 
the Training Plan,Viewing the Weight****
Categorie******************************/
class Guest:public Admin
{
	public:
//for guest menu
	void menu_guest()
	{
		int ch;
		cout<<" 1. View Plan \n 2. Weight Categorie \n 3. Main Menu"<<endl;
		cin>>ch;
		if(ch==1)
		{
			display_admin();//calling back the display_admin which show the training plan which admin insert
			menu_guest();
		}
		else if(ch==2)
		{
            cout<<"Categories \t Upper weight limit \n";
            cout<<"Heavyweight Unlimited \t (Over 100) \n";
            cout<<"Light-Heavyweight \t 100 \n";
            cout<<"Middleweight \t\t 90 \n";
            cout<<"Light-Middleweight \t 81 \n";
            cout<<"Lightweight \t\t 73 \n";
            cout<<"Flyweight \t\t 66 \n";
            menu_guest();
		}
		else
		{
			Main_menu();
		}
	}
};

//*** object for Guest***
 	Guest judo_guest;
class Customer:public Admin
{
	private:
		string name;
		float price = 0;	//for the cost to add in 
		float total = 0;	//for the price to add in 
		string cus_plan;	 // a plan that customer gonna choice		
		string cus_weight;	 //customer weighr in string 
	public:	
		void GetData()
			{
			cin.ignore();
			cout<<"Enter your name : "; 
			getline(cin,name);
			cin.ignore();
			int hr;	//hour
			int num;	 // number that show on display of admin
			judo_admin.display_admin();
			cout<<"Eenter the number: ";
			cin>>num;
			if(num == 1)
			{
				cus_plan = plan[0];
				cout<<"Price"<<cost[0]<<endl;
				price += cost[0];
			}
			else if(num == 2)
			{
				cus_plan = plan[1];
				cout<<"Price"<<cost[1]<<endl;
				price += cost[1];
			}
			else if (num == 3)
			{
				cus_plan = plan[2];
				cout<<"Price"<<cost[2]<<endl;
				price += cost[2];
			}
			char ch; //answer from user
			char ans; //answer from user
			
		//goto private tution fee again
			private_tution:
			cout<<"\t Do you want to join Private tuition for this week ('y' or 'n') \n \tPer Hour Price=9.50"<<endl;
			cin>>ch;
			if(ch=='y')
		{
				float private_tution = 9.50;
				cout<<"How many hours you want to take : ";
				cin>>hr;
				if(hr>5)
				{
					cout<<"You can only take 5 hour per week"<<endl;
					goto private_tution;
				}
				private_tution *= hr;
				price += private_tution;
				total += price;
				
		}
			else
			{
				total += price;
				cout<<"Total : "<<total<<endl;
				cout<<"Thank you for the information"<<endl;
			}
		if(num==1)
				{
					cout<<"You can't join the competition ."<<endl;
					cout<<"Total : "<<total<<endl;
				}
			else if ((num==2) || (num== 3))
			{
				// got to competition 
				competiton:
				cout<<"\t Competition entry fee per competition('y' or 'n') \n \tPrice= 22.00"<<endl;
				cin>>ans;
				if(ans=='y')
				{
					int com; // compatition time 
					weight_categories();
					cout<<"Enter your current weight : ";
					cin>>current_weight;
				if(current_weight<66)
				{
					cout<<"You can't join the compatition"<<endl;
					menu_customer();
				}
				else if(current_weight>=66 && current_weight < 73)
				{
					cout<<"You can join to Flyweight "<<endl;
					cus_weight = "Flyweight";
				}
				else if(current_weight>=73 && current_weight < 81)
				{
					cout<<"You can join to Lightweight "<<endl;
					cus_weight = "Lightweight";
				}
				else if (current_weight<=81 && current_weight < 90)
				{
					cout<<"You can join to Light-Middle weight "<<endl;	
					cus_weight = "Light-Middle weight";
				}
				else if(current_weight<=90 && current_weight < 100)
				{
					cout<<"You can join to Middle weight "<<endl;	
					cus_weight = "Middle weight";	
				}
				else if(current_weight==100)
				{
					cout<<"You can join to Light-Heavy weight "<<endl;	
					cus_weight = "Light-Heavy weight";
				}
				else if(current_weight>100)
				{
					cout<<"You can join to Heavy weight "<<endl;	
					cus_weight = "Heavy weight";
				}
				cout<<"How many time you want to join the compatition :";
				cin>>com;
				float competition_fee = 22;
					price += competition_fee*com;
					total += price;
				cout<<"Total : "<<total<<endl;
				}
				else 
				{
					cout<<"Thank you for the information"<<endl;
					cout<<"Total : "<<total<<endl;
				}
			}
			else 
			{
				cout<<"You got the wrong number.Please try again "<<endl;
				goto competiton;
			}
			
	}
	//showing weight
		void weight_categories()
		{
			cout<<"\t Weight categories"<<endl;
			cout<<"Heavyweight Unlimited \t (Over 100)"<<endl;
			cout<<"Light-Heavyweight \t 100"<<endl;
			cout<<"Middleweight \t\t 90"<<endl;
			cout<<"Light-Middleweight \t 81"<<endl;
			cout<<"Lightweight \t\t 73"<<endl;
			cout<<"Flyweight \t\t 66"<<endl;
		}
	//for viewing information
		void view_information()
		{
			int j = 0;
			for(int i=0;i<=j;i++)
			{
			cout<<"\t \t Customer Name \t Total Costs \t Weight \t Training Plan"<<endl;	
			cout<<"\t \t"<<name<<"\t\t"<<total<<"\t\t"<<cus_weight<<"\t\t"<<cus_plan<<endl;		
			}
			j++;
		}
};
	//object for customer//
	Customer judo_customer[3];
	int s=0;
int main()
{
	Main_menu();
}

void Main_menu()
{
		int num;
			cout<<" 1. Admin \n 2.Customer \n 3.Guest \n ";
			cin>>num;
			if(num==1)
			{
				adminmenu();
			}
			else if(num==2)
			{
				 menu_customer();
			}
			else if(num==3)
			{
				judo_guest.menu_guest();
			}
}
void adminmenu()
{
		int ch;
		cout<<endl;
		cout<<" 1.Insert Training Plan \n 2.View Training Plan \n 3.Update \n 0.Main Menu \n";
		cin>>ch;
		if(ch==1)
			{
				judo_admin.insert();
				adminmenu();
			}
		else if(ch==2)
			{
				judo_admin.display_admin();
				getch();
				adminmenu();
			}
		else if(ch==3)
			{
				judo_admin.update_admin();
			}
		else if(ch==0)
			{
				Main_menu();
			}
		else
			{
				cout<<"\t Wrong Number. Please Try Again."<<endl;			
			}	
}
void menu_customer()
	{
		int ch;
		cout<<" 1.Training Plan \n 2.Veiw Information \n 0.Main Menu \n";
		cin>>ch;
		if(ch==1)
			{
				judo_customer[s].GetData();
				s++;
				cout<<"\t"<<"Insert is finally done"<<endl;
				 menu_customer();
			}
		else if(ch==2)
			{
				for(int i=0;i<s;i++)
				{
					judo_customer[i].view_information();
				}
				s++;
				 menu_customer();
			}			
		else if(ch==0)
			{
				Main_menu();		
			}
}