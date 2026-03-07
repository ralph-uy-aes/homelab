In clas exercise

ABBBB ABBBB ABBBB       Q1
     C     C     C      Q0
 AAAAA AAAAA AAAAA      Disk
     BB    BB    BB     NIC


      When C hits that 5ms top queue quantum, it gets demoted to low queue, but at  some point there's a priority boost so it gets to top queue again
ABBBBCCCCCABBBBCABBBBCCCCCABBBBC
 AAAAA     AAAAA AAAAA     AAAAA 
     BB        BB    BB        BB 


AAABBBBBAAABAAABBBBBAAABAAABBBBB    CPU
   A       A   A       A   A        I/O
             pb          pb         Priority Boost?

A - 3ms C 1ms I
B - infms C
C - infms C

AAABBBBBCCCCCAAABBBBBCCCCCAAA
   A            A            A
              pb
HQ: A
LQ: B C