#include <JsonRpc/JsonRpcResponse.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		JsonRpcResponse::JsonRpcResponse()
			: JsonRpcMessage()
		{

		}

		JsonRpcResponse::JsonRpcResponse(JsonRpcId id, const json11::Json & result)
			: JsonRpcMessage(id)
			, m_result(result)
		{

		}

		JsonRpcResponse::JsonRpcResponse(JsonRpcId id, const JsonRpcError & error)
			: JsonRpcMessage(id)
			, m_error(error)
		{

		}

		const json11::Json & JsonRpcResponse::Result() const
		{
			return m_result;
		}

		const JsonRpcError & JsonRpcResponse::Error() const
		{
			return m_error;
		}

		bool JsonRpcResponse::IsError() const
		{
			return static_cast<bool>(m_error);
		}

		JsonRpcResponse JsonRpcResponse::Parse(const std::string & data)
		{
			std::string error;

			const auto& json = json11::Json::parse(data, error);
			if (!error.empty())
			{
				throw std::invalid_argument("Not a valid JSON");
			}

			return JsonRpcResponse::Parse(json);
		}

		JsonRpcResponse JsonRpcResponse::Parse(const json11::Json & json)
		{
			if (!json["jsonrpc"].is_string() || json["jsonrpc"].string_value() != "2.0")
			{
				throw std::invalid_argument("Not a valid JSON RPC message!");
			}

			return (json["error"].is_null())
				? JsonRpcResponse(json["id"].int_value(), json["result"])
				: JsonRpcResponse(json["id"].int_value(), JsonRpcError::Parse(json["error"]));
		}
	}
}
