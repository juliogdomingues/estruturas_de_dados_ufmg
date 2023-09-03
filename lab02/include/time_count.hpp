#include <ctime>
#include <iostream>
#include <sys/resource.h>

struct rusage start_rusage, end_rusage;
struct timespec start_time, end_time;

int start_count () {
    if (getrusage(RUSAGE_SELF, &start_rusage) == -1) {
        perror("getrusage");
        return 1; // Handle the error appropriately.
    }

    if (clock_gettime(CLOCK_MONOTONIC, &start_time) == -1) {
        perror("clock_gettime");
        return 1; // Handle the error appropriately.
    }
    return 0;
}

int end_count () {
    if (clock_gettime(CLOCK_MONOTONIC, &end_time) == -1) {
        perror("clock_gettime");
        return 1; // Handle the error appropriately.
    }

    if (getrusage(RUSAGE_SELF, &end_rusage) == -1) {
        perror("getrusage");
        return 1; // Handle the error appropriately.
    }

    // Calculate and print user and system time for the first loop
    long long user_time_sec1 = end_rusage.ru_utime.tv_sec - start_rusage.ru_utime.tv_sec;
    long user_time_usec1 = end_rusage.ru_utime.tv_usec - start_rusage.ru_utime.tv_usec;

    long long sys_time_sec1 = end_rusage.ru_stime.tv_sec - start_rusage.ru_stime.tv_sec;
    long sys_time_usec1 = end_rusage.ru_stime.tv_usec - start_rusage.ru_stime.tv_usec;

    // Normalize the time values
    if (user_time_usec1 < 0) {
        user_time_sec1--;
        user_time_usec1 += 1000000;
    }

    if (sys_time_usec1 < 0) {
        sys_time_sec1--;
        sys_time_usec1 += 1000000;
    }

    printf("User time: %lld seconds and %ld microseconds\n", user_time_sec1, user_time_usec1);
    printf("System time: %lld seconds and %ld microseconds\n", sys_time_sec1, sys_time_usec1);

    // Calculate and print the elapsed time in nanoseconds for the first loop
    long long elapsed_seconds1 = end_time.tv_sec - start_time.tv_sec;
    long elapsed_nanos1 = end_time.tv_nsec - start_time.tv_nsec;

    if (elapsed_nanos1 < 0) {
        elapsed_seconds1--;
        elapsed_nanos1 += 1000000000; // Convert nanoseconds to seconds
    }

    long long elapsed_total_nanos1 = elapsed_seconds1 * 1000000000LL + elapsed_nanos1;
    printf("Elapsed time: %lld nanoseconds\n", elapsed_total_nanos1);

    // Reset the timers for the second loop
    if (getrusage(RUSAGE_SELF, &start_rusage) == -1) {
        perror("getrusage");
        return 1; // Handle the error appropriately.
    }
    return 0;
}