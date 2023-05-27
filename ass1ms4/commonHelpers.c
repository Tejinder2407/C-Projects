/*Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144-ZDD*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"commonHelpers.h"

int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}


void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; 
    }
}

int getInteger() {
    while (1) {
        int temp_Int;
        char temp_Char = 'x';
        scanf("%d%c", &temp_Int, &temp_Char);

  
        if (temp_Char != '\n') {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
        else {
            return temp_Int;
        }
    }
}

int getPositiveInteger()
{
    while (1) {
        int temp_Int;
        char temp_Char = 'x';
        
        scanf("%d%c", &temp_Int, &temp_Char);

        if (temp_Char != '\n') {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
        else {
            if (temp_Int > 0) {
                return temp_Int;
            }
            else {
                printf("ERROR: Value must be a positive integer greater than zero: ");
            
            }
        }
    }
}


int getIntFromRange(int lowerBound, int upperBound) {
    while (1) {
        int tempInt;
        char tempChar = 'x';
       
        scanf("%d%c", &tempInt, &tempChar);

    
        if (tempChar != '\n') {
            clearStandardInputBuffer();
           
            printf("ERROR: Value must be an integer: ");
        }
        else {
            if (tempInt >= lowerBound && tempInt <= upperBound) {
                return tempInt;
            }
            else {
            
                printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            }
        }
    }
}

double getDouble() {
    while (1) {
        double tempDouble;
        char tempChar = 'x';
        
        scanf("%lf%c", &tempDouble, &tempChar);

       
        if (tempChar != '\n') {
            clearStandardInputBuffer();
         
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else {
            return tempDouble;
        }
    }
}

double getPositiveDouble() {
    while (1) {
        double temp_Double;
        char temp_Char = 'x';
      
        scanf("%lf%c", &temp_Double, &temp_Char);

     
        if (temp_Char != '\n') {
            clearStandardInputBuffer();
       
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else {
        
            if (temp_Double > 0) {
                return temp_Double;
            }
            else {
          
                printf("ERROR: Value must be a positive double floating-point number: ");
            }
        }
    }
}


char getCharOption(char str[]) {
    while (1) {
        char c;
        char temp_Char;

       
        scanf("%c%c", &c, &temp_Char);
       
        int is_Matched = 0;
        int a = 0;

        if (temp_Char == '\n') {
            while (1) {
                if (str[a] == '\0') break;

                if (str[a] == c) {
                    is_Matched = 1;
                    break;
                }
                a++;
            }
        }
        else {
            clearStandardInputBuffer();
        }
        if (is_Matched == 0) {
             
            printf("ERROR: Character must be one of [%s]: ", str);
        }
        else if (is_Matched == 1) {
          
            return c;
        }
    }
    clearStandardInputBuffer();
}

void getCString(char* c, int lowerBound, int upperBound) {
    while (1) {
        char str[1000];
       
        scanf("%[^\n]s", str);

        int A = 0;
        while (str[A] != '\0') {
            A++;
        }
        if (A >= lowerBound && A <= upperBound) {
         
            int B = 0;
            for (B = 0; B < A; B++) {
                c[B] = str[B];
            }
            int C = 0;
         
            while (1) {
                if (C >= A) {
                    if (C <= upperBound) {
                        c[C] = '\0';
                    }
                }
                if (C > upperBound) {
                    break;
                }
                C++;
            }
            clearStandardInputBuffer();
            break;
        }
        else {
           
            if (lowerBound == upperBound) {
                printf("ERROR: String length must be exactly %d chars: ", upperBound);
            }
            else if (A > upperBound) {
                printf("ERROR: String length must be no more than %d chars: ", upperBound);
            }
            else {
                printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
            }
            clearStandardInputBuffer();
        }
    }
}