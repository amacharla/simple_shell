#include "shellHeader.h"


int main(int ac, char **av, char **env)
{
	(void)(ac);
	(void)(av);
	int result;
	char *token, *option1, *option2;
	char *tokens[2];

	token = strdup("env");
	//option1 = strdup("*");
	//option2 = strdup("tags1");
	tokens[0] = token;
	tokens[1] = option1;
//	tokens[2] = option2;
	tokens[2] = NULL;

	result = cmdchk(tokens, env);
	_printf("MAIN-Command: %s result: %d\n", tokens[0], result);

	result = specialExec(tokens, env, result);
	_printf("MAIN-options: %s: status:%d\n", tokens[1], result);

	return (0);

}

int cmdchk_main(int ac, char **av, char **env)
{
	(void)(ac);
	(void)(av);
	int result;
	char *token;
	char *tokens[1];

	token = strdup("cp");
	tokens[0] = token;

	result = cmdchk(tokens, env);
	_printf("%s: %d\n", tokens[0], result);

	return (0);

}

int cutspecial_main(void)
{
	char *string = "he\n";
	char *result = strdup(string);

	printf("Before: $%s$", result);
       result = cutspecial(result);
       printf("After: $%s$", result);

       return (0);
}
int _printf_main(void)
{
	_printf("This is test1\n%s\n%d\n", "This is test2", 3);
	return (0);
}
int _alloc_main(void)
{
	char *testmem;
	int count = 0;

	testmem = malloc(sizeof(char*));
	count = _alloc(&testmem, 1);
	printf("alloc count: %d\n", count);

	printf("old size: %d\n", (unsigned int) sizeof(testmem));

	testmem = _realloc(testmem, (unsigned int) sizeof(char *), (unsigned int) sizeof(char *) * 2);

	printf("Realloc size: %d\n", (unsigned int) sizeof(testmem));

	count = _alloc(NULL,-1);
	printf("free alloc count: %i\n", count);

	return (0);

}