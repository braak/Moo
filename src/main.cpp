#include <iostream>
#include <map>
#include <functional>

#include "Moo.hpp"
#include "Version.hpp"

using namespace std;

void usage(const char *name);
int version(int argc, char **argv);
int help(int argc, char **argv);

struct Tool {
  function<int(int, char **)> func;
  string description;
  int operator()(int argc, char **argv) { return func(argc, argv); }
};
map<string, Tool> tools = {{"help", {help, "prints the help message"}},
                           {"version", {version, "prints the version"}}};

int main(int argc, char **argv) {
  if (argc > 1) {
    try {
      auto tool = tools.at(argv[1]);
      return tool(argc, argv);
    } catch (out_of_range) {
      usage(argv[0]);
      return 1;
    }
  }
  return Moo::moo().fail();
}

void usage(const char *name) {
  cout << "usage: " << name << " [<command> [<args>]]" << endl;
}
int version(int argc, char **argv) {
  cout << "Moo " << Moo::version << endl;
  return 0;
}
int help(int argc, char **argv) {
  usage(argv[0]);
  cout << "Commands are:" << endl;
  for (const auto tool : tools) {
    cout << "  " << tool.first << " - " << tool.second.description << endl;
  }
  return 0;
}
