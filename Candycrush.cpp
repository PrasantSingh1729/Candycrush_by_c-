#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iomanip>

using namespace std;

//random symbol generator
char random()
{
    char arr[4]={'%','#','&','@'};

    int temp=rand()%4;
    return arr[temp];
}

int main() {

//creating matrix
//****************************************************************************************************************************
    srand(time(NULL)); // randomize the each run

    int n;



    int point=0;

    cin>>n;

    int num=n;
    int digit=0;
    while(num>0)
    {
        digit++;
        num=num/10;
    }

    char mat[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                mat[i][j]=random();
            }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-2;j++)
            {
                if(mat[i][j]==mat[i][j+1] && mat[i][j+1]==mat[i][j+2])
                {
                    char temp=mat[i][j];
                    char ran=mat[i][j];
                    while(ran==temp)
                    {
                        ran=random();
                    }
                    mat[i][j+1]=ran;
                }
            }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-2;j++)
            {
                if(mat[j][i]==mat[j+1][i] && mat[j+1][i]==mat[j+2][i])
                {
                    char temp=mat[j][i];
                    char ran=mat[j][i];
                    while(ran==temp)
                    {

                        ran=random();
                        if(i+1<n && ran==mat[j][i+1])
                            ran=temp;
                        if(i-1>=0 && ran==mat[j][i-1])
                            ran=temp;
                    }
                    mat[j+1][i]=ran;
                }
            }
    }
    system("pause");
//**********************************************************************************************************



    //display
//**********************************************************************************************************
    while(1)
    {
        system("cls");

        cout<<setw(digit+1+1);
        for(int i=0;i<n;i++)
        {
                            if(i>0)
                {
                    cout<<setw(digit);
                }
            cout<<i+1<<" ";
        }
        cout<<"\n";

        for(int i=0;i<n;i++)
        {
            int temp=i+1;
            int d=0;
            while(temp>0)
            {
                d++;
                temp=temp/10;
            }

            cout<<i+1<<" ";
            cout<<setw(digit-d+1);
            for(int j=0;j<n;j++)
            {
                int t=j+1;
                int D=0;
                while(t>0)
                {
                    D++;
                    t=t/10;
                }
                if(j>0)
                {
                    cout<<setw(digit);
                }
                cout<<mat[i][j]<<" ";
            }

             cout<<"\n";

        }
        cout<<"Points:"<<point<<endl;
//***********************************************************************************************************

//user input and verification of input
//**********************************************************************************************************
        int a1[2],a2[2];
        cout<<"Swap : ";
        cin>>a1[0]>>a1[1];
        cout<<"with : ";
        cin>>a2[0]>>a2[1];

        //checking
        if(abs(a1[0]-a2[0])>1 || abs(a1[1]-a2[1])>1)
        {
            cout<<"\nInvalid Move\n";
            system("pause");
            continue;
        }
        if(abs(a1[0]-a2[0])==1 && abs(a1[1]-a2[1])==1)
        {
            cout<<"\nInvalid Move\n";
            system("pause");
            continue;
        }
        if(a1[0]>n || a2[0]>n || a1[1]>n || a2[1]>n)
        {
            cout<<"\nInvalid Move\n";
            system("pause");
            continue;
        }

        if(abs(a1[0]-a2[0])==0 && abs(a1[1]-a2[1])==0)
        {
            cout<<"\nInvalid Move\n";
            system("pause");
            continue;
        }

        //swapping
        int temp=mat[a1[0]-1][a1[1]-1];
        mat[a1[0]-1][a1[1]-1]=mat[a2[0]-1][a2[1]-1];
        mat[a2[0]-1][a2[1]-1]=temp;


        //re display
        system("cls");

        cout<<setw(digit+1+1);
        for(int i=0;i<n;i++)
        {
                            if(i>0)
                {
                    cout<<setw(digit);
                }
            cout<<i+1<<" ";
        }
        cout<<"\n";

        for(int i=0;i<n;i++)
        {
            int temp=i+1;
            int d=0;
            while(temp>0)
            {
                d++;
                temp=temp/10;
            }

            cout<<i+1<<" ";
            cout<<setw(digit-d+1);
            for(int j=0;j<n;j++)
            {
                int t=j+1;
                int D=0;
                while(t>0)
                {
                    D++;
                    t=t/10;
                }
                if(j>0)
                {
                    cout<<setw(digit);
                }
                cout<<mat[i][j]<<" ";
            }

             cout<<"\n";

        }
        cout<<"Points:"<<point<<endl;
//******************************************************************************************************


//counting matching around
//******************************************************************************************************
        int rflag=0,cflag=0;
        int left=0,right=0;
        int up=0,down=0;
        for(int i=1;rflag==0;i++)
        {
            if(mat[a2[0]-1][a2[1]-1]==mat[a2[0]-1][a2[1]-1+i] && a2[1]-1+i<n && right==i-1)
            {
                right++;
            }
            if(mat[a2[0]-1][a2[1]-1]==mat[a2[0]-1][a2[1]-1-i] && a2[1]-1-i>=0 && left==i-1)
            {
                left++;
            }
            if(right!=i && left!=i)
                break;
        }
        for(int i=1;cflag==0;i++)
        {
            if(mat[a2[0]-1][a2[1]-1]==mat[a2[0]-1+i][a2[1]-1] && a2[0]-1+i<n && down==i-1)
            {
                down++;
            }
            if(mat[a2[0]-1][a2[1]-1]==mat[a2[0]-1-i][a2[1]-1] && a2[0]-1-i>=0 && up==i-1)
            {
                up++;
            }
            if(up!=i && down!=i)
                break;
        }


//decision on the bases of number of similar symbol found around swap symbol
        if(left+right<2 && up+down<2)
        {
            cout<<"\n"<<"No group form\n";
            system("pause");
            //swapping back to prevent changes
            int temp=mat[a1[0]-1][a1[1]-1];
            mat[a1[0]-1][a1[1]-1]=mat[a2[0]-1][a2[1]-1];
            mat[a2[0]-1][a2[1]-1]=temp;

        }
       else                             //deleting row and column of matching symbols
        {
            int upper=a2[0]-up-1;
            int lower=a2[0]+down-1;
           if(up+down>=2)
           {
            point=point+up+down+1;
            for(int i=lower,j=upper-1;i>=0 || j>=0 ;i--,j--)
            {
                if(j<0)
                {
                        char ran='a';
                        char t='a';
                        while(ran=='a')
                    {

                        ran=random();
                        if(a2[1]-1+1<n && ran==mat[i][a2[1]-1+1])
                            ran=t;
                        if(a2[1]-1-1>=0 && ran==mat[i][a2[1]-1-1])
                            ran=t;
                        if(i+1<n && ran==mat[i+1][a2[1]-1])
                            ran=t;
                    }
                    mat[i][a2[1]-1]=ran;
                }
                else
                {

                 mat[i][a2[1]-1]=mat[j][a2[1]-1];
                }
            }
           }

            upper=a2[0]-1;
            lower=a2[0]-1;

     if(left+right>=2)
     {

            if(up+down<2)
            {
                for(int i=lower,j=upper-1,p=0;i>=0 || j>=0 ;i--,j--)
                {
                    if(j<0)
                    {
                        char ran='a';
                        char t='a';
                        while(ran=='a')
                    {

                        ran=random();
                        if(a2[1]-1-p+1<n && ran==mat[i][a2[1]-1-p+1])
                            ran=t;
                        if(a2[1]-1-p-1>=0 && ran==mat[i][a2[1]-1-p-1])
                            ran=t;
                        if(i+1<n && ran==mat[i+1][a2[1]-1-p])
                            ran=t;
                    }
                        mat[i][a2[1]-1-p]=ran;
                    }
                    else
                    {

                        mat[i][a2[1]-1-p]=mat[j][a2[1]-1-p];
                    }
                }
            }
            point=point+left+right+1;
            for(int p=1;p<=left;p++)
            {
                for(int i=lower,j=upper-1;i>=0 || j>=0 ;i--,j--)
                {
                    if(j<0)
                    {
                        char ran='a';
                        char t='a';
                        while(ran=='a')
                    {

                        ran=random();
                        if(a2[1]-1-p+1<n && ran==mat[i][a2[1]-1-p+1])
                            ran=t;
                        if(a2[1]-1-p-1>=0 && ran==mat[i][a2[1]-1-p-1])
                            ran=t;
                        if(i+1<n && ran==mat[i+1][a2[1]-1-p])
                            ran=t;
                    }
                        mat[i][a2[1]-1-p]=ran;
                    }
                    else
                    {

                        mat[i][a2[1]-1-p]=mat[j][a2[1]-1-p];
                    }
                }

            }

            for(int p=1;p<=right;p++)
            {
                for(int i=lower,j=upper-1;i>=0 || j>=0 ;i--,j--)
                {
                    if(j<0)
                    {
                        char t='a';
                        char ran='a';
                        while(ran=='a')
                        {

                            ran=random();
                            if(a2[1]-1+p+1<n && ran==mat[i][a2[1]-1+p+1])
                                ran=t;
                            if(a2[1]-1+p-1>=0 && ran==mat[i][a2[1]-1+p-1])
                                ran=t;
                            if(i+1<n && ran==mat[i+1][a2[1]-1+p])
                                ran=t;
                        }
                        mat[i][a2[1]-1+p]=random();
                    }
                    else
                    {

                        mat[i][a2[1]-1+p]=mat[j][a2[1]-1+p];
                    }
                }

            }


        }
        system("pause");
    }

    }

    return 0;

}
