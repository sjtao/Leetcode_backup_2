# Write your MySQL query statement below
# The bonus of an employee is 100% of their salary if the ID of the employee is an odd number and the employee name does not start with the character 'M'

SELECT employee_id,
    CASE
        WHEN employee_id % 2 = 1 AND name NOT LIKE 'M%' THEN salary
        ELSE 0
    END AS bonus
FROM Employees
ORDER BY employee_id;
