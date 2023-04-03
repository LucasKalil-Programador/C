#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "utils.h"
#include "methods.h"
#include <conio.h>

typedef struct {
    int id;
    double A, B, N;
    double start, end;
    double thread_result;
    double (*f)(double);
    double status_progress;
} thread_params;


// loop task
DWORD WINAPI thread_task(LPVOID lpParam) {
    thread_params* params = (thread_params*)lpParam;
    double delta_x = (params->B - params->A) / params->N;

    for (double i = params->start; i < params->end; i++)
    {
      params->thread_result += method2(params->A, delta_x, i, params->f); 
      params->status_progress = i;
    }
    
    return 0;
}


// build a array with params
thread_params* build_params(double A, double B, double N, size_t thread_count, double (*f)(double)) {
    thread_params * params = malloc(sizeof(thread_params) * thread_count);
    double tasks_per_th;
    modf(N / thread_count, &tasks_per_th);
    double remain_tasks = fmod(N, thread_count);
    double cstart = 1;
    
    for (size_t i = 0; i < thread_count; i++)
    {
      double start = cstart, end = cstart + tasks_per_th;
      if(remain_tasks > 0) { 
        remain_tasks--;
        end++; 
      }
      cstart = end;
      params[i] = (thread_params){ (i + 1), A, B, N, start, end, 0, f, 0 };
    }
    return params;
}


// start all threads
int start_threads(HANDLE* threads, thread_params* params, size_t thread_count) {
    for (size_t i = 0; i < thread_count; i++) {
      threads[i] = CreateThread(NULL, 0, thread_task, &params[i], 0, NULL);
      if (threads[i] == NULL) {
        printf("Failed to create thread id: %d\n", params[i].id);
        return 0;
      }
    }
    return 1;
}


// print status in console
void print_status(thread_params* params, size_t thread_count) {
    size_t buffer_size = thread_count * 64 + 32;
    double general_progress = 0;
    char buffer[buffer_size];
    int pad = 0;
    
    for (size_t i = 0; i < thread_count; i++) {
      double progress = (((params[i].status_progress - params[i].start) + 1) / (params[i].end - params[i].start)) * 100;
      if(progress < 100) {
        if(progress < 0) {
          progress = 0;
        }
        pad += snprintf(buffer + pad, buffer_size - pad, "Worker: %3d | progress: %6.3f%%\r\n", params[i].id, progress);
      }
      general_progress += progress;
    }
    snprintf(buffer + pad, buffer_size - pad, "General progress: %6.3f%%\r\n", general_progress / thread_count);
    system("cls");
    puts(buffer);
}


// while wait for thread print status on console after close and free threads
void wait_and_free_threads(HANDLE* threads, thread_params* params, size_t thread_count) {
    int code;
    do {
      code = WaitForMultipleObjects(thread_count, threads, TRUE, 250);
      print_status(params, thread_count);   
    } while (code != 0);
    print_status(params, thread_count); 

    for (size_t i = 0; i < thread_count; i++) {
        CloseHandle(threads[i]);
    }
    free(threads);
}


// main
int main() {
    system("cls");
    time_t start_time = time(NULL);

    double f(double x) { return pow(x, 2); }
    double A = 2, B = 3, N = pow(10, 9);
    size_t thread_count = 8;

    thread_params* params = build_params(A, B, N, thread_count, f);
    HANDLE* threads = malloc(sizeof(HANDLE) * thread_count);
    start_threads(threads, params, thread_count);    
    wait_and_free_threads(threads, params, thread_count);

    double result = 0;
    for (size_t i = 0; i < thread_count; i++)
    {
      result += params[i].thread_result;
    }
    
    int elapsed = (int)time(NULL) - start_time;
    printf("\r\nresult: %.16f | elapsed time: %s", result, seconds_time_str(elapsed));

    free(params);
    return 0;
}

// tests multi thread A = 2, B = 3, N = 100_000_000_000;
// -----------------------------------------------------------------------
// thread_count = 60 | result: 6.3333333333132131 | elapsed time: 00:13:59
// thread_count = 48 | result: 6.3333333333134840 | elapsed time: 00:14:21
// thread_count = 36 | result: 6.3333333333143846 | elapsed time: 00:14:54
// thread_count = 24 | result: 6.3333333333153226 | elapsed time: 00:16:43
// thread_count = 12 | result: 6.3333333333156840 | elapsed time: 00:25:49
// thread_count =  8 | result: 6.3333333333158759 | elapsed time: 00:32:45
// thread_count =  4 | result: 6.3333333333289961 | elapsed time: 01:04:05