#pragma once

enum http_method {
  HTTP_GET,
  HTTP_POST,
};

struct http_method_str_pair {
  enum http_method method;
  char *name;
};

extern enum http_method http_method_from_str(char *str);

enum http_version {
  HTTP_09,
  HTTP_1,
  HTTP_11,
  HTTP_2,
  HTTP_3,
};

struct http_version_str_pair {
  enum http_version version;
  char *name;
};

extern enum http_version http_version_from_str(char *str);

struct http_request {
  enum http_method method;
  char *path;
  enum http_version version;
};

extern struct http_request *parse_http_request(char *request_str);
