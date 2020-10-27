#include "Parcer_XML.h"

void Parcer_XML::Deserialization()
{
	std::ifstream input(this->m_file_path);

	if (this->m_file_path.empty() || !input)
		throw std::exception("Empty or File is not open");

	using boost::property_tree::ptree;

	ptree pt;
	read_xml(input, pt);

	BOOST_FOREACH(ptree::value_type const& v, pt.get_child("root"))
	{
		if (v.first == "Server")
		{
			this->Server.m_server_name = v.second.get<std::string>("servername");
			this->Server.m_server_display_name = v.second.get<std::string>("serverdisplayname");
			this->Server.m_listen_port = v.second.get<int>("listenerport");
		}

		if (v.first == "communicationsettings")
		{
			this->Server.m_blocking = v.second.get<bool>("blocking");
			this->Server.m_socket_timeout = v.second.get<int>("socket_timeout");
		}

		if (v.first == "logging")
		{
			this->Logger.m_file_name = v.second.get<std::string>("filename");
			this->Logger.m_log_level = v.second.get<int>("LogLevel");
			this->Logger.m_flush = v.second.get<bool>("flush");
		}

		if (v.first == "time")
		{
			this->Server.m_period_time = v.second.get<int>("Period_time");
		}

		if (v.first == "threadpool")
		{
			this->Server.m_max_working_threads = v.second.get<int>("maxworkingthreads");
		}
	}
}

void Parcer_XML::Serialization()
{

}

void Parcer_XML::show()
{
	std::cout << "-------------------SERVER-----------------" << '\n';
	std::cout << "Server_name: " << this->Server.m_server_name << '\n';
	std::cout << "Server_display_name: " << this->Server.m_server_display_name << '\n';
	std::cout << "Listen_port: " << this->Server.m_listen_port << '\n';
	std::cout << "Blocking: " << this->Server.m_blocking << '\n';
	std::cout << "Max_working_threads: " << this->Server.m_max_working_threads << '\n';
	std::cout << "Period_time: " << this->Server.m_period_time << '\n';
	std::cout << "Socket_timeout: " << this->Server.m_socket_timeout << '\n';

	std::cout << std::endl;

	std::cout << "-------------------LOGGER-----------------" << '\n';
	std::cout << "File_name: " << this->Logger.m_file_name << '\n';
	std::cout << "Log_level: " << this->Logger.m_log_level << '\n';
	std::cout << "Flush: " << this->Logger.m_flush << '\n';
}
