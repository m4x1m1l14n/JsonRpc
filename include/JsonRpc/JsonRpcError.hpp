#ifndef __JSONRPC_ERROR_HPP__
#define __JSONRPC_ERROR_HPP__

#include <json11.hpp>

namespace JsonRpc
{
	class JsonRpcError
	{
	public:
		JsonRpcError();
		JsonRpcError(uint64_t code);
		JsonRpcError(uint64_t code, const std::string& message);
		JsonRpcError(uint64_t code, const std::string& message, const json11::Json& data);

		static JsonRpcError Parse(const json11::Json& json)
		{
			// TODO Handle inputs!

			return JsonRpcError
			(
				json["code"].int_value(),
				json["message"].string_value(),
				json
			);
		}

		operator bool() const
		{
			return (m_code != 0);
		}

		uint64_t getCode() const
		{
			return m_code;
		}

		const std::string& getMessage() const
		{
			return m_message;
		}

		/*
		// NOTE Do not know why but not building!
		const json11::Json& operator[](const std::string& key) const
		{
			return m_data[key];
		}
		*/

		const json11::Json& get(const std::string& key) const
		{
			return m_data[key];
		}

	private:
		uint64_t m_code;
		std::string m_message;
		json11::Json m_data;
	};
}

#endif // __JSONRPC_ERROR_HPP__
