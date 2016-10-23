#include "filemanager.h"

FileManager::FileManager(MediaMap mMap, GroupMap gMap)
{
    mediaMap = mMap;
    groupMap = gMap;
}

MediaPtr FileManager::createPhoto(std::string mName,
                                  std::string path, int longi, int lat)
{
    PhotoPtr ptr(new Photo(mName, path, longi, lat));
    mediaMap[mName] = ptr;
    ptr.reset();
    return mediaMap[mName];
}

MediaPtr FileManager::createVideo(std::string mName,
                                  std::string path, int duration)
{
    VideoPtr ptr(new Video(mName, path, duration));
    mediaMap[mName] = ptr;
    ptr.reset();
    return mediaMap[mName];
}

MediaPtr FileManager::createFilm(std::string mName,
                                 std::string path, int duration, int *chap, int cNb)
{
    FilmPtr ptr(new Film(mName, path, duration, chap, cNb));
    mediaMap[mName] = ptr;
    ptr.reset();
    return mediaMap[mName];
}

GroupPtr FileManager::createGroup(std::string name)
{
    GroupPtr ptr(new Group(name));
    groupMap[name] = ptr;
    ptr.reset();
    return groupMap[name];
}

void FileManager::printMedia(std::string name, std::ostream& str)
{
    auto it = mediaMap.find(name);
    if (it == mediaMap.end())
    {
        str << "Media " << name << " not found" << std::endl << std::endl;
    } else
    {
        str << "Media " << name << " found" << std::endl << std::endl;
        it->second->printMedia(str);
    }
}

void FileManager::deleteMedia(std::string name)
{
//	for (auto it = groupMap.begin(); it != groupMap.end(); )
//    {

//    }
    auto it = mediaMap.find(name);
    if (it != mediaMap.end())
    {
        for (auto i = groupMap.begin(); i != groupMap.end(); i++)
            i->second->remove(it->second);
        mediaMap.erase(it);
    }
}

void FileManager::printGroup(std::string name, std::ostream &str)
{
    auto it = groupMap.find(name);
    if (it == groupMap.end())
    {
        str << "Group " << name << " not found" << std::endl << std::endl;
    } else
    {
        str << "Group " << name << " found" << std::endl << std::endl;
        it->second->printGroup(str);
    }
}

void FileManager::deleteGroup(std::string name)
{
    auto it = groupMap.find(name);
    if (it != groupMap.end())
    {
        groupMap.erase(it);
    }
}

void FileManager::addFileToGroup(std::string fileName, std::string groupName)
{
    auto it = mediaMap.find(fileName);
    if (it != mediaMap.end())
    {
        auto i = groupMap.find(groupName);
        if (i != groupMap.end())
        {
            (*i->second).push_back(it->second);
        }
    }
}

void FileManager::playMedia(std::string name)
{
    auto it = mediaMap.find(name);
    if (it != mediaMap.end())
    {
        it->second->play();
    }
}
