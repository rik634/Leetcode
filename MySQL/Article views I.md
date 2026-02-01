## Problem statement
- Table: Views

<img width="315" height="214" alt="image" src="https://github.com/user-attachments/assets/c2271d5d-b842-4f14-92d5-af4e59f4a7fc" />

There is no primary key (column with unique values) for this table, the table may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.

- Write a solution to find all the authors that viewed at least one of their own articles.
- Return the result table sorted by id in ascending order.

### Logic
We need to:
 - Identify rows where the author viewed their own article: author_id = viewer_id
 - Extract unique author_ids from these rows (remove duplicates)
 - Sort the result in ascending order by id
 - Return only the id column

### Solution
```mysql
SELECT DISTINCT 
    author_id AS id
FROM 
    Views
WHERE 
    author_id = viewer_id
ORDER BY 
    id;
```
