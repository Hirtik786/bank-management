#include <stdio.h>
int balance = 5000;
void change_password()
{
    int password;
    printf("enter a new password");
}
void withdraw()
{
    int withdraw;
    scanf("%d", &withdraw);
    printf("%d", balance - withdraw);
}
void loan()
{
    int loan;
    printf("Enter a loan amount");
    scanf("%d", &loan);
    printf("Your balnce: %d", balance + loan);
}
void transfer()
{
    int transfer;
    printf("enter a amount to transfer");
    scanf("%d", &transfer);
    printf("your current balance: %d", balance - transfer);
}
int main()
{
    int choice;
    printf("enter a number");
    printf("************************************\n");
    printf("Welcome to banking management System\n");
    printf("************************************\n");
    printf("\n1.Withdraw a Money\n");
    printf("\n2.Transfer a money\n");
    printf("\n3.Check a balance\n");
    printf("\n4.Account details\n");
    printf("\n5.Change a password\n");
    printf("\n6.loan\n");
    printf("\n7.Exit\n\n");
    printf("\nenter a number\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        withdraw();
        printf("Money has been withdrawn");
        break;
    case 2:
        transfer();
        printf("Money has been transferred");
        transfer();
        break;
    case 3:
        printf("your balance: %d\n", balance);
        break;
    case 4:
        printf("Details");
        break;
    case 5:
        printf("password");
        break;
    case 6:
        loan();
        printf("amount has been added in your account");
        break;
    case 7:
        printf("exit");
    default:
        printf("please select any of  above options.");
        break;
    }
}

// deposit

void deposit()
{
    FILE *deposit;
    deposit = fopen("Details.txt", "w");
    int account_number, amount;
    printf("enter a account number");
    scanf("%d", &account_number);
    printf("enter a amount");
    scanf("%d", &amount);
    if (amount < balance)
    {
        fprintf(deposit, "%d", balance - amount);
    }
    else
    {
        printf("You have not enough money in your account");
    }
}