#include <stdio.h>
#include <stdlib.h>

char name[20], email[20], age[20];
int accountNumber, create_password, enteredAccount, enteredPassword, value = 0, number, balance = 5000, withdrawAmount, depositAmount;
char choice;
FILE *detail;
FILE *transactionDetail;

void create_account()
{
    printf("\t******************************************\n");
    printf("\t\tCreate your Account here\n");
    printf("\t******************************************\n\n");

    detail = fopen("Details.txt", "w");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    printf("Enter your name : ");
    scanf("%s", name);
    fprintf(detail, "Name : %s\n", name);

    printf("Enter your email : ");
    scanf("%s", email);
    fprintf(detail, "Email : %s\n", email);

    printf("Create an account number : ");
    scanf("%d", &accountNumber);
    fprintf(detail, "Account Number : %d\n", accountNumber);

    printf("Enter your age: ");
    scanf("%s", age);
    fprintf(detail, "Age : %s\n", age);

    printf("Create a password : ");
    scanf("%d", &create_password);
    fprintf(detail, "Password : %d\n", create_password);

    fclose(detail);
    transactionDetail = fopen("transactionDetail.txt", "w");
    fprintf(transactionDetail, "Balance : %d\n", balance);
    fclose(transactionDetail);
}
void accountDetails()
{
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    fscanf(detail, "Name : %s\n", name);
    fscanf(detail, "Email : %s\n", email);
    fscanf(detail, "Account Number : %d\n", &accountNumber);
    fscanf(detail, "Age : %s\n", age);
    fscanf(detail, "Password : %d\n", &create_password);
    fclose(detail);
    printf("Details\n");
    printf("Name : %s\n", name);
    printf("Email : %s\n", email);
    printf("Account Number : %d\n", accountNumber);
    printf("Age : %s\n", age);
    printf("Password : %d\n", create_password);
}
void accountBalance()
{
    printf("Account Balance\n");
    transactionDetail = fopen("transactionDetail.txt", "r");
    fscanf(transactionDetail, "Balance : %d\n", &balance);
    printf("Your Balance is  : %d rs\n", balance);
    fclose(transactionDetail);
}
void withdrawMoney()
{
    printf("Withdraw Money\n");
    printf("Enter amount you want to withdraw : ");
    scanf("%d", &withdrawAmount);
    transactionDetail = fopen("transactionDetail.txt", "r");
    fscanf(transactionDetail, "Balance : %d\n", &balance);
    fclose(transactionDetail);
    transactionDetail = fopen("transactionDetail.txt", "w");
    if (withdrawAmount <= balance)
    {
        printf("You have withdraw = %d rs\n", withdrawAmount);
        balance = balance - withdrawAmount;
        fprintf(transactionDetail, "Balance : %d\n", balance);
        fclose(transactionDetail);
    }
    else
    {
        printf("You have not enough money");
    }
}
void depositMoney()
{
    printf("Deposit Money\n");
    printf("Enter amount you want to deposit : ");
    scanf("%d", &depositAmount);
    transactionDetail = fopen("transactionDetail.txt", "r");
    fscanf(transactionDetail, "Balance : %d\n", &balance);
    fclose(transactionDetail);
    transactionDetail = fopen("transactionDetail.txt", "w");
    printf("You have deposited = %d rs\n", depositAmount);
    balance = balance + depositAmount;
    fprintf(transactionDetail, "Balance : %d\n", balance);
    fclose(transactionDetail);
    printf("You have not enough money");
}
void changePassword()
{
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    fscanf(detail, "Password : %d\n", &create_password);
    fclose(detail);
    printf("Password : %d\n", create_password);
    printf("Enter your new password : ");
    scanf("%d", &create_password);
    detail = fopen("Details.txt", "w");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }
    fprintf(detail, "Name : %s\n", name);
    fprintf(detail, "Email : %s\n", email);
    fprintf(detail, "Account Number : %d\n", accountNumber);
    fprintf(detail, "Age : %s\n", age);
    fprintf(detail, "Password : %d\n", create_password);
    fclose(detail);
}
int login()
{
    printf("\n\t**************************\n");
    printf("\t\tLogin\n");
    printf("\t**************************\n");

    FILE *detail;
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
        return 0;
    }

    fscanf(detail, "Name : %s\n", name);
    fscanf(detail, "Email : %s\n", email);
    fscanf(detail, "Account Number : %d\n", &accountNumber);
    fscanf(detail, "Age : %s\n", age);
    fscanf(detail, "Password : %d\n", &create_password);

    fclose(detail);

    printf("Enter your account number : ");
    scanf("%d", &enteredAccount);

    printf("Enter your password : ");
    scanf("%d", &enteredPassword);
    system("cls");
    if (enteredAccount == accountNumber && enteredPassword == create_password)
    {
        printf("Account Login Successfully\n");
        value = 1;
    }
    else
    {
        printf("Login Failed. Incorrect account number or password.\n");
    }
}
void loginMenu()
{
    printf("**********************************************\n");
    printf("Welcome to banking management System\n");
    printf("**********************************************\n");
    printf("\n1.Depoit a Money");
    printf("\n2.Withdraw a Money");
    printf("\n3.Transfer a money");
    printf("\n4.Check a balance");
    printf("\n5.Account details");
    printf("\n6.Change a password");
    printf("\n7.loan");
    printf("\n8.Exit\n");
    printf("\nEnter your choice : \n");
    scanf("%c", &choice);

    switch (choice)
    {
    case '1':
        system("cls");
        depositMoney();
        break;
    case '2':
        system("cls");
        withdrawMoney();
        break;
    case '3':
        printf("Money has been transferred");
        break;
    case '4':
        accountBalance();
        break;
    case '5':
        system("cls");
        accountDetails();
        break;
    case '6':
        changePassword();
        // printf("password");
        break;
    case '7':
        // loan();
        printf("amount has been added in your account");
        break;
    case '8':
        system("cls");
        exit(0);
    default:
        system("cls");
        loginMenu();
        break;
    }
    printf("\nEnter 1 to show main menu : ");
    scanf("%d", &number);
    if (number == 1)
    {
        loginMenu();
    }
    else
    {
        exit(0);
    }
}
void mainMenu()
{
    printf("\t**************************\n");
    printf("\t\tMenu\n");
    printf("\t**************************\n");
    printf("(1) Create an Account\n");
    printf("(2) Log in\n");
    printf("(3) Exit\n");
    printf("Enter your choice : ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
        system("cls");
        create_account();
        printf("\nYour Account has been created");
        login();
        break;
    case '2':
        system("cls");
        login();
        break;
    case '3':
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        mainMenu();
        break;
    }
}

int main()
{
    mainMenu();
    if (value == 1)
    {
        loginMenu();
    }

    return 0;
}
