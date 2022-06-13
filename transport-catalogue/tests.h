#pragma once

#include "json_reader.h"
#include "log_duration.h"
#include "request_handler.h"
#include "transport_catalogue.h"

#include <cassert>
#include <iostream>
#include <random>
#include <sstream>
#include <tuple>
#include <vector>

namespace transport_catalogue
{
namespace tests
{
    void JsonReader();
    void AddAndFindStop();
    void AddAndFindBus();
    void RequestHandler();
    void HiLoadTest();

    void main_test();
}
}
