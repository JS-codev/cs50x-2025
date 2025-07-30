#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (isalpha(c)) letters++;
        if (c == ' ') words++;
        if (c == '.' || c == '!' || c == '?') sentences++;
    }

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float raw = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(raw);

    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", grade);
}
