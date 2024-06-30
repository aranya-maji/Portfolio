#include<iostream>


                                        //main header file for a cpp program


#include<time.h>


                                        //time library file used to include
                                        //time related effects in the program


#include<cstdlib>


                                        //IT defines a core set of functions
                                        //used for data type conversion,
                                        //pseudo-random number generation,
                                        //memory allocation, searching,
                                        //sorting, mathematics, and dealing
                                        //with wide or multi byte characters.


#include<graphics.h>


                                        //graphics library used to add graphics
                                        //to the program


#include<fstream>


                                        //file library used for file related
                                        //functions in the program


#include<string>


                                        //string used to add functionalities
                                        //of string in the program


using namespace std;


                                        //main/base class of the program


class stocks{

    public:


                                        //this section contains the variables
                                        //used in the program


    string name;

    string name1;

    string password1;

    string pin;

    string bankaccno;

    string panno;

    string debitcardno;

    string debitcardno1;

    string mobno;

    string mobno1;

    string temp;

    string pwd;

    string temp10;

    string temp20;

    string names;

    string names1;

    string value;

    string value1;

    string temp100;

    string temp200;

    string temp1;

    string temp30;

    string value2;

    string temp2;

    int o = 1;


                                        //it is for min number of trials
                                        //for user authentication


    int y,z,jam,b,g;

    int amount;

    int number = 0;


                                        //number represents number of
                                        //stocks owned by the user and
                                        //its default value is 0


    int number1 = 0;

    int number2 = 0;

    int number3 = 0;

    int number4 = 0;

    int invperst = 0;


                                        //investment per stock variable
                                        //contains how much a person invests
                                        //in a particular stock


    int invperst1 = 0;

    int invperst2 = 0;

    int invperst3 = 0;

    int invperst4 = 0;

    float balance = 100;


                                        //default wallet balance for all the
                                        //user is set to 100


    float price;

    float price1;

    int Choice;


                                        //it is the choice whether a person
                                        //wants to register or login into an
                                        //already registered account.


    string username;


                                        //it is the user name for the user


    string password2;


                                        //it is the password for login into the program
                                        //buy function enables the user to buy stocks
                                        //depending upon the choices provided thereupon.
                                        //it displays the list of the stocks from which
                                        //the user selects the one after selecting a
                                        //particular stock,
                                        //he/she will be directed to payment gateway
                                        //where he/she will make payment form there
                                        //particular account
                                        //x represents the number of stocks to be bought
                                        //and y represents the current value of the stock
                                        //and the final price is calculated by x*y


    float buy(int x,int y)
    {

        if(x*y>balance)
        {

            invperst = x*y;

            cout<<"\nNot enough funds\n";


                                        //when the person does not have enough money in
                                        //their respective wallet then payment could
                                        //also be processed through 2 gateways
                                        //1.Vpay and 2.Card payment
                                        //Vpay will ask user to enter his/her
                                        //mob no and payment will be precessed through
                                        //their respective UPI ids after authentication
                                        //card payment will ask the user to enter their
                                        //respective card number and payment will be
                                        //processed after authentication of the PIN
                                        //entered by the user


            cout<<"Pay via 1. VPAY or 2. Debit Card:- ";

            cin>>g;

            switch(g)


                                        //switch case have been used to select the
                                        //choice between VPAY and Card payment.


            {


                                        //vpay payment gateway


            case 1:

                label1:

                cout<<"Enter Mobile number:- ";

                cin>>mobno1;

                if(mobno1 == mobno)
                {

                    label:

                    cout<<"Enter pin:- ";

                    cin>>pin;

                    if(pin == password1)


                                        //pin authentication


                    {

                        cout<<"Paying "<<invperst<<" from UPI ID "<<mobno<<endl;


                                        //display message


                        goto nex;
                    }

                    else
                    {

                        cout<<"Invalid PIN\nre-enter PIN\n";

                        goto label;
                    }
                }

                else
                {

                    cout<<"Invalid Mobile number\n";

                    goto label1;
                }

                break;

            case 2:


                                        //card payment gateway


                label3:

                cout<<"Enter Card number:- ";

                cin>>debitcardno1;

                if(debitcardno1 == debitcardno)
                {

                    label4:

                    cout<<"Enter pin:- ";

                    cin>>pin;

                    if(pin == password1)


                                        //pin authentication


                    {

                        cout<<"Paying "<<invperst<<" from Account Number "<<bankaccno<<endl;


                                        //displaying  payment  message


                        goto nex;
                    }

                    else
                    {

                        cout<<"Invalid PIN\nre-enter PIN\n";

                        goto label4;
                    }
                }

                else
                {

                    cout<<"Invalid Card Number\n";

                    goto label3;
                }

                break;
            }

            exit(0);
        }

        else
        {


                                        //it updates the balance in the respective
                                        //wallets and bank accounts


            number = number + x;

            price = (float)-1*x*y;

            invperst = invperst + x*y;

            nex:

            return price;
        }
    }


                                        //sell function enables the user to sell a
                                        //already bought stock
                                        //if the current value of the stock exceeds
                                        //the the value at the initial thus making a
                                        //profit for the user
                                        //now the amount will be credited to the wallet
                                        //of the account from where he/she could continue trading


    float sell(int x, int y)
    {

        if(number<x)
        {

            cout<<"No stocks to sell!!"<<endl;

            exit(0);
        }

        else
        {


                                        //it updates the balance in the respective
                                        //wallet and the bank account


            number = number - x;

            price1 = (float)1*x*y;

            if((invperst - x*y)<0)
            {

                invperst = 0;
            }

            else
            {

                invperst = invperst - x*y;
            }

            return price1;
        }
    }

    void payment(float z)
    {

        balance = balance + z;


                                        //balance update


    }


                                        //this block displays the available stocks from
                                        //where a user could make a choice whether to
                                        //buy it or not
                                        //pictorial representations(graphs)have also been
                                        //used to represent the current growth and the
                                        //current value of that stock


    void displaystocks()
    {


                                        //choice will be entered by the user that which
                                        //stock he/she wants to view


        fr:

        cout<<"Available stocks in the market:-\n1. Stock1\n2. Stock2\n3. Stock3\n4. Stock4\n5. Display Data\n6. Exit"<<endl;

        cout<<"Enter choice:- ";

        cin>>Choice;

        if(Choice==1)
        {

            Stock1();
        }

        else if(Choice==2)
        {

            Stock2();
        }

        else if(Choice==3)
        {

            Stock3();
        }

        else if(Choice==4)
        {

            Stock4();
        }

        else if(Choice==5)
        {

            displaydata();

            goto fr;
        }

        else
        {

            cout<<"\nThanks for visiting!!\n";

            exit(0);
        }

        delay(2000);

        system("CLS");
    }

    void Stock1()
    {

        graph();
    }

    void Stock2()
    {

        graph();
    }

    void Stock3()
    {

        graph();
    }

    void Stock4()
    {

        graph();
    }


                                        //this section contains the graphics section of the program,
                                        //the graph and the growth of particular stock is
                                        //controlled by here itself


    void displaydata()
    {

        system("CLS");

        cout<<"********************User details********************"<<endl<<endl;

        cout<<"Username:- "<<name<<endl;

        cout<<"Mobile Number:- "<<mobno<<endl;

        cout<<"Bank Account Number:- "<<bankaccno<<endl;

        cout<<"PAN Number:- "<<panno<<endl;

        cout<<"Debit Card Number:- "<<debitcardno<<endl<<endl;

        cout<<"********************Balance********************"<<endl<<endl;

        cout<<"Balance:- "<<balance<<endl<<endl;

        cout<<"********************Stock1********************"<<endl<<endl;

        cout<<"Number of stocks in Stock1:- "<<number1<<endl;

        cout<<"Amount invested in Stock1:- "<<invperst1<<endl<<endl;

        cout<<"********************Stock2********************"<<endl<<endl;

        cout<<"Number of stocks in Stock2:- "<<number2<<endl;

        cout<<"Amount invested in Stock2:- "<<invperst2<<endl<<endl;

        cout<<"********************Stock3********************"<<endl<<endl;

        cout<<"Number of stocks in Stock3:- "<<number3<<endl;

        cout<<"Amount invested in Stock3:- "<<invperst3<<endl<<endl;

        cout<<"********************Stock4********************"<<endl<<endl;

        cout<<"Number of stocks in Stock4:- "<<number4<<endl;

        cout<<"Amount invested in Stock4:- "<<invperst4<<endl<<endl;

        cout<<endl;
    }

    void graph()
    {

        int c = 100;

        int Count = 0,ex = 0;

        srand((unsigned) time(NULL));

        initwindow(800,250);

        setcolor(WHITE);

        setlinestyle(0,0,3);

        while(1)
        {

            setcolor(WHITE);

            char ch;

            int a = 30,b = 100,d;

            line(30,50,30,200);

            line(30,200,750,200);

            settextstyle(0,0,0);

            outtextxy(200,210,"The values are shown in the console");

            for(int i = 0;i<10;i++)
            {

                system("CLS");//

                cout<<"*----------------------------------------------------------*"<<endl;

                d = 100 + (rand() % 100);

                cout<<endl;

                if(Choice==1)
                {

                    number = number1;

                    invperst = invperst1;
                }

                else if(Choice==2)
                {

                    number = number2;

                    invperst = invperst2;
                }

                else if(Choice==3)
                {

                    number = number3;

                    invperst = invperst3;
                }

                else if(Choice==4)
                {

                    number = number4;

                    invperst = invperst4;
                }

                cout<<"Time left before Auto-sell:- "<<10-Count<<" minutes "<<endl;

                cout<<"The current stock value is:- "<<200-d<<endl;

                cout<<"Number of stocks bought:- "<<number<<endl;

                cout<<"Amount invested in the current stock:- "<<invperst<<endl;

                cout<<"The balance is:- "<<balance<<endl;

                cout<<"Maximum stocks that can be bought:- "<<(int)balance/(200-d)<<endl;

                if(c>d)
                {

                    setcolor(GREEN);
                }

                else if(c<d)
                {

                    setcolor(RED);
                }

                else if(c==d)
                {

                    setcolor(YELLOW);
                }

                line(a,c,b,d);

                setcolor(WHITE);

                settextstyle(0,0,0);

                c = d;

                a = a + 70;

                b = b + 70;

                cout<<endl;

                cout<<endl;

                cout<<"Press y to skip to next minute"<<endl;

                cout<<"Press s to sell and b to buy"<<endl;

                cout<<"Press any other key to exit:- ";

                cin>>ch;

                if(ch == 'y')
                {

                    if(ex == 1)
                    {

                        Count++;

                        if(Count == 10)
                        {

                            cout<<"Time out: Sold"<<endl;

                            payment(sell(number,200-d));

                            ex = 0;

                            Count = 0;

                        }
                    }

                    continue;
                }

                else if(ch == 'b')
                {

                    cout<<"\nEnter the number of stocks to be bought:- ";

                    cin>>amount;

                    payment(buy(amount,200-d));

                    cout<<amount<<" stocks bought\n"<<endl;

                    cout<<-1*price<<" invested\n";

                    ex = 1;

                    Count = 0;

                    delay(2000);

                }

                else if(ch == 's')
                {

                    cout<<"\nEnter the number of stocks to be sold:- ";

                    cin>>amount;

                    if(amount>number)
                    {

                        cout<<"\nNot enough stocks\n";

                        exit(0);
                    }

                    else
                    {

                        cout<<amount<<" stocks sold\n"<<endl;

                        payment(sell(amount,200-d));

                        cout<<price1<<" earned\n";

                        if(number==0)
                        {

                            ex = 0;
                        }

                        Count = 0;
                    }

                    delay(2000);
                }

                else
                {

                    cout<<"\nThanks for visiting!!\n";

                    closegraph();

                    system("CLS");

                    displaystocks();

                }

                if(Choice == 1)
                {

                    number1 = number;

                    invperst1 = invperst;
                }

                else if(Choice == 2)
                {

                    number2 = number;

                    invperst2 = invperst;
                }

                else if(Choice == 3)
                {

                    number3 = number;

                    invperst3 = invperst;
                }

                else if(Choice == 4)
                {

                    number4 = number;

                    invperst4 = invperst;
                }


                                        //from here the file handling of the program starts.
                                        //4 users have already been put into registered column
                                        //whose info have been stored into files
                                        //file function of cpp have been used to extract
                                        //information from those files and it also authenticates
                                        //the user so that he/she may continue trading
                                        //fin function is used when we want to read a file and
                                        //fout is used when we want to write onto a file


                fstream fin1,fout1;


                                        //open function is used to open the file from the
                                        //corresponding position in the system


                fin1.open("data.csv",ios::in);

                fout1.open("data_buff.csv",ios::app);

                while(fin1>>temp1)
                {

                    y = 0;

                    temp100 = temp1[y];

                    while(temp100 != ",")
                    {

                        names1 = names1 + temp100;

                        temp100 = temp1[y+1];

                        y++;
                    }

                    if(names1 != name)
                    {

                        fout1<<temp1<<"\n";
                    }

                    else if(names1 == name)
                    {

                        fout1<<name<<","<<password1<<","<<mobno<<","<<bankaccno<<","<<panno<<","<<debitcardno<<","<<balance<<","<<number1<<","<<invperst1<<","<<number2<<","<<invperst2<<","<<number3<<","<<invperst3<<","<<number4<<","<<invperst4<<"\n";
                    }

                    names1.clear();
                }

                fin1.close();

                fout1.close();

                fstream fin2,fout2;

                fout2.open("data.csv",ios::out);

                fout2.close();

                fin2.open("data_buff.csv",ios::in);

                fout2.open("data.csv",ios::app);

                while(fin2>>temp2)
                {

                    fout2<<temp2<<"\n";
                }

                fout2.close();

                fin2.close();

                fout2.open("data_buff.csv",ios::out);

                fout2.close();
            }

            cleardevice();

            system("CLS");
        }

        getch();

        closegraph();
    }
};


                                        //login class declared for the user who have
                                        //already registered into the account
                                        //the info for the user will be extracted from
                                        //the file through file handling module of cpp
                                        //the program then authenticates the user and
                                        //after that he/she will be directed to trading
                                        //page where he/she could continue trading


class login:public stocks
{

    public:


                                        //verify function used to authenticate an already
                                        //registered user


    void verify()
    {

        t:

        cout<<"ENTER USERNAME = ";

        cin>>username;

        cout<<"ENTER PASSWORD = ";

        cin>>password2;

        fstream fin;

        fin.open("data.csv",ios::in);

        while(fin>>temp)
        {

            y = 0;

            temp10 = temp[y];

            while(temp10 != ",")
            {

                names = names + temp10;

                temp10 = temp[y+1];

                y++;
            }

            if(names != username)
            {

                names.clear();
            }

            else if(names == username)
            {

                z = y + 1;

                temp20 = temp[z];

                while(temp20 != ",")
                {

                    pwd = pwd + temp20;

                    temp20 = temp[z+1];

                    z++;
                }

                if(pwd != password2)
                {

                    if(o<3)
                    {

                        o++;

                        cout<<"\nIncorrect credentials....Please try again\n"<<endl;

                        goto t;
                    }

                    else
                    {

                        cout<<"\nUSER AUTHENTICATION FAILED PLEASE RETRY AFTER SOMETIME\n";
                    }
                }

                else if(pwd == password2)
                {

                    cout<<"\nUser Verified Successfully!!\n";

                    jam = 0;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    name = value1;

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    password1 = value1;

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    mobno = value1;

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    bankaccno = value1;

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    panno = value1;

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;

                    }

                    debitcardno = value1;

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    balance = stof(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    number1 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    invperst1 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    number2 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;

                    }

                    invperst2 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    number3 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;

                    }

                    invperst3 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    number4 = stoi(value1);

                    value1.clear();

                    jam++;

                    value = temp[jam];

                    while(value != ",")
                    {

                        value1 = value1 + value;

                        value = temp[jam+1];

                        jam++;
                    }

                    invperst4 = stoi(value1);

                    value1.clear();

                    fin.close();

                    delay(2000);


                                        //delay function used to delay the screen time so
                                        //to make the program seems real


                    system("CLS");


                                        //it used to clear the screen so to have a
                                        //minimalistic and clear screen


                    displaystocks();


                                        //it will display stocks after login into the account


                    cout<<endl;

                    delay(2000);

                    system("CLS");
                }
            }
        }
    }
};


                                        //class register will contain the program for registering
                                        //a new user
                                        //it will asks for personal information from the user and
                                        //then store it onto files so that user can just simply
                                        //login next time
                                        //after login different stocks will be displayed from where
                                        //user makes a choice and he/shew will either buy it or
                                        //move to next one


class registers:public login
{

    public:

    void regis(){

        cout<<"ENTER USERNAME = ";

        cin>>name;

        cout<<"ENTER PASSWORD FOR THE ACCOUNT = ";

        cin>>password1;

        cout<<"ENTER YOUR MOBILE NUMBER = ";

        cin>>mobno;

        cout<<"ENTER BANK ACCOUNT NUMBER = ";

        cin>>bankaccno;

        cout<<"ENTER PAN NUMBER = ";

        cin>>panno;

        cout<<"ENTER DEBIT CARD NUMBER = ";

        cin>>debitcardno;

        fstream ptr1;


                                        //file pointer used to points towards a file
                                        //to store information


        ptr1.open("data.csv",ios::app);

        ptr1<<name<<","<<password1<<","<<mobno<<","<<bankaccno<<","<<panno<<","<<debitcardno<<","<<balance<<","<<number1<<","<<invperst1<<","<<number2<<","<<invperst2<<","<<number3<<","<<invperst3<<","<<number4<<","<<invperst4<<"\n";

        ptr1.close();

        cout<<"\nREGISTERED SUCCESSFULLY!!\n"<<endl;

        delay(2000);

        system("CLS");

    }
};
int main()
{


                                        //an object name reg is made of register class which
                                        //inherits the features of all the classes
                                        //and the main functioning of the program is made
                                        //through this class only


    registers reg;

    int I;

    T:

    cout<<"Enter:-\n1. Register\n2. Login\n3. Exit"<<endl;

    cout<<"Enter option:- ";

    cin>>I;

    if(I==1)
    {

        reg.regis();


                                        //register function of the program are executed from here


        goto T;
    }

    else if(I==2)
    {

        reg.verify();


                                        //verifying function of the program are executed from here


    }

    else if(I==3)
    {

        cout<<"Thanks for visiting!!"<<endl;

        exit(1);
    }

    else
    {

        cout<<"Enter correct option!!\n"<<endl;

        goto T;
    }
}
