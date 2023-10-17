/*1.	Visualizzare i clienti (customers) in ordine alfabetico*/
select *
from customers
order by CompanyName;

/* 2.	Visualizzare i clienti che non hanno il fax*/
select *
from customers
where fax is null;

/* 3.	Selezionare i nomi dei clienti (CompanyName) che iniziano con le lettere P, Q, R, S */
select CompanyName
from customers 
where CompanyName LIKE 'P%'
or CompanyName LIKE 'Q%'
or CompanyName LIKE 'R%'
or CompanyName LIKE 'S%';

select CompanyName
from customers 
where CompanyName BETWEEN 'P' AND 'T';

/* 4.	Visualizzare Nome e Cognome degli impiegati assunti (HireDate) dopo il '1993-05-03' e aventi titolo di “Sales Representative”*/
select LastName, FirstName, Title, HireDate
from employees
where Title = 'Sales Representative'
and HireDate > '1993-05-03';

/*5.	Selezionare la lista dei prodotti non sospesi (attributo discontinued), visualizzando 
anche il nome della categoria di appartenenza*/
select ProductName, c.categoryName, discontinued
from products p, categories c 
where p.categoryid = c.categoryid
and discontinued = 0;

/*6. Selezionare gli ordini relativi al cliente ‘Ernst Handel’ (CompanyName)*/
select o.*
from orders o, customers c
where o.customerid = c.customerid
and companyname = 'Ernst Handel';

/*7. Selezionare il nome della società e il telefono dei corrieri (shippers) che hanno consegnato 
ordini nella città di ‘Rio de Janeiro’ (ShipCity in orders)
N.B. nella tabella orders l'id corriere è l'attributo ShipVia*/
select distinct CompanyName, Phone
from shippers s join orders o on (s.shipperid = o.shipvia)
where o.ShipCity = 'Rio de Janeiro';

/*8. Selezionare gli ordini (OrderID, OrderDate, ShippedDate) per cui la spedizione (ShippedDate)
è avvenuta entro 30 giorni dalla data dell’ordine (OrderDate)*/
select orderid, OrderDate, ShippedDate
from orders
where datediff(ShippedDate, OrderDate)<30;

/*9. Selezionare l’elenco dei prodotti che hanno un costo compreso tra 18 e 50, ordinando il risultato
in ordine di prezzo crescente */
select *
from products
where unitprice between 18 and 50
order by unitprice;

/*10.	Selezionare tutti i clienti (CustomerID, CompanyName) che hanno ordinato il prodotto 'Chang'*/
select distinct c.CustomerID, CompanyName
from customers c, orders o, `order details` od, products p
where c.customerid = o.customerid
and o.orderid = od.orderid
and p.productid = od.productid
and p.productname ='Chang';

/*11.	Selezionare i clienti che non hanno mai ordinato prodotti di categoria ‘Beverages’*/
select *
from customers c
where customerid not in (select o.customerid
						 from orders o, `order details` od, products p, categories cat
                         where o.orderid = od.orderid
                         and od.productid = p.productid
                         and p.categoryid = cat.categoryid
                         and cat.categoryName = 'Beverages')

select *
from customers c
where not exists	 (select *
					  from orders o, `order details` od, products p, categories cat
                      where o.orderid = od.orderid
                      and od.productid = p.productid
                      and p.categoryid = cat.categoryid
                      and cat.categoryName = 'Beverages'
                      and c.CustomerID = o.CustomerID)
         
/*12.	Selezionare il prodotto più costoso*/
select *
from products
order by UnitPrice desc
limit 1

select *
from products
where UnitPrice = (select max(UnitPrice)
				   from products p1)

/*13.	Visualizzare l’importo totale di ciascun ordine fatto dal cliente 'Ernst Handel' (CompanyName)*/
select o.orderid, sum(UnitPrice*Quantity)
from `order details` od, orders o, customers c
where c.customerid = o.customerid
and o.orderid = od.orderid
and c.CompanyName = 'Ernst Handel'
group by o.orderid;

/* 14.	Selezionare il numero di ordini ricevuti in ciascun anno */
select year(OrderDate), count(*)
from orders
group by year(OrderDate);

/* 15.	Visualizzare per ogni impiegato (EmployeeID, LastName, FirstName) il numero di clienti distinti serviti per ciascun paese (Country),
visualizzando il risultato in ordine di impiegato e di paese*/
select e.EmployeeID, LastName, FirstName, c.Country, count(distinct c.customerID) as numCustomers
from employees e, orders o, customers c
where e.employeeID = o.employeeID
and o.customerID = c.customerID
group by e.employeeid, LastName, FirstName, c.Country
order by 2, 3, 4;

/* 16.	Visualizzare per ogni corriere il numero di consegne effettuate, compresi i dati dei 
corrieri che non hanno effettuato nessuna consegna */
select ShipperID, CompanyName, count(o.orderID)
from shippers s left join orders o on (s.ShipperID = o.ShipVia)
group by ShipperID, CompanyName;

/* 17.	Visualizzare i fornitori (SupplierID, CompanyName) che forniscono un solo prodotto */
select s.SupplierID, CompanyName, count(*)
from suppliers s, products p
where s.SupplierID = p.SupplierID
group by SupplierID, CompanyName
having count(*) = 1;

/* 18.	Visualizzare tutti gli impiegati che sono stati assunti dopo Margaret Peacock */
select EmployeeID, LastName, FirstName, HireDate
from employees e
where HireDate >=ALL (select HireDate
					  from employees e1
					  where e1.LastName = 'Peacock'
					  and e1.FirstName = 'Margaret');

/* 19.	Visualizzare gli ordini relativi al prodotto più costoso */
select o.*
from orders o, `order details` od
where o.orderID = od.orderID
and od.productID IN (select productID
					from products
					where UnitPrice = (select max(UnitPrice)
									   from products p1));
                                     
/* 20.	Visualizzare i nomi dei clienti per i quali l’ultimo ordine è relativo al 1998  */
select c.customerID, CompanyName
from customers c, orders o
where c.customerID = o.customerID
group by c.customerID, CompanyName
having max(year(OrderDate)) = 1998;

/* 21.	Contare il numero di clienti che non hanno effettuato ordini */
select count(*)
from customers c
where customerID NOT IN (select o.customerID
						 from orders o);
                         
/* 22.	Visualizzare il prezzo minimo, massimo e medio dei prodotti per ciascuna categoria */
select c.categoryID, c.CategoryName, min(UnitPrice), max(UnitPrice), avg(UnitPrice)
from products p, categories c
where p.CategoryID = c.categoryID
group by c.categoryID, c.CategoryName;

/* 23.	Selezionare i prodotti che hanno un prezzo superiore al prezzo medio dei prodotti forniti dallo stesso fornitore */
select p.productID, p.productName
from products p
where p.UnitPrice > (select avg(UnitPrice)
					from products p1
					where p1.supplierID = p.supplierID);
                                        
/* 24.	Visualizzare, in ordine decrescente rispetto alla quantità totale venduta, i prodotti che hanno venduto una quantità 
totale superiore al prodotto ‘Chai’ */
select od.productID, sum(Quantity)
from `order details` od
group by od.productID
having sum(Quantity) > (select sum(od1.Quantity)
						from `order details` od1, products p
						where od1.productID = p.productID
						and p.productName = 'Chai')
order by sum(Quantity) desc;

/* 25.	Visualizzare il nome dei clienti che hanno fatto almeno due ordini di importo superiore a 15000 */
select c.CompanyName
from customers c, orders o
where c.customerID = o.CustomerID
and orderID IN (select od.orderid
				from `order details` od
				group by od.orderID
				having sum(od.Quantity*od.UnitPrice) > 15000) 
group by c.CustomerID, c.CompanyName
having count(*) >1;

/* 26.	Individuare i codici dei clienti che hanno fatto un numero di ordini pari a quello del cliente 'Eastern Connection' */
select o.customerID
from orders o
group by o.customerID
having count(*) = (select count(*)
				   from orders o1, customers c
                   where o1.customerID = c.customerID
                   and c.CompanyName = 'Eastern Connection');

/* 27. Visualizzare il numero di ordini ricevuti nel 1997 e di importo superiore a 10000*/
select count(*) 
from orders
where orderid in (select od.orderid
				  from orders o1, `order details` od
                  where o1.OrderID = od.OrderID
                  and year(o1.orderdate)=1996
                  group by od.orderid
                  having sum(od.Quantity*od.UnitPrice)>10000);
				
/* 28. Visualizzare i corrieri che hanno consegnato un numero di ordini superiore al numero di ordini consegnati da Speedy Express. */
select s.ShipperID, count(*)
from shippers s, orders o
where s.ShipperID = o.ShipVia
group by s.ShipperID
having count(*) > (select count(*)
					from shippers s1, orders o1
                    where s1.ShipperID = o1. ShipVia
                    and s1.CompanyName = 'Speedy Express');

/* 29. Visualizzare i clienti che hanno ordinato prodotti di tutte le categorie */
select *
from customers c, orders o, `order details` od, products p
where c.CustomerID = o.CustomerID
and o.orderID = od.OrderID 
and od.ProductID = p.ProductID
group by c.CustomerID
having count(distinct p.categoryid) = (select count(*)
										from categories c1);
 
 
select *
from customers c
where not exists (select * 
				  from categories cat
                  where not exists (select * 
								  from orders o, `order details` od, products p
								  where c.CustomerID = o.CustomerID
								  and o.orderID = od.OrderID 
								  and od.ProductID = p.ProductID
								  and p.CategoryID = cat.CategoryID));
                                        
                                        

				
                        

                  
                     

