# Write your MySQL query statement below
SELECT user_id,
       CONCAT(UPPER(SUBSTR(name, 1, 1)), LOWER(SUBSTR(NAME, 2))) AS name
FROM Users
ORDER BY user_id;