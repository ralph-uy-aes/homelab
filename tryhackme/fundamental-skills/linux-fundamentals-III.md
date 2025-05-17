# Linux Fundamentals III

#### Terminal Text Editors
- Instead of writing to files using echo and pipe or shell operators, we can use text editors much like Window's notepad.
- Two very popular options in UNIX are Vim and Nano
- To create a file with either option, use `nano/vim <filename>`
- In Nano, the interface shows some options in the footer. You can interpret `^` as `ctrl`
    - To exit Nano, `ctrl+x`
- Vim is much more advanced, customizable, portable, etc...
    - To exit Vim... good luck (jk it's `esc` followed by `:q`)

#### Useful Utilities
- To download files from the web via HTTP, use `wget <path/file>`
- To transfer files from your host via SSH, use Secure Copy or SCP
    - Instead of simply `cp` which is local, you can copy files between two different systems using SSH
    - Local to Remote syntax: `scp <file> <username>@<remote>:<path/file>`
    - Remote to Local syntax: `scp <username>@<remote>:<path/file> <file>`
- To host your system as a web server, use Python3's HTTPServer
    - Your system will act like an HTTP server that you can pull files from using `wget`
    - Hosting syntax: `python3 -m http.server` (occupies terminal)
    - Pulling syntax: `wget http://<server ip>:8000/<file>`
    - Since it acts like a web server, there's no indexing. You need to know the exact filename and path of the file you want
    - Updog or other webserver tools can make this process easier

#### Processes 101
- Programs running on the system that are managed by the kernel. Each have a unique process ID (PID) and is auto-incremented by order
- Processes are also known as daemons
- To view processes, use `ps`
    - Append the flag `aux` to see processes of other users and system processes
- To see real-time statistics about processes, use `top`
    - Statistics refresh every 10 seconds or when you use arrow keys
    - For colored output, use `htop`
- To terminate processes, use `kill <PID>`
    - Three signals could be used:
    1. `SIGTERM`: Kill the process, but allow cleanup
    2. `SIGKILL`: Kill the process, don't allow cleanup
    3. `SIGSTOP`: Simply stop or pause a process
- Processes are split up by namespaces which improves security because only similar processes in those namespaces can see other processes in that namespace
    - Namespaces are simply slices of a pizza
- PID 0 is the system's init which provides a way of managing user processes between the OS and user
    - Every succeeding process is a child of daemon PID 0
- Starting processes on boot is great for servers of all kinds
    - Use `systemctl <option> <service>` to interact with the `systemd` daemon
    - The four options are: start, stop, enable, and disable
- Backgrounding a process can be helpful to bypass the occupation of the terminal
    - Commands can be backgrounded by appending `&` after it like `echo Hello &`
    - You can force background already running processes such as scripts by using `ctrl + Z`
        - Common misconception is thinking that you've stopped it, but you only pushed it to the background
        - Confirm this by using `ps aux`
- Foregrounding a process is helpful for bringing back processes to interact with using the command `fg`

#### Automation
- Certain tasks may be scheduled using `cron` processes
- Crontab is one of the boot processes in a system and is responsible for managing cron jobs
    - For Windows, this is Task Scheduler
- A crontab is a special file with formatting recognized by cron
    - 6 Values are required:
    1. `MIN`: minute to execute
    2. `HOUR`: hour to execute
    3. `DOM`: day of the month to execute
    4. `MON`: month to execute
    5. `DOW`: day of the week to execute
    6. `CMD`: command to execute
    - Asterisk values may be used to bypass some values
    - Ex. I want to make a backup everyday at 12 AM or PM: `0 0,12 0 0 0 cp -R /home/minecraft /home/Documents/backup
    - Ex. I want to execute `echo Hi` every 2 hours: `0 */2 * * * echo Hi`
    - Ex. I want to `echo Dinner Time!` every 10 minutes past the hours between 1600-1700: `10 16-17 * * * echo "Dinner Time!"`
    - Ex. I want to do the same above, but do it every 10 minutes between those hours: `*/10 16-17 * * * echo "Dinner Time!"`
    - For an easier time, just use [Cron Tab Generator](https://crontab-generator.org)
- To edit your crontabs, use `crontab -e`

#### Package Management
- When developers want to submit software for community use, they submit it into `apt` and if approved, will be released
- Additional user repositories can be added to your system using `add-apt-repository`
- `apt` contains a lot of tools to remove and install software
- There are many different package managers like `dpkg` or `pacman`, but `apt` auto-updates as it is native
- Integrity of downloads is guaranteed by Gnu Privacy Guard (GPG) keys which are a safety check from the developers that are matched to you system's trusts
    - If mismatched, don't download
    - To download GPG keys, use `wget -q0 - <key> | apt-key add` and then add it to trusted keys
        - Then, use `apt update`

#### Logs
- Within `/var/log`, you can find log files.
- These show logs for different services and applications
- Great for monitoring system and application health
- Helpful for monitoring intrusions and diagnosing performance issues