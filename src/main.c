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
	printf("\nCaught signal %d (Ctrl-\\). Dumping core and exiting...\n", sig);
	clear_history();
	signal(sig, SIG_DFL); // Restaurar el comportamiento por defecto
	kill(getpid(), sig); // Enviar la señal nuevamente
}

int	main(void)
{
	int			i = 5;
	char		*input;
	char		*input_trimed;
	const char	*word = "hola";

	while (i)
	{
		// Configurar los manejadores de señal
		signal(SIGINT, signal_sigint);
		signal(SIGQUIT, signal_sigquit);
		printf("Número de intentos restantes ==> %i\n", i);
		input = readline("Introduce tu palabra: \n");
		if (!input)
		{
			// Detectar Ctrl-D (EOF)
			printf("\nCaught EOF (Ctrl-D). Exiting...\n");
			break ;
		}
		if (input[0] != '\0')
			add_history(input);

		// Procesar la entrada del usuario
		// OJO: ft_strtrim utiliza malloc!!!!!
		input_trimed = ft_strtrim(input, " ");
		free(input);
		if (void_chars(input_trimed) == true)
			continue;
		to_lower(input_trimed);
		printf("Has introducido --> %s\n", input_trimed);
		if (strcmp(input_trimed, word) == 0)
		{
			printf("¡Has ganado!\n");
			free(input_trimed);
			exit (0);
		}
		free(input_trimed); // Liberar la memoria asignada por ft_strtrim
		i--;
	}
	printf("Has perdido\n");
	return (0);
}
