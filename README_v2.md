<center><h1>Technical Readme of my approach to the project in progress - Bugs and Fixes - Stephen Omoregie.</h1> </center>

## Bug 1
- 😫 Problem: Emulating the same error output as the Thompson Shell
	- I had previously used `perror(argv[0]`); to print error to the stderr. However this was limited in terms of cusomizing the message further as I'd want (i.e: `./hsh: 1: /bin/tth: not found`).
- ✅ Solution: I created a custom err_msg function that receives multiple arguments (see file - `99-err_msg.c`), this allowed me to pass in the file descriptor, command count, name of the command and the custom message. 


## Bug 2
- 😫 Problem:  Memory Leaks for every time that the ENTER key is pressed multiple times and no command (i.e \n \n \n \n).
- ✅ Solution: 


## Bug 3
- 😫 Problem: Memory Leaks when command is not found
- ✅ Solution: 

## Bug 4:
- 😫 Problem: Duplicate Execution of command when (Having implemented PATH - to enable global execution of commands).
- ✅ Solution: 