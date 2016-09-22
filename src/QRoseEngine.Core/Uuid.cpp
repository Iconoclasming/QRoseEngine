#include "Uuid.hpp"

#include <algorithm>

extern "C"
{
#ifdef _WIN32
#include <rpc.h>
#include <rpcnterr.h>
#else
#include <uuid/uuid.h>
#endif
}

using namespace QRose;

const Uuid Uuid::Zero = Uuid::FromString("00000000-0000-0000-0000-000000000000");

Uuid::Uuid(std::string uuid)
{
	this->uuid = uuid;
}

Uuid::Uuid() : Uuid(GenerateUuid())
{
}

Uuid Uuid::GenerateUuid()
{
#ifdef WIN32
	UUID uuid;
	UuidCreate(&uuid);
	unsigned char* str;
	UuidToStringA(&uuid, &str);
	std::string s = (char*)str;
	RpcStringFreeA(&str);
	return FromString(s);
#else
	uuid_t uuid;
	uuid_generate_random(uuid);
	char s[37];
	uuid_unparse(uuid, s);
	return Uuid(s);
#endif
}

Uuid Uuid::FromString(std::string uuidString)
{
#ifdef WIN32
	UUID uuid;
	unsigned char* str = (unsigned char*)uuidString.c_str();
	RPC_STATUS status = UuidFromStringA(str, &uuid);
	if (status != RPC_S_OK)
	{
		throw std::invalid_argument("UUID string was in invalid");
	}
	std::string s((char*)str);
	return Uuid(s);
#else
	// TODO: linux implementation
#endif
}

bool Uuid::operator==(const Uuid & rhs) const
{
	return this->uuid == rhs.uuid;
}

bool Uuid::operator<(const Uuid & rhs) const
{
	return this->uuid < rhs.uuid;
}

std::string Uuid::ToString() const
{
	return uuid;
}

std::ostream& QRose::operator<<(std::ostream& s, const Uuid& id)
{
	return s << id.ToString();
}

Uuid QRose::operator >> (std::istream& s, Uuid& id)
{
	std::string uuidString;
	s >> uuidString;
	return Uuid::FromString(uuidString);
}