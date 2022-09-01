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
    FILE *fe, *fes; // for customer 1 and 2
    // file name and customers ID
    char eSewa[50], ID[50], ID1[50], mpin[50];

    int chosen; // to choose both login/register and other options
    char cont;
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
        customer.Balance = 0; // initial amount zero
        customer.Reward_points = 0;

        // copying ID in file, new filename
        strcpy(eSewa, customer.esewa_ID);

        // to concatenate strings .esewa with filename
        fe = fopen(strcat(eSewa, ".esewa"), "w");
        // store customer, struct,no.of instance and fe pointer
        fwrite(&customer, sizeof(struct customers), 1, fe);

        // successfully written file and registered acc
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
    // take input from user and extract info from file if pin matched: load and send money
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

        if (!strcmp(mpin, customer.MPIN)) // comparing previously written pin and currently

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

            switch (chosen) // for cases
            {
            case 1:
                system("clear");
                printf("\nNPR %.2f Balance", customer.Balance);
                break;

            case 2: // To load money
                system("clear");
                printf("\n\nLoad money:");
                scanf("%f", &amount);
                customer.Balance += amount;
                fe = fopen(eSewa, "w"); // no concate as its already done above
                fwrite(&customer, sizeof(struct customers), 1, fe);
                if (fwrite != NULL)
                    printf("\n\n!!!Deposite successful!!!");
                fclose(fe);
                break;

            case 3: // To send money
                system("clear");
                printf("\n\nEnter eSewa ID to send money:");
                scanf("%s", ID);
                printf("\n\nEnter amount NPR:");
                scanf("%f", &amount);
                if (amount > customer.Balance)
                    printf("\n\nInsufficient balance.");
                else
                {
                    fes = fopen(strcat(ID, ".esewa"), "r");

                    if (fes == NULL)
                    {
                        printf("\n\n!!!Number not registered!!!");
                    }
                    else
                    {
                        fread(&customerr, sizeof(struct customers), 1, fes);
                        fclose(fes);

                        customerr.Balance += amount; // update balance of customer 2

                        fes = fopen(eSewa, "w");
                        fwrite(&customerr, sizeof(struct customers), 1, fes);

                        if (fwrite != NULL)
                        {
                            printf("\n\n!!!NPR %.2f to %s payment successful!!!", amount, ID);
                            fclose(fes);

                            customer.Balance -= amount; // update balance of customer 1
                            strcpy(eSewa, customer.esewa_ID);
                            fe = fopen(strcat(eSewa, ".esewa"), "w");
                            fwrite(&customer, sizeof(struct customers), 1, fe);
                            fclose(fe);
                        }
                    }
                }
                break;

            case 4: // Reward points: Need to improvise
                system("clear");
                printf("Your reward point is: %.2f ", customer.Reward_points++);
                scanf("%f", &customer.Reward_points);
                break;

            case 5: // Topup
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
                    fes = fopen(strcat(ID, ".esewa"), "r");

                    if (fes == NULL)
                    {
                        printf("\n\n!!!Number not registered!!!");
                    }
                    else
                    {
                        fread(&customerr, sizeof(struct customers), 1, fes);
                        fclose(fes);

                        customerr.Balance += amount; // update balance of customer 2

                        fes = fopen(eSewa, "w");
                        fwrite(&customerr, sizeof(struct customers), 1, fes);

                        if (fwrite != NULL)
                        {
                            printf("\n\n!!!NPR %.2f to %s payment successful!!!", amount, ID);
                            fclose(fes);

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
                if (!strcmp(mpin, customer.MPIN)) // comparing old pin
                    printf("Enter new MPIN: ");
                scanf("%s", mpin);
                strcpy(customer.MPIN, mpin); // copying new pin
                fe = fopen(strcat(eSewa, ".esewa"), "w");
                fwrite(&customer, sizeof(struct customers), 1, fe);
                if (fwrite != NULL)
                    printf("\n\\n.....MPIN changed....");
                fclose(fe);

            default:
                printf("\n\n...Invalid...");
                break;
            }
            printf("\n\n??Continue to proceed?? [Y/N]: "); // Not working if clicked y
            scanf("%s", &cont);
        }
    }    
}
else
{
    printf("\n\nIncorrect MPIN..try again..");
}
return 0;
}