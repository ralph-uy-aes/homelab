# Relational Databases - Keys and Constraints

## 4.1 Primary Keys

#### Primary Keys
- A column or group of columns used to identify a row
- A primary key must be unique and never NULL
- Identifies exactly one row
- A bullet indicates primary keys in table diagrams

#### Composite Primary Keys
- Single primary key - only one column used to uniquely identify all rows
- Composite primary key - multiple columns to uniquely identify all rows
- A composite primary key must be:
1. Unique - all values of primary key columns when grouped together must be unique
2. Not NULL - no column must contain a NULL value
3. Minimal - ideally, you want to minimize the primary keys so no redundant keys that, once removed, still maintains the uniqueness of the composite

#### PRIMARY KEY Constraint
- A constraint used in `CREATE TABLE` that labels the primary key
- Ensures that the column or group of columns is unique and never null
- Written after every column as `PRIMARY KEY (Column)`

#### Auto-Increment Columns
- An integer column that is automatically assigned when a new row is inserted
- Specified after a column and its datatype with `AUTO_INCREMENT` keyword inside the `CREATE TABLE` statement
- In MySQL, an auto-increment column must:
1. Appear only once in each table
2. Not have a default value
3. Have an integer data type
4. Have an index


## 4.2 Foreign Keys

#### Foreign Keys
- A column or group of columns that refer to a primary key in another table
- Data types between foreign and primary keys must be the same, but the column names may be different
- For example, a table of employees has a primary key called ID. Another table called Department has a column called "Manager" which refers to the ID column of the Employee table.
- Can be NULL and not unique, but anything that is non-NULL must refer to an existing primary key in the other table

#### Composite Foreign Keys
- A foreign key that refers to a composite primary key must also be composite
- Think about it, if two primary keys must uniquely determine a row in one table, you must also need those two keys in another table to 
identify who you're referring to in the original table

#### Special Cases
- Multiple foreign keys may refer to the same primary key
- A foreign key may refer to the primary key of the same table
- For example, in the employee table, there might be a Manager column that refers to an employee in the same table, after all your manager is also an employee in the table
- Or between a department and employee table, there may be Manager1 and Manager2 columns inside the department database that refer to different primary keys for different employees in the employee table

#### Foreign Key Constraint
- A foreign key constraint is part of the `CREATE TABLE` statement
- Consists of `FOREIGN KEY (Column)` and `REFERENCES <table name> (Column)`
- Usually at the end of the `CREATE TABLE` statement
- Database system ensures that non-NULL foreign key values match a value of the referenced primary key


## 4.3 Referential Integrity

#### Referential Integrity Rule
- A relational rule that requires foreign key values are either fully NULL or match some primary key value
- Foreign keys must obey referential integrity at all times

#### Partially NULL Foreign Keys
- A composite foreign key value is partially NULL if some, but not all, columns are NULL
- These are violations of referential integrity rule

#### Referential Integrity Violations
- Can be violated in four ways:
1. A primary key is updated
2. A foreign key is updated
3. A row containing a primary key is deleted
4. A row containing a foreign key is inserted
- Emphasis on can, doesn't mean will be violated

#### Referential Integrity Actions
- Databases automatically correct referential integrity violations with any of four actions as SQL constraints:
1. `RESTRICT` - rejects an insert, update, or delete that violates referential integrity.
2. `SET NULL` - sets invalid foreign keys to NULL
3. `SET DEFAULT` sets invalid foreign keys to the foreign key default value
4. `CASCADE` - propagates primary key changes to foreign keys, meaning even a delete of a primary key row deletes all foreign keys rows referring to it

#### ON UPDATE and ON DELETE Clauses
- MySQL only supports RESTRICT for foreign key updates and inserts
- MySQL supports all four actions and are specified using `ON UPDATE` and `ON DELETE`
- Limitations:
1. `RESTRICT` is applied when `ON UPDATE` and `ON DELETE` are omitted
2. `SET NULL` can't be used when a foreign key is not allowed NULL values
3. `SET DEFAULT` is not supported in some MySQL configs
- Ex.
```
CREATE TABLE xxx(
    ...
    PRIMARY KEY (Code)
    FOREIGN KEY (ManagerID) REFERENCES Employee(ID)
        ON UPDATE SET NULL
        ON DELETE CASCADE
);
```

## 4.4 Constraints

#### Column and Table Constraints
- A constraint governs rules regarding allowable values in a database
- Based on relational and business rules
- Implemented with special keywords inside `CREATE TABLE`
- A column constraint appears after the column name and data type definition
    - They govern values in a single column
- A table constraint appears in a separate clause, is often found at the end of the `CREATE TABLE` statement and governs values in one or more columns
- Some Constraints:
1. `NOT NULL`
2. `DEFAULT`
3. `PRIMARY KEY`
4. `FOREIGN KEY`

#### UNIQUE Constraint
- Ensures that values in a column or group of columns are unique
- When applied to a single column, `UNIQUE` may appear either in a column declaration or a separate clause (encompassing multiple columns)
    - Just ensures that the combination of the two is a unique combination, not necessarily that one or the other must be unique

#### CHECK Constraint
- Specifies an expression on one or more columns of a table
- Can be specified at the end to be a table constraint see second example
- Violated when the expression is FALSE
- Ex. `Age INT CHECK(Age > 18)` or `CHECK (BirthDate > HireDate)`

#### Constraint Names
- Table constraints can be named with `CONSTRAINT <name> <declaration>`
- Most column constraints cannot be named, but the `CHECK` is an exception as well as `PRIMARY KEY` and `FOREIGN KEY`

#### Adding and Dropping Constraints
- You can use the `ADD`, `CHANGE`, or `DROP` clauses to modify constraints
- Syntax Ex:
    - `CHANGE CurrColName NewColName NewDataType [Constraint]`
    - `ADD [CONSTRAINT ConstraintName] PRIMARY KEY (Col1, Col2, ...)`
    - `ADD [CONSTRAINT ConstraintName] FOREIGN KEY (Col1, Col2, ...) REFERENCES TableName (Col)`
    - `ADD [CONSTRAINT ConstraintName] UNIQUE (Col1, Col2, ...)`
    - `ADD [CONSTRAINT ConstraintName] CHECK (Expression)`
    - `DROP PRIMARY KEY`
    - `DROP FOREIGN KEY ConstraintName`
    - `DROP INDEX ConstraintName` (drops `UNIQUE`)
    - `DROP CHECK ConstraintName`
    - `DROP CONSTRAINT ConstraintName`
- Dropping a table fails whenever a foreign key constraint refers to the table's primary key. Before dropping the table, drop either foreign key constraint or foreign key table.