#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool invalid_key(string key);
char substitute(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || invalid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Validate the substitution key
bool invalid_key(string key)
{
    if (strlen(key) != 26)
    {
        return true;
    }

    bool seen[26] = { false };

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }

        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return true; // Duplicate letter
        }
        seen[index] = true;
    }

    return false;
}

// Perform substitution for each character
char substitute(char c, string key)
{
    if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    else if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    else
    {
        return c;
    }
}
