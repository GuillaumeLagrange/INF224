#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>

#include "media.h"

class Group : public std::list<Media*>
{
public:
    Group(std::string n);
    std::string getName();
    void printGroup(std::ostream&);

private:
    std::string name;
};

#endif // GROUP_H
