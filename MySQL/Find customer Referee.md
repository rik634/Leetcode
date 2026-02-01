## Problem statement
- Table: Customer

<img width="304" height="190" alt="image" src="https://github.com/user-attachments/assets/e7f52491-86af-4703-a957-32f8e84368ed" />

In SQL, id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
- Find the names of the customer that are either:
  1. referred by any customer with id != 2.
  2. not referred by any customer.
-Return the result table in any order.


### Logic
- MySQL uses three-valued logic -- TRUE, FALSE and UNKNOWN. Anything compared to NULL evaluates to the third value: UNKNOWN.
- That “anything” includes NULL itself! That’s why MySQL provides the IS NULL and IS NOT NULL operators to specifically check for NULL.
- Thus, one more condition 'referee_id IS NULL' should be added to the WHERE clause
-  The key is to always use IS NULL or IS NOT NULL operators to specifically check for NULL value.

### Solution
```mysql
SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;
```

OR
```mysql
SELECT name FROM customer WHERE referee_id <> 2 OR referee_id IS NULL;
```
