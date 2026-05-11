# Lecture 10A - HDDs

#### Misconception
- HDDs are still useful today even though people were heralding the end of HDDs 
- People thought SSDs were going to replace HDDs
- They're still much much cheaper

#### Platter, Tracks, Sectors
- Disks have multiple platters
- Each platter has multiple tracks
- Each track has multiple sectors
- Each sector stores 512 bytes of data that can be read/written atomically by HDD controller

#### Surfaces, Cylinder
- Platters are double sided for more space
- Sectors have different sizes to deal with varying densities
- Outer tracks have more sectors that inner
- Set of all tracks that are the same distance away from the spindle (axis) is called a cylinder

#### Arm, Head
- Each platter surface has a head, can read/modify the magnetic patterns on the surface
- Heads are attached to an arm that can move across the surface to position the head on a track

#### Performance
- HDDs are slow because they have moving parts
- Performance highly depends on current position of the head
- When doing a read/write operation, latency depends on
    - Rotational delay
    - Seek time
    - Transfer time

#### Rotational Delay
- Depends on HDD's RPMs
- Today most RPMs are 7k to 10k
- If disk RPM is x, then rotational delay is about 1/x minutes in the worst case

#### Seek Time
- If the head is not positioned over the right track, then the arm has to move
    - This is called seeking
- There are physical or mechanical limits on how fast the arm can move
    - There is an acceleration phase, a coasting phase, a deceleration phase, and a setting phase
- This is on the order of ms

#### Transfer Time
- Once the head is on the right track and at the beginning of the right sector, it can begin reading/writing data
- Ti/o = Tseek + Trotation + Ttransfer

#### Disk Scheduling
- Disk Scheduling question: in which order should a stream of block # 
- The goal is to minimize average access time

#### Disk Scheduling: FIFO
- Basic algorithm
- Answer request in order they come
- Inefficient, doesn't serve requests that are nearby

#### Disk Scheduling: SSTF
- Shortest Seek Time First: a bit better
- Answer the request on the nearest track,  goal is to minimize arm movement
- Main problem: starvation, if there is a stream of request for the same track, then some requests will never be served

#### Disk Scheduling: SATF
- Shortest Access Time First: compute time for every block, optimize that way
- Takes into account seek time and rotational delay to pick the next requests,
- Has the same starvation problem: If there is a stream of requests that are near each other, then some requests will never be served

#### Solving Starvation: Elevator
- Elevator Algorithms
- Just like an elevator in a building, the head goes from the inner track to the outer and back and forth
- Problem: Requests that come in for the current track may have to wait until the elevator comes back
- Really not good to minimize request service time
- Just like when you miss the elevator that is now going 30 floors up before coming back down to where you are
- These algorithms are very far from shortest job first idea
- Also, these algorithms completely ignore rotational delay

#### Disk Scheduling in the OS?
- OSes used to do disk scheduling
- Nowadays, it's implemented in the HDD's controller

#### HDD Formatting
- Physical formatting
    - Divides the disk into sectors
    - Fills the disk with a special data structure for each sector
        - A header, data area, and a trailer
    - In the header and trailer is a sector number, and extra bits for error-correcting code
    - All done at the factor before shipping
- Logical Formatting
    - OS first partitions the disk into one or more groups of cylinders: the partitions
    - OS treats each partition as a separate disk
    - File system information is written to the partitions

#### Bad Blocks
- Sometimes, data on the disk is corrupted and ECC can't fix it
- Errors occur due to 
    - Damage to platter's surface
    - Defect in magnetic medium due to wear
    - Temporary mechanical error
    - Temporary thermal malfunction
- Controller hides the bad blocks, the computer seems like its storage is getting smaller and smaller

#### Main Takeaways
- HDDs are slow due to moving parts
- Therefore, a key question is that of picking a good order in which disk blocks are read/written given a list of requested I/O operations
- Different algorithms exist, nowadays all implemented in the HDD controller, and in practice they are variations on the “elevator algorithm” theme
- The concept of formatting
- The controller hides bad block
- Modern OSes see the disk simply as a logical array of blocks, and all the complexity is in the controller
- HDDs are not fast, but they are big and cheap