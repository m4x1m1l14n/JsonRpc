#ifndef __JSON_RPC_REQUEST_HPP__
#define __JSON_RPC_REQUEST_HPP__

#include <JsonRpc\JsonRpcMessage.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		class JsonRpcRequest
			: public JsonRpcMessage
		{
		public:
			JsonRpcRequest(int id, const std::string& method, const json11::Json& params)
				: JsonRpcMessage(id)
				, m_method(method)
				, m_params(params)
			{
				if (m_method.empty())
				{
					throw std::invalid_argument("method cannot be empty!");
				}
			}

			const std::string& getMethod() const
			{
				return m_method;
			}

			const json11::Json& getParams() const
			{
				return m_params;
			}

			json11::Json to_json() const
			{
				return json11::Json::object
				({
					{ "jsonrpc", "2.0" },
					{ "id", m_id },
					{ "method", m_method },
					{ "params", m_params }
					});
			}

			std::string str() const
			{
				return to_json().dump();
			}

			static JsonRpcRequest Parse(const std::string& data)
			{
				std::string error;

				const auto& json = json11::Json::parse(data, error);
				if (!error.empty())
				{
					throw std::invalid_argument("Not a valid JSON");
				}

				return JsonRpcRequest::Parse(json);
			}

			static JsonRpcRequest Parse(const json11::Json& json)
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

			static JsonRpcRequest Create(int id, const std::string& method, const json11::Json& params)
			{
				return JsonRpcRequest(id, method, params);
			}

		private:
			std::string m_method;
			json11::Json m_params;
		};
	}
}

#endif // !__JSON_RPC_REQUEST_HPP__
