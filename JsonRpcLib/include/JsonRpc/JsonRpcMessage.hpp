#ifndef __JSON_RPC_MESSAGE_HPP__
#define __JSON_RPC_MESSAGE_HPP__

#include <JsonRpc/JsonRpcCommon.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		class JsonRpcMessage
		{
		public:
			JsonRpcMessage()
				: m_id(0)
			{

			}

			JsonRpcMessage(int id)
				: m_id(id)
			{
				if (m_id == 0)
				{
					throw std::invalid_argument("0 is not a valid Id value!");
				}
			}

			int getId() const
			{
				return m_id;
			}

		protected:
			int m_id;
		};
	}
}

#endif // __JSON_RPC_MESSAGE_HPP__
