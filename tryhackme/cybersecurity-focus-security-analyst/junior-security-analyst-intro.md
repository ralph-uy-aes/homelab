# Junior Security Analyst Intro

#### Career
- Junior Security Analysts are Triage Specialists
- A lot of time is spent triaging or monitoring event logs and alerts
- Responsibilities:
1. Monitor and investigate alerts (24/7 SOC operations)
2. Configure and manage the security tools
3. Develop and implement basic Intrusion Detection System or IDS signatures
4. Participate in SOC groups and meetings
5. Create tickets and escalate security incidents to the Tier 2 and Team Lead if necessary
- Required Qualifications (Entry-Level):
1. 0-2 Years of experience with Security Operations
2. Basic understanding of Networking such as OSI model, TCP/IP model, Operating Systems, Web Applications
3. Scripting/programming skills are a plus
- Certification:
1. CompTIA Security+
- Eventually, you can move up to Tier 2 and Tier 3 as a SOC analyst
- Levels
1. Tier 1 - Triage
    - Monitor network traffic logs and events
    - Work on tickets, close alerts
    - Perform basic investigations and mitigations
2. Tier 2 - Incident Responder
    - Focuses on deeper investigations, analysis, and remediation
    - Proactively hunts for adversaries
    - Monitors and resolves more complex alerts
3. Tier 3 - Threat Hunter
    - Work on more advanced investigations
    - Performs advanced threat hunting and adversary research
    - Malware reverse-engineering

#### Security Operations Center or SOC
- Investigates, monitors, prevents, and responds to cyber threats 24/7
- McAfee: "Security operations teams are charged with monitoring and protecting many assets such as intellectual property, personnel data, business systems, and brand integrity. As the implementation component of an organization's overall cyber security framework, security operations teams act as the central point of collaboration in coordinated efforts to monitor, assess, and defend against cyber attacks"
- The SOC Circle
1. Reporting
2. Ticketing
3. Log Collection
4. Knowledge Base
5. Research and Development
6. Aggregation and Correlation
7. Threat Intelligence
8. Security Information and Event Management or SIEM
- Preparation and Prevention
    - SOC Analysts must be informed of the current cyber security threats
    - Crucial to detect and hunt threats
    - Build a security roadmap for the organization and be ready for the worst-case scenario
    - Prevention Methods
        - Intelligence gathering (threats, threat actors, TTPs (Tactics, Techniques, and Procedures))
        - Maintenance procedures (update firewall, patch vulnerabilities, blacklisting, and whitelisting)
- Monitoring and Investigation
    - Using Security Information and Event Management or SIEMs, and Endpoint Detection and Response or EDRs tools, you can monitor suspicious and malicious network activity
        - Think a firefighter with alarms that explain the severity of the fire, category, etc...
        - Start with critical threats, then high, then medium, and low
    - Understand how attacks work and prevent bad things from happening
    - Drill down on data logs and alerts using open source tools
- Response
    - After investigation, take action on compromised hosts
    - Isolate the hosts from the network
    - Terminate malicious processes and delete files

#### Practical
- The first thing to do on your shift as a SOC analyst is to check your tickets and see if you have any alerts.
- I started by looking at the alert logs and noticed one in particular that attempted to connect without authorization
    - The same IP was able to SSH successfully, so it must be investigated
- I use an IP scanner to check if the IP is potentially malicious
    - Lots of open-source databases have this as a functionality such as AbuseIPDB, Cisco Talos Intelligence, etc...
    - The IP came out as malicious, so it must be escalated as a ticket to a SOC Team Lead
    - Recall how the same IP was able to log in, this is a high priority threat
- I block the IP address with approval from the SOC Team Lead and close the ticket

#### Summary
- This served to be a great introduction to what it means to be a junior SOC analyst. The responsibilities were outlined as well as what requirements you might need. Lastly, a practical simulation was given to show you what it's like to be a junior SOC analyst.