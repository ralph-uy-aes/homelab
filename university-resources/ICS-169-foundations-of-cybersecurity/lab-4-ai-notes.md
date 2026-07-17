# 📚 ICS 169 – Lab 4: Applying User Authentication and Access Controls

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Create Users and Security Groups](#-section-1-part-1-create-users-and-security-groups)
3. [Section 1, Part 2: Create Folders and Configure Security Permissions](#-section-1-part-2-create-folders-and-configure-security-permissions)
4. [Section 1, Part 3: Verify Authentication and Access Controls](#-section-1-part-3-verify-authentication-and-access-controls)
5. [Section 2: Applied Learning – TrueNAS SMB Shares](#-section-2-applied-learning--truenas-smb-shares)
6. [Section 3: Challenge & Analysis – GG Studios Integration](#-section-3-challenge--analysis--gg-studios-integration)
7. [Master Command Reference](#-master-command-reference)
8. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
9. [Lab Deliverables Checklist](#-lab-4-deliverables-checklist)
10. [Key Takeaways](#-key-takeaways--lab-4)

---

## 🎯 Core Concepts & Introduction

### Authentication vs. Authorization

| Concept | Definition | Example |
|---------|------------|---------|
| **Authentication** | Verifying the identity of a user or system. | Entering a username and password. |
| **Authorization** | Determining if an authenticated identity has permission to access a resource. | Checking if a user has "Read" permission for a file. |

> **Key Insight:** Authentication comes first, then authorization. You must know *who* the user is before you can decide *what* they can do.

### Access Control Concepts

| Term | Definition |
|------|------------|
| **Access Control** | The process of evaluating access requests to grant or deny access. |
| **Access Control List (ACL)** | A stored permissions list for a resource specifying identities and allowed/denied actions. |
| **Principle of Least Privilege** | Each identity should have only the minimum access required to perform its role. |

### Active Directory Domain Services (AD DS)

- **Active Directory (AD):** Microsoft's centralized database of user credentials, computers, and configuration settings.
- **Domain:** A group of users and computers managed together.
- **Domain Controller (DC):** The server hosting Active Directory; the central authority for authentication and authorization.
- **Organizational Unit (OU):** A container used to organize objects within a domain (e.g., by department or geography).

### Security Groups in Active Directory

| Property | Options | Purpose |
|----------|---------|---------|
| **Group Scope** | Universal, Global, Domain Local | Defines how and where the group can assign permissions. |
| **Group Type** | Security, Distribution | Security = permission assignment; Distribution = email lists. |

> **Best Practice:** Assign permissions to **groups**, not individual users. This simplifies management and ensures consistency.

### Password Best Practices

- Never use easily guessed passwords.
- Use a non-sequential mix of letters, numbers, uppercase, lowercase, and special characters.
- Change passwords frequently.
- Never include the username in the password.
- Where possible, use multifactor authentication (MFA).

---

### Lab Topology Summary (Lab 4)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Workstation) |
| DomainController01 | 172.16.0.10 | Windows Server 2019 / Active Directory |
| FileServer01 | 172.30.0.5 | FreeBSD / TrueNAS (NAS Server) |
| pfSense-office | 172.30.0.1 / 202.20.1.1 / 10.0.0.1 | FreeBSD / Firewall-Router |
| pfSense-dc | 172.16.0.1 / 203.30.3.1 / 172.31.0.1 / 10.0.0.2 | FreeBSD / Firewall-Router |

---

## 👥 Section 1, Part 1: Create Users and Security Groups

### Active Directory Users and Computers (ADUC)

**What It Is:**
- A GUI tool for managing Active Directory objects.
- Accessible from Server Manager on a Domain Controller.
- Also available via **RSAT (Remote Server Administration Tools)** on Windows 10/11.

**Key Objects:**
- **Users:** Identities for people accessing the domain.
- **Security Groups:** Collections of users used to assign permissions.

### Hands-On Actions: Creating Groups and Users

| Step | Tool | Action | Result |
|------|------|--------|--------|
| 1 | Server Manager → ADUC | Open ADUC on DomainController01. | Console opens. |
| 2 | ADUC | Expand `securelabsondemand.com` domain. | View domain structure. |
| 3 | ADUC | Click **Users** container. | View existing users/groups. |
| 4 | ADUC | Create new group: **Developers** (Global, Security). | Group created. |
| 5 | ADUC | Create new group: **Managers** (Global, Security). | Group created. |
| 6 | PowerShell | `New-ADGroup -Name HumanResources -GroupScope Global -GroupCategory Security` | Group created via CLI. |
| 7 | ADUC | Create user: **Sam Carpenter** (scarpenter). | User created. |
| 8 | ADUC | Add scarpenter to **Developers** group. | User added. |
| 9 | ADUC | Create user: **Carl Prince** (cprince). | User created. |
| 10 | ADUC | Add cprince to **Developers** and **Managers**. | User added to both. |
| 11 | PowerShell | `New-ADUser -Name lcasado ...` | User **Laura Casado** created. |
| 12 | PowerShell | `Add-ADGroupMember -Identity HumanResources -Members lcasado` | User added to HumanResources. |
| 13 | PowerShell | `gpupdate /force` | Force policy update. |

### PowerShell Commands Reference

**Creating a Group:**
```powershell
New-ADGroup -Name HumanResources -GroupScope Global -GroupCategory Security
```

**Creating a User:**
```powershell
New-ADUser -Name lcasado -UserPrincipalName lcasado@securelabsondemand.com -AccountPassword (ConvertTo-SecureString -AsPlainText "P@ssw0rd!" -Force) -GivenName Laura -Surname Casado -Enabled $true
```

**Adding a User to a Group:**
```powershell
Add-ADGroupMember -Identity HumanResources -Members lcasado
```

**Forcing Group Policy Update:**
```powershell
gpupdate /force
```

### Deliverable Screenshots Required (Part 1)

- [ ] New users and groups in Active Directory Users and Computers.

---

## 📂 Section 1, Part 2: Create Folders and Configure Security Permissions

### NTFS vs. Share Permissions

| Permission Type | Scope | Purpose |
|-----------------|-------|---------|
| **NTFS (Security) Permissions** | Applied directly to files/folders on an NTFS volume. | Control access at the filesystem level. |
| **Share Permissions** | Applied to network shares. | Control access for remote users connecting over the network. |

### NTFS Permission Levels

| Permission | Description |
|------------|-------------|
| **Read** | View folder and sub-folder contents. |
| **Write** | Add files and sub-folders. |
| **Modify** | Read + Write + Delete. |
| **List Folder Contents** | View contents and execute files. |
| **Read & Execute** | Read + Execute files. |
| **Full Control** | All actions, including changing permissions. |
| **Special Permissions** | Granular, custom permissions. |

> **Important:** Inheritance is enabled by default. Disable inheritance to set custom permissions for sub-folders.

### Folder Structure Created

```
C:\LabFiles\
├── HRfiles\    → HumanResources group only
├── MGRfiles\   → Managers group only
└── DEVfiles\   → Developers group only
```

### Hands-On Actions: Folder Creation and Permissions

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Log in to vWorkstation as `SECURELABSONDEM\Administrator`. | Domain admin access. |
| 2 | Create `C:\LabFiles` folder. | Root folder for the lab. |
| 3 | Open LabFiles Properties → Security tab. | Configure NTFS permissions. |
| 4 | Click **Advanced** → **Disable Inheritance**. | Stop inheriting parent folder permissions. |
| 5 | Remove **Users** group. | Prevent general domain users from accessing. |
| 6 | Add **Developers**, **Managers**, **HumanResources** groups. | Grant basic read/list permissions. |
| 7 | Create sub-folders: `HRfiles`, `MGRfiles`, `DEVfiles`. | Department-specific folders. |
| 8 | Configure HRfiles: Remove Managers & Developers; allow HumanResources **Modify**. | Restrict to HR only. |
| 9 | Configure MGRfiles: Remove HumanResources & Developers; allow Managers **Modify**. | Restrict to Managers only. |
| 10 | Configure DEVfiles: Remove HumanResources & Managers; allow Developers **Modify**. | Restrict to Developers only. |

### Deliverable Screenshots Required (Part 2)

- [ ] Updated Security permissions for the **HRfiles** folder.
- [ ] Updated Security permissions for the **MGRfiles** folder.
- [ ] Updated Security permissions for the **DEVfiles** folder.
- [ ] Three folders within the **LabFiles** folder.

---

## ✅ Section 1, Part 3: Verify Authentication and Access Controls

### Test Matrix

| User | Group Membership | Should Access | Should NOT Access |
|------|------------------|---------------|-------------------|
| **scarpenter** (Sam Carpenter) | Developers | DEVfiles | HRfiles, MGRfiles |
| **lcasado** (Laura Casado) | HumanResources | HRfiles | MGRfiles, DEVfiles |
| **cprince** (Carl Prince) | Developers, Managers | DEVfiles, MGRfiles | HRfiles |

### Hands-On Actions: Testing Access

| Step | User | Action | Expected Result |
|------|------|--------|-----------------|
| 1 | scarpenter | Try to open HRfiles | ❌ Access Denied |
| 2 | scarpenter | Try to open MGRfiles | ❌ Access Denied |
| 3 | scarpenter | Open DEVfiles, create text file | ✅ Success |
| 4 | lcasado | Open HRfiles, create text file | ✅ Success |
| 5 | lcasado | Try to open MGRfiles | ❌ Access Denied |
| 6 | lcasado | Try to open DEVfiles | ❌ Access Denied |
| 7 | cprince | Open MGRfiles, create text file | ✅ Success |
| 8 | cprince | Open DEVfiles, create text file | ✅ Success |
| 9 | cprince | Try to open HRfiles | ❌ Access Denied |

### Deliverable Screenshots Required (Part 3)

- [ ] Unsuccessful access error for HRfiles as scarpenter.
- [ ] Unsuccessful access error for MGRfiles as scarpenter.
- [ ] Properties of file created in DEVfiles by scarpenter.
- [ ] Properties of file created in HRfiles by lcasado.
- [ ] Unsuccessful access error for MGRfiles as lcasado.
- [ ] Unsuccessful access error for DEVfiles as lcasado.
- [ ] Properties of file created in MGRfiles by cprince.
- [ ] Properties of file created in DEVfiles by cprince.
- [ ] Unsuccessful access error for HRfiles as cprince.

---

## 🖥️ Section 2: Applied Learning – TrueNAS SMB Shares

### TrueNAS Overview

- **TrueNAS:** Open-source Network Attached Storage (NAS) operating system.
- **Storage Pool:** A virtual device created from one or more physical drives.
- **Dataset:** A filesystem within a storage pool (similar to a partition).
- **SMB (Server Message Block):** Microsoft's protocol for file and printer sharing.

### SMB Share Permissions

- SMB shares use **ACLs (Access Control Lists)** to define permissions.
- Active Directory manages authentication for SMB shares.
- **Group ownership** determines access.

### Time Synchronization Requirement

> ⚠️ **Critical:** Active Directory, Kerberos, and TrueNAS require **closely synchronized time**. If the Domain Controller's time is incorrect, authentication will fail.

**Fix:**
```cmd
time
# Enter current Pacific Standard Time (HH:MM:SS)
```

### Hands-On Actions: TrueNAS Configuration

| Step | Action | Purpose |
|------|--------|---------|
| 1 | Open Firefox → `http://172.30.0.5` | Access TrueNAS console. |
| 2 | Log in: `root / password` | Authenticate. |
| 3 | Directory Services → Active Directory | Configure AD integration. |
| 4 | Domain Account Password: `P@ssw0rd!2`; Enable → Save | Join the domain. |
| 5 | Storage → Pools → Add Dataset | Create `Employees` dataset. |
| 6 | Sharing → Windows Shares (SMB) → Add | Create SMB share. |
| 7 | Path: `/mnt/tank/Employees`, Name: `Employees` | Define share. |
| 8 | Configure ACL: Restricted template. | Restrict access. |
| 9 | Apply Group: `SECURELABSONDEM\domain users` with **Read** permission. | Domain users can read. |
| 10 | Add Dataset: `DEVfiles` → Set ACL → Full Control for **Developers**. | Developer share. |
| 11 | Add Dataset: `MGRfiles` → Full Control for **Managers**. | Manager share. |
| 12 | Add Dataset: `HRfiles` → Full Control for **HumanResources**. | HR share. |

### TrueNAS ACLs vs. Windows NTFS Permissions

| Aspect | Windows NTFS | TrueNAS (SMB) ACLs |
|--------|--------------|-------------------|
| Scope | Local files/folders. | Network shares. |
| Inheritance | Configurable. | Configurable. |
| Group Control | Groups can be assigned. | Groups can be assigned. |

### Deliverable Screenshots Required (Section 2)

- [ ] Employees dataset on the TrueNAS Pools page.
- [ ] Three new datasets on the TrueNAS Pools page.
- [ ] Employees folder while signed in as **scarpenter** (only DEVfiles visible).
- [ ] Employees folder while signed in as **lcasado** (only HRfiles visible).
- [ ] Employees folder while signed in as **cprince** (DEVfiles and MGRfiles visible).

---

## 🚀 Section 3: Challenge & Analysis – GG Studios Integration

### Scenario

- Secure Labs on Demand acquired **GG Studios**.
- Need to integrate GG Studios employees into Active Directory.
- Separate security groups for GG Studios teams.
- Separate datasets on TrueNAS for GG Studios departments.

### Tasks

| Task | Details |
|------|---------|
| **Create Security Groups** | GG-Developers, GG-Marketing (Global, Security). |
| **Create Users** | Abernathy Bobbleshaw (GG-Developers), Leslie Wu (GG-Marketing). |
| **Create TrueNAS Datasets** | GG_DEVfiles, GG_MRKfiles. |
| **Assign Permissions** | Full Control for corresponding AD groups. |
| **Verify Access** | Log in as each user; confirm folder visibility. |

### Deliverable Screenshots Required (Section 3)

- [ ] Member Of tab for **Abernathy Bobbleshaw**.
- [ ] Member Of tab for **Leslie Wu**.
- [ ] New GG Studios datasets on the TrueNAS Pools page.
- [ ] Employees folder while signed in as **abobbleshaw**.
- [ ] Employees folder while signed in as **lwu**.

---

## 🛠️ Master Command Reference

### Windows / Active Directory Commands

| Command | Purpose |
|---------|---------|
| `New-ADGroup -Name <name> -GroupScope <scope> -GroupCategory <category>` | Create a new security group. |
| `New-ADUser -Name <name> -UserPrincipalName <UPN> -AccountPassword (ConvertTo-SecureString -AsPlainText "<password>" -Force) -GivenName <first> -Surname <last> -Enabled $true` | Create a new user account. |
| `Add-ADGroupMember -Identity <group> -Members <user>` | Add a user to a group. |
| `gpupdate /force` | Force immediate Group Policy update. |
| `time` | Set system time (for time synchronization). |

### TrueNAS (Web GUI) Steps

| Action | Navigation |
|--------|------------|
| Access TrueNAS | `http://172.30.0.5` (root/password). |
| Join AD Domain | Directory Services → Active Directory → Enable. |
| Create Dataset | Storage → Pools → Tank → Add Dataset. |
| Create SMB Share | Sharing → Windows Shares (SMB) → Add. |
| Configure ACL | Click "Configure Now" when prompted. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Authentication** | The process of verifying a user's identity. |
| **Authorization** | The process of determining what an authenticated user can do. |
| **Access Control** | The collection of mechanisms that protect resources from unauthorized access. |
| **Active Directory (AD)** | Microsoft's centralized database for managing users, computers, and policies. |
| **Domain Controller (DC)** | A server hosting Active Directory; the central authentication authority. |
| **Organizational Unit (OU)** | A container within Active Directory used to organize objects. |
| **Security Group** | A collection of users used to assign permissions. |
| **Global Security Group** | A group scope used within a single domain. |
| **NTFS Permissions** | Filesystem-level permissions on Windows NTFS volumes. |
| **Share Permissions** | Network-level permissions for SMB shares. |
| **ACL (Access Control List)** | A list of permissions for a resource. |
| **Principle of Least Privilege** | Grant only the minimum permissions required. |
| **SMB (Server Message Block)** | Microsoft's file and printer sharing protocol. |
| **Samba** | Microsoft's implementation of SMB. |
| **TrueNAS** | Open-source NAS operating system. |
| **Storage Pool** | A virtual storage device made from multiple physical drives. |
| **Dataset** | A filesystem within a TrueNAS pool. |

---

## 📋 Lab 4 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | New users and groups in ADUC | [ ] |
| 2 | Updated Security permissions for HRfiles | [ ] |
| 3 | Updated Security permissions for MGRfiles | [ ] |
| 4 | Updated Security permissions for DEVfiles | [ ] |
| 5 | Three folders within LabFiles | [ ] |
| 6 | Unsuccessful access – HRfiles as scarpenter | [ ] |
| 7 | Unsuccessful access – MGRfiles as scarpenter | [ ] |
| 8 | Properties – DEVfiles file by scarpenter | [ ] |
| 9 | Properties – HRfiles file by lcasado | [ ] |
| 10 | Unsuccessful access – MGRfiles as lcasado | [ ] |
| 11 | Unsuccessful access – DEVfiles as lcasado | [ ] |
| 12 | Properties – MGRfiles file by cprince | [ ] |
| 13 | Properties – DEVfiles file by cprince | [ ] |
| 14 | Unsuccessful access – HRfiles as cprince | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 15 | Employees dataset on TrueNAS Pools | [ ] |
| 16 | Three new datasets on TrueNAS Pools | [ ] |
| 17 | Employees folder as scarpenter | [ ] |
| 18 | Employees folder as lcasado | [ ] |
| 19 | Employees folder as cprince | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 20 | Member Of tab – Abernathy Bobbleshaw | [ ] |
| 21 | Member Of tab – Leslie Wu | [ ] |
| 22 | New GG Studios datasets on TrueNAS | [ ] |
| 23 | Employees folder as abobbleshaw | [ ] |
| 24 | Employees folder as lwu | [ ] |

---

## 💡 Key Takeaways – Lab 4

### Authentication & Authorization
1. **Authentication** verifies *who* you are; **authorization** decides *what* you can do.
2. **Active Directory** provides centralized authentication and authorization.
3. **Group Policy** enforces security settings across all domain-joined machines.

### Group Management
4. **Assign permissions to groups, not users** – it's easier to manage.
5. **Global security groups** are the most common type for single-domain environments.
6. **PowerShell** is more efficient than GUI for repetitive tasks (user/group creation).

### Folder Permissions
7. **NTFS permissions** control local access; **Share permissions** control network access.
8. **Inheritance** is enabled by default – disable it to set custom sub-folder permissions.
9. **Modify** permission includes Read, Write, and Delete.
10. **Full Control** also allows changing permissions (use sparingly).

### Principle of Least Privilege
11. Users should have **only the access they need** to do their job.
12. If a user is in multiple groups, they get the **union** of all permissions.
13. Test your controls by logging in as each user and verifying access.

### TrueNAS Integration
14. TrueNAS can integrate with Active Directory for centralized authentication.
15. **Time synchronization** is critical for AD/Kerberos authentication.
16. **SMB shares** allow Windows users to access TrueNAS as a network drive.
17. **Datasets** are created within storage pools; each dataset gets its own ACL.

### Testing & Verification
18. Always **validate** your access controls after configuration.
19. Access Denied errors are a sign that permissions are working correctly.
20. Document permissions with screenshots for future reference and auditing.