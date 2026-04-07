# Lecture 8A -  Main Memory

#### Main Memory: Basics
- Main Memory = Memory Unit in the Von Neumann Model
    - Huge array of bytes each with address
    - CPU puts addresses on the memory bus
    - Memory unit also fetches data for you using addresses
- Processes share main memory, 
    - OS must manage the main memory
- CPU only works with registers, but can issue addresses of locations in main memory

#### Address Binding
- One important question is address binding:
- When are physical addresses determined for bytes of data/instruction
- When do we decide that variable x is gonna be at FF12? for example

#### Address Binding - Absolute Addressing
- Binary executable contains physical addresses
- Simple, but has not been used in decades
- Bad idea to have physical addresses hardcoded into memory
    - If you write your code and put some global variable into main memory, programs can overwrite that same address, losing isolation principle
- No two programs should be allowed to overwrite in the same space
    - As a result, two programs (even similar ones) cannot run at the same time without there being bugs

#### Address Binding - Relative Addressing
- Assuming the address space starts at some "Base" address and compute all addresses as an offset from the Base
- Code is now completely relocatable, only the Base needs to be determined before running
- Can be ran anywhere in memory at whatever Base address
- Multiple instances can run each with a different Base address, as long as they don't overlap

#### RAM Virtualization
- All addresses in the process address space are expressed as an offset relative to the base value
- Allows us to virtualize RAM
- Instead of saying “the 4th byte in my address space is at address x”, it says “the 4th byte in my address space is at address BASE + 4”

#### Memory Virtualization
- Each program thinks that it's alone in RAM and that its address space starts at address 0
- Gives us Memory Protection
    - Program doesn't need to know anything about other programs
    - Good because when you write the code, you don't know what other programs will be running anyway
- A program references a logical address space which corresponds to physical address space
- Something needs to tell CPU how to translate from virtual to physical addresses

#### Virtualizing Address Spaces
- Some component needs to translate virtual addresses into physical addresses or add an offset to the Base
- FDE cycle, each cycle the computer computes Base + offset
- Base address is accessed very frequently
    - Offsets are added to the base address very frequently
    - Wasting even one CPU cycle to do the addition would be very expensive
- We use a base register and a limit register that stores the base address and largest possible logical address
- We implement the above using the super fast hardware component: Memory Management Unit (MMU)

#### So far
- Program generates only logical address >= 0
- Each such address is checked to see if it's beyond the limit, if it is a trap is generated and the program aborts
- If not, the address is translated
- Translated physical address is then sent to the memory bus, and RAM will do its job based on the address
- Bottom Line:
    - CPU only sees logical addresses
    - RAM only sees physical addresses

#### Segmentation
- An address space is full of empty space in which the heap and stack can grow
- Having a single contiguous segment is wasteful
- Segmentation: avoid waste by breaking up the address space into pieces
- Each piece has its own base/limit register
- Logical address space is now a collection of segments
    - Compiler/language interpreter handles segments and logical addresses are built appropriately
    - Writing in assembly, you may have to deal with segments manually
    - Typical segments used by a C compiler:
        - text
        - data
        - heap
        - stacks
        - standard C lib
- First bits of logical address are used to identify which segment is being referenced

#### MMU Segmentation 
- Implementing segmentation is easy
- Reserve bits in the logical address to reference a segment

#### Segmentation for Protection
- Splitting address space into segments allows us to implement protection mechanisms
- Can include bits that answer:
    - Is the segment readable, writable, or executable?
    - Any combination of 3 bits: RWX

#### Main Takeaways
- Programs should be relocatable
- Memory address virtualization
- Segmentation
- The CPU sees logical addresses, and the MMU transforms them into physical addresses
    - Determines the segment
    - Look up the segment table to find the segment’s base and limit values
    - Check that the logical address is within the limit, and if not generate a trap
    - Add the base to the logical address
    - And voila, we have the physical address