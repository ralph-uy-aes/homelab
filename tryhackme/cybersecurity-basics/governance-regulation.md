# Governance & Regulation

#### Terminologies
- **Governance**: Manage and **direct organization** or system to achieve its objectives and enforce laws
- **Regulation**: Rule or law **enforced by government** to ensure compliance
- **Compliance**: **Adherence to laws** that apply to an organization

#### Information Security Governance
- How information **assets are governed**
- What structures, **policies**, methods, guidelines are used to guarantee privacy, reliability, and accessibility
- Work to **counter cyber threats**
- Often includes the following processes:
	1. **Strategy**: **Develop and implement** comprehensive I.S. **strategy** to align with organization's objectives
	2. **Policies and Procedures**: **Prepare** **policies** to govern and protect information assets
	3. **Risk Management**: **Conduct** **risk assessments** to identify potential threats and implement risk mitigation measures
	4. **Performance Measurement**: **Establish** **metrics** and KPI (key performance indicators) to measure effectiveness of I.S. governance
	5. **Compliance**: **Ensure compliance** with regulations and industry practices

#### Information Security Regulation
- Legal and regulatory **frameworks** governing use and protection of information assets
- Work to **protect sensitive data** from unauthorized access
- **Compliance is mandatory** and enforced by regulatory bodies
- Ex. General Data Protection Regulation (GDPR), Payment Card Industry Data Security Standard (PCI DSS), Personal Information Protection and Electronic Documents Act (PIPEDA), etc...

#### Benefits of Governance
- **Better Security Posture**: Reduce the risk of security breaches and protect against unauthorized access
- **Stakeholder Confidence**: Enhance the trust of stakeholders by demonstrating robust cyber security policies
- **Regulatory Compliance**: Avoid legal and financial penalties from non-compliance
- **Business Objectives Aligned**: Help align business objectives and ensure cost-effectiveness of policies
- **Informed Decision-Making**: Provide decision makers with better knowledge about security risks and policies
- **Competitive Advantage**: Provides competitive advantage by demonstrating commitment of company in data security

#### Relevant Laws and Regulations
- **General Data Protection Regulation (GDPR)**
	- Data Privacy and Protection
	- Propagated by the EU to set requirements for how organizations handle and protect personal data of EU citizens
- **Healthcare Insurance Portability and Accountability Act (HIPAA)**
	- Healthcare
	- US-based law to maintain sensitivity of health-related information of citizens
- **Payment Card Industry Data Security Standard (PCI-DSS)**
	- Financial
	- Ensure secure handling, storage, processing, and transmission of cardholder data by merchants
- **Gramm-Leach-Bliley Act (GLBA)**
	- Financial
	- Financial companies must be sensitive to customer's non public personal information

#### Information Security Frameworks
- Comprehensive set of documents outlining organization's approach to I.S.
- **Policies**: Statement outlining organization's goals, principles, and guidelines
- **Standards**: Document establishing specific requirements for processes, products, and services
- **Guidelines**: Document providing recommendations for best practices (non-mandatory)
- **Procedures**: Set of specific steps to finish a process
- **Baselines**: Set of security standards that an organization must meet at minimum

#### Developing Governance Documents
- How do you actually develop policies?
1. **Identify Scope and Purpose**: What will the document cover and what is it for?
2. **Research and Review**: Ensure up-to-date research
3. **Draft the Document**: Create a draft that adheres to practices in writing clear and concise policies
4. **Review and Approval**: Stakeholders review the document and feedback is incorporated
5. **Implementation and Communication**: Communicate or disclose the document to all relevant parties
6. **Review and Update**: Keep the document up to date and monitor compliance

#### Example: Password Policy Preparation
- **Define Password Requirements**: Minimum length, special characters, expiration
- **Define Password Usage Guidelines**: How passwords should be used such as there should be a unique password for each account, no default passwords, no username in password, etc...
- **Define Password Storage and Transmission Guidelines**: Using encryption for and secure protocols for transmission
- **Define Password Change and Reset Guidelines**: How often passwords should be changed
- **Communicate the Policy**
- **Monitor Compliance**

#### Example: Incident Response Procedure
- **Define Incident Types**: Unauthorized access, malware infections, or data breaches
- **Define Incident Response Roles and Responsibilities**: Identify stakeholders and their roles
- **Detailed Steps**: Develop procedures for responding to each incident type
- **Report**: Document for future reference
- **Communicate the Policy**
- **Review and Update**

#### Governance Risk and Compliance Framework
- 3 Components:
	- **Governance Component**
		- Guide an organization towards its direction set by I.S. strategies
		- Monitor methods to measure performance and outcomes
	- **Risk Management Component**
		- Identify and assess risks to the organization
		- Implement mitigation strategies to manage risks
		- Monitor and report risks and continuously refine risk management strategies
	- **Compliance Component**
		- Ensure that an organization meets its legal, regulator, and industry obligations
		- Activities align with policies and procedures
		- Develop and implement compliance programs with audits and reporting issues to stakeholders

#### Guidelines in Developing GRC Program
1. **Define Scope and Objective**
2. **Conduct a Risk Assessment**
3. **Develop Policies and Procedures**
4. **Establish Governance Processes**
5. **Implement Controls**
6. **Monitor and Measure Performance**
7. **Continuously Improve**

#### Example: GRC Framework in the Financial Sector
- **Governance-Related Activities**: Nominate governance level executives and make financial-related policies such as bank secrecy act, anti-money laundering policy, audit policies, crisis management, etc...
- **Risk Management Activities**: Identify risks, outcomes, and countermeasures such as fraud, phishing, fake ATM cards and terminals, etc...
- **Compliance Activities**: Take measures to meet legal requirements and industry standards like PCI-DSS. Implement correct methods like SSL/TLS to avoid MitM attacks, patch management for unpatched software, awareness campaigns against phishing attacks, etc...

#### Privacy and Data Protection
- How do we deal with customers' Personally Identifiable Information (PII)?
- Using privacy regulations, customers can rest easy knowing their information is secured
- General Data Protection Regulation
	- GDPR is an EU data protection law that aims to protect personal data
	- ''Any data associated with an individual that can be utilized to identify them directly or indirectly"
	- Key points:
		- **Prior Approval** before collection of personal data
		- Personal data must be **minimized** to avoid unnecessary data risks and to reduce attack surface
		- **Adequate measures** are to be adopted to protect personal data
- Payment Card Industry Data Security Standard (PCI-DSS)
	- Maintains secure card transactions and protects against data theft and fraud
	- Established by major credit card brands
	- Requires strict control access to cardholder information
	- CHD means cardholder data

#### GDPR Non-Compliance Penalty
- This law only applies to businesses that conduct business in the EU and collect/store/process data of EU residents
1. Tier 1
	- Severe violations that involve unintended data collection, sharing or selling to third parties without consent
	- Maximum penalty could reach whichever is higher of:
		- 4% of organization's revenue
		- $20,000,000 Euros
2. Tier 2
	- Less severe violations such as data breach and cyber policies
	- Maximum penalty cold reach whichever is higher of:
		- 2% of organization's revenue
		- $10,000,000 Euros

#### NIST Special Publications
- **NIST 800-53**
	- "Security and Privacy Controls for Information Systems and Organizations" 
	- Developed by the National Institute of Standards and Technology
	- Provides a catalog of security controls that adhere to the CIA triad
	- Can be used as a framework to assess and enhance security of information systems and comply with laws
- **NIST 800-53 Revision 5**
	- Organizes security controls into 20 families, each addressing a specific security concern category
	- One of the most crucial control families of **NIST 800-53** is **Program Management**
		- Establishes, Implements, and Monitors organization-wide programs for security and privacy
- **Control Categories** (Category > Control > Sub-Control)
	- **Administrative Control**: Audit and Accountability, Awareness and Training, Configuration Management, Contingency Planning, Incident Response, Maintenance, Program Management, Risk Assessment, Security and Authorization
	- **Technical Controls**: Access Control, Identification and Authentication, System and Communications Protection, System and Information Integrity, System and Services Acquisition, System and Services Development, Program System and Services Development
	- **Physical Controls**: Personnel Security, Physical and Environmental Protection, Media Protection
	- **Strategic Controls**: Planning
- **NIST 800-63B**
	- A set of guidelines also created by NIST to help establish effective digital identity practices
	- Focuses on authentication and verification of identities
	- Identity assurance ranges are provided as well as authentication factors

#### Compliance Best Practices
- First, conduct a **discovery process** to recognize and catalog data assets, systems, threats by understanding data flow, dependencies, and vulnerabilities
- Then, map the **NIST 800-53** control families onto the identified assets and hazards
- Third, create a **governance structure** to allocate duties and outline precise controls implementation and maintenance procedures
	- Regularly monitor all measures to ensure compliance
- Finally, establish effective monitoring systems to identify and address security issues, conduct routine evaluations and improve implementation

#### Information Security Standards
- **ISO/IEC 27001**
	- Requirements to plan, develop, run, and update an organization's **Information Security Management System (ISMS)**
	- Documents are paid for and can be purchased by anyone
	- Consists of:
		- **Scope**: Specifies the ISMS's boundaries
		- **Information Security Policy**: Defines an organization's IS approach
		- **Risk Assessment**: Identifies and evaluates the risks to confidentiality, integrity, and availability of organization's information
		- **Risk Treatment**: Select and implement controls to reduce identified risks
		- **Statement of Applicability (SoA)**: Specifies which controls from the standard are applicable and which are not
		- **Internal Audit**: Conducts periodic audits of ISMS to ensure that it is operating effectively
		- **Management Review**: Review the performance of ISMS regularly
- **Service Organization Control 2 (SOC 2)**
	- Developed by American Institute of Certified Public Accountants (AICPA)
	- Compliance/Auditing Framework
	- Assesses the efficacy of a company's data security based on the CIA triad
	- Ensures that a company has put sufficient controls to safeguard systems and data
	- Primarily ensures that third party service providers store and process sensitive information securely
	- **SOC 2 Audit Process**:
		- **Scope**: determine what systems are relevant to the security and privacy of customer data
		- **Choose an Auditor**: select someone who's qualified for audits by checking their reputation, experience, and availability
		- **Plan the Audit**: work with auditor to build the timeline, scope, and criteria of the audit
		- **Prepare for the Audit**: prepare by reviewing security controls, policies, and procedures
		- **Conduct the Audit**: auditor reviews your controls and tests them to assess their effectiveness, includes interviews, control tests, and documentation reviews
		- **Receive Audit Report**: auditor provides a report with audit results, identifies areas for improvement and deficiencies in controls
	- What will be checked in an audit:
		- **Security**: Protect systems from attack, data loss, and other events
		- **Availability**: Ensure systems maintain high availability
		- **Processing Integrity**: Ensure system processing occurs in a timely manner
		- **Confidentiality**: Ensure confidential information is protected from unauthorized access
		- **Privacy**: Ensure that personal information is protected from unauthorized access
