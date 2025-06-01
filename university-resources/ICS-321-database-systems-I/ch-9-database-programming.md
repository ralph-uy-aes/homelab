# Database Programming

## 9.1 Programming Languages

#### Programming Languages
- Two Paradigms
1. Imperative Languages
    - Control flow statements determine execution order of steps
    - Procedural languages which are composed of functions, Ex. COBOL, C
    - Object-oriented languages which organize code into classes or objects, Ex. Java, Python, C++
2. Declarative Languages
    - No control flow statements
    - Each statement declares result desired
    - SQL, HTML

#### Database Programming
- Declarative languages are used for databases because they're easier to program and execute faster
- Complete applications do combine SQL with an imperative language, so together it becomes database programming
- Two challenges:
1. Syntax gap - SQL and other languages have very different syntax
2. Paradigm gap - query processing is fundamentally different between SQL and imperative languages

#### Database Programming Techniques
- To bridge the gaps:
1. Embedded SQL - SQL statements directly in a program written in another language. Preceded by `EXEC SQL` keywords to distinguish.
2. Procedural SQL - extends SQL with control flow statements
3. Application Programming Interface or API - Library of procedures or classes that links an application programming language to a computer service like database, email, or web.

#### Advantages and Disadvantages
- Embedded
    - Advantages: Simple
    - Disadvantages: Has gaps, More compile steps, Network traffic
- Procedural SQL
    - Advantages: Gaps are minimal, Compiled in one step, Reduced network traffic, Optimized
    - Disadvantages: Do not offer full capabilities of general-purpose languages
- API
    - Advantages: No syntax gap, paradigm gap reduced, Available for general-purpose and OOP languages, Database independent


## 9.2 Procedural SQL

#### Overview
- Basically, SQL with functions, loops, and conditionals
- Intended for database applications
- Can be used for complete programs, but are just used to create procedures usually, procedures are called stored procedures
- SQL/PSM (Persistent Stored Modules) is a standard for procedural SQL, extending core SQL standard
    - Implemented in many relational databases
- Database | Programming Language:
    - Oracle - PL/SQL
    - SQL Server - Transact-SQL
    - DB2 - SQL PL
    - PostgreSQL - PL/pgSQL
    - MySQL - SQL

#### Stored Procedures
- Declared with `CREATE PROCEDURE` statement
- Has optional `IN`, `OUT`, or `INOUT` keywords to limit parameters to input, output, or both
- Ex. 
```
CREATE PROCEDURE ProcedureName (<parameter>, <parameter>, ...)
Body

(<parameter>: [IN | OUT | INOUT] ParameterName Type)
```

#### Compound Statements
- A set of statements between a `BEGIN` and `END` keyword
    - A semicolon follows `END`
- `DECLARE` creates variables for use inside stored procedures
    - Statement creates variables
    - Ex. `DECLARE VariableName Type [DEFAULT Value];`
- `SET` assigns a variable with an expression
    - Variable must exist prior to assignment
    - `SET VariableName = <expression>;`
- `IF` is a conditional followed by `THEN`
    - Can have `ELSEIF` and also `ELSE` 
    - Terminated by `ENDIF`
    - Ex.
    ```
    IF expression THEN StatementList
    [ ELSEIF expression THEN StatementList ]
    [ ELSE StatementList ]
    END IF;
    ```
- `WHILE` is a loop statement followed by `DO`
    - Terminated by `END WHILE;`
    - Ex.
    ```
    WHILE expression DO
   StatementList
    END WHILE;
    ```

#### Cursors
- A special variable that identifies an individual row of a result table
- Necessary to process queries that return multiple rows
- Syntax:
    - `DECLARE CursorName CURSOR FOR Statement` - creates a cursor associated with a statement
    - `DECLARE CONTINUE HANDLER FOR NOT FOUND Statement` - specifies a statement that executes when the cursor moves past the last row an cannot fetch more data
    - `OPEN CursorName` - executes the query associated with the cursor and positions it before the first row of the table
    - `FETCH FROM CursorName INTO variable [, variable, ...]` - pushes cursor to next row and stores all data into a variable/s
    - `CLOSE CursorName` releases the result table associated with the cursor

#### Stored Functions
- A stored procedure that returns a single value
- Declared with `CREATE FUNCTION`
- Function parameters are for input only
- Returns a single value
- Invoked with an `SQL` expression, not `CALL`
- Ex.
```
CREATE FUNCTION FunctionName( <ParameterName Type>, <ParameterName Type>, ... )
   RETURNS Type
Body
```
- Behave like built-in SQL functions like `COUNT`, `SUM`

#### Characteristic
- Optional clause that appears between the header and body of a function or procedure
- Ex.
```
COMMENT 'string'
[NOT] DETERMINISTIC
{ CONTAINS SQL | NO SQL | READS SQL DATA | MODIFIES SQL DATA }
```

#### Triggers
- A stored procedure or stored function, but:
    - Have no parameters or return values
    - Not explicitly invoked by a `CALL` statement or within an expression
- `CREATE TRIGGER` specifies a TriggerName followed by four required keywords
1. `ON TableName` - identifies the table associated with the trigger
2. `INSERT, UPDATE, or DELETE` - indicates that the trigger executes when the corresponding SQL operation is applied to the table
3. `BEFORE` or `AFTER` - determines when the trigger executes before or after the insert,update, or delete
4. `FOR EACH ROW` - indicates the trigger executes repeatedly, once for each row affected by insert, update, and delete
- Ex.
```
CREATE TRIGGER TriggerName
{ BEFORE | AFTER } { INSERT | UPDATE | DELETE }
ON TableName 
FOR EACH ROW
Body
```