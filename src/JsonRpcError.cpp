#include <JsonRpc/JsonRpcError.hpp>

namespace JsonRpc
{
	JsonRpcError::JsonRpcError()
		: JsonRpcError(0)
	{

	}

	JsonRpcError::JsonRpcError(uint64_t code)
		: JsonRpcError(code, std::string())
	{

	}

	JsonRpcError::JsonRpcError(uint64_t code, const std::string & message)
		: JsonRpcError(code, message, json11::Json::NUL)
	{

	}

	JsonRpcError::JsonRpcError(uint64_t code, const std::string & message, const json11::Json & data)
		: m_code(code)
		, m_message(message)
		, m_data(data)
	{

	}
}
