# Structured Query Language - Aggregate Functions

## 6.1 Special Operators and Clauses

#### IN Operator
- Used with a `WHERE` clause to determine if a value is one of several values within parentheses
- Ex. 
```
SELECT * FROM Countries
WHERE Language IN ('Dutch', 'Kongo', 'English');
```
#### BETWEEN Operator
- Provides an alternative way to determine if a value is between two other values, kind of like a range in python
- Inclusive (<= and >=)
- Works for CHAR, VARCHAR
- Ex.
```
SELECT * FROM Numbers
WHERE Value BETWEEN 69 AND 420
```

#### LIKE Operator
- Matches text against a pattern using two wildcard characters: `%` and `_`
- Ex.
    - `LIKE L_t` - matches 'Lot', 'Lit', but not 'Loft'
    - `LIKE L%t` - matches everything as long as L and t are the start and end
- Case sensitive if you write `LIKE BINARY 'xxx'` `BINARY` makes it case-sensitive
- Use backslash to find characters like '%' and '_'
- RegEx (T-T) is used for matching

#### DISTINCT Operator
- Appended to `SELECT` like `SELECT DISTINCT` to only return unique values
- Ex.
```
SELECT Language
FROM CountryLanguage
WHERE IsOfficial = 'F';
```

#### ORDER BY Clause
- Put into a `SELECT` statement (before semicolon) to order selections by ascending order, or append by `DESC` to make it descending
- Can use more than one column to order (first columns take precedence in ordering)
- Ex.
```
SELECT Name, District, Population 
FROM City 
ORDER BY District, Population;
```


## 6.2 Simple Functions

#### Numeric Functions
- Functions are basically argument, code, return
    - Same as literally most languages
- Common Functions:
    - ABS(n)
    - LOG(n)
    - POW(x,y)
    - RAND()
    - ROUND(n,d)
    - SQRT(n)

#### String Functions
- Common Functions:
    - CONCAT(s1, s2)
    - UPPER(s)
    - LOWER(s)
    - REPLACE(s, from, to) - replace string "from" to new string in string s
    - SUBSTRING(s, pos, len)
    - TRIM(s) - remove leading and trailing spaces

#### Date and Time Functions
- Common Functions:
    - CURDATE(), CURTIME(), NOW()
    - DATE(expr), TIME(expr) - extracts either DATE or TIME from DATETIME
    - DAY(d), MONTH(d), YEAR(d) - extracts either of 3 from DATE
    - HOUR(t), MINUTE(t), SECOND(t) - extracts either of 3 from TIME
    - DATEDIFF(d1, d2), TIMEDIFF(t1, t2)


## 6.3 Aggregate Functions

#### Aggregate Functions
- Values are processed from a set of rows and return a summary value
- Common Functions:
    - COUNT()
    - MAX()
    - MIN()
    - SUM()
    - AVG()

#### GROUP By Clause
- Useful for tables with non-unique columns like Profession, Age, etc...
- Arguments can be one or more columns
- Typically appears between WHERE and ORDER BY
- Ex.
```
SELECT CountryCode, SUM(Population) FROM City
GROUP BY CountryCode;
```

#### HAVING Clause
- Used with `GROUP BY` to filter group results
- Follows `GROUP BY` in clause order
- Ex.
```
SELECT CountryCode, SUM(Population) FROM City
GROUP BY CountryCode
HAVING SUM(Population) > 1000
```

#### NULL Values
- Aggregate functions ignore NULL values
- Arithmetic operators return NULL when it is an operand, but Aggregate functions may generate different values depending on the arguments given to them
- Ex. `SUM(Salary) + SUM(Bonus)` is not the same as `SUM(Salary + Bonus)` if either Bonus or Salary is NULL