Author: Trever Hall
Date: 3/3/2022
Description: Experimentation with implementing locks for pthreads.
Assignment: pthreads!

Files
    pt.c
    pt-locks.c
    pt-tas.c
    pt-tatas.c

Respective Executable Files
    pt
    pt-locks
    pt-tas
    pt-tatas


How To Run On Command-Line
    After compiling with make, run:
        ./exeFileName - this runs the program with default values (4 threads and 10000 iterations).

    Setting Custom Values:
        use the -x [number_of_threads] and -y [number_of_iterations] flags
        Examples:
            ./exeFileName -x 8 -y 400 (runs 8 threads with 400 iterations each)
            ./exeFileName -x 2        (Runs 2 threads with default iterations each)
            ./exeFileName -y 2000     (Runs default number of threads with 2000 iterations each)
