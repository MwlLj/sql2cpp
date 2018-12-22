#namespace user_info

#create tables
/*
create table if not exists user_info(
	id integer primary key autoincrement,
	username varchar(32),
	userage int
);

create table if not exists user_info(
	id integer primary key autoincrement,
	username varchar(32),
	userage int
);
*/
#end

#create tables
/*
create table if not exists user_info(
	id integer primary key autoincrement,
	username varchar(32),
	userage int
);
*/
#end

/*
	@bref 插入一条记录
	@in_isarr false
	@out_isarr false
	@in username: string
	@in userage: int
*/
#define addUserinfo
insert into user_info values(null, ?, ?);
#end

/*
	@bref 插入多条记录
	@is_brace true
	@in_isarr true
	@out_isarr false
	@in userName: string
	@in userAge: int
*/
#define addMultiUserInfo
insert into user_info values(null, {0}, {1});
#end

/*
	@bref 通过用户ID获取用户信息
	@in_isarr false
	@out_isarr false
	@in id: int
	@out id: int
	@out username: string
	@out userage: int
*/
#define getUserinfoById
select * from user_info
where id = ?;
#end

/*
	@bref 获取全部的人员信息
	@in_isarr false
	@out_isarr true
	@out id: int
	@out username: string
	@out userage: int
*/
#define getAllUserinfo
select * from user_info;
#end

/*
	@bref 删除一个或多个用户
	@in_isarr true
	@out_isarr false
	@in id: int
*/
#define deleteUser
delete from user_info where id = ?;
#end

/*
	@bref 获取用户信息通过名字
	@is_brace true
	@in_class getUserInfoByName
	@out_class getUserInfoByName
	@in_isarr false
	@out_isarr true
	@in userName: string
	@out id: int
	@out userName: string
	@out userAge: int
*/
#define getUserInfo
select * from user_info where username = {0};
#end

/*
	@bref 获取用户信息通过年龄
	@is_brace true
	@in_class getUserInfoByAge
	@out_class getUserInfoByAge
	@in_isarr false
	@out_isarr true
	@in userAge: int
	@out id: int
	@out userName: string
	@out userAge: int
*/
#define getUserInfo
select * from user_info where userage = {0};
#end

/*
	@bref 更新用户名
	@in_isarr false
	@out_isarr false
	@in username: string
	@in id: int
*/
#define updateUsername
update user_info set username = ? where id = ?;
#end

/*
	@bref 更新用户名2
	@is_brace true
	@in_isarr false
	@out_isarr false
	@in id: int
	@in username: string
*/
#define updateUsername2
update user_info set username = {1} where id = {0};
#end

/*
	@bref 更新用户名3
	@is_brace true
	@is_group true
	@in_isarr false
	@out_isarr false
	@gin id: int
	@in username: string
*/
#define updateUsername3
update user_info set username = {1} where /*begin{0}*/id = {0}/*end*/;
#end

/*
	@bref 更新用户名4
	@is_brace true
	@in_isarr false
	@out_isarr false
	@in id[cond]: string
	@in username: string
*/
#define updateUsername4
update user_info set username = {1} {0};
#end
