# Lecture 11a - Compiler Overview

#### What's a Compiler
- A compiler is a translator
- Translates from a source language to a target language

#### What Should a Compiler Do?
- Should accept legal code and reject illegal code
- Should generate correct translated code
- Correct data, bss, and text segments, if generating x86 assembly
- Seems obvious, wasn't always easy and first compilers were known to have bugs and limitations
    - Dilemma: Is your code buggy or is it your compiler?
    - Nowadays, it is a 0.00000......0001% chance that it's your compiler's fault

#### Traditional 2-Pass Compiler
- Compilers use Intermediate Representation (IR) for the program being compiled
    - IR is a way to encode the program
    - Tree-like data structures with bells and whistles split your input into different outputs
- Splitting makes it possible to have multiple front end versions
    - You have a front-end which takes C++ and a front end that takes Python, 2 compilers for the price of 1.5

#### Front-End
- Scanner -Tokens-> Parser 
- Easy part of the compiler
- Where all error messages are generated
- Writing code for scanner and parser can be automated

#### Scanner
- Maps a stream of characters (text file for ex.) into words
- A word is called a token, which is a pair of two things
    - Lexeme: actual string in source code
    - Type: What this word means in the programming language
- "Given input, identify the words"

#### Parser
- A little harder
- Builds an Intermediate Representation (IR)
- Imagine a baby (scanner) saying words, to the baby it sounds good! To you (parser) it makes no sense, the baby is making syntax errors and must be terminated
- "Do these words grammatically make sense?"

#### Back-End
- Instruction Selection -> Register Allocation -> Instruction Scheduling
- Translates IR into machine code
- Chooses which machine instructions to use to translate the IR
- Chooses which values should be kept in registers
- Decides order in which instructions should be executed in which order

#### Instruction Selection
- Goal is to produce fast, compact code
- "The Syntax Optimizer"
- Used to be a huge issue when ISAs were very complicated with many many options
- No longer as big an issue nowadays

#### Register Allocation
- Registers allow for fast variable access, but number of registers is limited
- Optimal allocation is NP-hard (difficult)
- Compilers use approximation algorithms to try to get close to the optimal
- "The Register Optimizer"
- "How many registers to use?"

#### Instruction Scheduling
- Decides on how to reorder the instructions
- Very difficult problem that is the object of decades of research and development
- Compilers use complicated heuristics
- Some scheduling happens in hardware
- "The Hardware Optimizer"
- Similarity between code in C and what actually happens in the hardware is sometimes tenuous

#### Code Optimization
- What we've talked about so far has been known for decades
    - Some parts can be automated/generated using standard tools
    - Some parts have to be done by hand and many well-known techniques and algorithms can be reused
- Most people who work in compilers nowadays don't really work on these components
    - They usually work on making the code shorter/faster/more secure

#### Traditional 3-Pass Compiler
- The Middle-end is all about improving the code
- Iteratively transforms/rewrites the IR
- The Goal: Reduce the running time of the produced code
- The Constraint: Must preserve the exact behavior of the code