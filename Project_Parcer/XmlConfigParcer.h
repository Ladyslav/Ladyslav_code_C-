#pragma once
#include "IConfigParcer.h"

class XmlConfigParcer : public IConfigParcer
{
private:

	std::string m_file_path = "";

	struct ServerInfo
	{
		std::string m_server_name = "";
		std::string m_server_display_name = "";

		int m_listen_port = 0;
		int m_period_time = 0;
		int m_socket_timeout = 0;
		int m_max_working_threads = 0;

		bool m_blocking = false;
	} Server;

	struct LoggerInfo
	{
		std::string m_file_name = "";
		int m_log_level = 0;
		bool m_flush = false;
	} Logger;

public:

	XmlConfigParcer() = delete;
	XmlConfigParcer(const std::string path) : m_file_path(path) {};
	XmlConfigParcer(const XmlConfigParcer& obj) = delete;
	XmlConfigParcer(const XmlConfigParcer&& obj) = delete;
	~XmlConfigParcer() {};

	bool Deserialization() override;
	bool Serialization() override;
	bool GetServerInfo(ServerInfo& obj) const;
	bool GetLoggerInfo(LoggerInfo& obj) const;

	bool CheckValues() const;

	void show() const;
};

