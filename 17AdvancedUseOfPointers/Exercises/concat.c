
/* Concatenate two strings without changing either one.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *concat (const char *s1, const char *s2)
{
    char *result;

    result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL)
    {
       printf("Error: memory allocation failed.\n");
       exit(EXIT_FAILURE); 
    }
        
    else
    {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

int main (void)
{
    char s1[100], s2[100], *result;

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin); // fgets retains the \n that the user typed.
    s1[strcspn(s1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin); // fgets retains the \n that the user typed.
    s2[strcspn(s2, "\n")] = '\0';

    result = concat(s1, s2);
    printf("Concatenated string: %s\n", result);

    free(result);

    return 0;
}