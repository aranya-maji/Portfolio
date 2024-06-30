#include<iostream>
#include<graphics.h>
#include<charconv>
#include<conio.h>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

                                            //nodes with 4 directional nodes created for the Sudoku chart
                                            //data saves the data in the node
                                            //x and y saves the x and y coordinate for the data of the node (used by graphics)
                                            //location is the key to find out the exact node
                                            //nodes left, right, top, bottom are 4 directional child nodes

class Node
{
public:
    int data;
    int x;
    int y;
    int location;
    Node *left;
    Node *right;
    Node *top;
    Node *bottom;
};

                                            //head and pointers are assigned for different purposes

Node *head_sudoku = NULL;
Node *ptr1_temp = NULL;
Node *ptr2_temp = NULL;
Node *ptr3_temp = NULL;
Node *ptr4_temp = NULL;
Node *ptr5_temp = NULL;
Node *ptr_cur = NULL;

                                            //different variables are called for different purposes

int c = -1;
int val;
char *value = new char[1];
int x_axis;
int y_axis;
int loc = 0;
int check_value;
int Count = 81;

                                            //this function check checks whether the value to be put in the Sudoku chart follows the rules of Sudoku or not
                                            //it returns 0 if the value to be inserted satisfies the rules of Sudoku
                                            //it returns 1 if the value to be inserted does not satisfies the rules of Sudoku

void check()
{
    check_value = 0;
    ptr3_temp = ptr_cur;

    while(ptr3_temp->left != NULL)
    {
        ptr3_temp = ptr3_temp->left;
        if(val == ptr3_temp->data)
        {
            cout<<"Input invalid!! at e1"<<endl;
            delay(3000);
            check_value = 1;
            goto B;
        }
    }

    ptr3_temp = ptr_cur;
    while(ptr3_temp->top != NULL)
    {
        ptr3_temp = ptr3_temp->top;
        if(val == ptr3_temp->data)
        {
            cout<<"Input invalid!! at e2"<<endl;
            delay(3000);
            check_value = 1;
            goto B;
        }
    }

    ptr3_temp = ptr_cur;
    while(ptr3_temp->bottom != NULL)
    {
        ptr3_temp = ptr3_temp->bottom;
        if(val == ptr3_temp->data)
        {
            cout<<"Input invalid!! at e3"<<endl;
            delay(3000);
            check_value = 1;
            goto B;
        }
    }

    ptr3_temp = ptr_cur;
    while(ptr3_temp->right != NULL)
    {
        ptr3_temp = ptr3_temp->right;
        if(val == ptr3_temp->data)
        {
            cout<<"Input invalid!! at e4"<<endl;
            delay(3000);
            check_value = 1;
            goto B;
        }
    }

    ptr3_temp = ptr_cur;
    if(ptr3_temp->location == 1 || ptr3_temp->location == 2 || ptr3_temp->location == 3 || ptr3_temp->location == 10 || ptr3_temp->location == 11 || ptr3_temp->location == 12 || ptr3_temp->location == 19 || ptr3_temp->location == 20 || ptr3_temp->location == 21)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 1 || ptr4_temp->location == 2 || ptr4_temp->location == 3 || ptr4_temp->location == 10 || ptr4_temp->location == 11 || ptr4_temp->location == 12 || ptr4_temp->location == 19 || ptr4_temp->location == 20 || ptr4_temp->location == 21)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 1 || ptr4_temp->location == 2 || ptr4_temp->location == 3 || ptr4_temp->location == 10 || ptr4_temp->location == 11 || ptr4_temp->location == 12 || ptr4_temp->location == 19 || ptr4_temp->location == 20 || ptr4_temp->location == 21)
            {
                if(ptr4_temp->data == ptr3_temp->data)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e6"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 4 || ptr3_temp->location == 5 || ptr3_temp->location == 6 || ptr3_temp->location == 13 || ptr3_temp->location == 14 || ptr3_temp->location == 15 || ptr3_temp->location == 22 || ptr3_temp->location == 23 || ptr3_temp->location == 24)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 4 || ptr4_temp->location == 5 || ptr4_temp->location == 6 || ptr4_temp->location == 13 || ptr4_temp->location == 14 || ptr4_temp->location == 15 || ptr4_temp->location == 22 || ptr4_temp->location == 23 || ptr4_temp->location == 24)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 4 || ptr4_temp->location == 5 || ptr4_temp->location == 6 || ptr4_temp->location == 13 || ptr4_temp->location == 14 || ptr4_temp->location == 15 || ptr4_temp->location == 22 || ptr4_temp->location == 23 || ptr4_temp->location == 24)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 7 || ptr3_temp->location == 8 || ptr3_temp->location == 9 || ptr3_temp->location == 16 || ptr3_temp->location == 17 || ptr3_temp->location == 18 || ptr3_temp->location == 25 || ptr3_temp->location == 26 || ptr3_temp->location == 27)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 7 || ptr4_temp->location == 8 || ptr4_temp->location == 9 || ptr4_temp->location == 16 || ptr4_temp->location == 17 || ptr4_temp->location == 18 || ptr4_temp->location == 25 || ptr4_temp->location == 26 || ptr4_temp->location == 27)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 7 || ptr4_temp->location == 8 || ptr4_temp->location == 9 || ptr4_temp->location == 16 || ptr4_temp->location == 17 || ptr4_temp->location == 18 || ptr4_temp->location == 25 || ptr4_temp->location == 26 || ptr4_temp->location == 27)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 28 || ptr3_temp->location == 29 || ptr3_temp->location == 30 || ptr3_temp->location == 37 || ptr3_temp->location == 38 || ptr3_temp->location == 39 || ptr3_temp->location == 46 || ptr3_temp->location == 47 || ptr3_temp->location == 48)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 28 || ptr4_temp->location == 29 || ptr4_temp->location == 30 || ptr4_temp->location == 37 || ptr4_temp->location == 38 || ptr4_temp->location == 39 || ptr4_temp->location == 46 || ptr4_temp->location == 47 || ptr4_temp->location == 48)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 28 || ptr4_temp->location == 29 || ptr4_temp->location == 30 || ptr4_temp->location == 37 || ptr4_temp->location == 38 || ptr4_temp->location == 39 || ptr4_temp->location == 46 || ptr4_temp->location == 47 || ptr4_temp->location == 48)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 31 || ptr3_temp->location == 32 || ptr3_temp->location == 33 || ptr3_temp->location == 40 || ptr3_temp->location == 41 || ptr3_temp->location == 42 || ptr3_temp->location == 49 || ptr3_temp->location == 50 || ptr3_temp->location == 51)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 31 || ptr4_temp->location == 32 || ptr4_temp->location == 33 || ptr4_temp->location == 40 || ptr4_temp->location == 41 || ptr4_temp->location == 42 || ptr4_temp->location == 49 || ptr4_temp->location == 50 || ptr4_temp->location == 51)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 31 || ptr4_temp->location == 32 || ptr4_temp->location == 33 || ptr4_temp->location == 40 || ptr4_temp->location == 41 || ptr4_temp->location == 42 || ptr4_temp->location == 49 || ptr4_temp->location == 50 || ptr4_temp->location == 51)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 34 || ptr3_temp->location == 35 || ptr3_temp->location == 36 || ptr3_temp->location == 43 || ptr3_temp->location == 44 || ptr3_temp->location == 45 || ptr3_temp->location == 52 || ptr3_temp->location == 53 || ptr3_temp->location == 54)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 34 || ptr4_temp->location == 35 || ptr4_temp->location == 36 || ptr4_temp->location == 43 || ptr4_temp->location == 44 || ptr4_temp->location == 45 || ptr4_temp->location == 52 || ptr4_temp->location == 53 || ptr4_temp->location == 54)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 34 || ptr4_temp->location == 35 || ptr4_temp->location == 36 || ptr4_temp->location == 43 || ptr4_temp->location == 44 || ptr4_temp->location == 45 || ptr4_temp->location == 52 || ptr4_temp->location == 53 || ptr4_temp->location == 54)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 55 || ptr3_temp->location == 56 || ptr3_temp->location == 57 || ptr3_temp->location == 64 || ptr3_temp->location == 65 || ptr3_temp->location == 66 || ptr3_temp->location == 73 || ptr3_temp->location == 74 || ptr3_temp->location == 75)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 55 || ptr4_temp->location == 56 || ptr4_temp->location == 57 || ptr4_temp->location == 64 || ptr4_temp->location == 65 || ptr4_temp->location == 66 || ptr4_temp->location == 73 || ptr4_temp->location == 74 || ptr4_temp->location == 75)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 55 || ptr4_temp->location == 56 || ptr4_temp->location == 57 || ptr4_temp->location == 64 || ptr4_temp->location == 65 || ptr4_temp->location == 66 || ptr4_temp->location == 73 || ptr4_temp->location == 74 || ptr4_temp->location == 75)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 58 || ptr3_temp->location == 59 || ptr3_temp->location == 60 || ptr3_temp->location == 67 || ptr3_temp->location == 68 || ptr3_temp->location == 69 || ptr3_temp->location == 76 || ptr3_temp->location == 77 || ptr3_temp->location == 78)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 58 || ptr4_temp->location == 59 || ptr4_temp->location == 60 || ptr4_temp->location == 67 || ptr4_temp->location == 68 || ptr4_temp->location == 69 || ptr4_temp->location == 76 || ptr4_temp->location == 77 || ptr4_temp->location == 78)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 58 || ptr4_temp->location == 59 || ptr4_temp->location == 60 || ptr4_temp->location == 67 || ptr4_temp->location == 68 || ptr4_temp->location == 69 || ptr4_temp->location == 76 || ptr4_temp->location == 77 || ptr4_temp->location == 78)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }

    else if(ptr3_temp->location == 61 || ptr3_temp->location == 62 || ptr3_temp->location == 63 || ptr3_temp->location == 70 || ptr3_temp->location == 71 || ptr3_temp->location == 72 || ptr3_temp->location == 79 || ptr3_temp->location == 80 || ptr3_temp->location == 81)
    {
        ptr4_temp = head_sudoku;
        int i,j,a,b;
        for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
            {
                if(ptr4_temp->location == 61 || ptr4_temp->location == 62 || ptr4_temp->location == 63 || ptr4_temp->location == 70 || ptr4_temp->location == 71 || ptr4_temp->location == 72 || ptr4_temp->location == 79 || ptr4_temp->location == 80 || ptr4_temp->location == 81)
                {
                    if(ptr4_temp->data == val)
                    {
                        check_value = 1;
                        cout<<"Input invalid!! at e5"<<endl;
                        delay(3000);
                        goto B;
                    }
                }

                if(ptr4_temp->right != NULL)
                {
                    ptr4_temp = ptr4_temp->right;
                }
            }

            if(ptr4_temp->location == 61 || ptr4_temp->location == 62 || ptr4_temp->location == 63 || ptr4_temp->location == 70 || ptr4_temp->location == 71 || ptr4_temp->location == 72 || ptr4_temp->location == 79 || ptr4_temp->location == 80 || ptr4_temp->location == 81)
            {
                if(ptr4_temp->data == val)
                {
                    check_value = 1;
                    cout<<"Input invalid!! at e5"<<endl;
                    delay(3000);
                    goto B;
                }
            }

            for(j=0;j<8;j++)
            {
                ptr4_temp = ptr4_temp->left;
            }
            ptr4_temp = ptr4_temp->bottom;
        }
    }
    B:
    int x;
}

                                            //this function action allows user to decide what to do depending upon the situation
                                            //whether to insert value, erase a value or skip insertion
                                            //it allows user to freely move left to right and top to bottom across the Sudoku chart

void action()
{
    char c;
    cout<<"Enter value (Press 0 to skip and -1 to erase):- ";
    cin>>val;

    if(val == -1)
    {
        cout<<endl<<val<<endl;
        ptr_cur->data = val;
    }

    else if(val != 0)
    {
        check();
        if(check_value != 0)
        {
            goto C;
        }
        Count--;

        if(Count == 0)
        {
            cout<<endl<<"You won!!"<<endl;
            exit(1);
        }
        ptr_cur->data = val;
    }
    C:
    system("CLS");
    cout<<"Press-\nw to go up\ns to go down\na to go left\nd to go right"<<endl;
    cout<<"Enter your choice:- ";
    cin>>c;

    if(c == 'w' && ptr_cur->top != NULL)
    {
        ptr_cur = ptr_cur->top;
    }

    else if(c == 's' && ptr_cur->bottom != NULL)
    {
        ptr_cur = ptr_cur->bottom;
    }

    else if(c == 'a' && ptr_cur->left != NULL)
    {
        ptr_cur = ptr_cur->left;
    }

    else if(c == 'd' && ptr_cur->right != NULL)
    {
        ptr_cur = ptr_cur->right;
    }
}

                                            //this function display works to display the values as a graphical representation

void Display()
{
    Node *ptr1_temp = head_sudoku;
    int i,j,a,b;
    for(i=0;i<9;i++)
    {
        for(j=0;j<8;j++)
        {
            to_chars(value,value + 1,ptr1_temp->data);
            outtextxy(ptr1_temp->x,ptr1_temp->y,value);
            if(ptr1_temp->right != NULL)
            {
                ptr1_temp = ptr1_temp->right;
            }
        }
        to_chars(value,value + 1,ptr1_temp->data);
        outtextxy(ptr1_temp->x,ptr1_temp->y,value);
        for(j=0;j<8;j++)
        {
            ptr1_temp = ptr1_temp->left;
        }
        ptr1_temp = ptr1_temp->bottom;
    }
    setcolor(YELLOW);
    outtextxy(ptr_cur->x,ptr_cur->y,"X");
    setcolor(WHITE);
    action();
}

                                            //this function Sudoku_visual forms the graphics window
                                            //it forms the whole Sudoku chart

void Sudoku_visual()
{
    initwindow(500,500);
    A:
    setcolor(YELLOW);
    setlinestyle(0,0,1);
    line(10,10,10,478);
    line(10,478,478,478);
    line(10,10,478,10);
    line(478,10,478,478);
    line(10,62,478,62);
    line(10,114,478,114);
    setlinestyle(0,0,3);
    setcolor(RED);
    line(10,166,478,166);
    setlinestyle(0,0,1);
    setcolor(YELLOW);
    line(10,218,478,218);
    line(10,270,478,270);
    setlinestyle(0,0,3);
    setcolor(RED);
    line(10,322,478,322);
    setlinestyle(0,0,1);
    setcolor(YELLOW);
    line(10,374,478,374);
    line(10,426,478,426);
    line(62,10,62,478);
    line(114,10,114,478);
    setlinestyle(0,0,3);
    setcolor(RED);
    line(166,10,166,478);
    setlinestyle(0,0,1);
    setcolor(YELLOW);
    line(218,10,218,478);
    line(270,10,270,478);
    setlinestyle(0,0,3);
    setcolor(RED);
    line(322,10,322,478);
    setlinestyle(0,0,1);
    setcolor(YELLOW);
    line(374,10,374,478);
    line(426,10,426,478);
    setcolor(WHITE);
    Display();
    system("CLS");
    cleardevice();
    goto A;
    getch();
    closegraph();
}

                                            //this function setStartValues set initial values in the Sudoku chart to start with

void setStartValues()
{
    ptr5_temp = head_sudoku;
    int i,j,a,b;
    for(i=0;i<9;i++)
    {
        for(j=0;j<8;j++)
        {
            if(ptr5_temp->location == 1)
            {
                ptr5_temp->data = 9;
                Count--;
            }

            if(ptr5_temp->location == 3)
            {
                ptr5_temp->data = 3;
                Count--;
            }

            if(ptr5_temp->location == 5)
            {
                ptr5_temp->data = 8;
                Count--;
            }

            if(ptr5_temp->location == 6)
            {
                ptr5_temp->data = 5;
                Count--;
            }

            if(ptr5_temp->location == 7)
            {
                ptr5_temp->data = 6;
                Count--;
            }

            if(ptr5_temp->location == 8)
            {
                ptr5_temp->data = 2;
                Count--;
            }

            if(ptr5_temp->location == 11)
            {
                ptr5_temp->data = 5;
                Count--;
            }

            if(ptr5_temp->location == 12)
            {
                ptr5_temp->data = 1;
                Count--;
            }

            if(ptr5_temp->location == 14)
            {
                ptr5_temp->data = 6;
                Count--;
            }

            if(ptr5_temp->location == 17)
            {
                ptr5_temp->data = 8;
                Count--;
            }

            if(ptr5_temp->location == 20)
            {
                ptr5_temp->data = 2;
                Count--;
            }

            if(ptr5_temp->location == 21)
            {
                ptr5_temp->data = 8;
                Count--;
            }

            if(ptr5_temp->location == 24)
            {
                ptr5_temp->data = 9;
                Count--;
            }

            if(ptr5_temp->location == 25)
            {
                ptr5_temp->data = 1;
                Count--;
            }

            if(ptr5_temp->location == 29)
            {
                ptr5_temp->data = 9;
                Count--;
            }

            if(ptr5_temp->location == 31)
            {
                ptr5_temp->data = 4;
                Count--;
            }

            if(ptr5_temp->location == 33)
            {
                ptr5_temp->data = 3;
                Count--;
            }

            if(ptr5_temp->location == 39)
            {
                ptr5_temp->data = 5;
                Count--;
            }

            if(ptr5_temp->location == 43)
            {
                ptr5_temp->data = 7;
                Count--;
            }

            if(ptr5_temp->location == 49)
            {
                ptr5_temp->data = 6;
                Count--;
            }

            if(ptr5_temp->location == 51)
            {
                ptr5_temp->data = 7;
                Count--;
            }

            if(ptr5_temp->location == 53)
            {
                ptr5_temp->data = 1;
                Count--;
            }

            if(ptr5_temp->location == 57)
            {
                ptr5_temp->data = 4;
                Count--;
            }

            if(ptr5_temp->location == 58)
            {
                ptr5_temp->data = 5;
                Count--;
            }

            if(ptr5_temp->location == 61)
            {
                ptr5_temp->data = 9;
                Count--;
            }

            if(ptr5_temp->location == 62)
            {
                ptr5_temp->data = 7;
                Count--;
            }

            if(ptr5_temp->location == 64)
            {
                ptr5_temp->data = 3;
                Count--;
            }

            if(ptr5_temp->location == 65)
            {
                ptr5_temp->data = 1;
                Count--;
            }

            if(ptr5_temp->location == 68)
            {
                ptr5_temp->data = 7;
                Count--;
            }

            if(ptr5_temp->location == 70)
            {
                ptr5_temp->data = 8;
                Count--;
            }

            if(ptr5_temp->location == 71)
            {
                ptr5_temp->data = 5;
                Count--;
            }

            if(ptr5_temp->location == 74)
            {
                ptr5_temp->data = 7;
                Count--;
            }

            if(ptr5_temp->location == 75)
            {
                ptr5_temp->data = 9;
                Count--;
            }

            if(ptr5_temp->location == 76)
            {
                ptr5_temp->data = 8;
                Count--;
            }

            if(ptr5_temp->location == 77)
            {
                ptr5_temp->data = 2;
                Count--;
            }

            if(ptr5_temp->location == 79)
            {
                ptr5_temp->data = 3;
                Count--;
            }

            if(ptr5_temp->right != NULL)
            {
                ptr5_temp = ptr5_temp->right;
            }
        }

        if(ptr5_temp->location == 18)
        {
            ptr5_temp->data = 9;
            Count--;
        }

        if(ptr5_temp->location == 81)
        {
            ptr5_temp->data = 6;
            Count--;
        }

        for(j=0;j<8;j++)
        {
            ptr5_temp = ptr5_temp->left;
        }
        ptr5_temp = ptr5_temp->bottom;
    }
}

                                            //this function Sudoku_base builds Sudoku chart with multi list
                                            //the multi list is formed out of quad - linked list
                                            //it assigns new nodes to the Sudoku chart to complete it
                                            //it assigns the key location of each node and the x and y coordinates for the data of the node (used by graphics)

void Sudoku_base()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        if(ptr1_temp == NULL)
        {
            Node *t = new Node;
            t->data = c;
            x_axis = 32;
            y_axis = 32;
            loc++;
            t->location = loc;
            t->x = x_axis;
            t->y = y_axis;
            t->top = NULL;
            t->bottom = NULL;
            t->left = NULL;
            t->right = NULL;
            ptr1_temp = t;
        }
        else
        {
            Node *t = new Node;
            t->data = c;
            x_axis = x_axis + 52;
            t->x = x_axis;
            t->y = y_axis;
            loc++;
            t->location = loc;
            t->top = NULL;
            t->bottom = NULL;
            t->right = NULL;
            t->left = ptr1_temp;
            ptr1_temp->right = t;
            ptr1_temp = t;
        }
    }
    for(j=0;j<8;j++)
    {
        for(i=0;i<8;i++)
        {
            ptr1_temp = ptr1_temp->left;
            x_axis = x_axis - 52;
        }
        ptr2_temp = ptr1_temp;
        ptr1_temp = ptr1_temp->bottom;
        y_axis = y_axis + 52;
        x_axis = 0;
        for(i=0;i<9;i++)
        {
            if(ptr1_temp == NULL)
            {
                Node *t = new Node;
                t->data = c;
                x_axis = 32;
                t->x = x_axis;
                t->y = y_axis;
                loc++;
                t->location = loc;
                t->top = ptr2_temp;
                ptr2_temp->bottom = t;
                t->bottom = NULL;
                t->left = NULL;
                t->right = NULL;
                ptr1_temp = t;
            }
            else
            {
                Node *t = new Node;
                t->data = c;
                x_axis = x_axis + 52;
                t->x = x_axis;
                t->y = y_axis;
                loc++;
                t->location = loc;
                t->top = ptr2_temp;
                ptr2_temp->bottom = t;
                t->bottom = NULL;
                t->right = NULL;
                t->left = ptr1_temp;
                ptr1_temp->right = t;
                ptr1_temp = t;
            }
            ptr2_temp = ptr2_temp->right;
        }
    }
    for(i=0;i<8;i++)
    {
        ptr1_temp = ptr1_temp->left;
        x_axis = x_axis - 52;
    }
    for(i=0;i<8;i++)
    {
        ptr1_temp = ptr1_temp->top;
        y_axis = y_axis - 52;
    }
    head_sudoku = ptr1_temp;
    ptr_cur = head_sudoku;
    setStartValues();
    Sudoku_visual();
}

void SudokuGame_Main()
{
    Sudoku_base();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int score=0,x,y,f1x,f1y;

                                            //definition of each node of snake body

class snake
{
public:
    int sx;
    int sy;
    char direction;
    snake*next;
    snake*prev;
};

                                            //definition of each food node

class food
{
public:
    int fx;
    int fy;
    int food_count;
};

                                            //function initializing game area

void game_area()
{
    char buf[100];
    rectangle(50,50,754,754);
    rectangle(52,52,752,752);
    rectangle(54,54,750,750);
    outtextxy(365,760,"SNAKE GAME");
    outtextxy(770,430,"SCORE:");
    sprintf(buf,"%d",score);
    outtextxy(850,430,buf);
}

                                            //function which is called when snake hits the wall or hits itself

void game_over()
{
    char buf[100];
    cleardevice();
    rectangle(300,300,754,754);
    rectangle(302,302,752,752);
    rectangle(304,304,750,750);
    settextstyle(8,0,5);
    outtextxy(400,470,"GAME OVER!!");
    outtextxy(400,510,"SCORE:");
    sprintf(buf,"%d",score);
    outtextxy(550,510,buf);
    delay(750);
    exit(1);
}

                                            //This function generates food at random places if consumed

void create_food(food *f1,int x,int y)
{
    food *temp=new food;
    f1=temp;
    f1->fx=x;
    f1->fy=y;
    setfillstyle(SOLID_FILL,YELLOW);
    circle(f1->fx,f1->fy,8);
    floodfill(f1->fx,f1->fy,15);
}


food *f1=NULL;
snake *head;

                                            //This function adds up a node in snakes body upon consumption of food

void inc_size(snake *head,int a,int b)
{
    snake * ptr=new snake;
    ptr->sx=a;
    ptr->sy=b;
    snake*temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=ptr;
    ptr->prev=temp;
    ptr->next=NULL;
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(ptr->sx-6,ptr->sy-6,ptr->sx+6,ptr->sy+6);
    floodfill(ptr->sx-5,ptr->sy-5,15);
}

                                            //This function displays snake after every movement

void snake_display(snake *head)
{
    snake*ptr=head;
    snake*ptr1=head;

    while(ptr!=NULL)
    {
        setfillstyle(SOLID_FILL,GREEN);
        rectangle(ptr->sx-6,ptr->sy-6,ptr->sx+6,ptr->sy+6);
        floodfill(ptr->sx-5,ptr->sy-5,15);
        ptr=ptr->next;
    }
    setfillstyle(SOLID_FILL,RED);
    floodfill(ptr1->sx-5,ptr1->sy-5,15);
}

                                            //This function checks if snake has collided with itself

void check_defeat(snake*head)
{
    snake*ptr=head;
    snake*ptr1=ptr->next;

    while(ptr->next!=NULL)
    {
        while(ptr1!=NULL)
        {
            if(ptr->sx==ptr1->sx&&ptr->sy==ptr1->sy)
            {
                game_over();
            }
            ptr1=ptr1->next;
        }
        ptr=ptr->next;
    }
}

                                            //This function check if snake has collided with walls

void check_collison(snake *head)
{
    if (head->sx<=54||head->sx>=754||head->sy<=54||head->sy>=754)
    {
        game_over();
    }
}

                                            //This function checks if food has been consumed

int check_food(snake*head,food*f1)
{
    if((head->sx>=f1x-8 && head->sx<=f1x+8) && (head->sy>=f1y-8 && head->sy<=f1y+8) )
    {
        score=score+100;

        x=59+(rand()%682);
        y=59+(rand()%682);

        f1x=x;
        f1y=y;
        create_food(f1,f1x,f1y);
        return 9;
    }
}

                                            //This function begins the game and call various functions
                                            //like checking food consumption,
                                            //wall collision,self collision.

void game(snake *head , food *f1)
{
    game_area();
    head=new snake;
    head->next=NULL;
    int a=200;
    int b=200;
    snake*temp=new snake;
    temp->sx=a;
    temp->sy=b;
    temp->next=NULL;
    temp->prev=NULL;
    head=temp;
    setfillstyle(SOLID_FILL,RED);
    rectangle(head->sx-6,head->sy-6,head->sx+6,head->sy+6);
    floodfill(head->sx-5,head->sy-5,15);
    inc_size(head,head->sx+12,head->sy);
    inc_size(head,head->sx+24,head->sy);
    inc_size(head,head->sx+36,head->sy);

    srand ((unsigned) time(NULL));
    x=59+(rand()%682);
    y=59+(rand()%682);

    f1x=x;
    f1y=y;

    create_food(f1,f1x,f1y);


    cout<<"CHOOSE AN OPTION:"<<endl;
    cout<<"->PRESS 'w' TO GO UP"<<endl;
    cout<<"->PRESS 's' TO GO DOWN"<<endl;
    cout<<"->PRESS 'a' TO GO LEFT"<<endl;
    cout<<"->PRESS 'd' TO GO RIGHT"<<endl;

    char k;
    e:
    cout<<"PRESS ENTER:"<<endl;
    cin>>k;

    system("CLS");
    cout<<"CHOOSE AN OPTION:"<<endl;
    cout<<"->PRESS 'w' TO GO UP"<<endl;
    cout<<"->PRESS 's' TO GO DOWN"<<endl;
    cout<<"->PRESS 'a' TO GO LEFT"<<endl;
    cout<<"->PRESS 'd' TO GO RIGHT"<<endl;
    if(k=='w')
    {
        a:
        while(1)
        {
            if (GetAsyncKeyState(65))
            {
                goto b;
            }
            else if (GetAsyncKeyState(83))
            {
                goto c;
            }
            else if (GetAsyncKeyState(68))
            {
                goto d;
            }
            else if (GetAsyncKeyState(87))
            {
                goto a;
            }
            if(head->sy > head->next->sy)
            {
                outtextxy(770,445,"This move not possible");
                outtextxy(770,465,"Press 'a','s','d'");
                goto e;
            }

            snake*ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            if(head->next!=NULL)
            {
                while(ptr!=head)
                {
                    ptr->sx=ptr->prev->sx;
                    ptr->sy=ptr->prev->sy;
                    ptr=ptr->prev;
                }
                head->sy=head->sy-12;
            }
            else
            {
                head->sy=head->sy-12;
            }

            snake *ptr1=head;
            while(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            delay(150);
            cleardevice();
            game_area();
            create_food(f1,f1x,f1y);
            snake_display(head);
            check_collison(head);
            if(check_food(head,f1)==9)
            {
                inc_size(head,ptr1->sx,ptr1->sy+12);
            }
            check_defeat(head);
        }
    }



    else if(k=='s')
    {
        c:
        while(1)
        {
            if (GetAsyncKeyState(65))
            {
                goto b;
            }
            else if (GetAsyncKeyState(83))
            {
                goto c;
            }
            else if (GetAsyncKeyState(68))
            {
                goto d;
            }
            else if (GetAsyncKeyState(87))
            {
                goto a;
            }
            if(head->sy < head->next->sy)
            {
                outtextxy(770,445,"This move not possible");
                outtextxy(770,465,"Press 'a','d','w'");
                goto e;
            }
            snake*ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            if(head->next!=NULL)
            {
                while(ptr!=head)
                {
                    ptr->sx=ptr->prev->sx;
                    ptr->sy=ptr->prev->sy;
                    ptr=ptr->prev;
                }
                head->sy=head->sy+12;
            }
            else
            {
                head->sy=head->sy+12;
            }
            snake *ptr1=head;
            while(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            delay(150);
            cleardevice();
            game_area();
            create_food(f1,f1x,f1y);
            snake_display(head);
            check_collison(head);
            check_defeat(head);
            if(check_food(head,f1)==9)
            {
                inc_size(head,ptr1->sx,ptr1->sy-12);
            }
        }
    }

    else if(k=='a')
    {
        b:
        while(1)
        {
            if (GetAsyncKeyState(65))
            {
                goto b;
            }
            else if (GetAsyncKeyState(83))
            {
                goto c;
            }
            else if (GetAsyncKeyState(68))
            {
                goto d;
            }
            else if (GetAsyncKeyState(87))
            {
                goto a;
            }
            if(head->sx > head->next->sx)
            {
                outtextxy(770,445,"This move not possible");
                outtextxy(770,465,"Press 'd','s','w'");
                goto e;
            }
            snake*ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            if(head->next!=NULL)
            {
                while(ptr!=head)
                {
                    ptr->sx=ptr->prev->sx;
                    ptr->sy=ptr->prev->sy;
                    ptr=ptr->prev;
                }
                head->sx=head->sx-12;
            }
            else
            {
                head->sx=head->sx-12;
            }
            snake *ptr1=head;
            while(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            delay(150);
            cleardevice();
            game_area();
            create_food(f1,f1x,f1y);
            snake_display(head);
            check_collison(head);
            check_defeat(head);
            if(check_food(head,f1)==9)
            {
                inc_size(head,ptr1->sx+12,ptr1->sy);
            }
        }
    }

    else if(k=='d')
    {
        d:
        while(1)
        {
            if (GetAsyncKeyState(65))
            {
                goto b;
            }
            else if (GetAsyncKeyState(83))
            {
                goto c;
            }
            else if (GetAsyncKeyState(68))
            {
                goto d;
            }
            else if (GetAsyncKeyState(87))
            {
                goto a;
            }

            if(head->sx < head->next->sx)
            {
                outtextxy(770,445,"This move not possible");
                outtextxy(770,465,"Press 'a','s','w'");
                goto e;
            }

            snake*ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            if(head->next!=NULL)
            {
                while(ptr!=head)
                {
                    ptr->sx=ptr->prev->sx;
                    ptr->sy=ptr->prev->sy;
                    ptr=ptr->prev;
                }
                head->sx=head->sx+12;
            }
            else
            {
                head->sx=head->sx+12;
            }
            snake *ptr1=head;
            while(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            delay(150);
            cleardevice();
            game_area();
            create_food(f1,f1x,f1y);
            snake_display(head);
            check_collison(head);
            check_defeat(head);
            if(check_food(head,f1)==9)
            {
                inc_size(head,ptr1->sx-12,ptr1->sy);
            }
        }
    }
}

void snake_game()
{
    initwindow(950,900);
    game(head,f1);
    getch();
    closegraph();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                            //this singly linked list  will create be implemented to create a stack for each player
class Stack
{
public:
    int data;
    Stack *next;
};

                                            //this function will push the given parameter in stack
void push(Stack **stack1,int x)
{
    Stack *temp=new Stack;
    temp->data=x;
    temp->next=*stack1;
    *stack1=temp;
}

                                            //this function will pop the top of the stack
void pop(Stack **stack1)
{
    Stack *ptr=*stack1;
    Stack *temp;
    temp=ptr;
    ptr=ptr->next;
    delete(temp);
    *stack1=ptr;
}

//this function will give the top value of the stack
int top(Stack **stack1)
{
    Stack *ptr=*stack1;
    return ptr->data;
}

                                            //this function will check if the player has
                                            //stepped on a ladder or on a snake
                                            //and will change it's position accordingly
void condition(Stack **stack1)
{
    if(top(stack1)==9)
    {
        cout<<"WOOHOO!! YOU STEPPED ON A LADDER"<<endl;
        int x=9;
        while(top(stack1)!=93)
        {
            push(stack1,x);
            x++;
        }
    }
    else if(top(stack1)==16)
    {
        cout<<endl;
        cout<<"WOOHOO!! YOU STEPPED ON A LADDER"<<endl;
        int x=16;
        while(top(stack1)!=30)
        {
            push(stack1,x);
            x++;
        }
    }
    else if(top(stack1)==43)
    {
        cout<<endl;
        cout<<"WOOHOO!! YOU STEPPED ON A LADDER"<<endl;
        int x=43;
        while(top(stack1)!=52)
        {
            push(stack1,x);
            x++;
        }
     }
     else if(top(stack1)==29)
     {
        cout<<endl;
        cout<<"ALAS!! YOU STEPPED ON A SNAKE"<<endl;
        while(top(stack1)!=13)
        {
            pop(stack1);
        }
    }
    else if(top(stack1)==99)
    {
        cout<<endl;
        cout<<"ALAS!! YOU STEPPED ON A SNAKE"<<endl;
        while(top(stack1)!=2)
        {
            pop(stack1);
        }
    }
    else if(top(stack1)==67)
    {
        cout<<endl;
        cout<<"ALAS!! YOU STEPPED ON A SNAKE";
        int x=43;
        while(top(stack1)!=35)
        {
            pop(stack1);
        }
    }
}

                                            //it will create the graphics window of game
void game_page()
{
    char buff[100];
    rectangle(50,50,450,450);
    line(90,50,90,450);
    line(130,50,130,450);
    line(170,50,170,450);
    line(210,50,210,450);
    line(250,50,250,450);
    line(290,50,290,450);
    line(330,50,330,450);
    line(370,50,370,450);
    line(410,50,410,450);
    line(50,410,450,410);
    line(50,370,450,370);
    line(50,330,450,330);
    line(50,290,450,290);
    line(50,250,450,250);
    line(50,210,450,210);
    line(50,170,450,170);
    line(50,130,450,130);
    line(50,90,450,90);
    setcolor(GREEN);
    setlinestyle(0,0,3);
    line(230,390,430,350);
    line(150,270,390,230);
    line(390,430,350,70);
    setlinestyle(0,0,0);
    setcolor(WHITE);
    setcolor(RED);
    setlinestyle(0,0,3);
    line(390,350,350,390);
    line(110,70,110,430);
    line(270,310,310,190);
    setlinestyle(0,0,0);
    setcolor(WHITE);
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i);
        outtextxy(70+(40*(i-1)),430,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+20);
        outtextxy(70+(40*(i-1)),350,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+40);
        outtextxy(70+(40*(i-1)),270,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+60);
        outtextxy(70+(40*(i-1)),190,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+80);
        outtextxy(70+(40*(i-1)),110,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+10);
        outtextxy(430-(40*(i-1)),390,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+30);
        outtextxy(430-(40*(i-1)),310,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+50);
        outtextxy(430-(40*(i-1)),230,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+70);
        outtextxy(430-(40*(i-1)),150,buff);
    }
    for (int i=1;i<=10;i++)
    {
        sprintf(buff,"%d",i+90);
        outtextxy(430-(40*(i-1)),70,buff);
    }
 }

                                            //this function will create a token on the current stack top
create_player(int t)
{
    if(t>=1&&t<=10)
    {
        circle(70+40*(t-1),430,7);
        floodfill(70+40*(t-1),430,15);
    }
    else if(t>=21&&t<=30)
    {
        circle(70+40*(t-21),350,7);
        floodfill(70+40*(t-21),350,15);
    }
    else if(t>=41&&t<=50)
    {
        circle(70+40*(t-41),270,7);
        floodfill(70+40*(t-41),270,15);
    }
    else if(t>=61&&t<=70)
    {
        circle(70+40*(t-61),190,7);
        floodfill(70+40*(t-61),190,15);
    }
    else if(t>=81&&t<=90)
    {
        circle(70+40*(t-81),110,7);
        floodfill(70+40*(t-81),110,15);
    }
    else if(t>=11&&t<=20)
    {
        circle(430-(40*(t-11)),390,7);
        floodfill(430-(40*(t-11)),390,15);
    }
    else if(t>=31&&t<=50)
    {
        circle(430-(40*(t-31)),310,7);
        floodfill(430-(40*(t-31)),310,15);
    }
    else if(t>=51&&t<=70)
    {
        circle(430-(40*(t-51)),230,7);
        floodfill(430-40*(t-51),230,15);
    }
    else if(t>=71&&t<=90)
    {
        circle(430-(40*(t-71)),150,7);
        floodfill(430-(40*(t-71)),150,15);
    }
    else if(t>=91&&t<=100)
    {
        circle(430-(40*(t-91)),70,7);
        floodfill(430-(40*(t-91)),70,15);
    }
 }

                                            //if a player wins this function will show win page
void win(string player)
{
    char arr[100];
    strcpy(arr,player.c_str());
    char buff[100];
    sprintf(buff,"%s WINS",arr);
    cleardevice();
    rectangle(50,50,450,450);
    settextstyle(8,0,5);
    outtextxy(120,200,"GAME OVER!!");
    outtextxy(120,230,buff);
}

                                            //this is main working of game
                                            //two stacks of two players are create
                                            //upon pressing enter dice will roll and will change the players position
                                            //this is done by pushing value in stack till it achieves the final expected value after rolling the dice
                                            //if player steps on ladder it jumps on the position as set using push function
                                            //if player steps on snake it comes down to the position as set using pop function
void snl_main_game(Stack**stack1,Stack ** stack2)
{
    int temp1=0,temp2=0;
    Stack *player1=*stack1;
    Stack *player2=*stack2;
    string player_1,player_2;
    int d1,d2,t1,t2;
    cout<<"Enter name of player 1:"<<endl;
    cin>>player_1;
    cout<<"Enter name of player 2:"<<endl;
    cin>>player_2;
    push(&player1,1);
    t1=top(&player1);
    setfillstyle(SOLID_FILL,RED);
    create_player(t1);
    setfillstyle(SOLID_FILL,WHITE);
    push(&player2,1);
    t2=top(&player2);
    setfillstyle(SOLID_FILL,BLUE);
    create_player(t2);
    setfillstyle(SOLID_FILL,WHITE);
    srand((unsigned) time(NULL));
    while(top(&player1)!=100 || top(&player2)!=100)
    {
        a:
        cout<<player_1<<" press enter to roll the dice:"<<endl;
        c:
        if(_getch()==13)
        {
            d1=1+rand()%6;
            cout<<"you got a "<<d1<<endl;
        }
        temp1=temp1+d1;
        if (d1==6)
        {
            cout<<"It is a SIX!! Roll the dice again"<<endl;
            goto c;
        }
        while(temp1!=0)
        {
            t1=top(&player1);
            if(t1+temp1<100)
            {
                push(&player1,t1+1);
                t1=t1+1;
                temp1--;
            }
            else if (t1+temp1==100)
            {
                cout<<player_1<<" WINS "<<endl;
                win(player_1);
                delay(1000);
                exit(1);
            }
            else
            {
                cout<<"Move Not possible"<<endl;
                temp1=0;
                goto b;
            }
        }
        condition(&player1);
        t1=top(&player1);
        setfillstyle(SOLID_FILL,RED);
        create_player(t1);
        setfillstyle(SOLID_FILL,WHITE);
        cout<<player_1<<" is at "<<top(&player1)<<endl;
        cleardevice();
        game_page();
        condition(&player1);
        t1=top(&player1);
        setfillstyle(SOLID_FILL,RED);
        create_player(t1);
        setfillstyle(SOLID_FILL,WHITE);
        t2=top(&player2);
        setfillstyle(SOLID_FILL,BLUE);
        create_player(t2);
        setfillstyle(SOLID_FILL,WHITE);
        delay(1500);
        system("CLS");
        b:
        cout<<player_2<<" press enter to roll the dice:"<<endl;
        d:
        if(_getch()==13)
        {
            d2=1+rand()%6;
            cout<<"You got a "<<d2<<endl;
        }
        temp2=temp2+d2;
        if(d2==6)
        {
            cout<<"It is a SIX!! Roll the dice again"<<endl;
            goto d;
        }
        while(temp2!=0)
        {
            t2=top(&player2);
            if(t2+temp2<100)
            {
                push(&player2,t2+1);
                t2=t2+1;
                temp2--;
            }
            else if (t2+temp2==100)
            {
                cout<<player_2<<" WINS "<<endl;
                win(player_2);
                delay(1000);
                exit(1);
            }
            else
            {
                cout<<"Move Not possible"<<endl;
                temp2=0;
                goto a;
            }
        }
        condition(&player2);
        t2=top(&player2);
        setfillstyle(SOLID_FILL,BLUE);
        create_player(t2);
        setfillstyle(SOLID_FILL,WHITE);
        cout<<player_2<<" is at "<<top(&player2)<<endl;
        cleardevice();
        game_page();
        condition(&player1);
        t1=top(&player1);
        setfillstyle(SOLID_FILL,RED);
        create_player(t1);
        setfillstyle(SOLID_FILL,WHITE);
        t2=top(&player2);
        setfillstyle(SOLID_FILL,BLUE);
        create_player(t2);
        setfillstyle(SOLID_FILL,WHITE);
        delay(1500);
        system("CLS");
    }
}

void snake_and_ladders()
{
    initwindow(700,500);
    Stack *player_1;
    Stack *player_2;
    game_page();
    snl_main_game(&player_1,&player_2);
    getch();
    closegraph();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                            //global variables declared
                                            //x1 and y1 are for array index
                                            //x2 and y2 are for graphics coordinates

char *arr[3][3];
int x2 = 95;
int y2 = 95;
int x1 = 0;
int y1 = 0;
int remaining = 9;
char *player = "X";

                                            //this function winnerCheck works to find the winner or a tie and show it on the graph

void winnerCheck()
{
    if((arr[0][0] == arr[1][0]) && (arr[0][0] == arr[2][0]) && (arr[1][0] == arr[2][0]) && (arr[0][0] == "X" || arr[0][0] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(95,95,95,395);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[0][0]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[0][0] == arr[0][1]) && (arr[0][0] == arr[0][2]) && (arr[0][1] == arr[0][2]) && (arr[0][0] == "X" || arr[0][0] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(95,95,395,95);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[0][0]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]) && (arr[1][1] == arr[2][2]) && (arr[0][0] == "X" || arr[0][0] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(95,95,395,395);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[0][0]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[2][0] == arr[1][1]) && (arr[2][0] == arr[0][2]) && (arr[1][1] == arr[0][2]) && (arr[2][0] == "X" || arr[2][0] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(95,395,395,95);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[2][0]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[0][1] == arr[1][1]) && (arr[0][1] == arr[2][1]) && (arr[1][1] == arr[2][1]) && (arr[0][1] == "X" || arr[0][1] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(245,95,245,395);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[0][1]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[0][2] == arr[1][2]) && (arr[0][2] == arr[2][2]) && (arr[1][2] == arr[2][2]) && (arr[0][2] == "X" || arr[0][2] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(395,95,395,395);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[0][2]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[1][0] == arr[1][1]) && (arr[1][0] == arr[1][2]) && (arr[1][1] == arr[1][2]) && (arr[1][0] == "X" || arr[1][0] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(95,245,395,245);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[1][0]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if((arr[2][0] == arr[2][1]) && (arr[2][0] == arr[2][2]) && (arr[2][1] == arr[2][2]) && (arr[2][0] == "X" || arr[2][0] == "O"))
    {
        setcolor(GREEN);
        setlinestyle(0,0,5);
        line(95,395,395,395);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        cout<<arr[2][0]<<" is the Winner"<<endl;
        delay(5000);
        exit(1);
    }
    else if(remaining == 0)
    {
        cout<<"It is a tie!!"<<endl;
        delay(5000);
        exit(0);
    }
}

                                            //this function traverse works to move the user pointer to input mark

void traverse()
{
    char c,c1;
    cout<<"Press y to put and other to skip:- ";
    cin>>c1;
    if(c1 == 'y')
    {
        arr[y1][x1] = player;
        cleardevice();
        line(20,170,470,170);
        line(20,320,470,320);
        line(170,20,170,470);
        line(320,20,320,470);
        settextstyle(3,0,10);
        outtextxy(55,35,arr[0][0]);
        outtextxy(205,35,arr[0][1]);
        outtextxy(355,35,arr[0][2]);
        outtextxy(55,185,arr[1][0]);
        outtextxy(205,185,arr[1][1]);
        outtextxy(355,185,arr[1][2]);
        outtextxy(55,335,arr[2][0]);
        outtextxy(205,335,arr[2][1]);
        outtextxy(355,335,arr[2][2]);
        settextstyle(9,0,0);
        setlinestyle(0,0,5);
        setcolor(RED);
        rectangle(x2-70,y2-70,x2+70,y2+70);
        setlinestyle(0,0,1);
        setcolor(WHITE);
        if(player == "X")
        {
            remaining--;
            player = "O";
            winnerCheck();
        }
        else
        {
            remaining--;
            player = "X";
            winnerCheck();
        }
    }
    cout<<"Press\nw to go up\ns to go down\na to go left\nd to go right\nEnter choice:- ";
    cin>>c;
    if(c == 'w')
    {
        if(y2 != 95)
        {
            y2 = y2 - 150;
            y1--;
        }
    }
    else if(c == 's')
    {
        if(y2 != 395)
        {
            y2 = y2 + 150;
            y1++;
        }
    }
    else if(c == 'a')
    {
        if(x2 != 95)
        {
            x2 = x2 - 150;
            x1--;
        }
    }
    else if(c == 'd')
    {
        if(x2 != 395)
        {
            x2 = x2 + 150;
            x1++;
        }
    }
}

                                            //this function setInitial works to assign initial values to the array

void setInitial()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            arr[i][j] = "";
        }
    }
}

                                            //this function tictactoBase works to make the graphics

void tictactoBase()
{
    initwindow(490,490);
    A:
    system("CLS");
    cleardevice();
    line(20,170,470,170);
    line(20,320,470,320);
    line(170,20,170,470);
    line(320,20,320,470);
    settextstyle(3,0,10);
    outtextxy(55,35,arr[0][0]);
    outtextxy(205,35,arr[0][1]);
    outtextxy(355,35,arr[0][2]);
    outtextxy(55,185,arr[1][0]);
    outtextxy(205,185,arr[1][1]);
    outtextxy(355,185,arr[1][2]);
    outtextxy(55,335,arr[2][0]);
    outtextxy(205,335,arr[2][1]);
    outtextxy(355,335,arr[2][2]);
    settextstyle(9,0,0);
    setlinestyle(0,0,5);
    setcolor(RED);
    rectangle(x2-70,y2-70,x2+70,y2+70);
    setlinestyle(0,0,1);
    setcolor(WHITE);
    traverse();
    goto A;
    getch();
    closegraph();
}

                                            //this function tictacto_game sums up all the primary functions

void tictacto_game()
{
    setInitial();
    tictactoBase();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int x;
    cout<<"--------------------- Welcome to The Game World --------------------"<<endl<<endl;
    cout<<"Choose the game:- "<<endl;
    cout<<"1. Sudoku"<<endl;
    cout<<"2. Snake"<<endl;
    cout<<"3. Snake & Ladder"<<endl;
    cout<<"4. Tic-Tac-To"<<endl;
    cout<<"Press any other keys to exit"<<endl;
    cin>>x;
    if(x == 1)
    {
        cout<<"-------------------- Opening Sudoku --------------------";
        delay(4000);
        system("CLS");
        SudokuGame_Main();
    }
    else if(x == 2)
    {
        cout<<"-------------------- Opening Snake --------------------";
        delay(4000);
        system("CLS");
        snake_game();
    }
    else if(x == 3)
    {
        cout<<"-------------------- Opening Snake & Ladder --------------------";
        delay(4000);
        system("CLS");
        snake_and_ladders();
    }
    else if(x == 4)
    {
        cout<<"-------------------- Opening Tic-Tac-To --------------------";
        delay(4000);
        system("CLS");
        tictacto_game();
    }
    else
    {
        cout<<"Thanks for visiting!!"<<endl;
        exit(1);
    }
}
