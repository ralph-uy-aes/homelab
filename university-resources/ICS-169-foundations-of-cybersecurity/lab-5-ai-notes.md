# 📚 ICS 169 – Lab 5: Using Encryption to Enhance Confidentiality and Integrity
## Complete Notes

---

## 📖 Table of Contents

1. [Core Concepts & Introduction](#-core-concepts--introduction)
2. [Section 1, Part 1: Create and Exchange Asymmetric Encryption Keys](#-section-1-part-1-create-and-exchange-asymmetric-encryption-keys)
3. [Section 1, Part 2: Encrypt a File Using Asymmetric Encryption](#-section-1-part-2-encrypt-a-file-using-asymmetric-encryption)
4. [Section 1, Part 3: Decrypt a File Using Asymmetric Encryption](#-section-1-part-3-decrypt-a-file-using-asymmetric-encryption)
5. [Section 2: Applied Learning – OpenSSL and Hybrid Cryptography](#-section-2-applied-learning--openssl-and-hybrid-cryptography)
6. [Section 3: Challenge & Analysis – Digital Signatures with GPG](#-section-3-challenge--analysis--digital-signatures-with-gpg)
7. [Master Command Reference](#-master-command-reference)
8. [Comprehensive Vocabulary](#-comprehensive-vocabulary)
9. [Lab Deliverables Checklist](#-lab-5-deliverables-checklist)
10. [Key Takeaways](#-key-takeaways--lab-5)

---

## 🎯 Core Concepts & Introduction

### Cryptography Overview

**Cryptography** is the method of securing information by transforming human-readable information (plaintext) into unreadable ciphertext that can be read only by someone who possesses the correct key and can transform it back into plaintext.

### The Three Cryptographic Approaches

| Approach | Description | Speed | Authentication |
|----------|-------------|-------|----------------|
| **Symmetric Cryptography** | Same key used for encryption and decryption ("shared secret"). | Fast | ❌ No sender authentication |
| **Asymmetric Cryptography** | Two keys: public (encrypt) and private (decrypt). | Slow | ✅ Provides authentication |
| **Hybrid Cryptography** | Asymmetric for key exchange; symmetric for data encryption. | Fast | ✅ Provides authentication |

### Cryptographic Goals

| Goal | Description |
|------|-------------|
| **Confidentiality** | Only the intended recipient can read the message. |
| **Integrity** | The message has not been altered in transit. |
| **Authentication** | The sender's identity can be verified. |
| **Non-repudiation** | The sender cannot deny having sent the message. |

### Digital Signatures

A **digital signature** is constructed to demonstrate:
- **Integrity** of the signed data.
- **Authentication** – the signer had access to a particular private key.
- **Non-repudiation** – the signer cannot deny signing.

**Digital Signature Process:**

1. Sender calculates a **hash** of the message.
2. Sender encrypts the hash with their **private key** → this is the digital signature.
3. Sender sends the original message + digital signature.
4. Receiver calculates hash of received message.
5. Receiver decrypts digital signature using sender's **public key**.
6. If the two values match:
   - ✅ Message integrity is confirmed.
   - ✅ Sender authentication is confirmed.

### Hash Functions

- A **one-way mathematical function**.
- Takes arbitrary input → fixed-length output.
- Any change to input → substantial change to output.
- **Cannot be reversed** (computationally prohibitive).

> **Analogy:** Like grinding coffee beans – easy to grind, impossible to reassemble.

### Public Key Infrastructure (PKI)

- **PKI** is a framework that defines trusted entities to manage keys in the form of **digital certificates**.
- A digital certificate consists of a public encryption key + the identity of its owner, digitally signed by a **Certificate Authority (CA)**.
- PKI makes it possible to trust asymmetric cryptography at scale.

---

### Lab Topology Summary (Lab 5)

| Device | IP Address | OS / Role |
|--------|------------|-----------|
| vWorkstation | 172.30.0.2 | Windows Server 2022 (Kleopatra / GPG) |
| TargetLinux01 | 172.30.0.6 | Ubuntu 20 (OpenSSL / GPG) |

---

## 🔑 Section 1, Part 1: Create and Exchange Asymmetric Encryption Keys

### GPG4Win and Kleopatra

- **GPG4Win** is the Windows version of **GNU Privacy Guard (GPG)** .
- **Kleopatra** is the certificate manager and GUI for GPG.
- GPG is a free implementation of the **OpenPGP standard**.

### Key Pair Creation

| Field | Student Account | Alice's Account |
|-------|-----------------|-----------------|
| Name | Your Name | Alice Dodson |
| Email | student@securelabsondemand.com | adodson@securelabsondemand.com |
| Passphrase | 1Tsecurity! | Cyb3rSec! |
| Algorithm | RSA 3072-bit (default) | RSA 3072-bit (default) |

### Key Pair Components

| Component | Purpose |
|-----------|---------|
| **Public Key** | Shared with others so they can encrypt messages to you. |
| **Private Key** | Kept secret; used to decrypt messages sent to you. |
| **Fingerprint** | A 40-character hash of the public key; used to validate key integrity. |
| **Key-ID** | The last 8 characters of the fingerprint. |

### Hands-On Actions: Key Generation

| Step | User | Action |
|------|------|--------|
| 1 | Student | Log in to vWorkstation as Student (P@ssw0rd!). |
| 2 | Student | Open Kleopatra → File → New Key Pair. |
| 3 | Student | Select "Create a personal OpenPGP key pair". |
| 4 | Student | Enter Name, Email, check "Protect with passphrase". |
| 5 | Student | Passphrase: `1Tsecurity!`. |
| 6 | Student | ✅ Screen capture – fingerprint. |
| 7 | Student | Export public key to `C:\Users\Public`. |
| 8 | Student | Sign out; log in as Alice Dodson (adodson, P@ssw0rd!). |
| 9 | Alice | Repeat steps 2–5 with Name: Alice Dodson, Passphrase: `Cyb3rSec!`. |
| 10 | Alice | ✅ Screen capture – fingerprint. |
| 11 | Alice | Import Student's public key from `C:\Users\Public`. |
| 12 | Alice | Certify the key using Alice's passphrase. |
| 13 | Alice | ✅ Screen capture – Student's key in Alice's cache. |
| 14 | Alice | Export Alice's public key to `C:\Users\Public`. |
| 15 | Alice | Sign out; log back in as Student. |
| 16 | Student | Import Alice's public key. |
| 17 | Student | Certify the key using Student's passphrase. |
| 18 | Student | ✅ Screen capture – Alice's key in Student's cache. |

### Exporting a Public Key

- **Menu:** File → Export
- **Location:** `This PC\C:\Users\Public`
- **File Format:** `.asc` (ASCII-armored OpenPGP certificate)

### Certifying a Public Key

- **Why:** Certifying a certificate says you **trust the identity** associated with that public key.
- **How:** In Kleopatra, import the key → click Yes when prompted → enter your passphrase.

### Deliverable Screenshots Required (Part 1)

- [ ] Fingerprint for your key pair (Student).
- [ ] Fingerprint for Alice's key pair.
- [ ] Your public key in Alice's certificate cache.
- [ ] Alice's public key in your certificate cache.

---

## 🔐 Section 1, Part 2: Encrypt a File Using Asymmetric Encryption

### Asymmetric Encryption Process

| Step | Action | Key Used |
|------|--------|----------|
| 1 | Create plaintext message. | — |
| 2 | **Sign** the message. | Sender's **Private Key** |
| 3 | **Encrypt** the message. | Recipient's **Public Key** |
| 4 | Send encrypted file. | — |

### What This Achieves

| Property | How It's Provided |
|----------|-------------------|
| **Confidentiality** | Encrypted with recipient's public key. |
| **Authentication** | Signed with sender's private key. |
| **Integrity** | Digital signature uses hashing. |
| **Non-repudiation** | Only sender has their private key. |

### Hands-On Actions: Encrypting the Message

| Step | User | Action |
|------|------|--------|
| 1 | Student | Right-click desktop → New → Text Document. |
| 2 | Student | Name it `secret-message.txt`. |
| 3 | Student | Open file, type: `I like information systems security` and your name. |
| 4 | Student | Right-click `secret-message.txt` → Sign and encrypt. |
| 5 | Student | Encrypt for: `Alice Dodson` (using her public key). |
| 6 | Student | Click Sign/Encrypt. |
| 7 | Student | ✅ Screen capture – successful signing and encryption message. |
| 8 | Student | Open `secret-message.txt.gpg` with Notepad. |
| 9 | Student | ✅ Screen capture – ciphertext (raw encrypted data). |

### File Naming Convention

| File | Description |
|------|-------------|
| `secret-message.txt` | Original plaintext message. |
| `secret-message.txt.gpg` | Encrypted and signed file (binary ciphertext). |

### Deliverable Screenshots Required (Part 2)

- [ ] Successful signing and encryption message.
- [ ] Ciphertext.

---

## 🔓 Section 1, Part 3: Decrypt a File Using Asymmetric Encryption

### Decryption Process (Alice's Perspective)

| Step | Action |
|------|--------|
| 1 | Receive the encrypted file (over insecure channel). |
| 2 | Decrypt the ciphertext using Alice's **private key**. |
| 3 | Decrypt the digital signature using Student's **public key**. |
| 4 | Recompute the hash and compare with the decrypted signature. |
| 5 | If they match → ✅ Integrity and authentication verified. |

### Hands-On Actions: Decrypting the Message

| Step | User | Action |
|------|------|--------|
| 1 | Student | Copy `secret-message.txt.gpg` to `C:\Users\Public`. |
| 2 | Student | Sign out; log in as Alice Dodson (adodson, P@ssw0rd!). |
| 3 | Alice | Copy the file from `C:\Users\Public` to Alice's desktop. |
| 4 | Alice | Right-click the file → Decrypt and verify. |
| 5 | Alice | Enter Alice's passphrase: `Cyb3rSec!`. |
| 6 | Alice | ✅ Screen capture – Decrypt/Verify Files window. |
| 7 | Alice | Click Save All. |
| 8 | Alice | Open `secret-message.txt` in Notepad. |
| 9 | Alice | ✅ Screen capture – decrypted message in Notepad. |

### Decrypt/Verify Window Messages

| Message | Meaning |
|---------|---------|
| "Decryption successful" | Alice's private key successfully decrypted the file. |
| "Digital signature is valid" | The signature was verified using Student's public key. |
| "Certificate is fully trusted" | Alice has certified Student's public key. |

### Deliverable Screenshots Required (Part 3)

- [ ] Decrypt/Verify Files window.
- [ ] Decrypted `secret-message.txt` file in Notepad.

---

## 🖥️ Section 2: Applied Learning – OpenSSL and Hybrid Cryptography

### OpenSSL Overview

- **OpenSSL** is a software library used to secure communications over insecure network connections.
- Supports **SSL** and **TLS** (the "S" in HTTPS).
- Can be used for both symmetric and asymmetric cryptographic operations.

### Hybrid Cryptography in Practice

| Step | Action |
|------|--------|
| 1 | Generate an **asymmetric key pair** for the recipient. |
| 2 | Create a plaintext message. |
| 3 | **Symmetric encryption** – encrypt the message with a password/key. |
| 4 | **Asymmetric encryption** – encrypt the symmetric key with the recipient's **public key**. |
| 5 | Send both the encrypted message and encrypted symmetric key. |
| 6 | Recipient decrypts the symmetric key with their **private key**. |
| 7 | Recipient decrypts the message with the symmetric key. |

### Diffie-Hellman Key Exchange

- Uses asymmetric cryptography to generate identical symmetric keys on both ends.
- Keys are **never sent directly** over the channel.
- The foundation of hybrid cryptography in TLS.

### Part 1: Create an Asymmetric Key Pair (Instructor)

| Command | Purpose |
|---------|---------|
| `openssl genrsa -aes256 -out instructor_private.key 8192` | Generate 8192-bit RSA private key (AES-256 encrypted). |
| `openssl rsa -in instructor_private.key -pubout -out instructor_public.key` | Extract the public key from the private key. |
| `ls *.key` | List all key files. |

**Credentials:**
- **User:** instructor
- **Password:** password
- **Private Key Passphrase:** `s3c^r!ty`

**Key Files:**
- `instructor_private.key` – **Keep secret!** Protected with a passphrase.
- `instructor_public.key` – Share freely.

### Hands-On Actions: Instructor Key Generation

| Step | User | Action |
|------|------|--------|
| 1 | instructor | Log in to TargetLinux01 (instructor/password). |
| 2 | instructor | Open Terminal. |
| 3 | instructor | `openssl genrsa -aes256 -out instructor_private.key 8192` |
| 4 | instructor | Passphrase: `s3c^r!ty` (twice). |
| 5 | instructor | `openssl rsa -in instructor_private.key -pubout -out instructor_public.key` |
| 6 | instructor | Passphrase: `s3c^r!ty`. |
| 7 | instructor | `ls *.key` |
| 8 | instructor | ✅ Screen capture – key pair files. |
| 9 | instructor | `cp instructor_public.key /tmp` |
| 10 | instructor | `exit` and log out. |

### Deliverable Screenshots Required (Part 1)

- [ ] Instructor's key pair files (output of `ls *.key`).

---

### Part 2: Encrypt a File Using Symmetric Encryption (Student)

| Command | Purpose |
|---------|---------|
| `cp /tmp/instructor_public.key ~/` | Copy instructor's public key. |
| `touch secretmessage.txt` | Create a file. |
| `echo "Your Name" > secretmessage.txt` | Write name to file. |
| `echo "Encrypted Message for Instructor" >> secretmessage.txt` | Append message. |
| `cat secretmessage.txt` | Verify contents. |
| `openssl enc -aes-256-cbc -pbkdf2 -salt -a -e -in secretmessage.txt -out secretmessage_ENCRYPTED.txt` | Encrypt the file. |

**Credentials:**
- **User:** student
- **Password:** password

**Encryption Command Breakdown:**

| Argument | Meaning |
|----------|---------|
| `openssl enc` | Start an encryption operation. |
| `-aes-256-cbc` | Algorithm: AES with 256-bit key, CBC mode. |
| `-pbkdf2` | Use PBKDF2 to generate the key from the password. |
| `-salt` | Use a salt (random value). |
| `-a` | Base64 encode the output (readable). |
| `-e` | Encrypt. |
| `-in secretmessage.txt` | Input file (plaintext). |
| `-out secretmessage_ENCRYPTED.txt` | Output file (ciphertext). |

### Hands-On Actions: Student File Encryption

| Step | User | Action |
|------|------|--------|
| 1 | student | Log in to TargetLinux01 (student/password). |
| 2 | student | Open Terminal. |
| 3 | student | `cp /tmp/instructor_public.key ~/` |
| 4 | student | `touch secretmessage.txt` |
| 5 | student | `echo "Your Name" > secretmessage.txt` |
| 6 | student | `echo "Encrypted Message for Instructor" >> secretmessage.txt` |
| 7 | student | `cat secretmessage.txt` |
| 8 | student | `openssl enc -aes-256-cbc -pbkdf2 -salt -a -e -in secretmessage.txt -out secretmessage_ENCRYPTED.txt` |
| 9 | student | Password: `yourownpassword` (remember it!) |
| 10 | student | `cat secretmessage_ENCRYPTED.txt` |
| 11 | student | ✅ Screen capture – ciphertext. |
| 12 | student | `rm secretmessage.txt` (delete plaintext). |
| 13 | student | `ls` |
| 14 | student | ✅ Screen capture – ls output. |

### Deliverable Screenshots Required (Part 2)

- [ ] Ciphertext in `secretmessage_ENCRYPTED.txt`.
- [ ] Output of the `ls` command.
- [ ] **Document the password** you used to encrypt the file.

---

### Part 3: Transfer and Decrypt a File Using Hybrid Cryptography

### Student: Encrypt the Symmetric Key

| Command | Purpose |
|---------|---------|
| `touch secretkey.txt` | Create a file for the symmetric key. |
| `echo "yourownpassword" > secretkey.txt` | Write the symmetric password to the file. |
| `openssl rsautl -encrypt -pubin -inkey instructor_public.key -in secretkey.txt -out secretkey_ENCRYPTED.txt` | Encrypt the symmetric key with instructor's public key. |

**Command Breakdown:**

| Argument | Meaning |
|----------|---------|
| `openssl rsautl -encrypt` | RSA asymmetric encryption operation. |
| `-pubin` | Use a public key (vs. private key). |
| `-inkey instructor_public.key` | The public key file. |
| `-in secretkey.txt` | Input file (plaintext symmetric key). |
| `-out secretkey_ENCRYPTED.txt` | Output file (encrypted symmetric key). |

### Hands-On Actions: Student – Transfer Files

| Step | User | Action |
|------|------|--------|
| 1 | student | `touch secretkey.txt` |
| 2 | student | `echo "yourownpassword" > secretkey.txt` |
| 3 | student | `cat secretkey.txt` |
| 4 | student | `openssl rsautl -encrypt -pubin -inkey instructor_public.key -in secretkey.txt -out secretkey_ENCRYPTED.txt` |
| 5 | student | `cat secretkey_ENCRYPTED.txt` |
| 6 | student | ✅ Screen capture – encrypted contents. |
| 7 | student | `cp secretmessage_ENCRYPTED.txt /tmp` |
| 8 | student | `cp secretkey_ENCRYPTED.txt /tmp` |
| 9 | student | `exit` and log out. |

### Instructor: Decrypt and Verify

| Command | Purpose |
|---------|---------|
| `cp /tmp/secretmessage_ENCRYPTED.txt ~/` | Copy encrypted message. |
| `cp /tmp/secretkey_ENCRYPTED.txt ~/` | Copy encrypted symmetric key. |
| `openssl rsautl -decrypt -inkey instructor_private.key -in secretkey_ENCRYPTED.txt -out secretkey_DECRYPTED.txt` | Decrypt the symmetric key. |
| `openssl enc -aes-256-cbc -pbkdf2 -salt -a -d -in secretmessage_ENCRYPTED.txt -out secretmessage_DECRYPTED.txt` | Decrypt the message with the symmetric key. |

**Decryption Command Breakdown:**

| Argument | Meaning |
|----------|---------|
| `-d` | Decrypt (vs. -e for encrypt). |
| `-in secretmessage_ENCRYPTED.txt` | Input file (ciphertext). |
| `-out secretmessage_DECRYPTED.txt` | Output file (plaintext). |

### Hands-On Actions: Instructor – Decrypt

| Step | User | Action |
|------|------|--------|
| 1 | instructor | Log in to TargetLinux01 (instructor/password). |
| 2 | instructor | Open Terminal. |
| 3 | instructor | `cp /tmp/secretmessage_ENCRYPTED.txt ~/` |
| 4 | instructor | `cp /tmp/secretkey_ENCRYPTED.txt ~/` |
| 5 | instructor | `openssl rsautl -decrypt -inkey instructor_private.key -in secretkey_ENCRYPTED.txt -out secretkey_DECRYPTED.txt` |
| 6 | instructor | Passphrase: `s3c^r!ty`. |
| 7 | instructor | `cat secretkey_DECRYPTED.txt` |
| 8 | instructor | ✅ Screen capture – decrypted key. |
| 9 | instructor | `openssl enc -aes-256-cbc -pbkdf2 -salt -a -d -in secretmessage_ENCRYPTED.txt -out secretmessage_DECRYPTED.txt` |
| 10 | instructor | Password: (the symmetric key from the file). |
| 11 | instructor | `cat secretmessage_DECRYPTED.txt` |
| 12 | instructor | ✅ Screen capture – decrypted message. |

### Deliverable Screenshots Required (Part 3)

- [ ] Encrypted contents of `secretkey_ENCRYPTED.txt`.
- [ ] Decrypted contents of `secretkey_DECRYPTED.txt`.
- [ ] Contents of `secretmessage_DECRYPTED.txt`.

---

## ✍️ Section 3: Challenge & Analysis – Digital Signatures with GPG

### Part 1: Digitally Sign a Document Using GPG

**Scenario:** A security analyst needs to verify GPG compatibility between Windows and Linux.

**Tasks:**

| Task | Command |
|------|---------|
| Generate a new GPG key pair | `gpg --full-generate-key` |
| Create a message | `echo "Your message" > unsignedmessage.txt` |
| Sign the message | `gpg --sign unsignedmessage.txt` |
| Export the public key | `gpg --export -a "Quentin Compson" > qcompson_pubkey.asc` |

**Credentials:**
- **User:** instructor
- **Password:** password
- **Real Name:** Quentin Compson
- **Email:** qcompson@securelabsondemand.com
- **Passphrase:** BELLin2

### Hands-On Actions: GPG Signing

| Step | User | Action |
|------|------|--------|
| 1 | instructor | Log in to TargetLinux01 (instructor/password). |
| 2 | instructor | Open Terminal. |
| 3 | instructor | `gpg --full-generate-key` |
| 4 | instructor | Follow prompts: Real name, Email, Passphrase. |
| 5 | instructor | ✅ Screen capture – key fingerprint. |
| 6 | instructor | `echo "Your message text here" > unsignedmessage.txt` |
| 7 | instructor | ✅ Screen capture – contents of unsignedmessage.txt. |
| 8 | instructor | `gpg --sign unsignedmessage.txt` |
| 9 | instructor | `gpg --export -a "Quentin Compson" > qcompson_pubkey.asc` |
| 10 | instructor | `cp unsignedmessage.txt.gpg /tmp` |
| 11 | instructor | `cp qcompson_pubkey.asc /tmp` |

### Deliverable Screenshots Required (Part 1)

- [ ] Key fingerprint for the key pair generated.
- [ ] Contents of `unsignedmessage.txt`.

---

### Part 2: Verify the Digital Signature Using Kleopatra

**Objective:** Transfer the public key and signed document from TargetLinux01 to vWorkstation using **WinSCP**.

**WinSCP Connection Details:**
- **Hostname:** 172.30.0.6
- **Username:** root
- **Password:** toor
- **Protocol:** SFTP

**Steps in WinSCP:**
1. Connect to TargetLinux01.
2. Navigate to `/tmp`.
3. Copy `unsignedmessage.txt.gpg` and `qcompson_pubkey.asc` to the vWorkstation desktop.

**Kleopatra Verification Steps:**
1. Open Kleopatra.
2. Import the public key (`qcompson_pubkey.asc`).
3. Right-click the signed file (`unsignedmessage.txt.gpg`) → Decrypt and verify.
4. If successful, you should see the decrypted message.

### Deliverable Screenshots Required (Part 2)

- [ ] Successful signature verification on the signed message file.

---

## 🛠️ Master Command Reference

### Kleopatra / GPG (Windows / Linux)

| Action | Command / Method |
|--------|------------------|
| Open Kleopatra | Double-click Kleopatra icon. |
| Generate key pair | File → New Key Pair → Personal OpenPGP key pair. |
| Export public key | File → Export (save to `C:\Users\Public`). |
| Import public key | Kleopatra toolbar → Import Certificates. |
| Certify a key | Click Yes after importing → enter passphrase. |
| Sign and encrypt | Right-click file → Sign and encrypt. |
| Decrypt and verify | Right-click `.gpg` file → Decrypt and verify. |

### GPG Commands (Linux)

| Command | Purpose |
|---------|---------|
| `gpg --full-generate-key` | Generate a new GPG key pair. |
| `gpg --sign <file>` | Sign a file (creates `<file>.gpg`). |
| `gpg --export -a "<name>" > <file>.asc` | Export public key (ASCII-armored). |
| `gpg --verify <file>.gpg` | Verify the signature on a file. |

### OpenSSL Commands (Linux)

| Command | Purpose |
|---------|---------|
| `openssl genrsa -aes256 -out <file>.key 8192` | Generate RSA private key (AES-256 encrypted). |
| `openssl rsa -in <file>.key -pubout -out <file>.pub` | Extract public key. |
| `openssl enc -aes-256-cbc -pbkdf2 -salt -a -e -in <file> -out <file>_ENCRYPTED.txt` | Symmetric encryption. |
| `openssl enc -aes-256-cbc -pbkdf2 -salt -a -d -in <file>_ENCRYPTED.txt -out <file>_DECRYPTED.txt` | Symmetric decryption. |
| `openssl rsautl -encrypt -pubin -inkey <pub>.key -in <file> -out <file>_ENCRYPTED.txt` | Asymmetric encryption (RSA). |
| `openssl rsautl -decrypt -inkey <priv>.key -in <file>_ENCRYPTED.txt -out <file>_DECRYPTED.txt` | Asymmetric decryption (RSA). |

### Linux File Commands

| Command | Purpose |
|---------|---------|
| `touch <file>` | Create an empty file. |
| `echo "<text>" > <file>` | Write text to a file (overwrite). |
| `echo "<text>" >> <file>` | Append text to a file. |
| `cat <file>` | View the contents of a file. |
| `cp <source> <dest>` | Copy a file. |
| `rm <file>` | Delete a file. |
| `ls` | List files in the current directory. |

---

## 📚 Comprehensive Vocabulary

| Term | Definition |
|------|------------|
| **Plaintext** | Human-readable information before encryption. |
| **Ciphertext** | Encrypted, unreadable information. |
| **Symmetric Cryptography** | Same key for encryption and decryption. |
| **Asymmetric Cryptography** | Public and private key pair. |
| **Hybrid Cryptography** | Asymmetric for key exchange, symmetric for data. |
| **Digital Signature** | Encrypted hash of a message using private key. |
| **Hash Function** | One-way function producing fixed-length output. |
| **Non-repudiation** | Sender cannot deny sending a message. |
| **PKI (Public Key Infrastructure)** | Framework for managing digital certificates. |
| **Certificate Authority (CA)** | Trusted entity that issues digital certificates. |
| **GPG (GNU Privacy Guard)** | Open-source implementation of OpenPGP. |
| **Kleopatra** | Certificate manager/GUI for GPG. |
| **Key Pair** | Public key + private key. |
| **Fingerprint** | 40-character hash of a public key. |
| **Passphrase** | Used to encrypt/decrypt private keys. |
| **OpenSSL** | Software library for SSL/TLS and cryptography. |
| **RSA** | Public-key cryptosystem (asymmetric). |
| **AES** | Advanced Encryption Standard (symmetric). |
| **Diffie-Hellman** | Key exchange algorithm for hybrid cryptography. |
| **Salt** | Random value used with password hashing. |
| **PBKDF2** | Password-based key derivation function. |
| **CBC (Cipher Block Chaining)** | Block cipher mode of operation. |
| **Base64** | Encoding scheme for binary data to text. |

---

## 📋 Lab 5 Deliverables Checklist

### Section 1: Hands-On Demonstration

| # | Deliverable | Completed? |
|---|-------------|------------|
| 1 | Fingerprint for your key pair | [ ] |
| 2 | Fingerprint for Alice's key pair | [ ] |
| 3 | Your public key in Alice's certificate cache | [ ] |
| 4 | Alice's public key in your certificate cache | [ ] |
| 5 | Successful signing and encryption message | [ ] |
| 6 | Ciphertext | [ ] |
| 7 | Decrypt/Verify Files window | [ ] |
| 8 | Decrypted `secret-message.txt` in Notepad | [ ] |

### Section 2: Applied Learning

| # | Deliverable | Completed? |
|---|-------------|------------|
| 9 | Instructor's key pair files | [ ] |
| 10 | Ciphertext in `secretmessage_ENCRYPTED.txt` | [ ] |
| 11 | Output of the `ls` command | [ ] |
| 12 | Encrypted contents of `secretkey_ENCRYPTED.txt` | [ ] |
| 13 | Decrypted contents of `secretkey_DECRYPTED.txt` | [ ] |
| 14 | Contents of `secretmessage_DECRYPTED` | [ ] |
| 15 | Password used for symmetric encryption | [ ] |

### Section 3: Challenge & Analysis

| # | Deliverable | Completed? |
|---|-------------|------------|
| 16 | Key fingerprint for generated GPG key pair | [ ] |
| 17 | Contents of `unsignedmessage.txt` | [ ] |
| 18 | Successful signature verification in Kleopatra | [ ] |

---

## 💡 Key Takeaways – Lab 5

### Cryptography Fundamentals
1. **Symmetric encryption** is fast but lacks authentication and requires secure key distribution.
2. **Asymmetric encryption** provides authentication and non-repudiation but is slower.
3. **Hybrid cryptography** combines the best of both: asymmetric for key exchange, symmetric for data.

### GPG / Kleopatra (Windows)
4. **Kleopatra** simplifies the complex process of key management and encryption.
5. **Public keys** are for encryption; **private keys** are for decryption.
6. **Certifying** a public key means you trust the identity of its owner.
7. **Encrypt + Sign** provides confidentiality, integrity, authentication, and non-repudiation.
8. **Fingerprints** are used to verify the integrity of public keys.

### OpenSSL (Linux)
9. **OpenSSL** can generate RSA key pairs with `genrsa` and `rsa`.
10. **Symmetric encryption** is done with `openssl enc -aes-256-cbc`.
11. **Asymmetric encryption** is done with `openssl rsautl -encrypt`.
12. **Salting** and **PBKDF2** make password-based encryption more secure.
13. **Base64 encoding** (`-a`) makes ciphertext readable as text.

### Hybrid Cryptography Process
14. Generate an asymmetric key pair for the recipient.
15. Create a message and encrypt it **symmetrically** with a password.
16. Encrypt the symmetric password **asymmetrically** with the recipient's public key.
17. Send both the encrypted message and the encrypted password.
18. Recipient decrypts the password with their private key.
19. Recipient decrypts the message with the symmetric password.

### Digital Signatures
20. A **digital signature** is a hash of the message encrypted with the sender's private key.
21. The recipient verifies it by decrypting the signature with the sender's public key.
22. Digital signatures provide **integrity**, **authentication**, and **non-repudiation**.

### Security Best Practices
23. Always protect private keys with strong passphrases.
24. Never share private keys.
25. Validate public keys using fingerprints or trusted channels.
26. Use the largest practical key size (8192-bit RSA in lab).
27. Document passwords/passphrases securely for reference.