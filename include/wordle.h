// DEFINES

//libft
#include "libft/libft.h"

//max int y min int
#include <stdint.h>
#include <limits.h>

// printf, readline, perror
#include <stdio.h>

// rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
#include <readline/readline.h>
#include <readline/history.h>

// malloc, free, exit, getenv
#include <stdlib.h>

// write, access, read, close, fork, getcwd, chdir, unlink, execve, dup, dup2,
// pipe, isatty, ttyname, ttyslot, tcsetattr, tcgetattr
#include <unistd.h>

// open, stat, lstat, fstat
#include <sys/stat.h>
#include <fcntl.h>

// wait, waitpid, wait3, wait4
#include <sys/wait.h>

// signal, sigaction
#include <signal.h>

// opendir, readdir, closedir
#include <sys/types.h>
#include <dirent.h>

// strerror
#include <string.h>

// ioctl
#include <sys/ioctl.h>

// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <curses.h>
#include <term.h>

// Secuencias de escape ANSI para colores
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

// DEFINES
#define READLINE "Introduce tu palabra: "
#define WIN CYAN "\nHAS GANADO\n" RESET
#define LOSE RED "\nHAS PERDIDO\n" RESET
#define FORBIDDEN RED "Has introducido caracteres inválidos\n" RESET
#define WRONG_LONG RED "Número de letras incorrecto\n" RESET
#define EOF_MSG MAGENTA "\nCaught EOF (Ctrl-D). Exiting...\n" RESET

// STRUCTURES
typedef enum s_bool
{
	t_false,
	t_true,
}	t_bool;

/*_____           _        _                         
 |  __ \         | |      | |                        
 | |__) | __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
 |  ___/ '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
 | |   | | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
 |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
                                __/ | |              
                               |___/|_|            */

//////////////////////////////////////////////////////
//						MAIN.C						//
//////////////////////////////////////////////////////
void	signal_sigint(int sig);
void	signal_sigquit(int sig);

//////////////////////////////////////////////////////
//						PARSE.C						//
//////////////////////////////////////////////////////
bool	long_word(char *input, const char *word);
bool	forbidden_chars(char *input);
void	to_lower(char *input);
bool	parse(char *input, const char *word);

//////////////////////////////////////////////////////
//					GAME_LOGIC.C					//
//////////////////////////////////////////////////////
void	check_corrects(char *input, const char *word);