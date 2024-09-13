#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <windows.h>

using namespace std;

class Error {
private:
    string errorMessage{};
    string errorPath{};
public:
    // Error() = default;

    // Writes to the log file.
    void logErrorMsg() const {
        cout << "Logging message..." << endl;

        string logName = errorPath + "/log.txt"; // The slash "/" is actually different from the backslashes "/", but it works fine.
        cout << logName << endl;

        ofstream logFile(logName, ios::app);

        // Opening file error.
        if(logFile.fail())
        {
            cerr << "Error opening file. Please check your file path and permissions.";
            return;
        }

        logFile << errorMessage << endl;
        logFile.close();

        if(logFile.fail()) {
            cerr << "Error writing to file. Please check your available disk space and permissions.";
        }
    }

    // Sets the error message.
    void setErrorMsg(const string& x) {
        cout << "Setting message..." << endl;
        errorMessage = x;
    }

    // Gets the absolute path.
    string getPath() {
        cout << "Getting path..." << endl;
        char buffer[MAX_PATH];
        GetModuleFileName( NULL, buffer, MAX_PATH );
        string::size_type pos = string( buffer ).find_last_of( "\\/" );
        string path = string( buffer ).substr( 0, pos);

        cout << path << endl;
        return path;

    }

    void setPath(const string& x) {
        cout << "Setting path..." << endl;
        errorPath = x;
    }
};



int main() {
    int input = 0;
    while (true) {
        if(!(cin >> input)){
            cin.clear(); //clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the rest of the line
            cout << "Please enter a valid integer" << endl;
            Error err;
            err.setErrorMsg("Please enter a valid integer");
            err.setPath(err.getPath());
            err.logErrorMsg();
            continue;
        }
        break;
    }
    cout << input;
}
