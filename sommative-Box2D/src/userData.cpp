#include "userData.h"

UserData::UserData()
{
	m_type = UserDataType::NONE;
}

UserData::UserData(UserDataType type_) : m_type(type_)
{
	m_localId = -1;
}

UserDataType UserData::getUserDataType()
{
	return m_type;
}

void UserData::setType(UserDataType type_)
{
	m_type = type_;
}

void UserData::setLocalId(signed long id_)
{
	m_localId = id_;
}

signed long UserData::getLocalId()
{
	return m_localId;
}

const std::string UserData::UserDataTypeToString(UserDataType type_)
{

	switch (type_)
	{
	case UserDataType::BALL:
		return "BALL";
		break;
	case UserDataType::BOUNCER:
		return "BOUNCER";
		break;
	case UserDataType::DEATH:
		return "DEATH";
		break;
	case UserDataType::GOAL:
		return "WIN";
		break;
	case UserDataType::NONE:
	default:
		return "NONE";
		break;
	}
}
