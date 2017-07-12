# Server Rent System
    
This System has a client and a server.

- client: read login File log: wtempx, match login record. Then send the matched record to server. 
- server: create a thread receive record from the client. Then send to another thread, to store the records into Oracle database or a file. 
  
  
## Compile and run

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

2. Compile the server and client.
```
(cd server && make)
(cd client && make)
```

3. Run the server and the client. 
	- In your server director. run the server: `./server`
	- In your client director. run the client: `./client`
	- Note: first, run `./server` then run `./client`, the order is very important. 

4. Count how many records in you database table:
	- `select count(*) from logSys;`

5. Will print  a cute number `2183`, WO! clap for yourself, you sucessed! 
 
6. Note: before you another time complie and run this process, please run commands: 
```
(cd client && make debug)
(cd server && make debug)
```
