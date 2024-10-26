#include "parser.h"
#include <stdlib.h>
#include <string.h>

enum http_method http_method_from_str(char *str) {

  struct http_method_str_pair known_methods[] = {
    { HTTP_GET, "GET" },
    { HTTP_POST, "POST" },
  };

  for (unsigned i = 0; i < sizeof(known_methods) / sizeof(*known_methods); i++) {
    if (strcmp(known_methods[i].name, str) == 0)
      return known_methods[i].method;
  }

  return -1;
}

enum http_version http_version_from_str(char *str) {

  struct http_version_str_pair known_version[] = {
    { HTTP_09, "HTTP/0.9" },
    { HTTP_1, "HTTP/1" },
    { HTTP_11, "HTTP/1.1" },
    { HTTP_2, "HTTP/2" },
    { HTTP_3, "HTTP/3" },
  };

  for (unsigned i = 0; i < sizeof(known_version) / sizeof(*known_version); i++) {
    if (strcmp(known_version[i].name, str) == 0)
      return known_version[i].version;
  }

  return -1;
}

struct http_request *parse_http_request(char *request_str) {
  struct http_request *request = calloc(1, sizeof(*request));

  request->method = http_method_from_str(strtok(request_str, " "));
  request->path = strtok(NULL, " ");
  request->version = http_version_from_str(strtok(NULL, " "));

  return request;
}
