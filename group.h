#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>

#include "media.h"

class Group : public std::list<std::shared_ptr<Media>>
{
public:
    Group(std::string n);
    std::string getName();
    void printGroup(std::ostream&);
    ~Group();

private:
    std::string name;
};

#endif // GROUP_H
