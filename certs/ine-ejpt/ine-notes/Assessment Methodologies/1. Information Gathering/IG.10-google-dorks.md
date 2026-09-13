# IG.10 - Google Dorks

### Google Dorks
- AKA Google Hacking
- Using Google Search filters to find what we're looking for

### Site Operator
- `site:domain`
- Shows you sites specific to a domain and its subdomains
- Ex.
    - `site:ine.com`
        - Shows sites from ine.com and subdomains of ine.com
    - `site:*.ine.com`
        - Only show subdomains, not "ine.com" itself

### Inurl Operator
- `inurl:keyword`
- As name implies, it finds keywords inside of a url
- Ex.
    - `inurl:admin`
        - Shows sites where urls have the word admin 
    - `inurl:auth_user_file.txt`
        - Shows potential login portals with exposed passwords
    - `inurl:passwd.txt`
        - Unintentionally leaked passwords and usernames

### Intitle Operator
- `intitle:keyword`
- As name implies, it finds titles with the keyword
- Ex.
    - `intitle:admin`
        - Shows sites where the title has the word admin
    - `intitle:index of`
        - Shows sites with directory listing enabled
        - Vulnerable since anyone can see directory
        - VERY IMPORTANT

### Filetype Operator
- `filetype:extension`
- Shows sites where the extension is available
- Ex.
    - `filetype:pdf`
        - Shows PDFs associated with other keywords in the search

### Cache Operator
- `cache:site`
- Shows older versions or cached versions of websites
- Sort of similar to the WayBackMachine
    - WayBackMachine is still better for snapshots and overall history
- Ex.
    - `cache:ine.com`
    - Shows Google web cache or older version for `ine.com`

### Exploit Database
- Has some preset dorks for plug and play use
- Found under Google Hacking Database