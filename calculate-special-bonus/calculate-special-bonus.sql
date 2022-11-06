# Write your MySQL query statement below
# The bonus of an employee is 100% of their salary if the ID of the employee is an odd number and the employee name does not start with the character 'M'

SELECT employee_id, 
    IF(employee_id % 2 = 1 && name NOT LIKE 'M%', salary, 0) AS bonus
FROM Employees
ORDER BY employee_id;
