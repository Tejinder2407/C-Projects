/*Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144-ZDD*/

#include"accountTicketingUI.h"
#include<stdio.h>
#include "account.h"
#include"commonHelpers.h"


int login_Index = -1;
int modifyMenuActive = 0; 
void applicationStartup(struct Account accounts[], int size) {
   
    while (1) {
        if (login_Index == -1) {
            login_Index = menuLogin(accounts, size);
        }
        else if (login_Index == -2) {
           
            printf("\n==============================================\n"
                "Account Ticketing System - Terminated\n"
                "==============================================\n");
            break;
        }
        else {
           
            printf("\n");
            menuAgent(accounts, size, &accounts[login_Index]);
        }
    }
}

int menuLogin(const struct Account accounts[], int size) {
    printf("==============================================\n"
        "Account Ticketing System - Login\n"
        "==============================================\n"
        "1) Login to the system\n"
        "0) Exit application\n"
        "----------------------------------------------\n");
    printf("\n");
    printf("Selection: ");
    int option = getIntFromRange(0, 1);
    printf("\n");
    if (option == 0) {
        printf("Are you sure you want to exit? ([Y]es|[N]o): ");
        char c = getCharOption("yYnN");
        if (c == 'y' || c == 'Y') {
            return -2;  // TODO : Change for exit value
            // exit
        }
        else if (c == 'n' || c == 'N') {
            printf("\n");
            return -1;
        }
    }
    else if (option == 1) { // login to system
        login_Index = findAccountIndexByAcctNum(0, accounts, size, 1);
        if (login_Index != -1) {
            if (accounts[login_Index].accountType == 'C') {
                printf("ERROR:  Login failed!\n");
                printf("\n");
                pauseExecution();
                return -1;
            }
            return login_Index;
        }
        else {
            printf("ERROR:  Login failed!\n");
            printf("\n");
            pauseExecution();
            return -1;
        }
    }
    return -1;
}
void menuAgent(struct Account accounts[], int size, const struct Account* account) {
    while (1) {
        printf("AGENT: %s (%d)", account->person.personName, account->accountNumber);
        printf("\n==============================================\n"
            "Account Ticketing System - Agent Menu\n"
            "==============================================\n"
            "1) Add a new account\n"
            "2) Modify an existing account\n"
            "3) Remove an account\n"
            "4) List accounts: detailed view\n"
            "----------------------------------------------\n"
            "0) Logout\n\n"
            "Selection: ");

        int option = getIntFromRange(0, 4);

        printf("\n");
        if (option == 1) {
            // add an account
            int emt_Index = 0;
            int is_Found = 0;
            for (emt_Index = 0; emt_Index < size; emt_Index++) {
                if (accounts[emt_Index].accountNumber == 0) {
                    is_Found = 1;
                    break;
                }
            }
            if (is_Found == 0) {
                printf("ERROR: Account listing is FULL, call ITS Support!");
            }
            else {
                getAccount(&accounts[emt_Index]);
                printf("*** New account added! ***\n");
                printf("\n");
                pauseExecution();
            }
        }
        else if (option == 2) {
           
            printf("Enter the account#: ");
            int accno = getPositiveInteger();
            int indexx = findAccountIndexByAcctNum(accno, accounts, size, 0);

            if (indexx != -1) {
                
                setModifyMenuActive(1);
                while (modifyMenuActive == 1) {
                    updateAccount(&accounts[indexx]);
                }
            }
            else {
                 
            }
        }
        else if (option == 3) {
            
            printf("Enter the account#: ");
            int accno = getPositiveInteger();

            if (account->accountNumber == accno) { 
                printf("\nERROR: You can't remove your own account!\n\n");
                pauseExecution();
            }
            else {
                int indexx = findAccountIndexByAcctNum(accno, accounts, size, 0);
                if (indexx != -1) {
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&accounts[indexx]);

                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    char YsNo = getCharOption("YynN");
                    if (YsNo == 'y' || YsNo == 'Y') {
                        
                        accounts[indexx].accountNumber = 0;
                        printf("\n*** Account Removed! ***\n\n");
                        pauseExecution();
                    }
                    else {
                      
                    }
                }
                else {
                    
                }
            }
        }
        else if (option == 4) {
           
            displayAllAccountDetailRecords(accounts, size);
            printf("\n");
            pauseExecution();
        }
        else if (option == 0) {
            
            login_Index = -1;
            printf("### LOGGED OUT ###\n\n");
            break;
        }
    }

}
int findAccountIndexByAcctNum(int accNoToFind, const struct Account accounts[], int size, int isPrompt) {
    if (isPrompt == 1) {
        printf("Enter your account#: ");
        int accno = getPositiveInteger();
        accNoToFind = accno;
    }

    int a = 0;
    int is_Found = 0;
    for (a = 0; a < size; a++) {
        if (accNoToFind == accounts[a].accountNumber) {
            is_Found = 1;
            break;
        }
    }

    if (is_Found == 1) {
        return ;
    }
    else {
        return -1;
    }
}
void displayAllAccountDetailRecords(const struct Account accounts[], int size) {
    displayAccountDetailHeader();
    int index = 0;
    for (index = 0; index < size; index++) {
        if (accounts[index].accountNumber != 0) {
            displayAccountDetailRecord(&accounts[index]);
        }
    }
}


void displayAccountDetailHeader() {
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}
void displayAccountDetailRecord(const struct Account* account) {
    printf("%05d ", account->accountNumber);
    (account->accountType == 'A') ? printf("%-9s ", "AGENT ") : printf("%-9s ", "CUSTOMER ");
    printf("%-15s ", account->person.personName);
    printf("%5d ", account->person.birthYear);
    printf("%11.2lf ", account->person.householdIncome);
    printf("%-10s ", account->person.country);

    if (account->userLogin.userLoginName[0] != 0) {
        printf("%-10s ", account->userLogin.userLoginName);
        int a = 0;
        for (a = 0; a < 8; a++) {
            if ((a + 1) % 2 == 0) {
                printf("*");
            }
            else {
                printf("%c", account->userLogin.password[a]);
            }
        }
    }
    else {
        printf("%-10s ", "");
        printf("%-8s", "");
    }

    printf("\n");
}


// Pause execution until user enters the enter key
void pauseExecution(void)
{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');
}

int getModifyMenuActive() {
    return modifyMenuActive;
}
void setModifyMenuActive(int val) {
    modifyMenuActive = val;
}