# E.06 - Web Server Enumeration

### Web Server
- Software used to serve website data on the web
- Uses **HTTP** (Hypertext Transfer Protocol) for client-server communication
- HTTP is an application layer protocol using **TCP port 80**
- Popular web servers: **Apache**, **Nginx**, **Microsoft IIS**

### Enumeration
- Use Metasploit auxiliary modules to enumerate:
    - Web server version
    - HTTP headers
    - Brute-force directories
    - And much more

### Common Metasploit Modules
- `auxiliary/scanner/http/http_version` — web server version
- `auxiliary/scanner/http/http_header` — HTTP headers
- `auxiliary/scanner/http/robots_txt` — robots.txt
- `auxiliary/scanner/http/brute_dirs` — directory brute-force
- `auxiliary/scanner/http/dir_scanner` — directory scanning
- `auxiliary/scanner/http/files_dir` — file/directory discovery
- `auxiliary/scanner/http/http_login` — HTTP authentication brute-force

### Demo
- Web Server Enumeration

### eJPT Takeaway
- HTTP default port is **80** (HTTPS: 443)
- Enumeration reveals server type, version, headers, and hidden directories
- `robots.txt` often leaks sensitive paths
- Directory brute-forcing can uncover admin panels, backups, and config files