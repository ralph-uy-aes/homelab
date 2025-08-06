# Chapter 8: Access Control - Module B: Account Management

#### Identity Life Cycle
- User accounts connect low-level AAA functions and high-level identity management decisions
- Whatever technical solutions you're using, an account is only an effective security control if managed securely
1. When an account is approved for creation, it's assigned an identity and given authentication credentials
    - Vulnerabilities include accounts created without administrative oversight, accounts assigned to mistaken or non-trusted identities, and accounts with weak passwords/ credentials
    - Attackers with temporary access or social engineers will exploit this phase to create their own accounts
2. Before use, the account must be provisioned or assigned roles and privileges according to whatever access control model you use
    - It's easy to introduce vulnerabilities by assigning too many permissions to an account that may be abused or compromised later
    - Essential to use least privilege principles
    - Attackers will exploit provisioning system vulnerabilities for privilege escalation purposes
3. Active accounts must be maintained actively
    - Administrators should periodically review account privileges, especially after the owner's role or duties have changed
    - Since attackers will target active accounts, ongoing monitoring should watch for signs of misuse or suspicious activity
4. When accounts or their roles are no longer needed, they should be disabled, deleted, or deprovisioned
    - Otherwise they remain to be a vulnerability

#### Account Types
- User
    - Ordinary accounts
    - Can access data and perform tasks suitable to user's role
    - Don't have administrative functions or other sensitive data
- Privileged
    - Access to resources ordinary users od not
    - Includes administrator accounts
    - Help desk workers might be able to reset passwords for user accounts, but not change more critical security settings
- Shared/ Generic
    - Accounts used by multiple people
    - Lack of accountability makes shared accounts a poor security practice, but sometimes unavoidable
    - Should still be maintained and monitored
- Guest
    - Limited accounts for guests or visitors
    - More restricted than user accounts
    - Temporary employees should be given temporary accounts instead
- Service
    - Associated with an application or service that needs to interact with the system

#### Identity Proofing
- Verifying identification before issuing credentials
- Background checking for example
- Can be performed in-house or via a third-party
- Knowledge-based Authentication (KBA) systems request additional information
    - Static KBA uses pre-arranged questions, like security questions, usually easier to bypass
    - Dynamic KBA uses questions generated on the fly from something the real person should know, usually Out-of-Wallet (OOW) KBA which asks questions requiring information from a user's wallet
    - Out-of-band proofing is an OOW method using a second communications channel to provide defense in depth, such as requiring phone verification in addition to online verification

#### Identity System Components
- Often designed to span multiple services, systems, and even organizations
- Makes interoperability an important concern
- Many common standards are used for different components

#### Credential Management Systems
- Centralized credential management is often a PKI-based solution that generates and distributes certificates for users, machines, and other entities that need them
- Allow users to have strong, unique passwords for many accounts but only need to remember a single password to access the credential management
- Secure if the central password is strong and secret, but they also provide a single point of failure

#### Privileged Access Management (PAM)
- One option is to deploy PAM controls that constrain privileged accounts and their actions
- Extends beyond simple account management, making it harder for a malicious insider, careless administrator, or hacker to misuse privileged accounts without being caught
- Often difficult to implement in a way that maximizes security and minimizes disruption of legitimate privileged actions, but the security benefits can be worth it
- The developing trend is Just-in-Time (JIT) PAM, a real time model that evaluates and grants elevated permissions only for the bounds of a single task, then revokes them once it's complete
    - Relies on ephemeral credentials that have a short expiration period or are automatically revoked after use

#### Active Directory User Management
- You can create or manage user accounts in the Active Directory Users and Computers window on an AD domain controller
- Domain users and computers are both principals and leaf objects. Every domain has at least an Administrator and a Guest user
- Contacts, printers, and pointers to shared folders are leaf objects but not principals
- Security groups are principals used to centrally manage rights and permissions
- Distribution groups are non-principals primarily used to create email lists in Exchange
- Organizational Units (OUs) are non-principal container objects that can be arranged to mirror the organization's structure

#### Group Scopes
- Assigning permissions to groups is much more efficient and secure than assigning the same permissions to every user
- Scopes are most important on large networks with many domains, especially when they're spread over a wide geographic area
- Use domain local groups when you assign permissions to resources on the local domain
- Use global groups to organize users sharing similar permissions needs; don't assign permissions directly to the global group, add the global group to a domain local group with the necessary permissions
- Use universal groups for nesting global groups from different domains

#### Group Policy Objects (GPOs)
- Lets you centrally control how users can access Windows features and resources
- Allow you to change thousands of settings affecting all sorts of Windows functions, two categories:
    - Computer Configuration settings
        - Scripts (Startup/Shutdown) - Scripts that run when the computer first starts or when it shuts down
        - Software settings - Settings to automatically deploy software to the computer
        - Account policies - Policies related to user passwords, account lockout, and Kerberos settings
        - Local policies - Policies related to operating system hardening such as system logging, network security settings, access to removable media, etc...
        - Restricted groups - Policies preventing modification of individual security groups
        - Windows firewall - Windows firewall rules
        - Software restriction policies - Policies governing what software can run on the computer
    - User Configuration settings
        - Scripts (Logon/Logoff) - Scripts that run when a user logs on or logs off
        - Folder redirection - Settings to redirect user folders to network locations
        - Software settings - Settings to automatically distribute software to client computers when an affected user logs on
        - Administrative templates - Settings to control what features appear in the Start menu, taskbar, Control Panel, desktop

#### Managing GPOs
- Tools > Group Policy Management
- Doesn't just allow you to edit exiting GPOs, but also to create new ones
- Each subsequent GPO overrides the one before
1. Local GPO
2. Site GPO
3. Domain GPO
4. Organizational Unit GPO
5. Child OU GPO

#### Managing User Accounts
1. Define a user policy with restrictions and best practices
2. Enforce those policies with technological controls
3. Continuously review both security logs and user access settings to verify that enforcements are secure, and users are in compliance

#### Provisioning Accounts
- Choose user names carefully according to a standard naming convention. Keep the needs of various elements of security and usability in mind when assigning them:
    - To protect against attackers, user names should not be easy to guess just because you know  the account owner’s name or job role.
    - For usability, it should be easy for users to remember their own names, and for help desk employees to find the account of a particular user
    - For auditing purposes, user names should never be changed and should be easily filtered for reports
- Where possible, assign permissions to groups rather than individual accounts. It’s easier to add or remove group members than it is to make permissions changes to multiple accounts
- Where possible, avoid the use of generic accounts, such as guest accounts or any others shared by multiple users. As convenient as they are, they’re harder to monitor, individually log, and otherwise keep secure
- Assign administrators two accounts apiece: an administrator account for tasks that require elevated privileges and a standard user account for all other work
- When giving multiple accounts to a single user, ensure that each account has a separate password. Otherwise, someone gaining access to one gains access to all

#### Secure Account Access
- Allow users to choose their own passwords, and don’t ask them to tell you. When you must reset a password, choose a secure temporary value and require it to be changed on the next login.
- In addition to configuring a minimum length, you can enforce complexity requirements such as requiring a mix of uppercase, lowercase, numbers, and special characters. Setting a maximum password length is not recommended unless it can’t be supported for technical reasons.
- If possible, configure identity systems to test all passwords against a dictionary of weak or compromised passwords and deny weak options.
- NIST recommends passwords should be changed when there is reason to believe the account has been compromised, but not on a scheduled basis. However, many systems still allow a maximum password age.
- To prevent password reuse, configure a password history that tracks previous passwords. A minimum password age prevents users from cycling quickly through the entire history.
- Users are most likely to use long, strong passwords when they don’t have to remember them individually for each account. To encourage that, use credential management software.
- Configure a lockout policy that will block access to the account after successive failed logins. The most secure lockouts require administrative override to unlock, but you can also use a time-based delay.
- Use additional security policies supported by your access control systems, such as geolocation, time-based access, or conditional access.

#### Reviewing Access Privileges
- Apply permissions on a least privilege basis. Each account should be assigned to a user with a valid reason to access the system and given limited privileges based on expected work duties.
- Privileged accounts should receive extra scrutiny due to their increased risk profile.
    - Users who are also administrators should use separate accounts for administrative and regular tasks.
    - Consider stricter authentication for privileged accounts, such as MFA or PAM.
- Periodically review account permissions and contrast them with the associated subject’s regular duties.▪Review permissions whenever a user changes job duties.
    - Review permissions after significant system or procedural changes.
    - Ensure that users receive appropriate security training and policy notifications after any change to permissions or system functions.
- Review account activity to look for signs of intrusion or other suspicious behavior, with additional scrutiny for privileged users like administrators. Real-time alerts and periodic log reviews are both valuable.
    - Monitor authentication or authorization failures.
    - Examine successful authentication or authorization under unusual conditions, such as someone logging in from an unusual time or location or interactive login to a service account.
    - Deploy IDS, IPS, or DLP systems to provide additional protection.
- Disable accounts when they are no longer needed.
    - In addition to disabling accounts manually, you can set an automatic expiration date for temporary accounts.
    - Deleting accounts can be a problem if you want them back later and might violate regulatory requirements for data retention. Where possible, mark them as inactive. In Active Directory, you could create an “Inactive” OU, so it’s easy to tell they shouldn’t be enabled.
- If the auditing and automation tools built into Active Directory or any other account management system aren’t sophisticated enough to meet your needs, look into third-party scripts or tools.