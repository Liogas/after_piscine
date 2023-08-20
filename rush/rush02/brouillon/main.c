#include <unistd.h>

#include "h/check_arg.h"
#include "h/error_msg.h"

int main(int argc, char **argv)
{
    int err;

    err = 0;
    if(check_arg(argc, argv) > 0)
    {
        ARG_MSG()
        err++;
    }
    return (err);
}