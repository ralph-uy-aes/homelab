# How Websites Work

#### Websites
- Whenever you visit a website, your browser requests for information pertaining to the website you want from a webserver. The webserver handles your request and responds by sending the data back to your browser which shows you the data you've requested.
- There are two major components to websites
1. Front End (Client Side) - how your browser renders a website
2. Back End (Server Side) - processes your request and returns a response

#### HyperText Markup Language or HTML
- The language that websites are written in
- Composed of elements or tags that tell the browser how to display content
- Usually starts with `<!DOCTYPE html>` which defines the page to be an HTML5 document, tells the browser to interpret the content as HTML5
- Common Elements
1. `<html>` - the root element that contains every other element
2. `<head>` - the element that contains page information like the title
3. `<body>` - the element that defines the content shown in the browser
4. `<h1>` - large heading
5. `<p>` - paragraph
- Tags can contain attributes like class, src, or id that each define some parameters on the tag

#### JavaScript or JS
- The language used to make pages interactive
- Controls the functionality of the page and allows for dynamic page updates in real-time
- JS is added within the pages source code and can be loaded with the `<script>` tag or be included remotely with `<script src="<path>"></script>`

#### Sensitive Data Exposure
- Whenever a website doesn't properly protect or obfuscate sensitive clear-text information to the end-user
- Sensitive data can often be found in a site's frontend code
- Web developers may forget to remove login credentials in their comments for their HTML or JS code
- Can lead to attackers accessing different parts of the web application
- When assessing websites for security issues, one of the first things to do is to review the page source code to see any exposed login credentials or hidden links

#### HTML Injection
- Vulnerability that occurs whenever unfiltered user input is displayed on the page
- If a website fails to sanitize user input, the input is used on the page and an attacker can inject HTML code into a vulnerable website
- Input sanitization is the process of cleaning a user's input to prevent attempted database injections or HTML injections
- When a user controls how their input is displayed, they can submit HTML or JS code that may allow the user to alter the site's appearance and functionality
- The principle is to never trust user input by sanitizing everything the user enters before using it in a JS function
    - Can be done for example by removing HTML tags
- I injected a malicious link into a function that takes user input as "name" and appends it onto a `<tag>` element by typing `<a href="<Link>">name</a>` into the "name" field. This creates a link to the malicious site on the website itself

#### Summary
- Websites make a lot of sense to me as I have done a software engineering class. It is interesting to see how easily web devs overlook security and leak important information over source code as well as create sloppy user input filtering which allow malicious parties to create HTML and JS injections.