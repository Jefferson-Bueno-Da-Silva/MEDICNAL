#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
    char nomearquivo[50];
    DIR *dir;
    struct dirent *lsdir;


    dir = opendir(".\\PIM_Agendamento\\");

    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        strcpy(nomearquivo, lsdir->d_name);
        printf (" --> %s\n", nomearquivo);
    }

    closedir(dir);

    return 0;
	return 0;
}
