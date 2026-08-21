// first project incoming next
#include <stdio.h>
#include <string.h>

void textToBinary(const char *phrase) {
    for (size_t i = 0; phrase[i] != '\0'; i++) { //
        unsigned char c = phrase[i]; // Get the ASCII value of the character
        for (int bit = 7; bit >= 0; bit--) { // Loop through each bit of the character
            putchar((c >> bit) & 1 ? '1' : '0'); // Print '1' if the bit is set, otherwise print '0'
        }
        if (phrase[i + 1] != '\0') {
            putchar(' '); // Print a space between binary representations of characters
        }
    }
    putchar('\n');
}

void binaryToText(const char *binary) { 
    unsigned char c = 0; 
    int count = 0;

    for (size_t i = 0; binary[i] != '\0'; i++) { // Loop through each character in the binary string
        if (binary[i] == '0' || binary[i] == '1') { // Check if the character is a valid binary digit
            c = (c << 1) | (binary[i] - '0'); // Shift the current character left by 1 and add the new bit
            count++; 
            if (count == 8) { // If we have read 8 bits
                putchar(c); // Print the character corresponding to the binary value
                c = 0; // Reset the character for the next 8 bits
                count = 0; // Reset the count for the next character
            }
        }
    }

    if (count != 0) { // If there are remaining bits that don't form a complete byte
        printf("\nError: binary input length must be a multiple of 8 bits.\n"); // Print an error message if the binary input length is not a multiple of 8
    } else { 
        putchar('\n');
    }
}

int main(void) {
char choice;
char phrase[1000];
printf("________________________________\n");
printf("\nBinary conversion sistem\n");
printf("________________________________\n");
printf("\npress any key to continue...\n");
getchar(); // getchar() is used to wait for the user to press a key before continuing the program
int ch;
while ((ch = getchar()) != '\n' && ch != EOF) {} // Clear the input buffer to remove any extra characters that may have been entered before pressing enter
printf("________________________________\n");
printf("\nChoose whether to convert phrases to binary or binary to phrases:\n");
printf("________________________________\n");
printf("a) Convert phrases to binary\n");
printf("b) Convert binary to phrases\n");
printf("________________________________\n");
if (fgets(phrase, sizeof phrase, stdin) == NULL) return 0; // Read the user's choice from standard input
if (sscanf(phrase, " %c", &choice) != 1) { // Check if the input was successfully read and parsed
    printf("Invalid option, please choose a or b to continue the program\n");
} else if (choice == 'a' || choice == 'A') {
    printf("Insert a phrase to convert to binary:\n");
    if (fgets(phrase, sizeof phrase, stdin) == NULL) return 0;
    size_t len = strlen(phrase); // Check the length of the input phrase
    if (len > 0 && phrase[len - 1] == '\n') phrase[len - 1] = '\0'; // Remove the newline character from the end of the input phrase if it exists
    textToBinary(phrase);
} else if (choice == 'b' || choice == 'B') {
    printf("Insert a binary to convert to phrase:\n");
    if (fgets(phrase, sizeof phrase, stdin) == NULL) return 0;
    size_t len = strlen(phrase); // Check the length of the input binary string
    if (len > 0 && phrase[len - 1] == '\n') phrase[len - 1] = '\0';
    binaryToText(phrase);
} else {
    printf("Invalid option, please choose a or b to continue the program");
} return 0;
}
