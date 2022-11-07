# Write your MySQL query statement below
SELECT user_id AS buyer_id,
    join_date,
    COUNT(order_date) AS orders_in_2019
FROM Users
LEFT JOIN Orders ON Users.user_id = Orders.buyer_id
AND YEAR(order_date) = '2019'
GROUP BY user_id;