# Lecture 9c - Local Variables

#### Local Variables in program
- Local variables are returned as under
- For example, first local var is at EBP-4
- At the bottom is saved registers, at EBP is the saved EBP and at EBP+4 is the return address
- Everything after EBP are parameters and everything under EBP except saved registers

#### ENTER and LEAVE
- `enter x,0` instruction replaces these lines:
    - `push ebp`
    - `mov ebp, esp`
    - `sub esp, X`
- `leave` instruction replaces:
    - `mov esp, ebp`
    - `pop ebp`
    - `ret`

#### Knowing your Stack
- You need to know how the stack works and how to use it
- When Programming assembly, always have a mental picture of the stack
    - Something you don't do when using a high-level programming languages

#### Important Takeaways
- Local variables are stored on the stack
    - Otherwise we couldn’t have recursive subprograms have local variables!
- Now we can draw the stack for high-level code