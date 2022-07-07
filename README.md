# C language logging library

Simple library for logging activity in c langauge 

# What is logging
Logging is process of recording internal activity of program during its running. This is useful mainly when happend something unexpected and nobody knows how and why. Logging output shows us sequence of step preceding of given accident and give us chance to find the source of problem. Log output can be redirected into various output streams. For example to terminal (stdout, stderr) or named file etc.

# Logging levels
Logging can be divided to so called levels. Logging levels are logging outputs with given severity. Most common logging levels are Debug, Warning and Error. Every level means how severe given logging message is. Debug messages inform only about common interesting processes inside software, for example every input or output event. Warning messages inform about unexpected fails inside sofware, but the software can continue running without any problems. Error levels are unexpected fails inside software which are very severe and usualy software can't continue running or it is information about error which is needed to solve. 

# What to log
In general is necessary to log everything what helps to solve occurred problems or find source of the issue. That are usually input and output events which are very often source of an issue. Next importent place to logging are main loops of program and state machines where are states transitions and wehere is possible to occure potentional unexpected behaves. 

# Tutorial
Target platforms are Linux or Window with MSYS system, or it is possible to use simply two source file copy pased into project. For build log library simply call make command:
```
$ make
$ make test
$ sudo make install INCLUDE_PATH=/usr/include/ LIB_PATH=/usr/lib/
```
Log library not opening or closing output streams for writing logging messages. This must be solved outside of the library. On the other hand this gives flexibility for registering of output logging streams. First of all is needed to prepare output streams. This could be file output or terminal output streams. 
```
#include <stdio.h>
#include <stdlib.h>
#include <log.h>


int
main(void)
{
    FILE * log_file = fopen("log_file.log", "w");

    if(log_file == NULL)
    {
        fprintf(stderr, "Can't open output logging file!\n");
        return EXIT_FAILURE;
    }

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
    else
        fprintf(stderr, "Can't initialize Log object!\n");

    fclose(log_file);

    return EXIT_SUCCESS;
}
```

Output of this code is:

```
7.7.2022 - 12:29:19 [Debug] - Log init success
7.7.2022 - 12:29:19 [Debug] - This is debug logging message
7.7.2022 - 12:29:19 [Warning] - This is warning logging message
7.7.2022 - 12:29:19 [Error] - This is error logging message
Log is now off
```
