# Course 5 – Module 2: Identity and Access Management

---

## Principle of Least Privilege (PoLP)

**Principle of least privilege** – Users are granted only the minimum level of access and authorization required to complete a task or function.

### Benefits
- Limits access to sensitive information.
- Reduces accidental data modification, tampering, or loss.
- Supports system monitoring and administration.
- Closely related to **separation of duties** – dividing tasks among multiple users to prevent any single user from having complete control.

### User Account Types
| Account Type | Description |
|--------------|-------------|
| **Guest** | External users (customers, clients, contractors, partners). |
| **User** | Employees based on job duties. |
| **Service** | Applications or software interacting with other software. |
| **Privileged** | Elevated permissions or administrative access. |

### Auditing Accounts
1. **Usage audits** – Review which resources each account accesses.
2. **Privilege audits** – Check for privilege creep (excess permissions).
3. **Account change audits** – Monitor directory for suspicious changes.

---

## The Data Lifecycle

**Data lifecycle** – Model describing how data flows through an organization from creation to destruction.

### Five Stages
| Stage | Description |
|-------|-------------|
| **Collect** | Data is gathered from internal/external sources. |
| **Store** | Data is saved in databases, cloud storage, etc. |
| **Use** | Data is accessed, processed, or analyzed. |
| **Archive** | Data is retained for long-term reference. |
| **Destroy** | Data is permanently removed when no longer useful. |

### Data Governance
**Data governance** – Set of processes that define how an organization manages information.

| Role | Responsibility |
|------|----------------|
| **Data owner** | Decides who can access, edit, use, or destroy their information. |
| **Data custodian** | Handles safe transport, storage, and protection of information. |
| **Data steward** | Maintains and implements data governance policies. |

### Legally Protected Information
- **PII** – Personally identifiable information (name, address, phone).
- **PHI** – Protected health information (HIPAA in U.S., GDPR in EU).
- **SPII** – Sensitive PII (bank account, login credentials).

---

## Privacy Regulations and Compliance

**Information privacy** – Protection from unauthorized access and distribution of data.  
**Information security (InfoSec)** – Keeping data in all states away from unauthorized users.

### Key Regulations
| Regulation | Scope |
|------------|-------|
| **GDPR** | EU regulation; protects personal data of EU citizens/residents. |
| **PCI DSS** | Financial industry standard; secures credit/debit card transactions. |
| **HIPAA** | U.S. law; protects patient health information. |

### Security Assessments vs Audits
- **Security audit** – Review of controls, policies, and procedures against expectations (typically annual).
- **Security assessment** – Check resilience against threats (typically every 3-6 months).

---

## Symmetric vs Asymmetric Encryption

| Type | Key Usage | Speed | Security |
|------|-----------|-------|----------|
| **Symmetric** | Single secret key for encryption and decryption. | Faster | Shorter keys less secure. |
| **Asymmetric** | Public key (encrypts) + Private key (decrypts). | Slower | Longer keys more secure. |

### Common Algorithms
**Symmetric**
- **Triple DES (3DES)** – 168-bit keys (outdated, moving away).
- **AES** – 128, 192, or 256-bit keys (very secure).

**Asymmetric**
- **RSA** – 1,024, 2,048, or 4,096-bit keys.
- **DSA** – 2,048-bit keys.

### Key Length
- Longer keys = more secure but slower processing.
- Key length measured in **bits** (smallest unit of data).

*Kerckhoff's principle* – A cipher should be secure even if all its details (except the private key) are public.

---

## Hash Functions

**Hash function** – Algorithm that produces a fixed-size code (digest) that cannot be decrypted.

### Common Hash Algorithms
| Algorithm | Digest Size | Status |
|-----------|-------------|--------|
| **MD5** | 128-bit | Vulnerable to hash collisions (outdated). |
| **SHA-1** | 160-bit | Collision-resistant but not perfect. |
| **SHA-224, SHA-256, SHA-384, SHA-512** | 224-512 bits | NIST-approved, collision-resistant. |

### Attacks and Defenses
- **Hash collision** – Different inputs produce the same hash value.
- **Rainbow table** – Pre-generated hash values and plaintext (dictionary of weak passwords).
- **Salting** – Adding random characters to data before hashing to prevent rainbow table attacks.

### Key Commands (Lab Practice)
```bash
sha256sum file1.txt          # Generate hash
cat file1hash                # Display hash
cmp file1hash file2hash      # Compare hashes byte by byte
```

---

## SSO and MFA

### Single Sign-On (SSO)
Combines several logins into one. Benefits:
- Improves user experience.
- Lowers costs.
- Reduces attack surface.

**Protocols**: LDAP (on-premises), SAML (cloud).

**Password fatigue** – Users reusing passwords across services.

### Multi-Factor Authentication (MFA)
Requires two or more verification factors:
- **Something you know** – Password, PIN.
- **Something you have** – One-time passcode (OTP) via SMS, token.
- **Something you are** – Fingerprint, facial scan.

**2FA** – Two factors. **3FA** – Three factors.

---

## Identity and Access Management (IAM)

**IAM** – Collection of processes and technologies that manages digital identities in an environment.

### Authentication Factors
- Knowledge – something you know.
- Ownership – something you have.
- Characteristic – something you are.

### User Provisioning
Creating and maintaining a user's digital identity. **Deprovisioning** – Removing access when no longer needed.

### Access Control Frameworks
| Framework | Description |
|-----------|-------------|
| **MAC (Mandatory Access Control)** | Strictest; access granted by central authority (government/military). |
| **DAC (Discretionary Access Control)** | Data owner decides access (e.g., Google Drive sharing). |
| **RBAC (Role-Based Access Control)** | Access determined by user's role (e.g., marketing vs. network admin). |

**AAA Framework** – Authentication, Authorization, Accounting (closely related to IAM).

---

## Module 2 Glossary

- **Access controls** – Manage access, authorization, and accountability.
- **Algorithm** – Set of rules to solve a problem.
- **API token** – Small block of encrypted code with user info.
- **Asymmetric encryption** – Public/private key pair.
- **Bit** – Smallest unit of data.
- **Brute force attack** – Trial-and-error to discover private info.
- **Cipher** – Algorithm that encrypts information.
- **Cryptographic key** – Decrypts ciphertext.
- **Cryptography** – Transforming information to prevent unauthorized reading.
- **Data custodian** – Responsible for safe handling, transport, storage.
- **Data owner** – Decides access to their information.
- **Digital certificate** – Verifies identity of public key holder.
- **Encryption** – Converting data to encoded format.
- **Hash collision** – Different inputs producing same hash.
- **Hash function** – Algorithm producing non-decryptable code.
- **IAM** – Processes/technologies for managing digital identities.
- **Information privacy** – Protection from unauthorized access/distribution.
- **MFA** – Two or more verification factors.
- **Non-repudiation** – Authenticity can't be denied.
- **PCI DSS** – Financial industry security standards.
- **PII** – Information inferring identity.
- **Principle of least privilege** – Minimal access required.
- **PHI** – Protected health information.
- **PKI** – Encryption framework for online exchange.
- **Rainbow table** – Pre-generated hash values and plaintext.
- **Salting** – Random characters added before hashing.
- **Security assessment** – Check resilience against threats.
- **Security audit** – Review of controls/policies/procedures.
- **Security controls** – Safeguards to reduce risks.
- **Separation of duties** – No single user has complete control.
- **Session** – Sequence of requests/responses for a user.
- **Session cookie** – Token validating session duration.
- **SSO** – Technology combining multiple logins.
- **Symmetric encryption** – Single secret key.
- **User provisioning** – Creating/maintaining digital identity.