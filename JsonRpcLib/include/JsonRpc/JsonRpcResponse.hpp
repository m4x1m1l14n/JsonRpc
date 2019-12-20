#ifndef __JSON_RPC_RESPONSE_HPP__
#define __JSON_RPC_RESPONSE_HPP__

#include <JsonRpc\JsonRpcMessage.hpp>
#include <JsonRpc\JsonRpcError.hpp>

namespace JsonRpc
{
	class JsonRpcResponse
		: public JsonRpcMessage
	{
	public:
		JsonRpcResponse()
			: JsonRpcMessage()
		{

		}

		JsonRpcResponse(uint64_t id, const json11::Json& result)
			: JsonRpcMessage(id)
			, m_result(result)
		{
		}

		JsonRpcResponse(uint64_t id, const JsonRpcError& error)
			: JsonRpcMessage(id)
			, m_error(error)
		{
		}

		const json11::Json& getResult() const
		{
			return m_result;
		}

		const JsonRpcError& getError() const
		{
			return m_error;
		}

		bool IsError() const
		{
			return static_cast<bool>(m_error);
		}

		static JsonRpcResponse Parse(const std::string& data)
		{
			std::string error;

			const auto& json = json11::Json::parse(data, error);
			if (!error.empty())
			{
				throw std::invalid_argument("Not a valid JSON");
			}

			return JsonRpcResponse::Parse(json);
		}

		static JsonRpcResponse Parse(const json11::Json& json)
		{
			if (!json["jsonrpc"].is_string() || json["jsonrpc"].string_value() != "2.0")
			{
				throw std::invalid_argument("Not a valid JSON RPC message!");
			}

			return (json["error"].is_null())
				? JsonRpcResponse(json["id"].int_value(), json["result"])
				: JsonRpcResponse(json["id"].int_value(), JsonRpcError::Parse(json["error"]));
		}

	private:
		json11::Json m_result;
		JsonRpcError m_error;
	};
}

#endif // !__JSON_RPC_RESPONSE_HPP__
