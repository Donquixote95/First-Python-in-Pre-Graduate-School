-- view, one of database objects

-- 단순 뷰 ; 하나의 테이블과 연관된 뷰
-- 복합 뷰 ; 2개 이상의 테이블과 연관된 뷰

USE market_db;
SELECT mem_id, mem_name, addr FROM member;

-- 뷰는 SELECT 문으로 만든다. 이름만 보고도 뷰인지 알아볼 수 있도록 이름 앞에 v_를 붙이는 것이 일반적이다.

create view v_member
as
	SELECT mem_id, mem_name, addr FROM member;
    
select * from v_member;

select mem_name, addr from v_member
	where addr in ('서울', '경기');
    
-- 기본적인 뷰를 생성하면서 뷰에서 사용될 열 이름을 테이블과 다르게 지정할 수도 있다. 기존에 배운 별칭을 사용하면 된다. 중간에 띄어쓰기도 사용 가능하다.
-- 별칭은 열 이름 뒤에 작은따옴표 또는 큰따옴표로 묶어주고 형식상 AS를 붙여준다.
-- 뷰를 조회할 때는 열 이름에 공백이 있으면 백틱(`)으로 묶어줘야 한다.

USE market_db;
CREATE VIEW v_viewtest1
AS
	SELECT B.mem_id 'Member ID', M.mem_name AS 'Member Name',
		B.prod_name "Product Name",
					CONCAT(M.phone1, M.phone2) AS "Office Phone"
		FROM buy B
			 INNER JOIN member M
             ON B.mem_id = M.mem_id;
             
Select distinct `Member ID`, `Member Name` FROM v_viewtest1;
Select distinct * FROM v_viewtest1;

-- 뷰의 수정은 ALTER VIEW 구문을 사용하며, 열 이름에 한글을 사용해도 된다.
ALTER VIEW v_viewtest1
AS
	SELECT B.mem_id '회원 아이디', M.mem_name AS '회원 이름',
		B.prod_name "제품 이름",
					CONCAT(M.phone1, M.phone2) AS "연락처"
		FROM buy B
			 INNER JOIN member M
             ON B.mem_id = M.mem_id;

Select distinct `회원 아이디`, `회원 이름` FROM v_viewtest1;

-- 뷰의 삭제
DROP VIEW v_viewtest1;

-- 뷰의 정보 확인
USE market_db;
create or replace view v_viewtest2
as
	select mem_id, mem_name, addr from member;
    
DESCRIBE v_viewtest2;
-- DESCRIBE 를 DESC 로 줄여도 된다.
DESC v_viewtest2; -- view로는 Primary key 등의 정보는 확인할 수 없다.
desc member; -- view가 아니면 PK도 알 수 있다.

-- SHOW CREATE VIEW 뷰의 소스 코드를 확인한다. [Result Grid] 창보다 [Form Editor] 창에서 더 잘 보인다.
show create view v_viewtest2;

-- 뷰를 통한 데이터의 수정, 삭제
UPDATE v_member SET addr = '부산' WHERE mem_id = 'BLK';

-- 아래 경우에는 입력 불가
INSERT INTO v_member(mem_id, mem_name, addr) VALUES('BTS', '방탄소년단', '경기');
-- 뷰가 참조하는 테이블의 열 중에서 mem_number 열은 NOT NULL로 설정되어서 반드시 입력해줘야 한다. 하지만
-- 현재의 v_member에서는 mem_number 열을 참조하고 있지 않으므로 값을 입력할 방법이 없다.
-- 뷰를 통해서 데이터를 입력하려면, 뷰에서 보이지 않는 테이블의 열에 NOT NULL이 없어야 한다.
-- view에서 NN 열을 포함하도록 재정의하거나, member 열에서 NN 열 속성을 해제하던가, 기본값을 지정해야 한다.

create view v_height167
as
	select * from member where height >= 167;

select * from v_height167;

delete from v_height167 where height < 167;

insert into v_height167 values('TRA', '티아라', 6, '서울', NULL, nULL, 159, '2005-01-01');
select * from v_height167;

-- 예약어 WITH CHECK OPTION, 뷰에 설정된 값의 범위가 벗어나는 값은 입력되지 않도록 하는 것
drop view v_height167;
create view v_height167
as
	select * from member where height >= 167
			 WITH CHECK OPTION;
insert into v_height167 values('TRA', '티아라', 6, '서울', NULL, nULL, 159, '2005-01-01');

-- 복합 뷰는 읽기 전용이기 때문에 테이블에 데이터를 입력, 수정, 삭제할 수 없다.
-- 주로 두 테이블을 조인한 결과를 뷰로 만들 때 사용한다.
CREATE VIEW v_complex
AS
	SELECT B.mem_id, M.mem_name, B.prod_name, M.addr
		FROM buy B
			 INNER JOIN member M
             ON B.mem_id = M.mem_id;
             
select * from v_complex;

-- 뷰가 참조하는 테이블의 삭제
drop table if exists buy, member;

select * from v_height167; -- 참조하는 테이블이 없기 때문에 조회할 수 없다는 메시지
-- 관련 뷰가 있더라도 테이블은 쉽게 삭제된다.
-- 뷰가 조회되지 않으면 CHECK TABLE 문으로 뷰의 상태를 확인할 수 있다.
CHECK TABLE v_height167;