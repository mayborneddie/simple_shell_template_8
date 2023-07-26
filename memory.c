#include "shell.h"

/**
 * _memchr - locate a character in a block of memory
 * @s: pointer to the memory block to search
 * @c: the character to search for
 * @n: the number of bytes to search
 *
 * Return: a pointer to the first occurrence of @c in @s,
 * or NULL if not found
 */
void *_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
	}

	return (NULL);
}

/**
 * _memcpy - copy memory area
 * @dest: pointer to the destination buffer
 * @src: pointer to the source buffer
 * @n: the number of bytes to copy
 *
 * Return: a pointer to the destination buffer
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;
	size_t i;

	for (i = 0; i < n; i++)
		d[i] = s[i];

	return (dest);
}
