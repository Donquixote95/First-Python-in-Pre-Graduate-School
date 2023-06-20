#사용자가 반복해서 데이터를 입력하는 코드 작성

import pymysql

# global variable
conn, cur = None, None
data1, data2, data3, data4 = "", "", "", ""
sql = ""

# Main code
conn = pymysql.connect(host = '127.0.0.1', 
                       user = 'root', 
                       password = '8656',
                       db = 'soloDB',
                       charset = 'utf8')
cur = conn.cursor()

while (True) :
    data1 = input("사용자 ID ==> ")
    if data1 == "" :
        break;
    data2 = input("사용자 이름 ==> ")
    data3 = input("사용자 이메일 ==> ")
    data4 = input("사용자 출생연도 ==> ")
    sql = "INSERT INTO userTable VALUES('" + data1 + "', '" + data2 + "', '" + data3 + "', " + data4 + ")"
    #data1~3는 작은따옴표(')로 묶어야 하고, data4는 정수이므로 작은따옴표로 묶으면 안 된다.
    cur.execute(sql)

conn.commit()
conn.close()
    