#include <JsonRpc/JsonRpcId.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		JsonRpcId::JsonRpcId()
		{

		}

		JsonRpcId::JsonRpcId(int id)
		{
			m_value = id;
		}

		JsonRpcId::JsonRpcId(const std::string & id)
		{
			m_value = id;
		}

		json11::Json JsonRpcId::Id() const
		{
			return m_value;
		}

		json11::Json JsonRpcId::to_json() const
		{
			return m_value;
		}
	}
}
