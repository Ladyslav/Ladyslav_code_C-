#pragma once
#include "Interface_Parcer.h"

class Parcer_XML : public Parcer_Interface
{
private:

	std::string m_file_path;

	struct Server_Info
	{
		std::string m_server_name;
		std::string m_server_display_name;

		int m_listen_port;
		int m_period_time;
		int m_socket_timeout;
		int m_max_working_threads;

		bool m_blocking;
	} Server;

	struct Logger_Info
	{
		std::string m_file_name;
		int m_log_level;
		bool m_flush = false;
	} Logger;

public:

	Parcer_XML() = delete;
	Parcer_XML(const std::string path) : m_file_path(path) {};
	Parcer_XML(const Parcer_XML& obj) = delete;
	Parcer_XML(const Parcer_XML&& obj) = delete;
	~Parcer_XML() {};

	void Deserialization();
	void Serialization();
	void show();
};

