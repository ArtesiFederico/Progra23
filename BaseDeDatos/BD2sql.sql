mysql -u root -p 

drop database AlmacenBD;
create database AlmacenBD;
use AlmacenBD;

create table cajeros(
    Cod_caj int primary key,
    Nom_Apels nvarchar(255)
);

insert into cajeros(Cod_caj, Nom_Apels) values
(23, "Diego Merlo"),
(26, "Artesi Federico"),
(78, "Nahuel Nicito"),
(93, "Mariana Stern");


create table productos(
    Cod_prod int primary key,
    Nom_prod nvarchar(100),
    Precio_prod int
);

insert into productos(Cod_prod, Nom_prod, Precio_prod) values
(72673, "Papas Lays", 200),
(61543, "Cheetos", 180),
(54134, "Pauelos Elite", 400),
(61323, "Cerbeza Gancia", 210),
(51234, "Baterias Duracell", 600);


create table maquinas_registradas(
    Cod_maq int primary key,
    piso_maq int
);

insert into maquinas_registradas(Cod_maq, piso_maq) values
(132, 1),
(512, 2),
(432, 3),
(345, 3);

create table venta(
    ven_caj int,
    ven_maq int,
    ven_prod int,
    constraint fk_venta_caja foreign key (ven_caj) references cajeros(Cod_caj),
    constraint fk_venta_maquina foreign key (ven_maq) references maquinas_registradas(Cod_maq),
    constraint fk_venta_producto foreign key (ven_prod) references productos(Cod_prod)
);

insert into venta(ven_caj, ven_maq, ven_prod) values
(23, 512, 61543),
(93, 432, 72673),
(26, 132, 51234),
(26, 132, 61543),
(78, 345, 54134),
(23, 345, 61323);

select * from cajeros;
select * from productos;
select * from maquinas_registradas;
select * from venta;

----1
select ven_prod, COUNT(*) AS num_ventas 
from venta
GROUP BY ven_prod
ORDER BY num_ventas ASC;


-----2
select Nom_Apels, Nom_prod, Precio_prod, piso_maq
from cajeros inner join 
(productos inner join
(maquinas_registradas inner join venta
on ven_maq = Cod_maq)
on ven_prod = Cod_prod)
on ven_caj = Cod_caj;

------3
select piso_maq, Cod_maq, SUM(Precio_prod)
from venta, productos, maquinas_registradas
where ven_prod = Cod_prod
and ven_maq = Cod_maq
group by piso_maq;


-------4
select cajeros.Cod_caj, cajeros.Nom_Apels, SUM(Precio_prod)
from productos inner join (cajeros left join venta on ven_caj = Cod_caj)
on ven_prod = Cod_prod
group by Cod_caj, Nom_Apels;


------5
select Cod_caj, Nom_Apels
from venta
inner join cajeros on ven_caj = cajeros.Cod_caj
inner join maquinas_registradas on ven_maq = maquinas_registradas.Cod_maq
inner join(
    select maquinas_registradas.piso_maq, sum(Precio_prod) as to
)