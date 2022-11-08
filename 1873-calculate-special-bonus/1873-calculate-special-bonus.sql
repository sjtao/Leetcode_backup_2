# Write your MySQL query statement below
SELECT employee_id,
    IF(employee_id % 2 <> 1 OR name LIKE 'M%', 0, salary) AS bonus
FROM Employees
ORDER BY employee_id;