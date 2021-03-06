#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>
#include <windows.h>
#define Pathway "E:\\pin.txt"
#define NewPathway "E:\\newlist.txt"

typedef struct info
{
int acc_no;
char name[100];
char pincode[100];
char dad[100];
char mom[100];
char Address[100];
char City[100];
char Gender[100];
char EmailAdd[100];
char Religion[100];
char EducAttain[100];
char Occupation[100];
char Senior[100];
int days;
int year;
int Category;
int months;
double balance;

}list;

void gotoxy(int x,int y);
int insertcard();
void Enroll();
int ChooseProcess();
void Process();
int ChooseEditInfo();
void EditInfo();
void DelATM();
void view_user_bank();
int Choosepaybills();
void paybills();
void transfer();
void AccNoValidation();
int PinValidation();
void Trans();
int TransPili();
void Dep();
void Withdraw();
void CheckBal();
void ChangePin();
void view_list();
void removecard();
void reg();
void design();
void design2();
void design3();
void logo();

list luma;
int i,accountNo,flag;
char choose;

int main()
{
 char main_choose;
 type_error:
 fail_detect:
 printf("Do you have Existing Account (Y/N) ? ");
 scanf("%c",&main_choose);

 switch(main_choose)
 {
 case 'Y':
 case 'y':
    system("cls");
    if(insertcard())
        {
            printf("Invalid Atm Please Register First.\n");
            getch();
            system("cls");
            goto fail_detect;
        }
    Process();
    break;
 case 'N':
 case 'n':
    system("cls");
    Enroll();
    break;
 default:
     system("cls");
     goto type_error;

 }


}
void Enroll()
{
  int len,flag,ctr,type_error=0;
  char pili;
  FILE *flashdrive;
  flashdrive=fopen(Pathway,"a+");


  try_again:
  reg();
  //printf("Enter the account number : ");
  gotoxy(15,10);
  scanf("%d",&accountNo);
   while(fscanf(flashdrive,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
   {
      if(accountNo==luma.acc_no)
      {
          type_error++;
      }
   }
  luma.acc_no=accountNo;

    gotoxy(10,16);
    scanf(" %[^\n]",luma.name);
    gotoxy(71,16);
    scanf(" %[^\n]",luma.dad);
    gotoxy(18,21);
    scanf(" %[^\n]",luma.mom);
    gotoxy(80,21);
    scanf("%d",&luma.days);
    gotoxy(99,21);
    scanf("%d",&luma.months);
    gotoxy(115,21);
    scanf("%d",&luma.year);
    gotoxy(13,28);
    scanf(" %[^\n]",luma.Address);
    gotoxy(101,28);
    scanf(" %[^\n]",luma.City);
    gotoxy(11,32);
    scanf("%s",luma.Gender);
    gotoxy(40,32);
    scanf("%s",luma.EmailAdd);
    i=0;
    gotoxy(87,32);
    do{
    if(i==6)
        {
        break;
        }
    else
        {
        luma.pincode[i]=getch();

        if(luma.pincode[i]=='\b')
        {
                if (i<=0)
                    i++;
                else
                {
                    printf("\b \b");
                    i--;
                }
        }
        else if(luma.pincode[i]!='\r'){
                printf("*");
                i++;
        }
    }

}while(luma.pincode[i]!='\r');
luma.pincode[i]='\0';
    gotoxy(13,37);
    scanf(" %[^\n]",luma.Religion);
    cat:
    gotoxy(69,37);
    scanf("%d",&luma.Category);
    if(luma.Category==1)
    {
        gotoxy(71,37);
        printf("Saving Acc.");
    }
    else if(luma.Category==2)
    {
        gotoxy(71,37);
        printf("Money Market Acc.");
    }
    else if(luma.Category==3)
    {
        gotoxy(71,37);
        printf("Certificate of Deposit");
    }
    else if(luma.Category==4)
    {
        gotoxy(71,37);
        printf("Retirement Acc.");
    }
    else
    {
        gotoxy(71,37);
        printf("Error");
        goto cat;
    }
    gotoxy(28,44);
    scanf(" %[^\n]",luma.EducAttain);
    gotoxy(64,44);
    scanf(" %[^\n]",luma.Occupation);
    gotoxy(21,49);
    scanf("%s",luma.Senior);
    gotoxy(55,49);
    scanf("%lf",&luma.balance);
ctr=0;
    gotoxy(0,57);
    printf("Note:");
if(i!=6)
{
    ctr++;
    gotoxy(0,58);
    printf("Please Insert 6 Digits.");

}
i=0;
flag=0;
len=strlen(luma.pincode);
while(i<len)
{
    if(isdigit(luma.pincode[i])==0)
    {
        flag++;
    }
i++;
}

if(flag!=0)
{
    ctr++;
    gotoxy(0,58);
    printf("Please Insert 6 Digits.");

}
if(luma.balance<100)
{
    gotoxy(0,58+ctr);
    printf("Error,Our minimum deposit is 100");
    ctr++;
}
if(type_error==1)
{
    gotoxy(0,58+ctr);
    printf("Error,your Account Number is not availble.\n");
    ctr++;
}
   if(ctr>=1)
   {
    getch();
    system("cls");
    goto try_again;
   }
printf("Do you want to go to Transaction(Y/N) ? ");
scanf(" %c",&pili);
system("cls");

fprintf(flashdrive,"\n%d\n",luma.acc_no);
fprintf(flashdrive,"%s\n",luma.name);
fprintf(flashdrive,"%s\n",luma.dad);
fprintf(flashdrive,"%s\n",luma.mom);
fprintf(flashdrive,"%d\n",luma.days);
fprintf(flashdrive,"%d\n",luma.months);
fprintf(flashdrive,"%d\n",luma.year);
fprintf(flashdrive,"%s\n",luma.Address);
fprintf(flashdrive,"%s\n",luma.City);
fprintf(flashdrive,"%s\n",luma.Gender);
fprintf(flashdrive,"%s\n",luma.EmailAdd);
fprintf(flashdrive,"%s\n",luma.pincode);
fprintf(flashdrive,"%s\n",luma.Religion);
fprintf(flashdrive,"%d\n",luma.Category);
fprintf(flashdrive,"%s\n",luma.EducAttain);
fprintf(flashdrive,"%s\n",luma.Occupation);
fprintf(flashdrive,"%s\n",luma.Senior);
fprintf(flashdrive,"%f\n",luma.balance);

fclose(flashdrive);
if(pili=='Y'||pili=='y')
    {
        flag=1;
        AccNoValidation() ;
    }

}
int insertcard()
{
    FILE *flashdrive;
    i=1;
    char a=219,b=176;
for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
{
 gotoxy(50+i,16);
 printf("%c",a);
}
for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     gotoxy(50+i,17);
     printf("%c",a);
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,18);
     printf("%c",a);
     }
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
  {
    if(i==0||i==49)
     {
     gotoxy(50+i,19);
     printf("%c",a);
     }
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     gotoxy(50+i,20);
     printf("%c",a);
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     gotoxy(50+i,21);
     printf("%c",a);
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,22);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,22);
     printf("%c",b);
     }
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,23);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,23);
     printf("%c",b);
     }
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,24);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,24);
     printf("%c",b);
     }
 }
 for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,25);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,25);
     printf("%c",b);
     }
 }
  for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,26);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,26);
     printf("%c",b);
     }
 }
  for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,27);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,27);
     printf("%c",b);
     }
 }
  for(i=0;i<50;i++) /// THIS IS FOR ATM DESIGN
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,28);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,28);
     printf("%c",b);
     }
 }
  for(i=0;i<50;i++)
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,29);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,29);
     printf("%c",b);
     }
 }
  for(i=0;i<50;i++)
 {
     if(i==0||i==49)
     {
     gotoxy(50+i,30);
     printf("%c",a);
     }
     else
     {
     gotoxy(50+i,30);
     printf("%c",b);
     }
 }
  for(i=0;i<50;i++)
 {
     gotoxy(50+i,31);
     printf("%c",a);
 }

 gotoxy(35,33);
 printf("%c%c%c%c%c%c%c  %c     %c%c%c%c%c   %c%c%c  %c%c%c%c%c %c%c%c%c%c                                \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
 gotoxy(35,34);
 printf("%c      %c %c     %c      %c   %c %c     %c                     \n",a,a,a,a,a,a,a,a);
 gotoxy(35,35);
 printf("%c      %c %c     %c      %c   %c %c     %c                    \n",a,a,a,a,a,a,a,a);
 gotoxy(35,36);
 printf("%c      %c %c     %c      %c   %c %c     %c                            \n",a,a,a,a,a,a,a,a);
 gotoxy(35,37);
 printf("%c%c%c%c%c%c%c  %c     %c%c%c    %c%c%c%c%c %c%c%c%c%c %c%c%c                                \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
 gotoxy(35,38);
 printf("%c        %c     %c      %c   %c     %c %c                                \n",a,a,a,a,a,a,a);
 gotoxy(35,39);
 printf("%c        %c     %c      %c   %c     %c %c                              \n",a,a,a,a,a,a,a);
 gotoxy(35,40);
 printf("%c        %c%c%c%c%c %c%c%c%c%c  %c   %c %c%c%c%c%c %c%c%c%c%c            \n\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);


gotoxy(79,33);
printf("%c  %c    %c   %c%c%c%c%c  %c%c%c%c%c %c%c%c%c%c  %c%c%c%c%c                                \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(79,34);
printf("%c  %c%c   %c   %c      %c     %c   %c    %c                   \n",a,a,a,a,a,a,a,a,a);
gotoxy(79,35);
printf("%c  %c %c  %c   %c      %c     %c   %c    %c                      \n",a,a,a,a,a,a,a,a,a);
gotoxy(79,36);
printf("%c  %c  %c %c   %c      %c     %c   %c    %c                    \n",a,a,a,a,a,a,a,a,a);
gotoxy(79,37);
printf("%c  %c   %c%c   %c%c%c%c%c  %c%c%c%c  %c%c%c%c     %c                          \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(79,38);
printf("%c  %c    %c       %c  %c     %c   %c    %c                      \n",a,a,a,a,a,a,a,a);
gotoxy(79,39);
printf("%c  %c    %c       %c  %c     %c    %c   %c                       \n",a,a,a,a,a,a,a,a);
gotoxy(79,40);
printf("%c  %c    %c   %c%c%c%c%c  %c%c%c%c%c %c    %c   %c                        \n\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

gotoxy(60,44);
printf("%c%c%c%c%c   %c%c%c  %c%c%c%c%c  %c%c%c%c%c                                               \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(60,45);
printf("%c      %c   %c %c   %c  %c    %c                      \n",a,a,a,a,a,a,a);
gotoxy(60,46);
printf("%c      %c   %c %c   %c  %c     %c                     \n",a,a,a,a,a,a,a);
gotoxy(60,47);
printf("%c      %c   %c %c   %c  %c      %c                   \n",a,a,a,a,a,a,a);
gotoxy(60,48);
printf("%c      %c%c%c%c%c %c%c%c%c   %c      %c                                 \n",a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(60,49);
printf("%c      %c   %c %c   %c  %c     %c                     \n",a,a,a,a,a,a,a);
gotoxy(60,50);
printf("%c      %c   %c %c    %c %c    %c   %c%c  %c%c  %c%c         \n",a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(60,51);
printf("%c%c%c%c%c  %c   %c %c    %c %c%c%c%c%c    %c%c  %c%c  %c%c                         \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    do
    {
    i++;
    gotoxy(100,51);
    flashdrive=fopen(Pathway,"r+");

    }while(flashdrive==NULL&&i<=190000);

    gotoxy(40,55);
    printf("Processing: ");
    gotoxy(53,55);
    for(int i=0;i<50;i++)
    {
        Sleep(50);
        printf("%c",a);
    }
    if(i==190000)
    {
     gotoxy(105,55);
     printf("Error Please Register First or Insert Atm.");
    }
    else
    {
    gotoxy(105,55);
    printf("Completed");
    }
    getch();
    fclose(flashdrive);
    system("cls");
    return (flashdrive==NULL)?1:0;
}
int ChooseProcess()
{
    design();
    design3();
 int pili;
 char a=219;
    gotoxy(35,12);
    printf("   %c%c%c%c%c\n",a,a,a,a,a);
    gotoxy(35,13);
    printf("     %c\n",a);
    gotoxy(35,14);
    printf("1.)  %c RANSACTION\n",a);
    gotoxy(35,15);
    printf("     %c\n",a);
    gotoxy(35,16);
    printf("     %c\n",a);

    gotoxy(35,20);
    printf("   %c%c%c   %c%c%c \n",a,a,a,a,a,a);
    gotoxy(35,21);
    printf("   %c      %c\n",a,a);
    gotoxy(35,22);
    printf("2.)%c%c DIT %c NFO  \n",a,a,a);
    gotoxy(35,23);
    printf("   %c      %c  \n",a,a);
    gotoxy(35,24);
    printf("   %c%c%c   %c%c%c   \n",a,a,a,a,a,a);

    gotoxy(35,27);
    printf("    %c%c%c \n",a,a,a);
    gotoxy(35,28);
    printf("    %c  %c\n",a,a);
    gotoxy(35,29);
    printf("3.) %c  %c ELETE\n",a,a);
    gotoxy(35,30);
    printf("    %c  %c\n",a,a);
    gotoxy(35,31);
    printf("    %c%c%c\n",a,a,a);

    gotoxy(75,12);
    printf("   %c   %c     %c  \n",a,a,a);
    gotoxy(75,13);
    printf("   %c   %c     %c  \n",a,a,a);
    gotoxy(75,14);
    printf("4.)%c   %c IEW %c IST     \n",a,a,a);
    gotoxy(75,15);
    printf("    %c %c      %c    \n",a,a,a);
    gotoxy(75,16);
    printf("     %c       %c%c%c            \n",a,a,a,a);

    gotoxy(75,20);
    printf("   %c%c%c    %c%c%c         \n",a,a,a,a,a,a);
    gotoxy(75,21);
    printf("   %c  %c   %c  %c      \n",a,a,a,a);
    gotoxy(75,22);
    printf("5.)%c%c%c AY %c%c%c ILLS       \n",a,a,a,a,a,a);
    gotoxy(75,23);
    printf("   %c      %c  %c       \n",a,a,a);
    gotoxy(75,24);
    printf("   %c      %c%c%c        \n",a,a,a,a);

    gotoxy(75,27);
    printf("   %c%c%c%c%c\n",a,a,a,a,a);
    gotoxy(75,28);
    printf("     %c\n",a);
    gotoxy(75,29);
    printf("6.)  %c RANSFER\n",a);
    gotoxy(75,30);
    printf("     %c\n",a);
    gotoxy(75,31);
    printf("     %c\n",a);

    gotoxy(90,30);
    printf("Choose your path(1-6):");
    gotoxy(113,30);
    scanf("%d",&pili);
    return pili;
}
void Process()
{   try_again:
    switch(ChooseProcess())
    {
    case 1:
        system("cls");
        AccNoValidation();
        break;
    case 2:
        system("cls");
        EditInfo();
        break;
    case 3:
        system("cls");
        DelATM();
        break;
    case 4:
        system("cls");
        view_user_bank();
        break;
    case 5:
        system("cls");
        paybills();
        break;

    case 6:
        system("cls");
        transfer();
        break;
    default:
        system("cls");
        goto try_again;

    }
}
void transfer()
{
    char pili,a=219;
    int tranferNo,flag;
    double value,reduce;
    FILE *latest,*news;
    type_error:
    flag=0;
    latest=fopen(Pathway,"r");
    news=fopen(NewPathway,"w");
    design();
    logo();
    gotoxy(30,18);
    printf("Enter your account number : ");
    scanf("%d",&accountNo);
    gotoxy(30,20);
    printf("Enter the money you transfer : ");
    scanf("%lf",&value);
    gotoxy(30,22);
    printf("Enter the account number who recieve money : ");
    scanf("%d",&tranferNo);
    system("cls");
    while(fscanf(latest,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
    {
            if(accountNo==luma.acc_no)
            { flag++;
                if(PinValidation())
                {
                reduce=luma.balance-value;
                if(reduce<100)
                {
                    design();
                    logo();
                    gotoxy(30,24);
                    printf("Unavailable transferring money.");
                    getch();
                    system("cls");
                    goto type_error;
                }
                luma.balance=reduce;
                fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
                }
            }
            else if(tranferNo==luma.acc_no)
            {
                flag++;
                luma.balance+=value;
                fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
            }
            else
            {
                fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
            }
    }
    design();
    logo();
    if(flag!=2)/// fixed
        {
        gotoxy(30,22);
        printf("Your Account number is not yet registered.");
        gotoxy(30,23);
        printf("Do you want to try again (Y/N) ? ");
        scanf(" %c",&pili);
        system("cls");
        if(pili=='Y'||pili=='y')
        {
            fclose(latest);
            fclose(news);
            goto type_error;
        }
        else
        {
            fclose(latest);
            fclose(news);
            remove(Pathway);
            rename(NewPathway,Pathway);
            exit(0);
        }
    }
fclose(latest);
fclose(news);
remove(Pathway);
rename(NewPathway,Pathway);
 gotoxy(40,25);
  printf("Thank You and Come Again.\n");
  gotoxy(40,30);
  printf("Processing: ");
  for(int i=0;i<50;i++)
  {
        Sleep(50);
        printf("%c",a);
  }
    gotoxy(40,33);
    printf("Completed the Money is automatically Transfer.");
    getch();
    system("cls");
    Process();
}
void paybills()
{
    char pili,a=219;
    double value,reduce;
    int referens,flag=0;
    FILE *latest,*news;
    type_error:
    latest=fopen(Pathway,"r");
    news=fopen(NewPathway,"w");
    design();
    logo();
    gotoxy(30,20);
    printf("Enter the account number : ");
    scanf("%d",&accountNo);
    system("cls");
   while(fscanf(latest,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
   {
        if(accountNo==luma.acc_no)
        {
            flag++;
          if(PinValidation())
            {
                Try_Again:
                design();
                logo();
        switch(Choosepaybills())
        {
        case 1:
            system("cls");
            design();
            logo();
            gotoxy(35,22);
            printf("Enter the Reference Number : ");
            scanf("%d",&referens);
            gotoxy(35,24);
            printf("Enter the Amount : ");
            scanf("%lf",&value);
            gotoxy(35,26);
            printf("Paid Successfully.");
            reduce=luma.balance-value;
            if(100>reduce)
            {
                gotoxy(35,27);
                printf("Invalid,Please Try Again.");
                getch();
                system("cls");
                goto Try_Again;
            }
            luma.balance=reduce;
            getch();
            system("cls");
            break;
        case 2:
            system("cls");
            design();
            logo();
            gotoxy(35,22);
            printf("Enter the Reference Number : ");
            scanf("%d",&referens);
            gotoxy(35,24);
            printf("Enter the Amount : ");
            scanf("%lf",&value);
            gotoxy(35,26);
            printf("Paid Successfully.");
            reduce=luma.balance-value;
            if(100>reduce)
            {
                gotoxy(35,27);
                printf("Invalid,Please Try Again.");
                getch();
                system("cls");
                goto Try_Again;
            }
            luma.balance=reduce;
            getch();
            system("cls");
            break;
        case 3:
            system("cls");
            design();
            logo();
            gotoxy(35,22);
            printf("Enter the Reference Number : ");
            scanf("%d",&referens);
            gotoxy(35,24);
            printf("Enter the Amount : ");
            scanf("%lf",&value);
            gotoxy(35,26);
            printf("Paid Successfully.");
            reduce=luma.balance-value;
            if(100>reduce)
            {
                gotoxy(35,27);
                printf("Invalid,Please Try Again.");
                getch();
                system("cls");
                goto Try_Again;
            }
            luma.balance=reduce;
            getch();
            system("cls");
            break;
        case 4:
            system("cls");
            design();
            logo();
            gotoxy(35,22);
            printf("Enter the Reference Number : ");
            scanf("%d",&referens);
            gotoxy(35,24);
            printf("Enter the Amount : ");
            scanf("%lf",&value);
            gotoxy(35,26);
            printf("Paid Successfully.");
            reduce=luma.balance-value;
            if(100>reduce)
            {
                gotoxy(35,27);
                printf("Invalid,Please Try Again.");
                getch();
                system("cls");
                goto Try_Again;
            }
            luma.balance=reduce;
            getch();
            system("cls");
            break;
        case 5:
            system("cls");
            design();
            logo();
            gotoxy(35,22);
            printf("Enter the Reference Number : ");
            scanf("%d",&referens);
            gotoxy(35,24);
            printf("Enter the Amount : ");
            scanf("%lf",&value);
            gotoxy(35,26);
            printf("Paid Successfully.");
            reduce=luma.balance-value;
            if(100>reduce)
            {
                gotoxy(35,27);
                printf("Invalid,Please Try Again.");
                getch();
                system("cls");
                goto Try_Again;
            }
            luma.balance=reduce;
            getch();
            system("cls");
            break;
        case 6:
            system("cls");
            design();
            logo();
            gotoxy(35,22);
            printf("Enter the Reference Number : ");
            scanf("%d",&referens);
            gotoxy(35,24);
            printf("Enter the Amount : ");
            scanf("%lf",&value);
            gotoxy(35,26);
            printf("Paid Successfully.");
            reduce=luma.balance-value;
            if(100>reduce)
            {
                gotoxy(35,27);
                getch();
                printf("Invalid,Please Try Again.");
                system("cls");
                goto Try_Again;
            }
            luma.balance=reduce;
            getch();
            system("cls");
            break;
        case 7:
            system("cls");
            break;
        default:
            system("cls");
            goto Try_Again;
        }
            }
        fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
        }
    else
    {
        fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
    }
   }
   design();
    logo();
    if(flag==0)/// fixed
        {
        gotoxy(30,22);
        printf("Your Account number is not yet registered.");
        gotoxy(30,23);
        printf("Do you want to try again (Y/N) ? ");
        scanf(" %c",&pili);
        system("cls");
        if(pili=='Y'||pili=='y')
        {
            fclose(latest);
            fclose(news);
            goto type_error;
        }
        else
        {
            fclose(latest);
            fclose(news);
            remove(Pathway);
            rename(NewPathway,Pathway);
            exit(0);
        }
    }
fclose(latest);
fclose(news);

        remove(Pathway);
        rename(NewPathway,Pathway);
  gotoxy(40,25);
  printf("Thank You and Come Again.\n");
  gotoxy(40,30);
  printf("Processing: ");
  for(int i=0;i<50;i++)
  {
        Sleep(50);
        printf("%c",a);
  }
    gotoxy(40,33);
    printf("Completed the Money is automatically Transfer.");
    getch();
    system("cls");
    Process();
}
int Choosepaybills()
{
    int pili;
 gotoxy(30,20);
 printf("Please Choose in 1-7 only.");
 gotoxy(35,24);
 printf("1.Meralco\n");
 gotoxy(35,25);
 printf("2.Converge Internet Provider\n");
 gotoxy(35,26);
 printf("3.PLDT Internet Provider\n");
 gotoxy(35,27);
 printf("4.Smart Internet Provider\n");
 gotoxy(35,28);
 printf("5.Globe Internet Provider\n");
 gotoxy(35,29);
 printf("6.Maynilad\n");
 gotoxy(35,30);
 printf("7.Exit\n");
 gotoxy(65,29);
 printf("Enter the the number you want to edit : ");
 scanf("%d",&pili);
 return pili;
}
void view_user_bank()
{
    int k=0;
    char a=219;
    FILE *latest;
    latest=fopen(Pathway,"r");
    gotoxy(0,0);
    printf("Account Number");

    gotoxy(40,0);
    printf("Name");

    gotoxy(80,0);
    printf("Pincode");

    while(fscanf(latest,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
    {
        gotoxy(0,2+k);
        printf("%d",luma.acc_no);
        gotoxy(40,2+k);
        printf("%s",luma.name);
        gotoxy(80,2+k);
        printf("XXXXXX");
        gotoxy(37,0);
        printf("%c",a);
        gotoxy(77,0);
        printf("%c",a);
        gotoxy(37,1);
        printf("%c",a);
        gotoxy(77,1);
        printf("%c",a);
        gotoxy(37,2+k);
        printf("%c",a);
        gotoxy(77,2+k);
        printf("%c",a);
        k++;
    }
    fclose(latest);
    getch();
    system("cls");
    Process();
}
void DelATM()/// may bug
{
    int flag=0;
    char pili,a=219;;
    FILE *latest,*news;
    type_error:
    latest=fopen(Pathway,"r");
    news=fopen(NewPathway,"w");
    design();
    logo();
    gotoxy(30,20);
    printf("Enter the account number you want to Delete : ");
    scanf("%d",&accountNo);
    system("cls");
   while(fscanf(latest,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
   {
        if(accountNo==luma.acc_no)
        {
            if(PinValidation())
            {
            flag++;
            }
            else
            {
                fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
            }
        }
        else
        {
            fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
        }
   }
   design();
   logo();
   if(flag==0)/// fixed
        {
        gotoxy(30,22);
        printf("Your Account number is not yet registered.");
        gotoxy(30,23);
        printf("Do you want to try again (Y/N) ? ");
        scanf(" %c",&pili);
        system("cls");
        if(pili=='Y'||pili=='y')
        {
            fclose(latest);
            fclose(news);
            goto type_error;
        }
        else
        {
            fclose(latest);
            fclose(news);
            remove(Pathway);
            rename(NewPathway,Pathway);
            exit(0);
        }
    }
fclose(latest);
fclose(news);

        remove(Pathway);
        rename(NewPathway,Pathway);

  gotoxy(40,25);
  printf("Thank You and Come Again.\n");
  gotoxy(40,30);
  printf("Processing: ");
  for(int i=0;i<50;i++)
  {
        Sleep(50);
        printf("%c",a);
  }
    gotoxy(40,33);
    printf("Completed the card is automatically deleted.");
    getch();
    system("cls");
    Process();
}

void EditInfo()
{
    char a=219;
    int flag=0;
    FILE *latest,*news;
    char nam[100],mother[100],father[100],Adress[100],Citi[100],Email[100],Relygion[100],EducaAttain[100],Occu[100],pili;
    type_error:
    latest=fopen(Pathway,"r");
    news=fopen(NewPathway,"w");
    design();
    logo();
    gotoxy(30,20);
    printf("Enter the account number : ");
    scanf("%d",&accountNo);
    system("cls");
  while(fscanf(latest,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
   {
        if(accountNo==luma.acc_no)
        {flag=1;
            if(PinValidation())
            {
            More:
            design();
            logo();
            switch(ChooseEditInfo())
            {
            case 1:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Name : ");
                scanf(" %[^\n]",nam);
                strcpy(luma.name,nam);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
            case 2:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Mother's Name : ");
                scanf(" %[^\n]",mother);
                strcpy(luma.mom,mother);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
            case 3:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Father's Name : ");
                scanf(" %[^\n]",father);
                strcpy(luma.dad,father);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
            case 4:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Address : ");
                scanf(" %[^\n]",Adress);
                strcpy(luma.Address,Adress);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
            case 5:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your City : ");
                scanf(" %[^\n]",Citi);
                strcpy(luma.City,Citi);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
               printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
             case 6:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Email : ");
                scanf("%s",Email);
                strcpy(luma.EmailAdd,Email);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
             case 7:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Religion : ");
                scanf(" %[^\n]",Relygion);
                strcpy(luma.Religion,Relygion);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
             case 8:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Educational Attainment : ");
                scanf(" %[^\n]",EducaAttain);
                strcpy(luma.EducAttain,EducaAttain);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
             case 9:
                system("cls");
                design();
                logo();
                gotoxy(35,20);
                printf("Enter your Occupation : ");
                scanf(" %[^\n]",Occu);
                strcpy(luma.Occupation,Occu);
                gotoxy(35,22);
                printf("Edit Successfully.");
                gotoxy(35,24);
                printf("Do you want to change other information(Y/N):");
                scanf(" %c",&pili);
                system("cls");
                if(pili=='Y'||pili=='y')
                    goto More;
                break;
             case 10:
                system("cls");
                break;
             default:
                system("cls");
                goto More;
            }
            }
            fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
        }
        else
        {
          fprintf(news,"\n%d\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %f\n",luma.acc_no,luma.name,luma.dad,luma.mom,luma.days,luma.months,luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,luma.balance);
        }
    }
    design();
    logo();
    if(flag==0)/// fixed
        {
        gotoxy(30,22);
        printf("Your Account number is not yet registered.");
        gotoxy(30,23);
        printf("Do you want to try again (Y/N) ? ");
        scanf(" %c",&pili);
        system("cls");
        if(pili=='Y'||pili=='y')
        {
            fclose(latest);
            fclose(news);
            goto type_error;
        }
        else
        {
            fclose(latest);
            fclose(news);
            remove(Pathway);
            rename(NewPathway,Pathway);
            exit(0);
        }
    }
fclose(latest);
fclose(news);

        remove(Pathway);
        rename(NewPathway,Pathway);
  gotoxy(40,25);
  printf("Thank You and Come Again.\n");
  gotoxy(40,30);
  printf("Processing: ");
  for(int i=0;i<50;i++)
  {
        Sleep(50);
        printf("%c",a);
  }
    gotoxy(40,33);
    printf("Completed the card is automatically Edit.");
    getch();
    system("cls");
    Process();
}
int ChooseEditInfo()
{
 int pili;
 gotoxy(30,20);
 printf("Please Choose in 1-10 only.");
 gotoxy(35,24);
 printf("1.Name\n");
 gotoxy(35,25);
 printf("2.Mother's Name\n");
 gotoxy(35,26);
 printf("3.Father's Name\n");
 gotoxy(35,27);
 printf("4.Address\n");
 gotoxy(35,28);
 printf("5.City\n");
 gotoxy(35,29);
 printf("6.Email\n");
 gotoxy(35,30);
 printf("7.Religion\n");
 gotoxy(35,31);
 printf("8.Educational Attainment\n");
 gotoxy(35,32);
 printf("9.Occupation\n");
 gotoxy(35,33);
 printf("10.Exit\n");
 gotoxy(65,29);
 printf("Enter the the number you want to edit : ");
 scanf("%d",&pili);
 return pili;
}
void AccNoValidation()
{
    char pili;
    int flag=0;

    FILE *latest,*news;
    type_error:

    latest=fopen(Pathway,"r");
    news=fopen(NewPathway,"w");
    design();
    logo();
    gotoxy(30,20);
    printf("Enter the account number : ");
    scanf("%d",&accountNo);

    while(fscanf(latest,"%d  %[^\n]  %[^\n]  %[^\n] %d %d %d  %[^\n]  %[^\n] %s %s %s  %[^\n] %d  %[^\n]  %[^\n] %s %lf",&luma.acc_no,luma.name,luma.dad,luma.mom,&luma.days,&luma.months,&luma.year,luma.Address,luma.City,luma.Gender,luma.EmailAdd,luma.pincode,luma.Religion,&luma.Category,luma.EducAttain,luma.Occupation,luma.Senior,&luma.balance)!=EOF)
   {
        if(accountNo==luma.acc_no)
        {
            if(PinValidation())
            Trans();
            flag++;
          fprintf(news,"\n%d\n",luma.acc_no);
          fprintf(news,"%s\n",luma.name);
          fprintf(news,"%s\n",luma.dad);
          fprintf(news,"%s\n",luma.mom);
          fprintf(news,"%d\n",luma.days);
          fprintf(news,"%d\n",luma.months);
          fprintf(news,"%d\n",luma.year);
          fprintf(news,"%s\n",luma.Address);
          fprintf(news,"%s\n",luma.City);
          fprintf(news,"%s\n",luma.Gender);
          fprintf(news,"%s\n",luma.EmailAdd);
          fprintf(news,"%s\n",luma.pincode);
          fprintf(news,"%s\n",luma.Religion);
          fprintf(news,"%d\n",luma.Category);
          fprintf(news,"%s\n",luma.EducAttain);
          fprintf(news,"%s\n",luma.Occupation);
          fprintf(news,"%s\n",luma.Senior);
          fprintf(news,"%f\n",luma.balance);
        }
        else
        {
          fprintf(news,"\n%d\n",luma.acc_no);
          fprintf(news,"%s\n",luma.name);
          fprintf(news,"%s\n",luma.dad);
          fprintf(news,"%s\n",luma.mom);
          fprintf(news,"%d\n",luma.days);
          fprintf(news,"%d\n",luma.months);
          fprintf(news,"%d\n",luma.year);
          fprintf(news,"%s\n",luma.Address);
          fprintf(news,"%s\n",luma.City);
          fprintf(news,"%s\n",luma.Gender);
          fprintf(news,"%s\n",luma.EmailAdd);
          fprintf(news,"%s\n",luma.pincode);
          fprintf(news,"%s\n",luma.Religion);
          fprintf(news,"%d\n",luma.Category);
          fprintf(news,"%s\n",luma.EducAttain);
          fprintf(news,"%s\n",luma.Occupation);
          fprintf(news,"%s\n",luma.Senior);
          fprintf(news,"%f\n",luma.balance);
        }
    }
    if(flag==0)/// fixed
        {
        gotoxy(30,22);
        printf("Your Account number is not yet registered.");
        gotoxy(30,23);
        printf("Do you want to try again (Y/N) ? ");
        scanf(" %c",&pili);
        system("cls");
        if(pili=='Y'||pili=='y')
        {
            fclose(latest);
            fclose(news);
            remove(Pathway);
            rename(NewPathway,Pathway);
            goto type_error;
        }
        else
        {
            fclose(latest);
            fclose(news);
            remove(Pathway);
            rename(NewPathway,Pathway);
            exit(0);
        }
    }
fclose(latest);
fclose(news);
remove(Pathway);
rename(NewPathway,Pathway);
removecard();
}

int PinValidation()
{
char pass[100],a=219;
int tries=3;
system("cls");
design();
while(tries!=0)
 {
 logo();
 gotoxy(30,22);
 printf("Input Pincode: ");
 i=0;
 do{
    if(i==6)
        {
        break;
        }
    else
        {
        pass[i]=getch();

        if(pass[i]=='\b')
        {
                if (i<=0)
                    i++;
                else
                {
                    printf("\b \b");
                    i--;
                }
        }
        else if(pass[i]!='\r'){
                printf("*");
                i++;
        }
    }
}while(pass[i]!='\r');
pass[i]='\0';
if(i!=6)
{
    gotoxy(30,24);
    printf("Please Try Again input 6 numbers.");
    getch();
    system("cls");
    tries--;
}
else if (strcmp(luma.pincode,pass)==0)
{   gotoxy(30,26);
    printf("Processing: ");
    for(i=0;i<50;i++)
    {
        Sleep(50);
        printf("%c",a);
    }
    gotoxy(60,29);
    printf("Login Successfully.");
    getch();
    system("cls");
    break;
}
else
{
    gotoxy(30,24);
    printf("Incorrect pin code.");
    getch();
    tries--;
    system("cls");
    if(tries==0)
    {
        design();
        break;
    }
}
design();
 }
 if(tries==0)
 {
    logo();
    gotoxy(40,22);
    printf("The Card is unavailable right now please try again later.");
    return 0;
 }
 return 1;
}
void Trans()//improve this
{  Again:
    switch(TransPili())
    {
    case 1:
        system("cls");
        design();
        logo();
        Dep();
        break;
    case 2:
        system("cls");
        design();
        logo();
        Withdraw();
        break;
    case 3:
        system("cls");
        design();
        logo();
        CheckBal();
        break;
    case 4:
        system("cls");
        design();
        logo();
        ChangePin();
        break;
    case 5:
        system("cls");
        design();
        logo();
        view_list();
        break;
    case 6:
        system("cls");
        design();
        logo();
        break;
    default:
        system("cls");
        design();
        logo();
        gotoxy(30,20);
        printf("Try Again\n");
        gotoxy(30,21);
        printf("Please pick from 1-6 only.\n");
        gotoxy(57,21);
        getch();
        system("cls");
        goto Again;
    }
}
int TransPili()//improve this
{
    design();
    design2();
    int pili;
    char a=219;
    gotoxy(35,12);
    printf("    %c%c%c \n",a,a,a);
    gotoxy(35,13);
    printf("    %c  %c\n",a,a);
    gotoxy(35,14);
    printf("1.) %c  %c EPOSIT\n",a,a);
    gotoxy(35,15);
    printf("    %c  %c\n",a,a);
    gotoxy(35,16);
    printf("    %c%c%c\n",a,a,a);

    gotoxy(35,20);
    printf("    %c   %c\n",a,a);
    gotoxy(35,21);
    printf("    %c   %c\n",a,a);
    gotoxy(35,22);
    printf("2.) %c %c %c ITHDRAWAL\n",a,a,a);
    gotoxy(35,23);
    printf("    %c%c %c%c\n",a,a,a,a);
    gotoxy(35,24);
    printf("    %c   %c\n",a,a);

    gotoxy(35,27);
    printf("    %c%c%c\n",a,a,a);
    gotoxy(35,28);
    printf("    %c  %c\n",a,a);
    gotoxy(35,29);
    printf("3.) %c%c%c  ALANCE\n",a,a,a);
    gotoxy(35,30);
    printf("    %c  %c\n",a,a);
    gotoxy(35,31);
    printf("    %c%c%c\n",a,a,a);

    gotoxy(75,12);
    printf("    %c%c%c       %c%c%c\n",a,a,a,a,a,a);
    gotoxy(75,13);
    printf("    %c         %c  %c\n",a,a,a);
    gotoxy(75,14);
    printf("4.) %c   HANGE %c%c%c IN\n",a,a,a,a);
    gotoxy(75,15);
    printf("    %c         %c\n",a,a);
    gotoxy(75,16);
    printf("    %c%c%c       %c\n",a,a,a,a);

    gotoxy(75,20);
    printf("    %c%c%c\n",a,a,a);
    gotoxy(75,21);
    printf("     %c\n",a);
    gotoxy(75,22);
    printf("5.)  %c NFO\n",a);
    gotoxy(75,23);
    printf("     %c\n",a);
    gotoxy(75,24);
    printf("    %c%c%c\n",a,a,a);

    gotoxy(75,27);
    printf("    %c%c%c\n",a,a,a);
    gotoxy(75,28);
    printf("    %c\n",a);
    gotoxy(75,29);
    printf("6.) %c%c XIT\n",a,a);
    gotoxy(75,30);
    printf("    %c\n",a);
    gotoxy(75,31);
    printf("    %c%c%c\n",a,a,a);

    gotoxy(90,30);
    printf("Choose your path(1-6):");
    gotoxy(113,30);
    scanf("%d",&pili);
    return pili;
}
void Dep()
{
 double in;
 while(1)
 {
 gotoxy(40,20);
 printf("Enter the value you want to deposit: ");
 gotoxy(79,20);
 scanf("%lf",&in);
 if(in<=0)
 {
    gotoxy(40,21);
     printf("Please Try Again");
     getch();
     system("cls");
     design();
     logo();
 }
 else
 {
     break;
 }
 }
 luma.balance+=in;
 system("cls");
 Trans();
}
void Withdraw()
{
    double out,reduce;
    stupidity:
    gotoxy(40,20);
    printf("Enter the value you want to withdraw: ");
    gotoxy(79,20);
    scanf("%lf",&out);
    if(out<=0)
    {
    gotoxy(40,21);
     printf("Please Try again.");
     getch();
     system("cls");
     design();
     logo();
     goto stupidity;
     }
    reduce=luma.balance-out;
    if(reduce>=100)
    {
        luma.balance=reduce;
    }
    else
    {
     gotoxy(40,21);
     printf("Your current balance is %.2f\n",luma.balance);
     gotoxy(40,22);
     printf("Please Try Again The maintaining balance is P100.00\n");
     getch();
     system("cls");
     design();
     logo();
    }
    system("cls");
   Trans();
}
void CheckBal()
{
    gotoxy(40,20);
    printf("Your current balance is %.2f.",luma.balance);
    getch();
    system("cls");
    Trans();
}
void ChangePin()
{
    char pin[100],newpin[100],a=219;
 int d,c,flag,len;
 stupidity:
 while(1)
 {
    c=0;
    gotoxy(40,20);
    printf("Input the old pincode: ");
    do{
    if(c==6)
        {
        break;
        }
    else
        {
        pin[c]=getch();

        if(pin[c]=='\b')
        {
                if (c<=0)
                    c++;
                else
                {
                    printf("\b \b");
                    c--;
                }
        }
        else if(pin[c]!='\r'){
                printf("*");
                c++;
        }
    }

}while(pin[c]!='\r');
pin[c]='\0';
if(c!=6)
{
    gotoxy(40,21);
    printf("Incorrect,please try again");
    getch();
    system("cls");
    design();
    logo();
}
else if(strcmp(luma.pincode,pin)==0)
{
    break;
}
else
{
    gotoxy(40,21);
    printf("Incorrect,please try again");
    getch();
    system("cls");
    design();
    logo();
}
}
printf("\n");
while(1)
{
d=0;
gotoxy(40,25);
printf("Input the new pincode: ");
  do{
    if(d==6)
        {
        break;
        }
    else
        {
        newpin[d]=getch();

        if(newpin[d]=='\b')
        {
                if (d<=0)
                    d++;
                else
                {
                    printf("\b \b");
                    d--;
                }
        }
        else if(newpin[d]!='\r'){
                printf("*");
                d++;
        }
    }

}while(newpin[d]!='\r');
newpin[d]='\0';
d=0;
flag=0;
len=strlen(newpin);
while(d<len)
{
    if(isdigit(newpin[d])==0)
    {
        flag++;
    }
d++;
}
if(flag!=0)
{
    gotoxy(40,29);
    printf("Please try again and the pincode must be a digit.");
    getch();
    system("cls");
    design();
    logo();
    goto stupidity;
}
if(d!=6)
{

    gotoxy(40,29);
    printf("Incorrect,please try again");
    getch();
    system("cls");
    design();
    logo();
    goto stupidity;
}
else if(strcmp(luma.pincode,newpin)==0)
{
    gotoxy(40,29);
    printf("Your old pin and new pin is same.");
    gotoxy(40,31);
    printf("Please Try again.");
    getch();
    system("cls");
    design();
    logo();
    goto stupidity;
}
else
{

    gotoxy(40,29);
    printf("Processing: ");
    for(i=0;i<50;i++)
    {
        Sleep(50);
        printf("%c",a);
    }
    gotoxy(40,31);
    printf("Change pincode successfully.");
    getch();
strcpy(luma.pincode,newpin);
break;
}
}
system("cls");
Trans();
}
void view_list()
{
    gotoxy(30,20);
    printf("Name:");
    gotoxy(40,20);
    printf("%s",luma.name);
    gotoxy(30,21);
    printf("Parents:");
    gotoxy(40,21);
    printf("%s",luma.dad);
    gotoxy(40,22);
    printf("%s",luma.mom);
    gotoxy(30,23);
    printf("Birthday:");
    gotoxy(40,23);
    printf("%d/%d/%d",luma.months,luma.days,luma.year);
    gotoxy(30,26);
    printf("Address:");
    gotoxy(40,26);
    printf("%s",luma.Address);
    gotoxy(30,27);
    printf("City:");
    gotoxy(40,27);
    printf("%s",luma.City);
    gotoxy(30,28);
    printf("Gender:");
    gotoxy(40,28);
    printf("%s",luma.Gender);
    gotoxy(30,29);
    printf("Email:");
    gotoxy(40,29);
    printf("%s",luma.EmailAdd);
    gotoxy(30,30);
    printf("Category:");
    if(luma.Category==1)
    {
        gotoxy(40,30);
        printf("Saving Acc.");
    }
    else if(luma.Category==2)
    {
        gotoxy(40,30);
        printf("Money Market Acc.");
    }
    else if(luma.Category==3)
    {
        gotoxy(40,30);
        printf("Certificate of Deposit");
    }
    else if(luma.Category==4)
    {
        gotoxy(40,30);
        printf("Retirement Acc.");
    }
    gotoxy(73,20);
    printf("Pincode:");
    gotoxy(85,20);
    printf("%s",luma.pincode);
    gotoxy(73,21);
    printf("Religion:");
    gotoxy(85,21);
    printf("%s",luma.Religion);
    gotoxy(73,22);
    printf("Educ. Attain:");
    gotoxy(86,22);
    printf("%s",luma.EducAttain);
    gotoxy(73,23);
    printf("Occupation:");
    gotoxy(85,23);
    printf("%s",luma.Occupation);
    gotoxy(73,24);
    printf("Senior:");
    gotoxy(85,24);
    printf("%s",luma.Senior);
    gotoxy(73,25);
    printf("Balance:");
    gotoxy(85,25);
    printf("%.2f",luma.balance);


    getch();
    system("cls");
    Trans();

}
void removecard()
{
  char a=219;
  gotoxy(40,25);
  printf("Thank You and Come Again.\n");
  gotoxy(40,30);
  printf("Processing: ");
  for(int i=0;i<50;i++)
  {
        Sleep(50);
        printf("%c",a);
  }
    gotoxy(40,33);
    printf("Completed the card is automatically removed.");
    getch();
    system("cls");
    exit(0);
}
COORD co={0,0};
void gotoxy(int x,int y)
{
co.X=x;
co.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);

}
void reg()
{
    printf("Registration Form:\n");
    printf(" ____________________________________________________________________________________________________________________________\n");
    printf("||MukBank.com|( FACEBOOK.com )(+)      | 0 Menu       | Suggested Site:                                                      |\n");
    printf("||           |_________________________| 0 Tools      | (F)-|Facebook.com| (T)- |Twitter.com| (Y) - |Youtube.com|            |\n");
    printf("||___________|_________________________|_0_History____|______________________________________________________________________|\n");
    printf("|____________________________________________________________________________________________________________________________|\n");
    printf("| Mukbank.com/Registration-Form                                                                                              |\n");
    printf("|____________________________________________________________________________________________________________________________|\n");
    printf("|                                |   ____|  /   \\    |       | |  \\   /  |                                                 | |\n");
    printf("|            ___________         |  |__    |     |   |  0 ___| |   |_|   |                                                 | |\n");
    printf("|  Acct. No:|           |        |   __|   |  0  |   |   _ \\   | |\\   /| |                                                 | |\n");
    printf("|           |___________|        |  |      |     |   |  | \\ \\  | | \\_/ | |                                                 | |\n");
    printf("|                                |__|       \\___/    |__|  \\_\\ |_|     |_|                                                 | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|       Format: Surname ,  First Name   MI.                           Format: Surname ,  First Name   MI.                  | |\n");
    printf("|       ______________________________________                       ___________________________________                   |_|\n");
    printf("| Name:|                                      |       Father`s Name:|                                   |                  | |\n");
    printf("|      |______________________________________|                     |___________________________________|                  | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                  Format: Surname ,  First Name   MI.                        (1-31)            (1-12)                     | |\n");
    printf("|                ______________________________________                        _____          ___________         ______   |_|\n");
    printf("| Mother`s Name:|                                      |  Date of Birth: Days:|     | Month :|           | Year: |      |  | |\n");
    printf("|               |______________________________________|                      |_____|        |___________|       |______|  | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|         Format:Unit/Floor/House/BuildingName/Street Number/Street Name Barangay/District                                 | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|           ___________________________________________________________________________             ______________         | |\n");
    printf("| Address: |                                                                           |     City: |              |        | |\n");
    printf("|          |___________________________________________________________________________|           |______________|        | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|         _________                   ______________________________                   ______________                      | |\n");
    printf("| Gender:|         |  Email Address: |                              |     Pincode(6): |              |                     | |\n");
    printf("|        |_________|                 |______________________________|                 |______________|                     | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                                    Pick A Number:                                                                        | |\n");
    printf("|           ___________              ___________________________   _____________________________                           | |\n");
    printf("| Religion:|           |  Category: |1.)Savings Acc.            | |                             |                          | |\n");
    printf("|          |___________|            |2.)Money market Acc.       | |_____________________________|                          | |\n");
    printf("|                                   |3.)Certificates of Deposit |                                                          | |\n");
    printf("|                                   |4.)Retirement accounts     |                                                          | |\n");
    printf("|                                   |___________________________|                                                          | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                         ___________________                 _____________________________                                | |\n");
    printf("| Educational Attainment:|                   |  Occupation:  |                             |                               | |\n");
    printf("|                        |___________________|               |_____________________________|                               | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                 Yes / No                                                                                                 | |\n");
    printf("|                 _________                        ______________                                                          | |\n");
    printf("| Senior Citizen:|         |       First Deposit: |              |                                                         | |\n");
    printf("|                |_________|                      |______________|                                                         | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|                                                                                                                          | |\n");
    printf("|__________________________________________________________________________________________________________________________| |\n");
    printf("|----------------------------------------------------------------------------------------------------------------------------|\n");
}
void design()
{
char a=219,b=176;
    int i,j;
    for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
    printf("\n");
    for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
    printf("\n");
    for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
    printf("\n");
    for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
    printf("\n");
    for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
    printf("\n");
    for(j=0;j<30;j++)
    {
    for(i=0;i<140;i++)
    {
        if(i<=20)
        printf("%c",b);
        else if(i>=119)
            printf("%c",b);
        else
        {
            printf("%c",32);
        }
    }
    printf("\n");
    }
     for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
    printf("\n");
     for(i=0;i<140;i++)
    {
        printf("%c",b);

    }
    printf("\n");
    for(j=0;j<30;j++)
    {

    for(i=0;i<140;i++)
    {
        if((j==15&&(i>=89&&i<=115))||(j==26&&(i>=89&&i<=115)))
            printf("%c",b);
        else if(j==12&&i>=86)
            printf("%c",b);
        else if(i==55||i>=119)
        {
            printf("%c",b);
        }
        else if(i<=20)
        printf("%c",b);
        else if(i==85)
            printf("%c",b);
        else
        {
            printf("%c",32);
        }


    }
    printf("\n");
    }
for(i=0;i<140;i++)
    {
        printf("%c",b);
    }
gotoxy(26,41);printf("           /\\ \n");
gotoxy(26,42);printf("          /  \\  \n");
gotoxy(26,43);printf("         /    \\  \n");
gotoxy(26,44);printf("        /      \\  \n");
gotoxy(26,45);printf("       /        \\  \n");
gotoxy(26,46);printf("      /          \\  \n");
gotoxy(26,47);printf("     /            \\  \n");
gotoxy(26,48);printf("    /              \\ \n");
gotoxy(26,49);printf("   /                \\ \n");
gotoxy(26,50);printf("  /                  \\ \n");
gotoxy(26,51);printf(" /                    \\ \n");
gotoxy(26,52);printf("|___                ___| \n");
gotoxy(26,53);printf("     |            |  \n");
gotoxy(26,54);printf("     |            |  \n");
gotoxy(26,55);printf("     |            |  \n");
gotoxy(26,56);printf("     |            |  \n");
gotoxy(26,57);printf("     |            |  \n");
gotoxy(26,58);printf("     |            |  \n");
gotoxy(26,59);printf("     |            |  \n");
gotoxy(26,60);printf("     |            |  \n");
gotoxy(26,61);printf("     |____________|  \n");
gotoxy(58,41);printf(" _____    _____    _____ \n");
gotoxy(58,42);printf("|     |  |     |  |     |\n");
gotoxy(58,43);printf("|  1  |  |  2  |  |  3  |\n");
gotoxy(58,44);printf("|_____|  |_____|  |_____|\n");
gotoxy(58,47);printf(" _____    _____    _____ \n");
gotoxy(58,48);printf("|     |  |     |  |     |\n");
gotoxy(58,49);printf("|  4  |  |  5  |  |  6  |\n");
gotoxy(58,50);printf("|_____|  |_____|  |_____|\n");
gotoxy(58,53);printf(" _____    _____    _____ \n");
gotoxy(58,54);printf("|     |  |     |  |     |\n");
gotoxy(58,55);printf("|  7  |  |  8  |  |  9  |\n");
gotoxy(58,56);printf("|_____|  |_____|  |_____|\n");
gotoxy(58,59);printf(" _____    _____    _____ \n");
gotoxy(58,60);printf("|     |  |     |  |     |\n");
gotoxy(58,61);printf("|Enter|  |  0  |  |Clear|\n");
gotoxy(58,62);printf("|_____|  |_____|  |_____|\n");
gotoxy(95,41);printf("%c%c%c  %c  %c%c%c %c  %c\n",a,a,a,a,a,a,a,a,a);
gotoxy(95,42);printf("%c   %c %c %c   %c  %c   \n",a,a,a,a,a,a);
gotoxy(95,43);printf("%c   %c%c%c %c%c%c %c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a);
gotoxy(95,44);printf("%c   %c %c   %c %c  %c     \n",a,a,a,a,a,a);
gotoxy(95,45);printf("%c%c%c %c %c %c%c%c %c  %c \n",a,a,a,a,a,a,a,a,a,a);
gotoxy(98,55);printf("  %c%c%c%c               \n",a,a,a,a);
gotoxy(98,56);printf(" =%c===%c=          \n",a,a);
gotoxy(98,57);printf(" =%c===%c=           \n",a,a);
gotoxy(98,58);printf("  %c%c%c%c               \n",a,a,a,a);
gotoxy(98,59);printf("  %c               \n",a);
gotoxy(98,60);printf("  %c               \n",a);
}
void design2()
{
char a=219;
gotoxy(60,6);
printf("%c%c%c%c%c",a,a,a,a,a);
gotoxy(60,7);
printf("  %c",a);
gotoxy(60,8);
printf("  %c",a);
gotoxy(60,9);
printf("  %c",a);
gotoxy(60,10);
printf("  %c RANSACTION",a);
}
void design3()
{
   char a=219;
    gotoxy(60,6);
    printf("%c%c%c \n",a,a,a);
    gotoxy(60,7);
    printf("%c  %c \n",a,a);
    gotoxy(60,8);
    printf("%c%c%c \n",a,a,a);
    gotoxy(60,9);
    printf("%c     \n",a);
    gotoxy(60,10);
    printf("%c ROCESS \n",a);
}
void logo()
{
char a=219;
    gotoxy(43,6);
    printf("     %c%c%c%c%c%c \n",a,a,a,a,a,a);
    gotoxy(43,7);
    printf("   %c%c      %c%c  \n",a,a,a,a);
    gotoxy(43,8);
    printf("  %c          %c \n",a,a);
    gotoxy(43,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(43,11);
    printf("  %c          %c \n",a,a);
    gotoxy(43,11);
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c \n",a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(43,12);
    printf("  %c %c %c  %c %c %c\n",a,a,a,a,a,a);
    gotoxy(43,13);
    printf("  %c %c %c  %c %c %c\n",a,a,a,a,a,a);
    gotoxy(43,14);
    printf("  %c %c %c  %c %c %c\n",a,a,a,a,a,a);
    gotoxy(43,15);
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a);

    gotoxy(60,9);
    printf("%c   %c %c  %c %c  %c %c%c%c  %c%c%c %c  %c %c  %c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(60,10);
    printf("%c%c %c%c %c  %c %c %c  %c  %c %c %c %c%c %c %c %c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(60,11);
    printf("%c %c %c %c  %c %c%c   %c%c%c  %c%c%c %c %c%c %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(60,12);
    printf("%c   %c %c  %c %c %c  %c  %c %c %c %c  %c %c %c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(60,13);
    printf("%c   %c %c%c%c%c %c  %c %c%c%c  %c %c %c  %c %c  %c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

}






