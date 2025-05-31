# Structured Query Language - Joins

## 7.1 Join Queries

#### Joins
- A `SELECT` statement that combines data from two tables, known as left and right table
- Compares the columns with the `=` operator, so types must be comparable
- Usually compares foreign to primary key

#### Prefixes and Aliases
- When duplicate column names appear in a query with joins, you use a prefix which is the table name, then period, then the column name
- You can also use an alias which follows the column name and uses the `AS` keyword followed by the alias
- Ex. `SELECT Department.Name AS Team...`

#### Inner and Full Joins
- A join clause determines how a join query handles unmatched rows
- Common join clauses are:
1. `INNER JOIN` - selects only matching left and right table rows
2. `FULL JOIN` - selects all left and right table rows regardless of match, unmatched left table rows appear with NULL values on right table
- Appears between a `FROM` and an `ON` clause
- Ex.
```
SELECT Department.Name AS Team, Employee.Name AS Supervisor
FROM Department FULL JOIN Employee
ON Manager = ID;
```

#### Left and Right Joins
1. `LEFT JOIN` - selects all left table rows, but only matching right table rows
2. `RIGHT JOIN` - selects all right table rows, but only matching left table rows

#### Alternative Join Queries
- Inner joins can be written without the `JOIN` keyword
- Outer joins can be written with `UNION` instead of `JOIN`
- `UNION` combines the result of two `SELECT` clauses into one result table


## 7.2 Equijoins, Self-joins, and Cross-joins

#### Equijoin
- Compares columns of two tables with the = operator
- Non-equijoin compares columns with anything but the = operator
- Ex.
```
SELECT Class.Name, Student.Name
FROM Class
LEFT JOIN Student
ON Student.Code = Class.Code
AND StudentGrade >= 3.0;
```

#### Self-Join
- A table that joins to itself
- Compares any columns of a table as long as the columns have comparable data types
- Aliases are necessary to distinguish left and right tables
- Ex.
```
SELECT A.Name, B.Name
FROM Employee A
INNER JOIN Employee B
ON B.ID = A.Manager;
```

#### Cross-Join
- Combines two tables without comparing columns
- Uses `CROSS JOIN` without an `ON` clause
- All possible combinations of rows from both tables appear in the result
- Ex.
```
SELECT Model, Gigabytes, Iphone.Price + Storage.Price
FROM IPhone
CROSS JOIN Storage;
```