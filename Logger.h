#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <stdlib.h>

namespace ode
{

	class Logger
	{
	private:

		/*The Start Time of our Logger*/
		std::chrono::time_point<std::chrono::system_clock> startTime;

		std::chrono::time_point<std::chrono::system_clock> currentTime;

		bool isRunning;

		double elapsedTime;

	public:

		Logger();

		~Logger() = default;

		Logger(const Logger&) = delete;

		Logger(const Logger&&) = delete;

		const Logger& operator=(const Logger&) = delete;

		void logData(const std::string);

		void logData(const std::string,const std::string);

		void stop();


	};
}