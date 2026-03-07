# Lecture 5b - Advanced CPU Scheduling

#### CPU Scheduling in the Real World
- Previous set of lecture notes goes over basics of scheduling
- Punchline: use RR with a good time quantum
- But things are not as simple
1. Multi-Level Feedback Queue
    - Approach used in most real world OSes
2. Multi-Processor Scheduling
    - Only the surface here
3. What Linux does
    - Linux's long history

#### Time Quantum Conundrum
- If RR time quantum is too small, context-switch overhead would reduce useful CPU utilization, harms CPU-intensive jobs

#### Multi-Level Feedback Queue
- Ensure that interactive jobs never get stuck in the Ready Queue due to CPU-bound jobs
- Interactivity is going to be maintained

#### MLFQ Basic Idea 1: Priorities
- There are 8 priority levels, jobs can be in low priority or high priority
- A higher priority job ready to run always preempts a lower priority job that's currently running
    - If two jobs are in the same priority, they do round-robin
- Interactive jobs should be in the high priority queue
    - However jobs aren't going to be interactive the whole time, so there needs to be a mechanism to demote or promote a job based on its current interactiveness
- How do we make a mechanism to auto-detect job interactiveness
    - If a job don't use an entire time-quantum, it's probably highly interactive
        - If it keeps using its entire time-quantum, it's probably CPU or compute bound
- Therefore
    - If a job uses its full time quantum, it's demoted
    - If it doesn't then it's not demoted

#### Problem of Starvation
- What if we have too many interactive jobs
- How will the CPU-bound jobs ever run?

#### Another Problem: Gaming the System
- A very smart user could cheat the scheduler
- If you know the time quantum duration, you cna hve the program do fast, but useless I/O operations, right before the time quantum expires
- As a result, program never uses its time quantum fully and remains at the highest priority always
- Jobs that change behavior
    - Say a job is first CPU-intensive, so it's demoted

#### Solution: Priority Boost
- Once in a while, all jobs are moved back to the highest priority queue and are let trickle down
    - I like to call this one sagging pants mechanism
- But how frequent?
    - If too frequent, interactive jobs may lag
    - If too unfrequent, CPU-bound jobs will be unhappy
    - "Voodoo parameters" picking a perfect parameter is a dark art

#### MLFQ Parameters
- We have many voodoo constants in practice
- Easy to implement based on a configuration, but what is a good configuration
- People have experienced over the years and a good rule of thumb is large time quanta for lower-priority ready queues

#### Multi-Processor Scheduling
- All our processors are multi-core
- OSes need to do scheduling across multiple cores
- Whenever a core is idle, put a job on it based on MLFQ scheme
- But if processes keep jumping around, they won't be able to keep their cache, it makes cache useless and memory slow
  
#### Scheduling for Cache Affinity
- Each job has some affinity
- One or a few jobs bounce around, but other jobs stay put, good for the cache

#### Linux Scheduling
- Lot of scheduling ideas and developments
- Considered to have very good schedulers
- Well-known algorithms
    - O(1) Scheduler: multi-queues, bitmap tricks, MLFQ-like
    - CFS (Completely Fair Scheduler): stores jobs in rb trees instead of queues
    - BFS brainfuck scheduler
    - EEVDF (Earliest Eligible Virtual Deadline First)
- Default since has ben EEVDF 
    - Fast, more predictable than CFS

#### Main Takeaways
- Picking a time quantum is hard
- Multi-Level Feedback Queue (MLFQ) scheduling
    - Multiple RR queues with different time quanta
    - Goal: not penalize interactive jobs
- Priority boosting to avoid starvation
- Tracing MLFQ scheduling is easy (right?)
- Multi-core scheduling: cache affinity
- Real-world OSes all use roughly the same ideas with tweaks, bells, and whistles