/*Name-Yashkumar Vipulkumar Shah
  Student id-103985214
  Seneca email id-yvshah@myseneca.ca
  Section code-IPC144 NFF*/

#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_

#include"account.h"

void applicationStartup(struct Account accounts[], int size);
int menuLogin(const struct Account accounts[], int size);
void menuAgent(struct Account accounts[], int size, const struct Account* account);
int findAccountIndexByAcctNum(int accNoToFind, const struct Account accounts[], int size, int isPrompt);
void displayAllAccountDetailRecords(const struct Account accounts[], int size);
void pauseExecution(void);


void displayAccountDetailHeader();
void displayAccountDetailRecord(const struct Account* account);

int getModifyMenuActive();
void setModifyMenuActive(int val);
#endif