#include "media.h"
#include "video.h"
#include "photo.h"
#include "film.h"

#include <string>
#include <iostream>
using namespace std;


int main ()
{
    /* TEST OF PRINTMEDIA AND PLAY FUNCTIONS */
    /* OK */

//    Video * vid = new Video("avi", "media/sample");
//    vid->printMedia(cout);
//    vid->play();

//    Photo * photo = new Photo("lena", "media/lena");
//    photo->printMedia(cout);
//    photo->play();


    /* TEST OF POLYMORPHISM */
    /* OK */

//    Media ** medias = new Media * [10];

//    unsigned int count = 0;
//    medias[count ++] = new Video("Video 1", "Path 1");
//    medias[count ++] = new Photo("Photo 1", "Path 2");
//    medias[count ++] = new Video("Video 2", "Path 3");

//    for (unsigned int k=0; k <count; k++)
//    {
//        medias[k]->printMedia(cout);
//    }
    
    /* TEST OF FILM CHAPTER TAB PROTECTION */
 int * tab = new int[5] {1, 2, 3, 5, 4};
 Film * film = new Film("avi", "~/50_shades_of_gray", 95);
 film->printMedia(std::cout);
 cout << '\n';
 film->setChapters(tab, 5);
 film->printMedia(cout);
 cout << '\n';
 delete tab;
 film->printMedia(cout);
}
