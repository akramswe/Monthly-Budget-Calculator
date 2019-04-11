#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
void view_expense();
struct date{
    int month,day,year;
    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    float amt1;
    float amt2;
    float amt3;
    float amt4;
    float amt5;
    float amt6;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

    struct {

    float food;
    float cloth;
    float shelter;
    float house;
    float trnst;
    float health;
    float prsnl;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }expense;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the amount to Salary:$");
    scanf("%f",&add.amt);
    printf("\nEnter the amount to Other Income:$");
    scanf("%f",&add.amt1);


        fprintf(ptr,"%d %s %f %f %d/%d/%d\n",add.acc_no,add.name,add.amt,add.amt1,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void new_expense()

{
   int choice;
    FILE *ptr;

    ptr=fopen("expense.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the serial number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %f %f %f %f %f %f %f %d/%d/%d\n",&add.acc_no,&add.amt,&add.amt1,&add.amt2,&add.amt3,&add.amt4,&add.amt5,&add.amt6,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nFood (groceries, dining out, etc.):$");
    scanf("%f",&add.amt);
    printf("\nClothing (jeans, shoes, jewelry, etc.):$");
    scanf("%f",&add.amt1);
    printf("\nShelter (mortgage, rent, taxes, etc.):$");
    scanf("%f",&add.amt2);
    printf("\nHousehold (utilities, cell phone, cable, maintenance, etc.):$");
    scanf("%f",&add.amt3);
    printf("\nTransportation (public transportation, parking, gas, etc.):$");
    scanf("%f",&add.amt4);
    printf("\nHealth (insurance, medications, doctor visits, etc.):$ ");
    scanf("%f",&add.amt5);
    printf("\nPersonal (gifts, charity, entertainment, hobbies, etc.):$");
    scanf("%f",&add.amt6);

    fprintf(ptr,"%d %f %f %f %f %f %f %f %d/%d/%d\n",add.acc_no,add.amt,add.amt1,add.amt2,add.amt3,add.amt4,add.amt5,add.amt6,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void view_expense()
{
    FILE *view;
    view=fopen("expense.dat","r");
    int test=0;
    double t=1.0;
    float total=0.0;
    float total1=0.0;
    system("cls");
    printf("\n Date\t Serial No.\t Food\tCloth\tShelter\tHousehold Transportation Health Personal \tTotal\n");

    while(fscanf(view,"%d %f %f %f %f %f %f %f %d/%d/%d",&add.acc_no,&add.amt,&add.amt1,&add.amt2,&add.amt3,&add.amt4,&add.amt5,&add.amt6,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
            t = 3 + add.acc_no;
            total = add.amt+add.amt1+add.amt2+add.amt3+add.amt4+add.amt5+add.amt6;
           printf("\n%d/%d/%d%6d\t\t%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f",add.deposit.month,add.deposit.day,add.deposit.year,add.acc_no,add.amt,add.amt1,add.amt2,add.amt3,add.amt4,add.amt5,add.amt6,total,t);
           total1 = total1 + total;
           test++;
       }
       printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t Total Monthly Expenses: $%.2f",total1);

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
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}


void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    double t=1.0;
    float total=0.0;
    system("cls");
    printf("\nACC. NO.\tComment\t\t\tSalary\t\tOther Income\tTotal Income\n");

    while(fscanf(view,"%d %s %f %f %d/%d/%d",&add.acc_no,add.name,&add.amt,&add.amt1,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           t = 3 + add.acc_no;
           total = add.amt + add.amt1;
           printf("\n%6d\t %10s\t\t\t%.2f\t\t%.2f\t\t%.2f",add.acc_no,add.name,add.amt,add.amt1,total,t);
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
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void b_review()
{
      FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    double t=1.0;
    float total2=0.0;
    system("cls");
    while(fscanf(view,"%d %s %f %f %d/%d/%d",&add.acc_no,add.name,&add.amt,&add.amt1,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           t = 3 + add.acc_no;
           total2 = add.amt + add.amt1;
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view=fopen("expense.dat","r");
    float total=0.0;
    float total1=0.0;
    system("cls");
    while(fscanf(view,"%d %f %f %f %f %f %f %f %d/%d/%d",&add.acc_no,&add.amt,&add.amt1,&add.amt2,&add.amt3,&add.amt4,&add.amt5,&add.amt6,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
            t = 3 + add.acc_no;
            total = add.amt+add.amt1+add.amt2+add.amt3+add.amt4+add.amt5+add.amt6;
           total1 = total1 + total;
           test++;
       }
    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}
            float total3 = 0.0;
            total3=total2-total1;
            printf("\xB2\xB2\ Under/Over Budget \xB2\xB2\ \n");
           printf("\nTotal Monthly Income:$ %.2f",total2);
           printf("\nTotal Monthly Expenses:$%.2f",total1);
         printf("\n--------------------------------------\n");
        printf("Total under/over budget: $%.2f",total3);

        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}



void close(void)
{
    printf("\n\n\n\nThis C Mini Project is developed by Code With C team!");
    }


void menu(void)
{   int choice;
    system("cls");
    //system("color 9");
    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2 MONTHLY BUDGET CALCULATE \xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\t\t1.Create new account\n\t\t2.View your income list\n\t\t3.Update information of existing account\n\t\t4.Enter here daily Expense\n\t\t5.View daily Expense\n\t\t6.Under/Over Budget\n\t\t7.Removing existing account\n\t\t8.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:view_list();
        break;
        case 3:edit();
        break;
        case 4:new_expense();
        break;
        case 5:view_expense();
        break;
        case 6:b_review();
        break;
        case 7:erase();
        break;
        case 8:close();
        break;

    }



}
int main()
{
    char pass[10],password[10]="akram";
    int i=0;
    menu();
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
