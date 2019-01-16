#ifndef __USER_INFO_DB_PARAM_H__
#define __USER_INFO_DB_PARAM_H__

#include <string>
#include <list>

namespace user_info
{

class CAddUserinfoInput
{
public:
	explicit CAddUserinfoInput()
		: username(""), userage(0) {}
	explicit CAddUserinfoInput(const std::string &username, const int &userage)
		: username(username), userage(userage) {}
	virtual ~CAddUserinfoInput() {}

public:
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }
	void setUserage(const int &userage, bool use = true) { this->userage = userage; this->userageUsed = use; }
	const int &getUserage() const { return this->userage; }
	const bool &getUserageUsed() const { return this->userageUsed; }

private:
	std::string username;
	bool usernameUsed;
	int userage;
	bool userageUsed;
};

class CGetUserinfoByIdInput
{
public:
	explicit CGetUserinfoByIdInput()
		: id(0) {}
	explicit CGetUserinfoByIdInput(const int &id)
		: id(id) {}
	virtual ~CGetUserinfoByIdInput() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }

private:
	int id;
	bool idUsed;
};

class CGetUserinfoByIdOutput
{
public:
	explicit CGetUserinfoByIdOutput()
		: id(0), username(""), userage(0) {}
	explicit CGetUserinfoByIdOutput(const int &id, const std::string &username, const int &userage)
		: id(id), username(username), userage(userage) {}
	virtual ~CGetUserinfoByIdOutput() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }
	void setUserage(const int &userage, bool use = true) { this->userage = userage; this->userageUsed = use; }
	const int &getUserage() const { return this->userage; }
	const bool &getUserageUsed() const { return this->userageUsed; }

private:
	int id;
	bool idUsed;
	std::string username;
	bool usernameUsed;
	int userage;
	bool userageUsed;
};

class CGetAllUserinfoOutput
{
public:
	explicit CGetAllUserinfoOutput()
		: id(0), username(""), userage(0) {}
	explicit CGetAllUserinfoOutput(const int &id, const std::string &username, const int &userage)
		: id(id), username(username), userage(userage) {}
	virtual ~CGetAllUserinfoOutput() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }
	void setUserage(const int &userage, bool use = true) { this->userage = userage; this->userageUsed = use; }
	const int &getUserage() const { return this->userage; }
	const bool &getUserageUsed() const { return this->userageUsed; }

private:
	int id;
	bool idUsed;
	std::string username;
	bool usernameUsed;
	int userage;
	bool userageUsed;
};

class CDeleteUserInput
{
public:
	explicit CDeleteUserInput()
		: id(0) {}
	explicit CDeleteUserInput(const int &id)
		: id(id) {}
	virtual ~CDeleteUserInput() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }

private:
	int id;
	bool idUsed;
};

class CUpdateUsernameInput
{
public:
	explicit CUpdateUsernameInput()
		: username(""), id(0) {}
	explicit CUpdateUsernameInput(const std::string &username, const int &id)
		: username(username), id(id) {}
	virtual ~CUpdateUsernameInput() {}

public:
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }

private:
	std::string username;
	bool usernameUsed;
	int id;
	bool idUsed;
};

class CUpdateUsername2Input
{
public:
	explicit CUpdateUsername2Input()
		: id(0), username("") {}
	explicit CUpdateUsername2Input(const int &id, const std::string &username)
		: id(id), username(username) {}
	virtual ~CUpdateUsername2Input() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }

private:
	int id;
	bool idUsed;
	std::string username;
	bool usernameUsed;
};

class CUpdateUsername3Input
{
public:
	explicit CUpdateUsername3Input()
		: condition(""), username("") {}
	explicit CUpdateUsername3Input(const std::string &condition, const std::string &username)
		: condition(condition), username(username) {}
	virtual ~CUpdateUsername3Input() {}

public:
	void setCondition(const std::string &condition, bool use = true) { this->condition = condition; this->conditionUsed = use; }
	const std::string &getCondition() const { return this->condition; }
	const bool &getConditionUsed() const { return this->conditionUsed; }
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }

private:
	std::string condition;
	bool conditionUsed;
	std::string username;
	bool usernameUsed;
};

class CSubTestInput
{
public:
	explicit CSubTestInput()
		: userName(""), userAge(0) {}
	explicit CSubTestInput(const std::string &userName, const int &userAge)
		: userName(userName), userAge(userAge) {}
	virtual ~CSubTestInput() {}

public:
	void setUserName(const std::string &userName, bool use = true) { this->userName = userName; this->userNameUsed = use; }
	const std::string &getUserName() const { return this->userName; }
	const bool &getUserNameUsed() const { return this->userNameUsed; }
	void setUserAge(const int &userAge, bool use = true) { this->userAge = userAge; this->userAgeUsed = use; }
	const int &getUserAge() const { return this->userAge; }
	const bool &getUserAgeUsed() const { return this->userAgeUsed; }

private:
	std::string userName;
	bool userNameUsed;
	int userAge;
	bool userAgeUsed;
};

class CSubTestProInput
{
public:
	explicit CSubTestProInput()
		: userName(""), userAge(0) {}
	explicit CSubTestProInput(const std::string &userName, const int &userAge)
		: userName(userName), userAge(userAge) {}
	virtual ~CSubTestProInput() {}

public:
	void setUserName(const std::string &userName, bool use = true) { this->userName = userName; this->userNameUsed = use; }
	const std::string &getUserName() const { return this->userName; }
	const bool &getUserNameUsed() const { return this->userNameUsed; }
	void setUserAge(const int &userAge, bool use = true) { this->userAge = userAge; this->userAgeUsed = use; }
	const int &getUserAge() const { return this->userAge; }
	const bool &getUserAgeUsed() const { return this->userAgeUsed; }

private:
	std::string userName;
	bool userNameUsed;
	int userAge;
	bool userAgeUsed;
};

class CSubOutputTestInput
{
public:
	explicit CSubOutputTestInput()
		: userName("") {}
	explicit CSubOutputTestInput(const std::string &userName)
		: userName(userName) {}
	virtual ~CSubOutputTestInput() {}

public:
	void setUserName(const std::string &userName, bool use = true) { this->userName = userName; this->userNameUsed = use; }
	const std::string &getUserName() const { return this->userName; }
	const bool &getUserNameUsed() const { return this->userNameUsed; }

private:
	std::string userName;
	bool userNameUsed;
};

class CSubOutputTestOutput
{
public:
	explicit CSubOutputTestOutput()
		: userName("") {}
	explicit CSubOutputTestOutput(const std::string &userName)
		: userName(userName) {}
	virtual ~CSubOutputTestOutput() {}

public:
	void setUserName(const std::string &userName, bool use = true) { this->userName = userName; this->userNameUsed = use; }
	const std::string &getUserName() const { return this->userName; }
	const bool &getUserNameUsed() const { return this->userNameUsed; }

private:
	std::string userName;
	bool userNameUsed;
};

}

#endif // __USER_INFO_DB_PARAM_H__
