#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void login();
void deposit();
void withdraw();
void pin_change();
void bal_enq();
int ch,bal=2000,amount,i,pin1[]={'5','5','0','8'},pin[5];
char ch2;
int main()
{
clrscr();
login();
getch();
return 0;
}
void login()
{
int c=4,j=0;
clrscr();
printf("welcome to atm services \n");
printf("_____________________________\n");
printf("\t login details \n");
label:
printf("enter your pin number \n");
for(i=0;i<4;i++)
{
   pin[i]=getch();
   printf("*");
}
for(i=0;i<4;i++)
{
if(pin[i]==pin1[i])
j++;
else
{   c--;
   printf("\nincorrect pin \n");
   printf("you have %d attempts still \n",c);
   if(c!=0)
   goto label;
   else
   {
      printf("too many attempts \n");
      printf("try again later \n");

      getch();
      exit(0);
   }
}
}
if(j==4)
{
printf("\nlogin sucessful\n");
printf("welcome to atm services \n");
label2:
printf("1.deposit\n2.withdraw\n3.pin change\n4.balance enquiry \n5.exit\n");
printf("enter your choice \n");
scanf("%d",&ch);
switch(ch)
{
case 1:deposit();
break;
case 2:withdraw();
break;
case 3:pin_change();
break;
case 4:bal_enq();
break;
case 5:exit(0);
break;
default : printf("invalid choice \n");
}
printf("want to make another transaction (y/n):\n");
ch2=getch();
printf("%c",ch2);
if(ch2 == 'y')
goto label2;
printf("thankyou.. visit again \n");
       }
}
void withdraw()
{
printf("enter the withdrawal ammount \n");
scanf("%d",amount);
if(amount>=bal)
printf("insufficient balance \n");
else
bal=bal-amount;
printf("amount withdrawal successfully \n");
printf("available balance is %d\n",bal);
}
void deposit()
{
printf("enter the deposit amount \n");
scanf("%d",&amount);
bal=bal+amount;
printf("amount deposited successfully \n");
printf("available balance is %d\n",bal);
}
void pin_change()
{
int k=0;
printf("enter the old pin \n");
for(i=0;i<4;i++)
{
   pin[i]=getch();
   printf("*");
}
for(i=0;i<4;i++)
{
   if(pin[i]==pin1[i])
   k++;
   else
   {
   printf("incorrect pin number \n");
   }
}
if(k==4)
{
printf("enter the new pin number \n");
for(i=0;i<4;i++)
scanf("%d",pin1[i]);
printf("pin number changed successfully \n");
}
}
void bal_enq()
{
printf("the avialable balance is %d",bal);
}