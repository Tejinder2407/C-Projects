/*Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144-ZDD*/

#include<stdio.h>
#include"commonHelpers.h"
#include"account.h"
#include"accountTicketingUI.h"

int menuModifyPerson = 0;
int menuModifyLogin = 0;

void getAccount(struct Account* account) {
    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    printf("Enter the account number: ");
    account->accountNumber = getPositiveInteger();
    printf("\nEnter the account type (A=Agent | C=Customer): ");
    account->accountType = getCharOption("AC");

    printf("\n");
    getPerson(&account->person);
    if (account->accountType == 'A') {
        printf("\n");
        getUserLogin(&account->userLogin);
    }
    else if (account->accountType == 'C') {
       
        setUserLoginToSafeState(&account->userLogin);
    }
    printf("\n");
}
void getPerson(struct Person* person) {
    printf("Person Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter the person's full name (30 chars max): ");
    getCString(person->personName, 1, 30);
    printf("Enter birth year (current age must be between 18 and 110): ");
    person->birthYear = getIntFromRange(1911, 2003);
    printf("Enter the household Income: $");
    person->householdIncome = getPositiveDouble();
    printf("Enter the country (30 chars max.): ");
    getCString(person->country, 1, 30);
}
void getUserLogin(struct UserLogin* userLogin) {
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter user login (10 chars max): ");
    getCString(userLogin->userLoginName, 0, 10);
    printf("Enter the password (must be 8 chars in length): ");
    getCString(userLogin->password, 8, 8);
}

void updateAccount(struct Account* account) {
    printf("\nUpdate Account: %05d (%s)\n", account->accountNumber, account->person.personName);
    printf("----------------------------------------\n");
    printf("1) Update account type (current value: %c)\n"
        "2) Person\n"
        "3) Login\n"
        "0) Done\n"
        "Selection: ", account->accountType);
    int option = getIntFromRange(0, 3);
    printf("\n");
    if (option == 1) {
        // input account type -
        printf("Enter the account type (A=Agent | C=Customer): ");
        char c;
        c = getCharOption("AC");
        account->accountType = c;
        if (c == 'A') { 
            printf("\nAgent type accounts require a user login.  Please enter this information now:\n");
            printf("\n");
            getUserLogin(&account->userLogin);
        }
        else {
            
            setUserLoginToSafeState(&account->userLogin);
        }
    }
    else if (option == 2) {
        menuModifyPerson = 1;
        while (menuModifyPerson == 1) {
            updatePerson(&account->person);
        }
    }
    else if (option == 3) {
        if (account->accountType == 'C') {
            printf("ERROR:  Customer account types don't have user logins!\n");
        }
        else if (account->accountType == 'A') {
            menuModifyLogin = 1;
            while (menuModifyLogin == 1) {
                updateUserLogin(&account->userLogin);
            }
        }
    }
    else if (option == 0) {
        setModifyMenuActive(0);
        return;
    }
}

void updatePerson(struct Person* person) {

    printf("Person Update Options\n"
        "----------------------------------------\n"
        "1) Full name (current value: %s)\n"
        "2) Household Income (current value: $%.2lf)\n"
        "3) Country (current value: %s)\n"
        "0) Done\n"
        "Selection: ", person->personName, person->householdIncome, person->country);
    int option = getIntFromRange(0, 3);

    if (option == 1) {
        printf("\n");
        printf("Enter the person's full name (30 chars max): ");
        getCString(person->personName, 1, 30);
        printf("\n");
    }
    else if (option == 2) {
        printf("\n");
        printf("Enter the household Income: $");
        person->householdIncome = getPositiveDouble();
        printf("\n");
    }
    else if (option == 3) {
        printf("\n");
        printf("Enter the country (30 chars max.): ");
        getCString(person->country, 1, 30);
        printf("\n");
    }
    else if (option == 0) {
        menuModifyPerson = 0;
        return;
    }
}

void updateUserLogin(struct UserLogin* userLogin) {
    printf("User Login: %s - Update Options\n"
        "----------------------------------------\n"
        "1) Password\n"
        "0) Done\n"
        "Selection: ", userLogin->userLoginName);
    int  option;
    option = getIntFromRange(0, 1);
    if (option == 1) {
        printf("\n");
        printf("Enter the password (must be 8 chars in length): ");
        getCString(userLogin->password, 0, 8);
        printf("\n");
    }
    else if (option == 0) {
        menuModifyLogin = 0;
        return;
    }
}

void setUserLoginToSafeState(struct UserLogin* userLogin) {
    userLogin->userLoginName[0] = 0;
    userLogin->password[0] = 0;
}