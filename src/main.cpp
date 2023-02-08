#include <iostream>
#include <fstream>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dirent.h"

using namespace std;



/* when return 1, scandir will put this dirent to the list */
static int parse_ext(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) { /* only deal with regular file */
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           return 0;
         else {
           if(strcmp(ext, ".o") == 0) //OLD .ngl
             return 1;
         }
     }

     return 0;
}

int main(int argc, char *argv[])
{
	       struct dirent **namelist;
       int n;

       n = scandir(".", &namelist, parse_ext, alphasort);
       if (n < 0) {
           perror("scandir");
           return 1;
       }
       else {
           while (n--) {
			  //  ofstream myfile;
        //  myfile.open (namelist[n]->d_name);
        //  myfile << "Writing this to a file.\n";
        //  myfile.close();
               printf("%s\n", namelist[n]->d_name);
			   
               free(namelist[n]);
           }
           free(namelist);
       }

}