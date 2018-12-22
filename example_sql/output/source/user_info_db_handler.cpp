#include <stdio.h>
#include <string.h>
#include <sstream>
#include "user_info_db_handler.h"

namespace user_info
{

CDbHandler::CDbHandler(const std::string &dial, sql::ISql *s, int max)
	: m_connPool(s, max)
	, m_dial(dial)
{
	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn != nullptr) {
		std::string sql = "\
create table if not exists user_info(\
	id integer primary key autoincrement,\
	username varchar(32),\
	userage int\
);\
create table if not exists user_info(\
	id integer primary key autoincrement,\
	username varchar(32),\
	userage int\
);\
create table if not exists user_info(\
	id integer primary key autoincrement,\
	username varchar(32),\
	userage int\
);";
		conn->exec(sql);
		m_connPool.freeConnect(conn);
	}
}

CDbHandler::~CDbHandler()
{
}

uint32_t CDbHandler::addUserinfo(const CAddUserinfoInput &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "insert into user_info values(null, " << "\"" << input.getUsername().c_str() << "\"" << ", " << "\"" << input.getUserage() << "\"" << ");";
	sql = ss.str();
	conn->exec(sql);
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::addMultiUserInfo(const std::list<CAddMultiUserInfoInput> &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	for (auto iter = input.begin(); iter != input.end(); ++iter)
	{
		std::stringstream ss;
		ss << "insert into user_info values(null, " << "\"" << iter->getUserName().c_str() << "\"" << ", " << "\"" << iter->getUserAge() << "\"" << ");";
		sql = ss.str();
		conn->exec(sql);
	}
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::getUserinfoById(const CGetUserinfoByIdInput &input, CGetUserinfoByIdOutput &output)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "select * from user_info\
		where id = " << "\"" << input.getId() << "\"" << ";";
	sql = ss.str();
	bool exeRet = false;
	sql::IRow *row = conn->query(sql, exeRet);
	if (exeRet == false) return -1;
	if (exeRet == true && row == nullptr) return 0;
	while (row->next()) {
		std::vector<std::string> cols;
		cols.resize(3);
		bool b = row->scan(cols);
		if (!b) continue;
		std::stringstream ss;
		int id = 0;
		ss << cols[0];
		ss >> id;
		ss.str("");
		output.setId(id);
		output.setUsername(cols[1]);
		int userage = 0;
		ss << cols[2];
		ss >> userage;
		ss.str("");
		output.setUserage(userage);
	}
	row->close();
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::getAllUserinfo(std::list<CGetAllUserinfoOutput> &output)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	std::string sql = "select * from user_info;";
	bool exeRet = false;
	sql::IRow *row = conn->query(sql, exeRet);
	if (exeRet == false) return -1;
	if (exeRet == true && row == nullptr) return 0;
	output.clear();
	while (row->next()) {
		std::vector<std::string> cols;
		cols.resize(3);
		bool b = row->scan(cols);
		if (!b) continue;
		CGetAllUserinfoOutput tmp;
		std::stringstream ss;
		int id = 0;
		ss << cols[0];
		ss >> id;
		ss.str("");
		tmp.setId(id);
		tmp.setUsername(cols[1]);
		int userage = 0;
		ss << cols[2];
		ss >> userage;
		ss.str("");
		tmp.setUserage(userage);
		output.push_back(tmp);
	}
	row->close();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::deleteUser(const std::list<CDeleteUserInput> &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	for (auto iter = input.begin(); iter != input.end(); ++iter)
	{
		std::stringstream ss;
		ss << "delete from user_info where id = " << "\"" << iter->getId() << "\"" << ";";
		sql = ss.str();
		conn->exec(sql);
	}
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::getUserInfo(const CGetUserInfoByNameInput &input, std::list<CGetUserInfoByNameOutput> &output)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "select * from user_info where username = " << "\"" << input.getUserName().c_str() << "\"" << ";";
	sql = ss.str();
	bool exeRet = false;
	sql::IRow *row = conn->query(sql, exeRet);
	if (exeRet == false) return -1;
	if (exeRet == true && row == nullptr) return 0;
	output.clear();
	while (row->next()) {
		std::vector<std::string> cols;
		cols.resize(3);
		bool b = row->scan(cols);
		if (!b) continue;
		CGetUserInfoByNameOutput tmp;
		std::stringstream ss;
		int id = 0;
		ss << cols[0];
		ss >> id;
		ss.str("");
		tmp.setId(id);
		tmp.setUserName(cols[1]);
		int userAge = 0;
		ss << cols[2];
		ss >> userAge;
		ss.str("");
		tmp.setUserAge(userAge);
		output.push_back(tmp);
	}
	row->close();
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::getUserInfo(const CGetUserInfoByAgeInput &input, std::list<CGetUserInfoByAgeOutput> &output)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "select * from user_info where userage = " << "\"" << input.getUserAge() << "\"" << ";";
	sql = ss.str();
	bool exeRet = false;
	sql::IRow *row = conn->query(sql, exeRet);
	if (exeRet == false) return -1;
	if (exeRet == true && row == nullptr) return 0;
	output.clear();
	while (row->next()) {
		std::vector<std::string> cols;
		cols.resize(3);
		bool b = row->scan(cols);
		if (!b) continue;
		CGetUserInfoByAgeOutput tmp;
		std::stringstream ss;
		int id = 0;
		ss << cols[0];
		ss >> id;
		ss.str("");
		tmp.setId(id);
		tmp.setUserName(cols[1]);
		int userAge = 0;
		ss << cols[2];
		ss >> userAge;
		ss.str("");
		tmp.setUserAge(userAge);
		output.push_back(tmp);
	}
	row->close();
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::updateUsername(const CUpdateUsernameInput &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "update user_info set username = " << "\"" << input.getUsername().c_str() << "\"" << " where id = " << "\"" << input.getId() << "\"" << ";";
	sql = ss.str();
	conn->exec(sql);
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::updateUsername2(const CUpdateUsername2Input &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "update user_info set username = " << "\"" << input.getUsername().c_str() << "\"" << " where id = " << "\"" << input.getId() << "\"" << ";";
	sql = ss.str();
	conn->exec(sql);
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::updateUsername3(const CUpdateUsername3Input &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	if (input.getIdUsed() == false) {
		ss << "update user_info set username = " << "\"" << input.getUsername().c_str() << "\"" << "  ;";
	}
	else if (input.getIdUsed() == true) {
		ss << "update user_info set username = " << "\"" << input.getUsername().c_str() << "\"" << " where id = " << "\"" << input.getId() << "\"" << ";";
	}
	sql = ss.str();
	conn->exec(sql);
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

uint32_t CDbHandler::updateUsername4(const CUpdateUsername4Input &input)
{
	uint32_t ret = 0;

	sql::IConnect *conn = m_connPool.connect(m_dial);
	if (conn == nullptr) return -1;
	sql::ITransaction *trans = conn->begin();
	if (trans == nullptr) return -1;
	std::string sql("");
	std::stringstream ss;
	ss << "update user_info set username = " << "\"" << input.getUsername().c_str() << "\"" << " " << input.getId().c_str() << ";";
	sql = ss.str();
	conn->exec(sql);
	trans->commit();
	m_connPool.freeConnect(conn);

	return ret;
}

/*@@start@@*/

}

