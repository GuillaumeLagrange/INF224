#include "media.h"
using namespace std;

Media::Media()
{
    path = "";
    mediaName = "";
}

Media::Media(string _mediaName, string _path)
{
    path = _path;
    mediaName = _mediaName;
}

string Media::getMediaName() const
{
    return this->mediaName;
}

void Media::setMediaName(string name)
{
    mediaName = name;
}

string Media::getPath() const
{
    return path;
}

void Media::setPath(string p)
{
    path=p;
}

void Media::printMedia(ostream& stream) const
{
    stream << "Path : " << this->getPath() << '\n' << "Media name : "
           << this->getMediaName() << '\n';
}

//void Media::play() const {}
Media::~Media()
{
    std::cout << "Media " << path << " deleted\n\n";
}
