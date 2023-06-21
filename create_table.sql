DROP DATABASE IF EXISTS naver_db;
CREATE DATABASE naver_db;

USE naver_db;
DROP TABLE IF EXISTS member;
CREATE TABLE member
(mem_id	char(8) not null primary key, -- primary key는 NULL 값을 허용하지 않는다. NOT NULL을 생략해도 NOT NULL이 기본값
mem_name	varchar(10) not null, -- NOT NULL을 생략하면 NULL 허용이 기본값이다.
mem_number	tinyint not null,
addr	char(2) not null,
phone1	char(3) null,
phone2	char(8) null,
height	tinyint	unsigned null,
debut_date	date null
);

drop table if exists buy;
create table buy
( num int auto_increment not null primary key, -- auto increment로 지정했으면 primary key 또는 Unique 키로 지정해줘야 한다.
	mem_id	char(8) not null,
	prod_name	char(6)	not null,
    group_name	char(4)	null,
    price	int unsigned not null,
    amount	smallint unsigned not null
);