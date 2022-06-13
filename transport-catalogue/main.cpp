#include "json_reader.h"

#include <fstream>
#include <iostream>
#include <string_view>

using namespace std::literals;

void PrintUsage(std::ostream& stream = std::cerr) {
    stream << "Usage: transport_catalogue [make_base|process_requests]\n"sv;
}

namespace TC = transport_catalogue;
namespace MR = map_renderer;
namespace TR = transport_router;

void MakeBase() {
    RequestHandlerSerializer rh_serializer{};
    json_reader::JsonReader jr(std::cin, rh_serializer);
}

void ProcessRequests() {
    RequestHandlerDeserializer rh_deserializer{};
    json_reader::JsonReader jr(std::cin, rh_deserializer);
    jr.GetResult(std::cout);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        PrintUsage();
        return 1;
    }

    const std::string_view mode(argv[1]);

    if (mode == "make_base"sv) {
        MakeBase();
    } else if (mode == "process_requests"sv) {
        ProcessRequests();
    } else {
        PrintUsage();
        return 1;
    }
}
