#include <JsonRpc/JsonRpcError.hpp>

namespace m4x1m1l14n
{
	namespace JsonRpc
	{
		JsonRpcError::JsonRpcError()
			: JsonRpcError(0)
		{

		}

		JsonRpcError::JsonRpcError(JsonRpcErrorCode code)
			: JsonRpcError(code, std::string())
		{

		}

		JsonRpcError::JsonRpcError(JsonRpcErrorCode code, const std::string & message)
			: JsonRpcError(code, message, json11::Json::NUL)
		{

		}

		JsonRpcError::JsonRpcError(JsonRpcErrorCode code, const std::string & message, const json11::Json & data)
			: m_code(code)
			, m_message(message)
			, m_data(data)
		{

		}

		JsonRpcError JsonRpcError::Parse(const json11::Json & json)
		{
			const auto code = json["code"].is_number()
				? json["code"].int_value()
				: throw std::invalid_argument("Error code not present in input JSON object.");

			return JsonRpcError
			(
				code,
				json["message"].string_value(),
				json
			);
		}

		JsonRpcError::operator bool() const
		{
			return (m_code != 0);
		}

		bool JsonRpcError::IsServerError() const
		{
			return (m_code >= -32000 && m_code <= -32099);
		}

		JsonRpcErrorCode JsonRpcError::Code() const
		{
			return m_code;
		}

		const std::string & JsonRpcError::Message() const
		{
			return m_message;
		}

		const json11::Json & JsonRpcError::Get(const std::string & key) const
		{
			return m_data[key];
		}
	}
}
