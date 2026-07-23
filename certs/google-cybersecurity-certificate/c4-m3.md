# Course 4 – Module 3: Linux Commands in the Bash Shell

## Navigation and File Reading

### Filesystem Hierarchy Standard (FHS)
- **Root directory** – `/` (top‑level, all subdirectories branch off).
- **Common directories**:
  - `/home` – user home directories.
  - `/bin` – binary/executable files.
  - `/etc` – system configuration files.
  - `/tmp` – temporary files (often targeted by attackers).
  - `/mnt` – mount point for media (USB, hard drives).
- **File paths**:
  - **Absolute** – full path from root (e.g., `/home/analyst/projects`).
  - **Relative** – path from current directory (`.` for current, `..` for parent).
  - Tilde (`~`) represents the user’s home directory.

### Navigation Commands
| Command | Purpose |
|---------|---------|
| `pwd` | Print working directory (absolute path). |
| `ls` | List files/directories in current or specified path. Options: `-a` (show hidden), `-l` (show permissions/details), `-la` (both). |
| `cd` | Change directory. `cd ..` goes up one level. |
| `whoami` | Display current username. |

### Reading File Content
| Command | Purpose |
|---------|---------|
| `cat` | Display entire file content. |
| `head` | Show first 10 lines (use `-n` to specify number). |
| `tail` | Show last 10 lines. Useful for recent log entries. |
| `less` | Display file one page at a time – use arrow keys, space (next page), `b` (back), `q` (quit). |

---

## Filtering and Searching

- **`grep`** – Search for a text string in a file.  
  *Example:* `grep "error" server_logs.txt` – outputs lines containing "error".
- **Piping (`|`)** – Send output of one command as input to another.  
  *Example:* `ls | grep "Q1"` – list files containing "Q1".
- **`find`** – Search for files/directories based on criteria.
  - `-name` (case‑sensitive) and `-iname` (case‑insensitive). Use wildcards: `*log*`.
  - `-mtime` – last modified time in days (e.g., `-mtime -3` = within 3 days).
  - `-mmin` – same in minutes.

---

## Managing Files and Directories

### Creating, Removing, Moving, Copying
| Command | Purpose |
|---------|---------|
| `mkdir` | Create a new directory. |
| `rmdir` | Remove an **empty** directory. |
| `touch` | Create an empty file. |
| `rm` | Delete a file (use with caution; hard to recover). |
| `mv` | Move or rename a file/directory. |
| `cp` | Copy a file/directory (keeps original). |

### Editing with `nano`
- Open a file: `nano filename.txt` (create if not exists).
- Save: `Ctrl + O`, then `Enter`. Exit: `Ctrl + X`.

### Redirection Operators
- `>` – Overwrites file content with command output.  
  *Example:* `echo "New text" > file.txt`
- `>>` – Appends output to the end of the file.  
  *Example:* `echo "Add this" >> file.txt`

---

## Permissions and Authorization

### Permission Types and Owners
- **Permission letters** – `r` (read), `w` (write), `x` (execute).
- **Owner types** – `u` (user/owner), `g` (group), `o` (other).

### Viewing Permissions
- `ls -l` – displays 10‑character string:
  - 1st char: `d` (directory) or `-` (file).
  - Next 3: user permissions.
  - Next 3: group permissions.
  - Last 3: other permissions.

### Changing Permissions with `chmod`
Syntax: `chmod [who][+/-/=][permissions] file`
- `+` adds, `-` removes, `=` sets exactly.
- *Example:* `chmod g-rw bonus.txt` – removes read/write from group.
- *Example:* `chmod u+rwx,g+rx,o=r file` – sets user read/write/execute, group read/execute, other read.

### Changing Ownership with `chown`
- Change user owner: `sudo chown fgarcia file.txt`
- Change group owner: `sudo chown :security file.txt` (colon before group).

---

## User Management (Requires `sudo`)

| Command | Purpose |
|---------|---------|
| `useradd` | Add new user. Options: `-g` primary group, `-G` supplemental groups. |
| `usermod` | Modify existing user. `-g` changes primary group, `-aG` appends to supplemental group. Also `-d` (home), `-l` (login), `-L` (lock). |
| `userdel` | Delete user. Add `-r` to remove home directory. |
| `chown` | Change file/directory ownership (see above). |

### `sudo` (Super User Do)
- Grants temporary elevated privileges; safer than logging in as root.
- Always use `sudo` when adding/removing users or modifying system files.

---

## Getting Help in Linux

| Command | Purpose |
|---------|---------|
| `man` | Display the manual page for a command (detailed). *Example:* `man chown`. |
| `whatis` | Show a one‑line description of a command. *Example:* `whatis nano`. |
| `apropos` | Search manual page descriptions for a keyword. *Example:* `apropos -a create group` finds commands related to creating groups. |

*Online resources like the Unix & Linux Stack Exchange are also valuable.*

---

## Key Linux Commands Reference (Quick List)

| Command | Description |
|---------|-------------|
| `pwd` | Print current directory |
| `ls -la` | List all files with details |
| `cd` | Change directory |
| `cat` | Display file content |
| `head/tail` | Show start/end of file |
| `less` | Page through file |
| `grep` | Search for text in files |
| `find` | Locate files/directories |
| `mkdir` | Create directory |
| `rmdir` | Remove empty directory |
| `touch` | Create empty file |
| `rm` | Delete file |
| `mv` | Move/rename |
| `cp` | Copy |
| `nano` | Edit file in terminal |
| `chmod` | Change permissions |
| `chown` | Change ownership |
| `useradd` | Add user |
| `usermod` | Modify user |
| `userdel` | Delete user |
| `sudo` | Run as superuser |
| `man` | Manual page |
| `whatis` | Short description |
| `apropos` | Search man pages |