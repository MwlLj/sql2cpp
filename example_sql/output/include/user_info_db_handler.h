#ifndef __USER_INFO_DB_HANDLER_H__
#define __USER_INFO_DB_HANDLER_H__

#include <stdint.h>
#include <mutex>
#include "user_info_db_param.h"

struct sqlite3;
namespace user_info
{

class CDbHandler
{
public:
	explicit CDbHandler(const std::string &dbpath, bool isMemory = false);
	virtual ~CDbHandler();

public:
	/*@@start@@*/
	// 插入一条记录
	uint32_t add_userinfo(const CAdd_userinfoInput &input);
	// 通过用户ID获取用户信息
	uint32_t get_userinfo_by_id(const CGet_userinfo_by_idInput &input, CGet_userinfo_by_idOutput &output);
	// 获取全部的人员信息
	uint32_t get_all_userinfo(std::list<CGet_all_userinfoOutput> &output);
	// 删除一个或多个用户
	uint32_t delete_user(const std::list<CDelete_userInput> &input);
	// 更新用户名
	uint32_t update_username(const CUpdate_usernameInput &input);
	// 更新用户名2
	uint32_t update_username_2(const CUpdate_username_2Input &input);
	// 更新用户名3
	uint32_t update_username_3(const CUpdate_username_3Input &input);
	// 更新用户名4
	uint32_t update_username_4(const CUpdate_username_4Input &input);

private:
	sqlite3 *m_db;
	std::mutex m_mutex;
};

}

#endif // __USER_INFO_DB_HANDLER_H__
