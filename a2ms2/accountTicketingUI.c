/*
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca 
	Section: ipc144-ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include "accountTicketingUI.h"
#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"
#include <string.h>

int login_INDEX = -1;
int modifyMenuActive = 0; 
int uni_Acc_Num = 0;

void applicationStartup(struct AccountTicketingData* accountTicketingData)
{
    while (1)
    {
        if (login_INDEX == -1)
        { 
            login_INDEX = menuLogin(accountTicketingData->accounts, accountTicketingData->ACCOUNT_MAX_SIZE);
        }
        else if (login_INDEX == -2)
        {
            printf("\n==============================================\n"
                "Account Ticketing System - Terminated\n"
                "==============================================\n");
            break;
        }
        else
        {
            printf("\n");
            menuAgent(accountTicketingData, &accountTicketingData->accounts[login_INDEX]);
        }
    }
}

int menuLogin(const struct Account accounts[], int size)
{
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
    if (option == 0)
    {
        printf("Are you sure you want to exit? ([Y]es|[N]o): ");
        char c = getCharOption("yYnN");
        if (c == 'y' || c == 'Y')
        {
            return -2; 
          
        }
        else if (c == 'n' || c == 'N')
        {
            printf("\n");
            return -1;
        }
    }
    else if (option == 1)
    {                        
        int chancesLFT = 3;
        while (1)
        {
            int login_Index = CheckLoginCredentials(accounts, size);
            if (login_Index != -1)
            {
                login_INDEX = login_Index;
                return login_INDEX;
            }
            else
            {
                printf("INVALID user login/password combination! [attempts remaining:%d]\n", --chancesLFT);
                printf("\n");
            }
            if (chancesLFT <= 0)
            {
               
                printf("ERROR:  Access Denied.\n");
                printf("\n");
                pauseExecution();
                return -1;
                break;
            }
        }
    }
    return -1;
}
void menuAgent(struct AccountTicketingData* accountTicketingData, const struct Account* account)
{
    while (1)
    {
        printf("AGENT: %s (%d)", account->person.personName, account->accountNumber);
        printf("\n==============================================\n"
            "Account Ticketing System - Agent Menu\n"
            "==============================================\n"
            "1) Add a new account\n"
            "2) Modify an existing account\n"
            "3) Remove an account\n"
            "4) List accounts: detailed view\n"
            "----------------------------------------------\n"
            "5) List new tickets\n"
            "6) List active tickets\n"
            "7) List closed tickets\n"
            "8) Add a new ticket\n"
            "9) Manage a ticket\n"
            "----------------------------------------------\n"
            "0) Logout\n\n"
            "Selection: ");

        int option = getIntFromRange(0, 9);

        printf("\n");
        if (option == 1)
        {
            
            int emt_Index = 0;
            int isFound = 0;
            for (emt_Index = 0; emt_Index < accountTicketingData->ACCOUNT_MAX_SIZE; emt_Index++)
            {
                if (accountTicketingData->accounts[emt_Index].accountNumber == 0)
                {
                    isFound = 1;
                    break;
                }
            }
            if (isFound == 0)
            {
                printf("ERROR: Account listing is FULL, call ITS Support!\n\n");
                pauseExecution();
            }
            else
            {
                UpdateUniqueAccountNumber(accountTicketingData->accounts, accountTicketingData->ACCOUNT_MAX_SIZE);
                getAccount(&accountTicketingData->accounts[emt_Index]);
                printf("*** New account added! ***\n");
                printf("\n");
                pauseExecution();
            }
        }
        else if (option == 2)
        {
            printf("Enter the account#: ");
            int accno = getPositiveInteger();
            int indexx = findAccountIndexByAcctNum(accno, accountTicketingData->accounts, accountTicketingData->ACCOUNT_MAX_SIZE, 0);

            if (indexx != -1)
            {
                
                setModifyMenuActive(1);
                while (modifyMenuActive == 1)
                {
                    updateAccount(&accountTicketingData->accounts[indexx]);
                }
            }
            else
            {
                
            }
        }
        else if (option == 3)
        {
           
            printf("Enter the account#: ");
            int accno = getPositiveInteger();

            if (account->accountNumber == accno)
            { 
                printf("\nERROR: You can't remove your own account!\n\n");
                pauseExecution();
            }
            else
            {
                int indexx = findAccountIndexByAcctNum(accno, accountTicketingData->accounts, accountTicketingData->ACCOUNT_MAX_SIZE, 0);
                if (indexx != -1)
                {
                    printf("\n");
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&accountTicketingData->accounts[indexx]);

                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    char YsNo = getCharOption("YynN");
                    if (YsNo == 'y' || YsNo == 'Y')
                    {

                        
                        int a = 0;
                        int ticketRemovedCounter = 0;
                        for (a = 0; a < accountTicketingData->TICKET_MAX_SIZE; a++)
                        {
                            if (accountTicketingData->tickets[a].customerAccountNumber == accountTicketingData->accounts[indexx].accountNumber)
                            {
                                accountTicketingData->tickets[a].customerAccountNumber = 0; 
                                ticketRemovedCounter++;
                                
                            }
                        }
                        a = 0;
                        
                        accountTicketingData->accounts[indexx].accountNumber = 0;
                        
                        printf("\n*** Account Removed! (%d ticket(s) removed) ***\n\n", ticketRemovedCounter);
                        pauseExecution();
                    }
                    else
                    {
                        
                    }
                }
                else
                {
                   
                }
            }
        }
        else if (option == 4)
        {
            
            displayAllAccountDetailRecords(accountTicketingData->accounts, accountTicketingData->ACCOUNT_MAX_SIZE);
            printf("\n");
            pauseExecution();
        }
       
        else if (option == 5)
        {
           
            ListNewTickets(accountTicketingData);
        }
        else if (option == 6)
        {
           
            ListActiveTickets(accountTicketingData);
        }
        else if (option == 7)
        {
          
            ListClosedTickets(accountTicketingData);
        }
        else if (option == 8)
        {
            
            AddNewTicket(accountTicketingData);
        }
        else if (option == 9)
        {
            
            ManageTicket(accountTicketingData);
        }
        else if (option == 0)
        {
            
            login_INDEX = -1;
            printf("### LOGGED OUT ###\n\n");
            break;
        }
    }
}
int findAccountIndexByAcctNum(int accNoToFind, const struct Account accounts[], int size, int isPrompt)
{
    if (isPrompt == 1)
    {
        printf("Enter your account#: ");
        int acc_no = getPositiveInteger();
        accNoToFind = acc_no;
    }

    int a = 0;
    int is_Found = 0;
    for (a = 0; a < size; a++)
    {
        if (accNoToFind == accounts[a].accountNumber)
        {
            is_Found = 1;
            break;
        }
    }

    if (is_Found == 1)
    {
        return a;
    }
    else
    {
        return -1;
    }
}
int CheckLoginCredentials(const struct Account accounts[], int size)
{
    printf("Enter the account#: ");
    int acc_No = getPositiveInteger();
    printf("User Login        : ");
    char ul[32];
    getCString(ul, 1, 30);
    printf("Password          : ");
    char p[10];
    getPassword(p);
    int index = findAccountIndexByAcctNum(acc_No, accounts, size, 0);
    if (index != -1)
    {
        int credok = 1;
        if (strcmp(accounts[index].userLogin.userLoginName, ul) != 0)
        {
            credok = -1;
        }
        if (strcmp(accounts[index].userLogin.password, p) != 0)
        {
            credok = -1;
        }
        if (credok == 1)
        {
            return index;
        }
        else if (credok == -1)
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
    return -1;
}
void displayAllAccountDetailRecords(const struct Account accounts[], int size)
{
    displayAccountDetailHeader();
    int index = 0;
    for (index = 0; index < size; index++)
    {
        if (accounts[index].accountNumber != 0)
        {
            displayAccountDetailRecord(&accounts[index]);
        }
    }
}

//////
void displayAccountDetailHeader()
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}
void displayAccountDetailRecord(const struct Account* account)
{
    printf("%05d ", account->accountNumber);
    (account->accountType == 'A') ? printf("%-9s ", "AGENT ") : printf("%-9s ", "CUSTOMER ");
    printf("%-15s ", account->person.personName);
    printf("%5d ", account->person.birthYear);
    printf("%11.2lf ", account->person.householdIncome);
    printf("%-10s ", account->person.country);

    if (account->userLogin.userLoginName[0] != 0)
    {
        printf("%-10s ", account->userLogin.userLoginName);
        int a = 0;
        for (a = 0; a < 8; a++)
        {
            if ((a + 1) % 2 == 0)
            {
                printf("*");
            }
            else
            {
                printf("%c", account->userLogin.password[a]);
            }
        }
    }
    else
    {
        printf("%-10s ", "");
        printf("%-8s", "");
    }

    printf("\n");
}

void pauseExecution(void)
{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');
}

int getModifyMenuActive()
{
    return modifyMenuActive;
}
void setModifyMenuActive(int val)
{
    modifyMenuActive = val;
}

int getUniqueAccountNumber()
{
    return uni_Acc_Num;
}
void UpdateUniqueAccountNumber(const struct Account accounts[], int size)
{
   
    int a, larg_Acc_Num = -1;
    for (a = 0; a < size; a++)
    {
        int INT = accounts[a].accountNumber;
        if (INT > larg_Acc_Num)
        {
            larg_Acc_Num = INT;
        }
    }
    uni_Acc_Num = larg_Acc_Num + 1;
}

int getLoginindex()
{
    return login_INDEX;
}


void ListNewTickets(struct AccountTicketingData* accountTicketingData)
{
    while (1)
    {
        ListTicketHeader();
        int a = 0;
        int lstd_Tkts[50] = { 0 };
        int lstd_TktCounter = 0;

        for (a = 0; a < accountTicketingData->TICKET_MAX_SIZE; a++)
        {
            if (accountTicketingData->tickets[a].ticketStatus == 1 && accountTicketingData->tickets[a].customerAccountNumber != 0)
            {
                
                if (accountTicketingData->tickets[a].messageCounter == 1)
                {
                 
                    lstd_Tkts[lstd_TktCounter] = accountTicketingData->tickets[a].uniqueNumber;
                    lstd_TktCounter++;

                    printf("%06d ", accountTicketingData->tickets[a].uniqueNumber);
                    printf("%05d ", accountTicketingData->tickets[a].customerAccountNumber);
                    int b = 0;
                    int indx = -1;
                    for (b = 0; b < accountTicketingData->ACCOUNT_MAX_SIZE; b++)
                    {
                        if (accountTicketingData->accounts[b].accountNumber == accountTicketingData->tickets[a].customerAccountNumber)
                        {
                            indx = b;
                            break;
                        }
                    }
                    printf("%-15s ", accountTicketingData->accounts[indx].person.personName);
                    if (accountTicketingData->tickets[a].ticketStatus == 1)
                    {
                        printf("ACTIVE ");
                    }
                    else
                    {
                        printf("CLOSED ");
                    }
                    printf("%-30s ", accountTicketingData->tickets[a].subjectLine);
                    printf("    %d\n", accountTicketingData->tickets[a].messageCounter);
                }
            }
        }
        ListTicketFooter();
        printf("\nEnter the ticket number to view the messages or\n"
            "0 to return to previous menu: ");
        int INT_Ticket_Num = getInteger();
        if (INT_Ticket_Num == 0)
        {
            
            printf("\n");
            break;
        }
      
        a = 0;
        int exist = 0;
        for (a = 0; a < lstd_TktCounter; a++)
        {
            if (lstd_Tkts[a] == INT_Ticket_Num)
            {
                exist = 1;
                break;
            }
        }
        
        int lstd_Tkt_Index = FindTicketIndex(INT_Ticket_Num, accountTicketingData->tickets, accountTicketingData->TICKET_MAX_SIZE);

        if (exist == 1)
        { 
            printf("\n");
            struct Ticket INT_Ticket = accountTicketingData->tickets[lstd_Tkt_Index];
            ListMessageHeader(INT_Ticket);
            a = 0;
            for (a = 0; a < INT_Ticket.messageCounter; a++)
            {
                INT_Ticket.messages[a].authorAccountType == 'C' ? printf("CUSTOMER ") : printf("AGENT ");
                printf("(%s):\n", INT_Ticket.messages[a].authorAcountName);
                printf("   %s\n\n", INT_Ticket.messages[a].message);
            }
            pauseExecution();
        }
        else
        {
           
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
            printf("\n");
        }
    }
}
void ListActiveTickets(struct AccountTicketingData* accountTicketingData)
{
    while (1)
    {
        ListTicketHeader();
        int i = 0;
        int listed_Tickets[50] = { 0 };
        int listed_Ticket_Counter = 0;

        for (i = 0; i < accountTicketingData->TICKET_MAX_SIZE; i++)
        {
            if (accountTicketingData->tickets[i].ticketStatus == 1 && accountTicketingData->tickets[i].customerAccountNumber != 0)
            {
                // ticket is open
                listed_Tickets[listed_Ticket_Counter] = accountTicketingData->tickets[i].uniqueNumber;
                listed_Ticket_Counter++;

                printf("%06d ", accountTicketingData->tickets[i].uniqueNumber);
                printf("%05d ", accountTicketingData->tickets[i].customerAccountNumber);
                int j = 0;
                int indx = -1;
                for (j = 0; j < accountTicketingData->ACCOUNT_MAX_SIZE; j++)
                {
                    if (accountTicketingData->accounts[j].accountNumber == accountTicketingData->tickets[i].customerAccountNumber)
                    {
                        indx = j;
                        break;
                    }
                }
                printf("%-15s ", accountTicketingData->accounts[indx].person.personName);
                if (accountTicketingData->tickets[i].ticketStatus == 1)
                {
                    printf("ACTIVE ");
                }
                else
                {
                    printf("CLOSED ");
                }
                printf("%-30s ", accountTicketingData->tickets[i].subjectLine);
                printf("    %d\n", accountTicketingData->tickets[i].messageCounter);
            }
        }
        ListTicketFooter();
        printf("\nEnter the ticket number to view the messages or\n"
            "0 to return to previous menu: ");
        int INT_TicketNumber = getInteger();
        if (INT_TicketNumber == 0)
        {
            
            printf("\n");
            break;
        }
       
        i = 0;
        int exist = 0;
        for (i = 0; i < listed_Ticket_Counter; i++)
        {
            if (listed_Tickets[i] == INT_TicketNumber)
            {
                exist = 1;
                break;
            }
        }
        
        int listedTicketIndex = FindTicketIndex(INT_TicketNumber, accountTicketingData->tickets, accountTicketingData->TICKET_MAX_SIZE);

        if (exist == 1)
        {             
            printf("\n");
            struct Ticket tempTicket = accountTicketingData->tickets[listedTicketIndex];
            ListMessageHeader(tempTicket);
            i = 0;
            for (i = 0; i < tempTicket.messageCounter; i++)
            {
                tempTicket.messages[i].authorAccountType == 'C' ? printf("CUSTOMER ") : printf("AGENT ");
                printf("(%s):\n", tempTicket.messages[i].authorAcountName);
                printf("   %s\n\n", tempTicket.messages[i].message);
            }
            pauseExecution();
        }
        else
        {
           
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
            printf("\n");
        }
    }
}
void ListClosedTickets(struct AccountTicketingData* accountTicketingData)
{
    while (1)
    {
        ListTicketHeader();
        int i = 0;
        int lstd_Tickets[50] = { 0 };
        int lstd_TicketCounter = 0;

        for (i = 0; i < accountTicketingData->TICKET_MAX_SIZE; i++)
        {
            if (accountTicketingData->tickets[i].ticketStatus == 0 && accountTicketingData->tickets[i].customerAccountNumber != 0)
            {
                // ticket is open
                lstd_Tickets[lstd_TicketCounter] = accountTicketingData->tickets[i].uniqueNumber;
                lstd_TicketCounter++;

                printf("%06d ", accountTicketingData->tickets[i].uniqueNumber);
                printf("%05d ", accountTicketingData->tickets[i].customerAccountNumber);
                int j = 0;
                int IndX = -1;
                for (j = 0; j < accountTicketingData->ACCOUNT_MAX_SIZE; j++)
                {
                    if (accountTicketingData->accounts[j].accountNumber == accountTicketingData->tickets[i].customerAccountNumber)
                    {
                        IndX = j;
                        break;
                    }
                }
                printf("%-15s ", accountTicketingData->accounts[IndX].person.personName);
                if (accountTicketingData->tickets[i].ticketStatus == 1)
                {
                    printf("ACTIVE ");
                }
                else
                {
                    printf("CLOSED ");
                }
                printf("%-30s ", accountTicketingData->tickets[i].subjectLine);
                printf("    %d\n", accountTicketingData->tickets[i].messageCounter);
            }
        }
        ListTicketFooter();
        printf("\nEnter the ticket number to view the messages or\n"
            "0 to return to previous menu: ");
        int INT_TicketNumber = getInteger();
        if (INT_TicketNumber == 0)
        {
            
            printf("\n");
            break;
        }
        
        i = 0;
        int exist = 0;
        for (i = 0; i < lstd_TicketCounter; i++)
        {
            if (lstd_Tickets[i] == INT_TicketNumber)
            {
                exist = 1;
                break;
            }
        }
       
        int lstd_TicketIndex = FindTicketIndex(INT_TicketNumber, accountTicketingData->tickets, accountTicketingData->TICKET_MAX_SIZE);

        if (exist == 1)
        { 
            printf("\n");
            struct Ticket INT_Ticket = accountTicketingData->tickets[lstd_TicketIndex];
            ListMessageHeader(INT_Ticket);
            i = 0;
            for (i = 0; i < INT_Ticket.messageCounter; i++)
            {
                INT_Ticket.messages[i].authorAccountType == 'C' ? printf("CUSTOMER ") : printf("AGENT ");
                printf("(%s):\n", INT_Ticket.messages[i].authorAcountName);
                printf("   %s\n\n", INT_Ticket.messages[i].message);
            }
            pauseExecution();
        }
        else
        {
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
        }
    }
}
void AddNewTicket(struct AccountTicketingData* accountTicketingData)
{
    printf("Enter the account#: ");
    int accNo = getPositiveInteger();
    int index = findAccountIndexByAcctNum(accNo, accountTicketingData->accounts, accountTicketingData->ACCOUNT_MAX_SIZE, 0);
    if (index == -1)
    {
        printf("ERROR:  ACCOUNT NOT FOUND\n");
        
    }
    else
    {
        if (accountTicketingData->accounts[index].accountType == 'A')
        {
            printf("\nERROR: Agent accounts can't have tickets!\n\n");
            pauseExecution();
        }
        else
        {
            printf("\n");
            displayAccountDetailHeader();
            displayAccountDetailRecord(&accountTicketingData->accounts[index]);
            printf("\nAdd a new ticket for this customer? ([Y]es|[N]o): ");
            char INTC = getCharOption("YynN");
            if (INTC == 'y' || INTC == 'Y')
            {
                int i = 0;
                int emt_Tkt_Index = -1;
                for (i = 0; i < accountTicketingData->TICKET_MAX_SIZE; i++)
                {
                    if (accountTicketingData->tickets[i].uniqueNumber == 0)
                    {
                        emt_Tkt_Index = i;
                        break;
                    }
                }
                if (emt_Tkt_Index != -1)
                {
                    accountTicketingData->tickets[emt_Tkt_Index].ticketStatus = 1;
                    accountTicketingData->tickets[emt_Tkt_Index].customerAccountNumber = accNo;
                    accountTicketingData->tickets[emt_Tkt_Index].uniqueNumber = LatestTicketNumber(accountTicketingData->tickets, accountTicketingData->TICKET_MAX_SIZE);

                    printf("\nNew Ticket (Ticket#:%06d)\n"
                        "----------------------------------------\n",
                        accountTicketingData->tickets[emt_Tkt_Index].uniqueNumber);
                    printf("Enter the ticket SUBJECT (30 chars. maximum): ");
                    getCString(accountTicketingData->tickets[emt_Tkt_Index].subjectLine, 1, 30);
                    printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                    getCString(accountTicketingData->tickets[emt_Tkt_Index].messages[accountTicketingData->tickets[emt_Tkt_Index].messageCounter].message, 1, 150);
                    accountTicketingData->tickets[emt_Tkt_Index].messages[accountTicketingData->tickets[emt_Tkt_Index].messageCounter].authorAccountType = 'C';
                    strcpy(accountTicketingData->tickets[emt_Tkt_Index].messages[accountTicketingData->tickets[emt_Tkt_Index].messageCounter].authorAcountName, accountTicketingData->accounts[index].person.personName);
                    accountTicketingData->tickets[emt_Tkt_Index].messageCounter++;

                    printf("\n*** New ticket created! ***\n");
                    printf("\n");
                    pauseExecution();
                }
                else
                {
                    printf("ERROR:  Ticket listing is FULL, call ITS Support!\n");
                }
            }
            else
            {
                
            }
        }
    }
}
void ManageTicket(struct AccountTicketingData* accountTicketingData)
{
    while (1)
    {
        printf("Enter ticket number: ");
        int tktNumber = getPositiveInteger();
        int tktIndex = FindTicketIndex(tktNumber, accountTicketingData->tickets, accountTicketingData->TICKET_MAX_SIZE);
        if (tktIndex != -1)
        {
            while (1)
            {
                
                printf("\n----------------------------------------\n"
                    "Ticket %06d - Update Options\n"
                    "----------------------------------------\n",
                    tktNumber);
                printf("Status  : %s\n", accountTicketingData->tickets[tktIndex].ticketStatus == 1 ? "ACTIVE" : "CLOSED");
                printf("Subject : %s\n", accountTicketingData->tickets[tktIndex].subjectLine);
                printf("Acct#   : %d\n", accountTicketingData->tickets[tktIndex].customerAccountNumber);
                printf("Customer: %s\n", accountTicketingData->tickets[tktIndex].messages[0].authorAcountName);
                printf("----------------------------------------\n");
                printf("1) Add CUSTOMER message\n"
                    "2) Add AGENT message\n"
                    "3) Close ticket\n"
                    "4) Re-activate ticket\n"
                    "0) Done\n");
                printf("Selection: ");
                int option = getIntFromRange(0, 4);
               
                if (option == 1)
                {
                    if (accountTicketingData->tickets[tktIndex].ticketStatus == 0)
                    {
                        printf("ERROR: Ticket is closed - new messages are not permitted.\n");
                    }
                    else if (accountTicketingData->tickets[tktIndex].messageCounter >= 20)
                    {
                        printf("ERROR:  Message limit has been reached, call ITS Support!\n");
                    }
                    else
                    {
                        printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                        getCString(accountTicketingData->tickets[tktIndex].messages[accountTicketingData->tickets[tktIndex].messageCounter].message, 1, 150);
                        accountTicketingData->tickets[tktIndex].messages[accountTicketingData->tickets[tktIndex].messageCounter].authorAccountType = 'C';
                        strcpy(accountTicketingData->tickets[tktIndex].messages[accountTicketingData->tickets[tktIndex].messageCounter].authorAcountName, accountTicketingData->tickets[tktIndex].messages[0].authorAcountName);
                        accountTicketingData->tickets[tktIndex].messageCounter++;
                    }
                }
                else if (option == 2)
                {
                   
                    if (accountTicketingData->tickets[tktIndex].ticketStatus == 0)
                    {
                       
                        printf("ERROR: Ticket is closed - new messages are not permitted.\n");
                    }
                    else if (accountTicketingData->tickets[tktIndex].messageCounter >= 20)
                    {
                     
                        printf("ERROR:  Message limit has been reached, call ITS Support!\n");
                    }
                    else
                    {
                        printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                        getCString(accountTicketingData->tickets[tktIndex].messages[accountTicketingData->tickets[tktIndex].messageCounter].message, 1, 150);
                        accountTicketingData->tickets[tktIndex].messages[accountTicketingData->tickets[tktIndex].messageCounter].authorAccountType = 'A';
                        strcpy(accountTicketingData->tickets[tktIndex].messages[accountTicketingData->tickets[tktIndex].messageCounter].authorAcountName, accountTicketingData->accounts[getLoginindex()].person.personName);
                        accountTicketingData->tickets[tktIndex].messageCounter++;
                    }
                }
                else if (option == 3)
                {
                 
                    if (accountTicketingData->tickets[tktIndex].ticketStatus == 0)
                    {
                        printf("\nERROR: Ticket is already closed!\n");
                    }
                    else
                    {
                        printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                        char choice = getCharOption("YyNn");
                        if (choice == 'y' || choice == 'Y') {
                            accountTicketingData->tickets[tktIndex].ticketStatus = 0;
                            printf("\n");
                            printf("*** Ticket closed! ***\n");
                        }
                    }
                }
                else if (option == 4)
                {
                    
                    if (accountTicketingData->tickets[tktIndex].ticketStatus == 1)
                    {
                        printf("\nERROR: Ticket is already active!\n");
                    }
                    else
                    {
                        printf("\nAre you sure you want to RE-ACTIVATE this closed ticket? ([Y]es|[N]o): ");
                        char choice = getCharOption("YyNn");
                        if (choice == 'y' || choice == 'Y') {
                            accountTicketingData->tickets[tktIndex].ticketStatus = 1;
                            printf("\n");
                            printf("*** Ticket re-activated! ***\n");
                        }
                    }
                }
                else if (option == 0)
                {
                    printf("\n");
                    return;
                }
            }
        }
        else
        {
            printf("ERROR: Invalid ticket number.\n\n");
            break;
        }
    }
}

void ListTicketHeader()
{
    printf("------ ----- --------------- ------ ------------------------------ --------\n"
        "Ticket Acct# Full Name       Status Subject                        Messages\n"
        "------ ----- --------------- ------ ------------------------------ --------\n");
}

void ListTicketFooter()
{
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
}

void ListMessageHeader(struct Ticket ticket)
{
    printf("================================================================================\n"
        "%06d (%s) Re: %s\n"
        "================================================================================\n",
        ticket.uniqueNumber,
        (ticket.ticketStatus == 1) ? "ACTIVE" : "CLOSED",
        ticket.subjectLine);
}

int FindTicketIndex(int ticketNumber, struct Ticket tickets[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (tickets[i].uniqueNumber == ticketNumber)
        {
            return i;
            break;
        }
    }
    return -1;
}

int LatestTicketNumber(struct Ticket tickets[], int size)
{
    int greatst_Tkt_Num = -1;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (tickets[i].uniqueNumber > greatst_Tkt_Num)
            greatst_Tkt_Num = tickets[i].uniqueNumber;
    }
    return 70534;
}
