#include <iostream>
#include <string>
#include <fstream>

using namespace std;

fstream output_menu_stock("menu.txt",ios::app);
fstream input_menu_stock("menu.txt",ios::in);
fstream output_stock("stock.txt",ios::out);
fstream output_bill("bill.txt",ios::out);
fstream output_clients("clients_list.txt",ios::out|ios::app);
fstream output_datesell("date_sell.txt",ios::app);
class node
{
private:
    string name;
    int price;
    int stock;
    node *next;
public:
    friend class linkedlist;
};
class linkedlist
{
private:
    node *first;
    node *last;
public:
    linkedlist();
    void enter (string ,int,int);
    void charging(string); //for charging stock
    void changing(string); //for changing price
    void check(int &); //for warn to manger
    void ordering(string ,int,int &);

};
class coffeeshop
{
private:
    linkedlist coffeshop;
    int password;
    int summary=0;
public:
    coffeeshop();
    void settomenu();
    void chargemenu();
    void changingprice();
    void changingpass();
    void order();
    int checkpass();
    int checkday();
};


int main()
{
    coffeeshop test;
    int n=0;
    int c,pass,mc;
    if(!output_bill)
       {
           cout<<"sth is wrong"<<endl;
           return 0;
       }
       if(!output_clients)
       {
           cout<<"sth is wrong"<<endl;
           return 0;
       }
       if(!output_datesell)
       {
           cout<<"sth is wrong"<<endl;
           return 0;
       }
       if(!output_menu_stock)
       {
           cout<<"sth is wrong"<<endl;
           return 0;
       }
       if(!output_stock)
       {
           cout<<"sth is wrong"<<endl;
           return 0;
       }
    while(n!=1)
    {
     cout<<"1.Manager  2.Client"<<endl;
     cin>>c;
     switch (c)
     {
     case 1:
        cout<<"Please enter pass:";
        cin>>pass;
        if(pass==test.checkpass())
        {

            cout<<"Welcome manger"<<endl<<"Please choose your ask"<<endl<<"0.Start a day"<<endl<<"1.Add new Item"<<endl<<"2.Change price "<<endl<<"3.Charge stock "<<endl<<"4.Change password"<<endl<<"5.Checking a day"<<endl;
            cin>>mc;
            switch(mc)
            {
            case 0:
                int day,mounth,year;
                cout<<"Please enter dd,mm,yy"<<endl;
                cin>>day>>mounth>>year;
                output_datesell<<"Date :"<<day<<","<<mounth<<","<<year<<endl;
                break;
            case 1:
                test.settomenu();
                break;
            case 2:
                test.changingprice();
                break;
            case 3:
                test.chargemenu();
                break;
            case 4:
                test.changingpass();
                break;
            case 5:
                n=1;
                output_datesell<<"Last day summary: "<<test.checkday()<<endl;
                break;
                }
                break;
        }
        else
            {cout<<"Password is wrong!"<<endl;
            break;}
    case 2:
           test.order();
           break;
     }
    }
}


linkedlist::linkedlist()
{
    first=last=NULL;
}
void linkedlist::enter(string nam,int pric,int stoc)
{
    node *help;
    help=new node;
    help->next=NULL;
    if(first==NULL)
    {
        first=last=help;
    }
    else
    {
        last->next=help;
        last=help;
    }
    last->name=nam;
    last->price=pric;
    last->stock=stoc;
}
void linkedlist::check(int &chk)
{
    node *help;
    if(first==NULL)
    {
    cout<<"List is empty"<<endl;
    return;
    }
    help=first;
    do
    {
        if(help->stock<20)
            {output_stock<<help->name<<"\t"<<help->stock;
            help=help->next;
            chk=1;}
    }
    while(help!=NULL);

}
void linkedlist::changing(string a)
{
    node *help;
    int n;
    if(first==NULL)
    {
        cout<<"List is empty";
        return;
    }
    help=first;
    do
    {
        if(help->name==a)
        {
            cout<<"Pls enter new price:";
            cin>>n;
            help->price=n;
            return;
        }
        help=help->next;
    }
    while(help!=NULL);

}
void linkedlist::charging(string a)
{
    node *help;
    int n;
    if(first==NULL)
    {
        cout<<"List is empty";
        return;
    }
    help=first;
    do
    {
        if(help->name==a)
        {
            cout<<"Pls enter new stock:";
            cin>>n;
            help->stock=n;
            return;
        }
        help=help->next;
    }
    while(help!=NULL);

}
void linkedlist::ordering(string nam,int tedad,int &sum)
{
    node *help;
    int f=0;
    if (first==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    help=first;
    do
    {
        if(help->name==nam)
        {
            f=1;
            sum+=(help->price)*tedad;
            output_bill<<help->name<<"\t"<<help->price<<endl;
        }
        help=help->next;
    }
    while(help!=NULL);
    if(f==0)
        {cout<<"It wasn't on menu!"<<endl;
        return;}
}
void coffeeshop::settomenu()
{
    string Name;
    int Price;
    int Stock;
    int c=0;
    while(c==0)
    {
    cout<<"Pls enter Name,price,stock:";
    cin>>Name>>Price>>Stock;
    if(!output_menu_stock)
    {
        cout<<"Something is wrong!";
        return ;
    }
    output_menu_stock<<"Name: "<<Name<<endl<<"Price: "<<Price<<endl<<"Stock: "<<Stock<<endl;
    cout<<"Finish ?"<<endl<<"1.yes"<<"\t0.No"<<endl;
    cin>>c;
    }
}

void coffeeshop::chargemenu()
{
    string a;
    cout<<"Please enter the target for charge stock:";
    cin>>a;
    coffeshop.changing(a);
}
void coffeeshop::changingprice()
{
    string a;
    cout<<"Please enter your target for changing price:";
    cin>>a;
    coffeshop.changing(a);
}
void coffeeshop::changingpass()
{
    int p;
    cout<<"Please enter new pass:";
    cin>>p;
    password=p;
}
void coffeeshop::order()
{
    string firstname;
    string lastname;
    long int phonenumber;
    string nam;
    string pric;
    string stoc;
    int pric_int;
    int stoc_int;
    string ord;
    int ordnum;
    int sum=0;
    int c=0;
    cout<<"Welcome to our coffeeshop XD"<<endl<<"Please enter first and last name and your phone number:";
    cin>>firstname>>lastname>>phonenumber;
    output_clients<<"Firstname:"<<firstname<<" Lastname:"<<lastname<<"\t Phone number:"<<phonenumber<<endl;
    output_bill<<"Name :"<<firstname<<" "<<lastname<<endl<<"Orders:"<<endl;
    output_datesell<<"Name of client:"<<firstname<<" "<<lastname<<"Orders"<<endl;
    if(!input_menu_stock)
       {
           cout<<"sth is wrong"<<endl;
           return ;
       }
    while(!input_menu_stock.eof())
    {
        input_menu_stock>>nam;
        input_menu_stock>>nam;
        input_menu_stock>>pric;
        input_menu_stock>>pric;
        pric_int=stoi(pric);
        input_menu_stock>>stoc;
        input_menu_stock>>stoc;
        stoc_int=stoi(stoc);
        coffeshop.enter(nam,pric_int,stoc_int);
        cout<<"\t \tMENU"<<endl<<"Name: "<<nam<<"\t -*- \t Price: "<<pric_int<<" Toman"<<endl;
    }
    cout<<"Please choose from our menu and for exit enter end"<<endl;
    while(c==0)
    {
        cout<<"name:";
        cin>>ord;
        if(ord=="end")
            break;
        cout<<"What number of order:";
        cin>>ordnum;
        coffeshop.ordering(ord,ordnum,sum);
        output_datesell<<ord<<"  "<<ordnum<<endl;

    }
    output_bill<<"Summary of order: "<<sum<<"  Toman"<<endl<<endl<<"Thank you for choosing us";
    summary+=sum;

}
int coffeeshop::checkpass()
{
    return password;
}
int coffeeshop::checkday()
{
    int chk=0;
    coffeshop.check(chk);
    if(chk==1)
        cout<<"Somthings in menu not enough please check the stock file"<<endl;
    return summary;
}
coffeeshop::coffeeshop()
{
    password=0000;
}
