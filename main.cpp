#include <tmxlite/ObjectTypes.hpp>
#include <tmxlite/FreeFuncs.hpp>
#include <iostream>
#include <sstream>

#define ASSETS "../"

using namespace std;

std::string to_string(const tmx::Colour& colour)
{
    std::ostringstream ss;
    ss << "(";
    ss << "r: " << +colour.r << ", ";
    ss << "g: " << +colour.g << ", ";
    ss << "b: " << +colour.b << ", ";
    ss << "a: " << +colour.a;
    ss << ")";
    return ss.str();
}

int main()
{
    tmx::ObjectTypes file;
    file.load(ASSETS "objecttypes.xml");

    const auto &types = file.getTypes();

    for(const auto& type : types)
    {
        cout << "Found type '" << type.name << "', colour: " << to_string(type.colour) << endl;
        cout << "Properties:" << endl;

        for(const auto& prop : type.properties)
        {
            const auto& name = prop.getName();

            cout << "-- " << name << ", default is ";
            if(name == "expired") cout << boolalpha << prop.getBoolValue();
            else if(name == "level") cout << prop.getIntValue();
            else if(name == "life") cout << prop.getFloatValue();
            else if(name == "name") cout << prop.getStringValue();
            else if(name == "spells") cout << prop.getFileValue();
            cout << endl;
        }
    }

    return 0;
}