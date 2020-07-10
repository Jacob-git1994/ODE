#include "OutputManager.h"

using namespace ode;

OutputManager::OutputManager(Logger* log, const std::string path = "DefaultDir", const std::string fName = "default.txt",bool output = true) :
	logger(log),
	directory(path),
	fileName(fName),
	shouldWeOutput(output),
	isFileOpen(false)
{

	if (shouldWeOutput)
	{
		outFile.open(fileName.c_str());
		if (!outFile.is_open())
		{
			logger->logData("Unable to open file",__FILE__,__LINE__);

			isFileOpen = false;

			shouldWeOutput = false;
		}
		else
		{
			isFileOpen = true;
		}
	}
	else
	{
		logger->logData("Not Recording Data",__FILE__,__LINE__);
	}
}

OutputManager::~OutputManager()
{
	if (isFileOpen)
	{
		outFile.close();
		isFileOpen = false;
	}
}

void OutputManager::recordOutput(double time, const std::valarray<double>& stateVector)
{
	if (shouldWeOutput)
	{
		logger->logData("Recording Data",__FILE__,__LINE__);

		outFile << time << "\t";

		for (const auto& stateElement : stateVector)
		{
			outFile << stateElement << "\t";
		}
		outFile << "\n";
	}
}

void OutputManager::recordOutput(std::ostream& outStream, double time, const std::valarray<double>& stateVector)
{
	logger->logData("Recording Data to Command Prompt",__FILE__,__LINE__);

	outStream << time << "\t";

	for (const auto& stateElement : stateVector)
	{
		outStream << stateElement << "\t";
	}
	outStream << "\n";
}