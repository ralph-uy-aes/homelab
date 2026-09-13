# IG.08 - WAF With wafw00f

### wafw00f
- Web Application Firewall Fingerprinting Tool
    - Sends normal HTTP request and analyzes the response
	- If not successful, sends a number of malicious HTTP request and uses logic to deduce which WAF it is
	- If still not successful, still analyzes responses previously returned and uses another simple algorithm to guess if a WAF or security solution is actively responding to attacks
- Syntax: `wafw00f hostname -a`
- Doesn't only tell you that there's a WAF, tells you the specific WAF it is
- Can test multiple targets, all possible WAFs, etc
    - Very versatile