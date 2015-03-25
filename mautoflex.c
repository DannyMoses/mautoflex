#include <stdio.h>
#include <string.h>

int main(int argc, char** argv[]) {
  FILE *pScript = fopen("tmpscript", "w");
  if (pScript == NULL) {
    perror("The following error occurred");
    return -1;
  }
  char* shebangstr = "#! /bin/bash";
  char* flexstr = "flex";
  char* compilestr1 = "g++";
  char* compilestr2 = "lex.yy.c";
  char* compilestr3 = "-lfl";
  char* compilestr4 = "-o";
  char flexName[256];
  char finalName[256];

  printf("Welcome to mautoflex, the automatic flexer/compiler thing!\n");
  printf("What is the name of your .l file?\n");

  fscanf(stdin, "%s", flexName);

  printf("What is the name of the compiled project?");

  fscanf(stdin, "%s", finalName);

  printf("OK< here I go!\n");
  printf("generating script...\n");
  fprintf(pScript, "%s", shebangstr);
  fprintf(pScript, "%s", "\n");
  fprintf(pScript, "%s", flexstr);
  fprintf(pScript, "%s", " ");
  fprintf(pScript, "%s", flexName);
  fprintf(pScript, "%s", "\n");
  fprintf(pScript, "%s", compilestr1);
  fprintf(pScript, "%s", " ");
  fprintf(pScript, "%s", compilestr2);
  fprintf(pScript, "%s", " ");
  fprintf(pScript, "%s", compilestr3);
  fprintf(pScript, "%s", " ");
  fprintf(pScript, "%s", compilestr4);
  fprintf(pScript, "%s", " ");
  fprintf(pScript, "%s", finalName);
  
  fclose(pScript);

  system("chmod +x tmpscript");

  printf("Done creating script. Running...\n");
  
  system("./tmpscript");

  printf("Finished. Deleting script...\n");

  system("rm tmpscript");

  printf("Finished. Enjoy!\n");

  return 0;
}



