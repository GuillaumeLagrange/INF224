#ifndef PHOTO_H
#define PHOTO_H
#include "media.h"


class Photo : public Media
{
    public:
        Photo(std::string name = "", std::string p = "", int longi = 0, int lat = 0)
        {
            mediaName = name;
            path = p;
            longitude = longi;
            latitude = lat;
        }

    // GETTERS & SETTERS
        virtual int getLongitude() const {return longitude;}
        virtual int getLatitude() const {return latitude;}
        virtual void setLongitude(int l) {longitude = l;}
        virtual void setLatitude(int l) {latitude = l;}

    // FUNCTIONS
        void printMedia(std::ostream& str) const override
        {
            str << "This file is a PHOTO \n"
                << "Media name : " << mediaName << '\n'
                << "Path : " << path << '\n'
                << "Longitude : " << longitude << '\n'
                << "Latitude : " << latitude << "\n \n";
        }

        void play() const override
        {
            std::system(("xdg-open " + this->getPath() + '&').c_str());
        }


    private:
        int longitude;
        int latitude;
};

#endif // PHOTO_H
