# IG.05 - Whois Enumeration

### Practical Demo
- Whois
    - An internet protocol (query and response)
    - Used for querying databases that store registered users or assignees of an internet resource
    - Involves domain names, IP address block, or autonomous systems
- CLI Utility
    - `whois` is prepackaged in Kali
    - Syntax: `whois hostname`
    - Let's try with `hackersploit.org`
        - `whois hackersploit.org`
            - We are instantly provided with a lot of information
            - Domain Name, WHOIS Server, Renewal date, Creation date, Expiration date
            - Also has abuse contacts
            - The important piece is the Name Server
            - If DNSSEC is enabled, personal information of the owner of the domain is usually redacted
    - For example,
        - `whois zonetransfer.me`
            - We saw the registrant's organization, state and province, and country
            - Gives us information of the owner of the website
- You can also use `who.is` which is web-based, it might be less accurate for some fields