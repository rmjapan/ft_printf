# ft_printf_tester

A easy to use ft_printf project tester for 42 school.

## Currently testing (+500 tests)

%d, %i, %c, %s, %x, %X, %p, %u, and string only with the options "-0.*".

## How to use

Simply run:

``` bash
sh run.sh
```

or

``` bash
sh run.sh PATH LIB TIMER
```

- PATH = Your ft_printf project directory (Default: ../ft_printf)
- LIB = Your ft_printf library name (Default: libftprintf.a)
- TIMER = Time to wait after each setup log in seconds (Default: 0)

Default values can be edited in run.sh (From line 3 to 5).

## Add tests

1. Create a new file in tests folder (ex: "my_own_test.c")

2. Add the below code in:

    ```c
    #include "../tester.h"

    void    my_own_test(t_res *res)
    {
        testing("My own test"); // Only used as separotor for tests
        test(res, printf("[%s !!!]", "my test value"), ft_printf("'%s !!!'", "my test value")); // Real test
    }
    ```

3. Put yout prototype in tester.h (ex: void my_own_test(t_res *res);)

4. Finnaly call your test in tester.c > main:

    ```c
    #include "../tester.h"

    void    main()
    {
        ...
        my_own_test(res);
        ...
    }
    ```

Remark that you can use different char to enclose the string and therefore know which one produced each output. (ex: [] for printf and '' for your function)
Feel free to open a pull request to add tests !

## Preview

![Screen Shot](https://github.com/romslf/ft_printf_tester/blob/master/screenshot.PNG?raw=true)
