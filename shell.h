


//Basic loop of a shell
extern void my_shell_loop();

//Read input strings 
extern char *my_shell_read_string();

//Split input strings into args
extern char **my_shell_split_args(char *line);

//Execute the cmd input from users
extern int my_shell_execute(char **args);

//Launch the cmd if it's not internal cmd
extern int my_shell_launch(char **args);

//Internal cmd cd
extern int inner_function_cd(char **args);

//Internal cmd exit
extern int inner_function_exit(char **args);