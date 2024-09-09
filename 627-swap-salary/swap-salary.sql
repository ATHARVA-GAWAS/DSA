# Write your MySQL query statement below
UPDATE Salary
SET sex = (
    CASE WHEN sex = 'f' then 'm'
    ELSE 'f'
    END
);