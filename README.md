## minishell

The minishell project is a simplified Unix shell written in C, inspired by bash. The goal was to recreate core shell functionalities, including command execution, pipes, redirections, and process management.

### **Key Features**:

**Command Parsing:**
-  Handles arguments, quotes, environment variables ($PATH, etc.).

**Process Execution:** 
-  Uses fork(), execve(), and waitpid() to run programs.

**Pipes & Redirections:**
-  Supports | (pipes), >, <, >> for I/O operations.

**Signal Handling:** .
-  Responds to Ctrl-C (SIGINT) and Ctrl-\ (SIGQUIT).

**Built-in Commands:**
-  Implements basic functions like cd, echo, export, unset, env, and exit.