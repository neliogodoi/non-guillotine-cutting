#include "config.h"

const char* DIR_TEST = "./in/";
const char* ARG_FF = "-ff";
const char* ARG_BF = "-bf";
const char* ARG_HM = "-hm";
const char* ARG_MH = "-mh";

void load_line_argument(int argc, char **argv, line_argument* argument) {
   
  if (argc != 4) {
      print_help();
      exit(1);
  }

  if (strcmp(argv[1], "-f") == 0) {
    argument->file_name = argv[2];
    argument->opt_heuristic = argv[3];
  }
  else if (strcmp(argv[2], "-f") == 0) {
    argument->file_name = argv[3];
    argument->opt_heuristic = argv[1];
  }
  else {
    print_help();
    exit(1);
  }
}

double get_time ()
{
	struct timeval tv; gettimeofday(&tv, 0);
	return (double)(tv.tv_sec * 100.0 + tv.tv_usec / 10000.0);
}

void print_help() {
    printf("Informe os seguintes par�metros para a execu��o do programa:\n");
    printf("-f <nome do arquivo de entrada situado no diret�rio ./in>\n");
    printf("-ff <para execu��o da heur�stica construtiva first-fit>\n");
    printf("-bf <para execu��o da heur�stica construtiva best-fit>\n");
    printf("-hm <para execu��o da heur�stica de melhoramento>\n");
    printf("-mh <para execu��o da meta-heur�stica GRASP\n");
}