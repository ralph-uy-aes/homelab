# Lecture 8C: Making Address Spaces Smaller
  
#### Smaller Address Spaces
- Having small address spaces is always good
- Technique 1: Dynamic Memory Allocation in your programs
    - Ask programs to tell the OS exactly how much memory they need when they need it (malloc, new) so we don't always allocate the maximum allowed RAM to each process
- Lets see other techniques

#### Dynamic Loading
- Simple idea: Only load code/text when it's needed
- Done by code written by the programmer for this purpose
    - OS is not involved, but provides tools to make dynamic loading possible
- Supported in all programming languages/OSes
    - C/C++:
        - POSIX: dlopen, dlsym
        - Windows: LoadLibrary
    - Python:
        - import
    - java:
        - ClassLoader
- Same idea as dynamic memory allocation, but for code
    - Call malloc() if i need some bytes
    - Dynamically load some code if needed


#### Static Linking
- Historical way of reusing code
    - Add assembly code of useful functions form a library to your own executable

#### Dynamic Linking
- OS loads code automatically and different running programs can share the code
- Code is shared in shared libraries
    - libc.so in Linux
    - MSVCRT.DLL for windows

#### Shared Libraries
- When dynamic linking is enabled, linker just puts a stub in binary for each shared library routine reference
- Stub is a piece of code that
    - Checks whether the routine tis loaded in memory
    - Otherwise, loads it into memory shared
    - Replaces itself with a simple call to the routine
    - First call is expensive, all future calls will be for free
- Chances are when you run HelloWorld, code of printf is already in memory because some other programs has used it before you

#### Easy Updates
- How come when you update your system, you don't have to recompile all your executables?
- Provided APIs have not changed, you can just:
    - Replace a shared library by a new one
    - Ask system to reload it
    - Magically works
    - If update was critical, a reboot may be required
- Dynamic Linking requires help from the OS
    - Break memory isolation and allow shared text segments among processes

#### Shared Library Usage
- Linux: `ldd` prints shared libraries required by a program
- In Linux, you can easily override functions from loaded shared libraries by creating yourself a small shared library

#### Example: C and Memory Leaks
- In C, you can allocate/free memory with malloc() and free()
- It would be great if somehow the code counted calls to `malloc()` and `free()`
- We need to override something, see the slides for the demo lol
- Moral of the story: if you're not happy with a function in a standard lib, you can rewrite and replace on the fly

#### Main Takeaways
- Developer can save on RAM:
    - Use space-efficient data structures
    - Use Dynamic Memory Allocation
- Languages/compilers/OS provides things to help:
    - Dynamic loading: Load code only when it's about to be used
    - Dynamic linking: Don't duplicated code in RAM when used by multiple processes

#### Conclusion
- We may have to swap processes to disk because we run out of RAM
- Making address spaces as small as possible is thus a good idea
- Won’t have to swap as often, not as costly to swap if needed
- Bottom Line: let’s not waste bytes!