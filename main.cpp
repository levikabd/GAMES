#include <vector>
#include <string>

#include "gwindow.h"


int main()
{
    std::vector<std::string> listG;
    listG.push_back("Tank");
    listG.push_back("x / 0");
    listG.push_back("Fly");
    listG.push_back("EXIT");

    int res = gwin(listG);

    return res;
}
