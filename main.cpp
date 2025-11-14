#include <vector>
#include <string>

#include "welcome.h"
#include "bay.h"
#include "selectionw.h"


int main()
{
    //std::vector<std::string> listG;
    // listG.push_back("Tank");
    // listG.push_back("x / 0");
    // listG.push_back("Fly");
    // listG.push_back("EXIT");

    welcome();

    //int res = selection(listG);
    int res = selection();

    bay();

    return res;
};
