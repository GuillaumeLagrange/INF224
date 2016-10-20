#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>


class Media
{
    protected :
        std::string mediaName;
        std::string path;

    public:
        Media();
        Media(std::string mediaName, std::string path);
        virtual ~Media() {}

        std::string getMediaName() const;
        void setMediaName(std::string mediaName);

        std::string getPath() const;
        void setPath(std::string path);

        virtual void printMedia(std::ostream& stream) const;
        virtual void play() const = 0;
};

#endif // MEDIA_H
