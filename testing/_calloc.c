/**
 * _calloc - allocate memory wich has been initialized to zero
 * @nelem: amount of elements
 * @nsize: size depend data type
 * Return: pointer
 */

char *_calloc(int nelem, int nsize)
{
	char *ptr = NULL;
	int i;

	if (nelem == 0 || nsize == 0)
		return (NULL);
	
	ptr = malloc(nelem * nsize);

	if (!ptr)
		return (NULL);
	for (i = 0; i < (nelem * nsize); i++)
		ptr[i] = 0;

return (ptr);
}
