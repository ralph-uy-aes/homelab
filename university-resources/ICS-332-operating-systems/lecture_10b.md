# Lecture 10B - SSDs

#### Solid State Drives
- Flash based storage
- No moving parts
- Faster, Silent
- Lower power, more reliable, lighter
- Market share has been increasing
- HDD's only advantage now is $/byte
    - But people think that by 2030, HDD prices = SSD prices

#### SSD Storage Structure
- SSDs store bits into cells
    - Each cell can store 1, 2, or 3 bits depending on the technology
- Cells are organized into pages
- Pages are grouped into blocks
- Blocks are grouped into banks or planes

#### SSD Operations
- Read a page
    - Very fast, random access makes no difference
- Erase a block
    - Much more expensive
- Write a page
    - Requires that the page's block has been erased first
        - SSD Weirdness, to update data in a page, you need to erase it first
    - To make things worse, this causes wear out of the flash cells 
    - Write amplification: you need to first copy all other pages somewhere and then erase the whole block and then write to all pages

#### SSD Techniques
- Increase performance
    - Controller cleans up blocks with invalid pages
    - Called garbage collection
- Decrease wear out
    - Controller tries to spread writes over all pages, so that they all wear out together as late as possible

#### Main Takeaways
- SSDs are better than HDDs in almost all respect besides cost per byte
- The main issue: write amplification
- Techniques have been developed to deal with it (and with wear-and-tear), and nowadays these problems are no longer a big issue in practice