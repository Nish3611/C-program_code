// C program to encrypt and decrypt the message.
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encryption(char* message, int shift) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] != ' ') { // this condition preserve spaces
            message[i] = message[i] + shift;
        }
    }
}

// Function to decrypt the message
void decryption(char* message, int shift) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] != ' ') { // this condition preserve spaces
            message[i] = message[i] + (-shift);
        }
    }
}
//Function for the choice between encrypt and decrypt
void make_choice(char* message, int shift) {
    char choice;
    while(1)
    {
        printf("Enter e for encrypt and d for decrypt: ");
        scanf(" %c",&choice);
        if(choice == 'e' || choice == 'd')
        break;
        printf("Invalid input\n");
    }
    if (choice == 'e'){
        encryption(message, shift);
        printf("Encrypted message is: %s\n",message);
    }
    else if (choice == 'd') {

        decryption(message,shift);
        printf("Decrypted message is: %s\n",message);
    }
}

int main() { //main function
    char message[100];
    int shift;
    char choice;

    printf("Welcome to the message encryption and decryption tool\n");
    printf("Enter a message: ");
    gets(message);

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    while(shift<1 || shift>25)
    {
        printf("Invalid shift value\nEnter shift value again within the range: ");
        scanf("%d",&shift);
    }

    make_choice(message,shift);

    return 0;
}

