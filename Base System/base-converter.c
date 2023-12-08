#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

// color codes
#define RESET_COLOR "\033[0m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define WHITE "\e[0;37m"
#define BLUE "\e[0;34m"

// function of main program
void Main_Program();

// functions to convert
void Binary_to_Binary();
void Base4_to_Base4();
void Octal_to_Octal();
void Decimal_to_Decimal();
void Hexa_to_Hexa();

void Binary_to_Base4();
void Binary_to_Octal();
void Binary_to_Decimal();
void Binary_to_Hexa();

void Base4_to_Binary();
void Base4_to_Octal();
void Base4_to_Decimal();
void Base4_to_Hexa();

void Octal_to_Binary();
void Octal_to_Base4();
void Octal_to_Decimal();
void Octal_to_Hexa();

void Decimal_to_Binary();
void Decimal_to_Base4();
void Decimal_to_Octal();
void Decimal_to_Hexa();

void Hexa_to_Binary();
void Hexa_to_Base4();
void Hexa_to_Octal();
void Hexa_to_Decimal();

void clear_input_buffer();
int is_valid_hex(char c);
int is_valid_hex_array(const char *hexa, int size);

// function to tryAgain or exit
void Tryagain_or_exit();

// global variable declaration
int select_1, select_2;
char choice;

int main()
{
    system("cls");

    Main_Program();

    return 0;
}

void Main_Program()
{
    int c;

    printf(MAGENTA "------------------------------------------------\n" RESET_COLOR);
    printf(CYAN "Welcome to the Base Number Converter\n\n" RESET_COLOR);
    printf("[1] Binary\t (base 2)\n");
    printf("[2] Quaternary\t (base 4)\n");
    printf("[3] Octal\t (base 8)\n");
    printf("[4] Decimal\t (base 10)\n");
    printf("[5] Hexadecimal\t (base 16)\n\n");

    printf(CYAN "From: " RESET_COLOR);
    if (scanf("%d", &select_1) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Main_Program(); // Recursive call
        return;         // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Main_Program(); // Recursive call
            return;         // Exit the function
        }
    }

    printf(CYAN "To: " RESET_COLOR);
    if (scanf("%d", &select_2) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Main_Program(); // Recursive call
        return;         // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Main_Program(); // Recursive call
            return;         // Exit the function
        }
    }

    // Different selectionsto choose
    if (select_1 == 1 && select_2 == 1)
    {
        Binary_to_Binary();
        return;
    }
    else if (select_1 == 1 && select_2 == 2)
    {
        Binary_to_Base4();
        return;
    }
    else if (select_1 == 1 && select_2 == 3)
    {
        Binary_to_Octal();
        return;
    }
    else if (select_1 == 1 && select_2 == 4)
    {
        Binary_to_Decimal();
        return;
    }
    else if (select_1 == 1 && select_2 == 5)
    {
        Binary_to_Hexa();
        return;
    }
    else if (select_1 == 2 && select_2 == 1)
    {
        Base4_to_Binary();
        return;
    }
    else if (select_1 == 2 && select_2 == 2)
    {
        Base4_to_Base4();
        return;
    }
    else if (select_1 == 2 && select_2 == 3)
    {
        Base4_to_Octal();
        return;
    }
    else if (select_1 == 2 && select_2 == 4)
    {
        Base4_to_Decimal();
        return;
    }
    else if (select_1 == 2 && select_2 == 5)
    {
        Base4_to_Hexa();
        return;
    }
    else if (select_1 == 3 && select_2 == 1)
    {
        Octal_to_Binary();
        return;
    }
    else if (select_1 == 3 && select_2 == 2)
    {
        Octal_to_Base4();
        return;
    }
    else if (select_1 == 3 && select_2 == 3)
    {
        Octal_to_Octal();
        return;
    }
    else if (select_1 == 3 && select_2 == 4)
    {
        Octal_to_Decimal();
        return;
    }

    else if (select_1 == 3 && select_2 == 5)
    {
        Octal_to_Hexa();
        return;
    }
    else if (select_1 == 4 && select_2 == 1)
    {
        Decimal_to_Binary();
        return;
    }
    else if (select_1 == 4 && select_2 == 2)
    {
        Decimal_to_Base4();
        return;
    }
    else if (select_1 == 4 && select_2 == 3)
    {
        Decimal_to_Octal();
        return;
    }
    else if (select_1 == 4 && select_2 == 4)
    {
        Decimal_to_Decimal();
        return;
    }
    else if (select_1 == 4 && select_2 == 5)
    {
        Decimal_to_Hexa();
        return;
    }
    else if (select_1 == 5 && select_2 == 4)
    {
        Hexa_to_Decimal();
        return;
    }
    else if (select_1 == 5 && select_2 == 1)
    {
        Hexa_to_Binary();
        return;
    }
    else if (select_1 == 5 && select_2 == 2)
    {
        Hexa_to_Base4();
        return;
    }
    else if (select_1 == 5 && select_2 == 3)
    {
        Hexa_to_Octal();
        return;
    }
    else if (select_1 == 5 && select_2 == 5)
    {
        Hexa_to_Hexa();
        return;
    }
    else
    {
        printf(RED "\nInvalid selection! Please run the code again." RESET_COLOR);
        Main_Program();
        return;
    }
}

// A loop that can scan the input from left to \n
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// For Binary to Binary
void Binary_to_Binary()
{
    long long num;
    int remainder = 0, place = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a binary number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Binary_to_Binary(); // Recursive call
        return;             // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Binary_to_Binary(); // Recursive call
            return;             // Exit the function
        }
    }

    while (num)
    {
        remainder = num % 10;
        if (num > 0)
            if (remainder == 0 || remainder == 1)
            {
                printf(GREEN "\nIt is already a binary." RESET_COLOR);
                break;
            }
            else
            {
                printf(RED "\nInvalid Base 2 Input!\n");
                printf("Base 2 numbers only include 0 and 1!\n");
                printf("Try Again!\n" RESET_COLOR);
                Binary_to_Binary();
            }
        else
        {
            printf(RED "\nPlease enter a POSITIVE BASE 2 INTEGER.\n" RESET_COLOR);
            Binary_to_Binary();
        }
        num = num / 10;
        place++;
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Binary to Decimal
void Binary_to_Decimal()
{
    long long num, temp_num, total = 0, product = 0;
    int remainder = 0, place = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a binary number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Binary_to_Decimal(); // Recursive call
        return;              // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Binary_to_Decimal(); // Recursive call
            return;              // Exit the function
        }
    }

    temp_num = num;

    while (num)
    {
        remainder = num % 10;

        if (remainder == 0 || remainder == 1)
        {
            if (num == temp_num)
            {
                printf("\nSolution: \n\n");
            }
            product = remainder * (pow(2, place));
            printf("%d x 2^%d = %lld\n", remainder, place, product);
            total += product;
        }
        else
        {
            printf(RED "\nInvalid Base 2 Input!\n");
            printf("Base 2 numbers only include 0 and 1!\n");
            printf("Try Again!\n" RESET_COLOR);
            Binary_to_Decimal();
        }
        num = num / 10;
        place++;
    }
    printf("\nAdd the numbers to get the decimal\n");
    printf(GREEN "\nThe decimal equivalent of %lld is %lld\n" RESET_COLOR, temp_num, total);

    Tryagain_or_exit();
}

// For Binary to Base 4
void Binary_to_Base4()
{
    long long num, temp_num, total = 0, product = 0;
    int remainder = 0, place = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a binary number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Binary_to_Base4(); // Recursive call
        return;            // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Binary_to_Base4(); // Recursive call
            return;            // Exit the function
        }
    }

    temp_num = num;

    while (num)
    {
        remainder = num % 10;

        if (remainder == 0 || remainder == 1)
        {
            if (num == temp_num)
            {
                printf("\nSolution: \n\n");
            }
            product = remainder * (pow(2, place));
            printf("%d x 2^%d = %lld\n", remainder, place, product);
            total += product;
        }
        else
        {
            printf(RED "\nInvalid Base 2 Input!\n");
            printf("Base 2 numbers only include 0 and 1!\n");
            printf("Try Again!\n" RESET_COLOR);
            Binary_to_Base4();
        }
        num = num / 10;
        place++;
    }
    printf("\nThe decimal equivalent of %lld is %lld\n", temp_num, total);
    int a = 0;
    float division = 0;
    remainder = 0;
    char base4[100];

    printf("\nR represents the remainder\n\n");

    if (total > 0)
    {
        // Storing the binary in an array
        while (total)
        {
            remainder = total % 4;
            division = total / 4.0;
            if (division <= 99)
            {
                printf("%lld / 4 =  %.1f\t | R:%d\n", total, division, remainder);
            }
            else
            {
                printf("%lld / 4 =  %.1f |R:%d\n", total, division, remainder);
            }

            total = total / 4;
            base4[a++] = remainder + '0'; // Store the binary digit as character
        }

        // Sorting the base 4 array
        int start = 0;
        int end = a - 1;
        while (start < end)
        {
            char temp = base4[start];
            base4[start] = base4[end];
            base4[end] = temp;
            start++;
            end--;
        }
        printf("\nArrange the remainders from bottom to top to get the base 4\n\n");
        printf(GREEN "The base 4 equivalent of %lld is %s\n" RESET_COLOR, temp_num, base4);
    }

    Tryagain_or_exit();
}

// For Binary to Octal
void Binary_to_Octal()
{
    long long num, temp_num, total = 0, product = 0;
    int remainder = 0, place = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a binary number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Binary_to_Octal(); // Recursive call
        return;            // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Binary_to_Octal(); // Recursive call
            return;            // Exit the function
        }
    }

    temp_num = num;

    while (num)
    {
        remainder = num % 10;

        if (remainder == 0 || remainder == 1)
        {
            if (num == temp_num)
            {
                printf("\nSolution: \n\n");
            }
            product = remainder * (pow(2, place));
            printf("%d x 2^%d = %lld\n", remainder, place, product);
            total += product;
        }
        else
        {
            printf(RED "\nInvalid Base 2 Input!\n");
            printf("Base 2 numbers only include 0 and 1!\n");
            printf("Try Again!\n" RESET_COLOR);
            Binary_to_Octal();
        }
        num = num / 10;
        place++;
    }
    printf("\nThe decimal equivalent of %lld is %lld\n", temp_num, total);
    int a = 0;
    float division = 0;
    remainder = 0;
    char octal[100];

    printf("\nR represents the remainder\n\n");

    if (total > 0)
    {
        // Storing the binary in an array
        while (total)
        {
            remainder = total % 8;
            division = total / 8.0;
            if (division <= 99)
            {
                printf("%lld / 8 =  %.1f\t | R:%d\n", total, division, remainder);
            }
            else
            {
                printf("%lld / 8 =  %.1f |R:%d\n", total, division, remainder);
            }

            total = total / 8;
            octal[a++] = remainder + '0'; // Store the binary digit as character
        }

        // Sorting the octal array
        int start = 0;
        int end = a - 1;
        while (start < end)
        {
            char temp = octal[start];
            octal[start] = octal[end];
            octal[end] = temp;
            start++;
            end--;
        }
        printf("\nArrange the remainders from bottom to top to get the base 8\n\n");
        printf(GREEN "The octal equivalent of %lld is %s\n" RESET_COLOR, temp_num, octal);
    }

    Tryagain_or_exit();
}

// For Binary to Hexadecimal
void Binary_to_Hexa()
{
    long long num, temp_num, total = 0, product = 0;
    int remainder = 0, place = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a binary number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Binary_to_Hexa(); // Recursive call
        return;           // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Binary_to_Hexa(); // Recursive call
            return;           // Exit the function
        }
    }

    temp_num = num;

    while (num)
    {
        remainder = num % 10;

        if (remainder == 0 || remainder == 1)
        {
            if (num == temp_num)
            {
                printf("\nSolution: \n\n");
            }
            product = remainder * (pow(2, place));
            printf("%d x 2^%d = %lld\n", remainder, place, product);
            total += product;
        }
        else
        {
            printf(RED "\nInvalid Base 2 Input!\n");
            printf("Base 2 numbers only include 0 and 1!\n");
            printf("Try Again!\n" RESET_COLOR);
            Binary_to_Hexa();
        }
        num = num / 10;
        place++;
    }
    printf("\nThe decimal equivalent of %lld is %lld\n", temp_num, total);

    int a = 0;
    float division = 0;
    char hexa[100];
    remainder = 0;

    printf("\nR represents the remainder\n\n");

    if (total > 0)
    {
        while (total)
        {
            remainder = total % 16;
            division = total / 16.0;
            if (division <= 99)
            {
                printf("%lld / 16 =  %.1f | R:%d\n", total, division, remainder);
            }
            else
            {
                printf("%lld / 16 =  %.1f |R:%d\n", total, division, remainder);
            }
            if (remainder < 10)
                hexa[a] = remainder + '0';
            else
                hexa[a] = remainder + 'A' - 10;
            total = total / 16;
            a++;
        }
        printf("\nArrange the remainders from bottom to top to get the base 16\n");
        printf(GREEN "\nThe hexadecimal equivalent of %lld is ", temp_num);
        for (int j = a - 1; j >= 0; j--)
            printf(GREEN "%c" RESET_COLOR, hexa[j]);
        printf("\n");
    }

    Tryagain_or_exit();
}

// For Base 4 to Base 4
void Base4_to_Base4()
{
    long long num;
    int remainder = 0, above4 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a base 4 number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Base4_to_Base4(); // Recursive call
        return;           // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Base4_to_Base4(); // Recursive call
            return;           // Exit the function
        }
    }

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder >= 4)
            {
                above4++;
            }
            num = num / 10;
        }
        if (above4 == 0)
        {
            printf(GREEN "\nIt is already a quaternary." RESET_COLOR);
        }
        else
        {
            printf(RED "\nInvalid Base 4 Input!\n");
            printf("Base 4 numbers only include 0 - 3!\n");
            printf("Try Again!\n" RESET_COLOR);
            Base4_to_Base4();
            return;
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 4 INTEGER.\n" RESET_COLOR);
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Base 4 to Decimal
void Base4_to_Decimal()
{
    long long num, temp_num, temp_num2, product = 0, total = 0;
    int remainder = 0, place = 0, above4 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a base 4 number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Base4_to_Decimal(); // Recursive call
        return;             // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Base4_to_Decimal(); // Recursive call
            return;             // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder >= 4)
            {
                above4++;
            }
            num = num / 10;
        }

        if (above4 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;
                if (remainder <= 3 && remainder != -1)
                {
                    product = remainder * (pow(4, place));
                    printf("%d x 4^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 4 Input!\n");
                    printf("Base 4 numbers only include 0 - 3!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Base4_to_Decimal();
                }
                temp_num = temp_num / 10;
                place++;
            }
            printf("\nAdd the numbers to get the decimal\n");
            printf(GREEN "\nThe decimal equivalent of %lld is %lld\n" RESET_COLOR, temp_num2, total);
        }
        else
        {
            printf(RED "\nInvalid Base 4 Input!\n");
            printf("Base 4 numbers only include 0 - 3!\n");
            printf("Try Again!\n" RESET_COLOR);
            Base4_to_Decimal();
            return;
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 4 INTEGER.\n" RESET_COLOR);
        Base4_to_Decimal();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For base 4 to Binary
void Base4_to_Binary()
{
    long long num, temp_num, temp_num2, product = 0, total = 0;
    int remainder = 0, place = 0, above4 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a base 4 number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Base4_to_Binary(); // Recursive call
        return;            // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Base4_to_Binary(); // Recursive call
            return;            // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder >= 4)
            {
                above4++;
            }
            num = num / 10;
        }

        if (above4 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 3 && remainder != -1)
                {
                    product = remainder * (pow(4, place));
                    printf("%d x 4^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 4 Input!\n");
                    printf("Base 4 numbers only include 0 - 3!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Base4_to_Binary();
                }
                temp_num = temp_num / 10;
                place++;
            }
            printf("\nAdd the numbers to get the decimal\n");
            printf("The decimal equivalent of %lld is %lld\n", temp_num2, total);

            printf("\nR represents the remainder\n\n");

            int b = 0;
            float division = 0;
            char binary[100];
            remainder = 0;

            if (total >= 0)
            {
                while (total)
                {
                    remainder = total % 2;
                    division = total / 2.0;
                    if (division <= 99)
                    {
                        printf("%lld / 2 =  %.1f\t | R:%d\n", total, division, remainder);
                    }
                    else
                    {
                        printf("%lld / 2 =  %.1f |R:%d\n", total, division, remainder);
                    }
                    total = total / 2;
                    binary[b++] = remainder + '0'; // Store the binary digit as character
                }

                // Sorting the binary array
                int start = 0;
                int end = b - 1;
                while (start < end)
                {
                    char temp = binary[start];
                    binary[start] = binary[end];
                    binary[end] = temp;
                    start++;
                    end--;
                }
                printf("\nArrange the remainders from bottom to top to get the base 2\n");
                printf(GREEN "\nThe binary equivalent of %lld is %s" RESET_COLOR, temp_num2, binary);
            }
        }
        else
        {
            printf(RED "\nInvalid Base 4 Input!\n");
            printf("Base 4 numbers only include 0 - 3!\n");
            printf("Try Again!\n" RESET_COLOR);
            Base4_to_Binary();
            return;
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 4 INTEGER.\n" RESET_COLOR);
        Base4_to_Binary();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Base 4 to Octal
void Base4_to_Octal()
{
    long long num, temp_num, temp_num2, product = 0, total = 0;
    int remainder = 0, place = 0, above4 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a base 4 number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Base4_to_Octal(); // Recursive call
        return;           // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Base4_to_Octal(); // Recursive call
            return;           // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder >= 4)
            {
                above4++;
            }
            num = num / 10;
        }

        if (above4 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 3 && remainder != -1)
                {
                    product = remainder * (pow(4, place));
                    printf("%d x 4^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 4 Input!\n");
                    printf("Base 4 numbers only include 0 - 3!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Base4_to_Octal();
                }
                temp_num = temp_num / 10;
                place++;
            }
            printf("\nAdd the numbers to get the decimal\n");
            printf("The decimal equivalent of %lld is %lld\n", temp_num2, total);

            printf("\nR represents the remainder\n\n");

            int b = 0;
            float division = 0;
            char octal[100];
            remainder = 0;

            if (total >= 0)
            {
                while (total)
                {
                    remainder = total % 8;
                    division = total / 8.0;
                    if (division <= 99)
                    {
                        printf("%lld / 8 =  %.1f\t | R:%d\n", total, division, remainder);
                    }
                    else
                    {
                        printf("%lld / 8 =  %.1f |R:%d\n", total, division, remainder);
                    }
                    total = total / 8;
                    octal[b++] = remainder + '0'; // Store the binary digit as character
                }

                // Sorting the binary array
                int start = 0;
                int end = b - 1;
                while (start < end)
                {
                    char temp = octal[start];
                    octal[start] = octal[end];
                    octal[end] = temp;
                    start++;
                    end--;
                }
                printf("\nArrange the remainders from bottom to top to get the base 8\n");
                printf(GREEN "\nThe octal equivalent of %lld is %s" RESET_COLOR, temp_num2, octal);
            }
        }
        else
        {
            printf(RED "\nInvalid Base 4 Input!\n");
            printf("Base 4 numbers only include 0 - 3!\n");
            printf("Try Again!\n" RESET_COLOR);
            Base4_to_Octal();
            return;
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 4 INTEGER.\n" RESET_COLOR);
        Base4_to_Octal();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Base 4 to Hexadecimal
void Base4_to_Hexa()
{
    long long num, temp_num, temp_num2, total = 0, product = 0;
    int remainder = 0, place = 0, above4 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a base 4 number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Base4_to_Hexa(); // Recursive call
        return;          // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Base4_to_Hexa(); // Recursive call
            return;          // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder >= 4)
            {
                above4++;
            }
            num = num / 10;
        }
        if (above4 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 3 && remainder != -1)
                {
                    product = remainder * (pow(4, place));
                    printf("%d x 4^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 4 Input!\n");
                    printf("Base 4 numbers only include 0 - 3!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Base4_to_Hexa();
                }
                temp_num = temp_num / 10;
                place++;
            }
            printf("\nThe binary equivalent %lld is %lld\n", temp_num2, total);

            int a = 0;
            float division = 0;
            char hexa[100];
            remainder = 0;

            printf("\nR represents the remainder\n\n");

            if (total > 0)
            {
                while (total)
                {
                    remainder = total % 16;
                    division = total / 16.0;
                    if (division <= 99)
                    {
                        printf("%lld / 16 =  %.1f | R:%d\n", total, division, remainder);
                    }
                    else
                    {
                        printf("%lld / 16 =  %.1f |R:%d\n", total, division, remainder);
                    }
                    if (remainder < 10)
                        hexa[a] = remainder + '0';
                    else
                        hexa[a] = remainder + 'A' - 10;
                    total = total / 16;
                    a++;
                }
                printf("\nArrange the remainders from bottom to top to get the base 16\n\n");
                printf(GREEN "The hexadecimal equivalent of %lld is ", temp_num2);
                for (int j = a - 1; j >= 0; j--)
                    printf(GREEN "%c" RESET_COLOR, hexa[j]);
            }
        }
        else
        {
            printf(RED "\nInvalid Base 4 Input!\n");
            printf("Base 4 numbers only include 0 - 3!\n");
            printf("Try Again!\n" RESET_COLOR);
            Base4_to_Hexa();
            return;
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 4 INTEGER.\n" RESET_COLOR);
        Base4_to_Hexa();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Octal to Octal
void Octal_to_Octal()
{
    char octal[100];
    int remainder, above7, c;
    long long num;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter an octal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Octal_to_Octal(); // Recursive call
        return;           // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Octal_to_Octal(); // Recursive call
            return;           // Exit the function
        }
    }

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder > 7)
            {
                above7++;
            }
            num = num / 10;
        }
        if (above7 == 0)
        {
            printf(GREEN "\nIt is already an octal." RESET_COLOR);
        }
        else
        {
            printf(RED "\nInvalid Base 8 Input!\n");
            printf(RED "Base 8 numbers only include 0 - 7!\n");
            printf("Try Again!\n" RESET_COLOR);
            Octal_to_Octal();
            return;
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 8 INTEGER." RESET_COLOR);
    }

    printf("\n");

    Tryagain_or_exit();
}

// For Octal to Decimal
void Octal_to_Decimal()
{
    long long num, temp_num, temp_num2, total = 0, product = 0;
    int remainder = 0, place = 0, above7 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter an octal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Octal_to_Decimal(); // Recursive call
        return;             // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Octal_to_Decimal(); // Recursive call
            return;             // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder > 7)
            {
                above7++;
            }
            num = num / 10;
        }

        if (above7 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 7 && remainder != -1)
                {
                    product = remainder * (pow(8, place));
                    printf("%d x 8^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 8 Input!\n");
                    printf("Base 8 numbers only include the positive number 0-7!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Octal_to_Decimal();
                }
                temp_num = temp_num / 10;
                place++;
            }

            printf("\nAdd the numbers to get the decimal\n");
            printf(GREEN "\nThe decimal equivalent of %lld is %lld\n" RESET_COLOR, temp_num2, total);
        }
        else
        {
            printf(RED "\nInvalid Base 8 Input!\n");
            printf("Base 8 numbers only include the positive number 0-7!\n");
            printf("Try Again!\n" RESET_COLOR);
            Octal_to_Decimal();
            return; // Return after recursive call to prevent further execution
        }
    }

    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 8 INTEGER.\n" RESET_COLOR);
        Octal_to_Decimal();
        return;
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Octal to Binary
void Octal_to_Binary()
{
    long long num, temp_num, temp_num2, total = 0, product = 0;
    int remainder = 0, place = 0, above7 = 0, c;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter an octal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Octal_to_Binary(); // Recursive call
        return;            // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Octal_to_Binary(); // Recursive call
            return;            // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder > 7)
            {
                above7++;
            }
            num = num / 10;
        }

        if (above7 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 7 && remainder != -1)
                {
                    product = remainder * (pow(8, place));
                    printf("%d x 8^%d = %d\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 8 Input!\n");
                    printf("Base 8 numbers only include the positive number 0-7!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Octal_to_Binary();
                }
                temp_num = temp_num / 10;
                place++;
            }
        }
        else
        {
            printf(RED "\nInvalid Base 8 Input!\n");
            printf("Base 8 numbers only include the positive number 0-7!\n");
            printf("Try Again!\n" RESET_COLOR);
            Octal_to_Binary();
            return; // Return after recursive call to prevent further execution
        }

        printf("\nAdd the numbers to get the decimal\n");
        printf("The decimal equivalent of %lld is %lld\n", temp_num2, total);

        int a = 0;
        float division = 0;
        remainder = 0;
        char binary[100];

        printf("\nR represents the remainder\n\n");

        if (total > 0)
        {
            while (total)
            {
                remainder = total % 2;
                division = total / 2.0;
                if (division <= 99)
                {
                    printf("%lld / 2 =  %.1f\t | R:%d\n", total, division, remainder);
                }
                else
                {
                    printf("%lld / 2 =  %.1f |R:%d\n", total, division, remainder);
                }

                total = total / 2;
                binary[a++] = remainder + '0'; // Store the binary digit as character
            }
            int start = 0;
            int end = a - 1;
            while (start < end)
            {
                char temp = binary[start];
                binary[start] = binary[end];
                binary[end] = temp;
                start++;
                end--;
            }

            printf("\nArrange the remainders from bottom to top to get the base 2\n");
            printf(GREEN "\nThe binary equivalent of %lld is %s" RESET_COLOR, temp_num2, binary);
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 8 INTEGER.\n" RESET_COLOR);
        Octal_to_Binary();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Octal to Base 4
void Octal_to_Base4()
{
    long long num, temp_num, temp_num2, total = 0, product = 0;
    int remainder = 0, place = 0, c, above7 = 0;
    char octal[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter an octal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Octal_to_Base4(); // Recursive call
        return;           // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Octal_to_Base4(); // Recursive call
            return;           // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder > 7)
            {
                above7++;
            }
            num = num / 10;
        }

        if (above7 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 7 && remainder != -1)
                {
                    product = remainder * (pow(8, place));
                    printf("%d x 8^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 8 Input!\n");
                    printf("Base 8 numbers only include the positive number 0-7!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Octal_to_Base4();
                }
                temp_num = temp_num / 10;
                place++;
            }
        }
        else
        {
            printf(RED "\nInvalid Base 8 Input!\n");
            printf("Base 8 numbers only include the positive number 0-7!\n");
            printf("Try Again!\n" RESET_COLOR);
            Octal_to_Base4();
            return; // Return after recursive call to prevent further execution
        }

        printf("\nAdd the numbers to get the decimal\n");
        printf("The decimal equivalent of %lld is %lld\n", temp_num2, total);

        int a = 0;
        float division = 0;
        remainder = 0;
        char base4[100];

        printf("\nR represents the remainder\n\n");

        if (total > 0)
        {
            while (total)
            {
                remainder = total % 4;
                division = total / 4.0;
                if (division <= 99)
                {
                    printf("%lld / 4 =  %.1f\t | R:%d\n", total, division, remainder);
                }
                else
                {
                    printf("%lld / 4 =  %.1f |R:%d\n", total, division, remainder);
                }

                total = total / 4;
                base4[a++] = remainder + '0'; // Store the binary digit as character
            }
            int start = 0;
            int end = a - 1;
            while (start < end)
            {
                char temp = base4[start];
                base4[start] = base4[end];
                base4[end] = temp;
                start++;
                end--;
            }

            printf("\nArrange the remainders from bottom to top to get the base 4\n");
            printf(GREEN "\nThe base 4 equivalent of %lld is %s" RESET_COLOR, temp_num2, base4);
        }
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 8 INTEGER.\n" RESET_COLOR);
        Octal_to_Base4();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Octal to Hexadecimal
void Octal_to_Hexa()
{
    long long num, temp_num, temp_num2, product = 0, total = 0;
    int remainder = 0, place = 0, above7 = 0, c;
    char octal[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter an octal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Octal_to_Hexa(); // Recursive call
        return;          // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Octal_to_Hexa(); // Recursive call
            return;          // Exit the function
        }
    }

    temp_num = num;
    temp_num2 = num;

    if (num >= 0)
    {
        while (num)
        {
            remainder = num % 10;

            if (remainder > 7)
            {
                above7++;
            }
            num = num / 10;
        }

        if (above7 == 0)
        {
            printf("\nSolution: \n\n");
            while (temp_num)
            {
                remainder = temp_num % 10;

                if (remainder <= 7 && remainder != -1)
                {
                    product = remainder * (pow(8, place));
                    printf("%d x 8^%d = %lld\n", remainder, place, product);
                    total += product;
                }
                else
                {
                    printf(RED "\nInvalid Base 8 Input!\n");
                    printf("Base 8 numbers only include the positive number 0-7!\n");
                    printf("Try Again!\n" RESET_COLOR);
                    Octal_to_Hexa();
                }
                temp_num = temp_num / 10;
                place++;
            }
        }
        else
        {
            printf(RED "\nInvalid Base 8 Input!\n");
            printf("Base 8 numbers only include the positive number 0-7!\n");
            printf("Try Again!\n" RESET_COLOR);
            Octal_to_Hexa();
            return; // Return after recursive call to prevent further execution
        }

        printf("\nAdd the numbers to get the decimal\n");
        printf("The decimal equivalent of %lld is %lld\n", temp_num2, total);

        int a = 0;
        float division = 0;
        char hexa[100];
        remainder = 0;

        printf("\nR represents the remainder\n\n");

        if (total > 0)
        {
            while (total)
            {
                remainder = total % 16;
                division = total / 16.0;
                if (division <= 99)
                {
                    printf("%lld / 16 =  %.1f | R:%d\n", total, division, remainder);
                }
                else
                {
                    printf("%lld / 16 =  %.1f |R:%d\n", total, division, remainder);
                }
                if (remainder < 10)
                    hexa[a] = remainder + '0';
                else
                    hexa[a] = remainder + 'A' - 10;
                total = total / 16;
                a++;
            }
            printf("\nArrange the remainders from bottom to top to get the base 16\n");
            printf(GREEN "\nThe hexadecimal equivalent of %lld is ", temp_num2);
            for (int j = a - 1; j >= 0; j--)
                printf(GREEN "%c" RESET_COLOR, hexa[j]);
        }
    }

    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 8 INTEGER.\n" RESET_COLOR);
        Octal_to_Hexa();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Decimal to Decimal
void Decimal_to_Decimal()
{
    int c;
    long long num;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a decimal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Decimal_to_Decimal(); // Recursive call
        return;               // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Decimal_to_Decimal(); // Recursive call
            return;               // Exit the function
        }
    }

    if (num > 0)
    {
        printf(GREEN "\nIt is already a decimal.\n" RESET_COLOR);
    }
    else
    {
        printf(RED "\nPlease enter a POSITIVE BASE 2 INTEGER.\n" RESET_COLOR);
        Decimal_to_Decimal(); // Recursive call
        return;               // Exit the function
    }

    Tryagain_or_exit();
}

// For Decimal to Binary
void Decimal_to_Binary()
{
    long long num, temp_num, remainder = 0, a = 0, c;
    float division = 0;
    char binary[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a decimal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Decimal_to_Binary(); // Recursive call
        return;              // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Decimal_to_Binary(); // Recursive call
            return;              // Exit the function
        }
    }

    temp_num = num;

    if (num > 0)
    {
        printf("\nSolution: \n");
        while (num)
        {
            remainder = num % 2;
            division = num / 2.0;
            if (division <= 99)
            {
                printf("%lld / 2 =  %.1f\t | R:%lld\n", num, division, remainder);
            }
            else
            {
                printf("%lld / 2 =  %.1f |R:%lld\n", num, division, remainder);
            }
            num = num / 2;
            binary[a++] = remainder + '0'; // Store the binary digit as character
        }

        // Sorting the binary array
        int start = 0;
        int end = a - 1;
        while (start < end)
        {
            char temp = binary[start];
            binary[start] = binary[end];
            binary[end] = temp;
            start++;
            end--;
        }
        printf("\nArrange the remainders from bottom to top to get the base 2\n");
        printf(GREEN "\nThe binary equivalent of %lld is %s\n" RESET_COLOR, temp_num, binary);
    }
    else
    {
        printf(RED "\nInvalid Base 10 Input!\n");
        printf("Please enter a positive number!\n");
        printf("Try Again!\n" RESET_COLOR);
        Decimal_to_Binary();
    }

    Tryagain_or_exit();
}

// For Decimal to Base 4
void Decimal_to_Base4()
{
    long long num, remainder = 0, temp_num, a = 0, c;
    float division = 0;
    char base4[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a decimal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Decimal_to_Base4(); // Recursive call
        return;             // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Decimal_to_Base4(); // Recursive call
            return;             // Exit the function
        }
    }

    temp_num = num;

    if (num > 0)
    {
        printf("\nSolution: \n");
        printf("\nR represents the remainder\n\n");
        // Storing the binary in an array
        while (num)
        {
            remainder = num % 4;
            division = num / 4.0;
            if (division <= 99)
            {
                printf("%lld / 4 =  %.1f\t | R:%lld\n", num, division, remainder);
            }
            else
            {
                printf("%lld / 4 =  %.1f |R:%lld\n", num, division, remainder);
            }

            num = num / 4;
            base4[a++] = remainder + '0'; // Store the binary digit as character
        }

        // Sorting the base 4 array
        int start = 0;
        int end = a - 1;
        while (start < end)
        {
            char temp = base4[start];
            base4[start] = base4[end];
            base4[end] = temp;
            start++;
            end--;
        }
        printf("\nArrange the remainders from bottom to top to get the base 4\n\n");
        printf(GREEN "The base 4 equivalent of %lld is %s\n" RESET_COLOR, temp_num, base4);
    }
    else
    {
        printf(RED "\nInvalid Base 10 Input!\n");
        printf("Please enter a positive number!\n");
        printf("Try Again!\n" RESET_COLOR);
        Decimal_to_Base4();
    }

    Tryagain_or_exit();
}

// For Decimal to Octal
void Decimal_to_Octal()
{
    long long num, remainder = 0, temp_num, a = 0, c;
    float division = 0;
    char octal[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a decimal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Decimal_to_Octal(); // Recursive call
        return;             // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Decimal_to_Octal(); // Recursive call
            return;             // Exit the function
        }
    }

    temp_num = num;

    if (num > 0)
    {
        printf("\nSolution: \n");
        printf("\nR represents the remainder\n\n");
        // Storing the binary in an array
        while (num)
        {
            remainder = num % 8;
            division = num / 8.0;
            if (division <= 99)
            {
                printf("%lld / 8 =  %.1f\t | R:%lld\n", num, division, remainder);
            }
            else
            {
                printf("%lld / 8 =  %.1f |R:%lld\n", num, division, remainder);
            }

            num = num / 8;
            octal[a++] = remainder + '0'; // Store the binary digit as character
        }

        // Sorting the base 4 array
        int start = 0;
        int end = a - 1;
        while (start < end)
        {
            char temp = octal[start];
            octal[start] = octal[end];
            octal[end] = temp;
            start++;
            end--;
        }
        printf("\nArrange the remainders from bottom to top to get the base 8\n\n");
        printf(GREEN "The octal equivalent of %lld is %s\n" RESET_COLOR, temp_num, octal);
    }
    else
    {
        printf(RED "\nInvalid Base 10 Input!\n");
        printf("Please enter a positive number!\n");
        printf("Try Again!\n" RESET_COLOR);
        Decimal_to_Octal();
    }

    Tryagain_or_exit();
}

// For Decimal to Hexadecimal
void Decimal_to_Hexa()
{
    long long num, temp_num;
    int remainder = 0, a = 0, c;
    float division = 0;
    char hexa[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a decimal number: " RESET_COLOR);
    if (scanf("%lld", &num) != 1)
    {
        clear_input_buffer(); // to get if there is spaces in the input
        printf(RED "\nError: Invalid input. Please enter a number.\n" RESET_COLOR);
        Decimal_to_Hexa(); // Recursive call
        return;            // Exit the function
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace(c))
        { // to get if there is spaces in the input
            clear_input_buffer();
            printf(RED "\nError: Invalid input. Please enter a valid number.\n" RESET_COLOR);
            Decimal_to_Hexa(); // Recursive call
            return;            // Exit the function
        }
    }

    temp_num = num;

    if (num > 0)
    {
        printf("\nSolution: \n");
        printf("\nR represents the remainder\n\n");
        while (num)
        {
            remainder = num % 16;
            division = num / 16.0;
            if (division <= 99)
            {
                printf("%lld / 16 =  %.1f | R:%d\n", num, division, remainder);
            }
            else
            {
                printf("%lld / 16 =  %.1f |R:%d\n", num, division, remainder);
            }
            if (remainder < 10)
                hexa[a] = remainder + '0';
            else
                hexa[a] = remainder + 'A' - 10;
            num = num / 16;
            a++;
        }
        printf(GREEN "\nThe hexadecimal equivalent of %lld is ", temp_num);
        for (int j = a - 1; j >= 0; j--)
            printf(GREEN "%c" RESET_COLOR, hexa[j]);
        printf("\n");
    }
    else
    {
        printf(RED "\nInvalid Base 10 Input!\n");
        printf("Please enter a positive number!\n");
        printf("Try Again!\n" RESET_COLOR);
        Decimal_to_Hexa();
    }

    Tryagain_or_exit();
}

int is_valid_hex(char c)
{
    return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int is_valid_hex_array(const char *hexa, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!is_valid_hex(hexa[i]))
        {
            return 0; // Invalid hex character found
        }
    }
    return 1; // All characters are valid hex characters
}

// For Hexadecimal to Hexadecimal
void Hexa_to_Hexa()
{
    char hexa[100];

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a hexadecimal number: " RESET_COLOR);
    fgets(hexa, sizeof(hexa), stdin);
    hexa[strcspn(hexa, "\n")] = '\0'; // Remove trailing newline

    // Check if the input contains any spaces
    for (int i = 0; hexa[i] != '\0'; i++)
    {
        if (hexa[i] == ' ')
        {
            printf(RED "\nError: Invalid input. Spaces are not allowed.\n" RESET_COLOR);
            Hexa_to_Hexa();
            return; // Exit the function
        }
    }

    int size = strlen(hexa);

    // Check if the input is not empty and contains only valid hexadecimal characters
    if (size > 0 && is_valid_hex_array(hexa, size))
    {
        printf(GREEN "\nIt is already in hexadecimal." RESET_COLOR);
    }
    else
    {
        printf(RED "\nInvalid Base 16 Input!\n");
        printf("Base 16 numbers only include the positive number 0-9 and letters A-F!\n");
        printf("Try Again!\n" RESET_COLOR);
        Hexa_to_Hexa();
        return; // Exit the function
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Hexadecimal to Decimal
void Hexa_to_Decimal()
{
    char hexa[100];
    long long place = 0, total = 0, product;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a hexadecimal number: " RESET_COLOR);
    fgets(hexa, sizeof(hexa), stdin);
    hexa[strcspn(hexa, "\n")] = '\0'; // Remove trailing newline

    // Check if the input contains any spaces
    for (int i = 0; hexa[i] != '\0'; i++)
    {
        if (hexa[i] == ' ')
        {
            printf(RED "\nError: Invalid input. Spaces are not allowed.\n" RESET_COLOR);
            Hexa_to_Decimal();
            return; // Exit the function
        }
    }

    int size = strlen(hexa);

    // Check if the input is not empty and contains only valid hexadecimal characters
    if (size > 0 && is_valid_hex_array(hexa, size))
    {
        printf("\nSolution: \n");

        for (int i = size - 1; i >= 0; i--)
        {
            int integer = 0;

            if (hexa[i] >= '0' && hexa[i] <= '9')
            {
                integer = hexa[i] - '0';
            }
            else if (hexa[i] >= 'A' && hexa[i] <= 'F')
            {
                integer = hexa[i] - 'A' + 10;
            }
            else if (hexa[i] >= 'a' && hexa[i] <= 'f')
            {
                integer = hexa[i] - 'a' + 10;
            }

            product = integer * pow(16, place);
            printf("%d x 16^%lld = %lld\n", integer, place, product);

            total += integer * pow(16, place);
            place++;
        }
        printf("\nAdd all the products.\n");
        printf(GREEN "\nThe decimal equivalent of %s is %lld" RESET_COLOR, hexa, total);
    }
    else
    {
        printf(RED "\nInvalid Base 16 Input!\n");
        printf("Base 16 numbers only include the positive number 0-9 and letters A-F!\n");
        printf("Try Again!\n" RESET_COLOR);
        Hexa_to_Decimal();
        return; // Exit the function
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Hexadecimal to Binary
void Hexa_to_Binary()
{
    char hexa[100];
    long long place = 0, total = 0, product;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a hexadecimal number: " RESET_COLOR);
    fgets(hexa, sizeof(hexa), stdin);
    hexa[strcspn(hexa, "\n")] = '\0'; // Remove trailing newline

    // Check if the input contains any spaces
    for (int i = 0; hexa[i] != '\0'; i++)
    {
        if (hexa[i] == ' ')
        {
            printf(RED "\nError: Invalid input. Spaces are not allowed.\n" RESET_COLOR);
            Hexa_to_Binary();
            return; // Exit the function
        }
    }

    int size = strlen(hexa);

    // Check if the input is not empty and contains only valid hexadecimal characters
    if (size > 0 && is_valid_hex_array(hexa, size))
    {
        printf("\nSolution: \n\n");
        for (int i = size - 1; i >= 0; i--)
        {
            long long int integer = 0;

            if (hexa[i] >= '0' && hexa[i] <= '9')
            {
                integer = hexa[i] - '0';
            }
            else if (hexa[i] >= 'A' && hexa[i] <= 'F')
            {
                integer = hexa[i] - 'A' + 10;
            }
            else if (hexa[i] >= 'a' && hexa[i] <= 'f')
            {
                integer = hexa[i] - 'a' + 10;
            }
            else
            {
                printf(RED "\nInvalid hexadecimal number.\n" RESET_COLOR);
            }
            product = integer * pow(16, place);
            printf("%lld x 16^%lld = %lld\n", integer, place, product);

            total += integer * pow(16, place);
            place++;
        }

        printf("\nAdd all the products.\n");
        printf("The decimal equivalent of %s is %lld\n", hexa, total);

        int remainder = 0, a = 0;
        float division = 0;
        char binary[100];

        printf("\nR represents the remainder\n\n");

        if (total > 0)
        {
            while (total)
            {
                remainder = total % 2;
                division = total / 2.0;
                if (division <= 99)
                {
                    printf("%lld / 2 =  %.1f\t | R:%d\n", total, division, remainder);
                }
                else
                {
                    printf("%lld / 2 =  %.1f |R:%d\n", total, division, remainder);
                }

                total = total / 2;
                binary[a++] = remainder + '0'; // Store the binary digit as character
            }
            int start = 0;
            int end = a - 1;
            while (start < end)
            {
                char temp = binary[start];
                binary[start] = binary[end];
                binary[end] = temp;
                start++;
                end--;
            }
        }
        printf("\nArrange the remainders from bottom to top to get the base 2\n");
        printf(GREEN "\nThe binary equivalent of %s is %s" RESET_COLOR, hexa, binary);
    }
    else
    {
        printf(RED "\nInvalid Base 16 Input!\n");
        printf("Base 16 numbers only include the positive number 0-9 and letters A-F!\n");
        printf("Try Again!\n" RESET_COLOR);
        Hexa_to_Binary();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Hexadecimal to Octal
void Hexa_to_Octal()
{
    char hexa[100];
    long long place = 0, total = 0, product;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a hexadecimal number: " RESET_COLOR);
    fgets(hexa, sizeof(hexa), stdin);
    hexa[strcspn(hexa, "\n")] = '\0'; // Remove trailing newline

    // Check if the input contains any spaces
    for (int i = 0; hexa[i] != '\0'; i++)
    {
        if (hexa[i] == ' ')
        {
            printf(RED "\nError: Invalid input. Spaces are not allowed.\n" RESET_COLOR);
            Hexa_to_Octal();
            return; // Exit the function
        }
    }

    int size = strlen(hexa);

    // Check if the input is not empty and contains only valid hexadecimal characters
    if (size > 0 && is_valid_hex_array(hexa, size))
    {
        printf("\nSolution: \n\n");
        for (int i = size - 1; i >= 0; i--)
        {
            long long int integer = 0;

            if (hexa[i] >= '0' && hexa[i] <= '9')
            {
                integer = hexa[i] - '0';
            }
            else if (hexa[i] >= 'A' && hexa[i] <= 'F')
            {
                integer = hexa[i] - 'A' + 10;
            }
            else if (hexa[i] >= 'a' && hexa[i] <= 'f')
            {
                integer = hexa[i] - 'a' + 10;
            }
            else
            {
                printf(RED "\nInvalid hexadecimal number.\n" RESET_COLOR);
            }
            product = integer * pow(16, place);
            printf("%lld x 16^%lld = %lld\n", integer, place, product);

            total += integer * pow(16, place);
            place++;
        }

        printf("\nAdd all the products.\n");
        printf("The decimal equivalent of %s is %lld\n", hexa, total);

        int remainder = 0, a = 0;
        float division = 0;
        char octal[100];

        printf("\nR represents the remainder\n\n");

        if (total > 0)
        {
            while (total)
            {
                remainder = total % 8;
                division = total / 8.0;
                if (division <= 99)
                {
                    printf("%lld / 8 =  %.1f\t | R:%d\n", total, division, remainder);
                }
                else
                {
                    printf("%lld / 8 =  %.1f |R:%d\n", total, division, remainder);
                }

                total = total / 8;
                octal[a++] = remainder + '0'; // Store the binary digit as character
            }
            int start = 0;
            int end = a - 1;
            while (start < end)
            {
                char temp = octal[start];
                octal[start] = octal[end];
                octal[end] = temp;
                start++;
                end--;
            }
        }
        printf("\nArrange the remainders from bottom to top to get the base 8\n");
        printf(GREEN "\nThe octal equivalent of %s is %s" RESET_COLOR, hexa, octal);
    }
    else
    {
        printf(RED "\nInvalid Base 16 Input!\n");
        printf("Base 16 numbers only include the positive number 0-9 and letters A-F!\n");
        printf("Try Again!\n" RESET_COLOR);
        Hexa_to_Octal();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Hexadecimal to Base 4
void Hexa_to_Base4()
{
    char hexa[100];
    long long place = 0, total = 0, product;

    printf(MAGENTA "\n------------------------------------------------\n" RESET_COLOR);
    printf(YELLOW "Enter a hexadecimal number: " RESET_COLOR);
    fgets(hexa, sizeof(hexa), stdin);
    hexa[strcspn(hexa, "\n")] = '\0'; // Remove trailing newline

    // Check if the input contains any spaces
    for (int i = 0; hexa[i] != '\0'; i++)
    {
        if (hexa[i] == ' ')
        {
            printf(RED "\nError: Invalid input. Spaces are not allowed.\n" RESET_COLOR);
            Hexa_to_Base4();
            return; // Exit the function
        }
    }

    int size = strlen(hexa);

    // Check if the input is not empty and contains only valid hexadecimal characters
    if (size > 0 && is_valid_hex_array(hexa, size))
    {
        printf("\nSolution: \n\n");
        for (int i = size - 1; i >= 0; i--)
        {
            long long int integer = 0;

            if (hexa[i] >= '0' && hexa[i] <= '9')
            {
                integer = hexa[i] - '0';
            }
            else if (hexa[i] >= 'A' && hexa[i] <= 'F')
            {
                integer = hexa[i] - 'A' + 10;
            }
            else if (hexa[i] >= 'a' && hexa[i] <= 'f')
            {
                integer = hexa[i] - 'a' + 10;
            }
            else
            {
                printf(RED "\nInvalid hexadecimal number.\n" RESET_COLOR);
            }
            product = integer * pow(16, place);
            printf("%lld x 16^%lld = %lld\n", integer, place, product);

            total += integer * pow(16, place);
            place++;
        }

        printf("\nAdd all the products.\n");
        printf("The decimal equivalent of %s is %lld\n", hexa, total);

        int remainder = 0, a = 0;
        float division = 0;
        char base4[100];

        printf("\nR represents the remainder\n\n");

        if (total > 0)
        {
            while (total)
            {
                remainder = total % 4;
                division = total / 4.0;
                if (division <= 99)
                {
                    printf("%lld / 4 =  %.1f\t | R:%d\n", total, division, remainder);
                }
                else
                {
                    printf("%lld / 4 =  %.1f |R:%d\n", total, division, remainder);
                }

                total = total / 4;
                base4[a++] = remainder + '0'; // Store the binary digit as character
            }
            int start = 0;
            int end = a - 1;
            while (start < end)
            {
                char temp = base4[start];
                base4[start] = base4[end];
                base4[end] = temp;
                start++;
                end--;
            }
        }
        printf("\nArrange the remainders from bottom to top to get the base 4\n");
        printf(GREEN "\nThe base 4 equivalent of %s is %s" RESET_COLOR, hexa, base4);
    }
    else
    {
        printf(RED "\nInvalid Base 16 Input!\n");
        printf("Base 16 numbers only include the positive number 0-9 and letters A-F!\n");
        printf("Try Again!\n" RESET_COLOR);
        Hexa_to_Base4();
    }
    printf("\n");

    Tryagain_or_exit();
}

// For Try again or exiting to the main program
void Tryagain_or_exit()
{
    printf("\nTry again [Y/N/E]: ");
    scanf(" %c", &choice);
    getchar();
    printf("\nNote: If Y, return to the previous Conversion. If N, return to the Number System Selection. If E, Exit Program\n");
    if (choice == 'Y' || choice == 'y')
    {
        if (select_1 == 1 && select_2 == 1)
        {
            Binary_to_Binary();
            return;
        }
        else if (select_1 == 1 && select_2 == 2)
        {
            Binary_to_Base4();
            return;
        }
        else if (select_1 == 1 && select_2 == 3)
        {
            Binary_to_Octal();
            return;
        }
        else if (select_1 == 1 && select_2 == 4)
        {
            Binary_to_Decimal();
            return;
        }
        else if (select_1 == 1 && select_2 == 5)
        {
            Binary_to_Hexa();
            return;
        }
        else if (select_1 == 2 && select_2 == 1)
        {
            Base4_to_Binary();
            return;
        }
        else if (select_1 == 2 && select_2 == 2)
        {
            Base4_to_Base4();
            return;
        }
        else if (select_1 == 2 && select_2 == 3)
        {
            Base4_to_Octal();
            return;
        }
        else if (select_1 == 2 && select_2 == 4)
        {
            Base4_to_Decimal();
            return;
        }
        else if (select_1 == 2 && select_2 == 5)
        {
            Base4_to_Hexa();
            return;
        }
        else if (select_1 == 3 && select_2 == 1)
        {
            Octal_to_Binary();
            return;
        }
        else if (select_1 == 3 && select_2 == 2)
        {
            Octal_to_Base4();
            return;
        }
        else if (select_1 == 3 && select_2 == 3)
        {
            Octal_to_Octal();
            return;
        }
        else if (select_1 == 3 && select_2 == 4)
        {
            Octal_to_Decimal();
            return;
        }

        else if (select_1 == 3 && select_2 == 5)
        {
            Octal_to_Hexa();
            return;
        }
        else if (select_1 == 4 && select_2 == 1)
        {
            Decimal_to_Binary();
            return;
        }
        else if (select_1 == 4 && select_2 == 2)
        {
            Decimal_to_Base4();
            return;
        }
        else if (select_1 == 4 && select_2 == 3)
        {
            Decimal_to_Octal();
            return;
        }
        else if (select_1 == 4 && select_2 == 4)
        {
            Decimal_to_Decimal();
            return;
        }
        else if (select_1 == 4 && select_2 == 5)
        {
            Decimal_to_Hexa();
            return;
        }
        else if (select_1 == 5 && select_2 == 4)
        {
            Hexa_to_Decimal();
            return;
        }
        else if (select_1 == 5 && select_2 == 1)
        {
            Hexa_to_Binary();
            return;
        }
        else if (select_1 == 5 && select_2 == 2)
        {
            Hexa_to_Base4();
            return;
        }
        else if (select_1 == 5 && select_2 == 3)
        {
            Hexa_to_Octal();
            return;
        }
        else if (select_1 == 5 && select_2 == 5)
        {
            Hexa_to_Hexa();
            return;
        }
    }
    else if (choice == 'N' || choice == 'n')
    {
        Main_Program();
    }
    else if (choice == 'E' || choice == 'e')
    {
        exit(0);
    }
    else
    {
        printf("Invalid Choice!");
    }
}