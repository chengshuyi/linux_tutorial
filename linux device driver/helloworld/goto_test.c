#include "stdio.h"

int my_init_function(void)
{
    goto fail_those;
fail_those:
    printf("fail_those\n");
fail_that:
    printf("fail_that\n");
fail_this:
    return 0;
}

int main()
{
    my_init_function();
    return 0;
}
/*
int __init my_init_function(void)
{
    int err;
    err = register_this(ptr1, "skull");
    if (err)
        goto fail_this;
    err = register_that(ptr2, "skull");
    if (err)
        goto fail_that;
    err = register_those(ptr3, "skull");
    if (err)
        goto fail_those;
    return 0;
fail_those:
    unregister_that(ptr2, "skull");
fail_that:
    unregister_this(ptr1, "skull");
fail_this:
    return err;
}
*/