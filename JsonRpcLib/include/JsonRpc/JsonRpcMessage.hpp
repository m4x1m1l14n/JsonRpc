#ifndef __JSON_RPC_MESSAGE_HPP__
#define __JSON_RPC_MESSAGE_HPP__

#include <JsonRpc/JsonRpcCommon.hpp>
#include <JsonRpc/JsonRpcId.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		class JsonRpcMessage
		{
		public:
			JsonRpcMessage();
			JsonRpcMessage(JsonRpcId id);

			JsonRpcId Id() const;

		protected:
			JsonRpcId m_id;
		};
	}
}

#endif // __JSON_RPC_MESSAGE_HPP__
