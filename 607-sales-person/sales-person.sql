# Write your MySQL query statement below
select s.name from SalesPerson s
where s.sales_id not in(
    select o.sales_id 
    from Orders o left join Company c
    on o.com_id=c.com_id
    where o.com_id=c.com_id and c.name='RED'
);