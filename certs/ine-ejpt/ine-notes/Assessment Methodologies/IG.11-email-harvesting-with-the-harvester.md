# IG.11 - Email Harvesting with theHarvester

### theHarvester
- Can be used to gather IP addresses, subdomains, email addresses, etc...
- Simple to use, open-source tool
- Still a passive recon tool as it only performs OSINT
- Various Sources
    - Various search engines
    - Search engine dorks
    - Public data repositories
    - Shodan
- Important to note, `theharvester` was the old command, but the new command is `theHarvester`
    - Yes, we're that petty now

### Flags
- `-h` - Help
- `-d` - Domain or company name to search
- `-l` - Limit search results
- `-s` - Shodan to query discovered hosts
    - CAUTION: This sort of takes you into active info gathering, not passive
- `-v` - Virtual hosts lookup
- `-b SOURCE` - Define sources you want the harvester to query, bunch of different sources

### Example
- `theHarvester -d INE -b duckduckgo,baidu,bing,yahoo`
    - Basically look for things under the name "INE" from duckduckgo, baidu, bing, and yahoo
- `theHarvester -d ine.com -b duckduckgo,baidu,bing,yahoo`
    - Basically look for things under the from INE.com on duckduckgo, baidu, bin, and yahoo
    - Yielded more now that we narrowed it down more
    - Got Autonomous system numbers, IPs, subdomains, etc...