#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static const int MAX_SIZE = 1024*1024;
static const char* O_RDONLY = "r";

void write_error(char* msg){
  fprintf(stderr, "Error handling files: %s\n", msg);
}

char* read_file(char* path)
{
  char* str;
  FILE* fp;
  int len;
  fp = fopen(path, O_RDONLY);
  if(!fp)
  {
    write_error(strerror(errno));
    exit(EXIT_FAILURE);
  }
  fseek(fp,0L,SEEK_END);
  len = ftell(fp);
  if(len > MAX_SIZE)
  {
    write_error("File too large");
    exit(EXIT_FAILURE);
  }
  fseek(fp,0L,SEEK_SET);
  str = malloc(len+1);
  if(!str)
  {
    write_error("Could not Allocate Memory");
    exit(EXIT_FAILURE);
  }
  fread(str,1,len,fp);
  fclose(fp);
  str[len+1]=0;
  return str;
};

