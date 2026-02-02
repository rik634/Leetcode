## Problem statement
- Table: Sales
<img width="271" height="238" alt="image" src="https://github.com/user-attachments/assets/14564e41-7b14-4f1c-8377-c0a2a3e92d5c" />

(sale_id, year) is the primary key (combination of columns with unique values) of this table.
product_id is a foreign key (reference column) to Product table.
Each row of this table shows a sale on the product product_id in a certain year.
Note that the price is per unit.

- Table: Product
<img width="315" height="167" alt="image" src="https://github.com/user-attachments/assets/779ee48c-3f25-4a83-b98a-c18e45031e9f" />

product_id is the primary key (column with unique values) of this table.
Each row of this table indicates the product name of each product.

- Write a solution to report the product_name, year, and price for each sale_id in the Sales table.
- Return the resulting table in any order.

### Solution
```mysql
select p.product_name,s.year,s.price from Sales s left join Product p on s.product_id=p.product_id;
```
