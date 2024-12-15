/************************************* 

PROJECT : BANKING MANAGEMENT SYSTEM 

***************************************/

#include <stdio.h>
#include <string.h>
#include "FunctionDefine.cpp"


int main() {
    int selected_function;

    while (1) {
        printf("\n Banking Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Inquiry\n");
        printf("5. Money Transfere\n");
        printf("6. Loan Process\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");
        printf("Select the required Function: ");
        scanf("%d", &selected_function);

        switch (selected_function) {
            case 1:
                account_creation();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                balance_inquiry();
                break;
            case 5:
				transfer();
				break;
            case 6:
            	loan();
            	break;
            case 7:
                account_deletion();
                break;
            case 8:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid selection. Please try again.\n");
        }
	}  
}

