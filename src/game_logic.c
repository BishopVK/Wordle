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

/* void	check_corrects(char	*input, const char	*word)
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
} */

/* static int	check_if_displaced(char	*input, const char	*word, char	*buffer, int i)
{
	char	char_to_find = input[i];
	int		match_in_input = 0;
	int		match_in_word = 0;
	int		match_in_buffer = 0;

	i = 0;
	while (input[i])
	{
		if (input[i] == char_to_find)
			match_in_input++;
		i++;
	}
	//printf("Hay %i letras %c en %s\n", match_in_input, char_to_find, input);

	i = 0;
	while (word[i])
	{
		if (word[i] == char_to_find)
			match_in_word++;
		i++;
	}
	//printf("Hay %i letras %c en %s\n", match_in_word, char_to_find, word);

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == char_to_find)
			match_in_buffer++;
		i++;
	}
	//printf("Hay %i letras %c en %s\n", match_in_buffer, char_to_find, buffer);

	if (match_in_input - match_in_word - match_in_buffer > 0)
		return (0);
	// if (match_in_input > match_in_word)
	// 	return (match_in_word - match_in_buffer);

	return (match_in_word - match_in_buffer);
}

void	check_corrects(char	*input, const char	*word)
{
	int		i = 0;
	int		j;
	int		k = 0;
	char	*buffer = (char *)ft_calloc(ft_strlen(word) + 1, 1);
	bool	correct;
	int		nbr_displaced = 0;
	int		displaced;

	while (input[i])
	{
		correct = false;
		displaced = 0;
		j = 0;
		while (word[j]) // Correct and in place
		{
			if (ft_toupper(input[i]) == ft_toupper(word[i]))
			{
				//printf("i = %i\n", i);
				//printf("j = %i\n", j);
				printf(GREEN "%c" RESET, input[i]);
				//buffer[k++] = i + 48;
				buffer[k++] = input[i];
				//printf("\nbuffer = %s\n", buffer);
				correct = true;
				break;
			}
			j++;
		}
		if (correct == true)
		{
			i++;
			continue;
		}
		j = 0;
		while (word[j]) // Displaced
		{
			// if (buffer[j] != '\0')
			// {
			// 	j++;
			// 	continue;
			// }
			if (ft_toupper(input[i]) == ft_toupper(word[j]) && buffer[j] == '\0')
			{
				//printf("i = %i\n", i);
				//printf("j = %i\n", j);
				nbr_displaced = check_if_displaced(input, word, buffer, i);
				if (nbr_displaced > 0)
				{
					printf(YELLOW "%c" RESET, input[i]);
					buffer[k++] = input[i];
					displaced++;
				}
				//printf("\nbuffer = %s\n", buffer);
				break;
			}
			j++;
		}
		// if (displaced > 0)
		// {
		// 	i++;
		// 	continue;
		// }
		// //printf("i = %i\n", i);
		// //printf("j = %i\n", j);
		// //printf("Entre aquí!\n");
		// printf("%c", input[i]);
		// //printf("\nbuffer = %s\n", buffer);
		// i++;
		if (!correct && !displaced)
			printf("%c", input[i]);
		i++;
	}
	free (buffer);
} */

//THIS WORKS//

#define MAX_LEN 100

void print_colored(char c, const char *color) {
    printf("%s%c\033[0m", color, c);
}

void check_corrects(char *input, const char *word) {
    int len = strlen(word);
    char result[MAX_LEN];
    int marked[MAX_LEN] = {0}; // Array to keep track of marked letters

    // First pass: check for correct positions (green)
    for (int i = 0; i < len; i++) {
        if (input[i] == word[i]) {
            result[i] = 'G'; // G for Green
            marked[i] = 1;
        } else {
            result[i] = ' ';
        }
    }

    // Second pass: check for correct letters in wrong positions (yellow)
    for (int i = 0; i < len; i++) {
        if (result[i] != 'G') {
            for (int j = 0; j < len; j++) {
                if (input[i] == word[j] && !marked[j]) {
                    result[i] = 'Y'; // Y for Yellow
                    marked[j] = 1;
                    break;
                }
            }
        }
    }

    // Print the result with colors
    for (int i = 0; i < len; i++) {
        if (result[i] == 'G') {
            print_colored(input[i], "\033[0;32m"); // Green
        } else if (result[i] == 'Y') {
            print_colored(input[i], "\033[0;33m"); // Yellow
        } else {
            print_colored(input[i], "\033[0;37m"); // White
        }
    }
    printf("\n");
}