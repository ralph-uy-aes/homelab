# Lecture 1b - Memory Bottleneck

#### RAM is slow
- Often programs are slow because memory is crazy slow
- Accessing a register is very fast, though
- Accessing the memory can take around 50 ns, fast for us, slow for computers
- A CPU does nothing while it's waiting for the memory to give it data
    - This is called the Von-Neumann Bottleneck or the Memory Bottleneck
    - Many techniques have been developed to address this problem
- We don't know how to make RAM fast (in a cost effective way)

#### Memory Hierarchy
- We want big and fast memory
- Could we just build the memory just as gazillions of registers?
    - Nope, cost and physics say no
- The trick we play to provide the illusion of fast memory is called memory hierarchy
- Registers are O(kB), 1ns
- Caches are O(MB), 1-50 ns
- Memory are O(GB), ~100 ns
- Disks are O(TB), ~10,000 ns
- Top to bottom: Fast to slow, Smaller to bigger

#### A Real System
- 2 Sockets
- On each socket:
    - 24 hyperthreaded cores
    - 3 levels of cache
        - Split Data/ Instruction L1 caches

#### Memory Hierarchy in a Nutshell
- A program wants to access a byte in memory
    - Is the byte in cache?
        - If yes, put it in register
    - Otherwise, the byte is brought from the slow memory into the fast cache
    - Values "around the byte" are also brought into the cache
- This can happen at all levels
    - Each level of the hierarchy serves as a "cache" for the level below
    - It hopes that its in the closest cache