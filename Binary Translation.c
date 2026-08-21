// first project
#include <stdio.h>
#include <string.h>

void textToBinary(const char *phrase) {
    for (size_t i = 0; phrase[i] != '\0'; i++) { 
        unsigned char c = phrase[i]; 
        for (int bit = 7; bit >= 0; bit--) { 
            putchar((c >> bit) & 1 ? '1' : '0'); 
        }
        if (phrase[i + 1] != '\0') {
            putchar(' ');
        }
    }
    putchar('\n');
}

void binaryToText(const char *binary) { 
    unsigned char c = 0; 
    int count = 0;

    for (size_t i = 0; binary[i] != '\0'; i++) { 
        if (binary[i] == '0' || binary[i] == '1') { 
            c = (c << 1) | (binary[i] - '0');
            count++; 
            if (count == 8) { 
                putchar(c); 
                c = 0; 
                count = 0; 
            }
        }
    }
    if (count != 0) { 
        printf("\nError: binary input length must be a multiple of 8 bits.\n"); 
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
getchar(); 
int ch;
while ((ch = getchar()) != '\n' && ch != EOF) {} 
printf("________________________________\n");
printf("\nChoose whether to convert phrases to binary or binary to phrases:\n");
printf("________________________________\n");
printf("a) Convert phrases to binary\n");
printf("b) Convert binary to phrases\n");
printf("________________________________\n");
if (fgets(phrase, sizeof phrase, stdin) == NULL) return 0; 
if (sscanf(phrase, " %c", &choice) != 1) { 
    printf("Invalid option, please choose a or b to continue the program\n");
} else if (choice == 'a' || choice == 'A') {
    printf("Insert a phrase to convert to binary:\n");
    if (fgets(phrase, sizeof phrase, stdin) == NULL) return 0;
    size_t len = strlen(phrase); 
    if (len > 0 && phrase[len - 1] == '\n') phrase[len - 1] = '\0'; 
    textToBinary(phrase);
} else if (choice == 'b' || choice == 'B') {
    printf("Insert a binary to convert to phrase:\n");
    if (fgets(phrase, sizeof phrase, stdin) == NULL) return 0;
    size_t len = strlen(phrase); 
    if (len > 0 && phrase[len - 1] == '\n') phrase[len - 1] = '\0';
    binaryToText(phrase);
} else {
    printf("Invalid option, please choose a or b to continue the program");
} return 0;
}
