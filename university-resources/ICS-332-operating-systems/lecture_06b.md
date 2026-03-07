# Lecture 6B - Synchronization: Deadlocks

#### Deadlocks
- When a critical section is never unlocked
- Basically, when you write concurrent code, beware of deadlocks and beware of race conditions

#### Defining a Deadlock
- Can be formalized in a very general manner
- Resources and Processes
    - R1,..., Rn and P1,..., Pn
  - Deadlock State
    - Three necessary conditions
        - Mutual exclusion: one resource is not shareable
        - No preemption: resources cannot be forcibly removed from processes that are holding them
        - Circular wait: There is a set of waiting processes

#### Strategies Against Deadlocks
- Prevention: By design make no program possibly make a deadlock
- Avoidance: Watchdog approach, if we are aware of the resources that jobs will use
- Detection: Do whatever, when deadlock occurs, repair them