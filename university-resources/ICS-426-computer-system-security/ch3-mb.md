# Chapter 3: Organizational Security - Module B: Security Policies

#### Security Documentation
- Framework
    - A program or blueprint documenting the overall processes you need to design policies
    - Good frameworks are vendor-neutral
- Policy
    - Statement describing how the organization is to be run
    - Compliance with policies is mandatory for all employees or users
- Standard
    - Definition of specific methodologies or requirements needed to satisfy policies
    - Mandatory, but tend to be more technical and specific than policies
- Guideline
    - Descriptions of best practices and recommendations
    - Optional and leave room for interpretation
- Benchmark
    - Checklist of potential vulnerabilities in software
    - AKA secure configuration guide
- Procedure
    - Specific and ordered instructions for complying with particular element of a policy or standard
    - Procedures are mandatory and written for people who perform them

#### IT Governance Frameworks
- NIST 800 Series
- NIST Risk Management Framework (RMF)
- NIST Cybersecurity Framework (CSF)
- International Organization for Standardization (ISO) Frameworks
- CIS Critical Security Controls for Effective Cyber Defense (CIS CSC)
- Cloud Security Alliance Cloud Controls Matrix (CSA CCM)
- Statement on Standards for Attestation Engagements (SSAE)

#### Typical Policies
- Acceptable use policy (AUP): Target end users, ensure they follow secure practices and guidelines
- Asset management policy: Govern the tracking of hardware and software assets
- Credential policy: Define how passwords and other credentials will be created, distributed, and controlled
- Incident response policy: Specify steps to take in case of a security incident to minimize and repair damage
- Disaster planning and business continuity policy: Specify steps taken to secure assets, protect staff, and maintain business operations during natural or artificial disasters
- Change management and change control policy: Provide guidelines for updating policies and procedures to suit changing needs without introducing new vulnerabilities
- Standard operating procedures: Step-by-step instructions for performing routine tasks

#### Asset Ownership Policies
- Protection of assets often fails at the human level
- Data owner: Person who's responsible for keeping data safe and complying with applicable regulations
- Data controller: Equivalent with data owner, but for when there isn't a true data owner
- Data custodian: Sysadmin responsible for creating and enforcing technical controls regarding access to data, under the direction of its owner
- Data steward: Person responsible for data management from a business and stakeholder perspective
- Data processor: Third-party entity that accesses and acts upon personal data on behalf of its owner or controller
- Data user: Anyone given access to data by owner or custodian
- Data subject: Person who can be identified via some piece of PII
- Data Protection Officer (DPO): Executive who oversees development, implementation, and enforcement of privacy policies

#### Secure Personnel Policies
- Least Privilege: Ensure that employees are given only the permissions needed to perform their regular duties
- Mandatory Vacations: Employees must take vacations in order to prevent burnout and for other employees to trace any malicious actions such as embezzlement
- Job Rotation: Rotate tasks regularly in order to do a mini peer review of other employees' work, more perspectives means less errors
- Separation of Duties: It's tempting to let a single skilled employee bear long and complicated tasks, but this gives too much freedom to that employee to do fraud
- Clean Desk Space: Clean desk policy means keeping information from where anyone can access it

#### Security Procedures
- Standard Operating Procedure (SOP)
    - Step-by-step instructions used to perform essential, repeatble business tasks
    - Abide by standards or requirements
- Runbook
    - Set of conditional steps that must be performed as part of any security process
    - Best for clearly defined processes
    - Usually used for fully automated courses of action
- Playbook
    - Looser workflow or checklist to organize a security response process
    - Less likely to represent highly automated tasks

#### Business Agreements
- Memorandum of Understanding (MOU)
    - Less formal agreement of mutual goals between two or more organizations
    - Synonymous with letter of intent
    - Used when a formal contract has not bee completed or would not be appropriate
- Memorandum of Agreement (MOA)
    - More specific than MOU
    - Defines specific agreement
    - More likely to be a legally binding document than MOU
- Interconnection Security Agreement (ISA)
    - Specifies technical requirements involved in creating and maintaining a secure connection between two parties
    - Supports an existing MOU
    - Describes connection requirements, security controls, and topological map of connection
- Business Partners Agreement (BPA)
    - Written agreement defining general relationship between business partners
    - Defines how each organization shares profits losses, property, liability
    - Defines partners' responsibilities to each other
- Non-Disclosure Agreement (NDA)
    - Legal agreement that outlines proprietary or confidential information that will be shared between two or more parties that may not be disclosed
    - Often signed during onboarding

#### Supply Chain Agreements
- Service-Level Agreement (SLA)
    - Formal definition of service provided to or by the organization
    - Includes expectations for performance, reliability, and other service metrics
- Master Service Agreement (MSA)
    - Contract between two or more parties laying out a general agreement of their developing relationship
    - Designed ot make future agreements easier to negotiate
- Statement of Work (SOW)
    - Legally binding document describing the details of a project or transaction
    - Includes deliverables, timelines, and costs
    - Defines who is responsible for each part of the project
- Request for Quotation (RFQ)
    - Set of detailed specifications from a client looking to purchase something
    - Intended to generate bids on price and other elements
- Request for Proposal (RFP)
    - Non-binding document similar to an RFQ used for customized projects or solutions
    - Must contain enough detail and context to elicit an accurate bid, but usually gives vendors flexibility to apply their own expertise and creativity to meet requirements