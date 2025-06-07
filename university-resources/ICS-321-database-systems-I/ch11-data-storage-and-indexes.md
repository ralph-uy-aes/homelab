# Data Storage and Indices

## 11.1 Storage Media

#### Storage Media
- Different storage media is used to store data like RAM, magnetic disk, optical disk, and magnetic tape
- Four different specs:
    1. Speed
        - Access Time - time required to access the first byte in read or write
        - Transfer Rate - speed at which data is read or written after initial access
    2. Cost
    3. Capacity
    4. Volatility
        - Volatile Memory - memory lost when disconnected from power
        - Non-volatile Memory - retained without power
- Media for databases:
    1. Main Memory
        - Also known as RAM
        - Primary memory used when programs execute
        - Fast, expensive, small capacity
        - Volatile
    2. Flash Memory
        - Also known as SSD
        - Less expensive, higher capacity compared to RAM
        - Writes are much slower than reads
        - Much slower for read and write than RAM
        - Non-volatile
    3. Magnetic Disk
        - Also known as HDD
        - Slower, less expensive, and higher capacity than SSD
        - Non-volatile
    - Store data permanently on flash and magnetic disks, transferring to main memory during execution

#### Sectors, Pages, and Blocks
- Magnetic disk groups data in sectors, 512 bytes per sector but 4 kilobytes in newer disk formats
- Flash memory groups data in pages, between 2 to 16 kilobytes per page
- Databases and file systems use a uniform size called a block
    - Used when transferring data between main memory and storage media
    - Block size does not depend on storage media type
    - Controller manager conversion between blocks and other groups, so database is unaware of page and sector sizes
- Smaller blocks are better for transactional applications
- Larger blocks are better for analytic applications

#### Row-oriented Storage
- Accessing storage media is slow
- Databases attempt to minimize the number of blocks transferred for common queries
- Most relational databases are optimized for transactional applications which often read and write individual rows
- Rows are stored within one block, called row-oriented storage
    - Improves query performance
    - Less wasted storage

#### Column-oriented Storage
- Optimal for analytical applications
- Each block stores values for a single column only
    - Faster data access
    - Better data compression
- Reading or writing an entire row requires accessing multiple blocks, poor design for transactional application


## 11.2 Table Structures

#### Heap Table
- A scheme for organizing rows in blocks on storage media
- Databases support four alternative table structures:
    - Heap Table
    - Sorted Table
    - Hash Table
    - Table Cluster
- In a heap table, no order is imposed on rows
    - Database maintains a list of blocks assigned to the table and the address of the first available space for inserts
    - If blocks are full, a new block is allocated for inserts
- When a row is deleted, the space previously occupied is marked as free
- Free space is tracked as a linked list
    - Inserts are stored in the first space in the list
    - Head of the list is set to the next space
- Heap tables optimize insert operations
    - Good for a bulk load of many rows
    - Not optimal for queries that read rows in a specific order

#### Sorted Table
- Database designer identifies a sort column that determines physical row order
- Sort column is usually the primary key, but can be anything
- Optimal for queries that read data in order of the sort column
    - `JOIN` on the sort column
    - `SELECT` with range of sort column values in the `WHERE` clause
    - `SELECT` with `ORDER BY` the sort column
- Slow because new inserts can update everything else
    - Change two address values rather than move entire rows
    - When an attempt is made to insert a row into a full block, the block splits in two to create space for the insert
- Optimized for read queries, slow for insert and update operations

#### Hash Table
- Rows are assigned to buckets
    - Buckets are blocks or groups of blocks containing rows
    - Each bucket initially has one block, but can fill up with rows
    - Buckets become a chain of linked blocks
- Hash function and hash keys are used to determine each bucket
    - Hash keys are columns or groups of columns, usually the primary key
    - Hash function computes the bucket containing the row from the hash key
- Hash function - modulo function
    1. Convert hash key by interpreting the key's bits as an integer value
    2. Divide the integer by the number of buckets
    3. Interpret the division remainder as the bucket number
    4. Convert the bucket number to the physical address of the block containing the row
    - The number of buckets determine the module function (5 buckets is mod 5)
- Dynamic hash functions automatically allocate more blocks to the table, create additional buckets, and distribute rows across all buckets
- Optimal for inserts and deletes of individual rows
- Also optimal for row locations using hash key
- Slow on queries that select many rows with a range of values since rows are randomly distributed

#### Table Clusters
- Also known as multi-tables
- Rows of two or more tables interleaved in the same storage area
- Have cluster keys which is a column that is available in all tables
    - Determine the order in which rows are interleaved 
- Optimal when joining interleaved tables on the cluster key
- Perform poorly for many other queries


## 11.3 Single-level Indices

#### Single-level Indices
- A file containing column values along with pointers to rows containing the column value
- Identifies the block containing the row
- Pointer also identifies the exact location of the row within the block
- Created by database designers with the `CREATE INDEX` command
- Normally sorted on the column value
- Sorted index is not the same as the indices in a sorted table
- An index can be defined by multiple columns called a multi-column index
    - Each index entry is a composite of values from all indexed columns

#### Query Processing
- Table scan - database operation that reads table blocks directly without accessing an index
- Index scan - reads index blocks sequentially in order to locate the needed table blocks
- Hit ratio
    - Also known as filter factor or selectivity
    - Percentage of table rows selected by a query
- Index scans are faster than table scans

#### Primary and Secondary Indices
- Primary index - clustering index, an index on a sort column
- Secondary index - non-clustering, an index not on a sort column
- Dense index - contains an entry for every table row
- Sparse index - contains an entry for every table block

#### Inserts, Updates, Deletes
- Insert - whenever a row is inserted, a new index entry is created
- Update - update to an indexed column is like a delete followed by an insert
- Delete - row's index entry is deleted


## 11.4 Multi-level Indices

#### Multi-level Indices
- Stores column values and row pointers in a hierarchy
- Bottom level of hierarchy is a sorted single-level index
    - Sparse for primary indices or dense for secondary indices

#### Number of Levels
- A dense index has more bottom-level entries than a sparse index and may have more levels
- Assuming a table with 10 million rows and 400 index entries per block, a dense index has 3 levels
    - Level 3 is dense and has 25,000 blocks
    - Level 2 is sparse and has 63 blocks
    - Level 1 is sparse and has one block containing 63 index entries
- The number of index entries per block is called the fan-out of a multi-level index
- The number of levels in a multi-level index can be computed from fan-out, number of rows, and rows per block
    - Dense index number = $log_{fan-out} (number of rows)$
    - Sparse index number = $log_{fan-out} (\frac{number of rows}{rows per block})$

#### Query Processing
- Multi-level indices are faster than single-level indices on most queries
- Searches read one index block per level
- Databases use multi-level more than single-level

#### Calculations
- Number of blocks read in query processing
    - Table scan = $\frac{number of rows}{rows per table block}$
    - Single-level index scan = $number of index blocks + referenced table blocks$
    - Single-level index binary search = $log_2 (number of index blocks) + referenced table blocks$
    - Multi-level dense index search = $log_{fan-out} (number of rows) + referenced table blocks$
    - Multi-level sparse index search = $log_{fan-out} (frac{number of rows}{rows per table block}) + referenced table blocks$

#### Balanced Indices
- Each path from the top-level block to the bottom is called a branch
- Multi-level indices are called balanced when all branches are the same length and imbalanced if not
- Longer branches tend to be slower, so inserts maintain balanced indices

#### B-tree and B+tree Indices
- B+tree - all indexed values appear in the bottom level, pointers to table blocks appear only in the bottom level
- B-tree - if an indexed value appears in a higher level, the value is not repeated at lower levels


## 11.5 Other Indices

#### Hash Indices
- Index entries are assigned to buckets
- Uses hash function
    1. Applies the hash function to the column value to compute a bucket number
    2. Reads the index blocks for the bucket number
    3. Finds the index entry for the column value and reads the table block pointer
    4. Read the table block containing the row

#### Bitmap Indices
- A bitmap index is a grid of bits
    - Each index row corresponds to a unique table row 
    - Each index column corresponds to a distinct table value
- To locate rows database does:
    1. Determine the index column corresponding to the table value
    2. Read index column and find index rows set to one
    3. Determine table rows corresponding to index rows
    4. Determine pointers to blocks containing the table rows
    5. Read blocks containing the table rows

#### Logical Indices
- Single or multi level index in which pointers to table blocks are replaced with primary key values
- To locate a row database does:
    1. Looks up column value in the logical index to find primary key value
    2. Looks up primary key value in primary index to find the table block pointer
    3. Reads table block containing the row

#### Function Indices
- Database designer specifies a function on the column value
- Index entries contain the result of the function applied to column values, rather than the column values


## 11.6 Tablespaces and Partitions

#### Tablespaces
- Supported by most databases, but are not specified in the SQL standard
- A database object that maps one or more tables to a single file
- `CREATE TABLESPACE` statement names a tablespace and assigns the tablespace to a file
- `CREATE TABLE` statement assigns a table to a tablespace
- By default each table automatically has one table space
- Admins can assign one or more tables per tablespace
- Databases perform better with a single table per tablespace as opposed to multiple
- Ex.
    ```
    CREATE TABLESPACE Tablespace
    ADD DATAFILE 'C:/.../'

    CREATE TABLE Sample(
        ...
    )
    TABLESPACE Tablespace;
    ```

#### Partitions
- Subset of table data
- Horizontal partition - subset of table rows
- Vertical partition - subset of table columns
- Each partition is stored in a separate tablespace
- Partitions improve query performance by reducing amount of data accessed by database operations
- 3 Types
    1. Range - Associates each partition with a range of partition expression values, uses `VALUES LESS THAN` and `MAXVALUE` keywords
    2. List - Associates each partition with an explicit list of partition expression values using the `VALUES IN` keywords
    3. Hash - Requires a partition expression with positive integer values, specifies the number of partitions and partitions are automatically named $p_0$ to $p_{N-1}$
- Ex.
    ```
    CREATE TABLE TableName(
        ColumnName ColumnDefinition, ...
    )
    [PARTITION BY
        {   RANGE (Expression) | LIST (Expression) | HASH (Expression)  }
        [   PARTITIONS NumberOfPartitions   ]
        [   (PartitionDefinition, ...)  ]
    ];

    PartitionDefinition:
    PARTITION PartitionName
        [VALUES
        {LESS THAN {Expression} | MAXVALUE} | IN (Value, ...)]
        [TABLESPACE TablespaceName]
    ```