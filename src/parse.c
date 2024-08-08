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

bool	void_chars(char	*input)
{
	int	i = 0;
	while (input[i])
	{
		if (!ft_isalpha(input[i]))
		{
			printf("Has introducido caracteres no validos\n");
			return (true);
		}
		i++;
	}
	return (false);
}