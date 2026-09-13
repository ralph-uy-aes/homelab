# IG.13 - DNS Zone Transfers

### DNS
- Protocol used to resolve domain names/hostnames to IP addresses
- Just a quality of life protocol, makes it easier to remember which IP to go to
- DNS Servers (nameserver) are like telephone directories that map domain names to IPs
- DNS servers have been set up by companies like Cloudflare and Google
    - DNS servers contain the records of almost all domains on the internet

### DNS Records
- A - Hostname to IPv4 address 
- AAAA - Hostname to IPv6 address
- NS - Domain's nameserver
- MX - Domain's mailserver
- CNAME - Domain aliases
- TXT - Text record
- HINFO - Host Information
- SOA - Domain Authority
- SRV - Service Records
- PTR - IP address to hostname


### DNS Interrogation
- Process of enumerating DNS records for a specific domain
- Probes a DNS server to find DNS records for a specific domain, not just the domain itself
- Can give IP address of domain, subdomains, mail server addresses, etc.

### DNS Zone Transfer
- DNS server admins might want to copy or transfer zone files from one DNS server to another
    - This is a zone transfer
- If misconfigured or unsecured, zone transfers can be abused
    - Attackers can copy zone file from primary DNS server to another DNS server
- Can provide penetration testers with a holistic view of an organization's network
    - Internal network addresses can also be found on an organization's DNS server

### DNSdumpster
- Free tool that can find hosts related to a domain
- Simply type in a hostname and FEEL THE MAGIC!!!
    - Gives you as much DNS records as it can find

### dnsrecon
- Similar to DNSdumpster
- CAUTION: this is an active recon tool
- Syntax: `dnsrecon -d hostname`
- Could give you more records than DNSdumpster

### /etc/hosts
- This is the hosts file
- Basically it's your own little DNS table
- Put in an IP and a hostname pair and you can use it just like that

### dig
- DNS Lookup tool, gives you some DNS records

### fierce
- Precursor to nmap, unicornscan, nessus, nikto
- Scanner that helps locate non-contiguous IP space and hostnames against specific domains
- CAUTION: can be active recon
- Syntax: `fierece -dns hostname`