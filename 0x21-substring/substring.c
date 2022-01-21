#include "substring.h"


/**
* find_substring - finds all the possible substrings
* @s: string
* @words: array
* @nb_words: number of the elements in an array
* @n: address to store number of the elements
* Return: allocated array or NULL
*/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, wlen, j, i = 0, k;
	int *element, *found;

	if (!s)
		return (NULL);

	*n = 0;
	len = strlen(s);
	wlen = strlen(words[0]);

	found = malloc(nb_words * sizeof(int));
	element = malloc(len * sizeof(int));

	while (i <= len - nb_words * wlen)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 && strncmp(s + i + j * wlen, words[k], wlen) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			element[(*n)++] = i;
		i++;
	}
	free(found);
	return (element);
}
