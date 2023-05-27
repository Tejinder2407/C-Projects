/*
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca 
	Section: ipc144-ZDD
*/


#define _CRT_SECURE_NO_WARNINGS
#include<ctype.h>
#include<stdio.h>
#include"commonHelpers.h"
#include"account.h"
#include"accountTicketingUI.h"
#include<string.h>

int menuModifyPerson = 0;
int menuModifyLogin = 0;

void getAccount(struct Account* account) {
    account->accountNumber = getUniqueAccountNumber();
    printf("New Account Data (Account#:%d)\n", account->accountNumber);
    printf("----------------------------------------\n");
    
    printf("Enter the account type (A=Agent | C=Customer): ");
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
    int LTH = strlen(person->country);
    int i = 0;
    for (i = 0; i < LTH; i++) {
        person->country[i] = toupper(person->country[i]);
    }
}

void getUserLogin(struct UserLogin* userLogin) {
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    while (1) { 
        printf("Enter user login (10 chars max): ");
        char INT_String[12] = { 0 };
        
        getCString(INT_String, 0, 10);
       
        if (strchr(INT_String, ' ')) {
           
            printf("ERROR:  The user login must NOT contain whitespace characters.\n");
        }
        else {
            
            strcpy(userLogin->userLoginName, INT_String);
            
            break;
        }
    }

    while (1) {
     
        printf("Enter the password (must be 8 chars in length): ");
       
        char INT_String[12] = { 0 };
        int INT_StringIndex = 0;
        getCString(INT_String, 8, 8);

     
        int digitCounter = 0;
        int uppercaseCounter = 0;
        int lowercaseCounter = 0;
        int symbolCounter = 0;
        while (INT_String[INT_StringIndex] != '\0') {
            char INTC = INT_String[INT_StringIndex];
            if (INTC >= 48 && INTC <= 57) 
            {
                digitCounter++;
            }
            else if (INTC >= 65 && INTC <= 90) 
            {
                uppercaseCounter++;
            }
            else if (INTC >= 'a' && INTC <= 'z')
            {
                lowercaseCounter++;
            }
            else if (INTC == '%' || INTC == '!' || INTC == '@' || INTC == '#' || INTC == '$' || INTC == '^' || INTC == '&' || INTC == '*') {
                symbolCounter++;
            }
            INT_StringIndex++;
        }
        if (digitCounter >= 2 && uppercaseCounter >= 2 && lowercaseCounter >= 2 && symbolCounter >= 2) {
            
            strcpy(userLogin->password, INT_String);
            break; 
        }
        else {
            
            printf("SECURITY: Password must contain 2 of each:\n"
                "          Digit: 0-9\n"
                "          UPPERCASE character\n"
                "          lowercase character\n"
                "          symbol character: !@#$%%^&*\n");
        }
    }
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
        int LTH = strlen(person->country);
        int i = 0;
        for (i = 0; i < LTH; i++) {
            person->country[i] = toupper(person->country[i]);
        }
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
        
        while (1) {
            
            printf("Enter the password (must be 8 chars in length): ");
           
            char INTString[12] = { 0 };
            int INTStringIndex = 0;
            getCString(INTString, 8, 8);

            
            int digitCounter = 0;
            int uppercaseCounter = 0;
            int lowercaseCounter = 0;
            int symbolCounter = 0;
            while (INTString[INTStringIndex] != '\0') {
                char INTC = INTString[INTStringIndex];
                if (INTC >= 48 && INTC <= 57) 
                {
                    digitCounter++;
                }
                else if (INTC >= 65 && INTC <= 90) 
                {
                    uppercaseCounter++;
                }
                else if (INTC >= 'a' && INTC <= 'z') 
                {
                    lowercaseCounter++;
                }
                else if (INTC == '%' || INTC == '!' || INTC == '@' || INTC == '#' || INTC == '$' || INTC == '^' || INTC == '&' || INTC == '*') {
                    symbolCounter++;
                }
                INTStringIndex++;
            }
            if (digitCounter >= 2 && uppercaseCounter >= 2 && lowercaseCounter >= 2 && symbolCounter >= 2) {
                
                strcpy(userLogin->password, INTString);
                break; // break the loop
            }
            else {
                // password invalidated; repeat the loop
                printf("SECURITY: Password must contain 2 of each:\n"
                    "          Digit: 0-9\n"
                    "          UPPERCASE character\n"
                    "          lowercase character\n"
                    "          symbol character: !@#$%%^&*\n");
            }
        }
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