# Lecture 5A - CPU Scheduling Basics

#### CPU Scheduling
- Can be extremely theoretical, some people spend their whole lives doing scheduling
- "job" can be understood as process or thread from now on
- Scheduling policy: what should the OS do (complicated)
- Scheduling mechanism: how the OS does it (easy)

#### Policy and Mechanisms
- Policy: a scheduling strategy
    - Broad goal is to improve system performance and productivity including: 
        - Maximize CPU utilization, when CPU is idle, pick a ready job ASAP
        - Make jobs happy, jobs should feel like the CPU is fair and not too slow
- Mechanism: the dispatcher
    - OS component that knows how to switch between jobs on the CPU
    - Has to be super fast

#### Long-Term/Short-Term Scheduling
- Long-Term
    - Select jobs from a submitted pool of jobs and load them into memory
    - Orchestrate job executions in the long term (minute, hour)
    - Make scheduling decisions every minute, hour
    - Can construct complex schedules
    - Koa
- Short-term
    - Select already-in-memory jobs to run
    - Orchestrate job executions in very short term (milliseconds)
    - Make scheduling decisions every millisecond
    - Cannot make complex decisions

#### CPU and I/O Bursts
- CPU Burst: sequence of CPU instructions that do whatever computation until a syscall is placed to do some I/O
- I/O Burst: time during which job cannot execute its next instruction because it's waiting for I/O to complete

#### Bound Jobs
- CPU-Bound Job: A job that mostly uses CPU with short or few I/O bursts
    - Ray-tracer
- I/O Bound: A job that mostly waits for I/O with mostly short or few CPU Bursts
    - Text editor, file copier (`/bin/cp`)

#### CPU Scheduling Challenge
- CPU keeps ready jobs in a list: the Ready Queue
- OS must make scheduling decisions
    - Pick one of the jobs from the ready queue
    - Decide how long to give the CPU to the picked job
- Big challenge is that the only thing the OS knows is the number of jobs in the system, but the job population can be very diverse

#### The Scheduling Problem
- All jobs arrive at the same time
- Each job runs for the same amount of time and then finishes
- Once started, each job runs to completion
- All jobs are 100% CPU-bound
- The run-time of each job is known

#### Jbo Turnaround Time
- T_turnaround = T_completion - T_arrival
- Pretty clear that owners of CPU-bound jobs care about turnaround time
- Other jobs perhaps this metric makes little sense

#### Simplest Algorithm: FCFS
- First Come First Serve
- Given jobs A,B,C they all arrive at around the same time, but A came first then B then C
- A finishes first at 10 seconds, then B at 20, then C at 30
- Average turnaround time is `(10+20+30)/3=20`
- FCFS, convoy effect
    - What if A is extremely slow
    - This is like buying one thing at costco and then in front of you is CaseOh
    - Average turnaround time increases for all processes

#### Shortest Job First
- The person buying one thing in Costco is allowed to go first before CaseOh
- Not bad, everyone seems to be happy
- SJF is optimal with our assumption that everyone arrives at the same time
- What if jobs arrive at different times?
    - This is where SJF fails, essentially becomes a slightly optimized FCFS

#### Preempting Jobs
- Assumption of jobs must run to completion does not apply anymore
- The OS must be able to preempt or kick a job out of a CPU
- Shortest Time-to-Completion First
- Whenever a new job comes in and it has a shorter time-to-completion, then kick the running job and run the new job
- Whenever a job finishes, run the job with the shortest-time-to-completion
- We fixed the convoy problem!
    - Lowkey, imagine if you want to buy a banana and behind you someone wants to buy an apple, but caseoh was first
    - The cashier says wait caseoh, lets let them go first while caseoh is in the process of unloading his stuff
    - You buy your banana, then the guy behind you buys his apple, caseoh continues after all that

#### Starvation Problem
- A job may never run in the case of STCF
    - Caseoh might never get to buy his groceries (and starve) if a bunch of people wanna buy single-item groceries
    - A stream of short jobs could prevent a long job from ever completing

#### The OS Does not Know Job Durations
- You don't tell the OS how long your program is going to run when you start it
- Nice algorithms like SJF and STCF cannot be implemented in the OS

#### Round-Robin Scheduling
- Every OS does this today
- Let a job run for a bit, preempt, then run the next job, and repeat
- The max duration that a job runs before preemption is called the time quantum

#### Time Quantum Usage
- Whenever a job is scheduled it's allocated a time quantum
- If it uses its time quantum fully, then it's preempted when the time quantum expires
- If it stops computing before the time quantum expires, even when it's right before completion, it still gets preempted anyway

#### RR Time Quantum
- Too large: poor response time
- Too small: too much context-switching overhead

#### The Story So Far
- Turn-around time seems like a reasonable metric
- We can have algorithms that do ok for that metric
- Especially if we allow jobs to be preempted
- But turn-around time is impossible to optimize for if we don’t know the job durations!
- So we instead use RR Scheduling
- Bottom Line: All OS Schedulers use flavors of RR Scheduling
- Let’s look at our assumptions again….

#### One Option: Do Nothing
- OS could just not care and let a job do its I/O
- Wastes CPU time, it's idle during I/O

#### Scheduling Around I/O
- While A is waiting for I/O, schedule B, so that it runs on CPU while A waits for I/O

#### Main Takeaways
- Policy vs. Mechanisms
- Long-term vs. Short-term
- CPU and I/O bursts
- CPU- and I/O-bound programs
- Turnaround time
- Basic algorithms: FCFS, SJF, w/ or w/o preemption
- What’s done in practice: Round-Robin with a Time Quantum
- Tracing scheduling decisions is not hard (right?)