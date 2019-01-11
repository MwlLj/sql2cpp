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
	// 插入记录
	uint32_t addUserinfo(const std::list<CAddUserinfoInput> &input0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 通过用户ID获取用户信息
	uint32_t getUserinfoById(const CGetUserinfoByIdInput &input0, CGetUserinfoByIdOutput &output0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 获取全部的人员信息
	uint32_t getAllUserinfo(std::list<CGetAllUserinfoOutput> &output0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 删除一个或多个用户
	uint32_t deleteUser(const std::list<CDeleteUserInput> &input0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 更新用户名
	uint32_t updateUsername(const CUpdateUsernameInput &input0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 更新用户名2
	uint32_t updateUsername2(const CUpdateUsername2Input &input0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 更新用户名3
	uint32_t updateUsername3(const CUpdateUsername3Input &input0, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 子句测试
	uint32_t subTest(const CUpdateUsernameInput &input0, const CSubTestInput &input1, const std::list<CDeleteUserInput> &input2, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);
	// 子句测试pro
	uint32_t subTestPro(const CUpdateUsernameInput &input0, const CSubTestInput &input1, const std::list<CDeleteUserInput> &input2, const CSubTestProInput &input3, const std::list<CAddUserinfoInput> &input4, bool isAlreayStartTrans = false, sql::IConnect *reuseConn = nullptr);

public:
	sql::IConnect *connect() { return m_connPool.connect(m_dial); }
	void freeConnect(sql::IConnect *conn) { m_connPool.freeConnect(conn); }

private:
	sql::CConnPool m_connPool;
	std::string m_dial;
};

}

#endif // __USER_INFO_DB_HANDLER_H__
