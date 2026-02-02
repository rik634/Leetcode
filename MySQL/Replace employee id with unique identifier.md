## Problem statement
- Table: Employees
<img width="335" height="160" alt="image" src="https://github.com/user-attachments/assets/0d0971b4-5d61-442f-8df7-c8e1d07d9515" />

id is the primary key (column with unique values) for this table.
Each row of this table contains the id and the name of an employee in a company.

-Table: EmployeeUNI
<img width="322" height="164" alt="image" src="https://github.com/user-attachments/assets/7419612e-9c1f-4529-8b12-2e1c0e0c172e" />

(id, unique_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table contains the id and the corresponding unique id of an employee in the company.

- Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.
- Return the result table in any order.

### Solution
```mysql
SELECT euni.unique_id, e.name 
FROM Employees e  
LEFT JOIN EmployeeUNI euni  
ON e.id = euni.id;
```
