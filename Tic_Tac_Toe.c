/********************************************************TIC TOC TIE******************************************************************/
/*
Name : Samarth Rajendra Sangar.
Date : 18/11/2024
Project name : Tic Toc Tie game
*/
#include<stdio.h>                       //including header file's
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "Tic_toc_tie.h"

void Pattern()                          //function call to print box pattern
{
        if(turn==2)                     //based on condition print user entry value's
        {
            for(int i=0; i<Box_flag2; i++)
            printf("%d",p2[i]);
        }
        else if(turn==1)
        {
            for(int i=0; i<Box_flag1; i++)
            printf("%d",p1[i]);
        }
        printf("\n\n\r");               //loop to print box pattren with values
        for(int i=0; i<13; i++)
        {
            printf("\t\t\t\t\t");
            for(int j=0; j<24; j++)
            {
                if(i==4 || i==8 || i==12 || i==0)
                    printf("-");
                else if(j==0 || j==8 || j==16 || j==23)
                    printf("|");
                else if(i==2 && j==4 && patter[1]!=0)
                    printf("%c",patter[1]);
                else if(i==2 && j==12 && patter[2]!=0)
                    printf("%c",patter[2]);
                else if(i==2 && j==20 && patter[3]!=0)
                    printf("%c",patter[3]);
                else if(i==6 && j==4 && patter[4]!=0)
                    printf("%c",patter[4]);
                else if(i==6 && j==12 && patter[5]!=0)
                    printf("%c",patter[5]);
                else if(i==6 && j==20 && patter[6]!=0)
                    printf("%c",patter[6]);
                else if(i==10 && j==4 && patter[7]!=0)
                    printf("%c",patter[7]);
                else if(i==10 && j==12 && patter[8]!=0)
                    printf("%c",patter[8]);
                else if(i==10 && j==20 && patter[9]!=0)
                    printf("%c",patter[9]);
                else
                printf(" ");
            }
            printf("\n");
    }
}
void Loading()                                      //function for loading game
{
    int flag=0;
    for(int i=0; i<=6; i++)                         //running loop & display loading game
    {
            printf("\r\t\t            ");
            printf("\r\t\tLOADING");
            for(int k=0; k<3; k++)
            {
                printf(".");
                fflush(stdout);
                usleep(200000);                     //make some delay
            }
    }
}
int Win_Loss_chcek()                                //fuction to chcek win or not
{
    int flag=0;
    if(Check[1]==Check[2] && Check[1]==Check[3] && Check[2]==Check[3])
        flag=1;
    else if(Check[1]==Check[4] && Check[1]==Check[7] && Check[4]==Check[7])
        flag=1;
    else if(Check[1]==Check[5] && Check[1]==Check[9] && Check[5]==Check[9])
        flag=1;
    else if(Check[3]==Check[6] && Check[3]==Check[9] && Check[6]==Check[9])
        flag=1;
    else if(Check[2]==Check[5] && Check[2]==Check[8] && Check[5]==Check[8])
        flag=1;
    else if(Check[3]==Check[5] && Check[3]==Check[7] && Check[5]==Check[7])
        flag=1;
    else if(Check[4]==Check[5] && Check[4]==Check[6] && Check[5]==Check[6])
        flag=1;
    else if(Check[7]==Check[8] && Check[7]==Check[9] && Check[8]==Check[9])
        flag=1;

    if(flag==1)                                         //based on flag value print win & take user entry
    {
        printf("\t\tCongrats %s, You win !!\n\t\tWnat to play Again (Y/N) : ",turn==1?Player1:player2);
        scanf(" %c",&c);
        if(c!='Y' && c!='y')
            exit(0);
        else
            return 1;
    }
    return 0;
}

int checking(int x)                                    //chceking rather than 1-9 entry
{
    if(x==0)                                           //if true return 1 else 0
        return 1;
    int flag=0;
    for(int i=0; i<Box_flag1; i++)
    {
        if(p1[i]==x)
            flag++;
        if(p2[i]==x)
            flag++;
        if(p1[i]>=10 || p2[i]>=10)
            flag++;
    }
    if(flag>1)
        return 1;
    return 0;
}
int Tic_Toc_Tie()                                   //function to take player 1 & 2 entry 1 by 1 based on flag
{
    while(count<=9)
    {
        label1:
        system("clear");
        if(turn==1)
            Pattern();
        else
            Pattern();
        if(count==9)                            //count reaches 9 means break the loop
            break;
        if((Win_Loss_chcek())==1)               //win or loss
            return 1;

        if(count%2!=0)                          //based on count value take players entry      
        {
            printf("\r\t\t%s [O] :",player2);
            scanf("%d",&p2[Box_flag2++]);
            if((checking(p2[(Box_flag2)-1]))==1)        //chcek entry first
            {
                    turn=1;
                    Box_flag2--;
                    goto label1;
            }
            else
                turn=2;
            count++;
            patter[(p2[(Box_flag2)-1])]='O';
            Check[(p2[(Box_flag2)-1])]='O';
        }
        else{
            printf("\r\t\t%s [X] :",Player1);
            scanf("%d",&p1[Box_flag1++]);
            if((checking(p1[(Box_flag1)-1]))==1)            //check entry first
            {
                    turn=2;
                    Box_flag1--;
                    goto label1;
            }
            else
                turn=1;
            count++;
            patter[(p1[(Box_flag1)-1])]='X';
            Check[(p1[(Box_flag1)-1])]='X';
        }
    }
    printf("\t\tGame draw --> want to play again !!(Y/N) : ");      //after loop break print draw & take entry from user
    scanf(" %c",&c);
    if((c!='Y' && c!='y'))
        return 0;
    return 1;
}
int main()                              //main loop
{
    while(1)                            //continuous while loop
    {
        p1=calloc(5,sizeof(int));       //memeory allocation
        p2=calloc(5,sizeof(int));
        system("clear");                //clear screen & print prompt to user
        printf("\t\t************************************************************************\n");
        printf("\t\t----------------------------TIC TAC TOE---------------------------------\n");
        printf("\t\t************************************************************************\n\n\r");
        Loading();                      //function call to loading bar
        printf("\r\t\tWant to play !! (Y/N) : ");        //take entry from user
        scanf(" %c",&c);
        if((c!='Y' && c!='y'))
            break;
        printf("\t\tEnter Player1 Name : ");
        scanf(" %[^\n]",Player1);
        printf("\t\tEnter Player2 Name : ");
        scanf(" %[^\n]",player2);
        printf("\n\t\t[[%s --> X]\t[%s --> O]]\n",Player1,player2);         //print prompt
        printf("\n\t\tNote : Enter 1-9 to select box!\n");
        patter=calloc(10,sizeof(char));                         //memory allocation
        Check=malloc(10*sizeof(char));
        for(int i=1; i<11; i++)                                 //storing values into array
        {
            patter[i]=i+48;
            Check[i]=i+48;
        }
        Pattern();                          //printing Box pattren
        memset(patter,0,10);                //momoey clear
        printf("\n\t\tContinue (Y/N) : ");  //take entry from user
        scanf(" %c",&c);
        if((c!='Y' && c!='y'))
            break;
        system("clear");                    //system clear
        Loading();                          //call loading bar function
        system("clear");                    //system clear
        turn=1;                             //make flag 1
        label :
        printf("\r\t\t%s [X] :",Player1);   //take entry of first player
        scanf("%d",&p1[Box_flag1++]);
        if((checking(p1[(Box_flag1)-1]))==1)    //chcek entry
        {
                Box_flag1--;
                goto label;
        }
        count++;                            //increase  count & store char into array
        patter[(p1[(Box_flag1)-1])]='X';
        Check[(p1[(Box_flag1)-1])]='X';
        if(Tic_Toc_Tie()==1)                //call function & based on return value continue again
        {
            free(Check);
            free(patter);
            Box_flag1=0;
            Box_flag2=0;
            count=0;
            turn=0;
            system("clear");                //system clear
            continue;
        }
        else                                //else break super loop
            break;
    }
}