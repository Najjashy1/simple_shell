#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char input[MAX_INPUT];

	while (1)
	{
	    printf("$ ");
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		printf("\nExiting the shell...\n");
	    break;
	}
	input[strcspn(input, "\n")] = '\0';

	if (strlen(input) == 0)
	{
		continue;
	}
	char *args[MAX_INPUT];
	char *token;
	int arg_count = 0;
	
	token = strtok(input, " ");
	while (token != NULL)
	{
		args[arg_count++] = token;
	    token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
	    exit(EXIT_FAILURE);
	} else if (pid == 0);

		if (execvp(args[0], args) == -1)
		{
			printf("Command not found: %s\n", args[0]);
		exit(EXIT_FAILURE);
		}
	} else
	{
		int status;
	    waitpid(pid, &status, 0);
	}
    }

    return (0);
}

