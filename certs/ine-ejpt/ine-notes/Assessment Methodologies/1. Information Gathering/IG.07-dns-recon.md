# IG.07 - DNS Recon

### DNS Recon
- Python script that provides ability to perform
    - Check all NS Records for Zone Transfers
    - Enumerate General DNS Records for a Given Domain (MX, SOA, NS, A, AAAA, SPF, TXT)
    - Perform common SRV Record Enumeration
    - TLD Expansion
- Prepackaged with Kali Linux
- Syntax: `dnsrecon -d <domain_name>`
- Gives you a bunch of DNS records of various types

### DNS Dumpster
- Performs DNS reconnaissance and research
- Very similar to DNS Recon, but has better information organization
    - Gives IP Block owners, GeoIP map
- Web-based
- Basically, DNS Recon on steroids
- It can even run Nmap port scans
- Can even give you a domain mapping and connections of DNS records

### Recall: DNS Record Types & Their Importance
- **A (Address Record)**  
  - Maps a domain name to an **IPv4 address** (e.g., `192.168.1.10`).  
  - **Importance**: The core record for routing web traffic; reveals the target's public-facing server IPs, which are prime candidates for port scanning and vulnerability assessment.

- **AAAA (IPv6 Address Record)**  
  - Maps a domain to an **IPv6 address** (e.g., `2001:db8::1`).  
  - **Importance**: Often misconfigured or overlooked during security audits—finding IPv6 endpoints can expose unmonitored attack surfaces that bypass traditional IPv4 firewall rules.

- **MX (Mail Exchange Record)**  
  - Specifies the mail servers responsible for handling email for the domain, along with priority values.  
  - **Importance**: Identifies internal email infrastructure; valuable for social engineering, phishing campaign targeting, and checking for misconfigurations (e.g., open relays or missing SPF/DKIM).

- **NS (Name Server Record)**  
  - Lists the authoritative DNS servers for the domain.  
  - **Importance**: Primary targets for zone transfer attempts (`dnsrecon -t axfr`). Also highlights the DNS hosting provider, which can be probed for known vulnerabilities.

- **SOA (Start of Authority Record)**  
  - Provides administrative metadata about the zone: primary NS, responsible email address, serial number, refresh/retry/expiry timers.  
  - **Importance**: The serial number reveals if/when the zone was updated; the email (obfuscated with a dot) can uncover administrative contacts. Timers hint at DNS caching behavior, useful for cache-poisoning or DoS timing attacks.

- **SPF (Sender Policy Framework Record)**  
  - A TXT-based record that defines which IPs/servers are authorized to send emails from the domain.  
  - **Importance**: Weak or permissive SPF records (`+all`, `~all` misconfigurations) allow attackers to spoof emails and bypass spam filters; essential for email spoofing/reputation assessments.

- **TXT (Text Record)**  
  - A flexible free-text field; commonly holds SPF, DKIM, DMARC, and verification tokens for third-party services (e.g., Google, Microsoft).  
  - **Importance**: Decodes the entire email security posture (DKIM selectors, DMARC policies) and can leak internal service ownership (e.g., `_atproto`, `_github-challenge`), revealing hidden SaaS platforms linked to the organization.

- **SRV (Service Locator Record)**  
  - Defines specific servers and ports for particular services (e.g., `_ldap._tcp`, `_kerberos._udp`, `_sip._tls`).  
  - **Importance**: Standard enumeration (`dnsrecon -t srv`) exposes internal application protocols like LDAP, Kerberos, SIP, or XMPP—often revealing legacy or internal-only services that are poorly secured and ripe for lateral movement.

- **CNAME (Canonical Name Record)**  
  - Aliases one domain name to another (e.g., `www.example.com` → `example.com`).  
  - **Importance**: Maps the attack surface to underlying canonical hosts; can be used to discover cloud assets (AWS S3 buckets, Azure endpoints) or CDN providers, often leading to subdomain takeover if the alias points to a deprovisioned resource.