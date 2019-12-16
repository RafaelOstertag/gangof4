#include <algorithm>
#include <cerrno>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

const std::string spaces{"    "};

void printHelp(char* cmd) {
    std::cout << cmd << " <file> <varName> <filename> <output>\n\n";
    std::cout << "<file>\t\tfile to convert into C-string\n";
    std::cout << "<varName>\tvariable name\n";
    std::cout << "<filename>\tfile name of '.cxx' and '.hh' files\n";
    std::cout << "<output>\toutput directory.\n\n";
}

std::vector<unsigned char> readFile(const std::string& filename) {
    std::ifstream instream{filename.c_str(), std::ios_base::binary};
    if (!instream) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot open file '" << filename << "': ";
        errorMessage << std::strerror(errno);

        throw std::invalid_argument(errorMessage.str());
    }

    std::vector<unsigned char> binaryFile;
    binaryFile.reserve(8196);

    for (unsigned char c = instream.get(); !instream.eof();
         c = instream.get()) {
        binaryFile.push_back(c);
    }

    return binaryFile;
}

void writeHHFile(const std::string& filename,
                 const std::string& outputDirectory, const std::string& varName,
                 const std::vector<unsigned char>& data) {
    std::ofstream hhFile{outputDirectory + "/" + filename + ".hh",
                         std::ios_base::trunc};

    std::string uppercaseFilename{filename};
    std::for_each(uppercaseFilename.begin(), uppercaseFilename.end(),
                  [](char& c) { c = ::toupper(c); });

    std::string structName = varName + "Struct";
    structName[0] = std::toupper(structName[0]);

    hhFile << "#ifndef __" << uppercaseFilename << "_HH\n";
    hhFile << "#define __" << uppercaseFilename << "_HH\n\n";

    hhFile << "struct " << structName << " {\n";
    hhFile << spaces << "int size;\n";
    hhFile << spaces << "char "
           << "data"
           << "[" << data.size() + 1 << "];\n";
    hhFile << "};\n\n";

    hhFile << "extern " << structName << " " << varName << ";\n";

    hhFile << "#endif\n";
}

void writeCXXFile(const std::string& filename,
                  const std::string& outputDirectory,
                  const std::string& varName,
                  const std::vector<unsigned char>& data) {
    std::ofstream cxxFile{outputDirectory + "/" + filename + ".cxx",
                          std::ios_base::trunc};

    std::string structName = varName + "Struct";
    structName[0] = std::toupper(structName[0]);

    cxxFile << "#include \"" << filename << ".hh\"\n\n";
    cxxFile << structName << " " << varName << " = {\n";
    cxxFile << spaces << data.size() << ",\n";

    int charCounter = 0;
    std::string nextDataLine{"\"\n"};
    for (auto c : data) {
        if (charCounter == 0) {
            cxxFile << spaces << "\"";
        }

        cxxFile << "\\x" << std::setfill('0') << std::setw(2) << std::hex
                << int(c);

        charCounter++;

        if (charCounter >= 30) {
            cxxFile << nextDataLine;
            charCounter = 0;
        }
    }

    if (charCounter != 0) {
        cxxFile << nextDataLine;
    }
    cxxFile << "};\n";
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printHelp(argv[0]);
        return 1;
    }

    try {
        auto fileContent = readFile(argv[1]);

        writeHHFile(argv[3], argv[4], argv[2], fileContent);
        writeCXXFile(argv[3], argv[4], argv[2], fileContent);

        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
}
