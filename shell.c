#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "shell.h"		  //delimiter are whitespace tab and a new line

#define BUFFER_SIZE 64
#define TOKEN_DELIMITER " \t\n"


void my_shell_loop(){
  char *line;							// input string
  char **args;							// string arguments
  int status = 1;						// initial status

  while (status){						// keep doint until status changes
	printf("JoesShell% ");			
	line = shell_read_string();			// read string from keyboard
	args = shell_split_args(line);		// split args from input string
	status = shell_execute(args);		// record status of program
  }
   						
}



char *my_shell_read_string(){
  char *string = NULL;
  size_t input_size = 0; 			
  getline(&string, &input_size, stdin);		/* getline() function dynamiclly allocate memory for input string,
											,and stores strings and size of strings. Also getline will automatically 
											enlarge the block of memory as needed */
  return string;
}


char **my_shell_split_args(char *line){
  int buffer_size = BUFFER_SIZE; 								//can store 64 args
  int size = 0;													//current size of args
  char *token;
  char **tokens = malloc(buffer_size * sizeof(char*));			/* tokens stores pointers pointing to args
																allocate memory for 64 args of pointer */
  

  if (tokens == NULL) {
    printf("fail to allocate memory\n");
    exit(0);
  }
  token = strtok(line, TOKEN_DELIMITER);						//get the first token
  
  
  while (token != NULL) {								
    tokens[size] = token;
    size++;

	// if there are more than 64 args, then reallocate more memory for tokens
    if (size >= buffer_size) {
      buffer_size += BUFFER_SIZE								//double the buffer_size
      tokens = realloc(tokens, bufsize * sizeof(char*));		//allocate more memory
      if (!tokens) {
        printf("fail to allocate memory\n");
        exit(0);
      }
    }

    token = strtok(NULL, TOKEN_DELIMITER);				//walk through all the tokens
  }
  tokens[size] = NULL;								    //place null at the end of tokens
  
  return tokens;
}

int my_shell_execute(char **args){
  int i = 0;

  if (args[0] == NULL) {
    // If nothing is entered, just return 1 
    return 1;
  }

  for (i; i < 2; i++) {
    if(strcmp(args[0], builtin_str[i]) == 0) 			//check if a input cmd is internal cmd or not
		return (*internal_function[i])(args);		
  }

  return shell_launch(args);							//not a internal cmd, run this cmd
}



int my_shell_launch(char **args)
{
  pid_t pid;
  pid_t wait_pid;
  int status;

  pid = fork();
  if (pid == 0) {
    //If pid = 0, it's a child process, then call execvp
    if (execvp(args[0], args) == -1) {			/*  execvp will not return anything if it success, 
													but a -1 will be returned  if execvp is unsucessful */
      perror("execvp fail");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // forking process fail
    perror("forking fail");
  } else {
    // Parent process wait for child process to terminated
    do {
      wait_pid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));	//once children process terminated successfully, return 1
  }

  return 1;
}



/*
  Two internal functions 
 */
char *inner_function_str[] = {"cd", "exit"};

/* 
	Array of function pointers 
*/
int (*internal_function[]) (char **) = {&inner_function_cd,&inner_function_exit};


/*
  Internal function cd 
*/
int inner_function_cd(char **args)
{
  if (args[1] == NULL) {
    perror("need directory name to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {				// if chdir success, 1 will be retured
      perror("cd function fail");
    }
  }
  return 1;
}



int inner_function_exit(char **args)
{
  return 0;
}


