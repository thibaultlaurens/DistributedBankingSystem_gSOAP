#include "soapH.h"
#include "account1.nsmap"
#include <pthread.h>
#include "config.h"
// Max request backlog
#define BACKLOG (100) 

using namespace std;

class BankAccount {
private:
    float amount;
public:

    float Init(float amount) {
        this->amount = amount;
        return this->amount;
    }

    float AddMoney(float amount) {
        this->amount += amount;
        return this->amount;
    }

    float WithdrawMoney(float amount) {
        if (this->amount - amount > 0) {
            this->amount -= amount;
        }
        return this->amount;
    }

    float GetAmount() {
        return this->amount;
    }

};

//the account is a global var in order to ba accessible from the service method
BankAccount account;

int main(int argc, char** argv) {

    struct soap soap;
    soap_init(&soap);

    soap.send_timeout = 60;     // 60 seconds
    soap.recv_timeout = 60;     // 60 seconds
    soap.accept_timeout = 3600; // server stops after 1 hour of inactivity
    soap.max_keep_alive = 100;  // max keep-alive sequence 

    void *process_request(void*);
    struct soap *tsoap;
    pthread_t tid;
    //argv[1] contains port number
    int port = atoi(argv[1]);
    SOAP_SOCKET m, s;

    m = soap_bind(&soap, NULL, port, BACKLOG);

    if (!soap_valid_socket(m)) {
        exit(-1);
    }

    printf("connection OK, master = %d\n", m);

    while (true) {

        s = soap_accept(&soap);

        if (!soap_valid_socket(s)) {
            if (soap.errnum) {
                soap_print_fault(&soap, stderr);
                exit(1);
            }
            printf("server timed out\n");
            break;
        }
        printf("Thread %d accepts socket %d\n", m, s);
        tsoap = soap_copy(&soap); // make a safe copy of the soap context
        if (!tsoap)
            break;
        //create a new thread to execute the action
        pthread_create(&tid, NULL, (void*(*)(void*))process_request, (void*) tsoap);
    }

    soap_done(&soap); // detach soap struct
    return 0;
}

void *process_request(void *soap) {
    pthread_detach(pthread_self());
    soap_serve((struct soap*) soap);
    soap_destroy((struct soap*) soap); // dealloc C++ data
    soap_end((struct soap*) soap); // dealloc data and clean up
    soap_done((struct soap*) soap); // detach soap struct
    free(soap);
    return NULL;
}

//service methods, interact with the bankaccount object, return the amount every time
int account1__init(struct soap *soap, float amount, float *result) {
    *result = account.Init(amount);
    return SOAP_OK;
}
int account1__getAmount(struct soap *soap, float *result) {
    *result = account.GetAmount();
    return SOAP_OK;
}
int account1__addMoney(struct soap *soap, float amount, float *result) {
    *result = account.AddMoney(amount);
    return SOAP_OK;
}
int account1__withdrawMoney(struct soap *soap, float amount, float *result) {
    *result = account.WithdrawMoney(amount);
    return SOAP_OK;
}
