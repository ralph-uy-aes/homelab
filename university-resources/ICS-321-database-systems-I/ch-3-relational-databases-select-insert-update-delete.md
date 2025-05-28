# Relational Databases - Select, Insert, Update, Delete

## 3.1 Selecting Rows

#### Operators
- Operators are symbols that compute a value from one or more other values
- Arithmetic operators - compute numeric values from numeric operands
    - +, -, *, /, %
- Comparison operators - compute logical values like TRUE or FALSE
    - =, != or <>, <, <=, >, >=
- Logical operators - compute logical values from logical operands
    - AND, OR, NOT
- Unary means one operand (one value)
- Binary means two operands (two values)

#### Expressions
- A string of operations, operands, and parentheses that evaluate into a single value
- Operands may be column names or fixed values in SQL
- Operators in an expression are evaluated in order of operator precedence, but are always after parentheses
    - The order of operators is:
    1. - (unary)
    2. ^
    3. * / %
    4. + - (binary)
    5. = != < > <= >=
    6. NOT
    7. AND
    8. OR

#### SELECT Statement
- Selects rows from a table
- Always has a `SELECT` clause and a `FROM` clause
- Uses * to select all
- Ex.
```
SELECT Expression1, Expression2, ...
FROM <table name>;

SELECT Column1, Column2, ...
FROM <table name>;

SELECT * FROM <table name>;
```
- For big databases, you can use the `LIMIT <number>` clause to limit the selection to a number of records

#### WHERE Clause
- A condition is an expression that evaluates to a logical value
- `WHERE` is optional in `SELECT` and allows you to specify a certain condition
- `SELECT <expression (arithmetic) or column literal>` vs `WHERE <condition (logical, comparison)>`
- Ex.
```
SELECT Expression1, Expression 2, ...
FROM <table name>
WHERE Condition;
```


## 3.2 Null Values

#### NULL
- Unknown or inapplicable data
- Not the same as the number 0
- Zero bonus for an employee is not the same as inapplicable or unknown bonus

#### NOT NULL Constraint
- Columns may or may not have NULL values depending on the application
- You can append the `NOT NULL` constraint after the data type of a column to ensure that all NULL values are rejected

#### NULL Arithmetic and Comparisons
- When arithmetic or comparison operators have one or more NULL operands, the result is NULL
- If `WHERE` evaluates into NULL, that row is not selected

#### IS NULL Operator
- Comparison operators cannot be used to select NULL values, so `SELECT * FROM Employee WEHRE Salary = NULL;` does not work
- However, `SELECT * FROM Employee WHERE SALARY IS NULL;` does work

#### NULL Logic
- In math, expressions are always TRUE or FALSE, but when NULL is present, it may evaluate to NULL as well
- Truth Table (x/y/AND/OR)
    - TRUE, NULL, NULL, TRUE
    - FALSE, NULL, FALSE, NULL
    - NULL, NULL, NULL, NULL
    - NOT NULL => NULL


## 3.3 Inserting, Updating, and Deleting Rows

#### INSERT Statement
- Adds rows to a table
- Two clauses:
1. `INSERT [INTO] <table name> (Column1, Column2, ...)`
2. `VALUES (Value1, Value2, ...)`

#### DEFAULT Values
- When a column isn't specified in an `INSERT` statement, the column receives a NULL value for the row inserted
- However, you can specify `DEFAULT` values in the `CREATE TABLE` statement
- Ex.
```
CREATE TABLE Employee(
    ID          SMALLINT UNSIGNED,
    Name        VARCHAR(60) DEFAULT 'JOHN CORPORATE',
    BirthDate   DATE DEFAULT '2000-01-01',
    Salary      DECIMAL(7,2) DEFAULT 0.00
);
```

#### UPDATE Statement
- Modifies existing rows in a table
- Uses the `SET` clause to set new values to each column
- Optional `WHERE` clause to set for only those who pass the WHERE condition
- Ex.
```
UPDATE Employee
SET Name = 'Tom Snead', BirthDate = '2000-03-15', Salary = '60000'
WHERE ID = 5384;
```

#### DELETE Statement
- Deletes existing rows in a table
- Uses the `FROM` keyword followed by the table name
- Optional `WHERE` clause to specify which rows to be deleted, otherwise all
- Ex.
```
DELETE FROM Employee
WHERE EmployeePerformance < 100;
```

#### TRUNCATE Statement
- Deletes all rows from a table, identical to `DELETE FROM <table name>;`
- Differs from `DELETE` based on the database system used