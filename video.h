#ifndef VIDEO_H
#define VIDEO_H
#include "media.h"
#include <string>
#include <cstdlib>

class Video : public Media
{
    public:
        Video(std::string mName = "", std::string p = "", int d = 0)
        {
            mediaName = mName;
            path = p;
            duration = d;
        }


        virtual int getDuration() const {return duration;}
        virtual void setDuration(int d) {duration = d;}

        void printMedia(std::ostream& str) const override
        {
            str << "This file is a VIDEO \n"
                << "Path : " << path << '\n'
                << "Type of file : " << mediaName << '\n'
                << "Duration : " << duration << "\n \n";
        }

        void play() const override
        {
            system(("xdg-open " + this->getPath() + '&').c_str());
        }

    protected:
        int duration;
};

#endif // VIDEO_H
