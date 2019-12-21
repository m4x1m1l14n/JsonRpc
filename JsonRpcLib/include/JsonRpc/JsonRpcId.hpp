#ifndef __JSON_RPC_ID_HPP__
#define __JSON_RPC_ID_HPP__

#include <JsonRpc/JsonRpcCommon.hpp>

namespace m4x1m1l14n
{
    namespace JsonRpc
    {
		class JsonRpcId
		{
		public:
			// null id ctor
			JsonRpcId();

			// int id ctor
			JsonRpcId(int id);

			// string id ctor
			JsonRpcId(const std::string& id);

			json11::Json Id() const;

			json11::Json to_json() const;

		private:
			json11::Json m_value;
		};
    }
}

#endif // __JSON_RPC_ID_HPP__
