# Structured Query Language - Subqueries

## 8.1 Subqueries

#### Subqueries
- Sometimes called a nested or inner query
- A query within another SQL Query
- Typically used in a `WHERE` clause to return data to the outer query
- Placed inside parentheses

#### Correlated Subqueries
- Correlated when the `WHERE` clause references a column from teh outer query
- Row selected depend on what row is currently
- Ex.
```
SELECT Name, CountryCode, Population
FROM City C
WHERE Population > 2000 
    (SELECT AVG(Population)
    FROM City
    WHERE CountryCode = C.CountryCode)
```

#### EXISTS Operator
- Used by correlated subqueries
- Returns TRUE if at least one row is returned and FALSE if none are selected
- `NOT EXISTS` does the opposite
- Ex.
```
SELECT Name, CountryCode
FROM City C
WHERE EXISTS
(SELECT * 
FROM CountryLanguage
WHERE CountryCode = C.CountryCode
AND Percentage > 97);
```

#### Flattening Subqueries
- When you replace a subquery with an equivalent `JOIN`
- Steps:
1. Retain the outer query `SELECT`, `FROM`, `GROUP BY`, `HAVING`, and `ORDER BY` clauses
2. Add `INNER JOIN` clauses for each subquery table
3. Move comparisons between subquery and outer query columns to `ON` clauses
4. Add a `WHERE` with the remaining expressions in the subquery and outer query `WHERE` clauses
5. If needed, remove duplicate rows with `SELECT DISTINCT`


## 8.2 Complex Queries

#### Writing a Complex Query
- Strategy:
1. Examine table diagram or other database summary to understand tables and relationships
2. Identify tables containing the necessary data to answer the question
3. Determine which columns should appear in the result table
4. Write a query that joins the tables using its primary and foreign keys
5. Break the problem into simpler queries, one at a time


## 8.3 View Tables

#### Creating Views
- A table name associated with a `SELECT` statement called the view query
- `CREATE VIEW` creates a view table and specifies view name, query, and column names
- Ex.
```
CREATE VIEW ViewName [(Col1, Col2, ...)]
AS SelectStatement;
```

#### Querying Views
- A table specified in the view query's `FROM` clause is a base table
- Base table is stored, whereas view tables aren't
- A materialized view is a view for which data is stored at all times
  - Anything not materialized is not stored
  
#### Advantages of Views
- Protect sensitive data by excluding sensitive columns and including everything else needed
- Save complex queries Complex `SELECT` statements can be saved as a view, can be referenced instead of being written down
- Save optimized queries, optimal statements can be saved as a view and distributed to users

#### Inserting, Updating, and Deleting Views
- Commonly used in `SELECT` statements
- Using in `INSERT`, `UPDATE`, `DELETE` may be problematic
    - If a base table primary key does not appear in a view, an insert to the view generates a `NULL` primary key value, primary keys cannot be `NULL`
    - A view may contain aggregate functions such as AVG or SUM, one aggregate value corresponds to many, so if an update or insert is added to create a new aggregate value, it may be converted to many base table values which is undefined so insert and update is not allowed
    - Join view foreign keys of one base table may match primary keys of another, deleting one may delete foreign key rows or primary key rows which is undefined

#### WITH CHECK OPTION Clause
- View updates bring up a bothersome behavior: an unsatisfied `WHERE` clause from insert or update may occur
- To prevent this, use `WITH CHECK OPTION` which rejects inserts and updates that do not satisfy the `WHERE` clause, error message comes up instead


## 8.4 Relational Algebra
  
#### Operations and Expressions
- 9 Operations (Operation | Symbol):
1. Select is $\sigma$
2. Project is $\Pi$
3. Product is $x$
4. Join is $\Join$
5. Union is $\bigcup$
6. Intersect is $\bigcap$
7. Difference is $-$
8. Rename is $\rho$
9. Aggregate is $\gamma$
- Additional operators may include assign or divide which are just variations of the join operation inner join, full join, equijoin
- Query optimizers use these to optimize queries