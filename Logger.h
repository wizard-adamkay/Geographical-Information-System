//
// Created by Adam k on 11/22/2022.
//

#ifndef GISPROJECT_LOGGER_H
#define GISPROJECT_LOGGER_H

#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;
class Logger {
public:
    Logger(const string& logFileName, const string& dbFileName, const string& scriptFileName) {
        fileName = logFileName;
        logFile.open(logFileName);
        auto nowTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        logFile << "Course Project for COMP 8042\n";
        logFile << "Student Name: Adam Krawchuk, Student Id: A00966518\n";
        logFile << "Begin of GIS Program log:\n";
        logFile << "dbFile:\t" << dbFileName << "\n";
        logFile << "script:\t" << scriptFileName << "\n";
        logFile << "log:\t" << logFileName << "\n";
        logFile << "Start Time: " << ctime(&nowTime) << endl;
    }

    void log(const string& slog){
        logFile << slog << "\n";
//        cout << slog << endl;
    }

    void shutdown() {
        logFile << "Terminating execution of commands." << endl;
        logFile << "------------------------------------------------------------------------------------------" << endl;
        auto nowTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        logFile << "End time: " << ctime(&nowTime) << endl;
        exit(0);
    }

private:
    string fileName;
    ofstream logFile;
};
#endif //GISPROJECT_LOGGER_H
