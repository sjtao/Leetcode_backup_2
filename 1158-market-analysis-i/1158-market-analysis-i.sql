# Write your MySQL query statement below
# Write an SQL query to find for each user, the join date and the number of orders they made as a buyer in 2019

SELECT user_id as buyer_id, 
    join_date,
    count(order_date) as orders_in_2019
FROM Users
LEFT JOIN Orders ON Users.user_id = Orders.buyer_id
AND YEAR(order_date) = '2019'
GROUP BY user_id;