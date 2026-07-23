# Course 4 – Module 4: Databases and SQL

---

## SQL vs Linux Filtering

| Feature | SQL | Linux |
|---------|-----|-------|
| **Purpose** | Query structured data in databases. | Manage files, directories, and processes. |
| **Syntax** | Standardized keywords (SELECT, WHERE, JOIN). | Varies by command (grep, find, etc.). |
| **Structure** | Data organized in tables with columns/rows. | Data often unstructured text. |
| **Joining** | Can join multiple tables. | Cannot connect data across files. |
| **Best use** | Structured logs, employee records, login data. | Text files, system logs, file permissions. |

- Access SQL from Linux command line (e.g., `sqlite3`).

---

## Basic SQL Queries

### Essential Keywords

| Keyword | Purpose |
|---------|---------|
| `SELECT` | Specify which columns to return. |
| `FROM` | Specify which table to query. |
| `ORDER BY` | Sort results (ascending by default, use `DESC` for descending). |

### Examples
```sql
SELECT device_id, operating_system FROM machines;
SELECT * FROM employees ORDER BY last_name;
SELECT * FROM log_in_attempts ORDER BY login_date, login_time;
```

### Wildcards and Pattern Filtering

| Pattern | Meaning |
|---------|---------|
| `'a%'` | Starts with "a". |
| `'%a'` | Ends with "a". |
| `'%a%'` | Contains "a". |
| `'a_'` | Starts with "a", followed by one character. |
| `'a__'` | Starts with "a", followed by two characters. |

- Use `LIKE` instead of `=` with wildcards.  
  *Example:* `WHERE office LIKE 'South%'`

---

## Filtering with WHERE

### Comparison Operators

| Operator | Meaning |
|----------|---------|
| `=` | Equal to |
| `<` | Less than |
| `>` | Greater than |
| `<=` | Less than or equal to |
| `>=` | Greater than or equal to |
| `<>` or `!=` | Not equal to |

### Logical Operators

| Operator | Purpose |
|----------|---------|
| `AND` | Both conditions must be true. |
| `OR` | At least one condition must be true. |
| `NOT` | Negates a condition. |

### Examples
```sql
-- Failed attempts after 18:00
SELECT * FROM log_in_attempts 
WHERE success = 0 AND login_time > '18:00';

-- Attempts on May 8 or 9, 2022
SELECT * FROM log_in_attempts 
WHERE login_date = '2022-05-08' OR login_date = '2022-05-09';

-- Attempts not from Mexico
SELECT * FROM log_in_attempts 
WHERE NOT country LIKE 'MEX%';
```

### Date/Time Filtering

| Operator | Meaning |
|----------|---------|
| `BETWEEN` | Inclusive range (e.g., dates, numbers). |
| `>` / `<` | Exclusive (does not include the boundary). |
| `>=` / `<=` | Inclusive (includes the boundary). |

*Example:*  
```sql
SELECT * FROM log_in_attempts 
WHERE login_date BETWEEN '2023-02-01' AND '2023-02-07';
```

---

## SQL Joins

Joins combine tables using a common column (foreign key → primary key).

### Join Types

| Join | Returns |
|------|---------|
| **INNER JOIN** | Only rows with matching values in both tables. |
| **LEFT JOIN** | All rows from left table + matches from right table (NULL if no match). |
| **RIGHT JOIN** | All rows from right table + matches from left table (NULL if no match). |
| **FULL OUTER JOIN** | All rows from both tables (not supported in all SQL versions). |

### Syntax
```sql
-- INNER JOIN
SELECT * FROM machines 
INNER JOIN employees ON machines.device_id = employees.device_id;

-- LEFT JOIN (keep all machines)
SELECT * FROM machines 
LEFT JOIN employees ON machines.device_id = employees.device_id;

-- RIGHT JOIN (keep all employees)
SELECT * FROM machines 
RIGHT JOIN employees ON machines.device_id = employees.device_id;
```

### Dot Notation
- Use `table.column` to avoid ambiguity when columns have the same name in both tables (e.g., `machines.device_id`).

---

## Aggregate Functions

| Function | Purpose |
|----------|---------|
| `COUNT` | Number of rows. |
| `AVG` | Average of numeric values. |
| `SUM` | Sum of numeric values. |

*Example:*
```sql
SELECT COUNT(*) FROM customers WHERE country = 'USA';
```

---

## Module 4 Glossary

- **Database** – Organized collection of data.
- **Date and time data** – Data representing a date/time.
- **Exclusive operator** – Does not include the comparison value (e.g., `<`, `>`).
- **Filtering** – Selecting data that match a condition.
- **Foreign key** – Column in one table that is a primary key in another.
- **Inclusive operator** – Includes the comparison value (e.g., `<=`, `>=`, `BETWEEN`).
- **Log** – Record of events within systems.
- **Numeric data** – Data consisting of numbers.
- **Operator** – Symbol or keyword representing an operation.
- **Primary key** – Column with a unique entry for every row.
- **Query** – Request for data from a database.
- **Relational database** – Structured database with related tables.
- **SQL** – Language for creating, interacting with, and querying databases.
- **String data** – Ordered sequence of characters.
- **Syntax** – Rules for correctly structured code.
- **Wildcard** – Special character that substitutes for other characters (`%`, `_`).