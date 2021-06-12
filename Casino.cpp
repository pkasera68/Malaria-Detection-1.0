#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
 extern int dc;//extern storage class
  string name1;
class casino
{
    static long int comp_amt,player_amt,othr_pla;//static data member
    long int pl_bamt,bet,ch_comp,no_max,no_min,temp;
     string name;
    int c=0;
    public:
    	casino()//default constructor
    	{
		}
	void init()//Paramaterized constructor
    {
        comp_amt=10000;
        player_amt=10000;
        othr_pla=10000;
        no_max=10;
        no_min=1;
    }
    string operator+();//unary operator overloading
    //function overloading for operator +() function
    casino &operator+(casino &c4);//binary operator overlaoding
    int main_menu()//inside declaration of member function
    {
        getline(cin,name1);
        cout<<endl<<endl;
        c=1;
        return c;
    }
    casino(string &n)//parameterized constructor for computer bet
    {
       srand(static_cast <unsigned int> (time(0)));//srand is used to seed the rand() func with a new seed value so that every time we run the program 							
   												//a new set of radom num generated.here our seed is time(0) which will change the seed value than last time.
        no_max=10;					   			//if we not use srand before rand() then its its default seed is srand(1)and
        no_min=1;								// each time it will generate the same set of random variables.
        cout<<"Bet with computer."<<"\n\n";
        cout<<"Enter the amount:";
        cin>>pl_bamt;
        cout<<endl;
        l2:cout<<"NOTE:Must choose any number between 1 and 10."<<endl;
        cout<<"Give your CHOICE:";
        cin>>bet;
        cout<<endl;
        if(bet<1||bet>10)
        {
            cout<<"Please try again.....";
            cout<<endl;
            goto l2;
        }
        waiting();
        ch_comp=(rand()%no_max-no_min + 1) + no_min;	//generates a random number with a new seed between min limit and max limit.
               if(ch_comp==bet)
               {
                   cout<<"its "<<ch_comp<<" you Won "<<pl_bamt<<" against computer."<<endl;
                   cin.get();
                   cin.get();
                   comp_amt=comp_amt-pl_bamt;
                   player_amt+=pl_bamt;
                   
               }
               else
               {
                   cout<<"its "<<ch_comp<<" you Loose "<<pl_bamt<<" against computer."<<endl;
                   comp_amt+=pl_bamt;
                   player_amt=player_amt-pl_bamt;
                   cin.get();
                   cin.get();
               }
        
    }
    friend void show(casino &ob);//friend function
    static void show_compamt()//static memberfunction
    {
        cout<<"Computer's current amount:"<<comp_amt<<endl;
    }
    casino(casino &c3)//copy constructor for bet with any other player
    {
    	c3.player_amt=this->player_amt;
    	srand(static_cast <unsigned int> (time(0)));//srand is used to seed the rand() func with a new seed value so that every time we run the program 
        no_max=10;									//a new set of radom num generated.here our seed is time(0) which will change the seed value than last time.
        no_min=1;									//if we not use srand before rand() then its its default seed is srand(1)and
		cout<<"Bet with other player."<<"\n\n";		// each time it will generate the same set of random variables.
        cout<<"Enter other player name:";
        cin.get();
        getline(cin,c3.name);
        cout<<endl;
        cout<<"its "<<c3.name<<"'s turn:"<<endl;
        cout<<"Enter the amount you want to bet:";
        cin>>c3.pl_bamt;
        cout<<endl;
        cout<<"its your turn:"<<endl;
        l2:cout<<"NOTE:Must choose any number between 1 and 10."<<endl;
        cout<<"Give your CHOICE:";
        cin>>bet;
        cout<<endl;
        if(bet<1||bet>10)
        {
            cout<<"Please try again.....";
            cout<<endl;
            goto l2;
        }
        waiting();
        ch_comp=(rand()%no_max-no_min + 1) + no_min;//generates a random number with a new seed between min limit and max limit.
               if(ch_comp==bet)
               {
                   cout<<"its "<<ch_comp<<" "<<name1<<" Won "<<c3.pl_bamt<<" against "<<c3.name<<"."<<endl;
                   c3.othr_pla=c3.othr_pla-c3.pl_bamt;
                   player_amt+=c3.pl_bamt;
                    cin.get();
                    cin.get();
                   
               }
               else
               {
                   cout<<"its "<<ch_comp<<" "<<name1<<" Loose "<<c3.pl_bamt<<" against "<<c3.name<<"."<<endl;
                   c3.othr_pla=c3.othr_pla+c3.pl_bamt;
                   player_amt-=c3.pl_bamt;
                    cin.get();
                    cin.get();
               }
        this->player_amt=c3.player_amt;
		this->othr_pla=c3.othr_pla;        
    }
   	void waiting()
		{
			
			
			for(int i=1;i<=4;i++)
			{
				system("cls");
				cout<<endl<<"Waiting.";
				for(int j=1;j<=5;j++)
				{
					cout<<".";
					Sleep(400);
				}
			}
			system("cls");
		}
};
casino &casino::operator +(casino &c4)//binary operator overloading
{
	 cout<<"$$$$$$$$$$CASINO$$$$$$$$$$"<<endl;
        cout<<endl<<"WELCOME!"<<endl;
        cout<<"Enter your name:";
        return *this;//this ptr
}
void show(casino &ob)
{
    cout<<"Your Current amount:"<<ob.player_amt<<endl;
    cout<<"Other player's Current amount:"<<ob.othr_pla<<endl;
}
long int casino::comp_amt;//outside declaration of static data member
long int casino::othr_pla;//outside declaration of static data member
long int casino::player_amt;//outside declaration of static data member
//template<class D>
string casino::operator +()//unary operator overloding
{
	string ch1;
    cout<<"WELCOME! "<<name1<<endl;
    l1:cout<<"1)Bet with computer."<<endl;
    cout<<"2)Bet with other player."<<endl;
    cout<<"3)Display your current amount."<<endl;
    cout<<"4)For exit."<<endl;
    cout<<"Enter your choice:";
    cin>>ch1;
    cout<<endl;
    if(ch1!="1"&&ch1!="2"&&ch1!="3"&&ch1!="4")
    {
        cout<<"Please try again........"<<endl;
        goto l1;
    }
        return ch1;
    
}
template<class T,class P>//template T and P
 int choice_3(T &c1,P co) 
{								// template fuction
    casino::show_compamt();
        show(c1);
        cout<<"Press ENTER to goto menu.....";
        cin.get();
        cin.get();
}
//inheritance
template<class A>//template A
class developer:public casino //Derived class of class casino
{                            //template class
	public:
		A dev_info(A k)
		{
			if(k==1)
			{
			//system("cls");
			cout<<"\nProject name: Simple Casino Game.";
			cout<<"\nSource code: Object Oriented.";
			cout<<"\nDevelopment Year: 2019.";
			cout<<"\nGuided By: Dr M Srinivas.";
			cout<<"\nDeveloper's Name: Pranav Kasera.";
			cout<<"\nClass: M.C.A 1 st.";
			cout<<"\nRoll No: 197936.";
			cout<<"\nReg No: MC19107.";
			cout<<"\nDepartment: CSE.";
			cout<<"\nNational institute of technology,Warangal";
			}
		}
		
};
inline int loading() //inline function 
{
			system("cls");
			 char s='*';
			cout<<"Loading."<<endl;
			for(int i=1;i<=12;i++)
			{
				cout<<s;
				Sleep(450);//Delay the execution by 500 miliseconds
			}
			system("cls");
}
int main()
{
    auto casino c1;//auto storage class 
    c1.init();
	casino c2; 
    register string ch1;//register storage class
    c1=c1+c2;
    static int c=c1.main_menu();//static storage class
    system("cls");
    if(c==1)
    {
    	l4:system("cls");
    	loading();
     	ch1=+c1;
    }
    if(ch1=="1")
    {
    	loading();
        c1=casino(ch1);
        goto l4;
    }
    if(ch1=="2")
    {
    	loading();
        casino c3;
        c1=casino(c3);
        goto l4;
    }
    if(ch1=="3")
    {
    	loading();
        choice_3(c1,45);
        goto l4;
    }
    if(ch1=="4")
    {
    	system("cls");
    	cout<<"\nPress 1 to see the Project's information or any other number for EXIT."<<endl;
    	cin>>dc;
    	if(dc==1)
    	{
    		developer <int> d;
    		d.dev_info(dc);
    		cin.get();
		}
	}
    return 0;
}
    
