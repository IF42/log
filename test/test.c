#include <stdio.h>
#include <stdlib.h>
#include "../src/log.h"


int
main(void)
{
    FILE * log_file = fopen("log_file.log", "w");

    if(log_file == NULL)
        return EXIT_FAILURE;

    Log * log = log_new(2, (FILE*[2]) {stdout, log_file});

    if(log != NULL)
    {
        log_debug(log, "This is debug logging message");
        log_warning(log, "This is warning logging message");
        log_error(log, "This is error logging message");

        log_set_quiet(log, true);

        if(log_is_quiet(log) == true)
            printf("Log is now off\n");

        log_delete(log);
    }

    fclose(log_file);

    return EXIT_SUCCESS;
}
