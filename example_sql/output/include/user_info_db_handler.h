#ifndef __USER_INFO_DB_HANDLER_H__
#define __USER_INFO_DB_HANDLER_H__

#include <stdint.h>
#include "user_info_db_param.h"
#include "sql.h"

namespace user_info
{

class CDbHandler
{
public:
	explicit CDbHandler(const std::string &dial, sql::ISql *s, int max = 1);
	virtual ~CDbHandler();

public:
	/*@@start@@*/
	// 插入一条记录
	uint32_t addUserinfo(const CAddUserinfoInput &input);
	// 插入多条记录
	uint32_t addMultiUserInfo(const std::list<CAddMultiUserInfoInput> &input);
	// 通过用户ID获取用户信息
	uint32_t getUserinfoById(const CGetUserinfoByIdInput &input, CGetUserinfoByIdOutput &output);
	// 获取全部的人员信息
	uint32_t getAllUserinfo(std::list<CGetAllUserinfoOutput> &output);
	// 删除一个或多个用户
	uint32_t deleteUser(const std::list<CDeleteUserInput> &input);
	// 获取用户信息通过名字
	uint32_t getUserInfo(const CGetUserInfoByNameInput &input, std::list<CGetUserInfoByNameOutput> &output);
	// 获取用户信息通过年龄
	uint32_t getUserInfo(const CGetUserInfoByAgeInput &input, std::list<CGetUserInfoByAgeOutput> &output);
	// 更新用户名
	uint32_t updateUsername(const CUpdateUsernameInput &input);
	// 更新用户名2
	uint32_t updateUsername2(const CUpdateUsername2Input &input);
	// 更新用户名3
	uint32_t updateUsername3(const CUpdateUsername3Input &input);
	// 更新用户名4
	uint32_t updateUsername4(const CUpdateUsername4Input &input);

private:
	sql::CConnPool m_connPool;
	std::string m_dial;
};

}

#endif // __USER_INFO_DB_HANDLER_H__
