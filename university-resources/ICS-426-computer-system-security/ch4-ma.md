# Chapter 4: Cryptography - Module A: Cryptography Concepts

#### About Encryption
- Use of cryptography to protect data confidentiality
- Sender scrambles data with a mathematical formula called an encryption algorithm and a unique key
    - Serves the same purpose as a password
- Intended viewer has the appropriate key to decrypt the message
- Eavesdroppers can't decrypt it
- Ciphers are common encryption methods
    - Takes unencrypted plaintext and turns it into unreadable ciphertext of the same length
    - Can be broken or compromised
- Metrics
    - Work factor: Strength of any cryptographic system, factor needed to break encryption
    - Time factor: How long it would take to crack, more subjective metric

#### Substitution Ciphers
- Replaces each character of a message with a different one
- Caesar Cipher
    - Used by Julius Caesar for military correspondence
    - Rotates each character through the order of the alphabet
- ROT13
    - Modern version that rotates characters halfway or 13 places through the alphabet
- One-time Pad
    - Method where plaintext message is combined with a key composed of a string of random numbers or letters
    - Theoretically unbreakable, but very demanding in requirements
        - Must be as long as plaintext
        - Must be entirely random
        - Must never be reused
        - Must be kept secret from everyone but the sender and the recipient
    - Limited to specialized and high-risk communications

#### Transposition Ciphers
- Leave plaintext characters intact
- Shuffle them around to leave the cipher unreadable
- Rail-fence Cipher
    - Write the plaintext in a zigzag fashion across multiple lines of text, then assemble them into ciphertext order
    - Character frequency can't be used to attack transposition ciphers
    - Naturally break up common patterns and repetitions to some extent

#### Steganography
- Ciphers which are visibly encrypted invite attackers to break them
- Steganography obfuscates secret messages in seemingly innocuous information
    - Casual onlookers won't know it's there
- Hiding things in plain sight
- Rely on the fact that viewers for popular formats often disregard data that doesn't fit in
- Ex.
    - Web pages can hide messages in metadata
    - JPG files can contain MP3 audio data
- Careless steganography can increase file size, rousing suspicion

#### Digital Encryption
- Transport Encryption
    - Protects data in transit
        - Often have the greatest risk of compromise
    - Over the network
    - Universal for secure network protocols
- Storage Encryption
    - Protects data at rest
    - On some persistent storage medium
    - Not as ubiquitous as transport encryption
    - Usually used in secure systems
- Memory Encryption
    - Protects data in use
    - Data in RAM or anything that's being processed
    - Challenging to implement without hurting performance
    - Desirable for organizations with strict security needs
- Cryptographic Obfuscation
    - Protects code of a program to prevent reverse engineering
    - No change to functions
    - Used by malware to hide from scanners

#### Encryption Types
- Symmetric Encryption
    - Uses a single key to encrypt and decrypt data
    - AKA secret-key or private-key cryptography
    - Provides confidentiality only if key is secret
    - Well-suited for bulk encryption of large amounts of stored or transmitted data
- Asymmetric Encryption
    - Uses two mathematically related keys
        - Data can be encrypted with one and decrypted with the other
    - AKA public-key cryptography
    - Can be used to prove authenticity as well as confidentiality
        - Also used for key exchange
    - Much slower than symmetric encryption
- Cryptographic Hashing
    - Converts data into a hash or unique signature
    - Hash can't be turned back into original data
    - Can be compared to the data to verify its integrity and/or authenticity
    - Used for password storage

#### Confusion and Diffusion
- Confusion: Makes mathematical relationship between plaintext and key as complex as possible
- Diffusion: Breaks up patterns in the plaintext, so they won't be apparent in ciphertext

#### Cryptographic Modules
- Instead of an application doing encryption itself, it hands off the work to a separate cryptographic module
- Can use an API 
- Microsoft has CryptoAPI (CAPI) to provide application encryption services
    - A CAPI module is called a Cryptographic Service Provider (CSP)

#### Symmetric Encryption
- Main advantage is being able to encrypt data with a reasonably short key and limited computational complexity
- Best for large amount of encryption for transport or storage
- Main disadvantage is that the key must be kept secret to avoid compromise
- Two categories
    - Stream cipher
        - Operate like a one-time pad
        - Keystream is generated from an encryption key
        - Tend to be high performance
        - Less secure than a one-time pad
    - Block cipher
        - Encrypt plaintext in fixed-size blocks, applying the complete key to each block
        - Key and block sizes don't need to be the same
        - Data must be broken up into algorithm's block size, usually 64 or 128 bits
        - Additional padding must be added to round out size to fill a whole block
        - Has more overhead than a stream cipher, but is easier to keep secure

#### Symmetric Algorithms
- Advanced Encryption Standard (AES)
    - NIST's recommended standard since 2001
    - Features 128-bit blocks and can use 128, 192, or 256-bit keys
    - Fast, has wide hardware and software support
    - No practical attacks since cipher has been published
    - Currently the gold standard of encryption
    - AES-256 is used for Top Secret Communication, but 128 is good enough for most purposes
- Triple DES (3DES or TDES)
    - Block cipher designed in the 1990s based on Data Encryption Standard (DES)
        - Applies three different 56-bit DES keys to the same 64-bit block
    - Total length comes out to 168-bit key, practical work factor is more like 80 bits
    - Now obsolete, retired by NIST at the end of 2023
- Blowfish
    - First strong cipher placed in the public domain
    - Supports variable key sizes up to 448 bits
    - Not as popular as it once was because of its 64-bit block size and internal flaws
    - Twofish is a successor offering 128-bit blocks and comparable security to AES
- Rivest Cipher or Ron's Code
    - Family of ciphers developed by Ron Rivest, identifies as the RC series
    - RC4 is the most widely used stream cipher of the bunch
        - Very quick to encode or decode
    - Mostly been replaced with newer ciphers
- Salsa20
    - Public domain stream cipher developed by Daniel J. Bernstein in 2005
    - Uses a 20-round encryption cycle with a 256-bit key and a 64-bit nonce
    - Reasonable secure and high-performance even in software
    - Popular lightweight stream cipher

#### Modes of Operation
- Electronic Code Book Mode (ECB): Applies key similarly to each block, semantically insecure, little security for long messages
- Semantically secure modes modify how the key is applied using various combinations of IV and previous ciphertext: Cipher Block Chaining Mode (CBC), Cipher FeedBack Mode (CFB), Output FeedBack Mode (OFB), Counter Mode (CTR)
- Authenticated modes include hash-based authentication code to provide data authenticity and integrity protection: Galois Counter Mode (GCM), Offset CodeBook Mode (OCB)

#### Key Life Cycles
- Even if the key and algorithm are both strong, it's not good to keep encrypting with the same key forever
    - Just like passwords, keys must be changed periodically
- Strong cryptography uses temporary keys 
    - Symmetric cryptography is also called session key cryptography
    - Asymmetric cryptography has ephemeral keys that are only used for a short term
- Key exchange
    - In-band key exchange
        - Exchanged over primary communications channel
        - If channel isn't encrypted yet how do you keep the key secret?
        - Very difficult to make secure in-band exchanges
    - Out-of-band key exchange
        - Key is exchanged over a secondary, more secure channel
        - You could communicate a password to someone verbally or send a smart card via mail or courier
        - Exchange is only as secure as secondary channel

#### Asymmetric Encryption
- Starts with a single large random number, uses specialized mathematical equations to turn it into two separate, but related keys
    - Anything encrypted with one key can only be decrypted with the other
    - One key is private, the other is public
- Asymmetric encryption needs much longer keys for the same effective strength
    - Also much slower and not used for long messages
- A 1024-bit key has about the same work factor as an 80-bit symmetric AES key
    - 2048 bits is equivalent to 112-bit AES and 3072 bits is equivalent to 128-bit AES

#### Asymmetric Algorithms
- Rivest-Shamir-Adleman (RSA)
    - Uses a one-way problem called integer factorization
    - Private key is made from two large prime numbers and an additional value
    - Public key can be calculated from the private key, but not vice-versa
    - RSA keys can be up to 4096 bits, but much weaker than a symmetric key of the same size
    - Very computationally expensive, but popular for key exchange and digital signatures
    - RSA is the default for SSL and TLS certificates used by secure websites
- Digital Signature Algorithm (DSA)
    - Created by former NSA employee in 1991, soon adopted as an NIST standard
    - Uses different on-way problem called a discrete logarithm
    - Similar in strength and length to RSA, but different in performance
    - DSA requires 1024-bit keys which are no longer secure
- Elliptic Curve Cryptography (ECC)
    - Uses algorithms based on the difficulty of calculating specific properties of elliptical curves
    - Underlying math is difficult to explain but offers strong security with much shorter keys than other asymmetric algorithm
    - 256-bit ECC key is as strong as a 3072-bit RSA key, even if it's still only as strong as a 128-bit AES key
    - Much faster than RSA and DSA
- Elliptic Curve Digital Signature Algorithm (ECDSA)
    - ECC-based variant of DSA
    - Provides security level equivalent to about half of the ECC key size
    - 256-bit key provides a 128-bit work factor
    - Provides comparable security to RSA with shorter keys and higher performance
- Diffie-Hellman (DH)
    - Created by and named for Whitfield Diffie and Martin Hellman in 1976
    - DH key exchange was the first openly published public-key cryptography system
    - Used primarily for key exchanges rather than encrypting data
    - Can be based on a static key or an ephemeral key
    - DH implementations can be based on various underlying mathematical problems

#### Cryptographic Hashing
- Uses a one-way function to turn data into another form
- No matter how long the original data string is, the resulting hash is always the same size
- There are no keys, has isn't intended to be returned to its original form, doesn't reveal plaintext
- Simplest hash values are single-digit values called check digits
    - Imagine adding each digit of a long number together, then each digit of that number and so on until one digit remains
    - Longer hash value is often called a checksum or message digest
- Check digits also demonstrate another feature of hashes
    - If the input is longer than the hash, it's possible to have hash collisions where multiple different inputs produce the same hash
- Hash collisions can show the same hash for a legitimate file and a Trojan horse
    - If the Cyclic Redundancy Check (CRC) shows that the hashes are the same, you can download a Trojan horse

#### Hash Applications
- Data Integrity
    - You can verify the integrity of any data transmission by comparing a hash made by the sender to one made by the recipient
    - You can hash files when you store them
    - Verify that the data hasn't been altered by making a new hash for comparison
    - Unless the hash itself is stored or transmitted securely, attackers could alter a file and replace its hash
- Data Identification
    - If you need to identify a file or other data element uniquely, you can create hashes for each file and store them in a database or hash table
    - Hash tables are valuable for searching and organizing large amounts of data
    - Used for source code management systems, file-sharing networks, and image databases
    - Allows you to use hashes to identify users or systems
    - Hash based on a list of a computer's hardware, software, and unique information can uniquely identify it
- Key Generation
    - You can securely generate a new key by hashing an existing key, arbitrary data, or some combination of the two
    - Hashing is valuable for creating cryptography keys from passwords
    - Passwords are shorter and less random than modern keys
        - Use key-stretching algorithms to make brute force more difficult
- Password Storage
    - Plaintext password database is a security risk since an attacker who accesses the system can easily steal all user passwords at once
    - Password databases only store the hash, not the password itself

#### Salt and Pepper
- Rainbow tables can attack many hashes simultaneously
- Stored passwords are hashed along with a salt value to prevent such problems
    - Much like an IV, salts are unique to each password, not secret and typically stored in plaintext with the hash
    - Each stored password would need to be attacked by a unique rainbow table
    - Logging in is easy, just combine the password with the salt
- Salted hashes still isn't good enough for security professionals, so they suggest using a pepper value
    - Peppers are secret values that must be stored separately from the password database
    - The same pepper is used for all passwords on a system
        - Must be different for different systems
- Salting protects from rainbow tables
- Peppering protects individual hashes from being cracked by adding additional secrets

#### Hash-based Authentication
- Hash only protects message integrity and against accidental modification
- Combining hashes and other crypto tools achieves complete security
- Confidentiality is pretty obvious, you can encrypt the hash, the data, or both
- Process with Hash only
    1. A sends message and appends its hash
    2. B hashes the message and verifies it against what A sent
    3. If the same hash is generated from A and B, no interception occurred
    4. Otherwise, it was intercepted or modified
- Process with Keyed-Hash Message Authentication Code (HMAC)
    1. A and B have a shared secret key
    2. A combines it with the hashing process to create an HMAC
    3. A sends it as the hash to accompany the message
    4. Even if it is intercepted, the interceptor cannot create a new valid HMAC without knowing the secret key
    - Does not protect B's business interest A can claim that B wrote the message and generated the HMAC himself
    - Sometimes called MAC or Message Integrity Code (MIC)
- Process with Digital Signature
    1. A creates a hash of the data
    2. A encrypts hash of data with her private key
    3. A sends the encrypted hash with the plaintext message
    4. Anyone can read the message and use A's public key to decrypt the hash, but no one can duplicate the signature without A's private key
    5. B can prove that A sent the message
    - Follows non-repudiation, authenticity, and integrity

#### Hash Algorithms
- Message Digest 5 (MD5)
    - Successor to MD4
    - Produces 128-bit value, usually written as a 32-digit hexadecimal number
    - Widely used for a long time, but too short to be strong today
    - Not very collision resistant
    - Considered obsolete, but still used in local password storage
- Secure Hash Algorithm 1 (SHA-1)
    - Produces a 160-bit value and is written as 40 hexadecimal digits
    - Corrects the weaknesses of SHA-0
    - Has cryptographic flaws and can no longer be considered secure
- SHA-2
    - Successor of SHA-1, has significant mathematical differences to make it more secure
    - Includes six different functions, producing hashes between 224 and 512 bits
    - SHA-256 and SHA-512 are most popular for modern applications
- SHA-3
    - Based on the Keccak algorithm and produces hashes between 224 to 512 bits
    - Isn't intended to replace SHA-2, chosen as a similarly strong, but mathematically different backup option in case SHA-2 is compromised
    - A little stronger, but worse performance
- RACE Integrity Primitives Evaluation Message Digest (RIPEMD)
    - Developed by Computer Security and Industrial Cryptography research group (CSIC) in Belgium
    - Based on MD4, but with security improvements and additional functions
    - Produces hashes between 128 to 320 bits
- Poly1305
    - MAC standard designed by Daniel Bernstein
    - Produces 128-bit hash based on a 256-bit encryption key input
    - Originally designed for use with AES, but ChaCha20-Poly1305 has become a popular alternative to RC4

#### Password Storage Algorithms
- NT LAN Manager (NTLM)
    - Developed for storing password hashes in Windows NT 4.0
    - Designed both for network logon and for storing local user passwords
    - NTLMv1 is based on the older and very insecure LAN Manager hash
    - NTLMv2 improved logon process by adding HMAC-MD5 hashes
    - Modern Windows uses Kerberos-based network logon, but NTLMv2 is still supported
    - Local passwords are stored insecurely using MD4 hashes
- bcrypt
    - Specialized hash based on the Blowfish key setup process
    - Designed for password storage, but also useful for key derivation and stretching
    - Combines passwords with a 128-bit sale to create a 184-bit hash
    - Considered an old-well proven technology
- Password-Based Key Derivation Function 2 (PBKDF2)
    - Alternative to bcrypt designed by RSA and published as an IETF standard
    - Easily customized, supporting several underlying hashes, ciphers, and HMACs to produce keys and salted hashes of different lengths
    - PBKDF2 isn't considered as strong as bcrypt

#### Choosing Cryptographic Technologies
- Encryption: Primarily protects confidentiality
- Hashes: Protect integrity
- Multiple Forms: Provide authentication
- Digital Signatures: Support authentication and non-repudiation
- Steganography: Discourages attacks by making encrypted data seem innocuous

#### Identifying Cryptographic Limitations
- Insufficient key length or short hashes render any encryption scheme vulnerable to brute force cracking
- Encryption requires unpredictable secret keys for security
- Keys are only one entropy source in many cryptographic schemes
- Keys should be rotated periodically in case of compromise
- Generating ephemeral session keys from long-term static keys can make risky key exchanges less frequent
- Think of how advancing technologies may compromise your data