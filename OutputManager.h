#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <valarray>
#include <stdexcept>
#include "Logger.h"

namespace ode
{
	class OutputManager
	{
	private:
		Logger* logger;

		std::string directory;

		std::string fileName;

		std::fstream outFile;

		bool shouldWeOutput;

		bool isFileOpen;

	public:

		OutputManager() = delete;

		OutputManager(const OutputManager&) = delete;

		OutputManager(const OutputManager&&) = delete;

		const OutputManager& operator=(const OutputManager&) = delete;

		OutputManager(Logger*, const std::string, const std::string,bool);

		~OutputManager();

		const inline std::string& getDirectory() const { return directory; };

		const inline std::string& getFileName() const { return fileName; };

		const inline bool& output() const { return shouldWeOutput; };
		
		const inline bool& isOpen() const { return isFileOpen; }

		void recordOutput(double, const std::valarray<double>&);

		void recordOutput(std::ostream&, double, const std::valarray<double>&);


	};
}
