#include <ctime>
#include <iostream>
#include <sys/resource.h>

#include "../include/time_count.hpp"

// Estruturas para armazenar informações de uso de recursos e tempo
struct rusage start_rusage, end_rusage;
struct timespec start_time, end_time;

int start_count () {
    // Obter informações de uso de recursos no início
    if (getrusage(RUSAGE_SELF, &start_rusage) == -1) {
        perror("getrusage");
        return 1; // Tratar
    }

    // Obter o tempo atual no início
    if (clock_gettime(CLOCK_MONOTONIC, &start_time) == -1) {
        perror("clock_gettime");
        return 1; // Tratar
    }
    return 0;
}

int end_count () {
    // Obter o tempo atual no final
    if (clock_gettime(CLOCK_MONOTONIC, &end_time) == -1) {
        perror("clock_gettime");
        return 1; // Tratar
    }

    // Obter informações de uso de recursos no final
    if (getrusage(RUSAGE_SELF, &end_rusage) == -1) {
        perror("getrusage");
        return 1; // Tratar
    }

    // Calcular e imprimir o tempo de usuário e sistema
    long long user_time_sec1 = end_rusage.ru_utime.tv_sec - start_rusage.ru_utime.tv_sec;
    long user_time_usec1 = end_rusage.ru_utime.tv_usec - start_rusage.ru_utime.tv_usec;

    long long sys_time_sec1 = end_rusage.ru_stime.tv_sec - start_rusage.ru_stime.tv_sec;
    long sys_time_usec1 = end_rusage.ru_stime.tv_usec - start_rusage.ru_stime.tv_usec;

    // Normalização
    if (user_time_usec1 < 0) {
        user_time_sec1--;
        user_time_usec1 += 1000000;
    }

    if (sys_time_usec1 < 0) {
        sys_time_sec1--;
        sys_time_usec1 += 1000000;
    }

    // Normalizar os valores de tempo e converter para milissegundos
    long long user_time_ms1 = user_time_sec1 * 1000 + user_time_usec1 / 1000;
    long long sys_time_ms1 = sys_time_sec1 * 1000 + sys_time_usec1 / 1000;

    printf("User time: %lld milliseconds OR %ld microseconds\n", user_time_ms1, user_time_usec1);
    printf("System time: %lld milliseconds OR %ld microseconds\n", sys_time_ms1, sys_time_usec1);


    // Calcular e imprimir o tempo decorrido em microssegundos
    long long elapsed_seconds1 = end_time.tv_sec - start_time.tv_sec;
    long elapsed_nanos1 = end_time.tv_nsec - start_time.tv_nsec;

    if (elapsed_nanos1 < 0) {
        elapsed_seconds1--;
        elapsed_nanos1 += 1000000000; // Converter nanossegundos para segundos
    }

    long long elapsed_total_nanos1 = elapsed_seconds1 * 1000000000LL + elapsed_nanos1;
    long long elapsed_total_us1 = elapsed_total_nanos1 / 1000; // Convert nanoseconds to microseconds
    long long elapsed_total_ms1 = elapsed_total_nanos1 / 1000000; // Convert nanoseconds to milliseconds    
    printf("Elapsed time: %lld milliseconds OR %lld microseconds\n", elapsed_total_ms1, elapsed_total_us1);

    // Resetar os temporizadores
    if (getrusage(RUSAGE_SELF, &start_rusage) == -1) {
        perror("getrusage");
        return 1; // Tratar
    }
    return 0;
}