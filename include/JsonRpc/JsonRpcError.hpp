#ifndef __JSONRPC_ERROR_HPP__
#define __JSONRPC_ERROR_HPP__

#include <json11.hpp>

#include <JsonRpc/JsonRpcCommon.hpp>

namespace JsonRpc
{
	class JsonRpcError
	{
	public:
		JsonRpcError();
		JsonRpcError(JsonRpcErrorCode code);
		JsonRpcError(JsonRpcErrorCode code, const std::string& message);
		JsonRpcError(JsonRpcErrorCode code, const std::string& message, const json11::Json& data);

		static JsonRpcError Parse(const json11::Json& json);

		operator bool() const;

		JsonRpcErrorCode Code() const;
		const std::string& Message() const;
		const json11::Json& Get(const std::string& key) const;

	private:
		JsonRpcErrorCode m_code;
		std::string m_message;
		json11::Json m_data;
	};
}

#endif // __JSONRPC_ERROR_HPP__
