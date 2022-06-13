#include "tests.h"

using namespace std::literals;
using namespace transport_catalogue;

void tests::JsonReader() {
    
}

void tests::AddAndFindStop() {
    /*
    using stop_res = std::tuple<std::string, double, double>;
    
    TransportCatalogue test_catalogue;
    {
    for(std::string_view stop : {"Stop Tolstopaltsevo: 55.611087, 37.208290"sv,
                                 "Stop Biryulyovo Zapadnoye: 55.574371, 37.651700, 666m to Tolstopaltsevo"sv,
                                 "Stop Tolstopaltsevo: 66.99, 99.66"sv,
                                 "Stop Biryulyovo Zapadnoye: 55.33, 33.55"sv,
                                 "Stop Marushkino: 44.33, 11.22, 1000m to Tolstopaltsevo, 2000m to Biryulyovo Tovarnaya"sv,
                                 "Stop Universam: 55.33, 22.33, 5555m to Biryulyovo Tovarnaya"sv,
                                 "stop Biryulyovo Vostochnoe: 66.666, 99.999"sv, //wrong stop data
                                 "Biryulyovo Vostochnoe: 99.999, 66.666"sv}) { //wrong stop data
        try {
            UpdateCatalogue(test_catalogue, stop);
        }
        catch(const std::invalid_argument& e) {}
        catch(...) {
            assert(0);
        }
    }
    }
    std::vector<std::string_view> queries = {"Tolstopaltsevo"sv, "Marushkino"sv,
                                             "Universam"sv, "Biryulyovo Zapadnoye"sv};
    std::vector<stop_res> result = {stop_res("Tolstopaltsevo"s, 55.611087, 37.208290),
                                    stop_res("Marushkino"s, 44.33, 11.22),
                                    stop_res("Universam"s, 55.33, 22.33),
                                    stop_res("Biryulyovo Zapadnoye"s, 55.574371, 37.651700)};
    int id = 0;
    for(const auto query : queries) {
        const auto& res = test_catalogue.FindStop(query);
        assert(result.at(id++) == std::tie(res.name, res.coordinates.lat,
                                           res.coordinates.lng));
    }
    const auto& res = test_catalogue.FindStop("Biryulyovo Vostochnoe"sv);
    assert(res.empty());
    */
}

void tests::AddAndFindBus() {
/*
    using route_info = std::tuple<std::string, RouteType, std::vector<std::string_view>>;
    TransportCatalogue test_catalogue;
    {
    for(std::string_view stop : {"Stop Tolstopaltsevo: 66.99, 99.66"sv,
                                 "Stop Biryulyovo Zapadnoye: 55.33, 33.55"sv,
                                 "Stop Marushkino: 44.33, 11.22, 1000m to Tolstopaltsevo, 2000m to Biryulyovo Tovarnaya"sv,
                                 "Stop Universam: 55.33, 22.33, 5555m to Biryulyovo Tovarnaya"sv}) {
        UpdateCatalogue(test_catalogue, stop);
    }
    for(std::string_view bus : {"Bus 256: Biryulyovo Zapadnoye > Biryusinka > Universam > Biryulyovo Tovarnaya > Biryulyovo Passazhirskaya > Biryulyovo Zapadnoye"sv,
                                "Bus 750: Tolstopaltsevo - Marushkino - Rasskazovka"sv,
                                "Bus 666: Tolstopaltsevo - Biryulyovo Zapadnoye - Biryulyovo Tovarnaya"sv}) {
        UpdateCatalogue(test_catalogue, bus);
    }
    }
    std::vector<route_info> result = {{"256"s, RouteType::CIRCLE, {"Biryulyovo Zapadnoye"sv,
                                                                   "Biryusinka"sv,
                                                                   "Universam"sv,
                                                                   "Biryulyovo Tovarnaya"sv,
                                                                   "Biryulyovo Passazhirskaya"sv,
                                                                   "Biryulyovo Zapadnoye"sv}},
                                      {"750"s, RouteType::LINEAR, {"Tolstopaltsevo"sv,
                                                                   "Marushkino"sv,
                                                                   "Rasskazovka"sv}},
                                      {"666"s, RouteType::LINEAR, {"Tolstopaltsevo"sv,
                                                                   "Biryulyovo Zapadnoye"sv,
                                                                   "Biryulyovo Tovarnaya"sv}}
                                     };
    std::vector<std::string_view> queries = {"256"sv, "750"sv, "666"sv};
    size_t id = 0;
    for(auto query : queries) {
        const auto& res = test_catalogue.FindRoute(query);
        assert(result.at(id++) == std::tie(res.name, res.route_type, res.stop_names));
        assert(res.stop_names.size() == res.route.size());
        for(size_t i = 0; i < res.stop_names.size(); ++i) {
            assert(res.stop_names.at(i) == res.route.at(i)->name);
        }
    }
    auto res = test_catalogue.FindRoute("777"sv);
    assert(res.empty());
    assert(res.route_type == RouteType::NONE);
    */
}

void tests::RequestHandler() {
    
}

std::vector<std::string> InputGen() {
    return {};
}

std::vector<std::string> QueryGen() {
    return {};
}

void tests::HiLoadTest() {
    
}

template<typename Func>
void run_test(Func test, const char* test_name) {
    std::cerr << test_name << "...\n"s;
    test();
    std::cerr << test_name << " DONE\n"s;
}

#define RUN_TEST(TEST) run_test((TEST), (#TEST))

void tests::main_test() {
    RUN_TEST(tests::JsonReader);
    RUN_TEST(tests::AddAndFindStop);
    RUN_TEST(tests::AddAndFindBus);
    RUN_TEST(tests::RequestHandler);
    RUN_TEST(tests::HiLoadTest);
}
