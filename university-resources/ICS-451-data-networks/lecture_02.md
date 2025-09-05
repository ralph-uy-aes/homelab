# Lecture 2

#### Review
- Almost everything relevant to networking these days is related to the internet
    - Which is why we're focusing on the internet
- Client-server is the most prevalent type of network
    - Server holds all information
    - Clients request information

#### Layer Communication
- HTTP layer 7 first talks to layer 6 before it communicates to the destination layer 7
    - Does the US President only talk to the Russian President's secretary? No, but there is a chain of custody for the message
    - Layer (7,6,5) -> Layer 4 -> (...) -> Layer 4 -> Layer (5,6,7)
    - Often, we abstract away everything else and only keep the main idea, so we just say Client sends HTTP request to Server, but there is actually a lot more going on in between
- What happens in the HTTP layer is directly related to what we're sending and receiving
    - When you receive a MP4 or a JPG or even an HTML, your browser is doing most of the work in terms of making the file you have easily viewable
    - It's the same reason why MS Word can't play videos without some sort of plugin
    - You can think of a browser as an HTML/JPG/PDF/MP4/etc... viewer
    - Kind of like an IDE being able to compile and run all kinds of languages

#### Curl
- CLI command
- Basically a command line browser
    - Means it's faster, you can write scripts, etc...
    - You can make a script to open a website 10,000 times using curl in like 2 seconds
        - This is a load-test to ensure that things are working
        - Practical example, Fox asked Ravi to load-test the server for streaming the Super Bowl, which millions of people watch
        - Besides not failing, is the response-time reasonable

#### HTTP Protocol
- HTTP is extremely inefficient in the sense that it sends English characters
    - You could probably compress an HTTP that's 10,000 bytes by sending it in almost 100 bytes using binary
    - English is written in ASCII as opposed to binary which is just 1 and 0
- HTTP used to not work too well for even sending JPG files, but computers got way faster and now HTTP can be used to watch live streams of professional sports and such
- Format is First line -> Headers -> Body

#### Protocol Characteristics
- You can call it a request and response message
    - HTTP client request results in an HTTP server response
- Almost every protocol has a header and a body
    - The body is the starting point, it is what the client is trying to send to the server or what the server is sending back to the client
    - The header offers additional information or context to clarify the intent of the body, also makes it human interpretable
- Both request and response have their own header and body
    - There is an extra piece of information sent with the request and response, but it's usually irrelevant and we'd just call it the first line

#### HTTP Header
- A header is just a single line that contains a name and a value (name-value pair) formatted as (name:value)
- There can be multiple HTTP headers which are sent and received
- Some header names must be memorized in this class; there are probably hundreds, but not all need to be memorized
- Response headers
    - Content-Type: Basically defines what the content is like video or image or text
        - Could say "content-type:video/mp4" or "content-type:image/jpg"
    - Location: Contains the new address you need to go to
        - You only get this when there is a 3xx status code, implying redirection status
        - This is what you use when you use curl
        - A browser automatically interprets this response header and redirects you automatically
- Request headers
    - User-Agent: The type of HTTP client that is sending the request (browser, curl, etc...)
        - Important to provide information regarding whether you're using mobile/desktop or information regarding your location
        - Used to be divided between "desktop/mobile/ipad", but ipad has not been as popular anymore
        - Very specific, defines the version of all your HTTP client's software/hardware
        - There's more than a million user-agents because there are millions of versions of various software/hardware
        - You can trick servers by changing your user-agent and spoofing an entirely different device
            - https://useragents.io

#### HTTP Body
- No Response Body?
    - 404 Not found is not the body, there actually isn't any HTTP response body
        - However, some websites are smarter and give you a page that explicitly says "404 not found" with some graphics
- Method/Resource
    - Request/Header
    - Request/Body
- Status Code
    - Response Header
    - Response Body

#### Methods
- The most popular method is probably "GET", the second is "POST", then "OPTIONS" and finally, "HEAD"
- "PUT" and "DELETE" are not as common and are usually only used by people who create content
- Methods are found in the "First line" of HTTP protocol

#### GET
- You're "GETting" a folder or a file from a directory
- Most of the time, in a GET Request there is no Request Body
- The first line in a Response is usually a three digit status code then a description (think 404: Error Not Found) 
    - In the class, we will memorize about 5 to 6 status code
- When you type "www.hawaii.edu/ics"
    - You provide three pieces of information:
        - HTTP or HTTPS?
        - "www.hawaii.edu" the URL or who to send the method to
            - This is a proxy of the IP address that gets converted to the IP address of the server
        - "/ics" the resource to apply the method to
    - It converts to "GET /ics HTTP/1.1" (Method name + Resource + HTTP/version) in the first line
    - The URL is www.hawaii.edu, the resource itself is /ics
- HTTP 1.0 is obsolete, right now we're at HTTP 1.1, but soon it will be updated to HTTP 1.2

#### Status Codes
- Often three digits
- First digit indicates some meaning (1-5)
- Anything in the 200 category usually means you got what you wanted
- Anything in the 300 series by definition means "redirection", but not all of them do redirect you, more like a semi-error (kind of successful, but you have to work for the information)
    - Browsers automatically type in redirects for you
    - Curl, you have to redirect yourself
- 400s are usually client-side errors
- 500s are usually server-side errors
- 100s are information responses

#### Final/Midterm
- Will have header questions that will ask which are the important ones, what is the most interesting parts of the header?
    - Hint: Look at the STATUS CODE, pick the relevant headers like if there was a redirect (3xx), what is the location header?
        - Or if you had a (2xx), what are you looking for? What's interesting in the headers?

#### IP and URL
- Hostname is the www.whatever.com
- IP Address is the actual IP of www.whatever.com
- Imagine if everyone had a table that corresponded Hostname to IP Address, four billion rows of it
- Instead, we centralize the table and put it inside a server so that whenever a client types a hostname, it requests the IP Address corresponding to that hostname from the centralized server
    - The database client first sends the database request which gets the IP address from the database sever
    - Then, once the database client receives the corresponding IP address, it switches into a HTTP client and sends an HTTP request to an HTTP server

#### Domain Name System (DNS)
- DNS is also an application layer protocol
    - DNS is a very specific protocol that really just says here's a hostname, give me its IP address and it can do the reverse as well
- Client would be a DNS and HTTP client simultaneously if it were to send an HTTP request the usual way (www.whatever.com)
    - DNS client sends hostname to DNS server, DNS server responds with IP Address
    - HTTP client sends request to IP address of HTTP server, HTTP server responds
- But how do you get the IP address of the DNS Server?
    - The operating system comes with a DNS server IP address set already
    - This can be changed or updated manually
- How many DNS servers are there in the world?
    - There can't just be one DNS server for all the requests in the world
    - You need like 6 or 7 DNS servers in the world, all synchronously updated (when one is updated every other one must be)
    - This DNS gets turned into a distributed database
        - One server has bits and pieces of another server and so on