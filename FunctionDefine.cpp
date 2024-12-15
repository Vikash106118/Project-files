#include <stdio.h>
#include <string.h>
#include "Macros.cpp"
#include "FunctionDeclarations.cpp"

int accountNumbers[MAX_ACCOUNTS];
char names[MAX_ACCOUNTS][MAX_NAME_LENGTH];
float balances[MAX_ACCOUNTS];
int numAccounts = 0;

// loan process

void loan(){
	int accountNumber;
	int selection;
    printf("Enter Account Number for Loan: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            printf("Account Holder: %s\n", names[i]);
        	printf("\nLoan type\n");
        	printf("\n1. Personal loan\n2. Eductaion loan\nSelect the loan type: ");
        	scanf("%d", &selection);
        	switch(selection){
        		case 1:
        			Personal_loan();
        			break;
        		case 2:
        			Education_loan();
        			break;
        		default:
        			printf("Invalid selection. Please try again :)\n");
        			break;
			}
            return;
        }
    }
    
    printf("Invalid Account. Please check your account number");
}

void Personal_loan(){
	short int age;
	float salary;
	
	printf("Enter your age : ");
	scanf("%d", &age);
	
	if(age < 21){
		printf("Your not eligible for Loan ...!!!\n");
		return;
	}else{
		printf("Enter your salary per year : ");
		scanf("%f", &salary);
	}
}
void Education_loan(){
	
}


// Function to create a new account
void account_creation() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]%*c", names[numAccounts]);  

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &balances[numAccounts]);

    
    int min = 123456, max = 654321;
    accountNumbers[numAccounts] = rand() % (max - min + 1) + min;

    printf("Account created successfully!\n");
    printf("Your Account Number is : %d\n", accountNumbers[numAccounts]);
    numAccounts++;
}
void deposit() {
    int accountNumber;
    float amount;
    printf("Enter Account Number for Deposit: ");
    scanf("%d", &accountNumber);
   

    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
             printf("Account Holder: %s\n", names[i]);
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            balances[i] += amount;
            printf("Deposit successful. Updated balance: %.2f\n", balances[i]);
            return;
        }
    }
    printf("Account not found.\n");
}
void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter Account Number for Withdrawal: ");
    scanf("%d", &accountNumber);
for (int i = 0; i < numAccounts; i++) {
        
        if (accountNumbers[i] == accountNumber) {
            printf("Account Holder: %s\n", names[i]);
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (balances[i] >= amount) {
                balances[i] -= amount;
                printf("Withdrawal successful. Updated balance: %.2f\n", balances[i]);
            } else {
                printf("Insufficient funds.\n");
            }
            return;
             }
       }
    printf("Account not found.\n");
}
void balance_inquiry() {
    int accountNumber;
    printf("Enter Account Number for Balance Inquiry: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            printf("Account Holder: %s\n", names[i]);
            printf("Current Balance: %.2f\n", balances[i]);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to delete an account
void account_deletion() {
    int accountNumber;
    printf("Enter Account Number to Delete: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        
        if (accountNumbers[i] == accountNumber) {
             printf("Account Holder: %s\n", names[i]);
            for (int j = i; j < numAccounts - 1; j++) {
               
                accountNumbers[j] = accountNumbers[j + 1];
                strcpy(names[j], names[j + 1]);
                balances[j] = balances[j + 1];
            }
            numAccounts--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}
void transfer() {
    int senderAccount, receiverAccount;
    float amount;
    int senderIndex = -1, receiverIndex = -1;

    printf("Enter Sender's Account Number: ");
    scanf("%d", &senderAccount);
    printf("Enter Receiver's Account Number: ");
    scanf("%d", &receiverAccount);
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    
    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == senderAccount) {
            senderIndex = i;
        }
        if (accountNumbers[i] == receiverAccount) {
            receiverIndex = i;
        }
    }

    
    if (senderIndex == -1) {
        printf("Sender's account not found.\n");
    } else if (receiverIndex == -1) {
        printf("Receiver's account not found.\n");
    } else if (balances[senderIndex] < amount) {
        printf("Insufficient balance in sender's account.\n");
    } else {
       
        balances[senderIndex] -= amount;
        balances[receiverIndex] += amount;
        printf("Transfer successful! %.2f transferred from account %d to account %d.\n", amount, senderAccount, receiverAccount);
        printf("Updated balance for sender (Account %d): %.2f\n", senderAccount, balances[senderIndex]);
        printf("Updated balance for receiver (Account %d): %.2f\n", receiverAccount, balances[receiverIndex]);
    }
}