# Lecture 9a - Virtual Memory and Paging

#### Paging
- Break up address spaces into smaller chunks
- Should we have chunks of variable size?
    - Not a good idea as this is a well-known difficult problem algorithmically: Bin Packing
    - Known to be NP-hard
    - Don't want the OS to have to solve some NP-hard problems
- But if chunks are fixed, it's easy
- Each process' address spaces are split into same-size pages
- Physical memory is split in fixed-size frames and each frame can hold a page (frame size = page size)
- A page is virtual or logical: Virtual Page Number
- A frame is physical: Physical Frame Number

#### Paging and Addressing
- A process' address space is non-contiguous and pages are not even in the right order
- When given a logical address, we have to compute the virtual page number and the offset within the page

#### Virtual Page Number
- Virtual addresses issued by the CPU are split into two parts:
    - Virtual or logical page number: p
    - Offset within the page: d
    - Read the value at address x becomes read the value at offset d in page p
- Process still has the illusion of a contiguous address space starting at page 0, and so on
- In reality, each page is in a memory frame anywhere, we say page p is in frame f

#### Page-To-Frame Translation
- VPN has to be translated to corresponding PFN
- We need to keep track, for each process, of the mapping between each of its pages and the physical frame that page is in, to this end each process has a page table

#### Page size
- Defined by architecture
    - x86-64: 4KiB, 2MiB, and 1GiB
    - ARM: 4KiB, 64KiB, and 1MiB
- pagesize command gives you page size in UNIX-like systems

#### Generalization
- If page size is s
    - Also 2^o
- If logical address is x
- Then:
    - logical page number: p = floor(x/s)
    - offset: o = x mod s
- If page p is in frame f
- Then:
    - logical address x translates to physical address y = f * s + o

#### Sharing Memory Pages
- Create page table entries that point to the same physical frame in different processes' page tables
  
#### Valid Bit
- Each page entry is augmented by a valid bit
- Set to valid if the process is allowed to access the page
- Set to invalid otherwise
- If process references a page whose entry's valid bit is not set, then a trap is generated

#### What about Fragmentation
- No external fragmentation
    - Huge advantage of paging
- Only external fragmentation
    - Worst case: a process address space is n pages + 1 byte
        - We waste 1 page - 1 byte
    - Average case: Uniform distribution of address space sizes: 50%
- Using smaller pages reduces internal fragmentation
- Large pages have advantages:
    - Smaller page tables
    - Loading one large page from disk takes less time than loading many small ones
- Typical page sizes: 4KiB, 8KiB, 16KiB
- OSes today: multiple page sizes are supported

#### Frames Management
- OS needs to keep track of frames
- OS has a data structure: free frame list
- Much simpler than a list of holes with different sizes
- When a process needs a frame: OS takes a frame from free frame list and allocates into a process

#### Segmentation and Paging
- Intel architecture like most other architectures provide both segmentation and paging
- Logical/virtual address is transformed into a linear address via segmentation
- Linear address is transformed into a physical address via paging

#### Memory-Mapped Files
- Data files can be virtualized by mapping them to memory
- Memory Mapping
    - Map disk block(s) to memory frame(s)
    - Initial access is expensive
    - Subsequent access is made in memory and cheaper
    - On disk file may be updated at a convenient time upon closing
    - Memory mapping is performed by dedicated system calls (mmap)

#### Main Takeaways
- Paging is great:
    - No external fragmentation
    - Easy to share pages among processes
- Mechanisms:
    - Each process as a page table
    - Each page table entry maps a logical page to a physical frame
    - Each page table entry has a valid bit
    - Address translation is based on the page table
    - The OS manages the list of free frames, and gives out frames to processes
    - It’s an easy way to share memory about processes, and makes it trivial to generate memory-mapped files

