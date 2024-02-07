#include <stdio.h>
#include <stdlib.h>

char name[20], email[20];
int accountNumber, age, create_password, enteredAccount, enteredPassword, value = 0, value1 = 0, number, balance = 5000, withdrawAmount, depositAmount, transferAmount, aNTransfer;
char choice;
FILE *detail;
FILE *balanceFile;
FILE *transactionDetails;

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

    printf("Enter your email : ");
    scanf("%s", email);

    printf("Create an account number : ");
    scanf("%d", &accountNumber);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Create a password : ");
    scanf("%d", &create_password);
    if (age >= 18)
    {
        fprintf(detail, "Name : %s\n", name);
        fprintf(detail, "Email : %s\n", email);
        fprintf(detail, "Account Number : %d\n", accountNumber);
        fprintf(detail, "Age : %d\n", age);
        fprintf(detail, "Password : %d\n", create_password);
    }
    fclose(detail);
    balanceFile = fopen("balanceFile.txt", "w");
    fprintf(balanceFile, "Balance : %d\n", balance);
    fclose(balanceFile);
    transactionDetails = fopen("transactionDetails.txt", "w");
    fclose(transactionDetails);
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
    fscanf(detail, "Age : %d\n", &age);
    fscanf(detail, "Password : %d\n", &create_password);
    fclose(detail);
     printf("\n\t************************\n");
    printf("\t\tDetails\n");
    printf("\t************************\n\n");
    printf("Name : %s\n", name);
    printf("Email : %s\n", email);
    printf("Account Number : %d\n", accountNumber);
    printf("Age : %d\n", age);
    printf("Password : %d\n", create_password);
}
void accountBalance()
{
    printf("\n\t******************************\n");
    printf("\t\tAccount Balance\n");
    printf("\t******************************\n\n");
    balanceFile = fopen("balanceFile.txt", "r");
    fscanf(balanceFile, "Balance : %d\n", &balance);
    printf("Your Balance is  : %d rs\n", balance);
    fclose(balanceFile);
}
void withdrawMoney()
{
    printf("\n\t******************************\n");
    printf("\t\tWithdraw Money\n");
    printf("\t******************************\n\n");
    printf("Enter amount you want to withdraw : ");
    scanf("%d", &withdrawAmount);
    balanceFile = fopen("balanceFile.txt", "r");
    fscanf(balanceFile, "Balance : %d\n", &balance);
    fclose(balanceFile);
    balanceFile = fopen("balanceFile.txt", "w");
    if (withdrawAmount <= balance)
    {
        printf("You have withdraw = %d rs\n", withdrawAmount);
        balance = balance - withdrawAmount;
        fprintf(balanceFile, "Balance : %d\n", balance);
        fclose(balanceFile);
        transactionDetails = fopen("transactionDetails.txt", "a");
        fprintf(transactionDetails, "You have withdrawn %d rs\n", withdrawAmount);
        fclose(transactionDetails);
    }
    else
    {
        printf("You have not enough money");
    }
}
void depositMoney()
{
    printf("\n\t******************************\n");
    printf("\t\tDeposit Money\n");
    printf("\t******************************\n\n");
    printf("Enter amount you want to deposit : ");
    scanf("%d", &depositAmount);
    balanceFile = fopen("balanceFile.txt", "r");
    fscanf(balanceFile, "Balance : %d\n", &balance);
    fclose(balanceFile);
    balanceFile = fopen("balanceFile.txt", "w");
    printf("You have deposited = %d rs\n", depositAmount);
    balance = balance + depositAmount;
    fprintf(balanceFile, "Balance : %d\n", balance);
    fclose(balanceFile);
    transactionDetails = fopen("transactionDetails.txt", "a");
    fprintf(transactionDetails, "You have deposited %d rs\n", depositAmount);
    fclose(transactionDetails);
}
void moneyTransfer()
{
    printf("\n\t******************************\n");
    printf("\t\tTransfer Money\n");
    printf("\t******************************\n\n");
    printf("Enter account number in which you want to transfer : ");
    scanf("%d", &aNTransfer);
    printf("Enter amount you want to transfer : ");
    scanf("%d", &transferAmount);
    balanceFile = fopen("balanceFile.txt", "r");
    fscanf(balanceFile, "Balance : %d\n", &balance);
    fclose(balanceFile);
    balanceFile = fopen("balanceFile.txt", "w");
    if (transferAmount <= balance)
    {
        printf("You have transfer %d rs to account number : %d\n", transferAmount, aNTransfer);
        balance = balance - transferAmount;
        fprintf(balanceFile, "Balance : %d\n", balance);
        fclose(balanceFile);
        transactionDetails = fopen("transactionDetails.txt", "a");
        fprintf(transactionDetails, "You have transfer %d rs to account number : %d\n", transferAmount, aNTransfer);
        fclose(transactionDetails);
    }
    else
    {
        printf("You have not enough money");
    }
}
void transactionDetail()
{
    printf("\n\t******************************\n");
    printf("\t\tTransaction Details\n");
    printf("\t******************************\n\n");
    transactionDetails = fopen("transactionDetails.txt", "r");
    char buffer[50];
    while (fgets(buffer, sizeof(buffer), transactionDetails) != NULL)
    {
        printf("%s", buffer);
    }
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
    printf("\n\t**************************\n");
    printf("\t\tChange Password\n");
    printf("\t**************************\n\n");
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
    fprintf(detail, "Age : %d\n", age);
    fprintf(detail, "Password : %d\n", create_password);
    fclose(detail);
}
int login()
{
    printf("\n\t**************************\n");
    printf("\t\tLogin\n");
    printf("\t**************************\n\n");

    FILE *detail;
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    fscanf(detail, "Name : %s\n", name);
    fscanf(detail, "Email : %s\n", email);
    fscanf(detail, "Account Number : %d\n", &accountNumber);
    fscanf(detail, "Age : %d\n", &age);
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
    printf("**********************************************\n\n");
    printf("\n1.Depoit a Money");
    printf("\n2.Withdraw a Money");
    printf("\n3.Transfer a money");
    printf("\n4.Check a balance");
    printf("\n5.Account details");
    printf("\n6.Transaction details");
    printf("\n7.Change a password");
    printf("\n8.loan");
    printf("\n9.Exit\n");
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
        system("cls");
        moneyTransfer();
        break;
    case '4':
        system("cls");
        accountBalance();
        break;
    case '5':
        system("cls");
        accountDetails();
        break;
    case '6':
        system("cls");
        transactionDetail();
        break;
    case '7':
        system("cls");
        changePassword();
        break;
    case '8':
        // loan();
        printf("amount has been added in your account");
        break;
    case '9':
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
    printf("\t**************************\n\n");
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
        system("cls");
        if (age >= 18)
        {
            printf("\nYour Account has been created");
            login();
        }
        else
        {
            printf("\nYou are under 18 you are not eligible for account creation");
        }
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
