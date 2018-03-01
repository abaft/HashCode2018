#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <tuple>
#include <string_view>

using uint = unsigned int;
using steps_t = long long unsigned int;

namespace consts
{
    uint gridRows;
    uint gridCols;
    uint vehiclesNum;
    uint ridesNum;
    uint perRideBonus;
    steps_t steps;
}

struct Ride
{
    uint rowBegin;
    uint colBegin;

    uint rowEnd;
    uint colEnd;

    uint earliestStart;
    uint latestFinish;
};

struct CarAssignment
{
    uint carNum;
    std::vector<uint> rides;
};

void writeOutput(const std::string_view& name, const std::vector<CarAssignment>& data)
{
    std::string fileName(name);
    fileName.append(".out");

    std::fstream file(fileName);

    for (const auto& carAss : data)
    {
        file << carAss.carNum;

        for (const auto ride : carAss.rides)
        {
            file << ' ';
            file << ride;
        }

        file << '\n';
    }
}

std::vector<Ride> rides;

namespace io
{
    void readFile(const std::string_view& str)
    {
        std::fstream file(str.data());

        file >> consts::gridRows;
        file >> consts::gridCols;
        file >> consts::vehiclesNum;
        file >> consts::ridesNum;
        file >> consts::perRideBonus;
        file >> consts::steps;

        while (!file.eof())
        {
            Ride ride;

            file >> ride.rowBegin;
            file >> ride.colBegin;

            file >> ride.rowEnd;
            file >> ride.colEnd;

            file >> ride.earliestStart;
            file >> ride.latestFinish;

            rides.push_back(ride);
        }

        file.close();
    }
}

int main(const int argc, const char** args)
{

    std::cout << "Ben is an idiot." << '\n';

    return 0;
}