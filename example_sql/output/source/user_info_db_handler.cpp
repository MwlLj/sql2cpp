#include <stdio.h>
#include <string.h>
#include <sstream>
#include "sqlite3.h"
#include "user_info_db_handler.h"

namespace user_info
{

CDbHandler::CDbHandler(const std::string &dbpath, bool isMemory)
	: m_db(nullptr)
	, m_mutex()
{
	sqlite3_threadsafe();
	sqlite3_config(SQLITE_CONFIG_MULTITHREAD);
	int ret = SQLITE_OK;
	if (isMemory == false) {
		ret = sqlite3_open(dbpath.c_str(), &m_db);
	}
	else {
		ret = sqlite3_open(":memory:", &m_db);
	}
	if (ret == SQLITE_OK) {
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
		sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	}
}

CDbHandler::~CDbHandler()
{
	sqlite3_close(m_db);
}

uint32_t CDbHandler::add_userinfo(const CAdd_userinfoInput &input)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	char buf[512];
	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf), "insert into user_info values(null, \"%s\", \"%d\");"
		, input.getUsername().c_str(), input.getUserage());
	sql = buf;
	ret = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();

	return ret;
}

int get_userinfo_by_idCallback(void *data, int colCount, char **colValue, char **colName)
{
	int ret = 0;

	CGet_userinfo_by_idOutput *p = reinterpret_cast<CGet_userinfo_by_idOutput*>(data);
	if (p == nullptr) return -1;
	std::stringstream ss;
	if (colValue[0] != nullptr) {
		int id = 0;
		ss << colValue[0];
		ss >> id;
		ss.clear();
		p->setId(id);
	}
	if (colValue[1] != nullptr) {
		p->setUsername(colValue[1]);
	}
	if (colValue[2] != nullptr) {
		int userage = 0;
		ss << colValue[2];
		ss >> userage;
		ss.clear();
		p->setUserage(userage);
	}

	return ret;
}
uint32_t CDbHandler::get_userinfo_by_id(const CGet_userinfo_by_idInput &input, CGet_userinfo_by_idOutput &output)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	char buf[512];
	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf), "select * from user_info\
		where id = \"%d\";"
		, input.getId());
	sql = buf;
	ret = sqlite3_exec(m_db, sql.c_str(), get_userinfo_by_idCallback, &output, nullptr);
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();

	return ret;
}

int get_all_userinfoCallback(void *data, int colCount, char **colValue, char **colName)
{
	int ret = 0;

	std::list<CGet_all_userinfoOutput> *p = reinterpret_cast<std::list<CGet_all_userinfoOutput>*>(data);
	if (p == nullptr) return -1;
	CGet_all_userinfoOutput tmp;
	std::stringstream ss;
	if (colValue[0] != nullptr) {
		int id = 0;
		ss << colValue[0];
		ss >> id;
		ss.clear();
		tmp.setId(id);
	}
	if (colValue[1] != nullptr) {
		tmp.setUsername(colValue[1]);
	}
	if (colValue[2] != nullptr) {
		int userage = 0;
		ss << colValue[2];
		ss >> userage;
		ss.clear();
		tmp.setUserage(userage);
	}
	p->push_back(tmp);

	return ret;
}
uint32_t CDbHandler::get_all_userinfo(std::list<CGet_all_userinfoOutput> &output)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	std::string sql = "select * from user_info;";
	ret = sqlite3_exec(m_db, sql.c_str(), get_all_userinfoCallback, &output, nullptr);
	m_mutex.unlock();

	return ret;
}

uint32_t CDbHandler::delete_user(const std::list<CDelete_userInput> &input)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	for (auto iter = input.begin(); iter != input.end(); ++iter)
	{
		char buf[512];
		memset(buf, 0, sizeof(buf));
		snprintf(buf, sizeof(buf), "delete from user_info where id = \"%d\";"
			, iter->getId());
		sql = buf;
		ret = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	}
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();
	if (ret != SQLITE_OK) return ret;

	return ret;
}

uint32_t CDbHandler::update_username(const CUpdate_usernameInput &input)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	char buf[512];
	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf), "update user_info set username = \"%s\" where id = \"%d\";"
		, input.getUsername().c_str(), input.getId());
	sql = buf;
	ret = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();

	return ret;
}

uint32_t CDbHandler::update_username_2(const CUpdate_username_2Input &input)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	char buf[512];
	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf), "update user_info set username = \"%s\" where id = \"%d\";"
		, input.getUsername().c_str(), input.getId());
	sql = buf;
	ret = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();

	return ret;
}

uint32_t CDbHandler::update_username_3(const CUpdate_username_3Input &input)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	char buf[512];
	memset(buf, 0, sizeof(buf));
	if (input.getIdUsed() == false) {
		snprintf(buf, sizeof(buf), "update user_info set username = \"%s\"  ;"
			, input.getUsername().c_str());
	}
	else if (input.getIdUsed() == true) {
		snprintf(buf, sizeof(buf), "update user_info set username = \"%s\" where id = \"%d\";"
			, input.getUsername().c_str(), input.getId());
	}
	sql = buf;
	ret = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();

	return ret;
}

uint32_t CDbHandler::update_username_4(const CUpdate_username_4Input &input)
{
	if (m_db == nullptr) return -1;
	uint32_t ret = 0;

	m_mutex.lock();
	sqlite3_exec(m_db, "begin transaction;", nullptr, nullptr, nullptr);
	std::string sql("");
	char buf[512];
	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf), "update user_info set username = \"%s\" %s;"
		, input.getUsername().c_str(), input.getId().c_str());
	sql = buf;
	ret = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
	sqlite3_exec(m_db, "commit;", nullptr, nullptr, nullptr);
	m_mutex.unlock();

	return ret;
}

/*@@start@@*/

}

