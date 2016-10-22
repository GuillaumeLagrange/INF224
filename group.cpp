#include "group.h"

Group::Group(std::string n)
{
    name = n;
}

std::string Group::getName()
{
    return name;
}

void Group::printGroup(std::ostream& str)
{
    str << "Group name : " << name << '\n';
    for (Media * media : *this)
    {
        media->printMedia(str);
    }
}
