# Lecture 11C - Syntactic Analysis

#### Syntactic Analysis
- We need to check grammar, not just spelling
- Regex is not sufficient to describe the grammar of a language
- We need a more powerful tool: Context-Free Grammars
    - Plus some more mechanisms

#### Context-Free Grammars
- A set of production rules
- Each rule describes how a non-terminal symbol can be replaced/expanded/rewritten by a string that consists of non-terminal symbols and terminal symbols
    - Terminal symbols are lexical tokens
    - Rules are written with regex-like syntax
- Rules can be applied recursively
- See slides for example

#### What is Parsing?
- CFG is derivation, you have a grammar, you keep going down the rabbit hole and eventually you have something
    - But this is useless, we write programs for them to do something specific
- We do parsing instead
    - The opposite of derivation
    - Given a string of non-terminals, discover a sequence of rule derivations that produce this particular string
- When we say we can't parse a string, we mean that we can't find any legal way in which the string can be obtained from the start symbol through derivations
    - Or "Syntax Error"
- A parser program takes in terminal symbols and discovers a derivation sequence or says syntax error

S -> 0S | 1S | 0 | 1
