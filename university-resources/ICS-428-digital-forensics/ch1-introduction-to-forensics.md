# Chapter 1 - Introduction to Computer Forensics

## What is Computer Forensics?
- Forensics - "the use of science and technology to investigate and establish facts in criminal or civil courts of law"
    - Using science to process evidence to establish the facts of a case
- The modern world is full of devices that store data
    - Extraction of said data is the subject of computer forensics
    - Now this field is known as digital forensics
- US-CERT defines computer forensics as the process of using scientific knowledge for collecting, analyzing, and presenting evidence to the courts, dealing primarily with the recovery and analysis of latent evidence
    - The objective is to recover, analyze, and present computer-based material in a way that can be used as evidence in court
    - Strong emphasis on integrity and security of evidence
    - Any device that can store data is a potential subject of digital forensics

#### Using Scientific Knowledge
- Digital forensics is a science, not based on whims or gut feelings
    - Apply scientific methods and processes
    - Must have knowledge of relevant scientific disciplines
- Begins with a thorough understanding of computer hardware, then an understanding of operating systems, and the basics of computer networks

#### Collecting
- Before analysis, evidence must be collected
- There are specific procedures for properly collecting evidence
- The method of collecting evidence determines if it is admissible in a court

#### Analyzing
- One of the most time-consuming parts of a forensic investigation
- If you don't know enough, you may not see the significance of the data you have
- You need to be able to solve puzzles by putting data together and finding out what the bigger picture is

#### Presenting
- Once your investigation and analysis is done, the evidence must be presented in one form or another
- Two most basic forms are "expert report" and "expert testimony"
- Use plain English to interpret the arcane and paint an accurate picture for the court
    - Jargon and technobabble are not allowed
    - Use figures or graphics to demonstrate data

#### Expert Report
- Formal document that lists what tests you have conducted, what you found, and your conclusions
- Includes a curriculum vitae or CV which is like a resume with more detail regarding your experience as a forensic investigator
- Be able to back up your conclusions, generally have at least two or three references for every conclusion
    - Use US-CERT, FBI, US Secret Service, Cornell University Law School, etc... as valid references
- Most criminal court cases won't require a formal expert report, but you need to testify
- Civil court cases, especially intellectual property cases, have far more detailed reports with around 100 or more pages

#### Expert Testimony
- Testify as an expert witness, on the basis of scientific or technical knowledge nad not direct personal experience
- Two scenarios in which an expert testimony is given: deposition and trial
- Lying under oath during a testimony is a felony (perjury)
    - Destroys the expert's reputation
    - Better to be wrong than to tell a lie
- Depositions allow opposing counsel to ask you questions
    - It is best not to give more than what they ask for so that they're less prepared for trial
    - If you don't fully understand a questions, say so, ask for clarification
    - If you really don't know, say so, never guess
    - If you are not 100% certain, say so
    - Review any document being referred to, do not testify from memory
- Be prepared for deposition and trial testimonies:
    - Document and do every forensic process correctly
    - Use charts, diagrams, and other graphics
    - Prepare before you testify, re-read notes and your report
    - Keep calm and tell the truth
    - Don't try to be evasive when asked a question, answer directly
- US Federal Rules:
    - 702: 
        - A witness who is qualified as an expert by knowledge, skill, experience, training, or education may testify in the form of an opinion or otherwise if the proponent demonstrates to the court that it is more likely than not that:
        - (a) the expert’s scientific, technical, or other specialized knowledge will help the trier of fact to understand the evidence or to determine a fact in issue;
        - (b) the testimony is based on sufficient facts or data;
        - (c) the testimony is the product of reliable principles and methods; and
        - (d) the expert's opinion reflects a reliable application of the principles and methods to the facts of the case.
    - 703 Bases of an expert:
        - An expert may base an opinion on facts or data in the case that the expert has been made aware of or personally observed. If experts in the particular field would reasonably rely on those kinds of facts or data in forming an opinion on the subject, they need not be admissible for the opinion to be admitted. But if the facts or data would otherwise be inadmissible, the proponent of the opinion may disclose them to the jury only if their probative value in helping the jury evaluate the opinion substantially outweighs their prejudicial effect.
    - 704 Opinion on ultimate issue:
        - (a) In General — Not Automatically Objectionable. An opinion is not objectionable just because it embraces an ultimate issue.
        - (b) Exception. In a criminal case, an expert witness must not state an opinion about whether the defendant did or did not have a mental state or condition that constitutes an element of the crime charged or of a defense. Those matters are for the trier of fact alone.
    - 705 Disclosing the facts or data underlying an expert:
        - Unless the court orders otherwise, an expert may state an opinion — and give the reasons for it — without first testifying to the underlying facts or data. But the expert may be required to disclose those facts or data on cross-examination.
    - 706 Court-appointed expert witness:
        - Covers the appointment of neutral experts used to advise the court. Such experts are working for neither the plaintiff nor the defendant; they work for the court
    - 401 Test for relevant evidence:
        - Evidence is relevant if:
        - (a) it has any tendency to make a fact more or less probable than it would be without the evidence; and
        - (b) the fact is of consequence in determining the action.

## Understanding the Field of Digital Forensics
- The field is rapidly changing
- The military uses digital forensics to gather intelligence information from captured computers
- Government agencies use it to investigate crimes involving computers
- Law firms need experienced system forensics professionals to conduct investigations and testify as expert witnesses
- Criminal prosecutors use it when working with incriminating documents
- Academia is involved with forensic research and education
- Data recovery firms use digital forensics techniques to recover data after hardware or software failures
- Corporations use it to assist in employee termination and prosecution
- Insurance companies use digital evidence of possible fraud in accident, arson, and workers' compensation cases
- Individuals sometimes hire forensic specialists in support of possible claims

#### What is Digital Evidence?
- Information that has been processed and assembled to be relevant to an investigation
    - Not all raw information is evidence, data must be relevant
- A chain of custody is the continuity of control of evidence that makes it possible to account for all that has happened to evidence between its original collection and its appearance in court
- Four types of evidence:
    - Real
        - Physical object that can be touched or directly observed
        - Laptops with fingerprints, hard drives, USBs
    - Documentary
        - Data stored as written matter on paper or electronic files
        - Includes memory-resident data and computer files
        - Emails, logs, databases, photographs, metadata
    - Testimonial
        - Information used to support or interpret real or documentary evidence
        - Testimonial evidence may be used to demonstrate that fingerprints belong to a specific individual
        - Access controls can show that a user stored specific files on a desktop
    - Demonstrative
        - Information that helps explain any other evidence
        - Ex. chart explaining a technical concept to the judge and jury
        - Pictures often communicate better than just numbers and words

#### Scope-Related Challenges to System Forensics
1. Large Volumes of Data
2. Complexity of Computer System
3. Size and Character of Crime Scene
4. Size of Caseload and Resource Limitations
- Regardless of these factors, forensic specialists must be prepared to quickly complete an analysis regardless of these factors

#### Types of Digital Forensics Analysis
- Disk Forensics: Acquiring and analyzing information stored on physical storage media
- Email Forensics: Study of source and content of email as evidence
- Network Forensics: Examining network traffic, including transaction logs and real-time monitoring using sniffers and tracing
- Software Forensics: AKA malware forensics, examining malicious computer code
- Live System Forensics: Searching memory in real time, working with compromised hosts or to identify system abuse, requires specialized skills and training
- Cellphone Forensics: Searching the contents of cellphones

## General Guidelines

#### Chain of Custody
- Most important principle in any forensic effort, digital or non-digital
- Whereabouts and custody of evidence, how it was handled and stored, must be able to be shown at all times
- Failure to do so can lead to evidence being excluded

#### Don't Touch the Suspect Drive
- Touch the system as little as possible
- Possible to make changes to the system in the process of examining it, which is very undesirable
- Make a forensic copy and work with that
    - Use AccessData's Forensic Toolkit, Guidance Software's EnCase, or PassMark's OSForensics
- Sometimes direct interaction with live evidence is needed
    - Initial discovery of a system might require initial analysis to determine running processes and connections before making an image

#### Document Trail
- Document everything
- Who was present upon seizure?
- What was connected to the device or showing on the screen when seized?
- What tools and techniques were used?
- Etc...
- Impossible to document too much information, better to over-document

#### Secure the Evidence
- Critical to investigation integrity to maintain chain of custody
- Common to have forensic lab be a locked room with access given only to those who must enter
- Make sure no one can tamper with the evidence

## Knowledge Needed for Computer Forensics Analysis
- A certain background body of knowledge is required to conduct digital forensics

#### Random Access Memory
- One way to examine RAM is to look at the method whereby information is written to and read from the RAM
- From older to newer technologies:
    - Extended Data Out Dynamic Random Access Memory (EDO DRAM)
        - Single-cycle EDO has the ability to carry out a complete memory transaction in one clock cycle
        - Otherwise, each sequential RAM access within the same page takes two clock cycles instead of three, once the page has been selected
    - Burst EDO (BEDO) DRAM
        - An evolution of EDO, can process four memory addresses in one burst
    - Asynchronous Dynamic Random Access Memory (ADRAM)
        - ADRAM is not synchronized to the CPU clock
    - Synchronous Dynamic Random Access Memory (SDRAM)
        - SDRAM is a replacement for EDO
    - Double Data Rate (DDR) SDRAM
        - A later development of SDRAM
        - DDR2, DDR3, DDR4, and DDR5 are now available
- Volatility can also vary:
    - Random Access Memory (RAM)
        - Easy to write to and read from
        - Very volatile, without power the data is gone
    - Read-only Memory (ROM)
        - Not volatile at all, cannot be changed
        - Usually used for instructions embedded in chips and controls how the computer, option cards, peripherals, and other devices operate
    - Programmable Read-only Memory (PROM)
        - Can be programmed only once
        - Data is not lost when power is removed
    - Erasable Programmable Read-only Memory (EPROM)
        - Data is not lost when power is removed
        - EPROM is a technique for storing instructions on chips
    - Electronically Erasable Programmable Read-only Memory (EEPROM)
        - How the instructions on BIOS are stored

#### Hard Drives
- Forensic specialist must also understand the following storage devices
    - Small Computer System Interface (SCSI)
        - Has been around for many years
        - Popular in high-end servers
        - Must have a terminator at the end of the chain of devices to work and are limited to 16 chained devices
    - Integrated Drive Electronics (IDE)
        - Commonly used on PCs for many years
        - 40-pin connector indicates an IDE or EIDE drive
    - Enhanced Integrated Drive Electronics (EIDE)
        - Extension or enhancement of IDE
    - Parallel Advanced Technology Attachment (PATA)
        - Enhancement of IDE
        - Uses either 40-pin or 80-pin connector
    - Serial Advanced Technology Attachment (SATA)
        - What you are most likely to find today
        - Commonly found in workstations and many servers
        - Similar internals to IDE and EIDE, but connectivity to MOBO is different
        - Has no jumpers to set the drive
    - Serial SCSI
        - Enhancement of SCSI
        - Supports up to 65,537 drives and does not require termination
    - Solid-State Drives (SSDs)
        - More and more common
        - Different construction and method of storage
        - Use microchips that retain data in non-volatile memory chips and contain no moving parts
- All of these except for SSDs refer to how the drive connects to the MOBO and transfers data
- HDDs record data by magnetizing ferromagnetic material directionally to represent either a 0 or a 1 binary digit
    - Stored on platters, organized on a spindle with a read/write head reading and writing data to and from the platters
    - Organized as follows:
        - Sector is the basic unit of data storage on a hard disk, usually 512 bytes, newer systems use a 4096-byte sector size
        - Cluster is a logical grouping of sectors, can be 1 to 128 sectors in size or 512 bytes up to 64 kilobytes
        - Sectors are in turn organized by tracks
        - Drive geometry refers to the functional dimensions of a drive in terms of the number of heads, cylinders, and sectors per track
    - Low-level format creates a structure of sectors, tracks, and clusters
    - High-level format is the process of setting up an empty file system on the disk and installing a boot sector, sometimes referred to as a quick format

#### Windows
- The Windows Registry is the heart of Windows
    - Repository for all settings, software, and parameters for Windows
    - Updated to indicate and store new software, wallpaper changes, passwords for wireless networks, serial numbers of all USB devices, etc...
- Windows has other interesting places to look for forensic evidence such as certain folders and files
- Browser cookies and history can also be useful
- Windows is a very common OS, be familiar with it

#### Linux
- Interesting OS, not as widely used as Windows
- A favorite OS in the security and forensics community
- UNIX clone developed by Linus Torvalds
- Now there are well over 100 distros of Linux, most of the work is done from the command line or shell in Linux

#### Mac OS
- Based on FreeBSD, a UNIX clone very similar to Linux
- Underlying OS is a UNIX-like system
- Many forensic techniques used on Linux can also be used on Mac OS from the shell prompt

#### Files and File Systems
- Computers store discrete sets of related information in files
- Very easy to change the extension of a file to resemble another type of file, but will not change the file structure itself
- Examining the file header will give you a more accurate description of the exact file type than simply looking at the extension
    - File headers start at the first byte of a file
- File systems:
    - File Allocation Table (FAT)
        - First implemented in MS Standalone Disk BASIC
        - Stores file locations by sector in a file called the file allocation table
        - Contains information about which clusters are being used by which particular files and which clusters are free to be used
        - FAT16 and FAT32 differ in the number of bits available for filenames
    - New Technology File System (NTFS)
        - Introduce by MS in 1993 to replace FAT
        - Increased volume sizes that could be supported
    - Resilient File System (ReFS)
        - New file system from MS
        - A more resilient file system
        - Checksums for both metadata and file data as well as proactive error correction
    - Apple File System (APFS)
        - Default file system for Apple computers
        - Supports encryption, snapshots, and other features
        - Optimized for SSD use, but can also be used with traditional hard drives
    - Extended File System
        - First file system created for Linux
    - ReiserFS
        - Popular file system used primarily with Linux
        - First file system to be included with the standard Linux kernel
        - First appeared in Kernel version 2.4.1
    - Berkeley Fast File System
        - AKA UNIX file system
        - Developed at UC Berkeley specifically for UNIX
        - Uses bitmap to track free clusters, indicating which are available and not

#### Networks
- Information at rest vs information in motion
    - Anything at rest is stored inside the computer, including file system or memory
    - Anything in motion is being transmitted between endpoints and includes the protocols and other information needed for transmission
- Forensic investigators must be familiar with Open Systems Interconnection (OSI) Reference model and Internet Engineering Task  Force (IETF) model

#### Addresses
- Be aware of the way computer information is addressed and the proper vocabulary for discussing different types of addresses and units of information transfer
- Understand that not all addresses are a part of every communication
- Physical ports
    - Can be touched
    - Physical ports operate at OSI Layer 1 the Physical Layer
    - Units of information transfer are 1 and 0 bits grouped into fixed-length units called Layer 1 frames
- Media Access Control (MAC) Addresses
    - 6-byte address used to identify a network interface card
    - First three bytes identify the vendor, second three identify the specific card
    - Unique, tied to only one physical port, never duplicated or reused for any reason
- IP Addresses
    - Sometimes called logical addressed
    - Assigned to a computer and can easily be changed
    - IPv6 has been available for some time, majority of computers are still using IPv4 which provides a 32-bit address
- Logical Port Numbers
    - 20, 21 - FTP
    - 22 - SSH, SFTP
    - 23 - Telnet
    - 25 - SMTP
    - 43 - WhoIS
    - 53 - DNS
    - 69 - TFTP
    - 80 - HTTP
    - 88 - Kerberos Authentication
    - 109 - POP2
    - 110 - POP3
    - 137, 138, 139 - NetBIOS
    - 161 - SNMP
    - 179 - BGP (Border Gateway Protocol)
    - 194 - IRC
    - 220 - IMAP
    - 389 - LDAP
    - 443 - HTTPS
    - 445 - Active Directory, SMB
    - 464 - Kerberos
    - 465 - SMTP over SSL
    - 636 - LDAP over SSL/TLS
- Uniform Resource Locators
    - Allows internet users to type a name instead of an IP address
    - Introduced a number of potential forensic issues ranging from changing the mapping of website name to IP address permanently or temporarily
- Addressing Review
    - Most common that user information such as email text would be formatted as specified by the email protocol
    - A URL would be used to then find the actual IP address of the recipient
    - The message would be formatted per the TCP protocol and sent with the proper TCP port number set to the IP addresses

#### Basic Network Utilities
- Can be executed from a command line interface or from a shell
- `ipconfig`
    - Gives you information about your own system's connection to a network or to the internet
    - You can find out your own IP address
    - Also has the IP address for your default gateway, your connection to the outside world
    - `ipconfig/all` gives you the name of your computer, when your computer obtained the IP address it has, and more
- `ping`
    - Used to send a test or echo packet to a machine to find out if it is reachable and how long the packet takes to reach the machine
    - Useful diagnostic tool can be employed in elementary hacking techniques
- `tracert`
    - Useful for some live network troubleshooting
    - Information derived is not useful or trustworthy for forensic examination
    - In Linux it is `traceroute`

#### Obscured Information
- Scrambled using encryption, steganographic software, compressed, or in a proprietary file format
- Cyber-criminals obscure information to deter forensic examination
- Companies use certain manipulation and storage techniques to protect business-sensitive information

#### Anti-Forensics
- Perpetrators may use techniques to conceal their identities, locations, and behavior
- Using networked connections at a library, internet cafe, public computer kiosk, etc...
- Technique examples:
    - Data Destruction
        - Wiping memory buffers used by a program
        - Overwriting data clusters using 1s and 0s
        - Destroying volatile memory
        - Deleting files and folders and defragmenting hard drives
    - Data Hiding
        - Store data where an investigator is unlikely to find it
        - May hide data in reserved disk sectors, or as logical partitions within a defined, public partition
    - Data Transformation
        - Process information in a way that disguises its meaning
        - May use encryption to scramble a message based on an algorithm
        - Or use steganography to hide a message inside a larger message
    - File System Alteration
        - Corruption of data structures and files that organize data such as NTFS volumes

## The Daubert Standard
- Standard used by a trial judge to make a preliminary assessment of whether an expert's scientific testimony is based on reasoning or methodology that is scientifically valid and can properly be applied to the facts at issue. Under this standard, the factors that may be considered in determining whether the methodology is valid are: (1) whether the theory or technique in question can be and has been tested; (2) whether it has been subjected to peer review and publication; (3) its known or potential error rate; (4) the existence and maintenance of standards controlling its operation; and (5) whether it has attracted widespread acceptance within a relevant scientific community
- The Daubert Challenge is a motion to exclude all or part of a testimony due to it failing to meet the Daubert standard

## US Laws Affecting Digital Forensics

#### Federal Privacy Act of 1974
- Establishes a code of information-handling practices that governs the collection, maintenance, use, and dissemination of information about individuals that is maintained in systems of records 
- Groups of records under the control of an agency from which information is retrieved by the name of the individual or by some identifier assigned to the individual

#### Privacy Protection Act of 1980
- Protects journalists from being required to turn over to law enforcement any work product and documentary materials, including sources, before it is disseminated to the public
- Journalists who most need the protection of the PPA are those who are working on highly controversial stories

#### Communications Assistance to Law Enforcement Act of 1994
- Federal wiretap law for traditional wired telephony
- Expanded to include wireless, voice over packets, and other forms of electronic communications

#### Unlawful Access to Stored Communications: 18 USC Section 2701
- Access to a facility through which electronic communication is provided or exceeding the access that was authorized
- It is broadly written to apply to a range of offenses

#### The Electronic Communications Privacy Act of 1986
- Governs the privacy and disclosure, access, and interception of content and traffic data related to electronic communications

#### The Computer Security Act of 1987
- Passed to improve the security and privacy of sensitive information in federal computer systems
- Requires establishment of minimum acceptable security practices, creation of computer security plans, and training of system users or owners of facilities that house sensitive information

#### The Child Protection and Sexual Predator Punishment Act of 1998
- Requires service providers that become aware of the storage or transmission of child pornography to report it to law enforcement

#### The Children's Online Privacy Protection Act of 1998
- COPPA protects children 13 and under from collection and use of their personal information by websites

#### The Communications Decency Act of 1996
- Protects persons 18 and under from downloading or viewing indecent material

#### The Telecommunications Act of 1996
- Includes many provisions relative to the privacy and disclosure of information in motion through and across telephony and computer networks

#### The Wireless Communications and Public Safety Act of 1999
- Allows for collection and use of empty communications which means nonverbal and nontext communications

#### The USA PATRIOT Act
- Primary law under which a wide variety of internet and communications information content and metadata is currently collected

#### The Sarbanes-Oxley Act of 2002
- Contains many provisions about record-keeping and destruction of electronic records relating to management and operation of publicly held companies

#### 18 USC 1030 Fraud and Related Activity in Connection with Computers
- This is one of the most widely used laws in hacking cases, covers a wide range of crimes involving illicit access of any computer

#### The Digital Millennium Copyright Act (DMCA)
- Controversial law enacted in 1998
- Crime to publish methods or techniques to circumvent copyright protection
- Has been used against legitimate researchers publishing research papers

#### 18 USC Section 1028A Identity Theft and Aggravated Identity Theft
- Law targets any crime related to identity theft, often applied in stolen credit card cases

#### 18 USC Section 2251 Sexual Exploitation of Children
- Covers a range of child exploitation crimes and is often seen in child pornography cases

#### Warrants
- Warrants are not needed when evidence is in plain sight
    - If a person is clearly viewing "CP" in public and a detective catches this, no warrant is needed
- Warrants are also not needed if you consent to a search
- Border crossing individuals are subject to searches, this can include a complete forensic examination of laptops, cellphones, and other devices

## Federal Guidelines

#### The FBI
- If an incident occurs, the FBI recommends that the first responder should preserve the state of the computer at the time of the incident by making a backup copy of any logs, damaged, or altered files
- For incidents in progress, activate any auditing or recording software
    - Collect as much data as possible
- Common forms of computer evidence:
    - Hard drives
    - System logs
    - Portable storage
    - Router logs
    - Emails
    - Chat room logs
    - Cellphones
    - SIM cards
    - Logs from IDS or IPS or firewalls
    - Database and database logs
- FBI also suggests to work with a copy of a hard drive, not the original

#### The Secret Service
- Premier federal agency tasked with combating cyber crime
- Offers online courses in their website for computer forensics
- Secret Service's Golden Rules to begin investigation:
    - Officer safety: Secure the scene and make it safe
    - If you reasonably believe that the computer is involved in the crime you're investigating, take immediate steps to preserve the evidence
    - Determine whether you have a legal basis to seize the computer, such as plain view, search warrant, or consent
    - Do not access any computer files. If the computer is off, leave it off
    - If it is on, do not start searching through the computer. Instead, properly shut down the computer and prepare it for transport as evidence
    - If you reasonably believe that the computer is destroying evidence, immediately shut down the computer by pulling the power cord from the back of the computer
    - If a camera is available and the computer is on, take pictures of the screen. If it is off, take pictures of the computer, the location of the computer, and any electronic media attached
    - Determine whether the special legal or privacy considerations apply, such as those for doctors, attorneys, clergy, psychiatrists, newspapers, or publishers

#### The Regional Computer Forensics Laboratory Program (RCFL)
- The RCFL Program is a national network of forensic laboratories and training centers. The FBI provides startup and operation funding, training, staff, and equipment to the program
- Each of the 16 RCFLs examines digital evidence in support of criminal and national security investigations
- Provides law enforcement at all levels with digital forensics expertise
- Work with a wide variety of investigations such as terrorism, "CP", and homicide