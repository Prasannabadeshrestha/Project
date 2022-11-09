#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct customers
{
    char fName[50];
    char lName[50];
    char Address[50];
    char esewa_ID[50];
    char Email[50];
    char MPIN[50];
    float Balance;
    float Reward_points;
    char ans;
    char code[50];
};

int main()
{
    struct customers customer, customerr;
    FILE *fe; 
    char eSewa[50], ID[50], ID1[50], mpin[50];

    int chosen; 
    char cont = 'Y';
    float amount;

    printf("eSewa\nWelcome :)");
    printf("\n\n??Login or Register??");
    printf("\n\n1. Login to your account");
    printf("\n2. Register for free\n");

    printf("\n...ENTERING...:\t");
    scanf("%d", &chosen);

    if (chosen == 2)
    {
        system("clear");

        printf("Enter your first name:");
        scanf("%s", customer.fName);
        printf("\n\nEnter your last name:");
        scanf("%s", customer.lName);
        printf("\n\nEnter your address:");
        scanf("%s", customer.Address);
        printf("\n\nEnter your eSewa ID(Mobile no.):");
        scanf("%s", customer.esewa_ID);
        printf("\n\nEnter your email:");
        scanf("%s", customer.Email);
        printf("\n\nEnter your new MPIN (DO NOT FORGET):");
        scanf("%s", customer.MPIN);
        customer.Balance = 0;
        customer.Reward_points = 0;

        // copying ID in file, new filename
        strcpy(eSewa, customer.esewa_ID);

        // to concatenate strings .esewa with filename
        fe = fopen(strcat(eSewa, ".esewa"), "w");
        // store customer, struct,no.of instance and fe pointer
        fwrite(&customer, sizeof(struct customers), 1, fe);

        if (fwrite != 0)
        {
            printf("\n\n\t.....Congratualations!! You have successfully registered your account.....");
        }
        else
        {
            printf("\n\n Sorry! Try again.");
        }
        fclose(fe);
    }
    
    if (chosen == 1)
    {
        system("clear");

        printf("Enter eSewa ID:");
        scanf("%s", ID);
        printf("\n\nMPIN:");
        scanf("%s", mpin);
        strcpy(eSewa, ID);

        fe = fopen(strcat(eSewa, ".esewa"), "r");
        {
            printf("\n\n...Entering esewa...");
        }
        if (fe == NULL)
        {
            printf("\n\n.....Error!! First register your account.....");
        }
        else
        {
            fread(&customer, sizeof(struct customers), 1, fe);
            fclose(fe);

            if (!strcmp(mpin, customer.MPIN)) 

            {
                while (cont == 'Y')
                {
                    system("clear");
                    printf("\n\nPress 1 to check balance");
                    printf("\n\nPress 2 to load money");
                    printf("\n\nPress 3 to send money");
                    printf("\n\nPress 4 to check reward points");
                    printf("\n\nPress 5 to topup");
                    printf("\n\nPress 6 to change MPIN");
                    printf("\n\nChoose:");
                    scanf("%d", &chosen);

                    switch (chosen) 
                    {
                    case 1:
                        system("clear");
                        printf("\nNPR %.2f Balance", customer.Balance);
                        break;

                    case 2: 
                        system("clear");
                        printf("\n\nLoad money:");
                        scanf("%f", &amount);
                        customer.Balance += amount;
                        fe = fopen(eSewa, "w"); 
                        fwrite(&customer, sizeof(struct customers), 1, fe);
                        if (fwrite != NULL)
                            printf("\n\n!!!Deposite successful!!!");
                        fclose(fe);
                        break;

                    case 3: 
                        system("clear");
                        printf("\n\nEnter eSewa ID to send money:");
                        scanf("%s", ID);
                        printf("\n\nEnter amount NPR:");
                        scanf("%f", &amount);
                        if (amount > customer.Balance)
                            printf("\n\nInsufficient balance.");
                        else
                        {
                            fe = fopen(strcat(ID, ".esewa"), "r");

                            if (fe == NULL)
                            {
                                printf("\n\n!!!Number not registered!!!");
                            }
                            else
                            {
                                fread(&customerr, sizeof(struct customers), 1, fe);
                                fclose(fe);

                                customerr.Balance += amount; 

                                fe = fopen(eSewa, "w");
                                fwrite(&customerr, sizeof(struct customers), 1, fe);

                                if (fwrite != NULL)
                                {
                                    printf("\n\n!!!NPR %.2f to %s payment successful!!!", amount, ID);
                                    fclose(fe);

                                    customer.Balance -= amount; 
                                    strcpy(eSewa, customer.esewa_ID);
                                    fe = fopen(strcat(eSewa, ".esewa"), "w");
                                    fwrite(&customer, sizeof(struct customers), 1, fe);
                                    fclose(fe);
                                }
                            }
                        }
                        break;

                    case 4: 
                        system("clear");
                        printf("Your reward point is: %.2f ", customer.Reward_points++);
                        scanf("%f", &customer.Reward_points);
                        break;

                    case 5: 
                        system("clear");
                        printf("NPR %.2f Balance", customer.Balance);
                        printf("\n\nMobile(10 digits)/Landline(8 digits): ");
                        scanf("%s", ID);
                        printf("\n\nHave a promo code? Enter Y or N: ");
                        scanf("%s", &customer.ans);
                        fe = fopen(strcat(eSewa, ".esewa"), "r");
                        if (customer.ans == 'Y')
                        {
                            printf("\n\nEnter promo code: ");
                            scanf("%s", customer.code);
                            printf("\n\nEnter amount NPR: ");
                            scanf("%f", &amount);
                            strcpy(eSewa, ID);
                        }
                        else
                        {
                            printf("\n\nEnter amount NPR:");
                            scanf("%f", &amount);
                            strcpy(eSewa, ID);
                        }

                        if (amount > customer.Balance)
                            printf("\n\nInsufficient balance.");
                        else
                        {
                            fe = fopen(strcat(ID, ".esewa"), "r");

                            if (fe == NULL)
                            {
                                printf("\n\n!!!Number not registered!!!");
                            }
                            else
                            {
                                fread(&customerr, sizeof(struct customers), 1, fe);
                                fclose(fe);

                                customerr.Balance += amount; 

                                fe = fopen(eSewa, "w");
                                fwrite(&customerr, sizeof(struct customers), 1, fe);

                                if (fwrite != NULL)
                                {
                                    printf("\n\n!!!NPR %.2f to %s payment successful!!!", amount, ID);
                                    fclose(fe);

                                    customer.Balance -= amount;
                                    strcpy(eSewa, customer.esewa_ID);
                                    fe = fopen(strcat(eSewa, ".esewa"), "w");
                                    fwrite(&customer, sizeof(struct customers), 1, fe);
                                    fclose(fe);
                                }
                            }
                        }
                        break;

                    case 6:
                        printf("\n\nEnter old MPIN: ");
                        scanf("%s", mpin);
                        if (!strcmp(mpin, customer.MPIN))
                        {
                            printf("\n\nEnter new MPIN: ");
                            scanf("%s", mpin);
                            fe = fopen(eSewa, "w");
                            strcpy(customer.MPIN, mpin);
                            fwrite(&customer, sizeof(struct customers), 1, fe);
                            fclose(fe);
                            printf("\n\n.....MPIN changed....");
                        }
                        else
                            printf("\n\n...Invalid MPIN...");

                    default:
                        break;
                    }
                    printf("\n\n??Continue to proceed?? [Y/N]: "); 
                    scanf("%s", &cont);
                    cont = toupper(cont);
                }
            }
            else
            {
                printf("\n\nIncorrect MPIN..try again..");
            }
        }
    }

    return 0;
}
