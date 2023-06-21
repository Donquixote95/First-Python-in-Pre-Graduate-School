CREATE TABLE big_table1 (SELECT * FROM world.city, sakila.country);
CREATE TABLE big_table2 (SELECT * FROM world.city, sakila.country);
CREATE TABLE big_table3 (SELECT * FROM world.city, sakila.country);
SELECT COUNT(*) FROM big_table1;

-- cross join(상호 조인)

DELETE FROM big_table1; -- 빈 테이블은 남기고, 속도는 느리다. 이 노트북 기준으로 4.5s
DROP TABLE big_table2; -- 테이블 자체를 삭제하기 때문에 빠르다. 이 노트북 기준으로 0.032s
TRUNCATE TABLE big_table3; -- 빈 테이블은 남기고, 속도는 빠르다. 이 노트북 기준으로 0.031s

-- TRUNCATE는 DELTE와 달리 WHERE 문을 사용할 수 없다. 그러므로 조건 없이 전체 행을 삭제할 때만 사용한다.