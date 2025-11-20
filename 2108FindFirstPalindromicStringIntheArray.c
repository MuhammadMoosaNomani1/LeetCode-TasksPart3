#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isPalindrome(const char *s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return 0;
        left++, right--;
    }
    return 1;
}

char *firstPalindrome(char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++)
    {
        if (isPalindrome(words[i]))
        {
            return words[i];
        }
    }
    return "";
}

int main()
{
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char temp[101];
    char (*storage)[101] = malloc(n * sizeof(*storage));
    char *words[n];

    printf("Enter the words: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", storage[i]);
        words[i] = storage[i];
    }

    char *result = firstPalindrome(words, n);

    if (strlen(result) == 0)
    {
        printf("Output: \"\"\n");
    }
    else
        printf("Output: \"%s\"\n", result);

    free(storage);
    return 0;
}