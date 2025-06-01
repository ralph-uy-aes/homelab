# Transaction Management

## 10.1 Transactions

#### Transactions
- Sequence of database operations that must either be completed or rejected entirely
- Ex. If you wire transfer $100 into your friend's bank, it sends, but isn't received, the $100 is lost
- Saving complete transaction results is called a commit, while rejecting it is called a rollback

#### ACID Properties
- Transactions must be atomic, consistent, isolated, and durable
- Atomic - either all or none of the operations are executed and applied
- Consistent - all rules governing data are valid when transactions are committed
- Isolated - transactions are processed without interference from other transactions
- Durable - transaction is permanently saved in the database once committed, regardless of system failure
- Concurrency System: Isolated -> Consistent -> Supporting, but not Durable
- Recovery System: Atomic -> Durable -> Isolated -> Consistent

#### Isolation
- Conflicts between two transactions can induce wrong reads like:
1. Dirty read - When a transaction commits with uncommitted values from another transaction that gets rolled back
2. Non-repeatable read - A transaction repeatedly reads changing data (unstable data)
3. Phantom read - one transaction inserts or deletes a table row while another transaction is reading


## 10.2 Schedules

#### Schedules
- A sequential order of operations in multiple transactions
- Must preserve original order of operations within each transaction
- Operations in different transactions conflict when the order of operations may affect the result
- Two operations in different transactions conflict when
    - Both operations write the same data
    - One operation reads and another writes the same data
- Equivalent schedules contain the same transactions with all conflicting operations in the same order
- Conflicting schedules contain the same transactions with some conflicting operations in different order

#### Schedules and Concurrency
- Serial schedules are schedules where transactions are executed one at a time
- No concurrent transactions, every transaction begins, executes, and commits or rolls back before the next begins
- A serializable schedule can be turned into a serial one by switching the relative order of reads

#### Isolation Levels
1. Serializable - transactions run in a serializable schedule with  concurrent transactions, guaranteed isolation
2. Repeatable Read - transactions only read committed data, after read, other transactions cannot update data, allows phantom reads
3. Read Committed - transactions only read committed data, after read, other transactions can update data, allows non-repeatable and phantom reads
4. Read Uncommitted - transactions read uncommitted data, allows dirty, 
non-repeatable, and phantom reads

#### Schedules and Recovery
- In non-recoverable schedules, one or more transactions cannot be rolled back
- In cascading schedules, rollback of one transaction forces rollback of other transactions
- In strict schedules, rollback of one transaction never forces rollback of other transactions


## 10.3 Concurrency

#### Locking
- Concurrency systems are parts of databases that manage concurrent transactions
- A Lock is a permission for one transaction to read or write data
    - Concurrent transactions are prevented from reading or writing the same data
    - A transaction takes locks when the transaction needs to read or write data
    - A transaction releases locks when the transaction is committed or no longer needs the locked data
- A shared lock allows transactions to read, but not write data
    - An exclusive lock allows a transaction to read and write data
- Lock scope is the collection of data reserved by a lock, often a single row
- The lock manager tracks, grants, and releases locks

#### Two-phase Locking
- A technique that ensures serializable transactions
- Three variations:
1. Basic - expand and contract phases for each transaction, a transaction can release but not take locks
2. Strict - holds all exclusive locks until transaction commits or rolls back
3. Rigorous - holds both shared and exclusive locks until the transaction commits or rolls back

#### Deadlock
- Group of transaction that are frozen
- No transaction can proceed
- A dependent transaction is waiting for data locked by another transaction
- A cycle of dependent transactions indicates deadlock has occurred
- Concurrency systems manage deadlock with a variety of techniques
    - Aggressive locking - each transaction runs to completion, if not it waits until other transactions releases locks
    - Data ordering - all data needed by concurrent transactions is ordered, each transaction takes locks in order
    - Timeout - when waiting for a lock exceeds a time period, the transaction requesting the lock rolls back
    - Cycle detection - periodical checks for cycles of dependent transactions


## 10.4 Recovery

#### Failure Scenarios
1. Transaction failure - results in a rollback due to logical error, insufficient storage space, hardware or software failure; all data changes are restored to original values before transaction
2. System failure - results in the loss of main memory because data is stored in memory blocks inside storage media that may survive system failure, otherwise it is lost; recovery system recovers data written to main memory, but not storage media
3. Storage media failure - occurs when database is corrupted or connection is lost, saved by redundancies like RAID5

#### Recovery Log
- A file containing a sequential record of all database operations
- Log and database are stored on different storage media, so log survives database failures
- Required for restoration after failure
- Contains four types of records:
1. Update record - indicates a transaction has changed data
2. Compensation record - also known as undo record which, indicates a data has been restored to original state after rollback
3. Transaction record - indicates a transaction boundary (temporal)
4. Checkpoint record - indicates that all data in main memory has been saved on storage media

#### Recovery from Transaction Failure
- Relatively simple, component instructs a roll back for a transaction T, the system reads the recover log backwards to search for update records for T, for each update record:
    - Restored data D to original value V in the record
    - Write a compensation record for T, D, and V to the end of the log

#### Recovery from System Failure
- Two phase process
- Redo phase restores all transactions that were committed or rolled back since the last checkpoint
- Undo phase rolls back transactions that were neither committed nor rolled back

#### Recovery from Storage Media Failure
- Availability is the percentage of time a system is working from the perspective of the system user
- Many databases require high availability like 99%
- Primary concern is availability during storage media failures
- Techniques:
    - Cold back up where checkpoints are used and transactions are paused and copied to backup media
    - Hot backup where a secondary database is nearly synced to the primary and log records are sent to and processed by the secondary while the primary processes transactions


## 10.5 Transactions with SQL

#### Isolation Levels
- Transaction statements are standardized in SQL and implemented in most relational databases
- But, concurrency and recovery systems vary a lot, so many nonstandard extensions exist
- `SET TRANSACTION` statements set the isolation level for subsequent transactions
    - Ex.
    ```
    SET [ GLOBAL | SESSION ] TRANSACTION 
    ISOLATION LEVEL [ SERIALIZABLE | REPEATABLE READ | READ COMMITTED | READ UNCOMMITTED ];
    ```
    - Keyword following `ISOLATION LEVEL` balances isolation of concurrent transactions against performance
        - `SERIALIZABLE` provides complete isolation with longer    transaction duration
        - `READ UNCOMMITTED` allows conflicts between concurrent transactions with shorter duration
    - The keyword after `SET` defines the scope of the isolation level
        - `SESSION` sets the isolation level for all transactions in the current session; a session is a series of SQL statements submitted to a MySQL server, beginning when a user or program connects to the server and ending when the user or program disconnects
        - `GLOBAL` sets the isolation level for all transactions for all subsequent sessions; existing sessions are not affected and it `GLOBAL` can only be used by a database admin with required privileges
- Sequentially, `GLOBAL` is basically default level, then whenever you put a new `SET TRANSACTION` without any keywords after `SET`, it follows that only for the next transaction, and then when you put `SESSION` it only overrides `GLOBAL` and follows that for all following transactions until a new `SET TRANSACTION`

#### Transaction Boundaries
- First or last statements of a transaction
- One of three statements
    - `START TRANSACTION` starts a new transaction
    - `COMMIT` commits the current transaction
    - `ROLLBACK` rolls back the current transaction
- The autocommit system variable does what it says
    - You can set it `ON` or `OFF` with `SET autocommit = [ OFF | ON ];`
    - On by default
- `COMMIT` and `ROLLBACK` can optionally have
    - `AND CHAIN` overrides autocommit and starts a new transaction
    - `RELEASE` ends the current section and disconnects from the server
- `BEGIN` is identical to `START TRANSACTION`, but can be easily confused with `BEGIN-END`, not recommended

#### Savepoint
- A point in a transaction where partial transaction results are saved temporarily
- Prevent redoing work in lengthy transactions
- Managed with three statements using a savepoint name for an identifier:
    - `SAVEPOINT` saves internal transaction data and associates the data with the identifier
    - `RELEASE SAVEPOINT` discards the identifier and saved data
    - `ROLLBACK TO` resets transaction data to the savepoint values, restarts processing at the savepoint, and releases all subsequent savepoints
        - `ROLLBACK` is different as it reverses all changes vs `ROLLBACK TO` which erases everything up to a savepoint
- Ex.
```
SAVEPOINT identifier;

ROLLBACK TO identifier;

RELEASE SAVEPOINT identifier;
```

#### Checkpoints
- A dirty block is a database block that has been updated in main memory, but not yet saved on storage media
    - A checkpoint saves all dirty blocks to enable recovery from system failure
        - Suspends database processing
        - Writes a checkpoint record in the log
        - Writes all unsaved log records to the log file
        - Writes all dirty blocks to storage media
- A fuzzy checkpoint resumes processing while saving dirty blocks
- Log records and dirty blocks can be explicitly flushed with `FLUSH` statements
    - `FLUSH TABLES` writes all dirty blocks to storage media
    - `FLUSH LOGS` saves all log records to storage media
- Some databases have manual checkpoints using `CHECKPOINT` keyword