# IG.02 - Target Scoping

### Lesson Objective
- Understand target scoping
- How to identify what is in scope and out of scope

### What is it?
- Process of defining exactly what systems, networks, or apps you are authorized (allowed) to test
- You cannot just test everything you find in a penetration test (usually)
    - Test only what is authorized explicitly
    - Usually laid out in the Rules of Engagement
- For information gathering, it answers "What am I allowed to collect information about?"

### Common Types of Targets
- Defined in one or more ways:
- Domain-Based Targets
    - Websites or web applications
    - Ex.
        - example.com
        - testsite.local
    - May include
        - Primary domain
        - Subdomains (mail.example.com)
- IP-Based Targets
    - Ex.
        - Single IP (192.168.0.9)
        - Network range (192.168.0.1/24)
    - Common in internal, lab-based, or cloud-based environments
- Application-Based Targets
    - Reconnaissance focuses on this application only, not the entire server
    - Ex.
        - Specific web application
        - Login portal or API endpoint

### Scope
- In-Scope
    - Assets you are allowed to:
        - Collect information from
        - Scan
        - Enumerate
- Out-of-Scope
    - Assets you must not interact with
    - Ex.
        - Third-party services
        - External domains not listed in scope
        - Systems owned by another organization

### Why Scoping Matters
- Reconnaissance involves collecting useful information and obviously, not everything is useful
    - Without proper scoping:
        - You can scan irrelevant hosts
        - You may miss the actual target
        - Your results become noisy and confusing
    - Well-defined scopes keep your reconnaissance:
        - Focused
        - Efficient
        - Relevant to later stages
- Scopes can also be legally binding, so you should ideally cover your butt
