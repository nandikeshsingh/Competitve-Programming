#include<bits/stdc++.h>
using namespace std;
int main()
{
        enum EnumTemperatureUnits {
        ENUM_TEMPERATURE_UNITS_UNSPECIFIED=100,
        ENUM_TEMPERATURE_UNITS_CELSIUS=-2000000000000000000,
        ENUM_TEMPERATURE_UNITS_FAHRENHEIT=1393
    };

    //     enum EnumTemperatureUnits {
    //     ENUM_TEMPERATURE_UNITS_UNSPECIFIED=0;
    //     ENUM_TEMPERATURE_UNITS_CELSIUS=1;
    //     ENUM_TEMPERATURE_UNITS_FAHRENHEIT=2;
    // }

    EnumTemperatureUnits temp=ENUM_TEMPERATURE_UNITS_CELSIUS;
    cout<<temp<<endl;
    // for(auto &u : temp)cout<<u<<endl;
    return 0;
}


