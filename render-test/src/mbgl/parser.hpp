#pragma once

#include "metadata.hpp"

#include <mbgl/util/optional.hpp>
#include <mbgl/util/rapidjson.hpp>
#include <mbgl/util/variant.hpp>

#include <regex>
#include <string>
#include <tuple>
#include <vector>

using ErrorMessage = std::string;
using JSONReply = mbgl::variant<mbgl::JSDocument, ErrorMessage>;

using ArgumentsTuple = std::tuple<bool, bool, uint32_t, std::string, std::vector<TestPaths>>;

JSONReply readJson(const mbgl::filesystem::path&);
std::string serializeJsonValue(const mbgl::JSValue&);
std::string serializeMetrics(const TestMetrics&);

std::vector<std::string> readExpectedImageEntries(const mbgl::filesystem::path& base);
std::vector<std::string> readExpectedJSONEntries(const mbgl::filesystem::path& base);

TestMetrics readExpectedMetrics(const mbgl::filesystem::path& path);

ArgumentsTuple parseArguments(int argc, char** argv);
std::vector<std::pair<std::string, std::string>> parseIgnores(const std::string& testRootPath);

TestMetadata parseTestMetadata(const TestPaths& paths, const std::string& rootPath);

std::string createResultPage(const TestStatistics&, const std::vector<TestMetadata>&, bool shuffle, uint32_t seed);

std::string localizeURL(const std::string& url, const std::string& rootPath);

std::string toJSON(const mbgl::Value& value, unsigned indent, bool singleLine);
std::string toJSON(const std::vector<mbgl::Feature>& features, unsigned indent, bool singleLine);

void localizeSourceURLs(mbgl::JSValue& root, mbgl::JSDocument& document, const std::string& rootPath);
void localizeStyleURLs(mbgl::JSValue& root, mbgl::JSDocument& document, const std::string& rootPath);
