# Lecture 11b - Lexical Analysis - Lexing or Scanning

#### Lexical Analysis
- AKA Lexing/Scanning
- Does 2 things:
    - Transforms input source string into a sequence of substrings
    - Classifies them according to their role
- Input is the source code
- Output is al ist of tokens

#### Tokens
- Syntactic Category
- Example Tokens:
    - Identifier
    - Integer
    - Floating-point number
    - Keywords
    - Etc...
- In English:
    - Noun
    - Verb
    - Adjective
    - Etc

#### Lexeme
- String that represents an instance of a token
- Set of all possible lexemes that can represent a token instance is described by a pattern
    - English and other natural languages typically don't have patterns in their "tokens"
- For instance, we can decide that the pattern for an identifier is:
    - "A string of letters, numbers, or underscores, that starts with a capital letter"

#### Lexing Output
- See slides for output
- Note that the lexer removes non-essential characters
    - Spaces, tabs, linefeeds, comments
    - Good idea for lexer to allow for arbitrary numbers of whitespaces, tabs, and linefeeds

#### Lexer By Hand? Hell Naw
- Difficult!
    - Many types of tokens
        - Fixed String
        - Special Character Sequences
        - Numbers Defined by specific/complex rules
    - Many possibilities of token overlap
    - Many nested if-then-else in lexer's code

#### Lexer Specification
- It's hard to define things like floating point numbers, so we have to use RegEx (regular expression)
- We define a language to be a subset of the power set of an alphabet
    - Our alphabet is typically denoted by Sigma, the ASCII characters allowed in source code
    - Our language: a subset of all the possible strings
- Problem: our language is infinite or very very large
- Need to define patterns

#### Regular Expression (RegEx)
- Basically a notation for a pattern
- Expressions are correlated with meanings
- See slides for examples

#### REs for Proglang
- It is easy to define an RE that describes all keywords
- Can be split in groups if needed
- Keyword = 'if' | 'else' | 'for'...
- See slides for more examples

#### Finite Automation
- A finite automation is defined by
    - An input alphabet: $\Sigma$
    - A set of states: S
    - A start state: n
    - A set of accepting states: F (subset of S)
    - A set of transitions between states; subset of SxS
- See slides for graphs

#### REs and NFA
- We're left with two possibilities:
- Design DFAs
- Design NFAs
- Turns out one is not more powerful than the other

#### Putting it All Together
- Steps to designing/building a lexer
    - Come up with a RE for each token category
    - Come up with an NFA for each RE (easy for a human to do)
    - Convert the NFA (automatically) to a DFA (we have great algorithms to do it)
    - Write a piece of code that implements a DFA (easy for a human to do with a simple transition table)
- Implement your lexer as a ‘bunch of DFAs’

