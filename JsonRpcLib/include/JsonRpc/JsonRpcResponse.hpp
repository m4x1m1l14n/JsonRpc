#ifndef __JSON_RPC_RESPONSE_HPP__
#define __JSON_RPC_RESPONSE_HPP__

#include <JsonRpc/JsonRpcMessage.hpp>
#include <JsonRpc/JsonRpcError.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		class JsonRpcResponse
			: public JsonRpcMessage
		{
		public:
			JsonRpcResponse();
			JsonRpcResponse(JsonRpcId id, const json11::Json& result);
			JsonRpcResponse(JsonRpcId id, const JsonRpcError& error);

			const json11::Json& Result() const;
			const JsonRpcError& Error() const;

			bool IsError() const;

			static JsonRpcResponse Parse(const std::string& data);
			static JsonRpcResponse Parse(const json11::Json& json);

		private:
			json11::Json m_result;
			JsonRpcError m_error;
		};
	}
}

#endif // !__JSON_RPC_RESPONSE_HPP__
