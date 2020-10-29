#include "XmlConfigParcer.h"

//constexpr std::string_view server = "Server";

const std::string root = "root";

const std::string server = "Server";
const std::string servername = "servername";
const std::string serverdisplayname = "serverdisplayname";
const std::string listenerport = "listenerport";

const std::string communicationsettings = "communicationsettings";
const std::string blocking = "blocking";
const std::string socket_timeout = "socket_timeout";

const std::string logging = "logging";
const std::string filename = "filename";
const std::string LogLevel = "LogLevel";
const std::string flush = "flush";

const std::string Time = "time";
const std::string period_time = "Period_time";

const std::string threadpool = "threadpool";
const std::string maxworkingthreads = "maxworkingthreads";


bool XmlConfigParcer::Deserialization() 
{

	std::ifstream input(this->m_file_path);

	if (this->m_file_path.empty() || !input)
		return false;

	using boost::property_tree::ptree;

	ptree pt;
	read_xml(input, pt);

	BOOST_FOREACH(ptree::value_type const& v, pt.get_child(root))
	{
		if (v.first == server)
		{
			this->Server.m_server_name = v.second.get<std::string>(servername);
			this->Server.m_server_display_name = v.second.get<std::string>(serverdisplayname);
			this->Server.m_listen_port = v.second.get<int>(listenerport);
		}

		if (v.first == communicationsettings)
		{
			this->Server.m_blocking = v.second.get<bool>(blocking);
			this->Server.m_socket_timeout = v.second.get<int>(socket_timeout);
		}

		if (v.first == logging)
		{
			this->Logger.m_file_name = v.second.get<std::string>(filename);
			this->Logger.m_log_level = v.second.get<int>(LogLevel);
			this->Logger.m_flush = v.second.get<bool>(flush);
		}

		if (v.first == Time)
		{
			this->Server.m_period_time = v.second.get<int>(period_time);
		}

		if (v.first == threadpool)
		{
			this->Server.m_max_working_threads = v.second.get<int>(maxworkingthreads);
		}
	}
	return true;
}

bool XmlConfigParcer::Serialization()
{
	return false;
}

bool XmlConfigParcer::GetServerInfo(ServerInfo& obj) const
{
	if (!CheckServerValues())
	{
		return false;
	}
	else
	{
		obj = this->Server;
		return true;
	}
}

bool XmlConfigParcer::GetLoggerInfo(LoggerInfo& obj) const
{
	if (!CheckLoggerValues())
	{
		return false;
	}
	else
	{
		obj = this->Logger;
		return true;
	}
}

bool XmlConfigParcer::PutServerInfo(const ServerInfo& obj)
{
	Reset();
	this->Server.m_server_name = obj.m_server_name;
	this->Server.m_server_display_name = obj.m_server_display_name;
	this->Server.m_listen_port = obj.m_listen_port;
	this->Server.m_period_time = obj.m_period_time;
	this->Server.m_socket_timeout = obj.m_socket_timeout;
	this->Server.m_max_working_threads = obj.m_max_working_threads;
	this->Server.m_blocking = obj.m_blocking;
	return true;
}

bool XmlConfigParcer::PutLoggerInfo(const LoggerInfo& obj)
{
	Reset();
	this->Logger.m_file_name = obj.m_file_name;
	this->Logger.m_log_level = obj.m_log_level;
	this->Logger.m_flush = obj.m_flush;
	return true;
}

bool XmlConfigParcer::CheckServerValues() const
{
	if (Server.m_server_name == "" 
		|| Server.m_server_display_name == ""
		|| Server.m_listen_port == 0 
		|| Server.m_period_time == 0
		|| Server.m_socket_timeout == 0 
		|| Server.m_max_working_threads == 0 
		|| Server.m_blocking > 1)
		return false;
	else
		return true;

}

bool XmlConfigParcer::CheckLoggerValues() const
{
	if (Logger.m_file_name == "" || Logger.m_log_level > 3 || Logger.m_flush > 1)
		return false;
	else
		return true;
}

bool XmlConfigParcer::Reset()
{
	this->Server.m_server_name = "";
	this->Server.m_server_display_name = "";
	this->Server.m_listen_port = 0;
	this->Server.m_period_time = 0;
	this->Server.m_socket_timeout = 0;
	this->Server.m_max_working_threads = 0;
	this->Server.m_blocking = false;

	this->Logger.m_file_name = "";
	this->Logger.m_log_level = 0;
	this->Logger.m_flush = false;

	return true;
}

void XmlConfigParcer::show() const
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
