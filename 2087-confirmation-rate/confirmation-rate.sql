# Write your MySQL query statement below
select 
sp.user_id,
case when cn.action is null then 0.00
else round(sum(case when action='confirmed' then 1 else 0 end)/count(action),2) end as confirmation_rate
from signups sp left join confirmations cn 
on sp.user_id=cn.user_id
group by sp.user_id;