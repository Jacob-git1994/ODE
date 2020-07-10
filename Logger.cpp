#include "Logger.h"

using namespace ode;

Logger::Logger() : 
	startTime(startTime = std::chrono::system_clock::now()), 
	isRunning(true),
	elapsedTime(0.)
{
	this->logData("Initalized Logger", __FILE__,__LINE__);
	//std::cout << "Elapsed Time\tLog Message\n";
}

void Logger::logData(const std::string msg)
{
	try
	{
		if (isRunning)
		{
			currentTime = std::chrono::system_clock::now();

			elapsedTime = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count());

			std::cout << std::left << elapsedTime << "\t\t" << msg << "\n";
		}
		else
		{
			throw std::runtime_error("Logger has stopped");
		}
	}
	catch (std::exception& e)
	{
		isRunning = true;

		this->logData(e.what(),__FILE__,__LINE__);

		isRunning = false;
	}
}

void Logger::logData(const std::string msg,const std::string fileName)
{
	try
	{
		if (isRunning)
		{
			currentTime = std::chrono::system_clock::now();

			elapsedTime = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count());

			std::cout << std::left << elapsedTime << "\t\t" << msg << "\t\t" << fileName << "\n";
		}
		else
		{
			throw std::runtime_error("Logger has stopped");
		}
	}
	catch (std::exception& e)
	{
		isRunning = true;

		this->logData(e.what(),__FILE__,__LINE__);

		isRunning = false;
	}
}

void Logger::logData(const std::string msg, const std::string fileName,const int lineNumber)
{
	try
	{
		if (isRunning)
		{
			currentTime = std::chrono::system_clock::now();

			elapsedTime = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count());

			std::cout << std::left << elapsedTime << "\t\t" << lineNumber << "\t\t" << msg << "\t\t" << fileName << "\n";
		}
		else
		{
			throw std::runtime_error("Logger has stopped");
		}
	}
	catch (std::exception& e)
	{
		isRunning = true;

		this->logData(e.what(), __FILE__,__LINE__);

		isRunning = false;
	}
}

void Logger::stop()
{
	isRunning = false;
}