*This project has been created as part of the 42 curriculum by megiazar, ncruz-ne.*

# 42 Lisboa Common Core | Milestone 4: Cub3D

## Description

....



## Instructions

<<<<<<<<<<<<<<<<<<<<<<<< UPDATE >>>>>>>>>>>>>>>>>>>>>>>>
This project can be compiled with the exact requirements or with additional flair. For an improved experience, I recommend the following changes in `flair.h`:
- `FLAIR` to `ON`
- `UTENSIL` to `" chopstick"`

1. Compile the project with `make` or `make all`.
2. Run the project with `make run`, `make print` if you want the simulation log in a file, or
	```
	./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
	```
3. Use `make clean` to remove object files.
4. Use `make fclean` to remove all generated files.
5. Use `make re` to rebuild the project from scratch.
6. Testing rules — using `ARGS` in `Makefile`:
	1. `make valg` runs `valgrind`;
	2. `make hel` runs `helgrind`;
	3. `make db` starts `gdbtui` debugging session;
	4. `make test` runs first `valgrind`, followed by `helgrind` and lastly initiates a `gdbtui` session.
7. `make tclean` will remove only testing files and directories.
8. Use `make norm` to download the most updated version of 42 Norm.

Introducing invalid arguments to run the program will cause it to return with `EXIT_FAILURE` and an error message will be printed in **standard ouput** so that the user knows what is the issue.

`philo` will only run successfully if there are **4** or **5** arguments, with all of them being **positive integers** (from `1` to `INT_MAX` = **2147483647** for 32-bit integers), except for `number_of_times_each_philosopher_must_eat` that can be set to `0` — which will mean it will not be considered for the simulation.

When using `make run`, user must update the `ARGS` variable in `Makefile` directly or the individual variables that compose `ARGS`:
```
N_PHILO			= 1
T_DIE			= 800
T_EAT			= 200
T_SLEEP			= 200
N_EATS_X_PHILO	= 0
ARGS			= $(N_PHILO) $(T_DIE) $(T_EAT) $(T_SLEEP) $(N_EATS_X_PHILO)
```

Note that though all positive integer values are valid, the program shouldn't be tested during evaluation with `number_of_philosophers > 200`, `time_to_die < 60`, `time_to_eat < 60` or `time_to_sleep < 60`. A warning message will be displayed in standard output when user submits any parameter under these conditions.

`EXIT_FAILURE` is also the return status when any error occurs during program execution. Information will be added to **standard error** regarding the error that triggered the program's exit.

Testing output will be available in the directory defined in `Makefile` as `TEST_DIR`, under the filenames set in `VALG_LOG` and `HELG_LOG`.
The simulation log filename can also be defined in `Makefile` under `SIM_LOG`.


## Resources

### Allowed functions
- [open](LINK)
- [printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [malloc, free](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [write](https://man7.org/linux/man-pages/man2/write.2.html)
- [close](LINK)
- [gettimeofday](https://man7.org/linux/man-pages/man3/gettimeofday.3p.html)
- [read](LINK)
- [perror](LINK)
- [strerror](LINK)
- [exir](LINK)


### Important concepts

- [NAME](LINK)


### Additional great resources

- [NAME](LINK)


### Interesting rabbit holes we went through while working on this project...

...


### AI Usage

AI (LLMs) was used as a study and research support, to find more information on the various concepts we needed to learn and to assist in interpretation of technical texts.