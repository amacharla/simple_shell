#include "shellHeader.h"

char **tokenize(char *string, const char *delimiter)
{
	char **tokens, *token, *arguments;
	size_t i, numtokens = 1;

	/* duplicates string so we can manipulate it*/
	arguments = _strdup(string);
	if (arguments == NULL)
		return (NULL);
	/*go through string and count the delimiters*/
	for(i = 0; arguments[i]; i++)
		if (arguments[i] == *delimiter)
			numtokens++;
	/*allocate space in char *array  to hold tokens from string*/
	tokens = malloc(sizeof(char *) * (numtokens + 1));
	if (tokens == NULL)
		return (NULL);
	/*get each token and store it in char *array*/
	token = strtok(arguments, delimiter);
	for(i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;

	return (tokens);

}
/**
 * _addpath - adds path to filname
 * @first: pointer to path
 * @second: pointer to filename
 * Return: pointer to merged string or NULL if fails
 */
char *_addpath(char *first,char *second)
{
        int i, j, k;
        char *new;

        for (i = 0; first[i]; i++)
                ;
        for (j = 0; second[j]; j++)
		;
        k = i + j + 1;
        new = (char *) malloc(k * sizeof(char));
        if (!new)
                return(NULL);
        for (i = 0; first[i]; i++)
		new[i] = first[i];
        new[i] = '/';
        i++;
        for (j = 0; i < k; j++)
	{
		new[i] = second[j];
		i++;
	}
        new[i] = '\0';
	return (new);
}

char *_getenv(char *name)
{
        extern char **environ;
        char *token;
        unsigned int i;

        for(i = 0; environ[i]; i++)
        {
		if (_strncmp(environ[i], name, _strlen(name)))
		{
			/*make space for the VALUE*/
			token = malloc(sizeof(char) * _strlen(environ[i]) - _strlen(name));
			if (!token)
				return (NULL);
			_strcpy(token, environ[i]);
			token = strtok(token, "=");/*cut off key*/
			token = strtok(NULL, "\0");/*get value*/
			return (token);
                }
        }
        return (NULL);
}

int cmdchk(char **line)
{
	extern char **environ;
	int i = 0;
	char **paths, *path = _getenv("PATH"), *cmd;

	if (!path)
		return(-1);
	paths = tokenize(path, ":");
	if (!paths)
		return (-1);
	cmd = _strdup(line[0]);
	while (paths[i])
	{
		line[0] = _addpath(paths[i], cmd);
		if(!access(line[0], F_OK))
			return (1);
		i++;
	}
	return (0);
}