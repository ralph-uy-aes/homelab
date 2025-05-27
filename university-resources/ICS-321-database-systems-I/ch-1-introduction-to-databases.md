# Introduction to Databases

## 1.1 Database Basics

#### Data
- Any type of information (numeric, textual, visual, audio) that describes real systems
- Collected and processed to be used in different tasks like weather forecasts, investment analysis, pandemics, etc...
- Varies in:
1. Scope - amount of data produced and collected
2. Format - produced as numbers, text, images, audio, or video
3. Access - some data is private and others are public
- Historically, data was analog: encoded as continuous variations on various physical media
    - Ex. Audio recorded on vinyl discs, Images on celluloid tapes
- Nowadays, data is digital: encoded as ones and zeroes on electronic and magnetic media
    - Ex. MP3 in your SSD, JPG in your HDD
- Analog to digital caused the rise of large computer databases
- You can access public data using:
    - [data.gov] - Provides more than 250,000 U.S. government data sets to support research and application development.
    - [kaggle.com] - Owned by Google, supports an online community that allows users to find and publish data sets.
    - [data.Nasa.gov] - Provides numerous data sets in categories such as aerospace, earth science, and space science.
    - [cancer.gov/research] - Collects and reports data and information relative to all forms of cancer.
    - [opendata.cityofnewyork.us] - Data collected by the New York City government to support continuous monitoring and improvements to NYC and residents' health.

#### Databases
- A collection of data in a structured format
- Can be stored on anything, even paper or tablets
    - Modern databases are stored on computers that contain trillions of bytes of data and support thousands of users
- Similar data is stored in a standardized manner
- Databases are managed using:
1. Database Management System or DBMS - A software that reads and writes to a database. Ensures that data is secure, consistent, and available at all times
2. Query - A request to retrieve or update data. Query languages in particular are designed for databases systems. Read and write efficiently compared to general-purpose languages like Python and C++
3. Database Application - A software that helps business users interact with database systems. Databases and query languages might be too complex for users, so applications are made to simplify them.

#### Database Roles
1. Database Administrator
    - Secures the database
    - Enforces procedures for user access and database system availability
2. Database Designer
    - Determines the format of each data element and the database structure
    - Balances several priorities: storage, response time, and support for rules that govern the data
    - These priorities naturally conflict, so design is full of tradeoffs
3. Database Programmer
    - Develops the programs that utilize the database
    - Writes applications that combine database query languages and general-purpose languages
4. Database User
    - Requests, updates, or uses stored data to generate information
    - Access databases via applications or via queries directly to the database system.


## 1.2 Database Systems

#### File Systems and Database Systems
- Essentially, Database systems are used for larger and more complex databases that are shared by many users
- Have the following requirements:
1. Performance - maintain fast response times by structuring data properly on storage media and processing queries efficiently
2. Authorization - authorize individual users to access specific data, restrict everyone unauthorized
3. Security - protect against hackers by encrypting data and restricting access
4. Rules - ensure data is consistent with structural and business rules, includes synchronization
5. Recovery - systems must recover from failure and restore the database to a consistent state without loss
- File systems are not designed for the above and have since been replaced by database systems

#### Transactions
- A group of queries that must be completed or rejected entirely, no partials
- Sometimes the execution of queries can lead to incorrect data
- Database systems must:
1. Ensure transactions are processed completely or not at all. Any partial results must be reversed and the database must be restored in case of any failure.
2. Prevent transaction conflicts. Multiple transactions may access data simultaneously, causing conflict.
3. Ensure transaction results are never lost once completed. Everything must be saved on storage media.

#### Architecture
- The internal components and the relationship between them
- Components of most database systems are similar:
1. Query processor - Interprets queries, creates plans to modify the database or retrieve data, and returns results to the application. Query optimization may be used to ensure efficient instructions are executed.
2. Storage manager - Translates query processor instructions into low-level commands to modify or retrieve data. Storage managers use indices to locate data.
3. Transaction manager - Ensures transactions are properly executed. Prevents conflicts between concurrent transactions. Restores the database to a consistent state in the event of a failure.
4. Log - Contains complete records of every event processed by the database. Transaction manager writes into the log file before applying changes. In case of failure, the logs are used to restore the database.
5. Catalog - Also known as the data dictionary. A directory of tables, columns, indices, and other database objects.
- Some databases may have different components and some may not even have transaction managers

#### Products
- Most database systems are relational which means they store data in tables, columns, and rows like a spreadsheet
- Everything in a column have the same format, everything in a row is a single record with different values
- Structure Query Language or SQL is used by relational database systems
- Ideal for databases that require an accurate record of every transaction like banking, airline systems, and student records
- The internet generated massive volumes of online data called big data which often had poorly structured or missing information
    - Newer non-relational systems are called NoSQL or Not only SQL which is better for big data that is not relational or too accurate
    - NoSQL and other open source systems have proliferated
    - DB-Engines ranks the leading database products today
    1. Oracle Database owned by Oracle, relational, commercial
    2. MySQL owned by Oracle, relational, open source
    3. SQL Server, owned by Microsoft, relational, commercial
    4. PostgreSQL, owned by PSQL Global Development Group, relational, open source
    5. MongoDB, owned by MongoDB, NoSQL, open source


## 1.3 Query Languages

#### Common Queries
- A query is a command for a database to insert, retrieve, update, or delete data
- A query language is a language used for writing database queries
- Remember CRUD which means create, read, update, delete

#### Writing Queries with SQL
- Structured Query Language or SQL is the standard query language for relational databases (wow imagine if we had a standard for general languages)
- An SQL statement is a complete executable command, can be anything from retrieval, updates, creation, definition, or authorization.
1. `INSERT` - create a new value, uses `INTO <name>`
2. `SELECT` - retrieve an existing value, uses `FROM <name>`
3. `UPDATE <name>` - update an existing value
4. `DELETE` - delete an existing value, uses `FROM <name>`

#### Creating Tables with SQL
- `CREATE TABLE <name>` - creates a new table, but you must also specify the column names and their data types right after
    - For example:
    ```
    CREATE TABLE Employee(
        ID          INT,
        Name        VARCHAR(60),
        BirthDate   DATE,
        Salary      DECIMAL(7,2)
    );
    ```
    - `INT` - integer values
    - `DECIMAL` - fractional numeric values
    - `VARCHAR(n)` - textual values up to n values
    - `DATE` - year, month, day
    - `DECIMAL(10,3)` - ten significant digits including three after decimal point


## 1.4 Database Design and Programming

#### Conceptual Design
- Database design is a specification of database objects like tables, columns, data types, and indices
- For small databases, the design process can be unstructured
- For large databases, there are three phases:
1. Conceptual design
2. Logical design
3. Physical design
- Conceptual design is the phase that specifies database requirements without regard to a specific database system
- Requirements are represented as entities, relationships, and attributes
    - Has many alternative names like analysis, data modeling, and definition
    - Entities are basically entries like people or objects
    - Relationships are links between entities
    - Attributes are defining characteristics of entities
    - These requirements are often depicted in ER diagrams where rectangles are entities, lines are relationships, and text are attributes

#### Logical Design
- This pase implements database requirements in a specific database system
- A key is a column used to identify individual rows of a table
- Instead of an ER diagram, the logical design phase uses table diagram
    - Rectangles are tables which are labeled by the table name
    - Text under the rectangles represent columns
    - Bullets indicate key columns
    - Arrows between tables indicate columns that refer to keys. The tail of the arrow is aligned with the column and is pointing to the table which contains the key
- For example, The BookAuthor table has two columns: AuthorID and BookID. The two columns are both key columns and must source their values from different tables. The AuthorID key points to the Author table which contains the key ID and the columns FirstName, LastName, and Birthdate. The BookID key points to the Book table which contains the key ID and the columns Title, Category, and Price.
- Some relationships in the ER diagram from the conceptual design phase are implemented as tables in the table diagram of the logical design phase

#### Physical Design
- Finally, the physical design phase adds indices and specifies how tables are organized on storage media
- Specified with SQL statements and is specific to a database system
- Can be depicted in diagrams, but are not really as important as logical design for users and programmers
- Logical and physical design affects queries differently
    - Logical affects the result
    - Physical affects the processing speed, but never affects the result
        - Therefore, it is data independent which means designers can tune the performance of a query without changing the database application
        - Designers only modify indices or row order to improve performance, but generate the same results

#### Programming
- Because of data independence, database applications can be programmed before physical design is in place
    - This results in slower queries, but generate the same correct results
- To write database programs, SQL is usually combined with general-purpose languages like Python or C++
- To simplify the use of SQL with a general-purpose language, APIs are used
    - APIs hold a library of procedures or classes that link a language to a database
    - The host language calls library procedures and handle details like connecting to the database, executing queries, and returning results
    - Dozens of database APIs are available, each of them provide support for different general-purpose languages
    - APIs are written in the host language which is the same as the general-purpose language that the API will be used for


## 1.5 MySQL

#### MySQL Server
- A leading relational database system that is easy to use and install and can run on all major operating systems
- Several editions:
1. MySQL Community/Server - free edition with a complete set of database services and tools
2. MySQL Enterprise - paid edition for commercial databases
3. MySQL HeatWave - commercial edition like Enterprise, but has additional capabilities for analytics and machine learning

#### SQL Tools
1. SQL Sandbox - The SQL sandbox is an online SQL programming tool included in this zyBook. The sandbox has two practice databases, zybooksdb and sakila.
2. MySQL CL-Client - Command-Line Client is a simple, textual SQL programming tool. Command-Line Client is easier to learn than Workbench. Command-Line Client is included with the MySQL Server download and installation.
3. mycompiler.io - mycompiler.io is a free, online programming tool that supports SQL, as well as many other programming languages. This tool is easy to use but does not support the Sakila database.
4. MySQL Workbench - Workbench is a complex but powerful SQL programming tool with a graphical programming interface. Beginning students may find Workbench difficult to learn. Workbench is included with the MySQL Server download and installation.
