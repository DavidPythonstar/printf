#include "main.h"

/**
 * _strlen - counts letter in a strings
 * @s: string to count
 * Return: Number of words in string
 */

int _strlen(char *s)
{
        int counter = 0;
        int i = 0;

        while (s[i] != '\0')
        {
                i++;
                counter++;
        }
        return (counter);
}
