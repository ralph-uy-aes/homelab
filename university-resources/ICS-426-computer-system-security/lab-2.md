# Lab 2: Gathering Site Information

#### Overview
- In this exercise, you’ll perform simple probes on a website using browser-based OSINT tools. They show what the general public can learn about a website.

#### HackSearch Pro
- This add-on gathers site information using your browser from public resources such as Google, DNS, and WHOIS databases.
- Never probe sites without information
- Within Site Search
    - Performs a Google search for indexed pages within website
    - Includes pages you can't easily navigate to from the site's homepage
- DNS Information
    - Displays a Robtex search showing details about site's DNS entries
    - Shows information about physical location or email servers
- Document Search
    - Finds text and office documents
- Norton
    - Checks malware reputation
- BuiltWith
    - What web technologies the site uses

#### Updating Firefox-ESR Manually
- Download tar.xz file from installation page
- Extract and get firefox file
- `sudo mv firefox /opt`
- Create symbolic link `sudo ln -s /opt/firefox/firefox /usr/local/bin/firefox`
- Launch firefox via terminal `firefox`