#include "../include/wordle.h"

void	to_lower(char *input)
{
	int	i = 0;

	while (input[i])
	{
		input[i] = ft_tolower(input[i]);
		i++;
	}
}

bool	forbidden_chars(char	*input)
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