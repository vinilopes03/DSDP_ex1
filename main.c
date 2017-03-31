#include <stdlib.h>
#include <argp.h>

#define DATABASE_PATH "./database.dat"

/* Program version */
const char *argp_program_version = "0.1";

/* Email addres in case of bugs */
const char *argp_program_bug_address = "eduardoquijano2@gmail.com";

/* Program documentation */
static char doc[] = ""; // TODO

/* Description of the parameter */
static char args_doc[] = ""; // TODO

/* Acceptable options */ 
typedef enum  
{
    OPTION_CEP = 'c',
    OPTION_DESC = 'd'

} selectable_options;

static struct argp_option options[] = { 
    { "cep",         OPTION_CEP,    "CEP_NUM", 0, "CEP in it's long representation."},
    { "description", OPTION_DESC,   "DESCRITPION", 0, "Description of CEP"},
    { 0 } 
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{

    switch (key)
    {
        case OPTION_CEP:
            //arguments->num = atol(arg);
            printf("CEP: %s\n", arg );
            break;
        case OPTION_DESC:
            //arguments->description = strcpy(arguments->description, arg);
            printf("DESCRIPTION: %s\n", arg);
            break;
        case ARGP_KEY_ARG:
            /* No arguments */
            argp_usage (state);
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
  return EXIT_SUCCESS;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc };

int main (int argc, char **argv) 
{

    /* Parse arguments */
    argp_parse (&argp, argc, argv, 0, 0, NULL);

    return EXIT_SUCCESS;
}