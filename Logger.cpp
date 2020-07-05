#include "Logger.h"

using namespace ode;

Logger::Logger() : 
	startTime(startTime = std::chrono::system_clock::now()), 
	isRunning(true),
	elapsedTime(0.)
{
	//std::cout << "Elapsed Time\tLog Message\n";
}

void Logger::logData(const std::string msg = "This is default message")
{
	try
	{
		if (isRunning)
		{
			currentTime = std::chrono::system_clock::now();

			elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

			std::cout << elapsedTime << "\t\t" << msg << "\n";
		}
		else
		{
			throw std::runtime_error("Logger has stopped");
		}
	}
	catch (std::exception& e)
	{
		isRunning = true;

		this->logData(e.what(),__FILE__);

		isRunning = false;
	}
}

void Logger::logData(const std::string msg = "This is default message",const std::string fileName = "Unknown File")
{
	try
	{
		if (isRunning)
		{
			currentTime = std::chrono::system_clock::now();

			elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

			std::cout << elapsedTime << "\t\t" << msg << "\t\t" << fileName << "\n";
		}
		else
		{
			throw std::runtime_error("Logger has stopped");
		}
	}
	catch (std::exception& e)
	{
		isRunning = true;

		this->logData(e.what(),__FILE__);

		isRunning = false;
	}
}

void Logger::stop()
{
	isRunning = false;
}