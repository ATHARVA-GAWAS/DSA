# Wherever you are given a range, keep MIN() and MAX() in mind
select Product.product_id, Product.product_name 
from Product join Sales 
on Product.product_id = Sales.product_id 
group by Sales.product_id 
having MIN(Sales.sale_date) >= "2019-01-01" AND MAX(Sales.sale_date) <= "2019-03-31";