#include <stdio.h>
int main(){
    char name[20],identity[30],address[150],num[30];
    int age,balance=5000;
    printf("\n###########################\n");
    printf("\nWelcome to our Loan services\n");
    printf("\n############################\n");
    FILE *loan;
    loan=fopen("loan_details.txt","w");
    if (loan==NULL)
    {
        printf("error opening file");
    }
    printf("Enter your name: ");
    scanf("%s",name);
    fprintf(loan,"name: %s\n",name);

    printf("enter a identity number: ");
    scanf("%s",identity);
    fprintf(loan,"identity: %s\n",identity);

    printf("enter a address: ");
    scanf("%s",address);
    fprintf(loan,"Address %s\n",address);

    printf("enter a contact number: ");
    scanf("%s",num);
    fprintf(loan,"Conatct %s\n",num);

    printf("enter a age: ");
    scanf("%d",&age);
    fprintf(loan,"age %d\n",age);

    fprintf(loan,"Balance%d",balance);
    if (age>18)
    {
        int choice;
        printf("\n\t\t##### Select a Loan Amount #####\n");
        printf("\n 1: 5000\n");
        printf("\n 2: 10000\n");
        printf("\n 3: 15000\n");
        printf("\n 4: 20000\n");
        printf("\nenter a choice number\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        fscanf(loan,"%d",&balance);
        balance=balance+5000;
        fprintf(loan,"New balance %d\n\n",balance);
        printf("\n\n#### Thankyou for Choosing our Services! ####\n");
            break;
            case 2: 
            fscanf(loan,"%d",&balance);
        balance=balance+10000;
        fprintf(loan,"New balance %d\n",balance);
         printf("\n\n#### Thankyou for Choosing our Services! ####\n");
        break;
        case 3:
         fscanf(loan,"%d",&balance);
        balance=balance+15000;
        fprintf(loan,"New balance %d\n",balance);
         printf("\n\n#### Thankyou for Choosing our Services! ####\n");
        break;
        case 4:
        fscanf(loan,"%d",&balance);
        balance=balance+20000;
        fprintf(loan,"New balance %d\n",balance);
         printf("\n\n#### Thankyou for Choosing our Services! ####\n");
        default:
            break;
        }
    
fclose(loan);
}
else{
    printf("\n\n#### You are under 18 you are not eligible for loan #####\n");

      printf("\n\n#### Thankyou for Choosing our Services! ####\n");
}
}