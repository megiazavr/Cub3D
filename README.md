*This project has been created as part of the 42 curriculum by megiazar, ncruz-ne.*

# 42 Lisboa Common Core | Milestone 4: Cub3D

## Description

....

## Instructions

<<<<<<<<<<<<<<<<<<<<<<<< UPDATE >>>>>>>>>>>>>>>>>>>>>>>>
This project can be compiled with the exact requirements or with additional flair. For an improved experience, we recommend the following changes in `flair.h`:

- `FLAIR` to `ON`
- `UTENSIL` to `" chopstick"`

1. Compile the project with `make` or `make all`.
2. Run the project with `make run`, `make print` if you want the standard output messages in a file, or
  for a map filename path that doesn't have spaces:

	```bash
	./cub3D path_dir/map_filename.cub
	```

	for a map filename path that has space(s):

	```bash
	./cub3D "path dir/map filename.cub"
	```

3. Use `make clean` to remove object files.
4. Use `make fclean` to remove all generated files.
5. Use `make re` to rebuild the project from scratch.
6. Use `make print` to rebuild the project and print all output into a `.txt`.
7. Use `make stderr` to rebuild the project and print stderr messages into a `.txt`.
8. Testing rules — using `ARG` in `Makefile`:
	1. `make valg` remakes the debugging executable and runs `valgrind`;
	2. `make hel` remakes the debugging executable and runs `helgrind`;
	3. `make db` remakes the debugging executable and starts `gdbtui` debugging session;
	4. `make test` remakes the debugging executable, runs first `valgrind`, followed by `helgrind` and lastly initiates a `gdbtui` session.
9. `make tclean` will remove only testing files and directories.
10. Use `make norm` to download the most updated version of 42 Norm.

Introducing invalid arguments to run the program will cause it to return with `EXIT_FAILURE` and an error message will be printed in **standard error** as well as **standard ouput** so that the user knows what is the issue even without checking what's in `stderr`.

`philo` will only run successfully if there are **4** or **5** arguments, with all of them being **positive integers** (from `1` to `INT_MAX` = **2147483647** for 32-bit integers), except for `number_of_times_each_philosopher_must_eat` that can be set to `0` — which will mean it will not be considered for the simulation.

When using `make run`, user must update the `ARG` variable in `Makefile` directly or the individual variables that compose `ARG`:

``` Makefile
ARG = "path dir/map filename.cub"
```

Note that though all positive integer values are valid, the program shouldn't be tested during evaluation with `number_of_philosophers > 200`, `time_to_die < 60`, `time_to_eat < 60` or `time_to_sleep < 60`. A warning message will be displayed in standard output when user submits any parameter under these conditions.

`EXIT_FAILURE` is also the return status when any error occurs during program execution. Information will be added to **standard error** regarding the error that triggered the program's exit.

Testing output will be available in the directory defined in `Makefile` as `TEST_DIR`, under the filenames set in `VALG_LOG` and `HELG_LOG`.
The simulation log filename can also be defined in `Makefile` under `SIM_LOG`.

## Resources

### Allowed functions and their libraries

- fcntl.h
  - [open](https://man7.org/linux/man-pages/man2/open.2.html)
- All functions of [math.h](https://man7.org/linux/man-pages/man0/math.h.0p.html)
- All functions of [mlx.h](https://github.com/42paris/minilibx-linux)
- stdio.h
  - [printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- stdlib.h
  - [exit](https://man7.org/linux/man-pages/man3/exit.3.html)
  - [malloc, free](https://man7.org/linux/man-pages/man3/malloc.3.html)
  - [perror](https://man7.org/linux/man-pages/man3/perror.3.html)
- string.h
  - [strerror](https://man7.org/linux/man-pages/man3/strerror.3.html)
- sys/time.h
  - [gettimeofday](https://man7.org/linux/man-pages/man3/gettimeofday.3p.html)
- unistd.h
  - [close](https://man7.org/linux/man-pages/man2/close.2.html)
  - [read](https://man7.org/linux/man-pages/man2/read.2.html)
  - [write](https://man7.org/linux/man-pages/man2/write.2.html)

### Important concepts

#### RGB repsentation as an integer (32-bits)

`r` (integer variable representing red), `g` (integer variable representing green), and `b` (integer variable representing blue) are each validated to fit in 8 bits (0–255). The expression packs them into `0xRRGGBB`:

- `r << 16`: shifts red into bits 16–23.
- `g << 8`: shifts green into bits 8–15.
- `b`: stays in bits 0–7.
- `|` combines the three non-overlapping byte values.

```c
(r << 16) | (g << 8) | b
```

Example with `r = 255`, `g = 128`, `b = 64`:

```text
r << 16 = 0xFF0000
g << 8  = 0x008000
b       = 0x000040

result  = 0xFF8040
```

Each RGB value occupies **8 bits = 1 byte**. In hexadecimal, one digit represents 4 bits, so 8 bits require **two hex digits**.

- **R = 255**
  - `255 = 15 × 16 + 15`
  - Decimal `15` is hexadecimal `F`
  - Therefore, `255 = 0xFF`

- **G = 128**
  - `128 = 8 × 16 + 0`
  - Therefore, `128 = 0x80`

- **B = 64**
  - `64 = 4 × 16 + 0`
  - Therefore, `64 = 0x40`

The three bytes are then placed together:

```text
R       G       B
0xFF    0x80    0x40

0xFF8040
```

So `RGB(255, 128, 64)` is represented as **`0xFF8040`**.
The `[0,255]` validation ensures each component fits exactly within its 8-bit section. Each color component uses 8 bits and our resulting color will total 24 bits.

At 42 campus, the systems we use to work and evaluate our projects, an `int` has **32 bits**. The packed color uses only the lower 24 bits, the remaining 8 bits of the 32-bit `int` are unused:

```text
31             24 23       16 15        8 7         0
+----------------+-----------+-----------+-----------+
| unused (0)     |   red     |  green    |   blue    |
+----------------+-----------+-----------+-----------+
```

Read more:
- [Convert the given RGB color code to Hex color code](https://www.geeksforgeeks.org/dsa/convert-the-given-rgb-color-code-to-hex-color-code/)
- [RGB Representation as an Integer in Java](https://www.baeldung.com/java-rgb-color-representation)

##### Flood-fill

[NAME](LINK)

### Additional great resources

- [NAME](LINK)

### Interesting rabbit holes we went through while working on this project...

...

### AI Usage

AI (LLMs) was used as a study and research support, to find more information on the various concepts we needed to learn and to assist in interpretation of technical texts.
