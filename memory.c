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
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previously allocated block
 * @size: size of the new block in bytes
 *
 * Return: pointer to the reallocated block of memory,
 * or NULL if the allocation fails or size is 0 and ptr is not NULL.
 */
void *_realloc(void *ptr, size_t size)
{
	char *new_ptr;
	size_t copy_size;

	if (!ptr)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);

	copy_size = sizeof(ptr) < size ? sizeof(ptr) : size;
	_memcpy(new_ptr, ptr, copy_size);

	free(ptr);
	return (new_ptr);
}
/**
 * delete_array - frees a dynamically allocated array of strings
 * @arr: the array of strings to be freed
 */
void delete_array(char **arr)
{

	size_t i, size;

	size = _len(arr);
	if (!arr)
		return;

	for (i = 0; i < size; i++)
	{
		if (arr[i])
			free(arr[i]);
	}

	free(arr);
}
