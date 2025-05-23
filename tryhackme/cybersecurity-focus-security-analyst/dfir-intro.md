# DFIR: An Introduction

#### Digital Forensics and Incident Response
- Encompasses the collection of forensic artifacts from devices in order to investigate incidents
- Identify footprints left by attackers to determine the extent of compromise in an environment
- Restore the environment to the state before the attack occurred
- The need for DFIR
    - Finding evidence of attacker activity and differentiating real attacks from false alarms
    - Robustly remove the attacker, ensuring they no longer have a foothold in the system
    - Identify the extent and timeframe of a breach to communicate with stakeholders
    - Find loopholes that were used in the breach to patch them
    - Understand the behavior of the attacker to block further intrusion attempts
    - Share information of the attack with the community
- Who performs DFIR
    - Digital Forensics are performed by professionals in identifying forensic artifacts or evidence of human activity in devices
    - Incident Response is performed by professionals in cybersecurity, leveraging forensic information to identify activity of interest
- DFIR combines digital forensics and cybersecurity
    - DF and IR are combined because they're also highly independent
    - IR leverages the knowledge gained from DF
    - DF takes its scope and goals from IR

#### Basic Concepts
- Artifacts
    - Pieces of evidence that point to an activity performed in the system
    - Collected to support a claim or hypothesis about hacker activity
    - For example, an attacker could've used Windows registry keys to maintain persistence on a system
        - This registry key would be an artifact that a professional would collect
    - Artifacts can be found from Endpoint or Server's file system, memory, or network activity
- Evidence Preservation
    - Maintaining the integrity of collected evidence is a priority
    - Any sort of forensic analysis contaminates the evidence
    - Evidence must be write-protected and copied for analysis
    - If the copy gets corrupted, then you still have a backup
- Chain of Custody
    - Asks the question who should and shouldn't have access to the evidence
    - Evidence must also be kept securely in order to avoid contamination
    - Keeping the integrity of the data is vital to avoid weakening the case being built on it
- Order of Volatility
    - Evidence can be and is often volatile, can be lost forever if not captured on time
    - For example, data in RAM will be lost on shut down
    - Hard drive evidence would be less volatile than that of RAM, so it would have a lower order of volatility
    - DFIR requires an appropriate understanding of order of volatility of different sources
    - RAM data would need to be prioritized before hard drive data for example
- Timeline Creation
    - Upon collecting artifacts and maintaining their integrity, presenting them in a way that is easy to understand is vital to ensuring that it doesn't happen again
    - A timeline of events needs to be created to efficiently analyze these
    - Provides perspective to the investigation and helps collate information from various sources

#### DFIR Tools
1. Eric Zimmerman's Tools
    - A security researcher who has written tools to perform forensic analysis on Windows
    - Help the registry, file system, timeline, and many other analyses
    - See Windows Forensics 1 and Windows Forensics 2 rooms on THM
2. KAPE
    - Kroll Artifact Parser and Extractor or KAPE is another tool made by Eric Zimmerman
    - It automates the collection and parsing of forensic artifacts and can create a timeline of events
    - See KAPE room on THM
3. Autopsy
    - An open-source forensics platform that helps to analyze data from mobile devices, hard drives, and removable drives
    - Has plugins that improve its functionality
    - See Autopsy room on THM
4. Volatility
    - A tool to help perform memory analysis for memory captures on both Windows and Linux
    - Helps extract valuable information from the memory of a machine
    - See Volatility room on THM
5. Redline
    - An incident response tool freely distributed by FireEye
    - Can gather forensic data from a system and help with collected forensic information
    - See Redline room on THM
6. Velociraptor
    - Advanced endpoint-monitoring, forensics, and response powerful
    - Open-source, all-in-one, and very powerful
    - See Velociraptor room on THM

#### Incident Response Process
- NIST SP-800-61 Incident Handling guide
1. Preparation
2. Detection and Analysis
3. Containment, Eradication, and Recovery
4. Post-incident Activity
- Incident Handler's handbook (PICERL)
1. Preparation
2. Identification
3. Containment
4. Eradication
5. Recovery
6. Lessons Learned
- Both of these are pretty similar, as NIST just combines some of the steps in PICERL into one
- Preparation
    - Before an incident happens, everyone must be prepared in case of an incident
    - This means people, processes, and technology to prevent and respond to incidents
- Identification
    - Indicators of an incident identify it
    - Indicators are analyzed for false positives and then documented and communicated to stakeholders
- Containment
    - The incident is contained in order to limit its effects
    - Can be short-term and long-term fixes
- Eradication
    - The threat is eradicated from the network
    - If the entry point of the threat actor into the network is not plugged on top of eradicating the threat, the actor can gain a foothold again
- Recovery
    - Once the threat is removed, any service that had been disrupted are brought back
- Lessons Learned
    - Incident is reviewed and document
    - Steps are taken based on the findings from the incident to prepare the team better and the cycle repeats

#### Summary
- This is a great introduction to the process of DFIR. I learned about different tools that I can use as well as two different, but similar frameworks for incident response. I learned of a few key terms pertaining to DFIR and accomplished a practical simulation to act like a digital forensics professional. I learned of the NIST SP-800-61 incident handling guide and the PICERL or the SANS incident handler's handbook