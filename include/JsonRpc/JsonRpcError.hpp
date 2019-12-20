#ifndef __JSONRPC_ERROR_HPP__
#define __JSONRPC_ERROR_HPP__

#include <json11.hpp>

#include <JsonRpc/JsonRpcCommon.hpp>

namespace JsonRpc
{
	enum class JsonRpcErrorCodes : JsonRpcErrorCode
	{
		// Invalid JSON was received by the server.
		// An error occurred on the server while parsing the JSON text.
		ParseError = -32700,
		// The JSON sent is not a valid Request object.
		InvalidRequest = -32600,
		// The method does not exist / is not available.
		MethodNotFound = -32601,
		// Invalid method parameter(s).
		InvalidParams = -32602,
		// Internal JSON-RPC error.
		InternalError = -32603
	};

	class JsonRpcError
	{
	public:
		JsonRpcError();
		JsonRpcError(JsonRpcErrorCode code);
		JsonRpcError(JsonRpcErrorCode code, const std::string& message);
		JsonRpcError(JsonRpcErrorCode code, const std::string& message, const json11::Json& data);

		static JsonRpcError Parse(const json11::Json& json);

		operator bool() const;

		bool IsServerError() const;
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
