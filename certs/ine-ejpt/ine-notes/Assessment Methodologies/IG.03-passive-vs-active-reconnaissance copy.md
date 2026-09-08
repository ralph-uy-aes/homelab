# IG.03 - Passive vs Active Reconnaissance

### Lesson Objective
- Understand the difference between active and passive reconnaissance
- Have a simple repeatable reconnaissance strategy before using tools
- This course also focuses on methodology, not tools

### Passive Information Gathering
- Collecting information without directly interacting with the target systems
- Characteristics:
    - No direct connection to target servers
    - Low risk of detection
    - Usually performed first
- Ex.
    - Domain registration information
    - DNS records
    - Public website content
    - Search results
    - Publicly available email addresses

### Active Information Gathering
- Direct interaction with target systems
- Characteristics
    - Sends traffic to the target
    - Increased visibility
    - Preformed after passive recon
- Ex.
    - Live hosts
    - Open ports
    - Running services
    - Network responses

### Big ol Tip
- Passive before active

### What Are We Collecting?
- Build a map of the target
    - Domains and subdomains
    - IP addresses
    - Hosting infrastructure
    - Technologies and services
    - Open ports
    - Publicly exposed information

### Typical Recon Mapping Flow
- Define Target Scope
- Passive Reconnaissance
    - Domains and Subdomains
    - DNS Records
    - Whois Data
    - Website Footprinting
    - OSINT
        - Search Engines
        - Emails
        - Breach Awareness
    - Technology Fingerprinting
- Active Reconnaissance
    - Host Discovery
    - Port Scanning
    - Basic Service Identification
    - DNS Zone Transfer Setting
- Organize Findings
- Proceed to Enumeration and Exploitation

### Recon Strategy
- Four Step Strategy
- First, Define the target
    - Identify domain, IP address, or network range
    - Confirm what is in scope
- Second, Perform passive reconnaissance
    - Gather public information
    - Identify potential attack surfaces
    - Build initial understanding of the target
- Third, Perform active reconnaissance
    - Discover live hosts
    - Identify open ports
    - Detect exposed services
- Fourth, Document and organize your findings
    - Record domains, IPs, and ports
    - Prepare information for enumeration
    - Avoid repeating work later

### Common Mistakes
- Starting scans without a well-defined scope
- Skipping passive reconnaissance
- Scanning everything instead of relevant targets
- Not documenting results
- Trusting tool output without verifying

### Key Takeaways
- Target Scoping - defines what you are allowed to test
- Passive before active
- Reconnaissance is about collecting MEANINGFUL data
- A structured approach means better results and efficiency