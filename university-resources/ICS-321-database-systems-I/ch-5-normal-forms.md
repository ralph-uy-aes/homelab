# Normal Forms

## 5.1 First, second, and third normal form

#### Functional Dependence
- Column A depends on Column B, each B value is related to at most one A value
- A depends on B is denoted as $B\rightarrow A$
- Dependence of one column on another is called functional dependence

#### Normal Forms
- Redundancy is the repetition of related values in a table
- May cause database management problems if related values are updated
    - Changing all copies will make queries slow and complex
    - If not updated, copies become inconsistent and correct version is uncertain
- Normal Forms are rules for designing tables with less redundancy. Numbered one through five, and a sixth Boye-Codd (improvement on normal form 3)
- Each successive normal form reduces redundancy, the fifth has none
- Redundancy is whenever a dependence lies in a non-unique column. 
    - A primary key can never be redundant by definition
    - Two values where one depends on another value that is repeated is also repeated, causing redundancy in both columns
    - Ex. If you have a passenger numbered 222 and a name "Joe", the PassengerName column depends on the PassengerNumber column. PassengerNumber is not unique.
- Boye-Codd normal form eliminates all dependencies on non-unique columns and is the most important normal form in practice
- The fourth and fifth normal forms eliminate multi-valued and join dependencies which are complex and uncommon, so the fourth and fifth are more theoretical

#### First Normal Form
- Every cell contains exactly one value
- The table has a primary key
- Every non-key column depends on the primary key
- The table has no duplicate rows

#### Second Normal Form
- Every non-key column depends on the whole primary key
    - Non-key columns cannot depend on part of a composite primary key
- A table in second normal form is also in first normal form
- Ex. PassengerName depends on PassengerNumber, but not FlightCode. To convert this to second normal form, remove PassengerName. Every other non-key column depends on the entire composite primary key. Move PassengerNumber and PassengerName dependence into another table if you need.
- To identify non-dependence on composite primary key, check column values and if two distinct composite keys output the same value in that column, the table is not in second normal form

#### Third Normal Form
- Non-key columns depend on the key, the whole key, and nothing but the key
- Redundancy occurs in a second normal form table when a non-key column depends on another non-key column
- A third normal form table is also second and first normal form
- To identify this, compare two non-key columns and see if they rely on each other and not just the composite or simple primary key
- Ex. If a GradeLetter column depends on GradeNumber like B corresponds to an 88 and B also corresponds to 87, then GradeLetter depends on GradeNumber. These are not primary key columns, which is a redundancy in second normal form. Separate them into two tables each being only dependent on the composite or simple primary key to get the table into third normal form.


## 5.2 Boyce-Codd Normal Form

#### Redundancy and Dependence
- All dependencies are on unique columns
    - Dependence on a unique column never creates redundancy, so Boye-Codd Normal Form eliminates all redundancy arising from functional dependence

#### Third Normal Form
- A candidate key is a simple or composite column that is unique and minimal (all columns are necessary for uniqueness)
    - A table may have multiple candidate keys, but one is designated as the primary key
- A non-key column is a column not contained in a candidate key
- Whenever a non-key column A depends on B and B is unique, the table is in third normal form

#### Boyce-Codd Normal Form
- Applies to all columns and eliminates redundancy, unlike third normal form which only applies to non-key columns
- If column A depends on B, B is unique and both may be simple or composite
- The gold standard of table design
- Ex. TaskName column depends on EmployeeID and ProjectName columns and ProjectName column depends on EmployeeID column. ProjectName and EmployeeID is a composite candidate key, so they're unique, but TaskName is a non-key column and isn't unique. This makes it so that for duplicate ProjectName values, TaskName values may also be duplicated. This is in third normal form because the candidate keys are unique, but Boyce-Codd wants everything to be unique. Put EmployeeID and ProjectName into one table and TaskName and ProjectName into another, thereby making everything unique and in Boyce-Codd normal form.

#### Trivial Dependencies
- When the columns of A are a subset of the columns of B, the dependency is called trivial
- Technically, these must be excluded in definitions of normal form: A table is in Boyce-Codd normal form if, for all non-trivial dependencies B $\rightarrow$ A, B is unique


## 5.3 Applying Normal Form

#### Normalization
- The last step of logical design
- Eliminates redundancy by decomposing a table into two or more tables in a higher normal form
- Usually use Boyce-Codd normal form process:
1. List all unique columns, simple or composite (remove non-unique ones)
2. Identify dependencies on non-unique columns
3. Eliminate dependencies on non-unique columns (put them in a new table)
- No information is lost

#### Denormalization
- Redundancy is usually only a big deal in tables that frequently insert, update, or delete
    - Tables that don't do those too often and have redundancy is acceptable
    - Sometimes, redundancy can be desirable with faster and simpler queries for database reports
- Denormalization is the process of introducing redundancy by merging tables
    - Eliminates join queries and improves query performance
    - Results in first and second normal form tables

#### Database Design
- Database designer reviews each table for Boyce-Codd normal form
- If any dependencies are not on unique columns, table is decomposed into smaller tables to be in Boyce-Codd normal form
- Steps:
    - 8A: Identify dependencies in non-unique columns
    - 8B: Eliminate redundancies by decomposing tables
    - 8C: Consider denormalizing tables in reporting databases