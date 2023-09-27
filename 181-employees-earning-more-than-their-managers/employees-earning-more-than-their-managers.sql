# Write your MySQL query statement below
select name as Employee  
from Employee a
where a.Salary >(
    select b.salary
    from Employee b
    where a.ManagerId=b.Id
);