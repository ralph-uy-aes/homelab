# Lecture 9b - Paging 2

#### Paging is great but
- Paging has extra overhead
- Page tables can be very large
- Let's come up with solutions

#### Paging Overhead
- Each address coming out of the CPU is virtual
- Address translation has to be performed for every address issued by the CPU
- Page table is in RAM and will be accessed very frequently
- Page table base register
    - Makes it fast to switch between page tables at each context switch, doesn't speed up translation
- Because of paging, memory access time is doubled
    - However, temporal and spatial locality helps
    - We cache previous translation results
    - These are stored in the TLB

#### Translation Lookaside Buffer
- Hardware found in microprocessors
- It is basically a cache for page table
- Each entry is a <key,val> pair
- Give it a key, key is compared in parallel with all stored keys
- If one is found, associated value is returned

#### ASIDs
- Address-Space IDentifiers
- Each TLB is annotated with a PID
- TLB can contain entries associated ot multiple processes
- Each lookup attempts to match entry ASIDs with ASID of current process

#### Page Table Entries
- One thing we haven't talked about yet: how many bits are needed for a page table entry
- Page table consumes space in RAM
- Consider a system with 32-bit physical addresses
- n-th entry in page table is physical fram number
- Assume page/frame size is 4KiB = 2^12 b
- So we have 2^32/2^12 = 2^20 frames in RAM
- Let's say 32 bits = 4 bytes are used for each page table entry

#### Note on Page Table Structure
- Page table is just an array of entries

#### Exercise
- Page size: 32 KiB
- Logical Addresses: 39 bits
- Page table entry: 8 bytes
- offset is 15
- 2^15/2^3= 2^12 entries
- p1 = 39-12-15 = 12 = p1

#### Exercise 2
- 64KiB
- offset is 16
- 2^16/2^2 = 2^14 p2
- p1 = 41 - 14 - 16 = 11 p1
- 11, 14, 16
- What fraction is utilized, 2^11/2^14 = 1/8 of p1 is used

#### Main Takeaways
- Paging is a good idea, but it has its problems
- Problem #1: Address translation is slow
    - Solution: Use a TLB
- Problem #2: The Page Table can’t be contiguous memory that’s larger than a page
    - Solution: Use a hierarchical structure
    - The hierarchical structure makes translation slower, but we don’t care because we have a TLB anyway!
    - It requires that logical address bits be split into different parts
    - For instance, for a 2-level we would have a 3-way split: outer, inner, offset