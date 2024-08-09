#include "../include/wordle.h"

/* void	check_corrects(char	*input, const char	*word)
{
	int		i = 0;
	int		j;
	int		k = 0;
	char	*buffer = (char *)ft_calloc(ft_strlen(word) + 1, 1);
	bool	correct = false;
	bool	displaced = false;
	//bool	already_in_buffer;

	while (input[i])
	{
		//already_in_buffer = false;
		j = 0;
		while (word[j])
		{
			if (ft_toupper(input[i]) == ft_toupper(word[i]))
			{
				printf("i = %i\n", i);
				printf("j = %i\n", j);
				printf(GREEN "%c" RESET, input[i]);
				buffer[k] = input[i];
				printf("buffer = %s\n", buffer);
				break;
			}
			j++;
		}
		j = 0;
		if (correct == false)
		{
			while (word[j])
			{
				if (i != j && ft_toupper(input[i]) == ft_toupper(word[j]))
				{
					printf("i = %i\n", i);
					printf("j = %i\n", j);
					printf(YELLOW "%c" RESET, input[i]);
					buffer[k] = input[i];
					printf("buffer = %s\n", buffer);
					break;
				}
				j++;
			}
		}
		i++;
	}
} */

void	check_corrects(char	*input, const char	*word)
{
	int		i = 0;
	int		j;
	int		k = 0;
	char	*buffer = (char *)ft_calloc(ft_strlen(word) + 1, 1);
	//bool	already_in_buffer;

	while (input[i])
	{
		//already_in_buffer = false;
		j = 0;
		while (word[j])
		{
			if (ft_toupper(input[i]) == ft_toupper(word[i]))
			{
				printf("i = %i\n", i);
				printf("j = %i\n", j);
				printf(GREEN "%c" RESET, input[i]);
				buffer[k++] = i + 48;
				printf("\nbuffer = %s\n", buffer);
				break;
			}
			while (ft_strchr(buffer, j + 48) != NULL && j < (int)ft_strlen(word))
			{
				printf("Entre!!\n");
				j++;
			}
			if (ft_toupper(input[i]) == ft_toupper(word[j]) && i != j)
			{
				// k = 0;
				// while (buffer[k])
				// {
				// 	if (ft_toupper(input[i]) == ft_toupper(buffer[k]))
				// 	{
				// 		already_in_buffer = true;
				// 		break ;
				// 	}
				// 	k++;
				// }
				// if (already_in_buffer == true)
				// 	break;
				printf("i = %i\n", i);
				printf("j = %i\n", j);
				printf(YELLOW "%c" RESET, input[i]);
				//buffer[k++] = i + 48;
				printf("\nbuffer = %s\n", buffer);
				break;
			}
			else if (ft_toupper(input[i]) != ft_toupper(word[j]))
			{
				printf("i = %i\n", i);
				printf("j = %i\n", j);
				printf("%c", input[i]);
				//buffer[k++] = i + 48;
				printf("\nbuffer = %s\n", buffer);
				break;
			}
			j++;
		}
		i++;
	}
}