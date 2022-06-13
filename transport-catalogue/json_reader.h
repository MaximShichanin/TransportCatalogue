#pragma once

#include "json.h"
#include "svg.h"
#include "request_handler.h"

//#include <transport_catalogue.pb.h>

namespace json_reader {

class JsonReader {
public:
    JsonReader(std::istream& input, RequestHandler& request_handler);
    JsonReader(json::Document&& input, RequestHandler& request_handler);
    
    void GetResult(std::ostream& out) const;
private:
    //data
    const json::Document raw_request_;
    RequestHandler& request_handler_;
    json::Array raw_output_;
private:
    void ParseRequest();
    
    void AddItem(const json::Dict& item);
    void SetRenderer(const json::Dict& settings);
    void SetRouter(const json::Dict& settings);
    void SetSerializer(const json::Dict& settings);
    
    json::Dict MakeBusInfo(const json::Dict& route_query);
    json::Dict MakeStopInfo(const json::Dict& stop_query);
    json::Dict MakeMap(const json::Dict& map_query);
    json::Dict MakeRoute(const json::Dict& router_query);
    
    json::Array TranslateRouteToJson(const std::vector<domain::RouteItem>& items) const;
};

} //json_reader
