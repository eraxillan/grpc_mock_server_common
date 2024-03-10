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

#include "grpc_mock_server_configuration.h"

Config& Config::instance() {
    static Config instance;
    return instance;
}

bool Config::haveFullPath(const std::string& method_name) const {
    if (m_methods.contains(method_name)) {
        return !m_methods.at(method_name).m_full_path.empty();
    }
    return false;
}

bool Config::havePartialPath(const std::string& method_name) const {
    if (m_methods.contains(method_name)) {
        return !m_methods.at(method_name).m_partial_path.empty();
    }
    return false;
}

std::string Config::fullPath(const std::string& method_name) const {
    return m_methods.at(method_name).m_full_path;
}

std::string Config::partialPath(const std::string& method_name) const {
    return m_methods.at(method_name).m_partial_path;
}

bool Config::parseConfigXml(const std::string& data, MethodDescriptions& methods) {
    std::string full_path;
    std::string partial_path;

    pugi::xml_document doc;
    pugi::xml_parse_result parser_result = doc.load_buffer(data.data(), data.size());
    if (!parser_result) {
        assert(0);
        return false;
    }

    auto xpath_result_nodes = doc.select_nodes("/root/dataset/package/service/child::node()");
    for (pugi::xpath_node xpath_node : xpath_result_nodes) {
        pugi::xml_node node = xpath_node.node();
        auto service_node = node.parent();
        auto package_node = service_node.parent();
        auto dataset_node = package_node.parent();

        auto full_method_name =
            std::string(dataset_node.attribute("name").as_string())
            + "." + package_node.attribute("name").as_string()
            + "." + service_node.attribute("name").as_string()
            + "/" + node.attribute("name").as_string();

        pugi::xml_node full_node = node.child("full");
        pugi::xml_node partial_node = node.child("partial");
        if (!full_node.attribute("path").empty()) {
            full_path = full_node.attribute("path").as_string();
        }
        if (!partial_node.attribute("path").empty()) {
            partial_path = partial_node.attribute("path").as_string();
        }

        methods[full_method_name] = MethodDescription(full_path, partial_path);
    }

    return !methods.empty();
}

Config::Config() {
    std::string config_file_data = grpc_mock_server::readFile("../../../config.xml");
    parseConfigXml(config_file_data, m_methods);
}
