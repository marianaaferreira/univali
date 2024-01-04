create database m2;
use m2;

create table Unidade(
unidade_id int not null primary key,
cidade varchar(40)
);

create table Produto(
produto_id int not null primary key,
descricao varchar(50),
preco float
);

create table Vendedor(
matricula int not null primary key,
nome varchar(60)
);

create table Venda(
venda_id int not null primary key,
unidade int,
produto int,
quantidade float,
vendedor int,
data_venda date,
foreign key (unidade) references Unidade(unidade_id),
foreign key (produto) references Produto(produto_id),
foreign key (vendedor) references Vendedor(matricula)
);

insert into Unidade values (1, 'Unidade 1');
insert into Unidade values (2, 'Unidade 2');
insert into Unidade values (3, 'Unidade 3');

insert into Produto values (1, 'Produto 1', 15.5);
insert into Produto values (2, 'Produto 2', 30.0);
insert into Produto values (3, 'Produto 3', 10.5);
insert into Produto values (4, 'Produto 4', 50.0);
insert into Produto values (5, 'Produto 5', 55.0);

insert into Vendedor values (123, 'Vendedor 1');
insert into Vendedor values (234, 'Vendedor 2');
insert into Vendedor values (345, 'Vendedor 3');

insert into Venda values (1, 1, 1, 1, 123, '20-10-2023');
insert into Venda values (2, 1, 2, 3, 123, '21-10-2023');
insert into Venda values (3, 2, 3, 1, 234, '20-10-2023');
insert into Venda values (4, 2, 1, 1, 234, '22-10-2023');
insert into Venda values (5, 3, 1, 1, 345, '20-10-2023');
insert into Venda values (6, 3, 2, 1, 345, '20-10-2023');
insert into Venda values (7, 3, 3, 2, 345, '21-10-2023');
insert into Venda values (8, 1, 3, 2, 123, '21-10-2018');
insert into Venda values (9, 1, 3, 2, 123, '21-10-2019');
insert into Venda values (10, 1, 3, 2, 123, '21-10-2020');
insert into Venda values (11, 1, 3, 2, 123, '21-10-2021');
insert into Venda values (12, 1, 3, 2, 123, '21-10-2022');
insert into Venda values (13, 2, 4, 2, 234, '22-10-2023');
insert into Venda values (14, 1, 5, 2, 123, '21-12-2023');
insert into Venda values (15, 1, 5, 2, 123, '01-01-2024');
insert into Venda values (16, 1, 4, 2, 123, '12-12-2023');
insert into Venda values (17, 1, 1, 1, 123, '21-10-2021');


-- juncoes

--A.	Retorne todas as vendas de determinado produto, exibindo detalhes das unidades que realizaram a venda.
select * from Venda as v
join Unidade as u
on v.unidade = u.unidade_id
where v.produto = 1;

--B.	Retorne todas as vendas de determinado vendedor, exibindo os detalhes da venda, das unidades, e do vendedor.
select * from Venda
join Unidade
on Venda.unidade = Unidade.unidade_id
join Vendedor
on Venda.vendedor = Vendedor.matricula
where Venda.vendedor = 123;

--C.	Retorne todas as vendas de determinada unidade, realizadas nos últimos 2 anos.
select * from Venda 
join Unidade
on Venda.unidade = Unidade.unidade_id
where Unidade.cidade = 'Unidade 1' and year(data_venda)>=year(getdate())-2;

--D.	Retorne todos os produtos que não tiveram vendas realizadas no último mês.
select * from Produto
left join Venda
on Produto.produto_id = Venda.produto and month(Venda.data_venda) = month(dateadd(month, -1, getdate()))
where Venda.produto is null;

--E.	Retorne todos os vendedores que não realizaram nenhuma venda nos últimos 20 dias.
select * from Vendedor
left join Venda
on  Vendedor.matricula = Venda.vendedor and Venda.data_venda >= dateadd(day, -20, getdate())
where Venda.venda_id is null;

--agregações

--F.	Retorne a quantidade de vendas de determinado produto e o valor total destas vendas. 
select Produto.descricao, 
		sum(Venda.quantidade) as 'Qtd de vendas', 
		sum(Produto.preco * Venda.quantidade) as 'Valor total'
from Venda
join Produto on Venda.produto = Produto.produto_id
where Produto.descricao = 'Produto 2'
group by Produto.descricao;

--G.	Retorne a quantidade de vendas de determinado vendedor, exibindo o valor total destas vendas e a média dos valores das vendas.
select Vendedor.nome, 
		count(Venda.quantidade) as 'Qtd de vendas',
		sum(Produto.preco * Venda.quantidade) as 'Valor total',
		avg(Produto.preco * Venda.quantidade) as 'Media das vendas'
from Venda
join Vendedor on Vendedor.matricula = Venda.vendedor
join Produto on Produto.produto_id = Venda.produto
where Vendedor.nome = 'Vendedor 1'
group by Vendedor.nome;

--H.	Retorne todas as unidades que tiveram o valor total de vendas superior a 100.000 no último ano.
select * from(
	select Unidade.cidade, 
			sum(Venda.quantidade * Produto.preco) as [valor_total]
	from Venda
	join Unidade on Unidade.unidade_id = Venda.unidade 
	join Produto on Produto.produto_id = Venda.produto
	where year(Venda.data_venda) = year(dateadd(year, -1, getdate()))
	group by Unidade.cidade
)as Subconsulta
where valor_total > 20;

--I.	Retorne todos os produtos que tiveram total de vendas nos últimos 3 meses inferior a 20 unidades.
select * from (
	select Produto.descricao, 
			sum(Venda.quantidade) as [Qtd_vendas]
	from Venda
	join Produto on Venda.produto = Produto.produto_id
	group by  Produto.descricao
)as Subconsulta
where Qtd_vendas < 20;

--J.	Retorne todos os vendedores que no último ano tiveram valor de vendas acumulado acima da média das vendas de todos os vendedores.
select * from(
	select Vendedor.nome, 
			sum(Venda.quantidade * Produto.preco) as [venda_total] 
	from Venda
	join Produto on Produto.produto_id = Venda.produto
	join Vendedor on Vendedor.matricula = Venda.vendedor
	where year(Venda.data_venda) = year(dateadd(year, -1, getdate()))
	group by Vendedor.nome
)as Subconsulta
where venda_total > (
	select avg(Venda.quantidade * Produto.preco) as [media_vendas]
	from Venda
	join Produto on Produto.produto_id = Venda.produto
	where year(Venda.data_venda) = year(dateadd(year, -1, getdate()))
);

	