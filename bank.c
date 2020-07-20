#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int main_exit;
void menu();

void new_account();
void view_list();
void edit(void);
void transact(void);
void delete_acc(void);
void see(void);

struct date                                   //STRUCTURE FORMAT FOR DATE
{
    int month,day,year;
};

struct                                       //STRUCTURE FORMAT FOR STORING INFORMATION IN EVERY TASK.
{
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)     //FUNCTION FOR CALCULATING INTEREST.
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}

void fordelay(int j)                              //FUNCTION FOR PERFORMING NEXT TASK AFTER THE NUMBER OF MILI SECONDS PASSED AS AN ARGUMENT.
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_account()                                //FUNCTION FOR CREATING NEW ACCOUNT
{
    int choice;
    FILE *ptr;

    ptr=fopen("bankacc.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t ADD RECORD!!");
    printf("\n\n\nEnter today's date(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number: ");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,&add.name,&add.age,&add.dob.month,&add.dob.day,&add.dob.year,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
                printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }

    add.acc_no=check.acc_no;
    printf("\nEnter the name: ");
    scanf("%s",&add.name);
    printf("\nEnter the age: ");
    scanf("%d",&add.age);
    printf("\nEnter the date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the address: ");
    scanf("%s",&add.address);
    printf("\nEnter the citizenship: ");
    scanf("%s",&add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit: $");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice: ");
    scanf("%s",&add.acc_type);
        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nACCOUNT ADDED SUCCESSFULLY.");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");

    if (main_exit==1)
        menu();
    else if(main_exit==0)
            ty();
    else
        {
            printf("\nINVALID!\a");
            goto add_invalid;
        }
}

void view_list()      //FUNCTION FOR DISPLAYING THE LIST OF CUSTOMERS.
{
    FILE *view;
    view=fopen("bankacc.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\t\t\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t\t %20s\t\t\t%20s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            ty();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void edit(void)                    //FUNCTION FOR MODIFYING THE DETAILS OF THE CURRENT EXISTING ACCOUNT
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("bankacc.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nENTER THE ACCOUNT NUMBER WHO'S INFORMATION YOU'VE TO CHANGE: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {
            test=1;
            printf("\nWHICH PARAMETER YOU WANT TO CHANGE?\n1.ADDRESS\n2.PHONE NO\n\nENTER THE CHOICE:(1 for address and 2 for phone): ");
            scanf("%d",&choice);
            system("cls");

            if(choice==1)
            {
                printf("ENTER THE NEW ADDRESS: ");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("CHANGES SAVED!!");
            }
            else if(choice==2)
            {
                printf("ENTER THE NEW PHONE NUMBER: ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("CHANGES SAVED");
            }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }

    fclose(old);
    fclose(newrec);
    remove("bankacc.dat");
    rename("new.dat","bankacc.dat");

if(test!=1)
        {
            system("cls");
            printf("\n\n\t\t\tRECORD NOT FOUND!!");
            edit_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    ty();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }

    else
        {
            printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");

            if (main_exit==1)
            menu();

            else
            ty();
        }
}

void transact(void)         //FUNCTION FOR KEEPING A TRACK ON TRANSACTIONS.(DEPOSIT AND WITHDRAW)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("bankacc.dat","r");
    newrec=fopen("new.dat","w");

        printf("ENTER THE ACCOUNT NUMBER OF CUSTOMER: ");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\t\t\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }

                printf("\n\nDO YOU WANT TO: ");
                printf("\n1.DEPOSIT");
                printf("\n2.WITHDRAW");
                printf("\n\nENTER YOUR CHOICE(1 for deposit and 2 for withdraw): ");
                scanf("%d",&choice);

                if (choice==1)
                {
                    printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT: $");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDEPOSITED SUCCESSFULLY!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWITHDRAWN SUCCESSFULLY!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }

   fclose(old);
   fclose(newrec);
   remove("bankacc.dat");
   rename("new.dat","bankacc.dat");

   if(test!=1)
   {
       printf("\n\nRECORD NOT FOUND!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");

      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        ty();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            ty();
   }

}

void delete_acc(void)       //TO REMOVE THE ACCOUNT BY ENTERING THE ACCOUNT NUMBER.
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("bankacc.dat","r");
    newrec=fopen("new.dat","w");
    printf("ENTER THE ACCOUNT NUMBER YOU WANT TO DELETE: ");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
                test++;
                printf("\nRECORD DELETED SUCCESSFULLY!\n");
            }
   }

   fclose(old);
   fclose(newrec);
   remove("bankacc.dat");
   rename("new.dat","bankacc.dat");

   if(test==0)
        {
            printf("\n\t\tRECORD NOT FOUND!!");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    ty();
                else if(main_exit==0)
                    delete_acc();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {
            printf("\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
            menu();
            else
            ty();
        }

}

void see(void)                                     //FUNCTION TO SEE VIA THE DETAILS OF THE CUSTOMER
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;

    ptr=fopen("bankacc.dat","r");
    printf("DO YOU WANT TO CHECK BY FOLLOWING OPTIONS: \n1.VIA ACCOUNT NUMBER \n2.VIA NAME \nENTER YOUR CHOICE: ");
    scanf("%d",&choice);

    if(choice!=1&&choice!=2)
    {
        printf("\nNOT A VALID CHOICE.");
    }

    else if (choice==1)
    {   printf("ENTER THE ACCOUNT NUMBER: ");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nACCOUNT NO.:%d\nNAME:%s \nDOB:%d/%d/%d \nAGE:%d \nADDRESS:%s \nCITIZENSHIP:%s \nPHONE NUMBER:%.0lf \nTYPE OF ACCOUNT:%s \nAMOUNT DEPOSITED:$ %.2f \nDATE OF DEPOSIT:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $%.2f AS INTEREST ON %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d/%d/%d ",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d/%d/%d ",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d OF EVERY MONTH ",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {
         printf("ENTER THE NAME: ");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nACCOUNT NO.: %d\nNAME: %s \nDOB: %d/%d/%d \nAGE: %d \nADDRESS: %s \nCITIZENSHIP: %s \nPHONE NUMBER: %.0lf \nTYPE OF ACCOUNT: %s \nAMOUNT DEPOSITED: $%.2f \nDATE OF DEPOSIT: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d/%d/%d ",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d/%d/%d ",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d/%d/%d ",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYOU WILL GET $.%.2f AS INTEREST ON %d OF EVERY MONTH",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYOU WILL GET NO INTEREST!!\a");

                     }

            }
        }
    }


    fclose(ptr);

     if(test!=1)
        {
            system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    ty();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
            printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void ty(void)
{
    printf("\n\n\n\nTHANK YOU FOR VISITING OUR BANK SITE. HOPE TO SEE YOU SOON!!");
}


void menu(void)
{
    int choice;

    system("cls");
    system("color 9");
    printf("\n\n\t\t\tABC BANK MANAGEMENT SYSTEM!");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.CREATE NEW ACCOUNT");
    printf("\n\t\t2.UPDATE INFORMATION OF EXISTING ACCOUNT");
    printf("\n\t\t3.TRANSACTIONS");
    printf("\n\t\t4.DETAILS OF EXISTING ACCOUNT");
    printf("\n\t\t5.VIEW THE CUSTOMER LIST");
    printf("\n\t\t6.REMOVING THE CURRENT ACCOUNT");
    printf("\n\t\t7.EXIT");
    printf("\n\n\n\n\n\t\t ENTER YOUR CHOICE: ");


    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_account();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:view_list();
        break;
        case 6:delete_acc();
        break;
        case 7:ty();
        break;

    }



}
int main()
{
    char pass[10],password[10]="hello";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    /*do
    {
    //if (pass[i]!=13&&pass[i]!=8)
        {
            printf("*");
            pass[i]=getch();
            i++;
        }
    }while (pass[i]!=13);
    pass[10]='\0';*/
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
