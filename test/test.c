#include <stdlib.h>
#include <stdio.h>

#include "../src/log.h"


int 
main(void)
{
    FILE * f_log = fopen("test_log.log", "w");
    Log * log = log_new(2, (FILE* []){stdout, f_log});

    if(log == NULL)
    {
        fprintf(stderr, "log_new NULL pointer returned!\n");
        return EXIT_FAILURE;
    }

    log_warning(log, "This is warning test with values: %d", 42);
    log_error(log, "This is error test with values: %s", "Warning msg");

    log_set_quiet(log, true);

    log_debug(log, "Log is off");
    
    if(log_is_quiet(log) == true)
        printf("Log is off\n");
    
    log_delete(log);
    fclose(f_log);
    
    printf("Test exit success\n");

    return EXIT_SUCCESS;
}

