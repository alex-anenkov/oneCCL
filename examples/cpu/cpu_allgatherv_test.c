/*
 Copyright 2016-2020 Intel Corporation
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
     http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include <stdio.h>

#include "ccl.h"

#define COUNT 2

int main(int argc, char** argv) {
    int i = 0;
    size_t size = 0;
    size_t rank = 0;
    int sendbuf[COUNT];
    int* recvbuf;
    size_t* recv_counts;

    ccl_request_t request;
    ccl_stream_t stream;

    ccl_init();

    ccl_get_comm_rank(NULL, &rank);
    ccl_get_comm_size(NULL, &size);

    /* create CPU stream */
    ccl_stream_create(ccl_stream_host, NULL, &stream);

    /* initialize sendbuf */
    for (i = 0; i < COUNT; i++) {
        sendbuf[i] = rank;
    }

    /* modify sendbuf */
    for (i = 0; i < COUNT; i++) {
        sendbuf[i] += 1;
    }

    recvbuf = malloc(size * COUNT * sizeof(int));
    recv_counts = malloc(size * sizeof(size_t));
    for (i = 0; i < size; i++)
        recv_counts[i] = COUNT;

    /* invoke ccl_allgatherv */
    ccl_allgatherv(sendbuf,
                   COUNT,
                   recvbuf,
                   recv_counts,
                   ccl_dtype_int,
                   NULL, /* attr */
                   NULL, /* comm */
                   stream,
                   &request);

    ccl_wait(request);

    /* check correctness of recvbuf */
    for (i = 0; i < COUNT; i++) {
        if (recvbuf[i] != rank + 1) {
            recvbuf[i] = -1;
        }
    }

    /* print out the result of the test */
    if (rank == 0) {
        for (i = 0; i < COUNT; i++) {
            if (recvbuf[i] == -1) {
                printf("FAILED\n");
                break;
            }
        }
        if (i == COUNT) {
            printf("PASSED\n");
        }
    }

    free(recvbuf);
    free(recv_counts);

    ccl_stream_free(stream);

    ccl_finalize();

    return 0;
}
