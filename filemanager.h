#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "group.h"
#include "film.h"
#include "media.h"
#include "photo.h"
#include "video.h"

#include <map>

typedef std::shared_ptr<Media> MediaPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;

typedef std::map<std::string, MediaPtr> MediaMap;
typedef std::map<std::string, GroupPtr> GroupMap;

typedef std::shared_ptr<MediaMap> MediaMapPtr;
typedef std::shared_ptr<GroupMap> GroupMapPtr;

class FileManager
{
public:
    FileManager() {}
    FileManager(MediaMap mMap, GroupMap gMap);

    // File creation functions
    MediaPtr createPhoto(std::string mName,
                         std::string path, int longi, int lat);
    MediaPtr createVideo(std::string mName,
                         std::string path, int duration);
    MediaPtr createFilm(std::string mName,
                        std::string path, int duration, int * chap, int cNb);
    GroupPtr createGroup(std::string name);

    void printMedia(std::string name, std::ostream& str);
    void deleteMedia(std::string name);
    void printGroup(std::string name, std::ostream& str);
    void deleteGroup(std::string name);

    void addFileToGroup(std::string fileName, std::string groupName);
    void playMedia(std::string name);


private:
    MediaMap mediaMap;
    GroupMap groupMap;

};

#endif // FILEMANAGER_H
