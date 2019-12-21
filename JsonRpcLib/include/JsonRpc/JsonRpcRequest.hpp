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
			JsonRpcRequest(JsonRpcId id, const std::string& method, const json11::Json& params);

			const std::string& Method() const;
			const json11::Json& Params() const;

			json11::Json to_json() const;

			std::string str() const;

			static JsonRpcRequest Parse(const std::string& data);
			static JsonRpcRequest Parse(const json11::Json& json);

			static JsonRpcRequest Create(int id, const std::string& method, const json11::Json& params);

		private:
			std::string m_method;
			json11::Json m_params;
		};
	}
}

#endif // !__JSON_RPC_REQUEST_HPP__
