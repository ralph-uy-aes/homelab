# IG.14 - Host Discovery with Nmap

### IP Address
- To find out which subnet you are in, use `ip a s`
- This pulls up your `eth0` interface which contains your IP address and the CIDR for it, which also gives you the IP range of your network
    - Ex. `192.168.2.190/24`, /24 means thats how much IPs you can potentially scan

### Nmap
- Network Mapper
- Tool for network exploration and auditing

### Host Discovery
- `sudo nmap -sn IP/Range`
- Ex. `sudo nmap -sn 192.168.2.0/24`
    - Shows hosts that are within this subnet
    - Scans 256 IPs, shows only available or up hosts
- `netdiscover`
    - Sends ARP requests to IPs and finds hosts
    - `Ex. sudo netdiscover -i Interface -r IP/Range`
    - Same thing as what nmap gives you, but nicer interface

