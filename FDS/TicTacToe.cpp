#include<iostream>
using namespace std;
char array[] = {'1','2','3','4','5','6','7','8','9'};
int main()
{
    int p=1, choice;
    while(1)
    {
        cout<<"\n";
        for(int i=0;i<9;i++)
        {
            cout<<"|";
            if(i==3 || i==6)
            {
                cout<<"\n";
                cout<<"|";
            }
            cout<<array[i];
        }
        if(p==9)
        {
            cout<<"Game Draw!";
            exit(1);
        }
        cout<<"|";
        if(array[0]==array[1] && array[1]==array[2])
        {
            if(array[0]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[0]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[3]==array[4] && array[4]==array[5])
        {
            if(array[3]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[3]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[6]==array[7] && array[7]==array[8])
        {
            if(array[6]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[6]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[0]==array[3] && array[3]==array[6])
        {
            if(array[0]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[0]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[1]==array[4] && array[4]==array[7])
        {
            if(array[1]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[1]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[2]==array[5] && array[5]==array[8])
        {
            if(array[2]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[2]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[0]==array[4] && array[4]==array[8])
        {
            if(array[0]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[0]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        if(array[2]==array[4] && array[4]==array[6])
        {
            if(array[2]=='X')
            {
                cout<<"\nPlayer 1 won!";
                exit(1);
            }
            else if(array[2]=='O')
            {
                cout<<"\nPlayer 2 won!";
                exit(1);
            }
        }
        cout<<"\nPlayer "<<p<<" : ";
        cin>>choice;
        if(p%2==1)
        {
            if(choice == 1 && array[0]=='1')
            {
                array[0] = 'X';
                p++;
            }
            if(choice == 2 && array[1]=='2')
            {
                array[1] = 'X';
                p++;
            }
            if(choice == 3 && array[2]=='3')
            {
                array[2] = 'X';
                p++;
            }
            if(choice == 4 && array[3]=='4')
            {
                array[3] = 'X';
                p++;
            }
            if(choice == 5 && array[4]=='5')
            {
                array[4] = 'X';
                p++;
            }
            if(choice == 6 && array[5]=='6')
            {
                array[5] = 'X';
                p++;
            }
            if(choice == 7 && array[6]=='7')
            {
                array[6] = 'X';
                p++;
            }
            if(choice == 8 && array[7]=='8')
            {
                array[7] = 'X';
                p++;
            }
            if(choice == 9 && array[8]=='9')
            {
                array[8] = 'X';
                p++;
            }
            else if(choice>9)
            {
                cout<<"\nWrong choice!";
            }
        }
        if(p%2==0)
        {
            if(choice == 1 && array[0]=='1')
            {
                array[0] = 'O';
                p++;
            }
            if(choice == 2 && array[1]=='2')
            {
                array[1] = 'O';
                p++;
            }
            if(choice == 3 && array[2]=='3')
            {
                array[2] = 'O';
                p++;
            }
            if(choice == 4 && array[3]=='4')
            {
                array[3] = 'O';
                p++;
            }
            if(choice == 5 && array[4]=='5')
            {
                array[4] = 'O';
                p++;
            }
            if(choice == 6 && array[5]=='6')
            {
                array[5] = 'O';
                p++;
            }
            if(choice == 7 && array[6]=='7')
            {
                array[6] = 'O';
                p++;
            }
            if(choice == 8 && array[7]=='8')
            {
                array[7] = 'O';
                p++;
            }
            if(choice == 9 && array[8]=='9')
            {
                array[8] = 'O';
                p++;
            }
            else if(choice > 9)
            {
                cout<<"\nWrong choice!";
            }
        }
    }
}
