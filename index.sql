-- CREATE INDEX로 생성되는 인덱스는 보조 인덱스이다.

-- 기본 키, 고유 키로 자동 생성된 인덱스는 DROP INDEX로 제거하지 못한다.
-- ALTER TABLE 문으로 기본 키나 고유 키를 제거하면 자동으로 생성된 인덱스도 제거할 수 있다.
-- 하나의 테이블에 클러스터형 인덱스와 보조 인덱스가 모두 있는 경우 인덱스를 제거할 때는 보조 인덱스부터 제거하는 것이 좋다.
-- 클러스터형 인덱스부터 제거하면 내부적으로 데이터가 재구성되기 때문이다.

use market_db;
select * from member;

show index from member;

show table status like 'member';
-- data_length는 클러스터형 인덱스(데이터)의 크기를 Byte 단위로 표기한 것
-- MySQL에서 1페이지의 크기는 기본적으로 16KB 이므로 클러스터형 인덱스는 16384/(16*1024) = 1 페이지가 할당되어 있는 것.
-- 1KB는 1024Byte이다.
-- Index_length는 보조 인덱스의 크기이다.

create index idx_member_addr
	on member(addr); -- 단순 보조 인덱스(Simple Secondary Index)
    
-- 보조 인덱스는 단순 보조 인덱스(Simple Secondary Index)와 고유 보조 인덱스(Unique Secondary Index)로 나뉜다.
-- 단순 보조 인덱스는 중복을 허용한다는 의미이다.

show index from member;
show table status like 'member'; -- 현재는 index_length가 0으로 나온다. 
-- 생성한 인덱스를 실제로 적용시키려면 analyze table 문으로 먼저 테이블을 분석 처리해줘야 한다.

analyze table member;
show table status like 'member';

create unique index idx_member_mem_name
	on member (mem_name);
show index from member;

analyze table member;
show index from member;

select * from member;
select mem_id, mem_name, addr from member;
select mem_id, mem_name, addr 
	from member
    where mem_name = '에이핑크';
    
create index idx_member_mem_number
	on member (mem_number);
analyze table member;

select mem_name, mem_number
	from member
	where mem_number >= 7;
    
select mem_name, mem_number
	from member
	where mem_number >= 1; -- index가 있어도 MySQL이 판단해서 사용하지 않는 경우
    
select mem_name, mem_number
	from member
	where mem_number*2 >= 14; -- where 문에서 열에 연산이 가해지면 인덱스를 사용하지 않는다.

select mem_name, mem_number
	from member
	where mem_number >= 14/2; -- where 절에 나온 열에 연산을 가한 게 아니기 때문에 인덱스를 사용한다.
    
show index from member;

drop index idx_member_mem_name on member;
drop index idx_member_addr on member;
drop index idx_member_mem_number on member;

-- 클러스터형 인덱스를 제거하면 데이터를 재구성하기 때문에 오래 걸린다, 그러므로 보조 인덱스를 먼저 제거하는 게 편하다.
alter table member
	drop primary key; -- 외래 키 관계를 먼저 제거해줘야 이 명령을 실행 가능
    
select table_name, constraint_name
	from information_schema.referential_constraints
    where constraint_schema = 'market_db';
    -- information_schema 데이터베이스의 referential_constraints 테이블을 조회하면 외래 키의 이름을 알 수 있다.

alter table buy
	drop foreign key buy_ibfk_1;
alter table member
	drop primary key;