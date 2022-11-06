# Write your MySQL query statement below
SELECT actor_id, director_id FROM (
    SELECT actor_id, director_id, COUNT(CONCAT(actor_id, '-', director_id)) as cp
    FROM ActorDirector
    GROUP BY actor_id, director_id
) as COOP
WHERE cp >= 3;