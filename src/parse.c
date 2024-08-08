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

bool	parse(char *input, const char *word)
{
	if (long_word(input, word) == true)
		return (true);
	if (forbidden_chars(input) == true)
		return (true);
	to_lower(input);
	return (false);
}