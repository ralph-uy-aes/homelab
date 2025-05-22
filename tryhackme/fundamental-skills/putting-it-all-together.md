# Putting It All Together

#### Other Components
- Load Balancers
    - When a website's traffic gets busier and busier, or applications need high availability, load balancers are used
    - Load balancers provide two main features
    1. Ensure high traffic websites can handle the load
    2. Provide a failover if a server becomes unresponsive
    - When a website with a load balancer is requested, the load balancer receives the request first and then forwards it to one of many servers
        - Uses different algorithms to decide which server is best to handle the request (round-robin or weighted for example)
    - Also perform periodic health checks to ensure every server is running correctly
        - If it doesn't respond appropriately or at all, it stops sending the server traffic until it responds appropriately again
- Content Delivery Networks or CDNs
    - An excellent resource for cutting down traffic to a busy website
    - Allows you to host static files from your website like JS, CSS, Images, or Videos and host them across thousands of servers all around the world
    - When a user requests one of these files, CDN works out the nearest server from you and sends the request there instead of potentially from the other side of the world
- Databases
    - A way for websites to store information for users
    - Web servers communicate with databases ot store and recall data from them
    - Can range from a simple plain text file to complex clusters of multiple servers providing speed and resilience
    - MySQL, MSSQL, MongoDB, PostgreSQL, etc...
- Web Application Firewall or WAF
    - Sits between web request and web server to protect web servers from hacking or DDoS attacks
    - Analyzes web requests for common attack techniques, whether the request is from a real browser and not a bot
    - Checks if an excessive amount of requests are being sent using rate limiting
        - Only allows a certain amount of requests from an IP per second
    - If deemed to be potentially malicious, the request is dropped

#### How Web Servers Work
- A Web server is software that listens for incoming connections and utilizes HTTP to deliver web content to its clients
- Common web servers are Apache, Nginx, ISS, and NodeJS
- Delivers files from a root directory stored locally which varies between servers
    - For Apache and Nginx, it is in `/var/www/html/`
    - All resources are inside `/html/`
- Virtual Hosts
    - Web servers can host multiple websites with different domain names using virtual hosts
    - Web server checks the hostname requested from the HTTP headers and matches that against virtual hosts
        - If no match is found, default website is provided
    - Root directories of virtual hosts can be mapped into different locations on the hard drive like `/var/www/one/` and `/var/www/two/`
    - Limitless in number
- Static and Dynamic Content
    - Static content is content that never changes like pictures, JS, CSS, etc...
    - Dynamic content is content that could change given different requests like vlogs, youtube recommendations, search results, etc..
    - The backend usually handles the dynamic content changes, while the frontend handles the static content
- Scripting and Backend Languages
    - These allow for the user to interact with the website
    - PHP, Python, Ruby, NodeJS, Perl, etc...
    - Can interact with databases, call external services, process inputs, etc...

#### Order
1. DNS request
2. Check Local Cache for IP Address
3. Check Recursive DNS server for address
4. Query Root Server to find authoritative DNS server
5. Authoritative DNS server advises IP address for website
6. Pass through Web Application Firewall
7. Pass through Load Balancer
8. Connect to Web Server
9. Web server receives the request
10. Web application talks to Database
11. Browser renders the HTML into a viewable Website

#### Summary
- Finally, the last room in the fundamental skills portion, now I can start specializing. Overall, this room served to be a good recap and an extension of my knowledge. I learned about how requests are optimized and secured via Load Balancers, Virtual Hosts, Content Delivery Networks, Databases, and Web Application Firewalls. I also learned of static and dynamic content as well as scripting and backend languages. Lastly, I took a quiz where I had to arrange the process in making DNS requests.