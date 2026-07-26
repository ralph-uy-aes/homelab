# 📚 ICS 169 – Lab 7: Implementing an IT Security Policy
## Complete Notes

---

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Implementing a Password Protection Policy](#-section-1-part-1-implementing-a-password-protection-policy)
3. [Section 1, Part 2: Implementing an Antivirus Policy](#-section-1-part-2-implementing-an-antivirus-policy)
4. [Section 2: Applied Learning – Applying a Windows Security Baseline](#-section-2-applied-learning--applying-a-windows-security-baseline)
5. [Section 3: Challenge & Analysis](#-section-3-challenge--analysis)
6. [Master Command Reference](#-master-command-reference)
7. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
8. [Lab Deliverables Checklist](#-lab-7-deliverables-checklist)
9. [Key Takeaways](#-key-takeaways--lab-7)

---

## 🎯 Core Concepts & Introduction

### The IT Security Policy Framework

An IT security policy is **not a single document** but rather a **framework or infrastructure** that supports the entire cybersecurity program.

| Layer | Type | Description | Examples |
|-------|------|-------------|----------|
| **Top** | Organizational Policies | Set the overall tone, goals, and culture around security. Broad in scope; endorsed by executive leadership. | Security Vision, Risk Management |
| **Middle** | Functional Policies | Address specific operational areas; guide managers and staff in applying security principles. | Acceptable Use, Antivirus, Email, Firewall, Wireless, Mobile Devices |
| **Bottom** | Supporting Documents | Provide detailed guidance on implementing policies. | Standards, Procedures, Baselines, Guidelines |

### Functional Policies Examples

| Policy | Purpose |
|--------|---------|
| **Acceptable Use** | Outlines appropriate use of organizational resources. |
| **Antivirus** | Defines requirements for malware detection and prevention. |
| **Email** | Establishes guidelines for appropriate use of email systems. |
| **Firewall** | Describes how firewall configurations are managed and maintained. |
| **Wireless** | Regulates the secure use of wireless networks. |
| **Mobile Devices** | Provides requirements for securing mobile devices. |

### Supporting Documents

| Document Type | Description |
|---------------|-------------|
| **Standards** | Mandated requirements used to address security risk. |
| **Procedures** | Step-by-step systematic actions to accomplish security requirements. |
| **Baselines** | Collections of configuration settings that adhere to security policy. |
| **Guidelines** | Recommendations to help security personnel implement solutions. |

### Password Protection Policy Elements

| Element | Description |
|---------|-------------|
| **Policy Requirements** | Complexity rules (length, character variety), expiration timeframes, reuse restrictions. |
| **Procedures** | How users manage passwords (reset mechanisms, recovery workflows). |

### Sample Password Policy

- Passwords must be at least **9 characters** and contain at least **3 of 4**: uppercase, lowercase, numbers, special characters.
- Passwords must expire every **30 days** and be unique from previous **15 passwords**.
- Self-service password reset process available.

---

### Lab Topology Summary (Lab 7)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Domain Member) |
| DomainController01 | 172.16.0.10 | Windows Server 2019 / Active Directory |
| Switch01 | 172.30.0.3 | Debian 11 |
| pfSense-office | 172.30.0.1 / 202.20.1.1 / 10.0.0.1 | FreeBSD / Firewall-Router |
| pfSense-dc | 172.16.0.1 / 203.30.3.1 / 172.31.0.1 / 10.0.0.2 | FreeBSD / Firewall-Router |

---

## 🔐 Section 1, Part 1: Implementing a Password Protection Policy

### Active Directory and Group Policy Overview

| Component | Purpose |
|-----------|---------|
| **Active Directory (AD)** | Centralized framework for managing user accounts, devices, and organizational settings. |
| **Group Policy Object (GPO)** | Defines and enforces security configurations at scale. |
| **GPMC (Group Policy Management Console)** | Primary interface for managing GPOs across a domain. |
| **Default Domain Policy** | Microsoft-provided starting point with common secure settings. |

### Password Policy Settings Configured

| Setting | Value | Purpose |
|---------|-------|---------|
| **Enforce password history** | 15 passwords remembered | Prevents password reuse. |
| **Maximum password age** | 30 days | Forces regular password changes. |
| **Minimum password length** | 9 characters | Ensures passwords are long enough. |
| **Password must meet complexity requirements** | Enabled | Requires mixed character types. |

### GPO Hierarchy

```
Forest: securelabsondemand.com
  └── Domains
        └── securelabsondemand.com
              └── Group Policy Objects
                    └── Default Domain Policy (linked to domain)
                          └── Computer Configuration
                                └── Policies
                                      └── Windows Settings
                                            └── Security Settings
                                                  └── Account Policies
                                                        └── Password Policy
```

### GPO Link Settings

| Setting | Meaning |
|---------|---------|
| **Link Enabled = Yes** | Policy settings are applied to linked entities (domain, OU, etc.). |
| **Enforced = Yes** | Prevents lower-level GPOs from overriding these settings (disables inheritance). |

### Hands-On Actions: Password Policy Configuration

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open Server Manager → Tools → Group Policy Management | Access GPMC. |
| 2 | Navigate to Default Domain Policy. | Locate the policy to edit. |
| 3 | Right-click → Edit. | Open Group Policy Management Editor. |
| 4 | Navigate to Password Policy. | Access password settings. |
| 5 | Set **Enforce password history** = 15. | Remember 15 previous passwords. |
| 6 | Set **Maximum password age** = 30. | Passwords expire every 30 days. |
| 7 | Set **Minimum password length** = 9. | Minimum 9 characters. |
| 8 | Enable **Password must meet complexity requirements**. | Require mixed character types. |
| 9 | ✅ Screen capture – Newly configured Domain Password Policy settings. | — |
| 10 | `gpupdate /force` in PowerShell. | Force policy update. |
| 11 | Open Active Directory Users and Computers. | Access user management. |
| 12 | Reset Alice Dodson's password to `P@ssw0rd` (8 chars). | ❌ Fails – does not meet 9-char requirement. |
| 13 | Reset password to `P@ssw0rd!2`. | ✅ Success – meets requirements. |
| 14 | ✅ Screen capture – Successful password change message. | — |
| 15 | Log in to vWorkstation as `adodson / P@ssw0rd!2`. | Verify policy is enforced. |
| 16 | ✅ Screen capture – Logged on user account. | — |

---

## 🛡️ Section 1, Part 2: Implementing an Antivirus Policy

### Antivirus Policy Components

| Component | Purpose |
|-----------|---------|
| **Policy Statement** | Defines organizational requirements for antivirus protection. |
| **User-Level Controls** | Users are not responsible for configuring antivirus settings. |
| **Administrator Enforcement** | IT uses AD/GPO to enforce settings at scale. |

### Sample Antivirus Policy

- All organizational endpoints must be protected by approved and up-to-date antivirus/antimalware software.
- Antivirus configurations will be centrally managed using Active Directory Group Policy; users may not override these settings.
- While third-party antivirus software is permitted, it must be explicitly approved and used in conjunction with Microsoft Defender.
- All antivirus solutions must be regularly updated with the latest software patches and malware signature databases.

### Group Policy Settings for Windows Defender

| Setting | Path | Change Made |
|---------|------|-------------|
| **Turn off real-time protection** | Computer Configuration > Policies > Administrative Templates > Windows Components > Microsoft Defender Antivirus > Real-time protection | Set to **Disabled** (keeps real-time protection ON) |
| **Configure local setting override to turn on real-time protection** | Same path | Set to **Disabled** (prevents users from turning it off) |

### Key Concepts

- **Real-time protection** monitors incoming data (email, downloads) and blocks malware before it causes damage.
- **Tamper Protection** prevents unauthorized changes to security settings (managed via InTune or Defender for Endpoint, not GPO).
- **Get-MpPreference** PowerShell cmdlet verifies enforcement of antivirus settings.

### Hands-On Actions: Antivirus Policy Configuration

| Step | Action | Purpose |
|------|--------|---------|
| 1 | On vWorkstation, open Settings → Virus & threat protection. | View current settings. |
| 2 | Attempt to turn off Real-time protection, Cloud-delivered protection, Tamper Protection. | ❌ Reverts immediately – policy-enforced. |
| 3 | Sign out of vWorkstation. | — |
| 4 | On DomainController01, open GPMC → Default Domain Policy → Edit. | Access Group Policy Editor. |
| 5 | Navigate to Real-time protection settings. | Locate Defender settings. |
| 6 | Set **Turn off real-time protection** = Disabled. | Keep real-time protection ON. |
| 7 | Set **Configure local setting override to turn on real-time protection** = Disabled. | Prevent users from overriding. |
| 8 | ✅ Screen capture – Newly configured Domain Real-time protection Policy settings. | — |
| 9 | `gpupdate /force` on DomainController01. | Force policy update. |
| 10 | Log in to vWorkstation as `adodson / P@ssw0rd!2`. | — |
| 11 | `gpupdate /force` on vWorkstation. | Force policy update. |
| 12 | `Get-MpPreference` in PowerShell. | Verify `DisableRealtimeMonitoring : False`. |
| 13 | ✅ Screen capture – PowerShell output verifying real-time protection. | — |

---

## 📋 Section 2: Applied Learning – Applying a Windows Security Baseline

### What is a Security Baseline?

A **security baseline** is a curated collection of GPOs that apply recommended configuration settings for hardening an operating system against common threats.

| Component | Description |
|-----------|-------------|
| **Microsoft Security Compliance Toolkit (SCT)** | Includes preconfigured Windows security baselines reflecting industry best practices. |
| **Domain Security Baseline** | Contains recommended settings for domain controllers and domain-joined systems. |
| **Import Settings Wizard** | Used to import baseline GPOs into an existing GPO. |

### Account Lockout Policy

Prevents attackers from using automated techniques to compromise passwords.

| Setting | Description |
|---------|-------------|
| **Account lockout threshold** | Number of failed sign-in attempts before lockout. |
| **Account lockout duration** | How long the account remains locked. |
| **Reset account lockout counter after** | Time before the failed attempt count resets to 0. |

### Hands-On Actions: Applying a Security Baseline

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open File Explorer → `C:\SCT\...\GP Reports`. | Locate baseline reports. |
| 2 | Open `MSFT Windows 10 1809 and Server 2019 - Domain Security.htm`. | View recommended settings. |
| 3 | Locate Password and Account Lockout Policy settings. | See Microsoft's recommendations. |
| 4 | ✅ Screen capture – Microsoft's recommended Password and Account Lockout policy settings. | — |
| 5 | In GPMC, right-click **Group Policy Objects** → New. | Create a new GPO. |
| 6 | Name: **MSDomainSecurity2026**. | — |
| 7 | Right-click new GPO → **Import Settings**. | Open Import Settings Wizard. |
| 8 | Browse to `C:\SCT\...\GPOs`. | Locate baseline GPO backup. |
| 9 | Select **MSFT Windows 10 1809 and Server 2019 - Domain Security**. | Import the baseline. |
| 10 | Complete the wizard. | Import settings. |
| 11 | Right-click domain → **Link an Existing GPO** → Select **MSDomainSecurity2026**. | Link GPO to the domain. |
| 12 | ✅ Screen capture – Linked MSDomainSecurity2026 object. | — |
| 13 | Right-click GPO → **Save Report** → Save to desktop. | Export GPO settings. |
| 14 | Open the report, locate Password and Account Lockout policy settings. | Review imported settings. |
| 15 | ✅ Screen capture – Password and Account Lockout policy settings. | — |

---

## 📝 Section 3: Challenge & Analysis

### Part 1: Researching Acceptable Use Policies (AUP)

**Definition:** An Acceptable Use Policy defines the appropriate and inappropriate use of organizational resources such as computers, networks, and data systems.

**Purpose:** Protects against insider threats, supports compliance with legal frameworks (HIPAA, PCI DSS, GDPR), and reduces organizational liability.

#### Five Common AUP Policy Statements

**1. Authorized Use**
- Users must authenticate using assigned credentials only.
- Defines what users are authorized to access based on their roles.
- Works in conjunction with access control to specify user permissions.
- **Source:** Mohave County Technology Acceptable Use Policy

**2. Prohibited Activities**
- Users are not allowed to engage in illegal activities such as piracy, extortion, unauthorized access, or accessing obscene material.
- Prevents organizational liability for trafficking illegal material.
- **Source:** Mohave County Technology Acceptable Use Policy

**3. Expectation of Privacy**
- States that users should have no expectation of privacy when using organizational resources.
- Limits liability for the organization.
- **Source:** NASA Policy Directive NPD 2540.1H

**4. Data Protection**
- Users must protect organizational data against unauthorized disclosure and/or use.
- Puts partial or shared liability on users who act in ways that could harm confidentiality, integrity, or availability.
- **Source:** CDC STD-IPS Glossary

**5. Right to Monitor**
- States that the organization may monitor or inspect the use of its IT resources.
- Ties into the expectation of privacy policy.
- Gives more administrative control to the organization.
- **Source:** Bryant University Acceptable Use Policy

---

### Part 2: Researching Privacy Policies

**Definition:** A Privacy Policy informs users how their personal information is collected, stored, and protected.

**Purpose:** Ensures legal compliance (GDPR, CCPA, HIPAA, FERPA), builds trust with users, and reflects ethical considerations in data handling.

#### Five Common Privacy Policy Statements

**1. Data Collection**
- Provides transparency to users about what data is collected and how it's used.
- Common in cookie settings.
- Necessary for GDPR compliance (right to be informed).
- **Source:** FTC Fair Information Practice Principles (FIPP)

**2. Data Consent**
- Gives users choice about what data is used and how.
- Seen in cookie settings (marketing cookies) and user analytics options.
- Required for GDPR and CCPA compliance.
- Prevents coercive or deceptive data practices.
- **Source:** FTC FIPP

**3. Right to Access, Correct, Delete**
- States that users have the right to access, correct, update, or request deletion of personal information.
- Gives users control over their personal information.
- Required for GDPR and CCPA compliance.
- **Source:** FTC FIPP

**4. Data Protection**
- Data collectors must maintain the integrity and security of collected data.
- Gives liability to data holders, aligning their interests with data owners.
- Required by HIPAA for protecting health/medical information.
- **Source:** FTC FIPP

**5. Right to Complain**
- Users should be able to complain about privacy violations.
- Provides recourse or compensation for affected users.
- Required by GDPR and HIPAA.
- Enforces accountability upon data collectors.
- **Source:** FTC FIPP

---

## 🛠️ Master Command Reference

### Group Policy Management

| Command / Action | Purpose |
|------------------|---------|
| `Server Manager → Tools → Group Policy Management` | Open GPMC. |
| Right-click GPO → Edit | Open Group Policy Management Editor. |
| Right-click domain → Link an Existing GPO | Link a GPO to a domain/OU. |
| Right-click GPO → Import Settings | Import settings from a baseline. |
| Right-click GPO → Save Report | Export GPO settings as HTML. |
| `gpupdate /force` | Force immediate Group Policy update. |

### PowerShell Commands

| Command | Purpose |
|---------|---------|
| `gpupdate /force` | Force Group Policy update. |
| `Get-MpPreference` | View Microsoft Defender Antivirus preferences. |
| `Get-MpPreference \| Select DisableRealtimeMonitoring` | Check if real-time protection is enforced. |

### Active Directory Users and Computers

| Action | Purpose |
|--------|---------|
| `Tools → Active Directory Users and Computers` | Open ADUC. |
| Right-click user → Reset Password | Change a user's password. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **IT Security Policy** | A framework of documents that communicates security expectations and objectives. |
| **Organizational Policy** | High-level policy that sets the overall tone, goals, and culture around security. |
| **Functional Policy** | Addresses specific operational areas (e.g., Antivirus, Password, Email). |
| **Standard** | Mandated requirements used to address security risk. |
| **Procedure** | Step-by-step systematic actions to accomplish security requirements. |
| **Baseline** | Collections of configuration settings that adhere to security policy. |
| **Guideline** | Recommendations to help implement security solutions. |
| **Active Directory (AD)** | Centralized framework for managing user accounts, devices, and settings. |
| **Group Policy Object (GPO)** | Defines and enforces security configurations. |
| **GPMC (Group Policy Management Console)** | Tool for managing GPOs. |
| **Default Domain Policy** | Microsoft-provided GPO with common secure settings. |
| **Security Baseline** | Preconfigured collection of GPOs for hardening an OS. |
| **Security Compliance Toolkit (SCT)** | Microsoft tool with preconfigured security baselines. |
| **Account Lockout Policy** | Prevents automated password attacks by locking accounts after failed attempts. |
| **Tamper Protection** | Prevents unauthorized changes to security settings. |
| **Acceptable Use Policy (AUP)** | Defines appropriate and inappropriate use of organizational resources. |
| **Privacy Policy** | Informs users how personal information is collected, stored, and protected. |

---

## 📋 Lab 7 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Newly configured Domain Password Policy settings | [ ] |
| 2 | Successful password change message | [ ] |
| 3 | Logged on user account | [ ] |
| 4 | Newly configured Domain Real-time protection Policy settings | [ ] |
| 5 | PowerShell output verifying `DisableRealtimeMonitoring : False` | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 6 | Microsoft's recommended Password and Account Lockout policy settings | [ ] |
| 7 | Linked MSDomainSecurity2026 object | [ ] |
| 8 | Password and Account Lockout policy settings (from imported baseline) | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 9 | Five common Acceptable Use Policy statements with explanations and sources | [ ] |
| 10 | Five common Privacy Policy statements with explanations and sources | [ ] |

---

## 💡 Key Takeaways – Lab 7

### IT Security Policy Framework
1. **Security policy is a framework**, not a single document. It includes organizational policies, functional policies, and supporting documents.
2. **Leadership defines the security vision** and allocates resources; analysts implement technical solutions.
3. **Functional policies** address specific areas: Acceptable Use, Antivirus, Email, Firewall, Wireless, Mobile Devices.

### Password Protection Policy
4. **Password policies** combine requirements (complexity, length, expiration) and procedures (reset workflows).
5. **Active Directory + GPOs** enable centralized, scalable enforcement of password policies.
6. **Enforce password history** prevents password reuse; **Maximum password age** forces regular changes.
7. **Complexity requirements** ensure passwords contain mixed character types.
8. **Account lockout policies** prevent automated brute-force attacks.

### Antivirus Policy
9. **Antivirus policies** define requirements for malware protection and central management.
10. **GPOs can enforce** real-time protection settings and prevent users from disabling them.
11. **Tamper Protection** (managing via GPO) requires additional tools like InTune or Defender for Endpoint.
12. `Get-MpPreference` is the reliable way to verify antivirus enforcement (UI may not show grayed-out settings).

### Security Baselines
13. **Microsoft Security Baselines** provide preconfigured GPOs reflecting industry best practices.
14. **Import Settings Wizard** allows easy import of baseline GPOs into existing policies.
15. **Baselines save time** by eliminating the need to manually configure 100+ individual settings.

### Acceptable Use Policies (AUP)
16. **AUPs define appropriate use** of organizational resources and protect against insider threats.
17. Common statements: Authorized Use, Prohibited Activities, Expectation of Privacy, Data Protection, Right to Monitor.
18. **AUPs support compliance** with HIPAA, PCI DSS, GDPR, and other regulations.

### Privacy Policies
19. **Privacy policies inform users** how personal information is collected, stored, and protected.
20. Common statements: Data Collection, Data Consent, Right to Access/Correct/Delete, Data Protection, Right to Complain.
21. **Regulatory frameworks** (GDPR, CCPA, HIPAA, FERPA) shape privacy policy requirements.
22. **Ethical considerations** – respecting user autonomy, transparency, and trust – should guide privacy policies.