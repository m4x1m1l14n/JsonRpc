#include <JsonRpc/JsonRpcRequest.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		JsonRpcRequest::JsonRpcRequest(JsonRpcId id, const std::string & method, const json11::Json & params)
			: JsonRpcMessage(id)
			, m_method(method)
			, m_params(params)
		{
			if (m_method.empty())
			{
				throw std::invalid_argument("method cannot be empty!");
			}
		}

		const std::string & JsonRpcRequest::Method() const
		{
			return m_method;
		}

		const json11::Json & JsonRpcRequest::Params() const
		{
			return m_params;
		}

		json11::Json JsonRpcRequest::to_json() const
		{
			return json11::Json::object
			({
				{ "jsonrpc", "2.0" },
				{ "id", m_id },
				{ "method", m_method },
				{ "params", m_params }
			});
		}

		std::string JsonRpcRequest::str() const
		{
			return to_json().dump();
		}

		JsonRpcRequest JsonRpcRequest::Parse(const std::string & data)
		{
			std::string error;

			const auto& json = json11::Json::parse(data, error);
			if (!error.empty())
			{
				throw std::invalid_argument("Not a valid JSON");
			}

			return JsonRpcRequest::Parse(json);
		}

		JsonRpcRequest JsonRpcRequest::Parse(const json11::Json & json)
		{
			if (!json["jsonrpc"].is_string() || json["jsonrpc"].string_value() != "2.0")
			{
				throw std::invalid_argument("Not a valid JSON RPC message. Missing jsorpc specifier.");
			}

			return JsonRpcRequest
			(
				json["id"].int_value(),
				json["method"].string_value(),
				json["params"]
			);
		}

		JsonRpcRequest JsonRpcRequest::Create(int id, const std::string & method, const json11::Json & params)
		{
			return JsonRpcRequest(id, method, params);
		}
	}
}
