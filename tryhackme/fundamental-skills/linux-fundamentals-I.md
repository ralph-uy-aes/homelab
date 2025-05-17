# Linux Fundamentals I

#### What is Linux?
- One of the most popular operating systems in the world, used in many different devices, websites, cars, etc...
- It is an umbrella term for many different operating systems **based on UNIX** (distributions or distros)
- Open-source, therefore highly versatile
- Lightweight and Portable, therefore you don't need much to run it
	- Due to this, sometimes you don't even get a GUI, only a terminal
- Ex. Ubuntu and Debian

#### Basic Commands 
- These are the muscle memory commands that any self-respecting linux user should know by heart
1. `echo`: Outputs or "echoes" what ever text you provide
2. `whoami`: Outputs which user you're logged in as
3. `ls`: Lists all directories
4. `cd`: Change directory
5. `cat`: Output contents of a file (concatenate)
	- To get a scrollable `cat` just use `less`
6. `pwd`: Output your current directory

#### Intermediate Commands
- These are more complex commands that need parameters or options to be fully useful
1. `find`: Finds a file in any directory specified
	- `-name <filename>` : Specify the name of the file, you can use `*.ext` to specify all `*` files with the `ext`ension specified
2. `grep`: Finds whatever you specify within files or directories

#### Linux Shell Operators
1. `&`: Allows you to run commands in the background
2. `&&`: Allows you to combine multiple commands together in one line
3. `>`: Redirector, takes output from one command and direct it elsewhere
	- `echo <content> > <file>`: Puts the content into whatever file is specified (overwrites)
4. `>>`: The same as `>`, but appends the output instead of overwriting