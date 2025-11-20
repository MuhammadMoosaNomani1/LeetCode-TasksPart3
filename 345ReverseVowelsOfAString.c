#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char *reverseVowels(char *s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        while (left < right && !isVowel(s[left]))
        {
            left++;
        }
        while (left < right && !isVowel(s[right]))
        {
            right--;
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    return s;
}

int main()
{
    char s[1000];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0';
    printf("Original String is %s\n", s);
    printf("Reversed String is %s", reverseVowels(s));
    return 0;
}