/*Name-Tejinder singh
  Student id-129121216
  Seneca email id- ktejinder-singh@myseneca.ca
  Section code-IPC144 ZDD*/

#ifndef COMMONHELPERS_H_
#define COMMONHELPERS_H_

int currentYear(void);
void clearStandardInputBuffer(void);

// helper functions 

int getInteger();
int getPositiveInteger();
double getDouble();
double getPositiveDouble();
int getIntFromRange(int lowerBound, int upperBound);
char getCharOption(char str[]);
void getCString(char* c, int lowerBound, int upperBound);

#endif