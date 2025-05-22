# DNS in Detail

#### Domain Name System or DNS
- A simple way for us to communicate with devices on the internet without having to remember complex or long numbers
- Every house has a unique address and so does every computer on the internet
    - Except, computers have IPs which are a set of four octets each ranging 0-255, separated by periods
- Imagine having to type out the IP of google whenever you want to search for something as opposed to simply typing out "google.com"
    - DNS helps with this

#### Domain Hierarchy
1. Top Level Domain or TLD
    - The most right-hand part of a domain name, think ".com" or ".org"
    - There are two types:
    1. Generic TLD or gTLD - historically used to indicate the purpose of the domain, like .edu or .org or .gov, but now has evolved to more fun names like .online, .club, .party
    2. Country Code TLD or ccTLD - used for geographical purposes like .co.uk, .us, .ph
2. Second Level Domain
    - The actual name that is often registered, limited to 63 characters plus the TLD and can only include a-z, 0-9, and hyphens
3. Subdomain
    - The left-hand side of the second level domain, think admin.google.com
    - Has the same restrictions as the second level domain
    - Multiple subdomains split with periods can be used to create longer names, but must be less than 254 characters

#### Record Types
1. A Record - Records resolve to an IPv4 address
2. AAAA Record - Records resolve to an IPv6 address
3. CNAME Record - Records resolve to another domain name, for example store.tryhackme.com returns a CNAME record shops.shopify.com and another DNS request is sent to work out shops.shopfiy.com's IP address
4. MX Record - Records resolve to the address of the servers that handle the email for the queried domain, for example tryhackme.com would have an MX record response like alt1.aspmx.l.google.com. Also has a priority flag for whenever other backup servers should be communicated with.
5. TXT Record - Free text fields where any text-based data can be stored. Can have multiple uses, but commonly to list servers that can send an email on behalf of the domain or verify ownership of the domain name

#### Making A Request
- Process outline for whenever a request is made
1. Local client first checks its local cache to see if its address has been looked up recently. If not, create a request to your recursive DNS server will be made
2. Recursive DNS servers are usually provided by your ISP, but can also be chosen by yourself. This has a local cache of recently looked up domain names. If a result is found locally, it is sent back to your computer and your request ends there, more common for frequently visited sites like google or facebook. If it cannot be found locally, the hunt begins starting with the internet's root DNS servers
3. Root servers are basically the DNS backbone of the internet. They redirect you to the correct TLD server that deals with the corresponding TLD of the requested domain
4. TLD servers hold the records for where to find authoritative servers that answer the DNS request. Authoritative servers are often known as the nameserver for the domain, for example for tryhackme.com, it is kip.ns.cloudflare.com and uma.ns.cloudflare.com. Many nameservers exist for a domain name to act as a backup in case on goes down
5. Authoritative DNS servers are responsible for storing DNS records for a particular domain name as well as updates to DNS records. The DNS record is sent back to the recursive DNS server where a local copy is cached for future requests and is relayed back to the original client who requested for it. DNS records come with Time To Live or TTL values that represents how long in seconds the records are cached for.

#### Practical
- You can use `nslookup` to send DNS requests
- Syntax: `nslookup --type=<Type> <Domain Name>`
    - `--type` - can be anything from A, CNAME, MX, or TXT
    - `<Domain Name>` - can be whatever domain name you need, can be additionally prepended with a subdomain like "shop."

#### Summary
- Overall, DNS is a very simple concept, but it was good to know the specifics of it. I learned the process of a DNS request, hierarchies associated with domain names, types of servers that all contribute in DNS request fulfillment, and types of records that could be requested. Additionally, I did a practical simulation of DNS requests that used various record types.