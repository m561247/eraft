/**
 * @file proto_parser.h
 * @author https://github.com/loveyacper/Qedis
 * @brief
 * @version 0.1
 * @date 2023-06-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <ctype.h>

#include <string>
#include <vector>

enum class ParseResult : int8_t {
  ok,
  wait,
  error,
};

ParseResult GetIntUntilCRLF(const char*& ptr, std::size_t nBytes, int& val);

class ProtoParser {

 public:
  void        Reset();
  ParseResult ParseRequest(const char*& ptr, const char* end);
  const std::vector<std::string>& GetParams() const {
    return params_;
  }
  void SetParams(std::vector<std::string> p) {
    params_ = std::move(p);
  }
  bool IsInitialState() const {
    return multi_ == -1;
  }

 private:
  // ptr 是 char* 类型的引用
  ParseResult _ParseMulti(const char*& ptr, const char* end, int& result);
  ParseResult _ParseStrlist(const char*&              ptr,
                            const char*               end,
                            std::vector<std::string>& results);
  ParseResult _ParseStr(const char*& ptr, const char* end, std::string& result);
  ParseResult _ParseStrval(const char*& ptr,
                           const char*  end,
                           std::string& result);
  ParseResult _ParseStrlen(const char*& ptr, const char* end, int& result);

  int multi_ = -1;
  int paramLen_ = -1;

  size_t                   numOfParam_ = 0;
  std::vector<std::string> params_;
};
