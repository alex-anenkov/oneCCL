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
#ifndef COMMA
#define COMMA ,
#endif


COLL_EXPLICIT_INSTANTIATION(char);
COLL_EXPLICIT_INSTANTIATION(int);
COLL_EXPLICIT_INSTANTIATION(int64_t);
COLL_EXPLICIT_INSTANTIATION(uint64_t);
COLL_EXPLICIT_INSTANTIATION(float);
COLL_EXPLICIT_INSTANTIATION(double);

#ifdef CCL_ENABLE_SYCL
    COLL_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<char COMMA 1>);
    COLL_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<int COMMA 1>);
    COLL_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<int64_t COMMA 1>);
    COLL_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<uint64_t COMMA 1>);
    COLL_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<float COMMA 1>);
    COLL_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<double COMMA 1>);
#endif //CCL_ENABLE_SYCL

SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, char);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, int);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, ccl::bfp16);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, float);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, double);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, int64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(char, uint64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, char);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, int);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, ccl::bfp16);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, float);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, double);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, int64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int, uint64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, char);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, int);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, ccl::bfp16);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, float);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, double);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, int64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(int64_t, uint64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, char);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, int);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, ccl::bfp16);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, float);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, double);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, int64_t);
SPARSE_ALLREDUCE_EXPLICIT_INSTANTIATION(uint64_t, uint64_t);

#ifdef CCL_ENABLE_SYCL
    SPARSE_ALLREDUCE_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<int COMMA 1>,
                                                  cl::sycl::buffer<float COMMA 1>);
    SPARSE_ALLREDUCE_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<int COMMA 1>,
                                                  cl::sycl::buffer<ccl::bfp16 COMMA 1>);
                                                  
    SPARSE_ALLREDUCE_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<int64_t COMMA 1>,
                                                  cl::sycl::buffer<float COMMA 1>);
    SPARSE_ALLREDUCE_EXPLICIT_CLASS_INSTANTIATION(cl::sycl::buffer<int64_t COMMA 1>,
                                                  cl::sycl::buffer<ccl::bfp16 COMMA 1>);
#endif //CCL_ENABLE_SYCL
#undef COMMA
