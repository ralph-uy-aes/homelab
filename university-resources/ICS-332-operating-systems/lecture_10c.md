# Lecture 10C - RAID

#### RAID
- Whenever we use a disk we want it to be faster, bigger, and/or more reliable
- Concept: when one disk fails, you have another
- Redundant Array of Independent Disks
    - Software implemented at the OS level
    - An intelligent RAID controller in hardware
    - A "RAID array" as a stand alone box
- From the outside, it just looks like a single disk
- This is called transparency (another term for virtualization)

#### RAID Levels
- RAID-0, RAID-1, RAID-4, and RAID-5
- RAID-50 doesn't mean 50 levels, it means RAID-5 + RAID-0

#### RAID-0: Striping
- No redundancy
- We take data and we stripe it across the disks
- Gives the illusion of a larger disk with higher bandwidth when reading/writing a file
    - Accessing a single strip is not any faster
- Improves performance, but not reliability
- Useful for high-performance applications
- 100% performance, but also likely data loss

#### RAID-1: Mirroring
- Also called shadowing
- Write each byte to 2 disks
- Uses twice as many disks as RAID-0
- Vastly increases reliability unless you have extremely unlikely simultaneous failures
- Performance can be boosted by reading from disk with fastest seek time if using HDDs

#### RAID-10: Stripe and Mirror
- One can do mirroring and striping with each mirror

#### RAID-4: Parity
- Stores parity bits for each block/stripe so that lost data within one disk fails can be reconstructed
- Parity bits can help reconstruct missing bytes
- Basically, a bunch of XORs
- Example
    - Say you store 4 bits on a disk: 0 1 1 0
    - You compute a 5th bit (the parity bit) as the XOR of those bits: (((0 xor 1) xor 1) xor 0) =0
    - You store that bit somewhere on another disk
        - So to store 4 bits, you use 5 bits
    - Say you lose one bit: 0 ? 1 0
    - You can XOR the remaining bits with the parity bit to recover the lost bit: (((0 xor 0) xor 1) xor 0) = 1
    - Say you lose a different bit: 0 1 1 ?
    - The XOR still works: (((0 xor 1) xor 1) xor 0) = 0

#### RAID-5: Spread out Parity
- All disks store some of the parity bits
- Better for random writes because writes of parity bits can happen in parallel
- RAID-4 is almost never used and RAID-5 is preferred

#### Main Takeaways 
- RAID can be used to:
    - Boost performance
    - Boost resilience
    - Boost both
- Different RAID levels have different properties for performance and resilience
- RAID can be implemented in software, but typically it’s part of a hardware controller
- A key technique is to use parity bits computed via XOR to recover lost data