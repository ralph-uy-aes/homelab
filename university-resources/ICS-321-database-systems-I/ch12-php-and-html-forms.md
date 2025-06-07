# PHP and HTML Forms

## 12.1 Full-stack Development (PHP)

#### Overview
- Most websites and applications require the development of client-side technologies that interact with server-side tech
- Client-side means front-end and refers to HTML, CSS, JavaScript
- Server-side means back-end and refers to PHP, Python, Node.js, Databases
- Full Stack Developers are proficient in both

#### Web Hosting
- Web hosting companies host other websites on their company servers usually for a fee
- Usually used by smaller companies who don't own that kind of hardware
- Factors to choose a company:
    - Reliability
    - Flexibility
    - Security
    - Malware Protection
    - Price

#### Server-side Programming
- Factors in choosing a server-side programming platform:
    - Server Platform
    - Tool Support
    - Developer Experience
    - Library Support
- Traditionally, server-side technologies were used to create dynamic webpages
    - These are webpages that are generated on the web server when requested
    - Now, static webpages are dynamically altered by JavaScript
- Single Page Applications or SPAs provide a similar user experience as a desktop application, all in a single webpage
    - Gmail, Google Docs, Google Calendar
- A web API is a collection of functions that are invoked using HTTP

#### Client-side Programming
- Tools to aid UI Development:
    - HTML Preprocessor
    - CSS Preprocessor
    - UI Library
    - CSS Front-end Framework
- Tools to aid in JS Development:
    - Compile-to-JS language
    - JS Framework


## 12.2 Getting Started With PHP

#### Introduction to PHP
- Personal Home Page, but now it stands for PHP: Hypertext Preprocessor
- Relatively easy to learn, free to use, and ships with the Apache web server, the most popular server-side technology currently in use

#### Executing PHP
- A PHP Script is a file composed of HTML tags and PHP code inserted between `<?php ?>`
- When the browser requests a PHP script, the web server starts the PHP engine which compiles the requested PHP and executes the code

#### Error Reporting
- The `php.ini` file contains configuration settings. When writing and debugging PHP code, most developers enable error reporting using `error_reporting = 1` and generate four types of error messages:
    1. Parse error - syntax error during compilation
    2. Fatal error - runtime error that halts execution
    3. Warning - runtime error that does not halt execution
    4. Notice - runtime message of possible logic error
- `display_error` must also be set to 1 to send error messages to the browser, but set it to 0 so users don't see error messages

#### Comments, Variables, Constants
- A comment is created in PHP using
    ```
    // comment
    # comment
    /* comment
    */
    ```
- A variable stores a single value
    - Must start with a $ sign
    - Can be a combination of letters, digits, or underscores
    - May not start with a digit right after $
- A constant is an identifier initialized to a value that does not change
    - Constants cannot be changed
    - Constants do not use $ in the name
    - Constants are usually ALL CAPS
    - Created with `define("NAME", Value);`

#### Working with Strings
- Variable interpolation is when the PHP engine substitutes the value of a variable for the variable name inside of a double quoted string
    - `$x = "test"; $y = "This is a $x";`
    - If single quotes are sued, variable interpolation does not work
- In order to concatenate strings, use the period
    - `$x = "test"; $y  = "This is a " . $x;`
- Escape Sequences use backslash

## 12.3 to 12.10 
- These are all specific to PHP and I will update them when I have time

## 12.11 Classes and Objects

#### Introduction to Classes and Objects
- A class is a programer defined data type that contains properties and methods
- A property is a variable defined inside a class
- A method is a function defined inside a class
- An object is an instance of a class
- The `new` keyword is used to create an object from a class like `$object = new ClassName;`
- An object's method or property can be accessed using the object operator or `->` like `$object->property = "value";` or `$object->method();`
    - `$this` is used within a method to access the object's properties like `$this->property`
    - Properties are created under a class using `public $Name;`
    - Methods are created under a class using `function sayHello(){...}`

#### References
- When an object is instantiated with `new`, a reference is created to identify the object in memory
- Multiple references can refer to one object

#### Constructors and Destructors
- A constructor is a method that is called when an object is instantiated
    - Defined with `function __construct(parameters) {...}`
- A destructor is a method that is called when no other references to an object exist, useful for cleanup
    - Defined with `function __destruct() {...}`

#### Inheritance
- Allows the child class to inherit parent class' properties and methods
- Extends keyword is used to specify the parent class from which the child is inheriting
- `class Child extends Parent {...}`
- Overriding
    - When a child class redefines a method from a parent

#### Visibility
- The visibility of a property or method determines its accessibility outside of the class
    1. public - accessible from anywhere
    2. protected - accessible only from within the class and those who inherit it
    3. private - accessible only from the defining class
- Methods are public by default

#### Static Properties and Methods
- Static means that a property or method is accessible directly from the class without the need of an instance
- `static` is used to define static properties or methods
- The scope resolution operator or `::` is used between the class name and static property or method like `ClassName::$staticProperty = 10;`


## 12.12 PHP Data Objects

#### PDO
- PHP Script creates a PDO to connect to a MySQL server
    - Created with a DSN and MySQL server account's username and password
    - Data Source Name or DSN is a string containing database information
        - DSN Prefix - "mysql:" for MySQL
        - host - database server's hostname
        - port - database server's port number
        - dbname - database name
- If it fails to connect to MySQL it returns a PDOException resulting in a fatal error

#### SELECT Statement
- Once connected, SQL statements can be executed using `query(sql)` method which executes the `sql` statement given
- Once data has been queried, you can use `fetch()` to return an associative array containing the data from one row or FALSE if none was selected
- Ex.
```
$sql = "SELECT stuid, name, gpa FROM student WHERE gpa >= 2.0";
$statement = $pdo->query($sql);
while ($row = $statement->fetch()){
    echo "$row[stuid], $row[name], $row[gpa]\n"
}
```

#### Prepared Statements
- An SQL statement may be created dynamically using values from a file, database, user input, etc...
- Used to create dynamic SQL statements
- A prepared statement is an SQL statement that can be customized with parameters
- A web application that uses input from a user in an SQL statement may be susceptible to SQL Injection attacks
    - When a malicious user enters input int oa web application that alters the intent of an SQL statement
- Prepared statements circumvent most SQL injection attacks
- Executed and created in three steps:
    1. Prepare - The PDO method `prepare(sql)` prepares the parameterized SQL statement for execution and returns a PDOStatement
    2. Bind - `bindParam(param-id, variable)` binds the variable to the parameter identifier in the SQL statement, `bindValue(param-id, value)` alternatively binds a value
    3. Execute - `execute` executes the SQL statement


## 12.13 Forms

#### <form> Element
- `<form>` allows the browser to submit information from the user to the server
- Has two primary attributes
    1. Action attribute - indicates the URL where the form data should be sent, typically the URL
    2. Method attribute - indicates the HTTP request type the browser will use to communicate with the server, uses either POST or GET

#### GET
- A technique used by web browsers to submit information to a web server by altering the URL of the HTTP request
- When a user clicks submit in a form that uses GET, the browser:
    1. Collects all data from fields into a query string, Ex. `first=Rick&last=Morty`
    2. Create a URL using the server page and query string, Ex. `http://example.com/apply?first=Rick&last=Morty`
    3. Use the newly created URL to create and send an HTTP GET request
    4. Display or update the webpage using the HTTP response received from the server

#### POST
- A technique used by web browsers to submit information to a web server by sending information in the HTTP request body
- When a user clicks the submit button in a form that uses POST, the browser:
    1. Create an HTTP POST request using the URL from the form's action attribute
    2. Create a query string from the form data, Ex. `first=Sarah&last=Connor`
    3. Place the query string in the HTTP request message body, and send the request
    4. Display or update the webpage using the HTTP response received from the server

#### Form Widgets
- A widget is usually a graphical interactive component that the browser uses to interact with a user
- `<input>` uses:
    - `type` - indicates the widget type like password, text, button, etc..
    - `name` - names the widget and sends the widget's value when the form is submitted
    - `id` - uniquely identifies the widget
    - `placeholder` - specifies text that first appears in a text widget, typically for giving the user a hint as to the expected value
    - `value` - the default value for a widget
- `<label>` displays descriptive text associated with a specific widget
    - Has a `for` attribute whose value should match the `id` attribute for the widget being labeled, helps people using screen readers understand what input is expected
- `<textarea>` allows users to enter multiple lines of text, has optional rows and cols attributes to specify the size of the text area


## 12.15 Submitting Forms PHP

#### Data Validation and Sanitization
- Checking input for correctness
- Performed in two parts:
    1. Client-side - performed in web browser using JS and HTML form validation attributes
    2. Server-side - performed on the web server using PHP
- On the server, data is usually sanitized before validation
- Data sanitization is removing undesired characters from input
    - Uses `trim()` which removes whitespaces characters
    - Escaping any HTML in the text using `htmlspecialchars()`, Ex. `htmlspecialchars("<script>");` returns `&lt;script&gt;`
    - Checking to see if text conforms to an expected pattern, like credit cards having 16 digits or emails ending with an domain
- Escaping HTML prevents XSS or cross-site scripting attacks
    - When a user injects `<script>` with JS into a webpage to cause harm