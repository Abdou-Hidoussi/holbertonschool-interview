#include "regex.h"

/**
 * wildcmp - compares two strings
 * @s1: string
 * @s2: string
 * Return: 1 if match, 0 if not
 */
int wildcmp(char const  *s1, char const  *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2 && *(s2 + 1) != '*')
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '.' && *(s2 + 1) != '*')
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	if (*(s2 + 1) == '*')
		return (wildcmp(s1, s2 + 2) || wildcmp(s1 + 1, s2));
	return (0);
}
/**
 * regex_match - Match a string with a regex
 * @str: String to match
 * @pattern: Regex to match
 * Return: 1 if match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	return (wildcmp(str, pattern));
}
