# Chapter 1: Security Fundamentals - Module C: Enterprise Security Strategy

#### About Governance
- Formal, policy-driven practice that aligns operational functions such as security with overall business strategy
    - Policies must address stakeholder goals and define clear channels for control and accountability
- Risk management helps you choose security controls while governance is how you make sure they're correctly implemented
- Stakeholders does not mean shareholders
    - Stakeholders are all groups whose support is essential to the organization's existence

#### Organizational Planning
- Strategic plans
    - High-level
    - Defined by senior management for long-term goals
- Tactical plans
    - Short-term goals, more concrete
    - Designed to meet specific strategic objectives and may be delegated to mid-level management
- Operational plans
    - How to perform day-to-day operations in ways that meet higher-level plans
    - Created or administered by low-level management and followed directly by employees
    - More specific

#### Regulatory Compliance
- Ensures that the organization follows the best practices in protecting its informational assets
- A matter of calculating risks and finding the controls and procedures that minimize them

#### Consequences of Non-compliance
- As dangerous as cybersecurity threats
- Failing to protect assets is the same as advertising them to attackers
- Fines can be posed as penalties
- Sanctions can be imposed as legal penalties
- Loss of license can be a result of non-compliance
- Reputational damage, contractual impacts, increased scrutiny are all consequences of non-compliance

#### Cybersecurity Regulatory Structures
- Surbanes-Oxley Act of 2002 (SOX)
    - Federal law designed to protect investors from fraudulent corporate accounting practices
    - Applies to all publicly traded companies and public accounting firms in the US
    - Regulates the preservation, auditing, and disclosure of financial records and related communications
- Federal Information Security Management Act (FISMA)
    - Law applying to all federal agencies
    - Requires agencies to develop, document, and implement an information security and protection program
    - Provides guidelines for minimum standards and cost-effectiveness
- Health Insurance Portability and Accountability Act (HIPAA)
    - Federal law designed to protect the health insurance coverage of workers who change or lose their jobs
    - Protects the privacy of patient records
    - Defines protected health information (PHI) and regulates how it can be used, stored, accessed, disclosed
- Family Educational Rights and Privacy Act (FERPA)
    - Federal privacy law that governs access to educational records held by any school or educational institution
    - Requires that adult students or parents of minor students have access to their records and limit how they can be shared with others
- Gramm-Leach-Bliley Act (GLBA)
    - Designed to protect customers of financial institutions
    - Requires that institutions meet minimum standards to safeguard personal information of their clients and customers
    - Requires them to inform customers about how their data will be stored, used, or shared
- General Data Protection Regulation (GDPR)
    - Newly enacted EU privacy law governing all individual data relating to EU residents
    - Important to American companies that do business with EU residents
- Payment Card Industry Data Security Standard (PCI DSS)
    - Not a law, but a set of shared rules developed by the world's major credit card companies and administered by the PCI council
    - Regulates how payment information must be stored, processed, and transmitted

#### Private Data
- Personally identifiable information (PII) also known as sensitive personal information (SPI) can e used to uniquely identify or locate an individual person or used in conjunction with other information to do so

#### General Data Protection Regulation (GDPR) Compliance
- EU regulation covering all individual data relating to EU residents
- Defines three roles in privacy
    - Data subject is an individual whose private data is collected
    - Data controller is any entity that collects information about a data subject
    - Data processor handles or processes PII on behalf of a data controller, does not include employees of the controller

#### Organizational Roles and Responsibilities
- Manager
    - Responsible for organization's assets and empowered to make decisions about how to protect them
    - Requests approval of security decisions
        - Held accountable for any security failings
    - Delegates technical decisions to other people
        - Ensure that everything is soundly designed and faithfully implemented
- Security Professional
    - Any technically trained employee responsible for implementing security controls as designated by upper management
    - Responsible for performing security tasks, overseeing users, and recognizing policy violations or security incidents 
- User
    - Anyone with access to a sensitive asset, but not directly in the context of securing it
    - Must have enough awareness of security to intelligently comply with policies and refrain from any actions that may compromise security
- Auditor
    - People responsible for monitoring and reviewing the effectiveness of security policies
    - May be outside consultants or independent security professionals within the organization
    - Makes sure that security policies are adequately designed,  implemented, and complied with

#### Management Positions
- Chief Information Officer (CIO): oversees IT operations, requires technical knowledge, more strategic than hands-on in large organizations
- Chief Security Officer (CSO): oversees strategic security needs, focusing on risk management 
- Chief Information Security Officer (CISO): can replace or aid CSO, more focused on information assets
- Chief Compliance Officer (CCO) and Chief Privacy Officer (CPO): specialized roles that ensure compliance with industry regulations and privacy laws

#### Defense in Depth
- Define multiple layers on which the organization needs to be secured
- Define where you need to look when you set up security systems
- Ensures that no single flaw will compromise everything

#### Security by Design
- Secure by design
    - Secure development procedures minimize security bugs and incorporate security controls that resist attack
    - Software that isn't secure by design will have more vulnerabilities
- Secure by default
    - Finished software should have default configuration settings that promote secure operations
- Secure by deployment
    - Software should be easy for users to deploy and maintain in a secure state
    - Logging, patches, installation, maintenance tasks should all be easy to do
- Communications
    - Developers should communicate openly with users and administrators about security issues with the software
    - Otherwise vulnerabilities won't be found and mitigated

#### Security Through Obscurity
- Hide the inner workings of programs to prevent imitators and make attacks more difficult
- Administrators sometimes use non-standard ports for vulnerable network services to make them harder to notice
- Discouraged by most standards organizations because it often leads to neglecting other security controls

#### Open Security
- All technologies and methodologies are known quantities based on openly published technologies that anyone can see
- Security experts can examine the system and look for flaws or ways to improve it further
- Attackers can study them too, but don't gain an advantage over defenders