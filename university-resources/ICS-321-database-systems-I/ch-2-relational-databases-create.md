# Relational Databases - Create

## 2.1 Relational Model

#### Database Models
- A database model is a conceptual framework for database systems
- It has 3 parts:
1. Data structures that prescribe how data is organized
2. Operations that manipulate data structures
3. Rules that govern valid data
- The relational model is a database model based on a tabular data structure
    - Published in 1970 by E.F. Codd of IBM and commercialized in 1980
    - Structure, operations, and rules are standardized in SQL
    - Replaced hierarchical and network databases from the 1960s and 1970s
    - Initially designed for transactional data for banks and airlines
- The 1990s saw the rise of the internet which generated big data
    - Unprecedented data volumes and rapidly changing data structures
    - Relational databases have gradually improved support for big data and continue to dominate today
- Some Models (Name/Data Structure/Release Year/Example/Strengths):
    1. Hierarchical, Tree, 1960s, IMS, Fast Queries and Efficient Storage
    2. Network, Linked List, 1970s, IDMS, Fast Queries and Efficient Storage
    3. Relational, Table, 1980s, Oracle DB, Productivity and Simplicity in Transactional Applications
    4. Object, Class, 1990s, ObjectStore, Integration with OOP Languages
    5. Graph, Vertex and Edge, 2000s, Neo4j, Flexible Schema for Evolving Business Requirements
    6. Document, XML JSON, 2010s, MongoDB, Flexible Schema and Unstructured and Semi-Structured Data

#### Relational Data Structure
- Based on set theory
- A set is an unordered collection of elements in braces {c, a, b}
- A tuple is an ordered set of elements in parentheses (a, b, c)
- A table has a name, a tuple of columns, and a set of rows
- A column has a name and data type
- A row is an unnamed tuple of values, each value corresponds to a column
- A data type is a named set of values where column values are drawn from
- Terminology (Databases/Mathematics/Files)
    - Table = Relation = File
    - Column = Attribute = Field
    - Row = Tuple = Record
    - Data type = Domain = Data type

#### Relational Operations
- Based on set theory
- Each operation generates a result table from one or two input tables:
    - Select - selects a subset or all rows of a table
    - Project - selects one or more columns of a table
    - Product - lists all combinations of rows of two tables
    - Join - combines two tables by comparing related columns
    - Union - selects all rows of two tables
    - Intersect - selects rows common to two tables
    - Difference - selects rows that appear in one table but not another
    - Rename - changes a table name
    - Aggregate - computes functions over multiple table rows like sum or count
- Operations are collectively called relational algebra and are the theoretical foundation of SQL

#### Relational Rules
- Logical constraints that ensure data is valid
- Implemented as SQL constraints and enforced by a database system
- Part of relational model and govern data in every relational database
    - Ex.
    1. Unique primary key - all tables has at least one primary key column where values may not repeat
    2. Unique column names - two different columns cannot have the same name
    3. No duplicate rows - no two entities may have identical values
- Business rules are based on business policy and specific to a particular database
    - Ex.
    1. All rows of the Employee table must have a valid entry in the DeptCode column
    2. PassportNumber values may not repeat in different Employee rows


## 2.2 Structured Query Language

#### Sublanguages
- SQL statements are divided into 5 sublanguages:
1. Data Definition Language or DDL - defines database structure
2. Data Query Language or DQL - retrieves data
3. Data Manipulation Language or DML - inserts, updates, and deletes data
4. Data Transaction Language or DTL - manages transactions
5. Data Control Language or DCL - specifies user access to data

#### Language Elements
- SQL is built from many language elements 5 introductory ones are:
1. Literal - Explicit values like strings or numbers. Ex. `'Maria'`, `129`, `"Hello World"`
2. Keyword - Special words for the language processor defined by the database system. Ex. `SELECT`, `INSERT`, `INTEGER`
3. Identifier - Names of database objects like table or database names defined by the programmer. Ex. `City`, `FirstName`, `Population`
4. Expression - Sequence of literals, identifiers, and operations that evaluate into single values. Ex. `Population > 1000 OR Name = "Tokyo"`
5. Comment - Text ignored by the language processor, single line comments are prepended with `--` and mutli line comments use the `/**/` structure. Ex. `-- single line comment`
- A statement is a complete executable instruction that ends with a semicolon
    - Consists of one or more clauses
    - Clauses begin with a keyword, then other elements. Ex. `SELECT Name`
    - Line breaks separate the clauses and are ignored by the language processor
    - Statements only break at the semicolon
    - Ex.
    ```
    -- Commenti commento
    SELECT Name
    FROM City
    WHERE Population > 10000;
    ```

#### Syntax Definitions
- MySQL syntax definitions use the following notation:
1. UPPERCASE - indicates SQL keywords
2. lowercase - indicates an identifier or expression
3. [Square brackets] - enclose an optional language element
4. {Curly braces} - enclose a series of alternative language elements separated by vertical bars
5. Ellipsis... - indicates that the preceding language element may be repeated
6. (Parentheses) - used along with commas to indicate literal symbols
- This is a good guide for reading the documentation

#### The SQL Standard
- Specifies the official syntax and behavior of SQL statements
- Published jointly by the American National Standards Institute or ANSI and the International Organization for Standardization or ISO
- Parts of the standard are not the same as sublanguages, a part is a formal specification of syntax and behavior while a sublanguage is an informal grouping of statements
- All five sublanguages are specified in one part of the standard called Foundation
- Active Parts:
1. 1 - Framework
2. 2 - Foundation
3. 3 - Call-Level Interface (SQL/CLI)
4. 4 - Persisted Stored Modules (SQL/PSM)
5. 9 - Management of External Data (SQL/MED)
6. 10 - Object Language Bindings (SQL/OLB)
7. 11 - Information and Definition Schemas (SQL/Schemata)
8. 13 - Routines and Types using Java (SQL/JRT)
9. 14 - XML-Related Specifications (SQL/XML)
10. 15 - Multi-Dimensional Arrays (SQL/MDA)
11. 16 - Property Graph Query (SQL/PGQ)
- MySQL Uses:
1. Framework - introduces relational principles, terms, and concepts, but does not specify SQL syntax.
2. Foundation - the core of the SQL standard and specifies statements of the five sublanguages.
3. Persisted Storage Modules - extends SQL with programming elements such as loops and procedures.
4. SQL/Schemata - defines the information_schema database
5. SQL/XML - specifies an XML data type and functions that manipulate XML data.


## 2.3 Managing Databases

#### CREATE DATABASE and DROP DATABASE Statements
- A database system instance is a single executing copy of a database system
- Personal computers usually just run one instance of a database system
- Shared computers for cloud services and such run multiple instances
- `CREATE DATABASE <name>` - creates a new database
- `DROP DATABASE <name>` - deletes an existing database including all tables

#### USE and SHOW Statements
- `USE <name>` - selects a default database for use in subsequent statements
- `SHOW <object>` - provides information about databases, tables, and columns
    1. `SHOW DATABASES` - lists all databases in the instance
    2. `SHOW TABLES [FROM <database name>]` - lists all tables in the default database
    3. `SHOW COLUMNS FROM <table name>` - lists all columns in the table given of the default database
    4. `SHOW CREATE TABLE <table name>` - shows the CREATE TABLE statement for the table given of the default database


## 2.4 Tables

#### Tables, Columns, and Rows
- A table has a name, columns, and rows
- A column has a name and a data type
- A row is an unnamed sequence of values
- A cell is a single column of a single row

#### Rules for Tables
1. Each cell must have only one value (NULL if unknown)
2. No duplicate column names
3. No duplicate rows
4. No row order (because a table has a set of rows)
- Rule 4 is equivalent to data independence

#### CREATE TABLE and DROP TABLE Statements
- `CREATE TABLE [IF NOT EXISTS] <name>` - creates a new table by specifying the table name, column names, and data types
- `DROP TABLE [IF EXISTS] <name>` - deletes an existing table along with all of its rows from a database
- Ex.
    ```
    CREATE TABLE Employee (
        ID          INT,
        Name        VARCHAR(60),
        BirthDate   DATE,
        Salary      DECIMAL(7,2)
    );

    DROP TABLE Employee;
    ```

#### ALTER TABLE Statement
- Adds, deletes, or modifies columns on an existing table
- Specifies the table name followed by a clause that indicates what should be altered
1. ADD - adds a column
2. CHANGE - modifies a column
3. DROP - deletes a column
- Ex.
    ```
    ALTER TABLE Coffee
    ADD Origin VARCHAR(60)
    CHANGE Price PromoPrice DECIMAL(3,2)
    DROP Flavor;


## 2.5 Data Types

#### Data Type Categories
- A named set of values from which column values are drawn
- Few General Categories:
1. Integer - represent positive and negative whole numbers
2. Decimal - represent numbers with fractional values
3. Character - represent textual characters
4. Date and Time - represent date and time or both
5. Binary - store data exactly as they appear in memory or files
6. Spatial - store geometric information such as lines, polygons, or coordinates
7. Document - contain textual data in XML or JSON
- Few SQL Categories (General/SQL/Example)
1. Integer, INT, -1000
2. Decimal, FLOAT , 3.1415
3. Character, VARCHAR, Chicago
4. Date and Time, DATETIME, 12/25/2025 10:35:30
5. Binary, BLOB, 100100111
6. Spatial, POINT, (2.5, 33.44)
7. Document, XML, `<menu>...</menu>`

#### MySQL Data Types
- Unsigned means a number cannot be negative and signed means it can be negative
- To minimize a table size, try to use the types with the smallest storage requirements
- Common MySQL Data Types:
1. TINYINT (1B), SMALLINT (2B), MEDIUMINT (3B), INT(4B), BIGINT(8B)
2. DECIMAL(M, D) (M, D B), FLOAT (4B), DOUBLE (8B)
3. DATE (3B), TIME (3B), DATETIME (5B)
4. CHAR(N) (NB), VARCHAR(N) (N+1 B or N+2 B), TEXT (N+2 B)