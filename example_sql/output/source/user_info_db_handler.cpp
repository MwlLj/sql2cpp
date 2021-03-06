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
		std::string sql("");
		sql = "\
create table if not exists user_info(\
	id integer primary key auto_increment,\
	username varchar(32),\
	userage int\
);\
create table if not exists user_info(\
	id integer primary key auto_increment,\
	username varchar(32),\
	userage int\
);";
		conn->exec(sql);
		sql = "\
create table if not exists user_info(\
	id integer primary key auto_increment,\
	username varchar(32),\
	userage int\
);";
		conn->exec(sql);
	}
	m_connPool.freeConnect(conn);
}

CDbHandler::~CDbHandler()
{
}

uint32_t CDbHandler::addUserinfo(const std::list<CAddUserinfoInput> &input0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	for (auto iter = input0.begin(); iter != input0.end(); ++iter)
	{
		ss << "insert into user_info values(null, " << "'" << iter->getUsername().c_str() << "'" << ", " << "'" << iter->getUserage() << "'" << ");";
		sql = ss.str();
		ss.str("");
		result = conn->exec(sql);
		if (!result) break;
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::getUserinfoById(const CGetUserinfoByIdInput &input0, CGetUserinfoByIdOutput &output0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	ss << "select * from user_info\
		where id = " << "'" << input0.getId() << "'" << ";";
	sql = ss.str();
	ss.str("");
	sql::IRow *row = conn->query(sql, result);
	if (result == true && row != nullptr) {
		while (row->next()) {
			std::vector<std::string> cols;
			cols.resize(3);
			bool b = row->scan(cols);
			if (!b) continue;
			std::stringstream ss;
			int id = 0;
			ss << cols[0];
			ss >> id;
			ss.clear();
			output0.setId(id);
			output0.setUsername(cols[1]);
			int userage = 0;
			ss << cols[2];
			ss >> userage;
			ss.clear();
			output0.setUserage(userage);
		}
		row->close();
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::getAllUserinfo(std::list<CGetAllUserinfoOutput> &output0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	sql = "select * from user_info;";
	sql::IRow *row = conn->query(sql, result);
	if (result == true && row != nullptr) {
		output0.clear();
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
			ss.clear();
			tmp.setId(id);
			tmp.setUsername(cols[1]);
			int userage = 0;
			ss << cols[2];
			ss >> userage;
			ss.clear();
			tmp.setUserage(userage);
			output0.push_back(tmp);
		}
		row->close();
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::deleteUser(const std::list<CDeleteUserInput> &input0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	for (auto iter = input0.begin(); iter != input0.end(); ++iter)
	{
		ss << "delete from user_info where id = " << "'" << iter->getId() << "'" << ";";
		sql = ss.str();
		ss.str("");
		result = conn->exec(sql);
		if (!result) break;
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::updateUsername(const CUpdateUsernameInput &input0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	ss << "update user_info set username = " << "'" << input0.getUsername().c_str() << "'" << " where id = " << "'" << input0.getId() << "'" << ";";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::updateUsername2(const CUpdateUsername2Input &input0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	ss << "update user_info set username = " << "'" << input0.getUsername().c_str() << "'" << " where id = " << "'" << input0.getId() << "'" << ";";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::updateUsername3(const CUpdateUsername3Input &input0, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	ss << "update user_info set username = " << "'" << input0.getUsername().c_str() << "'" << " " << input0.getCondition().c_str() << ";";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::noParamTest(bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	sql = "select * from user_info;";
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::subTest(const CUpdateUsernameInput &input0, const CSubTestInput &input1, const std::list<CDeleteUserInput> &input2, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	ss << "update user_info set username = " << "'" << input0.getUsername().c_str() << "'" << " where id = " << "'" << input0.getId() << "'" << ";";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	ss << "insert into user_info values(null, " << "'" << input1.getUserName().c_str() << "'" << ", " << "'" << input1.getUserAge() << "'" << ");";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	for (auto iter = input2.begin(); iter != input2.end(); ++iter)
	{
		ss << "delete from user_info where id = " << "'" << iter->getId() << "'" << ";";
		sql = ss.str();
		ss.str("");
		result = conn->exec(sql);
		if (!result) break;
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::subTestPro(const CUpdateUsernameInput &input0, const CSubTestInput &input1, const std::list<CDeleteUserInput> &input2, const CSubTestProInput &input3, const std::list<CAddUserinfoInput> &input4, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	ss << "update user_info set username = " << "'" << input0.getUsername().c_str() << "'" << " where id = " << "'" << input0.getId() << "'" << ";";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	ss << "insert into user_info values(null, " << "'" << input1.getUserName().c_str() << "'" << ", " << "'" << input1.getUserAge() << "'" << ");";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	for (auto iter = input2.begin(); iter != input2.end(); ++iter)
	{
		ss << "delete from user_info where id = " << "'" << iter->getId() << "'" << ";";
		sql = ss.str();
		ss.str("");
		result = conn->exec(sql);
		if (!result) break;
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	ss << "insert into user_info values(null, " << "'" << input3.getUserName().c_str() << "'" << ", " << "'" << input3.getUserAge() << "'" << ");";
	sql = ss.str();
	ss.str("");
	result = conn->exec(sql);
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	for (auto iter = input4.begin(); iter != input4.end(); ++iter)
	{
		ss << "insert into user_info values(null, " << "'" << iter->getUsername().c_str() << "'" << ", " << "'" << iter->getUserage() << "'" << ");";
		sql = ss.str();
		ss.str("");
		result = conn->exec(sql);
		if (!result) break;
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

uint32_t CDbHandler::subOutputTest(const std::list<CSubOutputTestInput> &input0, CSubOutputTestOutput &output0, std::list<CGetAllUserinfoOutput> &output1, const std::list<CAddUserinfoInput> &input2, bool isAlreayStartTrans /* = false */, sql::IConnect *reuseConn /* = nullptr*/)
{
	uint32_t ret = 0;

	sql::IConnect *conn = nullptr;
	sql::ITransaction *trans = nullptr;
	bool result = false;
	std::string sql("");
	if (!isAlreayStartTrans) {
		conn = m_connPool.connect(m_dial);
		if (conn == nullptr) return -1;
		trans = conn->begin();
		if (trans == nullptr) {
			m_connPool.freeConnect(conn);
			return -1;
		}
	}
	else {
		conn = reuseConn;
	}
	std::stringstream ss;
	for (auto iter = input0.begin(); iter != input0.end(); ++iter)
	{
		ss << "update user_info set username = " << "'" << iter->getUserName().c_str() << "'" << ";\
		select username from user_info;";
		sql = ss.str();
		ss.str("");
		sql::IRow *row = conn->query(sql, result);
		if (result == true && row != nullptr) {
			while (row->next()) {
				std::vector<std::string> cols;
				cols.resize(1);
				bool b = row->scan(cols);
				if (!b) continue;
				std::stringstream ss;
				output0.setUserName(cols[0]);
			}
			row->close();
		}
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	sql = "select * from user_info;";
	sql::IRow *row = conn->query(sql, result);
	if (result == true && row != nullptr) {
		output1.clear();
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
			ss.clear();
			tmp.setId(id);
			tmp.setUsername(cols[1]);
			int userage = 0;
			ss << cols[2];
			ss >> userage;
			ss.clear();
			tmp.setUserage(userage);
			output1.push_back(tmp);
		}
		row->close();
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}
	for (auto iter = input2.begin(); iter != input2.end(); ++iter)
	{
		ss << "insert into user_info values(null, " << "'" << iter->getUsername().c_str() << "'" << ", " << "'" << iter->getUserage() << "'" << ");";
		sql = ss.str();
		ss.str("");
		result = conn->exec(sql);
		if (!result) break;
	}
	if (!isAlreayStartTrans) {
		if (result) {
			trans->commit();
		}
		else {
			trans->rollback();
		}
		m_connPool.freeConnect(conn);
	}

	if (!result) {
		ret = 1;
	}

	return ret;
}

/*@@start@@*/

}

