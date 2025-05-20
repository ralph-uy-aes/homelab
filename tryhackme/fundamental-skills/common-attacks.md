# Common Attacks

#### Social Engineering
- "People Hacking"
    - The target is not a computer, rather people of interest!
    - Instead of brute-forcing a password, just ask for it
- This type of attack snowballs which means it gets worse and worse the more information is gathered by the attacker
- This attack also takes advantage of OSINT and reconnaissance
    - Relies heavily on publicly available information initially
    - Uses public information to escalate into emails, accounts, phone numbers
    - May get as far as identity theft or worse
- Besides impersonation, hackers could use physical devices like USB drops, malicious charging cables, keylogger powerbanks, Raspberry Pi, etc...
- Stuxnet
    - Computer virus used to target Iran nuclear program in 2009
    - Self-replicating across networks and even the internet
    - Escaped labs and became widespread causing new variants to exist
    - How did it infiltrate Iranian computers?
        - USB drops were planted in places where Iranian nuclear program employees frequented
        - Bet on them plugging the USBs into sensitive computers
        - Worked and destroyed the entire program and nuclear centrifuges
- Attack Stats
    - Escalating
    - Multi-layered
    - Works offline
    - Psychological
    - Unpredictable and highly versatile
- Delivery Methods
    - Face-to-face
    - Mail
    - Text
    - Calls
    - Physical devices
- Safety Protocols
    - Multi-factor Authentication
    - Avoid plugging in unknown or suspicious external media devices
    - Insist on a proof of identity whenever a stranger calls you claiming to know you

#### Social Engineering: Phishing
- A subsection of social engineering, phishing is an extremely common attack vectors currently
- This attack has evolved to new variants: "smishing" for SMS and "vishing" for video chat
- Three Primary Types
1. General Phishing
    - No one is targeted in particular, instead targets large groups (users of an app, citizens of a state or city)
    - Large-scale campaigns and are generally easy to spot
    - Unsophisticated mimicry
2. Spearphishing
    - More targeted towards individuals or smaller groups (employees within a company, school faculty)
    - Mid-scale campaigns and are harder to spot
    - More sophisticated methods and generally better crafted
3. Whaling
    - Precise targeting, usually high-value individuals (company executives, principals, oligarchs)
    - Small-scale campaigns, thereby being near invisible
    - Extremely sophisticated and tailored to be indiscernible from legitimacy
- Large Amazon Purchase
    - You receive an email from Amazon claiming that you bought a $4,000 70-inch QLED Crystal TV
    - They send you a website with you purchase history clearly showing that you did buy that TV, but it wants your credentials, so you sign in
    - You're redirected back to the real Amazon site like nothing ever happened
- Attack Stats
    - Extremely common
    - Mimicry
    - Versatile
    - Email-based
    - Massive scale (AOE)
- Delivery Methods
    - Emails
    - SMS
    - Video calls
- Safety Protocols
    - Thoroughly examine suspicious emails to check for grammar or spelling mistakes, account or domain name discrepancies
    - Avoid clicking on suspicious links or interacting with suspicious emails
    - Don't download or open PDFs from untrusted sources
    - Compare email domains as most companies would have their own domains, whereas phishing domains are generic like gmail
    - If you do happen to land on a site that asks you for your credentials, don't input them unless it is legit
    - Do not assume that you're immune

#### Malware and Ransomware
- Malware continues to be a problem despite many antivirus solutions
- Any software that is designed to perform malicious actions is considered malware
- Malware can have different purposes such as stealing information, destruction, takeover, etc...
    - Command and Control or C2 tasks are often performed by malware which allows attackers to take control over infected systems remotely, often incorporating key-logging
- Wannacry was a ransomware attack on a lot of devices
    - Requested payment in BTC
    - Caused up to $4-billion in damages
    - Authors may have generated $5-million + in ransom profits
- Ransomware is a subcategory of malware where it is specifically designed to lock data and/or take it hostage via encryption
    - Requires victims to pay attackers within some timeframe
    - Extremely fast-spreading 
    - Encrypts as much data as possible on as many machines as possible
    - The attacker might not even give your data back!
- Attack Stats
    - Adaptive (Arms Race)
    - Highly Contagious
    - C2
    - Engineered Software
    - Highly Destructive
    - Blitzkrieg
- Delivery Methods
    - Software (Installers, .exe, PDFs, .psl, .bat, .hta, .js)
    - All social engineering methods
    - Physical devices
    - Macros
- Safety Protocols
    - Always update and patch your software
    - Never click on suspicious links
    - Don't open file attachments
    - Don't download or run suspicious software
    - Never plug suspicious devices in sensitive computers
    - Always back up important data
    - Ensure antivirus software is up-to-date and activated
    - If you are infected, don't pay, contact authorities and contain the infection by disabling router or connections (prevent contagion). Do not power off the infected device, could destroy opportunities for decryption

#### Passwords and Authentication
- The first general safety protocol is writing secure passwords
- Passwords are an integral part in authentication, imagine a world without passwords
    - Unfortunately, secure passwords are harder to write than insecure passwords
    - People are also too carefree in safekeeping their passwords (writing them on post-its)
- Secure Passwords
    - Hard to crack, easy to remember
    - Use more than 8 characters
    - Use a combination of letters and numbers
    - Use unusual symbols like `#` or `&`
    - Use date ranges like `2005-2100` instead of simply `2005`
    - Still vulnerable to social engineering or in-depth reconnaissance
- Best general practice right now is to just use passphrases like `I love it when it rains cats and dogs!` instead of simply `catdoglover!2005` because length is currently stronger than sheer complexity
    - But, if you're extra paranoid, use both length and complexity: `1230i9iFj(@)EQI(**@(#)#)!@#&%%&$*#uiw)@)(E)!(@#`
    - Will literally take millions of years to crack and also millions of years to input correctly
- Weak Passwords
    - Easy to crack and guess, easy to type and remember
    - Uses the typical form: `<string> <number> <symbol>`
    - Shorter in length
    - Doesn't use alphanumeric combinations or symbols
- Exposed Passwords
    - Don't reuse passwords because if one website is breached, hackers can easily reuse that for other websites by credential stuffing (brute-forcing credentials onto other websites)
    - Different sites store passwords differently, often having different levels of security
        - Some store them as plaintext (very bad)
        - Some store them encrypted (good until attacker gets that key)
        - The industry standard is password hashing which uses math algorithms to ensure that reversal is impossible
            - Whenever you input your password, it gets rehashed and then compared again to the stored hash
            - Longer passwords = longer hash = longer algorithm time
    - Exposed passwords are also often found in the dark web
    - Use [HaveIBeenPwned](https://haveibeenpwned.com) to check if you're exposed
        - Or if you're the one doing the pwning, use BreachForums (tor site)
- Password Attacks
    - Local attacks require a stolen copy of credentials (usernames/ emails and hashed passwords) and then use software to hash unhashed passwords hoping to get an equivalent hashed password
        - Can use randomly generated sequences of characters
        - Or dictionaries and word lists
    - Remote attacks involve the original server
        - Either brute-force known usernames by sending requests to a server
        - Or use already exposed usernames and passwords to do some credential stuffing

#### Multi-Factor Authentication and Password Managers
- Another safety protocol is using MFA and password managers
- MFAs require another authentication method besides your password
    - Can be anything from a six-digit code, confirmation, fingerprint, etc...
    - TOTP or Time-base on time password is an example of MFA where secondary authentication is timed and changes over some frequency
    - Yubikey is a physical device that is another form of MFA
    - Ideally, a trifecta method is used where a password, smart card, and fingerprint are required for authentication
    - Realistically, these methods can end up costing a lot and be a tedious experience for most users
- The most common MFA currently is text-based or SMS-TOTP but this isn't the most secure and has seen hackers rerouting OTP
- The better MFA are app-based like the Steam Authenticator App
- Password Managers bypass the need for you to remember and type down all your long passwords
    - It's like having a multi-tool with all your passwords instead of having to carry a toolbox around
    - The passwords are stored in vaults either locally or online through the provider's server
    - You pull up your passwords by using biometrics like fingerprint or facial recognition
    - Some password managers:
    1. [1Password](https://1password.com) ($2.99/mo)
    2. [LastPass](https://www.lastpass.com) ($3/mo)
    3. [KeePass](https://keepass.info) (free!)
    4. [Bitwarden](https://bitwarden.com/) (freemium!)

#### Public Network Safety
- Public networks are great, but are extremely unsecure
    - MitM or Man in the Middle attacks can be easily set up and attackers can monitor network traffic
    - Fortunately, modern websites use the TLS or Transport Layer Security protocol to encrypt traffic between users and servers
    - Anyone else on that public network can see that you're also connected
- Solution? Don't connect to untrusted networks
    - Just use a private network or cellular data
    - If you really need to connect, use a VPN or Virtual Private Network
        - VPNs encrypt all traffic leaving and re-entering your machine, rendering all interception useless
        - VPN self-hosting is free, but many people use paid services
- Website Connection Security
    - The standards that are upheld by online services to ensure your security
    - Most websites make use of HTTPS or Hyper Text Transfer Protocol Secure whose underlying encryption is via TLS or Transport Layer Security
    - If you look at the left of your website's address in your search engine, there should be a padlock if it is secured by TLS
        - Do note, a malicious website can still be TLS secured
    - Do not enter credentials in an unsecured website

#### Backups
- Backups are the single most important defensive measure to protect data
    - Attacks are nullified for non-sensitive data as ransomware turns from annihilation to minor inconvenience
- The Golden 3, 2, 1 Rule
    - You should always keep 3 up-to-date copies of your data
    - Backups should be stored in two different storage mediums
    - One or more backups should be off-site (away from home or work)

#### Software Updates
- Updates are essential to the DevOps cycle and often contain security patches that eliminate prior vulnerabilities
- Eternal Blue was discovered by the NSA and was leaked on April 2017
    - This vulnerability affected Windows OS and gives attackers complete control over Windows systems
    - Microsoft released a patch called MS17-010 which should've removed the vulnerable component, but a lot of administrators refused to download it
    - This was the very cause of the Wannacry ransomware and since admins didn't want to update, everything that was vulnerable to Eternal Blue was infected
- At some point, software is deprecated and reaches EOL or End Of Life, at this point, replace it or segregate it to prevent exploitation
- Antivirus updates are pretty frequent because they keep known exploit signatures
    - When new malware is discovered, antivirus vendors generate signatures to identify the malware
    - Updated antivirus catch these signatures and prevent malware

#### Summary
- I learned a ton from this room. Everything from common attack vectors to safety protocols was discussed. I had background knowledge on all of these topics, but I got a more in-depth look at things like TLS, password security, how VPNs work, Backup rules, antivirus signatures, malware, etc... I also learned about real cases of these attacks and also examples of real products like password managers and VPNs.
