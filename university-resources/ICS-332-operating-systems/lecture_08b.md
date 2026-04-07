# Lecture 8B - Swapping

#### Swapping
- What if we want to start a new process but it RAM is full
    - We move processes back adn forht between main memory and disk
- When a process is swapped back in, it may be put into the same physical memory space or not
- Its ok because programs are relocatable and addresses are virtualized

#### Bad News about Swapping
- Disk is slow
- The approach is not to swap and swapping should be exceptional
- Swapping is now often disabled

#### Where are we
- We now have the mechanisms we need
    - Give each process a slab of RAM that can fit anywhere
- We need a policy to decide how to place each slab in memory
    - We want to have as many process address spaces in memory
    - We want to minimize swapping
- Memory is swiss cheese processes are holes

#### Memory Allocation
- Kernel must keep a list of available memory regions or holes
- When a process arrives, it is placed in a "I need memory input queue"
- Kernel must make decisions:
    - Process selection: Pick a process from input queue
    - Memory allocation: Pick a hole in which a process will be placed

#### Memory Allocation Strategies
- Which process should be picked?
    - FCFS?
        - Easy fast to compute, may delay small processes
    - Allow processses to jump ahead?
        - Slow to compute, may cause starvation
    - Limit jumping ahead, look ahead
- Which hole should be picked for the process that was picked?
    - First fit?
        - Pick the first hole that is big enough
    - Best fit? 
        - Pick the smallest hole that is big enough
    - WOrst fit?
        - Pick the biggest hole
- How should the picked process be placed in the picked hole?
    - Top?
    - Middle?
    - Bottom?

#### Memory Allocation
- Which one??
    - FCFS + First Fit + Top?
    - Jump ahead + worst fit + bottom?
- We are trying to serve a problem that we don't know the question of
    - We don't know the future, so we can't pick a strategy
    - Instead of doing it algorithimically, we just use heuristics
- No best strategy, even a "terrible heuristic" could be good in some weird situation

#### External Fragmentation
- We don't want to have external fragmentation
- Having disjoint holes that are unused in main memory that could fit another process could be unused, wasted memory
- How many holes are there?
- External fragmentation is not entirely avoidable, so we will instead "defragment" or "compact"
- Compaction
    - Defragging a hard drive
    - Moving processes around
        - Lots of slow memory copies
    - Creates complex issues with I/O and DMA
    - No OS does this
    - So we just live with external fragmentation

#### Internal Fragmentation
- Tinier holes
- Caused by a solution to a problem
- OS keeps a list of fragments, this list also uses memory obviously
    - What if the list is 20 bytes big, but the only fragment it is tracking is 1 byte, what a waste of 20 bytes
- In practice, an OS allocates slabs that are multiples of some block size
    - But a process may not use the whole slab and some space is wasted, this is called internal fragmentation
    - If OS only gives 4KiB and a process needs 4.1 KiB, it gets 2 blocks anyway and wastes 3.9 KiB, that is internal fragmentation
- If we make smaller blocks, we get lower internal fragmentation, but we need to keep track of even more blocks
- If we make bigger blocks, we get more internal fragmentation, but fewer blocks to track

#### Main Takeaway
- Our objective was to allocate a contiguous slab of memory to each process (or to each process segment) so that their address spaces can be in RAM
- The mechanisms are “easy”
    - Relocatable code with virtualized addresses
    - Swapping processes in and out
- But finding a good policy is hard
    - FirstFit, BestFit, WorstFit are three classic algorithms
- Internal and External Fragmentation