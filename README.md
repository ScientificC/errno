# errno

This repository contains some error handling modules used in the development of the libraries

[![Build Status](https://travis-ci.org/ScientificC/errno.svg?branch=master)](https://travis-ci.org/ScientificC/errno) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

A pure C errno implementation with CMake build support

## Table of Contents

- [errno](#errno)
  - [Table of Contents](#table-of-contents)
  - [Using the Library](#using-the-library)

## Using the Library

> NOTE: This will install in /usr/local. You probably don't want that. But this is a quick start. The best thing to do is to combine this library with your other code into a larger CMake project/solution.

Install with [clib](https://github.com/clibs/clib):

```shell
clib install ScientificC/errno
```

or,

```shell
git clone https://github.com/ScientificC/errno.git
cd cml
mkdir build
cd build
cmake .. <build options>
make && make install
```
