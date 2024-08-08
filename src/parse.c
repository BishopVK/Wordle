#include "../include/wordle.h"

bool	long_word(char *input, const char *word)
{
	if (ft_strlen(input) != ft_strlen(word))
	{
		printf(WRONG_LONG);
		return (true);
	}
	return (false);
}

bool	forbidden_chars(char *input)
{
	int	i = 0;
	while (input[i])
	{
		if (!ft_isalpha(input[i]))
		{
			printf(FORBIDDEN);
			return (true);
		}
		i++;
	}
	return (false);
}

void	to_lower(char *input)
{
	int	i = 0;

	while (input[i])
	{
		input[i] = ft_tolower(input[i]);
		i++;
	}
}

void	win(char *input, const char *word)
{
	char	*word_lower;

	word_lower = ft_strdup(word);
	to_lower(word_lower);
	if (strcmp(input, word_lower) == 0)
	{
		printf(WIN);
		printf("La palabra correcta era " YELLOW "%s\n" RESET, word);
		free(input);
		free(word_lower);
		exit (0);
	}
	free(word_lower);
}

bool	parse(char *input, const char *word)
{
	if (long_word(input, word) == true)
		return (true);
	if (forbidden_chars(input) == true)
		return (true);
	to_lower(input);
	win(input, word);
	return (false);
}