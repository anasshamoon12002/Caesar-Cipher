#include <stdio.h>
#include <stdlib.h>

void encrypt();				// encrypt() function prototype

void decrypt();				// decrypt() function prototype


int main()					// Main function
{
    int choice;

    while (1)
    {
        printf("\nEnter an option number.\n");
        printf("1. Encrypt    2. Decrypt    3. Exit \n");
        scanf("%d", &choice);

        if(choice < 1 || choice > 3)
        {
            printf("\nEnter a valid option.\n");
        }
        else if (choice == 1)
        {
            encrypt();
        }
        else if (choice == 2)
        {
            decrypt();
        }
        else
        {
            break;
        }
    }

    getchar();

    return EXIT_SUCCESS;
}

void encrypt()				// encrypt() function definition
{
    int i;
    int temp, key;
    char message[60];
    char encrypted_msg[60];

    puts("Enter a string:");	// Inputs string from the user.
    getchar();
    gets(message);

    printf("\n");

    a:

    puts("Enter the key. ( 1 - 25) ");	// Takes key from the user.
    scanf("%d", &key);
    getchar();

    if (key < 1 || key > 25)
    {
        puts("\nEnter a valid key:\n");
        goto a;
    }

    printf("\n \nENCRYPTION PASS... \n \n");	// Encryption pass. Generates the encrypted message.

    for (i = 0; i < strlen(message); i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            temp = (int)message[i] + key;

            if (temp > 'Z')
            {
                temp = temp - 26;
            }

            encrypted_msg[i] = temp;

        }

        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            temp = (int)message[i] + key;

            if (temp > 'z')
            {
                temp = temp - 26;
            }

            encrypted_msg[i] = temp;

        }

        else
        {
            encrypted_msg[i] = message[i];
        }
    }

    encrypted_msg[i] = '\0';

    for (i = 0; i < strlen(encrypted_msg); i++)		// Prints the encrypted message.
    {
        printf("%c", encrypted_msg[i]);
    }

    printf("\n \n");
}

void decrypt()			// Decrypt() function definition.
{
    int i, key;
    char temp;
    char decrypted_msg[60];
    char encrypted_msg[60];


    puts("Enter a string:");	// Inputs string from the user.
    getchar();
    gets(encrypted_msg);

    printf("\n");

    a:

    puts("Enter the key. ( 1 - 25) ");	// Takes key from the user.
    scanf("%d", &key);

    if (key < 1 || key > 25)
    {
        puts("\nEnter a valid key:\n");
        goto a;
    }


    printf("DECRYPTION PASS... \n \n");			// Decryption pass. Decrypts the encrypted message.

    for (i = 0; i < strlen(encrypted_msg); i++)
    {
        if (encrypted_msg[i] >= 'A' && encrypted_msg[i] <= 'z')
        {

            if (encrypted_msg[i] >= 'a' && encrypted_msg[i] <= 'z')
            {
                temp = encrypted_msg[i] - key;

                if (temp < 'a')
                {
                    temp = temp + 26;
                }

                decrypted_msg[i] = temp;

            }
            else
            if (encrypted_msg[i] >= 'A' && encrypted_msg[i] <= 'Z')
            {
                temp = encrypted_msg[i] - key;

                if (temp < 'A')
                {
                    temp = temp + 26;
                }

                decrypted_msg[i] = temp;

            }

        }
        else
        {
            decrypted_msg[i] = encrypted_msg[i];
        }
    }

    decrypted_msg[i] = '\0';

    for (i = 0; i < strlen(decrypted_msg); i++)			// Prints the decrypted message.
    {
        printf("%c", decrypted_msg[i]);
    }

    printf("\n \n");
}
