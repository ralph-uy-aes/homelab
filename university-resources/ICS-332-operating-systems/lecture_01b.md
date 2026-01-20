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

#### Memory Hierarchy Analogy
- To write a paper at your desk at home you need a reference book from the library
- You go to the library and find the book on a shelf, noticing that books around it are on the same topic
    - Option 1: Leave the book at the library and go to the library every time you need one reference (no memory/ no cache)
    - Option 2: Take only the book you need and reuse it at will, but if you want another book on the same topic, you need to go back
    - Option 3: Take the book and the books around it and put them on your desk, now you don't need to go back to the library
- Option 3 is your desk is a cache for the library
    - The set of books you grabbed is a cache line or memory line

#### Misses and HIts
- Cache hit
    - You want to reference a bit, and you find it in cache, you hit it!
    - You hope to mostly have cache hits
- Cache miss
    - The processor references an address and the data at that address is not in cache
    - You missed!
    - A memory line is brought into the cache

#### Cache/Memory Lines
- See illustrations in the slides for a visualization

#### All this Happens in Hardware
- All cache management is done in hardware
- OS or programmer can't dictate how the cache works
- Real hardware is more complex, there are several layers of cache

#### Locality in your Programs
- The memory hierarchy is useful because of locality
- Temporal Locality: A memory location that was referenced in the pas is likely to be referenced again
    - If you reference a byte, you're likely to reference it again soon
- Spatial Locality: A memory location next to one that was referenced in the past is likely to be referenced in the near future
    - If you reference a byte, you're likely to reference a byte close to it
- In general, all useful programs have some locality
- But programming for best locality is a well-known challenge

#### How Much Does Locality Help?
- See slides for code example

#### Direct Memory Access (DMA)
- Usually you need to copy large amounts of data to and from RAM and peripheral devices
- In Pure Von-Neumann CPU needs to be involved for every operation which would induce the memory bottleneck problem because CPU waits and waits and memory is slow
- It would be better if we had copies occur independently, so the CPU can do something useful while memory copies are taking place
    - DMA says "let's not have the CPU do this"
- Used on all modern computers
- Works by:
    - CPU tells DMA controller to initiate a RAM copy
    - When it finishes copying, the controller tells the CPU it's done by generating an interrupt
    - In the meantime, the CPU can do other things
- To perform data transfers, the DAM controller uses the memory bus
    - In the meantime, the code executed by the CPU likely also uses the memory bus, they can interfere with each other
- There are several ways to manage this interference, like give priority to DMA or CPU, weight usage, etc...
- In general DMA leads to much better performance and software should used it as often as possible

#### Main Takeaways
- The way we cope with slow RAM is via a Memory Hierarchy, using “caching”
- Caching works because our programs have natural locality behavior
    - Temporal and Spatial
- CPU caches are managed by the hardware (not the OS)
    - When you reference a byte, you get the whole “line” (hoping for spatial locality) and you keep it around in cache (hoping for temporal locality)
- As a programmer you can influence locality of your program a lot, which can be hard to do
    - But simple examples should appear staightforward