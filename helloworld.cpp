/*    @file helloworld.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 8/31/14  */

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){

  int tvalue = 0;
  char *nvalue = NULL;
  int n;
     
  opterr = 0;
     
  while ((n = getopt (argc, argv, "t:n:")) != -1){
    switch (n){
      case 't':
        tvalue = atoi(optarg);
        break;
      case 'n':
        nvalue = optarg;
        break;
     case '?':
        if (optopt == 'n'){
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        }
        if (optopt == 't'){
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        }
        else if (isprint (optopt)){
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        }
        else{
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        }
        return 1; 
      default:
        abort ();
    }
  }

  if(tvalue!=0){
    int t = 1;
    while(t<=tvalue){
      if(nvalue != NULL){
        cout << "[" << t << "] Hello " << nvalue << "!\n";	
      }
      else{
        cout << "[" << t << "] Hello World!\n";
      } 
      t++;
    }
  }

  else{
    if(nvalue != NULL){
      cout << "Hello " << nvalue << "!\n";	
    }
    else{
     cout << "Hello World!\n";
    } 
  }
  
  return 0;

}
