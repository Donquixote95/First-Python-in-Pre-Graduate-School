-- 클러스터형 인덱스와 보조 인덱스는 모두 내부적으로 균형 트리로 만들어진다.
-- 균형 트리(Balanced tree, B-tree) ; 나무를 거꾸로 표현한 자료 구조
-- 트리에서 제일 상단의 뿌리를 루트, 줄기를 중간, 끝에 달린 잎을 리프라고 부른다.

-- 균형 트리에서 데이터가 저장되는 공간을 노드(node)라고 부른다.
-- 루트 노드(root node) 가장 상위 노드
-- 중간 노드(internal node)
-- 리프 노드(leaf node) 제일 마지막에 존재하는 노드

-- MySQL에서는 노드를 페이지(page)라고 부른다. 페이지는 최소의 저장 단위로 16Kbyte의 크기를 가진다.
-- 균형 트리는 루트 페이지부터 검색한다.

-- 페이지 분할 ; 새로운 페이지를 준비해서 데이터를 나누는 작업
-- 인덱스를 구성하면 데이터 변경 작업 시 성능이 나빠진다.
-- 페이지 분할은 성능에 영향을 준다. 페이지 분할 때문에 INSERT 작업이 일어날 때 느리게 입력된다.

USE market_db;
drop table if exists cluster;
create table cluster
(mem_id char(8),
mem_name varchar(10)
);

insert into cluster values('TWC', '트와이스');
insert into cluster values('BLK', '블랙핑크');
insert into cluster values('WMN', '여자친구');
insert into cluster values('OMY', '오마이걸');
insert into cluster values('GRL', '소녀시대');
insert into cluster values('ITZ', '잇지');
insert into cluster values('RED', '레드벨벳');
insert into cluster values('APN', '에이핑크');
insert into cluster values('SPC', '우주소녀');
insert into cluster values('MMU', '마마무');

select * from cluster;

alter table cluster
	add constraint
    primary key(mem_id);
    
show index from cluster;

-- index page 중에서 리프 페이지는 데이터 페이지이다.
-- 클러스터형 인덱스를 구성하면 데이터 페이지도 인덱스에 포함된다. 영어사전의 본문이 찾아보기의 일부라는 것과 같은 개념이다.

create table second -- 보조 인덱스를 테스트
(mem_id char(8),
mem_name varchar(10)
);

insert into second values('TWC', '트와이스');
insert into second values('BLK', '블랙핑크');
insert into second values('WMN', '여자친구');
insert into second values('OMY', '오마이걸');
insert into second values('GRL', '소녀시대');
insert into second values('ITZ', '잇지');
insert into second values('RED', '레드벨벳');
insert into second values('APN', '에이핑크');
insert into second values('SPC', '우주소녀');
insert into second values('MMU', '마마무');

alter table second
	add constraint
    unique(mem_id);
select * from second;

-- 인덱스 페이지의 리프 페이지에 인덱스로 구성한 열을 정렬한다.
-- 일반 책의 찾아보기를 보면 각 단어 옆에 페이지 번호가 써있는 것과 동일하다.
-- 데이터의 위치는 '페이지 번호 +#위치'로 기록된다.

-- 인덱스 검색(index scan) ; 검색속도는 클러스터형 인덱스가 보조 인덱스보다 조금 더 빠르다.