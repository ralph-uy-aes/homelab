# Chapter 9: Enterprise Architecture - Module A: System Vulnerabilities

#### Host Attack Surfaces
- Applications
    - Every application installed increases a system's attack surface
    - Malware is a serious risk, but other exploitable vulnerabilities exist
- Operating System Services
    - Modern OS have complex web of system services, built-in applications, and network functions that can have critical vulnerabilities
    - Worse than vulnerable third-party applications
- Firmware
    - BIOS or system software of embedded devices can have system vulnerabilities
    - Hard to patch and identify
- Drivers
    - Operate at a low level close to hardware
    - Vulnerable or maliciously altered drivers can be a significant threat
- Hardware Interfaces
    - Not all vulnerabilities can be targeted over the network
    - Attackers can target boot processes, physical storage devices, login methods, and peripheral connections
    - Physical access also makes it easier to perform unauthorized system modifications or just steal the whole system

#### Software Vulnerabilities
- Malware
    - One of the most common and obvious security threats
    - Can range from minor to sever in terms of impact
- Open Service Ports
    - Any network service listening on an open port increases the system's attack surface over the network
    - Unnecessary services and lax firewall rules create vulnerabilities, disable unused ports
- Unpatched Software
    - Unsupported legacy systems and applications are a particular risk since their vulnerabilities will not be fixed by a vendor patch
- Unauthorized Systems and Software
    - Any undocumented device, application, or network service in the enterprise is a vulnerability
    - Increases attack surface, but isn't accounted for in risk management or network hardening procedures
    - Not all rogue devices or shadow IT assets are malicious

#### Hardware and Firmware Vulnerabilities
- Malicious software or rootkits placed on preinstalled media or applications
- Altered firmware or system software that deliberately or accidentally introduces security flaws
- Spyware or hardware devices that snoop on trusted OS processes, VMs, or other processes with sensitive data in memory
- Booting a computer into an attacker-controlled operating system to access sensitive data protected by its regular OS
- Compromising a physically insecure network host, such as a remote access client, and using it to attack the rest of the network

#### Security Misconfigurations
- Weak or no passwords allow easy access
- Computers left unlocked and unattended mean anyone can access them without credentials
- Default credentials are included with many devices or applications, if they're not changed or removed, an attacker can simply look them up in system documentation
- When user accounts are given excessive privilege, especially regarding file access or system changes, an attacker who compromises an account can do more damage
- Insufficient logging and tracking of user activity makes identifying account compromise or misuse difficult

#### Malware
- Virus
    - Attaches malicious code to another file, which can do direct damage and spread itself to other running programs
    - Viruses themselves can be categorized
        - Program viruses infect executable files and are activated when you run the program
        - Boot sector viruses infect a drive's boot sector and are activated when the drive is first accessed
        - Macro viruses and script viruses infect data files used by applications with built-in scripting languages, such as MS Office, activated upon opening
    - Rely on human action
    - Active virus usually remain resident in memory, even when the application that installed it is no longer running
- Worm
    - Replicates itself by exploiting system vulnerabilities
    - Can spread through the network unassisted, exploiting vulnerable systems
    - Connecting to the internet could infect a PC in moments without any other human action
    - Today, worms include browser attacks that can infect your system even if you don't knowingly download executable files
- Trojan
    - Masquerades as a harmless program
    - Victim takes the seemingly harmless program and when they run it, the malicious functions take over
    - Considered social engineering attacks because they rely on human trust
- Bloatware/ Grayware
    - Subjective label for applications that aren't strictly malware, but aren't wanted by the user either
    - Usually comes bundled with other applications
    - Main issue is resource consumption, especially for cheaper PCs
    - Cybersecurity issue is increased attack surface
- Drive-by Download
    - A compromised website spreads malware to visitors
    - Some contain malicious scripts that exploit browser or plugin vulnerabilities
    - Others convince visitors to download infected files, spreading like a virus or trojan
    - Malicious link or redirect can send users to the site without knowing what it is or even that they've visited it
- Logic Bomb
    - Malicious code that lies dormant until a specific condition is met
    - Can spread like a virus, worm, or trojan, but popular for insiders with privileged access
    - Real case: 
        - Programmer at an insurance firm put code in the system that would be triggered if he was fired
        - Two years later, he was terminated
        - Logic bomb went off and deleted thousands of payroll records
    - Technically easter eggs like those found in games
- Removable Device
    - Removable devices have been used to spread viruses since the days of floppy drives
    - Allows offline hosts to be infected
    - Device might contain an executable or boot sector virus, but could also have HID spoofing hardware that identifies itself as a USB device and delivers a script to take control of the computer
    - HID spoofing can even affect seemingly ordinary USB cables as well as flash drives

#### Malware Payloads
- Payload defines the malicious actions it takes and the effects it has
- Backdoor
    - Any hidden way into a system or application that bypasses standard authentication processes
    - Can be used to gather data, remotely control computers, send spam emails, or almost anything the computer can
    - Example is the remote access trojan (RAT) which invisible installs a remote access program an attacker can later use to take control of the computer or spy on its user
- Command and Control (C2)
    - A more advanced form of backdoor that uses automated processes to establish and maintain remote control of infected systems
    - Malware with C2 functions sends beaconing messages looking for C2 servers belonging to the attacker
    - Once inside, the machine awaits further instructions
- Botnet
    - C2 often allows central control of large numbers of computers to achieve a common goal
    - Resulting networks are called botnets and the individual infected systems are called zombies
    - Botnet controllers can direct zombies to send emails, make DDoS attacks, steal data, or perform distributed computing tasks like Bitcoin mining, all without the system owners' knowledge
- Ransomware
    - Attempts to extort money from the victim to undo or prevent further damage
    - Disguised as a legitimate service, much like a trojan
- Spyware/Keylogger
    - Gathers information about users and computer activities to send to other parties
    - Can track browser activity, redirect network traffic, steal financial or user account information, or capture user input
    - Keyloggers capture user input including passwords and other sensitive data
- Adware
    - Delivers advertisements to the infected system, usually within a browser or other application windows
    - Frequently has a spyware component, even if it's just to track user activities and choose targeted ads
- Browser security compromises
    - Malware often manipulates computer behaviors to bypass standard security checks and enable other attacks against browsers and network clients

#### How Malware Hides
- Polymorphic Malware
    - Has a polymorphic engine that changes its code whenever it spreads
    - Involves some elements of encryption and randomization, alter the malware's signature to complicate detection but don't change how the code functions
- Stealth Malware
    - Has features to hide its effects from easy detection
    - Might carefully mask the modifications it makes to the system, move to a different file system or memory location, or intercept OS calls to fool other applications in to thinking everything is working normally
    - Retrovirus are stealth malware that attacks antimalware applications or signatures to avoid detection
- Fileless Malware
    - Stealth malware that does not permanently save any malicious files to the system's hard drive, evading detection by conventional file-based malware scanning
    - Examples include malicious scripts loaded into RAM and arbitrary code execution following a memory exploit
    - Usually does not persist after a system reboot, but can include persistence features that make the system easy to reinfect
- Rootkit
    - Named for early versions that allowed administrative root access to Unix-like OS, later developed stealth features designed to hide them from detection
    - Compromise boot systems and core OS functions to gain high-level access to hide them from most detection methods
    - Can even infect device firmware, requiring specialized equipment to remove or render the device unusable

#### Malicious Scripts
- PowerShell
    - Scripts designed to run in MS PowerShell command interpreter
    - Usually have a .ps1 extension
    - Based on the .NET framework and is much more powerful than the older Command Prompt
    - PowerShell scripts are often used for a wide range of administration and automation tasks in Windows systems
- bash
    - Scripts designed to run in Unix-like cli environments, such as bash or csh
    - Also known as shellcode and files sometimes have a .sh extension
    - Have similar risks to PowerShell scripts in that an attacker who can execute one with the right privileges can perform almost any system task
    - Commonly used to install or run software of the attacker's choice
    - Newer Windows editions that include the Windows Subsystem for Linux are also vulnerable to bash scripts
- Python
    - Scripts written in the Python language, often with a .py extension
    - Available for almost every OS and are installed by default on many distributions, so they're an easy avenue for cross-platform attacks
    - Windows does not include a Python interpreter by default, but Python programs can be compiled into an executable format for systems without one
- Macros
    - Scripting languages used to automate routine tasks
    - MS Office applications can perform a series of pre-recorded tasks on command, such as when a file is opened
- Visual Basic for Applications/ Visual Basic Script
    - A script written for MS Visual Basic macro language or its lightweight scripting language subset
    - VBA scripts in Office documents allow more sophisticated na powerful macros than UI-based recording and VBS scripts can also execute via the Windows Scripting Host or the IIS Web Server
- JavaScript
    - A script written to execute in a web browser or server
    - Used primarily in client-side attacks against web browsers and applications
    - Frequently embedded in links or attachments intended to be opened in a browser
    - Standalone files have a .js extension

#### Image-based Attacks
- Malware can be placed in image metadata. In 2022, a malware campaign distributed a photo of distant galaxies taken by the James Webb Telescope. While the image was certainly pretty, it contained a malicious URL that would download malware if certain Word macros were enabled.
- Steganography allows hidden information to be placed in the image data itself. While it’s unlikely to spread self-executable viruses, seemingly normal images can be used for data infiltration or exfiltration.
- Adversarial images can attack AI systems used for image recognition and other data processing. For example, researchers at the University of Adelaide created an image of a flower that a facial recognition system misidentified as Barack Obama. A random person holding the flower in a photo would likewise be identified as Obama instead of themselves

#### Defending Against Malware
- Ensure that all hardware and software are legitimately sourced and unaltered.
    - Only download software from verified, vendor-approved sources.
    - Use signed drivers and applications, or at least check downloads against securely obtained hashes.
    - Perform code review of custom software before deploying it.
    - Make sure the equipment has not been modified from its factory configuration.
- Ensure that all systems have anti-malware software with real-time monitoring installed and kept up to date.
    - There are a wide variety of antivirus applications, free and commercial, with different feature sets and capabilities—research which option best suits your organization’s needs.
    - Windows 8 and newer include real-time antivirus scanning by default, but older versions do not. 
    - You should only run one real-time scanner on a given system, but additional applications for manual or scheduled scans can provide vendor diversity
- Regulating system permissions can make it less likely for systems to become infected in the first place.
    - Restricting user permissions can make it more difficult for users to install trojan horses or viruses to gain the access they need to spread.
    - Restricting the use of removable media prevents malware from spreading on flash drives or similar vectors. Even if such devices aren’t blocked entirely, disabling auto-run features can reduce risk.
    - Regularly check systems for unexpected installed applications or running processes.•Regularly install security patches for operating systems and applications, especially browsers and their add-ons. Frequently they are designed to fix exploits used by malware.
- Network security features can protect against malware.
    - Firewalls can block the spread of worms.
    - Spam filters can recognize harmful email attachments.
    - IDS, SIEM, and network-based antimalware can detect assorted malware activities.
- Acceptable use policies and user education are essential tools in reducing malware risk.
    - Users should be aware of the risks of visiting unknown sites and installing untrusted software.
    - Users should be shown how to recognize phishing links and suspicious attachments.
    - Unknown removable media should not be used or plugged in out of curiosity.
    - Security software should only be disabled when, and for as long as, absolutely necessary

#### Automated Malware Analysis
- Heuristic methods can be used to identify when an unfamiliar program's behavior or characteristics resemble a virus's
- Sanboxing is a method in which an antimalware engine runs a suspicious program in an isolated environment where it can't make lasting system changes. Then, it examines the program's input, output, memory contents, and other details