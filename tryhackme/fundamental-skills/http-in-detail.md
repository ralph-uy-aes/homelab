# HTTP in Detail

#### HyperText Transfer Protocol or HTTP
- The protocol used whenever you access a website
- Developed by Tim Berners-Lee and co. during 1989-1991
- Defines rules used for communicating with web servers for transmitting webpage data in HTML, Images, Videos, etc...

#### HyperText Transfer Protocol Secure or HTTPS
- Secure version of HTTP
- Data is encrypted so it stops people from seeing data sent and received and assures that the web server you're connecting to is not a clone or a malicious site impersonating the real one

#### HTTP Requests and Responses
- Whenever we access a website, the browser makes requests to web servers for assets like HTML and images and download the responses
- The browser tells the server specifically how and where to access the resources using Uniform Resource Locator or URL
    - URLs are essentially instructions on how to find specific resources
    - `http//user:password@tryhackme.com:80/view-room?id=1#task3`
        - Scheme: http - The protocol to use for accessing resources (HTTP, HTTPS, FTP) 
        - Credentials: user:password - Sometimes services require authentication, this means username and password
        - Host or Domain: tryhackme.com - The domain or IP of the server
        - Port: 80 - The port to connect to (80: HTTP, 443: HTTPS)
        - Path: view-room - The file name or location of resource to access
        - Query String: ?id=1 - Extra bits of information to send to the path, id=1 literally means the resource whose id=1
        - Fragment: #task3 - Reference to a location on the actual page requested, usually seen in pages with hyper links
- Request
    - It is possible to make a request to a web server with just one line: `GET / HTTP/1.1`
        - GET is the request method
        - / is the page being requested
        - HTTP/1.1 is the version of HTTP
    - Other data may also be required, so they're sent in the form of headers
        - Headers contain extra information to give to web servers you're communicating with
        - `Host: tryhackme.com` - The web page we are trying to access
        - `User-Agent: Mozilla/5.0 Firefox/87.0` - Which browser version we are using
        - `Referer: https://tryhackme.com/` - Which web page referred us to the new web page
        - ` ` - HTTP requests must always end with blank line to act as a delimiter (like a semicolon in C)
- Response
    - `HTTP/1.1 200 OK` - HTTP/1.1 is the version of HTTP, 200 OK is the status code that tells us the request is completed successfully
    - `Server: nginx/1.15.8` - The web server's software and version number
    - `Date: Fri, 09 Apr 2021 13:34:03 GMT` - The current time of the web server
    - `Content-Type: text/html` - What sort of information is going to be sent, in this case html
    - `Content-Length: 98` - How long the response is, used to verify if content is missing
    - `<html>...` - The actual requested content in the form of HTML code in this case

#### HTTP Methods
- HTTP methods are used by clients to indicate intended actions when making HTTP requests
1. GET - Used for getting information from a web server
2. POST - Used for submitting data to the web server and potentially creating new records
3. PUT - Used for submitting data to a web server to update information
4. DELETE - Used for deleting information or records from a web server

#### HTTP Status Codes
- Status codes are codes that tell you how the server responded
    - The first line indicates the code and how the client should handle the response
1. 100-199 - Information Response - The first part of the request was accepted and they should send the rest. Not common anymore.
2. 200-299 - Success - Request was successful,
3. 300-399 - Redirection - The request was redirected to another source (a new webpage or a new website).
4. 400-499 - Client Errors - There was an error with the request.
5. 500-599 - Server Errors - There was a server-side error, server cannot handle the request.
- Common Codes
1. 200 OK - Request was successful
2. 201 Created - Resource has been created
3. 301 Moved Permanently - Redirects the browser to a new webpage or tells search engines that the page was moved and to look there instead
4. 302 Found - Kind of like a temporary redirection and may change in the future
5. 400 Bad Request - Something was wrong or missing in the request, usually missing some parameters that the server needs for the resource
6. 401 Not Authorized - Not allowed to view the resource until you're authorized in some way, usually username and password
7. 403 Forbidden - No permission to view this resource whether logged in or not
8. 405 Method Not Allowed - Request method not allowed for resource requested
9. 404 Page Not Found - Page or resource does not exist
10. 500 Internal Service Error - Server has some error with the request and doesn't know how to handle it properly
11. 503 Service Unavailable - Server is either overloaded or under maintenance

#### HTTP Headers
- Additional bits of data you can send to web servers when making requests
- No headers are required, but it will be difficult to view websites properly without having them in requests
- Common Request Headers
1. Host - Some web servers host multiple websites so providing the host headers can help you get whichever one you need, if not you get the default
2. User-Agent - Browser's software and version number tells the server what format it should use to show the elements properly (HTML, JS, CSS)
3. Content-Length - How much data to expect in the web request, ensures no missing data
4. Accept-Encoding - What type of compression methods your browser supports so the data can be transmitted faster over the internet
5. Cookie - Data sent to the server to help remember information
- Common Response Headers
1. Set-Cookie - Information to store which gets sent back to the web server on each request
2. Cache-Control - How long to store response content in a browser's cache before having to be requested again
3. Content-Type - What type of data is being returned, using the content-type header the browser knows how to process the data
4. Content-Encoding - What method was used to compress the data to be transmitted faster over the internet

#### Cookies
- Small pieces of data stored whenever a "Set-Cookie" header is received
- Every further request sends cookie data back to the server
- HTTP is stateless, meaning it doesn't keep track of previous requests
- Cookies can be used to remind web servers who you are including personal settings for websites
    - Often used to remind websites authentication credentials
    - Not cleartext, instead shares a unique secret code or token
- Cookies can be viewed via developer tools under the Network tab and on each request, shows a detailed breakdown
    - Under the Cookies tab of the request

#### Summary
- HTTP was way simpler than I thought, honestly only the cookies make the whole thing seem complicated. I learned how requests and responses work, what parts there are to them, common headers for both request and response, status code ranges, and parts of a URL.