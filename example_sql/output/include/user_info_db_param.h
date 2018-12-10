#ifndef __USER_INFO_DB_PARAM_H__
#define __USER_INFO_DB_PARAM_H__

#include <string>
#include <list>

namespace user_info
{

class CAdd_userinfoInput
{
public:
	explicit CAdd_userinfoInput()
		: username(""), userage(0) {}
	explicit CAdd_userinfoInput(const std::string &username, const int &userage)
		: username(username), userage(userage) {}
	virtual ~CAdd_userinfoInput() {}

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

class CGet_userinfo_by_idInput
{
public:
	explicit CGet_userinfo_by_idInput()
		: id(0) {}
	explicit CGet_userinfo_by_idInput(const int &id)
		: id(id) {}
	virtual ~CGet_userinfo_by_idInput() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }

private:
	int id;
	bool idUsed;
};

class CGet_userinfo_by_idOutput
{
public:
	explicit CGet_userinfo_by_idOutput()
		: id(0), username(""), userage(0) {}
	explicit CGet_userinfo_by_idOutput(const int &id, const std::string &username, const int &userage)
		: id(id), username(username), userage(userage) {}
	virtual ~CGet_userinfo_by_idOutput() {}

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

class CGet_all_userinfoOutput
{
public:
	explicit CGet_all_userinfoOutput()
		: id(0), username(""), userage(0) {}
	explicit CGet_all_userinfoOutput(const int &id, const std::string &username, const int &userage)
		: id(id), username(username), userage(userage) {}
	virtual ~CGet_all_userinfoOutput() {}

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

class CDelete_userInput
{
public:
	explicit CDelete_userInput()
		: id(0) {}
	explicit CDelete_userInput(const int &id)
		: id(id) {}
	virtual ~CDelete_userInput() {}

public:
	void setId(const int &id, bool use = true) { this->id = id; this->idUsed = use; }
	const int &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }

private:
	int id;
	bool idUsed;
};

class CUpdate_usernameInput
{
public:
	explicit CUpdate_usernameInput()
		: username(""), id(0) {}
	explicit CUpdate_usernameInput(const std::string &username, const int &id)
		: username(username), id(id) {}
	virtual ~CUpdate_usernameInput() {}

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

class CUpdate_username_2Input
{
public:
	explicit CUpdate_username_2Input()
		: id(0), username("") {}
	explicit CUpdate_username_2Input(const int &id, const std::string &username)
		: id(id), username(username) {}
	virtual ~CUpdate_username_2Input() {}

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

class CUpdate_username_3Input
{
public:
	explicit CUpdate_username_3Input()
		: id(0), username("") {}
	explicit CUpdate_username_3Input(const int &id, const std::string &username)
		: id(id), username(username) {}
	virtual ~CUpdate_username_3Input() {}

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

class CUpdate_username_4Input
{
public:
	explicit CUpdate_username_4Input()
		: id(""), username("") {}
	explicit CUpdate_username_4Input(const std::string &id, const std::string &username)
		: id(id), username(username) {}
	virtual ~CUpdate_username_4Input() {}

public:
	void setId(const std::string &id, bool use = true) { this->id = id; this->idUsed = use; }
	const std::string &getId() const { return this->id; }
	const bool &getIdUsed() const { return this->idUsed; }
	void setUsername(const std::string &username, bool use = true) { this->username = username; this->usernameUsed = use; }
	const std::string &getUsername() const { return this->username; }
	const bool &getUsernameUsed() const { return this->usernameUsed; }

private:
	std::string id;
	bool idUsed;
	std::string username;
	bool usernameUsed;
};

}

#endif // __USER_INFO_DB_PARAM_H__
