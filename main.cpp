#include "media.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"

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
    /* OK */
//    int * tab = new int[5] {1, 2, 3, 5, 4};
//    Film * film = new Film("avi", "~/50_shades_of_gray", 95);
//    film->printMedia(std::cout);
//    cout << '\n';
//    film->setChapters(tab, 5);
//    film->printMedia(cout);
//    cout << '\n';
//    delete [] tab;
//    film->printMedia(cout);

//    tab = new int[5] {5,4,3,2,1};
//    film->setChapters(tab, 5);
//    film->printMedia(cout);

//	delete film;

    /* TEST OF GROUPPS*/
    Photo * photo1 = new Photo("lena1", "media/lena");
    Photo * photo2 = new Photo("lena2", "media/lena");
    Photo * photo3 = new Photo("lena3", "media/lena");

    Video * vid1 = new Video("avi", "media/sample1");

    Film * film1 = new Film("avi", "~/50_shades_of_gray1", 95);

    Group * group1 = new Group ("Groupe 1");
    Group * group2 = new Group ("Groupe 2");

    group1->push_back(photo1);
    group1->push_back(vid1);
    group1->push_back(film1);

    group2->push_back(photo1);
    group2->push_back(photo2);
    group2->push_back(photo3);

    group1->printGroup(cout);
    group2->printGroup(cout);

    delete group1;
    cout << "Deleted group 1 \n \n";

    group2->printGroup(cout);

    delete group2;
    cout << "Deleted group 2 \n \n";

    delete photo1;
    delete photo2;
    delete photo3;
    delete vid1;
    delete film1;
    cout << "Deleted media files \n";
}
