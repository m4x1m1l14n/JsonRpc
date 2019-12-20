#ifndef __JSON_RPC_MESSAGE_HPP__
#define __JSON_RPC_MESSAGE_HPP__

#include <json11.hpp>

namespace JsonRpc
{
	class JsonRpcMessage
	{
	public:
		JsonRpcMessage()
			: m_id(0)
		{

		}

		JsonRpcMessage(uint64_t id)
			: m_id(id)
		{
			if (m_id == 0)
			{
				throw std::invalid_argument("0 is not a valid Id value!");
			}
		}

		uint64_t getId() const
		{
			return m_id;
		}

	protected:
		uint64_t m_id;
	};
}

#endif // __JSON_RPC_MESSAGE_HPP__
