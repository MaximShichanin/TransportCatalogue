/*******************************************************************************
This is an instruction about how to create TransportCatalogue Base. Input is 
JSON-based file with data content such a buses and stops data and catalogue
settings. The description is given in <key>: <value> format.
*******************************************************************************/

//How to add Bus/Stop data
Route items may be emplaced into catalogue with "base_request" key:

"base_request": [<data array>]

There are two kinds <data_array> items:
0. Stop. To add next stop:

    "type": "Stop",
    "name": "stop name",
    "latitude": 43.590317,
    "longitude": 39.746833,
    "road_distances": {
        "other stop": 4300,
        "yet another stop": 2000
    }
    
"type": "Stop" - marks, that there is a stop item;
"name": <name> - stop name. May contain numbers, letters and whitespace;
"latitude": <value>, "longitude": <value> - stop geolocation. Value is floating
point number;
"road_distances": {<other_stop_name>: <value>, ...} - distance to other stops in
meters. Value is a positive integer. Field may be empty and in such case route
distance will be computed by stop geolocation;

1. Bus. To add next bus:

    "type": "Bus",
    "name": "bus name",
    "stops": [<first_stop>, <second_stop>, ...],
    "is_roundtrip": <true/false>
    
"type": "Bus" - marks, that there is a bus item;
"name": <name> - bus name. May contain numbers, leters and whitespaces;
"is_roundtrip": <true/false> - route type setting. If key is true - there is
circle route and linear route otherwise.
"stops": [<first_stop>, <second_stop>, ...] - list of stops on route. There are 
two kinds of bus route: linear and circle. By linear route, bus moves from start
stop to last, and backward from last stop to first. Linear route stop list will 
be transformed such way:
[<St_0>, <St_1>, <St_2>] -> [<St_0>, <St_1>, <St_2>, <St_1>, <St_0>].
By circle route, the bus moves from start position to the last, which is the
first stop in the list. If first and last stops aren't equal in a given list,
then first stop will be pushed back to list:
[<St_0>, <St_1>, <St_2>] -> [<St_0>, <St_1>, <St_2>, <St_0>].
If any stop in list doesn't exist in catalogue, it will be pushed with default
parameters;

//How to set Catalogue

Map renderer may be set by "renderer_settings" key:

    "render_settings": {
        "width": 1200,
        "height": 500,
        "padding": 50,
        "stop_radius": 5,
        "line_width": 14,
        "bus_label_font_size": 20,
        "bus_label_offset": [
            7,
            15
        ],
        "stop_label_font_size": 18,
        "stop_label_offset": [
            7,
            -3
        ],
        "underlayer_color": [
            255,
            255,
            255,
            0.85
        ],
        "underlayer_width": 3,
        "color_palette": [
            "green",
            [
                255,
                160,
                0
            ],
            "red"
        ]
      }
"width": <width_val> - canvas width;
"height": <height_val> - canvas height;
"padding": <padding_val> - canvas padding;
"stop_radius": <stop_radius_val> - radius of stop mark;
"line_width": <width_val> - route line width;
"bus_label_font_size": <font_size_val> - font size for bus text;
"bus_lebel_offset": [<x>, <y>] - offset of bus text from mark;
"stop_label_font_size": <font_size_val> - font size for stop text;
"stop_lebel_offset": [<x>, <y>] - offset of stop text from mark;
"underlayer_color": <color> - color of canvas underlayer;
"underlayer_width": <width_val> - underlayer width;
"color_palette": [<color_0>, <color_1>, ...] - colors for route lines. Every
next route color will be set by looping of color palette;

Possible values:
<width_val>, <height_val>, <padding_val>, <stop_radius_val>, <width_val> - 
floating point number;
<font_size_val> - positive integer;
<color> - there are three ways to set color: by string ("green", "red"), by
RGB-format ([<r>, <g>, <b>]) and RGBa-format ([<r>, <g>, <b>, <a>]).
<r>, <g>, <b> - positive integer numbers in range 0..255, <a> - positive
floating point number in range 0.0..1.0;

Router may be set by "routing_settings" key:

    "routing_settings": {
        "bus_wait_time": 2,
        "bus_velocity": 30
    }

"bus_wait_time": <val> - set time for waiting next bus on stop in minutes;
"bus_velocity": <val> - set bus velocity in km/h;
<val> is a positive integer number.

Serializer may be set by "serialization_settings" key:

    "serialization_settings": {
        "file": "<path_to_file>"
    }
    
"file": <path_to_file> - set the location of catalogue. All accepted data and
settings will be serialized into <path_to_file>.

By default, the TransportCatalogue reads data from stdin stream. You can make it
to read data from file by such way:
./transport_catalogue make_base < <path_to_json_data_file>
