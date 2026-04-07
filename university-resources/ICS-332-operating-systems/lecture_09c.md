# Lecture 9c - Paging 3

#### Demand Paging
- Lazy scheme, pages are only allocated to processes when it needs it
    - Don't load the page before the process references it
- Initially only one page is loaded
- An eager scheme would load all pages at once
- Done using valid bit of page table entries
    - Valid if legal and in memory
    - Invalid if illegal or on disk
    - Initially everything is marked invalid
- During address translation, if bit is invalid a trap is generated so the OS can trigger the page load from disk into RAM
- Trap is called a page fault