#include "filemanager.h"
#include "media.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"

#include <string>
#include <iostream>
#include <memory>
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
    /* OK */
//    shared_ptr<Photo> photo1 (new Photo("lena1", "media/lena"));
//    shared_ptr<Photo> photo2 (new Photo("lena2", "media/lena"));
//    shared_ptr<Photo> photo3 (new Photo("lena3", "media/lena"));

//    shared_ptr<Video> vid1 (new Video("avi", "media/sample1"));

//    shared_ptr<Film> film1 (new Film("avi", "~/50_shades_of_gray1", 95));

//    shared_ptr<Group> group1 (new Group ("Groupe 1"));
//    shared_ptr<Group> group2 (new Group ("Groupe 2"));

//    group1->push_back(photo1);
//    group1->push_back(vid1);
//    group1->push_back(film1);

//    group2->push_back(photo1);
//    group2->push_back(photo2);
//    group2->push_back(photo3);

//    photo1.reset();
//    photo2.reset();
//    photo3.reset();
//    vid1.reset();
//    film1.reset();

//    group1->printGroup(cout);
//    group2->printGroup(cout);

//    group1.reset();
//    cout << "Deleted group 1 \n \n";

//    group2->printGroup(cout);

    /* TEST OF FILEMANAGER */
    /* OK */

    std::shared_ptr<FileManager> fm(new FileManager());

    fm->createPhoto("Photoname", "path", 0, 0);
    fm->printMedia("Photoname", std::cout);
    fm->printMedia("False Name", std::cout);

    fm->createGroup("Groupname");

    fm->addFileToGroup("Photoname", "Groupname");

    fm->createVideo("Videoname", "path", 10);
    fm->addFileToGroup("Videoname", "Groupname");
    fm->printGroup("Groupname", std::cout);

    fm->deleteMedia("Photoname");
    fm->printGroup("Groupname", std::cout);

    fm->deleteGroup("Groupname");
    fm->printMedia("Videoname", std::cout);

    fm->createGroup("PlayTest");
    fm->createPhoto("lena", "media/lena", 0, 0);
    fm->playMedia("lena");

}
