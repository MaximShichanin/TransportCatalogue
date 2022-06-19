About PathFinder
----------------

This is simple app for cataloging information about bus routes and
searching for optimized path from one point to another. Program may
build a map in svg format.

How to build
------------

To build this app you need:
cmake version 3.10 or higher (https://cmake.org/)
protobuf version 3.20 or higher (https://developers.google.com/protocol-buffers)

To build the app follow steps:

0. mkdir ./build
1. cmake ../src -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=<path_to_protobuf_dir>
2. cmake --build ./
If you need Debug version, use -DCMAKE_BUILD_TYPE=Degug flag.
Make shure that you have permissions to create files in your working
directory.
Program has been built successfully on Ubuntu/Linux 20.04 with
gcc version 11.2.0, but other gcc versions, that are compatible with C++17
standard should work properly.

How t use
---------

Program use JSON queries to configure transport catalogue and searching
information in there. In output file you get JSON answers to your queries.
To run program use two keys: "make_base" and "process_requests"
To create data base run:
./build/pathfinder make_base < <path_to_JSON-based_data> 
To query to existing data base run:
./build/pathfinder process_requests < <path_to_JSON-based_query> 

There is some major query keys to program: "base_requests" - to add
information about stops and routes in catalogue, "renderer_settings" and
"routing_settings" - to configure program, "stat_requests" - to get
information from program.
For more information see example_mb.json, example_mb.json and answer.json files.

What to impruve?
---------------

May adds a rendering found path on routes
