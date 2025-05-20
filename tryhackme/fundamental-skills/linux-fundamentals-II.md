# Linux Fundamentals II

#### Secure Shell (SSH)
- A protocol for connecting to and interacting with the cli of a remote Linux machine
- Encrypted form protocol
    - Any input sent in a human-readable format is encrypted for network travel
    - Unencrypted upon reaching the remote machine
- Allows remote command execution
- Syntax: `ssh <username>@<remote machine ip>`

#### Flags and Switches
- Commands can often be used standalone like `ls`
    - This lists all files in the directory, but is limited to visible files only
- However, we can use flags and switches to extend its functionality
    - `<command> -<argument>` is a generic form of this application
    - One of the most common arguments for a lot of commands is `-h` or `--help` which brings up a concatenated version of manual
        - However, `-h` can also be the flag for human-readable output
    - If you want to open the manual, `man <command>` is the syntax for that

#### Filesystem Commands
- These commands are used to interact with the filesystem over the terminal
1. `touch`: Create a file
    - Append a filename to create a blank file. Edit contents with `echo` or using a text editor.
2. `mkdir`: Create a directory
    - Append a name to create an empty directory.
3. `cp`: Copy a file or directory
    - First argument is the name of the existing file. Second argument is the name of the new file.
4. `mv`: Move a file or directory
    - First argument is the name of the existing file. Second argument is the name of the new file.
5. `rm`: Remove a file or directory
    - For removing directories, the flag `-R` is required for recursive removal.
6. `file`: Determine the type of a file
    - Very important in CTFs

#### Permissions 101
- In UNIX-based OS, some files and folders are only accessible to certain groups or users
- To show this in a neat way, use `ls -l`
- The first three columns show the access constraints or the permissions
- The permissions are formatted as 10 slots: `----------`
    - It is ordered in 'ugo' meaning user, group, and other
    - `r` means read
    - `w` means write
    - `x` means execute
    - The first slot simply shows `d` if it is a directory and `-` if it is a file
- You can switch to a different user by using the substitute user command `su`
    - Either be root or sudo user or have two requirements to successfully run this command:
        1. Username
        2. Password
    - You can use flags to change shells or specify commands on login
    - The `-l` flag simulates a real login instead of substitution and takes you to the home directory of that user

#### Common Directories
1. `/etc`
    - One of the most important root directories
    - Location for system files used by the OS
    - `sudoers` contains a list of users and groups that can run `sudo`
    - `passwd` and `shadow` show how the system stores passwords for each user using `sha512`. Very powerful when you have root privilege
    - `/etc` must be protected
2. `/var`
    - 'var' is actually short for variable data
    - Stores data that is frequently accessed or written by services and applications on the system
    - Log files can be found in `/var/log`
    - Also has data that aren't explicitly associated with specific users
3. `/root`
    - The `/home` for the root user
    - Think the admin's office
4. `/tmp`
    - 'tmp' is short for temporary
    - Volatile and stores data only needed to be accessed once or twice
    - As soon as the system is restarted, `/tmp` is wiped
    - Kind of like a cache
    - Any user can write to this directory by default, very helpful for pen-testing and scripting

#### Summary
- I learned about SSH, flags and switches, filesystem commands, common directories, permissions and access control. Overall, very fundamental and was full of things that new Linux users should be familiar with.
