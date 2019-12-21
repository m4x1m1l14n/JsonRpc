#include <JsonRpc/JsonRpcMessage.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		JsonRpcMessage::JsonRpcMessage()
		{

		}

		JsonRpcMessage::JsonRpcMessage(JsonRpcId id)
			: m_id(id)
		{

		}

		JsonRpcId JsonRpcMessage::Id() const
		{
			return m_id;
		}
	}
}
