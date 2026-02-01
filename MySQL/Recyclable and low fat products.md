## Problem statement
- Table: Products
<img width="321" height="204" alt="image" src="https://github.com/user-attachments/assets/828e891f-ecbf-4f30-b213-9773a8d3cd98" />

product_id is the primary key (column with unique values) for this table.
low_fats is an ENUM (category) of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
recyclable is an ENUM (category) of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
 
- Write a solution to find the ids of products that are both low fat and recyclable.
- Return the result table in any order.

### Solution
```mysql
SELECT
    product_id
FROM
    Products
WHERE
    low_fats = 'Y' AND recyclable = 'Y'
```

 
