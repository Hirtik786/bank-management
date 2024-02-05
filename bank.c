#include <stdio.h>
#include <stdlib.h>

char name[20], email[20], age[20];
int accountNumber, create_password, enteredAccount, enteredPassword;
char choice;

void create_account() {
    printf("\t******************************************\n");
    printf("\t\tCreate your Account here\n");
    printf("\t******************************************\n\n");

    FILE *detail;
    detail = fopen("Details.txt", "w");
    if (detail == NULL) {
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
}
int login() {
    printf("\n\t**************************\n");
    printf("\t\tLogin\n");
    printf("\t**************************\n");

    FILE *detail;
    detail = fopen("Details.txt", "r");
    if (detail == NULL) {
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

    if (enteredAccount == accountNumber && enteredPassword == create_password) {
        printf("Account Login Successfully");
    } else {
        printf("Login Failed. Incorrect account number or password.\n");
    }
}


void mainMenu() {
    printf("\t**************************\n");
    printf("\t\tMenu\n");
    printf("\t**************************\n");
    printf("(1) Create an Account\n");
    printf("(2) Log in\n");
    printf("(3) Exit\n");
    printf("Enter your choice : ");
    scanf(" %c", &choice);

    switch (choice) {
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

int main() {
    mainMenu();
    return 0;
}
