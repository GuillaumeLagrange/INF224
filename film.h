#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <string>
#include <iostream>


class Film : public Video
{
public:
    Film(std::string mName = "", std::string p = "", int d = 0,
         int * chap = new int , int cNb = 0);
    int * getChapters() ;
    void setChapters(int * chap, int cNb);
    int getChapNumber();
    void printMedia(std::ostream&) ;
    ~Film();

private :
    int * chapters;
    int chapNb;
};

#endif // FILM_H
