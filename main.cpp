#include <vector>
#include <string>

#include "gwindow.h"
#include "welcome.h"

int main()
{
    std::vector<std::string> listG;
    // listG.push_back("Tank");
    // listG.push_back("x / 0");
    // listG.push_back("Fly");
    // listG.push_back("EXIT");

    welcome();

    int res = gwin(listG);
    return res;
};
