# Cyber Kill Chain
#### Cyber Kill Chain Framework
- The chain of an attack structured in a way that involves target identification, decision and order to attack, and finally target destruction
- Established by Lockheed Martin
- To successfully attack, an adversary must go through all the phases of the kill chain
- Important to understand and protect against ransomware attacks, security breaches and Advanced Persistent Threats (APT)
	- Cyber Kill Chains can be used to assess network and system security by identifying missing security controls and closing security gaps
	- Knowing the Kill Chain allows you to recognize patterns of intrusion and intruder's goals and how to break the Kill Chain

#### Reconnaissance Phase
- The first step in the kill chain is collecting information about the victim, this is the **planning phase**
- **OSINT** (Open-Source INTelligence)
	- Attacker needs to understand the victim by collecting as much information as possible
	- An attack on a company may involve knowing the size of the company, employees, etc..
- **Email Harvesting**
	- The process of obtaining email addresses from public, paid, or free services
	- Attackers use this for a phishing attack 
	- Hacker's email harvesting arsenals can be expansive:
		- theHarvester - besides gathering emails, also gathers names, subdomains, IPs, and URLs using OSINT
		- Hunter.io - email hunting tool that lets you obtain contact information associated with the domain
		- OSINT Framework - provides collection of OSINT tools based on various categories

#### Weaponization Phase
- After reconnaissance, work on creating a weapon of destruction
- Sometimes, acting behind the scenes without directly interacting with the victim is desired
- A "weaponizer" is created which combines malware and exploit into a deliverable payload
	- Hackers can either use automated tools to generate the malware or go to the DarkWeb to purchase malware
	- More sophisticated actors or APT groups write their own malware to make it sample unique and to evade detection
- Terminology
	- **Malware**: a program or software designed to disrupt or gain unauthorized access to a computer
	- **Exploit**: a program or code that takes advantage of a vulnerability or flaw in a system or application
	- **Payload**: malicious code that hackers run on a system
- Weapon examples:
	- Create an infected Microsoft Office document that contains a malicious macro or VBA script
	- Malicious payload or sophisticated worm inside multiple USB drives that are distributed to the public (virus)
	- Command and Control (C2) techniques execute commands on a victim's machine or deliver more payloads (See MITRE ATT&CK)
	- Select a backdoor implant to evade security mechanisms

#### Delivery Phase
- After building the weapon, find a way to transmit it
- Phishing Emails
	- A malicious email is created to target a specific person or multiple people
	- The email contains the payload or malware
	- Suppose an attacker finds the name of your best friend, so he creates a decoy email with your best friend's name. He sends you the phishing email with your friend's name, so you open it.
- Infected USB Drives
	- Intentionally dropping USB drives in public places like coffee shops, parking lots, classrooms, etc..
	- Attackers could even intentionally give you a USB device acting like it's a gift
	- Or even better, sell you an infected hard drive or SSD
- Watering Hole Attack
	- Targeted attack designed to aim at a specific group of people by compromising a website that they usually visit collectively, but then redirecting it to a malicious website
	- Find a known vulnerability on the website and try to exploit it
	- After visiting the website, the victim unintentionally downloads malware to their computer
		- Also called a "Drive-By Download"
	- Ex. Ads that make you install a fake browser extension

#### Exploitation Phase
- After transmitting it and gaining access to a system, find ways on exploiting your new access and getting value out of it
- Lateral Movement
	- Techniques that a malicious actor uses after gaining initial access to the victim's machine to move deeper into a network and get sensitive data
- Zero-day Exploit
	- An unknown exploit in the wild that exposes a vulnerability in software or hardware
	- Creates complicated problems before anyone realizes anything is wrong
	- No opportunity for detection at the beginning
		- Because it is brand-new
- Exploitation examples:
	- Victim triggers the exploit by interacting with the payload
	- Using a zero-day exploit
	- Exploit software, hardware, and human vulnerabilities
	- Attacker triggers exploits for server-based vulnerabilities

#### Installation Phase
- After gaining access and exploiting it of resources, you want to be able to come back at some point
- Backdoors, also known as access points, allow attackers to regain access to a system in case they lose connection
	- But, these can get revoked if the system is patched or if he loses connection to the system
- Persistent Backdoors let the attacker access systems that he has compromised in the past
	- Achieved through:
		- Web Shells: malicious scripts that have simple file formatting that are hard to detect due to how benign they seem (.php, .asp, .aspx, .jsp)
		- Backdoor on Victim's Machine: Meterpreter is a Metasploit framework payload that gives an interactive shell to the attacker remotely that can be used to execute malicious codes on the victim's machine
		- Creating and Modifying Windows Services: known as T1543.003 in MITRE ATT&CK, you can create Windows services that execute malicious scripts regularly to exhibit persistence (sc.exe for example)
			- Masqueraded services are ones that look like regular Windows services, but are modified to be malicious
		- Registry or Startup: by adding run keys of the payload into the registry or startup folder, it executes whenever the user logs in
- Timestomping
	- Allows an attacker to modify a file's timestamps, including the modify, access, create, and change times
	- Makes detection harder for a forensic investigator because the malware appears to be a legitimate program

#### Command & Control Phase
- After gaining persistence, the C2 channel is opened up
- This allows the attacker to remotely control and manipulate the victim
- C&C or C2 Beaconing
	- A type of malicious communication between a C&C server and malware on the infected host
- Infected hosts consistently communicate with the C2 server
	- The compromised end point communicates with the external server of the attacker
	- Once established, the hacker has full control of the victim's machine
- Internet Rely Chat (IRC)
	- Traditional C2 channel used by attackers
	- No longer used as they are easily detectable due to modern security solutions
- Common Modern C2 Channels:
	- HTTP on port 80 and HTTPS on port 443: blends malicious traffic with legitimate traffic to evade firewalls
	- DNS: infected machine makes DNS requests to the DNS server owned by the attacker. This is called DNS Tunneling

#### Actions on Objectives or Exfiltration Phase
- Attacker has now:
	- Collected victim credentials
	- Performed privilege escalation
	- Internal reconnaissance (find more vulnerabilities internally)
	- Lateral movement through network
	- Collect and exfiltrate sensitive data
	- Delete backups and shadow copies (Microsoft Shadow Copies create backup copies and snapshots)
	- Overwrite and corrupt data

#### Summary
- I learned about the different phases that compose the cyber kill chain. I learned about different reconnaissance methods, where you could get cyber weapons, how you can transmit those weapons and exploit systems with them, how to back door into a system and have persistent access, and how you can escalate your privileges within a system.