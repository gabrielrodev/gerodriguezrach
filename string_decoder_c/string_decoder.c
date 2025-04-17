#define _CRT_SECURE_NO_WARNINGS // Needed for Visual Studio
#include <stdio.h>
#include <string.h> // For strlen()

/*
    Name: Gabriel Rodriguez
    Date: 2/14/2025
    Assignment: String_Decoder_Assignment(B)
    Purpose: This program takes an input string and encodes it using a custom substitution cipher.
             The original and encoded strings are displayed, and the user can repeat the process.
*/

// Function Prototypes
void encode_string(char str[]);

int main() {
    char input[101]; // Space for 100 characters + null terminator
    char choice;

    do {
        // 1. Get user input
        printf("Enter a string (max 100 characters): ");

        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            return 1; // Exit with error
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // 2. Display original string
        printf("\nOriginal String: %s\n", input);

        // 3. Encode and display the encoded string
        encode_string(input);

        // 4. Ask if the user wants to enter another string
        printf("\nWould you like to encode another string? (y/n): ");

        
        if (scanf(" %c", &choice) != 1) {
            printf("Error reading input.\n");
            return 1; // Exit with error
        }

        
        int temp = getchar(); // Read and discard newline
        (void)temp; // Ignore the returned value safely

    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}

// Function to encode a string based on the decoder chart
void encode_string(char str[]) {
    char decoded[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Normal Alphabet
    char encoded[] = "HIVJKWLAMYNBXOZCTPUDQSRGEF"; // Encoded Alphabet

    size_t len = strlen(str);
    char encoded_string[101]; // Storage for encoded string

    // Process each character
    for (size_t i = 0; i < len; i++) { 
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // Find index in normal alphabet and replace with encoded letter
            for (size_t j = 0; j < 26; j++) {
                if (str[i] == decoded[j]) {
                    encoded_string[i] = encoded[j];
                    break;
                }
            }
        }
        else {
            // Keep non-alphabet characters unchanged
            encoded_string[i] = str[i];
        }
    }
    encoded_string[len] = '\0'; // Null-terminate the string

    printf("Encoded String: %s\n", encoded_string);
}
