/*******************************************************************************
This is an instruction about how to query to TransportCatalogue database, which 
was created with make_base key. Input is JSON-based file with queries to 
the catalogue. The description is given in <key>: <value> format.
*******************************************************************************/

You need to set serializer for reading database file:

    "serialization_settings": {
        "file": "<path_to_file>"
    }
    
"file": <path_to_file> - set the location of catalogue.

Queries begin after "stat_requests" key:

    "stat_requests": [<query_array>]

Possible query keys:

To get information about bus/stop, use next query syntax:
    {
        "id": <query_id>,
        "type": "<query_type>",
        "name": "<item_name>"
    }
<query_id> - positive integer number;
<query_type> - one of next keys: "Stop" or "Bus";
<item_name> - bus/stop name;

To build a route from one stop to another, use next query syntax:
    {
        "id": <query_id>,
        "type": "Route",
        "from": "<from_stop_name>",
        "to": "<to_stop_name>"
    }

To render a map of routes in catalogue, use next query syntax:
    {
        "id": <query_id>,
        "type": "Map"
    }

By default, the TransportCatalogue reads queries from stdin stream and pushes
results into stdout stream. You can make it to read queries from file and writes
results into another file by such way:
./transport_catalogue process_requests < <path_to_query_file> > <path_to_res_file>
