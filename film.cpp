#include "film.h"


Film::Film(std::string mName, std::string p, int d, int *chap, int cNb) : Video(mName, p, d)
{
    chapters = new int[cNb];
    for (int i = 0; i < cNb; i++)
    {
        chapters[i] = chap[i];
    }
    chapNb = cNb;
}

Film::~Film()
{
    delete chapters;
}

void Film::setChapters(int *chap, int cNb)
{
    for (int i = 0; i < cNb; i++)
    {
        chapters[i] = chap[i];
    }
    chapNb = cNb;
}

int * Film::getChapters()
{
    int * chap = new int[chapNb];
    for(int i = 0; i < chapNb; i++)
    {
        chap[i] = chapters[i];
    }
    return chap;
}

int Film::getChapNumber()
{
    return chapNb;
}

void Film::printMedia(std::ostream &str)
{
    str << "This file is a FILM \n"
        << "Path : " << path << '\n'
        << "Media name : " << mediaName << '\n'
        << "Duration : " << duration << '\n'
        << "Number of chapters : " << chapNb << '\n';
    if (chapNb != 0)
    {
        str << "Chapters length :\n";
        for (int i = 0; i < chapNb; i++)
        {
        str << "Chapter " << i + 1 << " : " << chapters[i] << '\n';
        }
    }
    else
    {
        str << "No chapters specified \n";
    }
}

