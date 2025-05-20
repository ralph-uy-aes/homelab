# Security Principles

#### CIA Triad
- A measure of a system's security
- **Confidentiality**: only the **intended parties** can access the data
	- Ex. Buying something online means putting your credit card info into the site's db. Confidentiality is satisfied if the db is never readable by unintended parties
- **Integrity**: ensure that **data cannot be altered**, if altered make it detectable
	- Ex. Filling out your delivery address for your order must be immutable by any party
- **Availability**: ensure that the system **serves you** when needed
	- Ex. You want to be able to access the online store
- Beyond the Triad
	- **Authenticity**: **nothing is fraudulent** (fake) and data actually comes from their original source
		- Ex. A customer ordering 1000 pizzas is authentically ordering, not lying
	- **Nonrepudiation**: data distributors cannot claim that they aren't the **source of the data** (no takebacksies)
		- Ex. A customer who has authenticated 1000 pizza orders cannot just say I didn't order that
- Parkerian Head
	1. Availability
	2. Utility
	3. Integrity
	4. Authenticity
	5. Confidentiality
	6. Possession
- **Utility**: usefulness of some data
- **Possession**: no unauthorized taking, copying or controlling

#### DAD Triad
- Triad of attack types on a system's security
	- **Disclosure**: opposite of confidentiality, sharing confidential data
	- **Alteration**: opposite of integrity, an altered piece of data is no good
	- **Destruction/Denial**: opposite of availability, guess what this one means
- Ensuring that **CIA is upheld** is to ensuring that **DAD is protected against**
- Over-protection becomes a thing when **availability is restricted** by unrestricted confidentiality and integrity
- Under-protection becomes a thing when **confidentiality and integrity is restricted** by unrestricted availability

#### Security Models
- Ensures that a system implements one or more security functions
- **Bell-LaPadula Model**
	- Aims to achieve **confidentiality** with 3 rules:
		1. **Simple Security Property**
			- "no read up" 
			- A subject at a lower security level **cannot read** objects **above their level**
			- **Prevents access** to sensitive data **by** **lower security levels**
		2. **Star Security Property**
			- "no write down"
			- A subject at a higher security level **cannot write** objects **below their level**
			- **Prevents disclosure** of sensitive data **by** **higher security levels**
		3. **Discretionary-Security Property**
			- An **access matrix** is used to allow read and write operations
	- Low clearances can share sensitive data to high clearances
	- High clearances can read sensitive data from low clearances
	- Bell-LaPadula sucks for file-sharing
- **Biba Model**
	- Aims to achieve **integrity** with 2 rules:
		1. **Simple Integrity Property**
			- "no read down"
			- A subject at a higher security level **cannot read** objects **below their level**
		2. **Star Integrity Property**
			- "no write up"
			- A subject at a lower security level **cannot write** objects **above their level**
	- Biba struggles with internal threats
- **Clark-Wilson Model**
	- Also aims to achieve integrity with 4 concepts:
		1. **Constrained Data Item**: data type whose integrity we want to preserve
		2. **Unconstrained Data Item**: all data types beyond CDI, such as: users and system input
		3. **Transformation Procedures**: procedures are programmed operations, such as: read and write
		4. **Integrity Verification Procedures**: procedures check and ensure the validity of CDIs
- More security models:
	- Brewer and Nash
	- Goguen-Meseguer
	- Sutherland
	- Graham-Denning
	- Harrison-Ruzzo-Ullman

#### Defense In-Depth
- Security systems that implement the concept of "Defense in-depth" have multiple levels
	- These are called "Multi-Level Security"
- Analogy: Say you wanna keep your 1 Bitcoin secured. You own a house which has a bedroom and in that bedroom there is a closet which has a safe. You can secure it in multiple levels if you lock your Bitcoin inside the safe and then lock the closet and then lock the bedroom and then lock the house. 
- Even though MLS might not stop all thieves, they will surely slow them down

#### ISO/IEC 19249
- International Organization for Standardization (ISO)
- International Electrotechnical Commission (IEC)
- ISO/IEC 19249:2017 Information technology - Security techniques - Catalogue of architectural and design principles for secure products, systems, and applications
- Purpose: have a **better idea** of what international organizations would teach regarding **security principles**
- **5 Architectural Principles**:
	1. Domain Separation
		- Domains > Entities > Components
			- Domains are like the **assigned security attributes** and unique to each Entity
			- Entities are like a **group of similar** or related components 
			- Components are like **applications, data, processes**, etc...
		- Included in the Goguen-Meseguer Model
	2. Layering
		- Abstraction of a security system into multiple different levels
		- Allows for a **unique security policy** to be imposed **per level**
		- Related to **Defense In-Depth**
		- OSI models layers provides specific services to the layers above it
	3. Encapsulation
		- Basically, **do not give users the ability** to **directly access** sensitive variables in a program
			- I.e. if you have a clock object with an `int time` variable, do not let a user input a `String` by not letting them access `time` directly
		- Instead, create a method for the object so that whenever the user wants to change time, the object does it for them only using valid arguments
		- The aim is to **prevent invalid values** for your variables
	4. Redundancy
		- Ensures **availability and integrity** by creating "backups"
		- RAID 5 has redundancy by keeping copies of fractions of each file in each drive. If one fails, you can still rebuild the files in the drive thanks to the fractions in the other drives
			- Integrity is ensured through detecting changes via parity.
	5. Virtualization
		- **Sharing** a single set of hardware (PC) over multiple operating systems (VMs) 
		- You can create sandbox environments that have **no real consequence** in the case of getting attacked
- **5 Design Principles**:
	1. Least Privilege
		- "need-to-know basis" or "who can access what?"
		- Provide anyone **the least amount of privilege** or permissions for them to carry out their task and **nothing more**
		- If a document must be viewed, give read permissions, but not write permissions
	2. Attack Surface Minimization
		- Vulnerabilities come from **more openings** in a system
		- Some vulnerabilities are known and others are not. For those that ARE known, **reduce the attack surface** by removing the cause of said vulnerabilities
		- Turn off network services in Linux that are not in use
	3. Centralized Parameter Validation
		- Many threats are due to the system **receiving input** from users **that are invalid**
		- DDOS, remote code execution, and SQL injections for example
		- **Validate your parameters** before accepting any to begin with, must be centralized in one library or system
	4. Centralized General Security Services
		- **Centralize all security services**
		- There must only be one server for authentication for example
			- This actually kind of works against availability because it creates a single point of failure
	5. Prepare for Error and Exception Handling
		- Software must be designed to **fail safe**
		- When a user tries to input an invalid value to a text field, this could crash the database
		- **Handling errors** for invalid values must be implemented
			- Error messages must be confidential in order to **not leak information** about other users

#### Trust
1. Trust but Verify
	- The principle of verifying **even when an entity is trusted**
	- Requires set up of proper logging mechanisms
		- Crawl through logs and compare to make sure everything is normal
	- Realistically, verifying everything is not feasible, **very resource heavy**
2. Zero Trust
	- The principle of **trust = vulnerability**
	- Caters to insider threats
	- "Never trust, always verify"
	- Everything is an adversary until proven otherwise
	- Microsegmentation
		- Design where a network segment can be as small as a single host
		- Communication between segments requires authentication and passed ACLs

#### Threat Vs Risk
- Vulnerability: **susceptibility to attack**, a vulnerability is a weakness
- Threat: a **potential danger** associated with this weakness or vulnerability
- Risk: **likelihood of a threat actor** exploiting a vulnerability

#### Summary
- I learned about the CIA and DAD triads, how they are implemented via different security models such as Bell-LaPadula, Biba, and Clark-Wilson models. I also learned more about MLS and ISO/EIC 19249 standards. Finally, I learned about trust, zero-trust. and threat vs risk.