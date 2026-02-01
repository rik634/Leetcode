## Problem statement
- Table: Tweets
<img width="333" height="155" alt="image" src="https://github.com/user-attachments/assets/0ccf1c9a-41f8-4b40-9011-3a670bd0a309" />

tweet_id is the primary key (column with unique values) for this table.
content consists of alphanumeric characters, '!', or ' ' and no other special characters.
This table contains all the tweets in a social media app

- Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.
- Return the result table in any order.

### Solution
```mysql
select tweet_id from Tweets where length(content)>15
```
