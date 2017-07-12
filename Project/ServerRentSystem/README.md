## Server Rent System

#### How to use

1. Open your Oracle database in your favoriate terminal, create a database table:
```sql
SQL> create sequence log_seq;

SQL> commit;

SQL> create table logSys(
  2  num number not null primary key,
  3  userID varchar(32) not null,
  4  IP varchar(32) not null, 
  5  loginTime date not null,
  6  logoutTime date not null,
  7  durations number not null);
```

2. Then comple the client, into client director, then:
`make debug`, don't care about the errors. 
then `make`

3. Then comple the server, into server director, then:
`make debug`, don't care about the errors. 

4. run the server and the client. 
	- In your server director. run the server: `./server`
	- In your client director. run the client: `./client`

5. Then count how many records in you database table:
	- `select count(*) from logSys;`

6. Will print  a cute number `2183`, ok! you sucess! 
 
