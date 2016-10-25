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

bool FileManager::printMedia(std::string name, std::ostream& str)
{
    auto it = mediaMap.find(name);
    if (it == mediaMap.end())
    {
        str << "Media " << name << " not found" << std::endl << std::endl;
        return false;
    } else
    {
        str << "Media " << name << " found" << std::endl << std::endl;
        it->second->printMedia(str);
        return true;
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

bool FileManager::printGroup(std::string name, std::ostream &str)
{
    auto it = groupMap.find(name);
    if (it == groupMap.end())
    {
        str << "Group " << name << " not found" << std::endl << std::endl;
        return false;
    } else
    {
        str << "Group " << name << " found" << std::endl << std::endl;
        it->second->printGroup(str);
        return true;
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

bool FileManager::processRequest(TCPConnection &cnx,
                                 const string &request, string &response)
{
   cerr << "\nRequest: '" << request << "'" << endl;

   // Request parsing
   std::string action, name;
   std::stringstream str;
   str << request;
   str >> action;
   str >> name;

   // Locking ressources
   TCPLock lock(cnx);

   // Treating request
   std::stringstream answer_str;
   bool searched, played;
   searched = false;
   played = false;
   if (action == "search")
   {
       searched = printGroup(name, answer_str);
       if (!searched)
       {
           searched = printMedia(name, answer_str);
       }
   }
   if (action == "play")
   {
       playMedia(name);
   }

   // Sending response
  if(played || searched)
      response = answer_str.str();
  else
      response = "Error : no such file";
  cerr << "response: " << response << endl;

  return true;
}
