#include "soapH.h"
#include "account1.nsmap"
#include <stdio.h>
#include "config.h"

using namespace std;

char bankaccount[][22] = {"http://localhost:8456", "http://localhost:8567"};
struct soap soap;

class Client {
private:
    //Ask the user to choose an operation and call the right bankaccount method
    void OperationMenu(int accountId) {
        int input;
        float amount;
        float result;

        printf("Select an operation: \n\t");
        printf("1- GetAmount\n\t2- AddMoney\n\t3- WithDrawMoney\n\t4- Return to account selection\n");
        scanf("%d", &input);
        if (input == 1) {
            soap_call_account1__getAmount(&soap, bankaccount[accountId], "", &result);
        }
        if (input == 2 || input == 3) {
            //ask for the amount
            printf("Enter the amount\n");
            scanf("%f", &amount);

            if (input == 2) {
                soap_call_account1__addMoney(&soap, bankaccount[accountId], "", amount, &result);
            } else if (input == 3) {
                soap_call_account1__withdrawMoney(&soap, bankaccount[accountId], "", amount, &result);
            }
        }
        if (input == 4) {
            AccountMenu();
        }
        if (soap.error) {
            soap_print_fault(&soap, stderr);
            exit(-1);
        } else
            printf("Operation OK, amount = %f\n", result);
        OperationMenu(accountId);
    }
    
public:
    //Ask the user to choose an account and call the operation menu
    void AccountMenu() {
        int input;
        printf("Select an account: \n\t");
        printf("0- Account1\n\t1- Account2\n");
        scanf("%d", &input);
        OperationMenu(input);
    }

    

};

int main(int argc, char** argv) {
    float result1, result2;
    Client client;

    soap_init(&soap);

    //Init 2 bankaccounts with two amounts
    soap_call_account1__init(&soap, bankaccount[0], "", 300.00, &result1);
    soap_call_account1__init(&soap, bankaccount[1], "", 150.00, &result2);
    printf("init account OK\n");

    client.AccountMenu();

    return 0;
}
