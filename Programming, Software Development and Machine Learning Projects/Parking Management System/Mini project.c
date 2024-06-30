#include<stdio.h>
#include<string.h>

// comments are provided at first
// then the codes are provided


// structure declared named park
// contains year,month,date,hour,minute


struct park
{
    char number[20];
    int year;
    int month;
    int date;
    int hour;
    int minute;
};

                        // some global variables are declared for efficiency
                        // 2 file pointers declared
                        // fp is the main file pointer
                        // every execution is done through fp
                        // fb is the buffer file pointer
                        // fb comes into action only while exiting a vehicle from the parking lot


FILE *fp,*fb;

                        // array p is the main array
                        // p always works with fp
                        // array b is the buffer array
                        // b always works with fb


struct park p[200],b[200];


                        // few integers are declared
                        // they come into action at various points of the whole program


int i=0,j=0,k,x,y=0,q=0,r=0;


                        // these specific integers are declared for the specific action
                        // eny refers to Entry Year
                        // enmo refers to Entry Month
                        // end refers to Entry Day
                        // enh refers to Entry Hour
                        // enm refers to Entry Minute


int eny,enmo,end,enh,enm;


                        // exy refers to Exit Year
                        // exmo refers to Exit Month
                        // exd refers to Exit Day
                        // exh refers to Exit Hour
                        // exm refers to Exit Minute


int exy,exmo,exd,exh,exm;

                        // a User defined function date is declared
                        // its job is to check whether a year is leap year or not
                        // and to decide maximum number of days in a month


int date(int mcheck,int ycheck)
{
    int g;
    if(ycheck%400==0||ycheck%4==0)
    {
        if(mcheck==1)
        {
            g=31;
        }
        else if(mcheck==2)
        {
            g=29;
        }
        else if(mcheck==3)
        {
            g=31;
        }
        else if(mcheck==4)
        {
            g=30;
        }
        else if(mcheck==5)
        {
            g=31;
        }
        else if(mcheck==6)
        {
            g=30;
        }
        else if(mcheck==7)
        {
            g=31;
        }
        else if(mcheck==8)
        {
            g=31;
        }
        else if(mcheck==9)
        {
            g=30;
        }
        else if(mcheck==10)
        {
            g=31;
        }
        else if(mcheck=11)
        {
            g=30;
        }
        else if(mcheck==12)
        {
            g=31;
        }
    }
    else
    {
        if(mcheck==1)
        {
            g=31;
        }
        else if(mcheck==2)
        {
            g=28;
        }
        else if(mcheck==3)
        {
            g=31;
        }
        else if(mcheck==4)
        {
            g=30;
        }
        else if(mcheck==5)
        {
            g=31;
        }
        else if(mcheck==6)
        {
            g=30;
        }
        else if(mcheck==7)
        {
            g=31;
        }
        else if(mcheck==8)
        {
            g=31;
        }
        else if(mcheck==9)
        {
            g=30;
        }
        else if(mcheck==10)
        {
            g=31;
        }
        else if(mcheck=11)
        {
            g=30;
        }
        else if(mcheck==12)
        {
            g=31;
        }
    }
    return g;
}

                        // a User defined function named dur is declared
                        // it takes input from the user and database and calculates the total duration of parking
                        // it also has the rate of parking charges
                        // it then calculates the total amount of money to be paid for the parking
                        // it takes the following inputs from the user and the database.....
                        // Entry Year from the database
                        // Entry Month from the database
                        // Entry Day from the database
                        // Entry Hour from the database
                        // Entry Minute from the database
                        // Exit Year from the user
                        // Exit Month from the user
                        // Exit Day from the user
                        // Exit Hour from the user
                        // Exit Minute from the user
                        // arguments are declared for dur

int dur(int a,int b,int c,int d,int e,int l,int m,int n,int o,int p)
{

                        // these specific integers are declared for the specific action
                        // couny refers to duration of Years parked
                        // counmo refers to duration of Months parked
                        // cound refers to duration of Days parked
                        // counh refers to duration of Hours parked
                        // counm refers to duration of Minutes parked
                        // rate refers to the parking charges per minute
                        // total refers to the total duration of time the vehicle was parked in minutes


    int couny,counmo,cound,counh,counm;
    int rate;
    rate=1;
    int total;


                        // counting the duration of Years parked


    couny=b-a;


                        // counting the duration of Months parked if Exit Month more than or equal to Entry Month


    if(d>=c)
    {
        counmo=d-c;
    }


                        // counting the duration of Months parked if Exit Month less than Entry Month


    if(d<c)
    {
        counmo=12-c+d;
        couny=couny-1;
    }


                        // counting the duration of Days parked if Exit Day more than or equal to Entry Day


    if(l>=e)
    {
        cound=l-e;
    }


                        // counting the duration of Days parked if Exit Day less than Entry Day


    if(l<e)
    {
        cound=date(c,a)-e+l;
        counmo=counmo-1;
    }


                        // counting the duration of Hours parked if Exit Hour more than or equal to Entry Hour


    if(n>=m)
    {
        counh=n-m;
    }


                        // counting the duration of Hours parked if Exit Hour less than Entry Hour


    if(n<m)
    {
        counh=24-m+n;
        cound=cound-1;
    }


                        // counting the duration of Minutes parked if Exit Minute more than or equal to Entry Minute


    if(p>=o)
    {
        counm=p-o;
    }


                        // counting the duration of Minutes parked if Exit Minute less than Entry Minute


    if(p<o)
    {
        counm=60-o+p;
        counh=counh-1;
    }


                        // displaying the user about the duration of Years parked
                        // displaying the user about the duration of Months parked
                        // displaying the user about the duration of Days parked
                        // displaying the user about the duration of Hours parked
                        // displaying the user about the duration of Minutes parked
                        // calculating the total duration of parking in minutes
                        // displaying the user the total duration of the vehicle parked in minutes
                        // displaying the user about the price rate of parking per minute
                        // calculating the total amount of money to be paid in rupees
                        // displaying the user the total amount of money to be paid in rupees


    printf("\nThe vehicle was parked for.....");
    printf("\n%d years",couny);
    printf("\n%d months",counmo);
    printf("\n%d days",cound);
    printf("\n%d hours",counh);
    printf("\n%d minutes\n\n",counm);
    total=(couny*12*30*24*60)+(counmo*30*24*60)+(cound*24*60)+(counh*60)+counm;
    printf("Therefore your total time duration of parking is %d minutes\n",total);
    printf("The rate of parking here is Rs %d per minute\n",rate);
    printf("Therefore the total cost of parking of this vehicle here is %d x %d = Rs %d\n\n",total,rate,total*rate);
}



                        // a User defined function named en is declared
                        // it takes user input like......
                        // Vehicle Number
                        // Entry Year
                        // Entry Month
                        // Entry Day
                        // Entry Hour
                        // Entry Minute
                        // it takes these data from the user
                        // it puts these data in the array p of structure park
                        // then these data are put in main file parking.txt
                        // it then closes the file



int en()
{
    char check[20];
    i=0,j=0;
    int y,mo,d,h,m;


                        // fp opens the main file parking.txt in read mode


    fp=fopen("parking.txt","r");


                        // it assigns all the value from the file to the array p


    fread(p,sizeof(struct park),200,fp);


                        // it closes fp


    fclose(fp);


                        // it runs the loop till the data in p is of NULL value


    while(p[i].date!='\0')
    {
        i++;
    }


                        // user enters the vehicle number


    printf("Enter the vehicle number: ");
    scanf("%s",&check);


                        // it runs the loop till the data in p is of NULL value
                        // loop is run to check whether another vehicle with same number is already parked in the same parking lot
                        // the program terminates if vehicle with same number is already in the same parking lot because of few reasons


    while(p[j].date!='\0')
    {
        k=strcmp(check,p[j].number);
        if(k==0)
        {
            printf("\nAnother vehicle with same number is in this parking lot!!\n");
            exit(1);
        }
        j++;
    }


                        // if it is a unique vehicle number..... the program goes on
                        // it takes user input like......
                        // Vehicle Number
                        // Entry Year
                        // Entry Month
                        // Entry Day
                        // Entry Hour
                        // Entry Minute


    printf("Enter the entry year: ");
    scanf("%d",&y);
    if(y<2021)
    {
        printf("\nYear not valid\n");
        exit(1);
    }
    else
    {
        p[i].year=y;
    }
    printf("Enter the entry month: ");
    scanf("%d",&mo);
    if(mo<1||mo>12)
    {
        printf("\nMonth not valid\n");
        exit(1);
    }
    else
    {
        p[i].month=mo;
    }
    printf("Enter the entry date: ");
    scanf("%d",&d);
    if(d<1||d>date(mo,y))
    {
        printf("\nDate not valid\n");
        exit(1);
    }
    else
    {
        p[i].date=d;
    }
    printf("Enter the entry hour: ");
    scanf("%d",&h);
    if(h<0||h>23)
    {
        printf("\nHour not valid\n");
        exit(1);
    }
    else
    {
        p[i].hour=h;
    }
    printf("Enter the entry minute: ");
    scanf("%d",&m);
    if(m<0||m>59)
    {
        printf("\nMinute not valid\n");
        exit(1);
    }
    else
    {
        p[i].minute=m;
    }
    strcpy(p[i].number,check);


                        // fp opens the main file parking.txt in write mode
                        // it assigns all the values in the array p in parking.txt
                        // it closes the file after writing


    fp=fopen("parking.txt","w");
    fwrite(p,sizeof(struct park),200,fp);
    printf("\nYour vehicle is registered successfully..... Park in any of the free space\n\n");
    fclose(fp);
}


                        // a User defined function named sh is declared
                        // its purpose is to display all the vehicles currently in the parking lot with their details to the user


int sh()
{
    i=0;


                        // fp opens the main file parking.txt in read mode
                        // it assigns all the data in the file to the array p
                        // it then closes the file


    fp=fopen("parking.txt","r");
    fread(p,sizeof(struct park),200,fp);
    fclose(fp);


                        // it checks if there are any vehicle currently in the parking lot


    if(p[0].date==0)
    {
        printf("\nNo vehicle is currently parked in this parking lot!!\n\n");
    }


                        // if there are vehicles currently in the parking lot.......then the program continues


    else
    {
       while(1)
        {


                        // stops displaying as all the vehicle details are displayed


            if(p[i].date==0)
            {
                break;
            }


                        // displays details like......
                        // Vehicle Number
                        // Entry Year
                        // Entry Month
                        // Entry Day
                        // Entry Hour
                        // Entry Minute


            else
            {
                printf("\n**Vehicle number: %s\n",p[i].number);
                printf("**Entry year: Year %d\n",p[i].year);
                printf("**Entry month: %d of the Year\n",p[i].month);
                printf("**Entry date: %d of the Month\n",p[i].date);
                printf("**Entry hour: %d Hrs\n",p[i].hour);
                printf("**Entry minute: %d Mins\n\n",p[i].minute);
                i++;
            }
        }
    }
}


                        // a User defined function named ex is declared
                        // its purpose is to Exit the vehicle out of the parking lot as per the demand of the user


int ex()
{
    i=0,k=0,y=0,q=0;
    int y1,mo1,d1,h1,m1;
    char buff[20];
    int wrcheck=0;


                        // fp opens the main file parking.txt in read mode
                        // it assigns those data in the array p
                        // then it closes the file


    fp=fopen("parking.txt","r");
    fread(p,sizeof(struct park),200,fp);
    fclose(fp);


                        // it checks whether there are any vehicle currently parked in the parking lot


    if(p[0].date==0)
    {
        printf("\nNo vehicle is currently parked in this parking lot!!\n\n");
    }


                        // if there is any vehicle currently parked in the parking lot......then the program goes on


    else
    {


                        // fb opens the buffer file parkingbuff.txt in write mode
                        // and then closes it without writing anything
                        // purpose of this is to clear out any data in parkingbuff.txt


        fb=fopen("parkingbuff.txt","w");
        fclose(fb);


                        // fb opens the buffer file parkingbuff.txt in read mode
                        // and then closes it just by reading the empty file
                        // purpose of this is to clear out any data from the buffer array b as well


        fb=fopen("parkingbuff.txt","r");
        fread(b,sizeof(struct park),200,fb);
        fclose(fb);


                        // user enters the vehicle number


        printf("Enter the vehicle number: ");
        scanf("%s",&buff);


                        // this loop finds out the vehicle in the parking lot
                        // it then displays all the details of the vehicle


        while(i<200)
        {
            k=strcmp(buff,p[i].number);
            if(k==0)
            {
                printf("\n**Vehicle number: %s\n",p[i].number);
                printf("**Entry year: Year %d\n",p[i].year);
                printf("**Entry month: %d of the Year\n",p[i].month);
                printf("**Entry date: %d of the Month\n",p[i].date);
                printf("**Entry hour: %d Hrs\n",p[i].hour);
                printf("**Entry minute: %d Mins\n\n",p[i].minute);
                x=i;
                wrcheck=1;
                break;
            }
            else
            {
                i++;
            }
        }
        if(wrcheck==0)
        {
            printf("\nNo vehicle by that number was parked in the parking lot!!\n");
            exit(1);
        }


                        // it assigns the respective values of the desired vehicle in the specified variables
                        // eny refers to Entry Year
                        // enmo refers to Entry Month
                        // end refers to Entry Day
                        // enh refers to Entry Hour
                        // enm refers to Entry Minute


        eny=p[x].year;
        enmo=p[x].month;
        end=p[x].date;
        enh=p[x].hour;
        enm=p[x].minute;


                        // it takes the input data from the user regarding the Exit of the vehicle
                        // exy refers to Exit Year
                        // exmo refers to Exit Month
                        // exd refers to Exit Day
                        // exh refers to Exit Hour
                        // exm refers to Exit Minute


        printf("Enter the exit year: ");
        scanf("%d",&y1);
        if(y1<2021)
        {
            printf("\nYear not valid\n");
            exit(1);
        }
        else if(y1<eny)
        {
            printf("\nYear not valid\n");
            exit(1);
        }
        else
        {
            exy=y1;
        }
        printf("Enter the exit month: ");
        scanf("%d",&mo1);
        if(mo1<1||mo1>12)
        {
            printf("\nMonth not valid\n");
            exit(1);
        }
        else if(eny==exy&&mo1<enmo)
        {
            printf("\nMonth not valid\n");
            exit(1);
        }
        else
        {
            exmo=mo1;
        }
        printf("Enter the exit date: ");
        scanf("%d",&d1);
        if(d1<1||d1>date(mo1,y1))
        {
            printf("\nDate not valid\n");
            exit(1);
        }
        else if(eny==exy&&enmo==exmo&&d1<end)
        {
            printf("\nDate not valid\n");
            exit(1);
        }
        else
        {
            exd=d1;
        }
        printf("Enter the exit hour: ");
        scanf("%d",&h1);
        if(h1<0||h1>23)
        {
            printf("\nHour not valid\n");
            exit(1);
        }
        else if(eny==exy&&enmo==exmo&&d1==end&&h1<enh)
        {
            printf("\nHour not valid\n");
            exit(1);
        }
        else
        {
            exh=h1;
        }
        printf("Enter the exit minute: ");
        scanf("%d",&m1);
        if(m1<0||m1>59)
        {
            printf("\nMinute not valid\n");
            exit(1);
        }
        else if(eny==exy&&enmo==exmo&&d1==end&&h1==enh&&m1<enm)
        {
            printf("\nMinute not valid\n");
            exit(1);
        }
        else
        {
            exm=m1;
        }


                        // the User defined function named dur is executed here


        dur(eny,exy,enmo,exmo,end,exd,enh,exh,enm,exm);


                        // fp opens the main file parking.txt in read mode
                        // it assigns those data in the array p
                        // then it closes the file


        fp=fopen("parking.txt","r");
        fread(p,sizeof(struct park),200,fp);
        fclose(fp);


                        // it runs a loop till the whole array length
                        // it takes all the values from the main array p
                        // then puts the data in the buffer array b
                        // the only thing is that it skips the vehicle details that is chosen by the user


        for(y=0;y<200;y++)
        {
            if(y!=x)
            {
                strcpy(b[q].number,p[y].number);
                b[q].year=p[y].year;
                b[q].month=p[y].month;
                b[q].date=p[y].date;
                b[q].hour=p[y].hour;
                b[q].minute=p[y].minute;
                q++;
            }
        }


                        // fb opens the buffer file parkingbuff.txt in write mode
                        // then all the data in the buffer array b is pasted in the buffer file
                        // then the file is closed


        fb=fopen("parkingbuff.txt","w");
        fwrite(b,sizeof(struct park),200,fb);
        fclose(fb);


                        // fb opens the buffer file parkingbuff.txt in read mode
                        // then all the data from the buffer file is pasted in the buffer array b
                        // then the file is closed
                        // this prevents unexpected errors


        fb=fopen("parkingbuff.txt","r");
        fread(b,sizeof(struct park),200,fb);
        fclose(fb);


                        // fp opens the main file parking.txt in write mode
                        // and then closes it without writing anything
                        // purpose of this is to clear out any data in parking.txt


        fp=fopen("parking.txt","w");
        fclose(fp);


                        // fp opens the main file parking.txt in read mode
                        // and then closes it just by reading the empty file
                        // purpose of this is to clear out any data from the main array p as well


        fp=fopen("parking.txt","r");
        fread(p,sizeof(struct park),200,fp);
        fclose(fp);


                        // this loop copies all data from the buffer array b
                        // then paste them in the main array p


        for(r=0;r<200;r++)
        {
            strcpy(p[r].number,b[r].number);
            p[r].year=b[r].year;
            p[r].month=b[r].month;
            p[r].date=b[r].date;
            p[r].hour=b[r].hour;
            p[r].minute=b[r].minute;
        }


                        // fp opens the main file parking.txt in write mode
                        // writes all the data from main array p to the main file
                        // it then closes the file


        fp=fopen("parking.txt","w");
        fwrite(p,sizeof(struct park),200,fp);
        fclose(fp);


                        // fb opens the buffer file parkingbuff.txt in write mode
                        // and then closes it without writing anything
                        // purpose of this is to clear out any data in parkingbuff.txt


        fb=fopen("parkingbuff.txt","w");
        fclose(fb);


                        // fb opens the buffer file parkingbuff.txt in read mode
                        // and then closes it just by reading the empty file
                        // purpose of this is to clear out any data from the buffer array b as well


        fb=fopen("parkingbuff.txt","r");
        fread(b,sizeof(struct park),200,fb);
        fclose(fb);
        printf("Vehicle with this number can now leave the parking lot!!\n\n");
    }
}


                        // the main program starts from here
                        // its purpose is to grant users options about which service they want to use in the system
                        // it then takes input from the user regarding the options
                        // it then executes the functions as per the option input


int main()
{
    int op;
    while(1)
    {
        printf("Enter from the following options:\n");
        printf("1. Entry\n");
        printf("2. Exit\n");
        printf("3. Show parking status\n");
        printf("4. Quit system\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        if(op==1)
        {
            en();
        }
        else if(op==2)
        {
            ex();
        }
        else if(op==3)
        {
            sh();
        }
        else if(op==4)
        {
            printf("\nThank You!!\n");
            break;
        }
        else
        {
            printf("Enter correct option!!\n");
        }
    }
}
