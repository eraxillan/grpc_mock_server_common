/*
 *
 * Copyright 2018 gRPC authors, 2022 Aleksandr Kamyshnikov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_MOCK_SERVER_CONFIGURATION_H
#define GRPC_MOCK_SERVER_CONFIGURATION_H

#include <memory>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <random>
#include <iomanip>
#include <map>
#include <cassert>

// XML parser
#include <pugixml.hpp>
#include "grpc_mock_server_export.h"
#include "grpc_mock_server_utils.h"

class GRPC_MOCK_SERVER_LIBRARY_API Config {
    struct MethodDescription {
        std::string m_full_path;
        std::string m_partial_path;
    };
    using MethodName = std::string;
    using MethodDescriptions = std::map<MethodName, MethodDescription>;
    MethodDescriptions m_methods;

public:
    static Config& instance();

    bool haveFullPath(const std::string& method_name) const;
    bool havePartialPath(const std::string& method_name) const;
    std::string fullPath(const std::string& method_name) const;
    std::string partialPath(const std::string& method_name) const;

private:
    static bool parseConfigXml(const std::string& data, MethodDescriptions& methods);

private:
    Config();
    Config(const Config& root) = delete;
    Config& operator=(const Config&) = delete;
};
#endif  // GRPC_MOCK_SERVER_CONFIGURATION_H
