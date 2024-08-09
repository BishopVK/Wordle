#include "../include/wordle.h"

// Manejador de la señal SIGINT (Ctrl-C)
void	signal_sigint(int sig)
{
	(void)sig;
	//printf("\nCaught signal %d (Ctrl-C). Exiting...\n", sig);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// Manejador de la señal SIGQUIT (Ctrl-\)
void	signal_sigquit(int sig)
{
	printf(MAGENTA "\nCaught signal %d (Ctrl-\\). Dumping core and exiting...\n" RESET, sig);
	clear_history();
	signal(sig, SIG_DFL); // Restaurar el comportamiento por defecto
	kill(getpid(), sig); // Enviar la señal nuevamente
}

int	main(void)
{
	int			i = 5;
	char		*input;
	char		*input_trimed;
	const char	*word = "char";

	while (i)
	{
		// Configurar los manejadores de señal
		signal(SIGINT, signal_sigint);
		signal(SIGQUIT, signal_sigquit);
		printf("\nPalabra a adivinar: " YELLOW "%li letras\n" RESET, ft_strlen(word));
		printf("Número de intentos restantes: " YELLOW "%i\n" RESET, i);
		input = readline(READLINE);
		if (!input) // Detectar Ctrl-D (EOF)
		{
			printf(EOF_MSG);
			exit (0);
		}
		if (input[0] != '\0')
			add_history(input);
		input_trimed = ft_strtrim(input, " ");
		free(input);
		if (parse(input_trimed, word) == true)
		{
			free(input_trimed);
			continue;
		}
		printf("Has introducido --> %s\n", input_trimed);
		check_corrects(input_trimed, word);
		free(input_trimed);
		i--;
	}
	printf(LOSE);
	printf("La palabra correcta era " YELLOW "%s\n" RESET, word);

	// Retry
	/* input = readline(MAGENTA "¿Quieres volver a jugar? (si/no)" RESET);
	input_trimed = ft_strtrim(input, " ");
	free(input);
	to_lower(input_trimed);
	while (1)
	{
		printf("Entre aquí!\n");
		if (ft_strcmp(input_trimed, "si") == 0)
		{
			free(input_trimed);
			main();
		}
		else if (ft_strcmp(input_trimed, "no") == 0)
		{
			free(input_trimed);
			return (0);
		}
		free(input_trimed);
		input = readline(MAGENTA "¿Quieres volver a jugar? (si/no)" RESET);
		input_trimed = ft_strtrim(input, " ");
		free(input);
		to_lower(input_trimed);
	} */
	return (0);
}
